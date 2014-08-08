//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlVarVectType.ipp
//
//------------------------------------------------------------------------------
#include "ecXmlVarVectType.h"
#include "ecXmlBasicType.h"
#include "ecXmlReader.h"
#include "ecXmlWriter.h"

/////////////////////////////////////////////////////////////////////////
// Function:     Big four and other header functions
// Description:  Common functions
/////////////////////////////////////////////////////////////////////////

// constructor
template<class ElementType>
EcXmlVariableVectorType<ElementType>::EcXmlVariableVectorType():
EcXmlBaseVariableCompoundType(),
m_VectorContainer()
{
}

// constructor of a vector size
template<class ElementType>
EcXmlVariableVectorType<ElementType>::EcXmlVariableVectorType
   (
   EcU32 size
   ):
EcXmlBaseVariableCompoundType()
{
   m_VectorContainer.resize(size);
}

// destructor
template<class ElementType>
EcXmlVariableVectorType<ElementType>::~EcXmlVariableVectorType
   (
   )
{
   // delete the entries in the vector container
   for(size_t ii=0,size=m_VectorContainer.size();ii<size;++ii)
   {
      EcDELETE(m_VectorContainer[ii]);
   }
}

// copy constructor
template<class ElementType>
EcXmlVariableVectorType<ElementType>::EcXmlVariableVectorType
   (
   const EcXmlVariableVectorType<ElementType>& orig
   ):
EcXmlBaseVariableCompoundType(orig)
{
   // allocate space if needed
   const size_t size = orig.m_VectorContainer.size();
   if(m_VectorContainer.size()!=size)
   {
      m_VectorContainer.resize(size);
   }

   // copy the vector container
   for(size_t ii=0;ii<size;++ii)
   {
      m_VectorContainer[ii] =
         dynamic_cast<ElementType*>(orig.m_VectorContainer[ii]->clone());
   }
}

// assignment operator
template<class ElementType>
EcXmlVariableVectorType<ElementType>& EcXmlVariableVectorType<ElementType>::
   operator=
   (
   const EcXmlVariableVectorType<ElementType>& orig
   )
{
   // self assignment.
   if (this==&orig)
   {
      return *this;
   }

   // call parent
   EcXmlBaseVariableCompoundType::operator=(orig);

   // delete the previous entries in the vector container
   const size_t size = m_VectorContainer.size();
   for(size_t ii=0; ii<size; ++ii)
   {
      EcDELETE(m_VectorContainer[ii]);
   }

   // allocate space if needed
   const size_t sizeOrig = orig.m_VectorContainer.size();
   if(size != sizeOrig)
   {
      m_VectorContainer.resize(sizeOrig);
   }

   // copy the vector container
   for(size_t ii=0; ii<sizeOrig; ++ii)
   {
      m_VectorContainer[ii] = dynamic_cast<ElementType*>(orig.m_VectorContainer[ii]->clone());
   }

   return *this;
}

// equality operator
template<class ElementType>
EcBoolean EcXmlVariableVectorType<ElementType>::operator==
   (
   const EcXmlVariableVectorType<ElementType>& orig
   ) const
{

   EcBoolean retVal=EcXmlBaseVariableCompoundType::operator==(orig);

   const size_t size1=vectorContainer().size();
   const size_t size2=orig.vectorContainer().size();

   if(size1!=size2)
   {
      retVal=EcFalse;
   }

   if(retVal)
   {
      // check each value in the vector container
      for(size_t ii=0;ii<size1;++ii)
      {
         if(m_VectorContainer[ii]==0 || orig.m_VectorContainer[ii]==0 ||
            !(m_VectorContainer[ii]->equality(orig.m_VectorContainer[ii])))
         {
            retVal=EcFalse;
            break;
         }
      }
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// End of header functions
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Function:     operator[] const and nonconst version
// Description:  Returns a reference (there is a const and a nonconst
//               version) to the object at the specified index.
// I/O:          Input: integer index, Output: element reference
/////////////////////////////////////////////////////////////////////////

// const version
template<class ElementType>
const ElementType& EcXmlVariableVectorType<ElementType>::operator[]
   (
   EcU32 index
   ) const
{
   if(index<m_VectorContainer.size() && m_VectorContainer[index])
   {
      return *m_VectorContainer[index];
   }
   else
   {
      EcPrint(Warning) << "EcXmlVariableVectorType<ElementType>::operator[]: bad index\n";
      EcPrint(Warning) << "Will attempt to return the first vector element.\n";
      return *m_VectorContainer[0];
   }
}

// nonconst version - use with care
template<class ElementType>
ElementType& EcXmlVariableVectorType<ElementType>::operator[]
   (
   EcU32 index
   )
{
   if(index<m_VectorContainer.size() && m_VectorContainer[index])
   {
      return *m_VectorContainer[index];
   }
   else
   {
      EcPrint(Warning) << "bad index\n";
      EcPrint(Warning) << "Will attempt to return the first vector element.\n";
      return *m_VectorContainer[0];
   }
}

/////////////////////////////////////////////////////////////////////////
// Function:     exchange()
// Description:  exhange one entry with another if the other exists
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVariableVectorType<ElementType>::exchange
   (
   EcU32 index,
   const ElementType& newValue
   )
{
   if(index<m_VectorContainer.size())
   {
      // delete the old and replace it with a copy of the new
      EcDELETE(m_VectorContainer[index]);
      m_VectorContainer[index]=dynamic_cast<ElementType*>(newValue.clone());
      return EcTrue;
   }
   else
   {
      EcPrint(Warning) << "EcXmlVariableVectorType<ElementType>::exchange: bad index, "
             << index << std::endl;
      return EcFalse;
   }
}

/////////////////////////////////////////////////////////////////////////
// Function:     erase()
// Description:  remove one entry from vector
// I/O:          see below
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVariableVectorType<ElementType>::erase
   (
   const EcU32 index
   )
{
   if(index<m_VectorContainer.size())
   {
      // delete the memory the pointer points to.
      EcDELETE(m_VectorContainer[index]);

      // remove from the vector
      typename VectorContainer::iterator iter =
         m_VectorContainer.begin()+index;
      m_VectorContainer.erase(iter);

      return EcTrue;
   }
   else
   {
      EcPrint(Warning) << "EcXmlVariableVectorType<ElementType>::erase: bad index, "
             << index << std::endl;
      return EcFalse;
   }
}


/////////////////////////////////////////////////////////////////////////
// Function:     erase()
// Description:  remove a range of entries from vector
// I/O:          see below
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVariableVectorType<ElementType>::erase
   (
   const EcU32 first,
   const EcU32 last
   )
{
   if(last<=m_VectorContainer.size() && first<last)
   {
      for(EcU32 ii=first,count=last-first; count; ++ii,--count)
      {
         // delete the memory.
         EcDELETE(m_VectorContainer[ii]);
      }

      // remove from the vector
      typename VectorContainer::iterator iterFirst =
         m_VectorContainer.begin()+first;
      typename VectorContainer::iterator iterLast =
         m_VectorContainer.begin()+last;
      m_VectorContainer.erase(iterFirst,iterLast);

      return EcTrue;
   }
   else
   {
      EcPrint(Warning) << "EcXmlVariableVectorType<ElementType>::erase: bad first/last indices: "
             << first << "/" << last << std::endl;
      return EcFalse;
   }
}


/////////////////////////////////////////////////////////////////////////
// Function:     pushBack()
// Description:  Adds a new element to the vector container.
// I/O:          Input element
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
void EcXmlVariableVectorType<ElementType>::pushBack
   (
   const ElementType& element
   )
{
   // push the element on
   m_VectorContainer.push_back(dynamic_cast<ElementType*>(element.clone()));
}

/////////////////////////////////////////////////////////////////////////
// Function:     vectorContainer() const and nonconst version
// Description:  gets a reference (there is a const and a nonconst
//               version) to the vector container.
// I/O:          Return vector container pointer
/////////////////////////////////////////////////////////////////////////

// const version
template<class ElementType>
const typename EcXmlVariableVectorType<ElementType>::VectorContainer&
EcXmlVariableVectorType<ElementType>::vectorContainer
   (
   ) const
{
   return m_VectorContainer;
}

/////////////////////////////////////////////////////////////////////////
//End of function block : vectonContainer
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Function:     reserve
// Description:  reserves space in the vector container.
// I/O:          Input size
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
void EcXmlVariableVectorType<ElementType>::reserve
   (
   EcU32 size
   )
{
   m_VectorContainer.reserve(size);
}

/////////////////////////////////////////////////////////////////////////
// Functions:    resize()
// Description:  resizes the vector container
// I/O:          Input size
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
void EcXmlVariableVectorType<ElementType>::resize
   (
   EcU32 size
   )
{
   // delete the entries in the vector container
   const size_t currentSize = m_VectorContainer.size();

   if(size==currentSize)
   {
      // quick exit if no size change
      return;
   }

   if(size<currentSize)
   {
      // delete elements if there is a size reduction
      for(size_t ii=size;ii<currentSize;++ii)
      {
         EcDELETE(m_VectorContainer[ii]);
      }
   }

   // resize if there is a size change
   m_VectorContainer.resize(size);
}

/// clear all entries in the vector container
template<class ElementType>
void EcXmlVariableVectorType<ElementType>::clear
   (
   )
{
   // delete the entries in the vector container
   for(size_t ii=0,size=m_VectorContainer.size(); ii<size; ++ii)
   {
      EcDELETE(m_VectorContainer[ii]);
   }

   // now clear the vector
   m_VectorContainer.clear();
}

/////////////////////////////////////////////////////////////////////////
// Function:     assign()
// Description:  assigns a value to a range in the vector container.
// I/O:          Input size and object
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
void EcXmlVariableVectorType<ElementType>::assign
   (
   EcU32 size,
   ElementType& obj
   )
{
   // delete the entries in the vector container
   const size_t sizeVector = m_VectorContainer.size();
   for(size_t ii=0; ii<sizeVector; ++ii)
   {
      EcDELETE(m_VectorContainer[ii]);
   }

   // allocate space if needed
   if(m_VectorContainer.size()!=size)
   {
      m_VectorContainer.resize(size);
   }

   // copy the vector container
   for(size_t ii=0; ii<size; ++ii)
   {
      m_VectorContainer[ii] =
         dynamic_cast<ElementType*>(obj.clone());
   }
}

/////////////////////////////////////////////////////////////////////////
// Function:     size()
// Description:  Get the length of the vector
// I/O:          Output: length.
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcU32 EcXmlVariableVectorType<ElementType>::size
   (
   ) const
{
   return EcU32(m_VectorContainer.size());
}

/////////////////////////////////////////////////////////////////////////
// Functions:    read()
// Description:  Reads the class from an xml data stream
// I/O:          Insert stream, Output error status
//
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVariableVectorType<ElementType>::read
   (
   EcXmlReader& stream
   )
{
   // delete the old entries in the vector container
   for(size_t ii=0,size=m_VectorContainer.size(); ii<size; ++ii)
   {
      EcDELETE(m_VectorContainer[ii]);
   }

   // resize the vector to zero.  New entries will be pushed
   // onto this vector.
   m_VectorContainer.clear();

   const size_t numAttributes = stream.remainingNumOfAttributes();
   for (size_t ii=0; ii<numAttributes; ++ii)
   {
      if ( stream.attributeName() == EcXml::EcCountToken )
      {
         // Get vector size
         EcU32 size = atoi(stream.attributeValue().c_str());

         // reserve the correct amount of space
         m_VectorContainer.reserve(size);
      }
   }

   // call the parent
   EcBoolean retVal=EcXmlBaseVariableCompoundType::read(stream);

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Functions:    write()
// Description:  Writes the class to an xml data stream
// I/O:          Insert stream, Output error status
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVariableVectorType<ElementType>::write
   (
   EcXmlWriter& stream
   ) const
{
   // write the count attribute
   stream.setAttributeName(EcXml::EcCountToken);

   // write the attribute value.
   const size_t size = vectorContainer().size();
   EcXmlU32(size).write(stream);

   EcBoolean retVal=EcXmlBaseVariableCompoundType::write(stream);

   // loop through all the entries in the vector container
   for(size_t ii=0; ii<size; ++ii)
   {
      if(vectorContainer()[ii])
      {
         // write the start tag
         stream.writeStartTag(vectorContainer()[ii]->token());
         vectorContainer()[ii]->write(stream);
         stream.writeEndTag();
      }
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     writeSchema
// Description:  writes the schema for object
// I/O:          Insert stream, Output error status
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVariableVectorType<ElementType>::writeSchema
   (
   EcXmlSchema& stream
   ) const
{

   // write the count attribute
   stream.setAttributeName(EcXml::EcCountToken);

   // write the attribute value.
   EcXmlU32().writeSchema(stream);

   EcBoolean retval = EcXmlBaseVariableCompoundType::writeSchema(stream);

   return retval;
}

/////////////////////////////////////////////////////////////////////////
// Functions:    writeHeaderToStream()
// Description:  Write just the header and opening tag.
// I/O:          Input: a stream, stream name, and object name
//               Output: an allocated pWriter pointer
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVariableVectorType<ElementType>::writeHeaderToStream
   (
   std::ostream& stream,
   EcXmlWriter*& pWriter,
   const EcString& streamName,
   const EcToken& objectName
   ) const
{
   // error check
   if(stream.bad() || stream.fail())
   {
      return EcFalse;
   }

   // create XML writer
   pWriter=new EcXmlWriter(streamName,stream);

   // write XML header and open root tag
   pWriter->writeStartTag(objectName);

   EcBoolean retVal=EcXmlObject::write(*pWriter);

   if(retVal)
   {

      // write the count attribute
      pWriter->setAttributeName(EcXml::EcCountToken);

      // write the attribute value.
      const size_t size = vectorContainer().size();
      EcXmlU32(size).write(*pWriter);

      retVal=EcXmlBaseVariableCompoundType::write(*pWriter);
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Functions:    writeBodyToStream()
// Description:  Append the body (the elements) to the stream
// I/O:          Input: an allocated pWriter pointer
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVariableVectorType<ElementType>::writeBodyToStream
   (
   EcXmlWriter* pWriter
   ) const
{
   // error check
   if(!pWriter)
   {
      return EcFalse;
   }

   // loop through all the entries in the vector
   for(size_t ii=0,size=vectorContainer().size(); ii<size; ++ii)
   {
      if(vectorContainer()[ii])
      {
         // write the start tag
         pWriter->writeStartTag(vectorContainer()[ii]->token());
         vectorContainer()[ii]->write(*pWriter);
         pWriter->writeEndTag();
      }
   }

   return EcTrue;
}

/////////////////////////////////////////////////////////////////////////
// Functions:    appendElementToStream()
// Description:  Append an element to an ostream
// I/O:          Input: an allocated pWriter pointer, the element
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVariableVectorType<ElementType>::appendElementToStream
   (
   EcXmlWriter* pWriter,
   const ElementType& element
   ) const
{
   // error check
   if(!pWriter)
   {
      return EcFalse;
   }

   // write the new element
   pWriter->writeStartTag(element.token());
   element.write(*pWriter);
   pWriter->writeEndTag();

   return EcTrue;
}

/////////////////////////////////////////////////////////////////////////
// Functions:    writeFooterToStream()
// Description:  write the closing tag and free memory
//               pWriter will be null.
// I/O:          Input: an allocated pWriter pointer
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVariableVectorType<ElementType>::writeFooterToStream
   (
   EcXmlWriter*& pWriter
   ) const
{
   // error check
   if(!pWriter)
   {
      return EcFalse;
   }

   // close root tag
   pWriter->writeEndTag();

   // free memory for the writer
   EcDELETE(pWriter);

   return EcTrue;
}

/////////////////////////////////////////////////////////////////////////
// Functions:    readValueFromToken()
// Description:  read an XML object from a stream after reading the start tag
//               return value signals success or failure
// I/O:          Input string token and stream
//               Output error status
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVariableVectorType<ElementType>::readValueFromToken
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
      ElementType* element =
         dynamic_cast<ElementType*>(newObjectFromToken(token));

      // if the object could not be read from the factory specific to this
      // object, try the augmentation factory that is part of the EcXmlReader
      if(!element && stream.factoryPointer())
      {
         element =
            dynamic_cast<ElementType*>(stream.factoryPointer()->newObjectFromToken(token));
      }

      // if there was no registered function for the token or
      // it was not registered as an ElementType, an error occurred.
      if(!element)
      {
         EcPrint(Warning) << "EcXmlVariableVectorType::readValueFromToken() error:\n\t\""
                << token << "\" tag not registered.\n";
         retVal=EcFalse;
      }
      else
      {
         element->read(stream);
         m_VectorContainer.push_back(element);
      }
   }

   return retVal;
}
