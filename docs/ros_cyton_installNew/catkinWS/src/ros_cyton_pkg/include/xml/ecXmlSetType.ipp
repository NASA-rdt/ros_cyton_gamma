//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlSetType.ipp
//
//------------------------------------------------------------------------------
#include "ecXmlSetType.h"
#include "ecXmlReader.h"
#include "ecXmlWriter.h"

/////////////////////////////////////////////////////////////////////////
// Function:     Big four and other header methods.
// Description:  Common functions
/////////////////////////////////////////////////////////////////////////

// constructor
template<class ElementType>
EcXmlSetType<ElementType>::EcXmlSetType():
EcXmlObject(),
m_SetContainer()
{
}

// single value constructor
template<class ElementType>
EcXmlSetType<ElementType>::EcXmlSetType
(
   const ElementType& value
)
{
   m_SetContainer.insert(value);

}

// destructor
template<class ElementType>
EcXmlSetType<ElementType>::~EcXmlSetType
   (
   )
{
}

// copy constructor
template<class ElementType>
EcXmlSetType<ElementType>::EcXmlSetType
   (
   const EcXmlSetType<ElementType>& orig
   ):
EcXmlObject(orig),
m_SetContainer(orig.m_SetContainer)
{
}

// assignment operator
template<class ElementType>
EcXmlSetType<ElementType>& EcXmlSetType<ElementType>::operator=
   (
   const EcXmlSetType<ElementType>& orig
   )
{
   // self assignment.
   if (this==&orig)
   {
      return *this;
   }

   // call parent
   EcXmlObject::operator=(orig);

   m_SetContainer=orig.m_SetContainer;

   return *this;
}

// equality operator
template<class ElementType>
EcBoolean EcXmlSetType<ElementType>::operator==
   (
   const EcXmlSetType<ElementType>& orig
   ) const
{

   EcBoolean retVal=EcXmlObject::operator==(orig);

   if(retVal)
   {
      if (!(m_SetContainer==orig.m_SetContainer))
      {
         retVal = EcFalse;
      }
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
//End of header methods.
/////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////
// Function:    add()
// Description: Adds a new key/value pair to the map.  If a key/value
//              pair with the same key already exists, it overwrites.
// I/O:         Input: key and value.
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
void EcXmlSetType<ElementType>::add
   (
   const ElementType& value
   )
{
   m_SetContainer.insert(value);
}

/////////////////////////////////////////////////////////////////////////
// Function:     erase()
// Description:  Erases an element, if the key exists in the map
// I/O:          returns true if the key existed.
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlSetType<ElementType>::erase
   (
   const ElementType& key
   )
{
   EcBoolean retVal=EcFalse;

   // get an iterator for the set, starting at the location
   // specified by the key.
   typename SetContainer::iterator iter =
      m_SetContainer.find(key);

   // if we didn't find the value, an error occurred.
   if(!(iter==m_SetContainer.end()))
   {
      // remove the value
      m_SetContainer.erase(iter);

      // successfully removed the data
      retVal=EcTrue;
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:    find()
// Description: find a value in the set.  Returns true if it is found,
//              false otherwise.
// I/O:         Return: True for success.
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlSetType<ElementType>::find
  (
  const ElementType& key
  ) const
{
   // get an iterator to the location of the key.
   typename SetContainer::const_iterator iter = m_SetContainer.find(key);

   // if the value was found, return true, otherwise false
   if(iter==m_SetContainer.end())
   {
      // the key does not exist in the set
      return EcFalse;
   }
   else
   {
      // the key exists in the set
      return EcTrue;
   }
}

/////////////////////////////////////////////////////////////////////////
// Function:    clear()
// Description: Erases all key/value pairs, leaving an empty map
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
void EcXmlSetType<ElementType>::clear
   (
   )
{
   m_SetContainer.clear();
}

/////////////////////////////////////////////////////////////////////////
// Functions:    size()
// Description:  get the size of the map container
// I/O:          return size
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcU32 EcXmlSetType<ElementType>::size
   (
   ) const
{
   return EcU32(m_SetContainer.size());
}


/////////////////////////////////////////////////////////////////////////
// Function:    read()
// Description: Reads the object from an XML data stream.
// I/O:         Input stream, returns true if all went OK.
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlSetType<ElementType>::read
   (
   EcXmlReader& stream
   )
{
   EcBoolean retVal=EcXmlObject::read(stream);

   if(retVal)
   {
      // delete the old values of the vector so we can
      // push_back as we read the values.
      m_SetContainer.clear();

      //
      // Note:
      //   Loop here to get any attributes from the array.
      //

      const EcU32 numAttributes = stream.remainingNumOfAttributes();

      EcU32 setSize = 0;

      for ( EcU32 ii=0; ii<numAttributes; ++ii )
      {
         if ( stream.attributeName() == EcXml::EcCountToken )
         {
            // Get vector size
            setSize = atoi(stream.attributeValue().c_str());
         }
      }

      // if not EMPTY_TAG for current element, process data

      if ( stream.mode() != EcXmlFileReader::EMPTY_TAG )
      {
         EcString token;

         //create a blank utility element
         ElementType element;
         element.xmlInit();

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
            // get element name
            token = stream.element();

            if( token == EcXml::EcGroupToken.token() )
            {
               // read next tag
               mode = stream.readXml();

               if( mode == EcXmlFileReader::CONTENT )
               {
                  stream.setContentVectorFlag();

                  // process until no more data
                  while ( stream.isContentAvailable() )
                  {

                     // read the value
                     element.read(stream);

                     // push the blank value onto the vector.
                     m_SetContainer.insert(element);

                     // count data for verification
                     ++count;
                  }
               }
               else
               {
                  EcPrint(Warning) << "EcXmlSetType Error: XML parser should be in data mode\n";
                  return EcFalse;
               }
            }
            else
            {

               // read the value
               element.read(stream);

               // push the blank value onto the vector.
               m_SetContainer.insert(element);

               // count data for verification
               ++count;
            }

            // read next tag
            mode = stream.readXml();
            if( EcXmlFileReader::ERROR_FOUND == mode)
            {
               return EcFalse;
            }
         }

         if ( count != setSize )
         {
            EcPrint(Info) << "EcXmlSetType Error: "
                   << "set size not equal to attribute value -- "
                   << setSize << ", actual -- " << count << std::endl;
         }
      }
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:    write()
// Description: Writes the object to an xml data stream.
// I/O:         Input stream, output error status
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlSetType<ElementType>::write
   (
   EcXmlWriter& stream
   ) const
{
   EcBoolean retVal=EcXmlObject::write(stream);

   // write the attribute value.
   size_t size = setContainer().size();
   if( 0 == size )
   {
      // create empty tag
      return retVal;
   }

   // write the count attribute and value
   stream.setAttributeName(EcXml::EcCountToken);
   EcXmlU32(size).write(stream);

   // get the iterator for the set
   typename SetContainer::const_iterator lp = setContainer().begin();

   // loop through all the entries in the map
   for(size_t ii=0; lp!=setContainer().end(); ++lp,++ii)
   {
      // get the element
      const ElementType& element = *lp;
      if( element.isBasicType() )
      {
         // write the vector element
         if( ii == 0 )
         {
            stream.writeStartTagUsingParentNamespace(EcXml::EcGroupToken);
         }

         element.write(stream);

         if( ii == size-1 )
         {
            stream.writeEndTag();
         }
      }
      else
      {
         // write the vector element
         stream.writeStartTagUsingParentNamespace(EcXml::EcElementToken);
         element.write(stream);
         stream.writeEndTag();
      }
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     writeSchema
// Description:  writes the class schema to the schema creator
// I/O:          Input stream, output error status
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
EcBoolean EcXmlSetType<ElementType>::writeSchema
   (
   EcXmlSchema& stream
   ) const
{
   EcBoolean retVal=EcXmlObject::writeSchema(stream);

   // write the start tag for the map element
   stream.writeStartTagUsingParentNamespace
      (EcXml::EcElementToken, EcXmlSchemaElementType::UNBOUNDED);

   // write the element
   stream.writeStartTagUsingParentNamespace(EcXml::EcKeyToken);
   ElementType().writeSchema(stream);
   stream.writeEndTag();



   // closes EcElementToken
   stream.writeEndTag();

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:    nullValue()
// Description: Returns an empty map.
// I/O:         Output EcXmlSetType
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
typename EcXmlSetType<ElementType>::SetContainer
EcXmlSetType<ElementType>::nullObject
   (
   )
{
   return std::set<ElementType>();
}


/////////////////////////////////////////////////////////////////////////
// Function:    token()
// Description: Gets the xml token tag for this object.
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
ECXML_DEFINE_TOKENS(EcXmlSetType<ElementType>, EcXml::EcSetTypeToken)


/////////////////////////////////////////////////////////////////////////
// Function:     setContainer
// Description:  get the set container
// I/O:          Output: the set container
/////////////////////////////////////////////////////////////////////////
template<class ElementType>
const typename EcXmlSetType<ElementType>::SetContainer&
EcXmlSetType<ElementType>::setContainer
   (
   ) const
{
   return m_SetContainer;
}
