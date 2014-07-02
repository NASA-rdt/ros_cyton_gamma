//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlVarElemType.ipp
//
//------------------------------------------------------------------------------
#include "ecXmlVarElemType.h"
#include "ecXmlReader.h"
#include "ecXmlWriter.h"

/////////////////////////////////////////////////////////////////////////
// Function:     Big four and other header functions
// Description:  Common functions.
/////////////////////////////////////////////////////////////////////////
// constructor
template<class ElementType>
EcXmlVariableElementType<ElementType>::EcXmlVariableElementType
   (
   ):
EcXmlBaseVariableCompoundType(),
m_pElement(0)
{
}

// destructor
template<class ElementType>
EcXmlVariableElementType<ElementType>::~EcXmlVariableElementType
   (
   )
{
   EcDELETE(m_pElement);
}

// copy constructor.  Also copies the parent link pointer.
template<class ElementType>
EcXmlVariableElementType<ElementType>::EcXmlVariableElementType
   (
   const EcXmlVariableElementType<ElementType>& orig
   ):
EcXmlBaseVariableCompoundType(orig)
{
   // copy the expression tree
   if(orig.m_pElement)
   {
      m_pElement=
         dynamic_cast<ElementType*>(orig.m_pElement->clone());
   }
   else
   {
      m_pElement=0;
   }
}

// assignment operator
template<class ElementType>
EcXmlVariableElementType<ElementType>&
   EcXmlVariableElementType<ElementType>::operator=
   (
   const EcXmlVariableElementType<ElementType>& orig
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
   if(orig.m_pElement)
   {
      // delete the old tree
      EcDELETE(m_pElement);

      m_pElement=
         dynamic_cast<ElementType*>(orig.m_pElement->clone());
   }
   else
   {
      EcDELETE(m_pElement);
   }

   return *this;
}

// equality operator
template<class ElementType>
EcBoolean EcXmlVariableElementType<ElementType>::operator==
   (
   const EcXmlVariableElementType<ElementType>& orig
   ) const
{
   EcBoolean retVal=EcXmlBaseVariableCompoundType::operator==(orig);


   if(retVal)
   {
      if(m_pElement && orig.m_pElement)
      {
         // neither pointer is NULL
         if(!m_pElement->equality(orig.m_pElement))
         {
            retVal=EcFalse;
         }
      }
      else
      {
         // at least one of the pointers is NULL
         // they should both be NULL for equality
         if(m_pElement || orig.m_pElement)
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
template<class ElementType>
const ElementType* EcXmlVariableElementType<ElementType>::element
   (
   ) const
{
   return m_pElement;
}

/// gets a pointer to the top expression (nonconst)
template<class ElementType>
ElementType* EcXmlVariableElementType<ElementType>::element
   (
   )
{
   return m_pElement;
}

/// sets the top expression through a copy
template<class ElementType>
void EcXmlVariableElementType<ElementType>::setElement
   (
   const ElementType& element
   )
{
   // free memory for the old value
   EcDELETE(m_pElement);

   // set the pointer to a copy of the new value
   m_pElement=dynamic_cast<ElementType*>(element.clone());
}

/////////////////////////////////////////////////////////////////////////
//End of get/set
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Function:     read()
// Description:  Reads class data from an XML stream.
// I/O:          Input: stream, Output: true for success.
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVariableElementType<ElementType>::read
   (
   EcXmlReader& stream
   )
{
   EcBoolean retVal=EcXmlBaseVariableCompoundType::read(stream);

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     write()
// Description:  Writes class data to an XML stream.
// I/O:          Input: stream, Output: true for success.
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVariableElementType<ElementType>::write
   (
   EcXmlWriter& stream
   ) const
{
   EcBoolean retVal=EcXmlBaseVariableCompoundType::write(stream);

   // write the expression elements
   if(m_pElement)
   {
      stream.writeStartTag(m_pElement->token());
      m_pElement->write(stream);
      stream.writeEndTag();
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     readValueFromToken()
// Description:  read an XML object from a stream after reading the start tag
//               return value signals success or failure
// I/O:          Input string and stream, Output status
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVariableElementType<ElementType>::readValueFromToken
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
      // free memory for the old value
      EcDELETE(m_pElement);

      // create the element from a creator function in the parent's map
      m_pElement=dynamic_cast<ElementType*>(newObjectFromToken(token));

      // if the object could not be read from the factory specific to this
      // object, try the augmentation factory that is part of the EcXmlReader
      if(!m_pElement && stream.factoryPointer())
      {
         m_pElement =
            dynamic_cast<ElementType*>(stream.factoryPointer()->newObjectFromToken(token));
      }

      // if there was no registered function for the token or
      // it was not registered as an ElementType, an error occurred.
      if(!m_pElement)
      {
         EcPrint(Warning) << "EcXmlVariableElementType::readValueFromToken() error:\n\t\""
                << token << "\" tag not registered.\n";
         retVal=EcFalse;
      }
      else
      {
         // and read the data from the stream
         m_pElement->read(stream);
      }
   }

   return retVal;
}
