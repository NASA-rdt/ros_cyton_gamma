//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlVectorType.ipp
//
//------------------------------------------------------------------------------
#include "ecXmlVectorType.h"
#include "ecXmlReader.h"
#include "ecXmlWriter.h"

#include <algorithm>

/////////////////////////////////////////////////////////////////////////
// Functions:    Big four and other header functions
// Description:  Common functions
/////////////////////////////////////////////////////////////////////////

// constructor
template<class ElementType>
EcXmlVectorType<ElementType>::EcXmlVectorType():
EcXmlObject(),
m_VectorContainer()
{
}

// constructor of a vector size
template<class ElementType>
EcXmlVectorType<ElementType>::EcXmlVectorType
   (
   EcU32 size
   ):
EcXmlObject()
{
   m_VectorContainer.resize(size);
}

// constructor of a vector size, initialized to value val
template<class ElementType>
EcXmlVectorType<ElementType>::EcXmlVectorType
   (
   EcU32 size,
   ElementType val
   ):
EcXmlObject()
{
   m_VectorContainer.resize(size,val);
}

// destructor
template<class ElementType>
EcXmlVectorType<ElementType>::~EcXmlVectorType
   (
   )
{
}

// copy constructor
template<class ElementType>
EcXmlVectorType<ElementType>::EcXmlVectorType
   (
   const EcXmlVectorType<ElementType>& orig
   ):
EcXmlObject(orig),
m_VectorContainer(orig.m_VectorContainer)
{
}

// assignment operator
template<class ElementType>
EcXmlVectorType<ElementType>& EcXmlVectorType<ElementType>::operator=
   (
   const EcXmlVectorType<ElementType>& orig
   )
{
   // self assignment.
   if (this==&orig)
   {
      return *this;
   }

   // call parent
   EcXmlObject::operator=(orig);

   // Copy the STL vector container, unless it's empty.
   //
   // The empty check handles a little known problem w/ VS2010
   // when running in debug mode causing iterator incompatible via:
   // clear() -> erase() the iterators are null 'cause the vector is not only 
   // empty but temporary things are not fully constructed.
   if (orig.size() == 0)
   {
      m_VectorContainer.clear();
   }
   else
   {
      m_VectorContainer = orig.m_VectorContainer;
   }

   return *this;
}

// equality operator
template<class ElementType>
EcBoolean EcXmlVectorType<ElementType>::operator==
   (
   const EcXmlVectorType<ElementType>& orig
   ) const
{
   EcBoolean retVal=EcXmlObject::operator==(orig);

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
         if(!(m_VectorContainer[ii]==orig.m_VectorContainer[ii]))
         {
            retVal=EcFalse;
            break;
         }
      }
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
//End of header functions
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Functions:    operator[] const and nonconst versions
// Description:  Returns a reference (there is a const and a nonconst
//               version) to the object at the specified index.
// I/O:          Input: integer index, Output element reference
/////////////////////////////////////////////////////////////////////////

// const version
template<class ElementType>
const ElementType& EcXmlVectorType<ElementType>::operator[]
   (
   EcU32 index
   ) const
{
   return m_VectorContainer[index];
}

// nonconst version
template<class ElementType>
ElementType& EcXmlVectorType<ElementType>::operator[]
   (
   EcU32 index
   )
{
   return m_VectorContainer[index];
}

/////////////////////////////////////////////////////////////////////////
//End of function block : operator[]
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Function:     pushBack
// Description:  Add element to end of vector
// I/O:          Input element
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
void EcXmlVectorType<ElementType>::pushBack
   (
   const ElementType& element
   )
{
   // push the element on
   m_VectorContainer.push_back(element);
}

/////////////////////////////////////////////////////////////////////////
// Function:     append
// Description:  append the passed in vector to the end of this vector
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
void EcXmlVectorType<ElementType>::append
   (
   const EcXmlVectorType<ElementType>& other
   )
{
   // push the element on
   m_VectorContainer.insert(  m_VectorContainer.end(),
                              other.vectorContainer().begin(),
                              other.vectorContainer().end() );
}

/////////////////////////////////////////////////////////////////////////
// Functions:    vector() const and nonconst version
// Description:  gets a reference (there is a const and a nonconst
//               version) to the vector container.
// I/O:          Return vector container reference
/////////////////////////////////////////////////////////////////////////

// const version
template<class ElementType>
const typename EcXmlVectorType<ElementType>::VectorContainer&
EcXmlVectorType<ElementType>::vectorContainer
   (
   ) const
{
   return m_VectorContainer;
}

// nonconst version
template<class ElementType>
typename EcXmlVectorType<ElementType>::VectorContainer&
EcXmlVectorType<ElementType>::vectorContainer
   (
   )
{
   return m_VectorContainer;
}

/////////////////////////////////////////////////////////////////////////
// End vectorContainer
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Functions:    reserve
// Description:  reserves space in the vector container.  This is
//               just a pass-through.
// I/O:          Input size
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
void EcXmlVectorType<ElementType>::reserve
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
void EcXmlVectorType<ElementType>::resize
   (
   EcU32 size
   )
{
   if(m_VectorContainer.size()!=size)
   {
      m_VectorContainer.resize(size,ElementType());
   }
}

/////////////////////////////////////////////////////////////////////////
// Functions:    resize()
// Description:  grow the vector container if necessary, but do not shrink
// I/O:          Input size
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
void EcXmlVectorType<ElementType>::resizeToAtLeast
   (
   EcU32 size
   )
{
   if(m_VectorContainer.size()<size)
   {
      m_VectorContainer.resize(size,ElementType());
   }
}

/////////////////////////////////////////////////////////////////////////
// Function:     clear()
// Description:  clear all entries in the vector container
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
void EcXmlVectorType<ElementType>::clear
   (
   )
{
   m_VectorContainer.clear();
}

/////////////////////////////////////////////////////////////////////////
// Function:     erase
// Description:  delete one element
// I/O:          Input: element index
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVectorType<ElementType>::erase
   (
   const EcU32 index
   )
{
   if(index>=m_VectorContainer.size())
   {
      EcPrint(Warning) << "EcXmlVectorType<ElementType>::erase(): index ("
             << index << ") exceeds vector size (" << m_VectorContainer.size() << ").\n";
      return EcFalse;
   }

   typename VectorContainer::iterator iter =
      m_VectorContainer.begin()+index;

   m_VectorContainer.erase(iter);

   return EcTrue;
}

/////////////////////////////////////////////////////////////////////////
// Function:     erase
// Description:  delete a range of elements
// I/O:          Input: the first and last indices to be deleted
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVectorType<ElementType>::erase
   (
   const EcU32 first,
   const EcU32 last
   )
{
   if(last>m_VectorContainer.size())
   {
      EcPrint(Warning) << "index (" << last << ") exceeds vector size ( " << m_VectorContainer.size() << ").\n";
      return EcFalse;
   }
   else if(first>last)
   {
      EcPrint(Warning) << "first (" << first << ") is bigger than last (" << last << ").\n";
      return EcFalse;
   }

   typename VectorContainer::iterator firstIter =
      m_VectorContainer.begin()+first;

   typename VectorContainer::iterator lastIter =
      m_VectorContainer.begin()+last;

   m_VectorContainer.erase(firstIter,lastIter);

   return EcTrue;
}

/////////////////////////////////////////////////////////////////////////
// Functions:    assign()
// Description:  assigns a value to a range in the vector container.
//               This is just a pass-through.
// I/O:          Input size and object
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
void EcXmlVectorType<ElementType>::assign
   (
   EcU32 size,
   const ElementType& obj
   )
{
   m_VectorContainer.assign(size,obj);
}

/////////////////////////////////////////////////////////////////////////
// Function:    size()
// Description: Get the length of the vector
// I/O:         Output: length.
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcU32 EcXmlVectorType<ElementType>::size
   (
   ) const
{
   return EcU32(m_VectorContainer.size());
}

/////////////////////////////////////////////////////////////////////////
// Function:     leftRotate()
// Description:  left rotate by the specified amount
// I/O:          Input rotation amount, Output error status
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVectorType<ElementType>::leftRotate
   (
   EcU32 amount
   )
{
   EcBoolean retVal;
   if(amount<m_VectorContainer.size())
   {
      std::rotate(m_VectorContainer.begin(),
                  m_VectorContainer.begin()+amount,
                  m_VectorContainer.end());
      retVal=EcTrue;
   }
   else
   {
      retVal=EcFalse;
   }
   return retVal;
}


/////////////////////////////////////////////////////////////////////////
// Functions:    read()
// Description:  Reads the class from an xml data stream
// I/O:          Insert stream, Output error status
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVectorType<ElementType>::read
   (
   EcXmlReader& stream
   )
{
   EcBoolean retVal=EcXmlObject::read(stream);

   if(retVal)
   {
      // delete the old values of the vector so we can
      // push_back as we read the values.
      m_VectorContainer.resize(0);

      //
      // Note:
      //   Loop here to get any attributes from the array.
      //

      // initialize value to hold explicly stated size of the vector
      EcU32 vectorSize = 0;

      const EcU32 numAttributes = stream.remainingNumOfAttributes();
      for ( EcU32 ii=0; ii<numAttributes; ++ii )
      {
         if ( stream.attributeName() == EcXml::EcCountToken )
         {
            // Get vector size
            vectorSize = atoi(stream.attributeValue().c_str());

            // reserve vector space
            m_VectorContainer.reserve( vectorSize );
         }
      }

      // if not EMPTY_TAG for current element, process data

      if ( stream.mode() != EcXmlFileReader::EMPTY_TAG )
      {
         //create a blank utility element
         const ElementType element;

         // read next tag
         EcXmlFileReader::XML_READER_MODE mode = stream.readXml();
         if( EcXmlFileReader::ERROR_FOUND == mode)
         {
            return EcFalse;
         }

         // keep looping so long as there is valid next start tag.

         // create counter for content items read
         EcU32 count = 0;

         while ( mode == EcXmlFileReader::START_TAG ||
                 mode == EcXmlFileReader::EMPTY_TAG )
         {
            if( stream.element().EcToken::operator==(EcXml::EcGroupToken.token()) )
            {
               // read next tag
               mode = stream.readXml();

               if( mode == EcXmlFileReader::CONTENT )
               {
                  stream.setContentVectorFlag();

                  // process until no more data
                  while ( stream.isContentAvailable() )
                  {
                     // push the blank value onto the vector.
                     m_VectorContainer.push_back(element);

                     // read the value and increment counter
                     m_VectorContainer[count++].read(stream);
                  }
               }
               else
               {
                  EcPrint(Warning) << "EcXmlVectorType Error: "
                     "XML parser should be in data mode\n";
                  return EcFalse;
               }
            }
            else
            {
               // push the blank value onto the vector.
               m_VectorContainer.push_back(element);

               // read the value and increment the counter
               m_VectorContainer[count++].read(stream);
            }

            // read next tag
            mode = stream.readXml();
            if( EcXmlFileReader::ERROR_FOUND == mode)
            {
               return EcFalse;
            }
         }

         if ( count != vectorSize )
         {
            EcPrint(Info) << "EcXmlVectorType Error: "
               "array size not equal to attribute value -- "
                <<  vectorSize << ", actual -- " << count << std::endl;
            EcPrint(Info) << "Filename: " << stream.filename() << ", Line count: " << stream.lineCountOfFile() << std::endl;
         }
      }
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Functions:   write()
// Description: Writes the class to an xml data stream
// I/O:         Insert stream, Output error status
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVectorType<ElementType>::write
   (
   EcXmlWriter& stream
   ) const
{
   EcBoolean retVal=EcXmlObject::write(stream);

   // write the count attribute
   stream.setAttributeName(EcXml::EcCountToken);

   // write the attribute value.
   const size_t size = vectorContainer().size();
   EcXmlU32(size).write(stream);

   // loop through all the entries in the vector
   for(size_t ii=0;ii<size;++ii)
   {
      if( vectorContainer()[ii].isBasicType() )
      {
         // write the vector element
         if( ii == 0 )
         {
            stream.writeStartTagUsingParentNamespace(EcXml::EcGroupToken);
         }

         vectorContainer()[ii].write(stream);

         if( ii == size-1 )
         {
            stream.writeEndTag();
         }
      }
      else
      {
         // write the vector element
         stream.writeStartTagUsingParentNamespace(EcXml::EcElementToken);
         vectorContainer()[ii].write(stream);
         stream.writeEndTag();
      }
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     writeSchema
// Description:  writes the schema of object
// I/O:          Insert stream, Output error status
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVectorType<ElementType>::writeSchema
   (
   EcXmlSchema& stream
   ) const
{
   EcBoolean retVal=EcXmlObject::writeSchema(stream);

   // write the count attribute
   stream.setAttributeName(EcXml::EcCountToken);

   // write the attribute value.
   EcXmlU32().writeSchema(stream);

   ElementType type;

   stream.writeStartTagUsingParentNamespace
      (EcXml::EcElementToken, EcXmlSchemaElementType::UNBOUNDED);
   type.writeSchema(stream);
   stream.writeEndTag();

   // If a basic type, add groups to schema
   // "Groups" only applies to basic types
   if( type.isBasicType() )
   {
      stream.writeStartTagUsingParentNamespace(EcXml::EcGroupToken);

      // sending two basic values to the schema makes it a list type
      type.writeSchema(stream);
      type.writeSchema(stream);

      stream.writeEndTag();
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Functions:    writeHeaderToStream()
// Description:  Write just the header and opening tag.
// I/O:          Input: a stream, stream name, and object name
//               Output: an allocated pWriter pointer
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVectorType<ElementType>::writeHeaderToStream
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

   EcXmlObject::write(*pWriter);

   // write the count attribute
   pWriter->setAttributeName(EcXml::EcCountToken);

   // write the attribute value.
   const size_t size = vectorContainer().size();
   EcXmlU32(size).write(*pWriter);

   // special case for basic types
   ElementType element;
   if( element.isBasicType() )
   {
      pWriter->writeStartTagUsingParentNamespace(EcXml::EcGroupToken);
   }

   return EcTrue;
}

/////////////////////////////////////////////////////////////////////////
// Functions:    writeBodyToStream()
// Description:  Append the body (the elements) to the stream
// I/O:          Input: an allocated pWriter pointer
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVectorType<ElementType>::writeBodyToStream
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
      if( vectorContainer()[ii].isBasicType() )
      {
         vectorContainer()[ii].write(*pWriter);
      }
      else
      {
         // write the vector element
         pWriter->writeStartTagUsingParentNamespace(EcXml::EcElementToken);
         vectorContainer()[ii].write(*pWriter);
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
EcBoolean EcXmlVectorType<ElementType>::appendElementToStream
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

   if( element.isBasicType() )
   {
      element.write(*pWriter);
   }
   else
   {
      // write the vector element
      pWriter->writeStartTagUsingParentNamespace(EcXml::EcElementToken);
      element.write(*pWriter);
      pWriter->writeEndTag();
   }

   return EcTrue;
}

/////////////////////////////////////////////////////////////////////////
// Functions:    writeFooterToStream()
// Description:  write the closing tag and free memory
//               pWriter will be null.
// I/O:          Input: an allocated pWriter pointer
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlVectorType<ElementType>::writeFooterToStream
   (
   EcXmlWriter*& pWriter
   ) const
{
   // error check
   if(!pWriter)
   {
      return EcFalse;
   }

   ElementType element;
   if( element.isBasicType() )
   {
      // write the closing tag for the group
      pWriter->writeEndTag();
   }

   // close root tag
   pWriter->writeEndTag();

   // free memory for the writer
   EcDELETE(pWriter);

   return EcTrue;
}

/////////////////////////////////////////////////////////////////////////
// Function:    nullValue()
// Description: Returns a copy of an empty vector.
// I/O:         Return EcXmlVectorType
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcXmlVectorType<ElementType> EcXmlVectorType<ElementType>::nullObject
   (
   )
{
   return EcXmlVectorType<ElementType>();
}

/////////////////////////////////////////////////////////////////////////
// Function:    token()
// Description: Gets the xml token tag for this object.
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
ECXML_DEFINE_TOKENS(EcXmlVectorType<ElementType>, EcXml::EcVectorTypeToken)

// Specify that these EcXmlVectorType instantiates will come from this library.
#ifdef WIN32
EC_STABLE_XML_TEMPLATE_DECL template class EC_STABLE_XML_DECL EcXmlVectorType<EcXmlString>;
#endif
