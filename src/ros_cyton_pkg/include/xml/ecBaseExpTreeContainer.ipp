//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseExpTreeContainer.ipp
//
//------------------------------------------------------------------------------
#include "ecBaseExpTreeContainer.h"

#include <foundCore/ecMacros.h>
#include "ecXmlReader.h"
#include "ecXmlWriter.h"

/////////////////////////////////////////////////////////////////////////
// Function:     Big four and other header functions
// Description:  Common functions.
/////////////////////////////////////////////////////////////////////////
// constructor
template<class ExpressionType>
EcBaseExpressionTreeContainer<ExpressionType>::
   EcBaseExpressionTreeContainer():
EcXmlBaseVariableCompoundType(),
m_pTopElement(0)
{
}

// destructor
template<class ExpressionType>
EcBaseExpressionTreeContainer<ExpressionType>::
   ~EcBaseExpressionTreeContainer
   (
   )
{
   EcDELETE(m_pTopElement);
}


// copy constructor.  Also copies the parent link pointer.
template<class ExpressionType>
EcBaseExpressionTreeContainer<ExpressionType>::
   EcBaseExpressionTreeContainer
   (
   const EcBaseExpressionTreeContainer<ExpressionType>& orig
   ):
EcXmlBaseVariableCompoundType(orig)
{
   // copy the expression tree
   if(orig.m_pTopElement)
   {
      m_pTopElement=
         dynamic_cast<ExpressionType*>(orig.m_pTopElement->clone());
   }
   else
   {
      m_pTopElement=0;
   }
}


// assignment operator
template<class ExpressionType>
EcBaseExpressionTreeContainer<ExpressionType>&
   EcBaseExpressionTreeContainer<ExpressionType>::operator=
   (
   const EcBaseExpressionTreeContainer<ExpressionType>& orig
   )
{
   // self assignment.
   if (this==&orig)
   {
      return *this;
   }

   // call parent
   EcXmlBaseVariableCompoundType::operator=(orig);

   // copy the expression tree
   if(orig.m_pTopElement)
   {
      // delete the old tree
      EcDELETE(m_pTopElement);

      m_pTopElement=
         dynamic_cast<ExpressionType*>(orig.m_pTopElement->clone());

      // set the container pointer of the new top element (and the tree below)
      setTopElementContainerToThis();
   }
   else
   {
      EcDELETE(m_pTopElement);
   }

   return *this;
}


// equality operator
template<class ExpressionType>
EcBoolean EcBaseExpressionTreeContainer<ExpressionType>::operator==
   (
   const EcBaseExpressionTreeContainer<ExpressionType>& orig
   ) const
{
   EcBoolean retVal=EcXmlBaseVariableCompoundType::operator==(orig);

   if(retVal)
   {
      if(m_pTopElement && orig.m_pTopElement)
      {
         // neither pointer is NULL
         if(!m_pTopElement->equality(orig.m_pTopElement))
         {
            retVal=EcFalse;
         }
      }
      else
      {
         // at least one of the pointers is NULL
         // they should both be NULL for equality
         if(m_pTopElement || orig.m_pTopElement)
         {
            retVal=EcFalse;
         }
      }
   }
   return retVal;
}


/////////////////////////////////////////////////////////////////////////
//End of header functions.
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Function:     get/set
// Description:  Accessors and mutators for member variables.
// I/O:          Input or return pointer to top expression
/////////////////////////////////////////////////////////////////////////

/// gets a pointer to the top expression (const)
template<class ExpressionType>
const ExpressionType* EcBaseExpressionTreeContainer<ExpressionType>::topElement
   (
   ) const
{
   return m_pTopElement;
}


/// gets a pointer to the top expression (nonconst)
template<class ExpressionType>
ExpressionType* EcBaseExpressionTreeContainer<ExpressionType>::topElement
   (
   )
{
   return m_pTopElement;
}


/// sets the top expression through a copy
template<class ExpressionType>
void EcBaseExpressionTreeContainer<ExpressionType>::setTopElement
   (
   const ExpressionType& topElement
   )
{
   // set the pointer to a copy of the new value
   ExpressionType* pNewTopElement=dynamic_cast<ExpressionType*>(topElement.clone());

   // free memory for the old value.  This is done after the clone in case some part
   // of the old value is used in setting the new.
   EcDELETE(m_pTopElement);

   // set the value to the new pointer
   m_pTopElement = pNewTopElement;

   setTopElementContainerToThis();
}


/// sets the top expression pointer and later deletes this pointer
/// Use with great care
template<class ExpressionType>
void EcBaseExpressionTreeContainer<ExpressionType>::
   setAndDeleteTopElementPointer
   (
   ExpressionType* pTopElement
   )
{
   // free memory for the old value
   EcDELETE(m_pTopElement);

   // set the pointer--it will later be deleted
   m_pTopElement=pTopElement;

   setTopElementContainerToThis();
}


/////////////////////////////////////////////////////////////////////////
//End of get/set
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Function:     read()
// Description:  Reads class data from an XML stream.
// I/O:          Input: stream, Output: true for success.
/////////////////////////////////////////////////////////////////////////
template<class ExpressionType>
EcBoolean EcBaseExpressionTreeContainer<ExpressionType>::read
   (
   EcXmlReader& stream
   )
{
   EcBoolean retVal=EcXmlBaseVariableCompoundType::read(stream);

   // if it exists set the container for the top element to this.  This
   // container pointer is propagated throughout the tree.
   if(m_pTopElement)
   {
      setTopElementContainerToThis();
   }

   return retVal;
}


/////////////////////////////////////////////////////////////////////////
// Function:     write()
// Description:  Writes class data to an XML stream.
// I/O:          Input: stream, Output: true for success.
/////////////////////////////////////////////////////////////////////////
template<class ExpressionType>
EcBoolean EcBaseExpressionTreeContainer<ExpressionType>::write
   (
   EcXmlWriter& stream
   ) const
{
   EcBoolean retVal=EcXmlBaseVariableCompoundType::write(stream);

   // write the expression elements
   if(m_pTopElement)
   {
      stream.writeStartTag(m_pTopElement->token());
      m_pTopElement->write(stream);
      stream.writeEndTag();
   }

   return retVal;
}


/////////////////////////////////////////////////////////////////////////
// Function:     writeSchema
// Description:  writes the class schema to the schema creator
// I/O:          Input: stream, Output: true for success.
/////////////////////////////////////////////////////////////////////////
template<class ExpressionType>
EcBoolean EcBaseExpressionTreeContainer<ExpressionType>::writeSchema
   (
   EcXmlSchema& stream
   ) const
{
   EcBoolean retVal=EcXmlObject::writeSchema(stream);

   // write the DLL library names
   stream.writeStartTagUsingParentNamespace(EcXml::EcAddLibrariesToken);
   EcXmlStringVector().writeSchema(stream);
   stream.writeEndTag();

   // get a convenient reference to the component map
   const EcXmlCreatorMap& creatorMap=m_XmlFactory.creatorMap();

   // if we have any componenents, then write them at this time.
   if ( creatorMap.size() > 0 )
   {
      // get an iterator for the map, starting at the first pair
      EcXmlCreatorMap::const_iterator iter=creatorMap.begin();

      // open schema group for this object
      stream.openGroup();

      // loop through all the entries in the map
      while(iter!=creatorMap.end())
      {
         // get element
         ExpressionType* element =
            dynamic_cast<ExpressionType*>((iter->second)());

         element->setContainer(this);

         // write the start tag
         stream.writeStartTag(iter->first, EcXmlSchemaElementType::UNBOUNDED);

         // if already registered, bypass writing schema for element
         if( !stream.isRegistered(iter->first, typeid(*element).name()))
         {
            // write schema for element
            element->writeSchema(stream);

            // write the end tag
            stream.writeEndTag();
         }

         // clean element
         EcDELETE(element);

         // increment to next element
         ++iter;
      }

      // close schema group for this object
      stream.closeGroup();
   }

   return retVal;
}


/////////////////////////////////////////////////////////////////////////
// Function:     setTopElementContainerToThis
// Description:  If needed, sets the child's pointer to this
/////////////////////////////////////////////////////////////////////////
template<class ExpressionType>
void EcBaseExpressionTreeContainer<ExpressionType>::
   setTopElementContainerToThis
   (
   )
{
   // do nothing by default
}


/////////////////////////////////////////////////////////////////////////
// Function:     readValueFromToken()
// Description:  read an XML object from a stream after reading the start tag
//               return value signals success or failure
// I/O:          Input string and stream, Output status
/////////////////////////////////////////////////////////////////////////
template<class ExpressionType>
EcBoolean EcBaseExpressionTreeContainer<ExpressionType>::readValueFromToken
   (
   const EcToken& token,
   EcXmlReader& stream
   )
{
   EcBoolean retVal=EcTrue;

   // check to see if it is an add-libraries token
   if(token==EcXml::EcAddLibrariesToken)
   {
      m_AddLibraries.read(stream);
      processLibraries();
   }
   else
   {
      // create the element from a creator function in the parent's map
      setAndDeleteTopElementPointer
         (
         dynamic_cast<ExpressionType*>(newObjectFromToken(token))
         );

      // if the object could not be read from the factory for this method
      // try the augmentation factory
      if(!m_pTopElement && stream.factoryPointer())
      {
         setAndDeleteTopElementPointer
            (
            dynamic_cast<ExpressionType*>(stream.factoryPointer()->newObjectFromToken(token))
            );
      }

      // finally, if there was no registered function for the token or
      // it was not registered as an ExpressionType, an error occurred.
      if(!m_pTopElement)
      {
         retVal=EcFalse;
      }
      else
      {
         // and read the data from the stream
         m_pTopElement->read(stream);
      }
   }

   return retVal;
}
