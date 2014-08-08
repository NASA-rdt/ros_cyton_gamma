//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlMapType.ipp
//
//------------------------------------------------------------------------------
#include "ecXmlMapType.h"
#include "ecXmlReader.h"
#include "ecXmlWriter.h"

/////////////////////////////////////////////////////////////////////////
// Function:    Big four and other header methods.
// Description: Common functions
/////////////////////////////////////////////////////////////////////////

// constructor
template<class KeyType, class ValueType>
EcXmlMapType<KeyType,ValueType>::EcXmlMapType():
EcXmlObject(),
m_MapContainer()
{
}

// single value constructor
template<class KeyType, class ValueType>
EcXmlMapType<KeyType,ValueType>::EcXmlMapType
(
   KeyType key,
   ValueType value
)
{
   m_MapContainer[key] = value;

}

// destructor
template<class KeyType, class ValueType>
EcXmlMapType<KeyType,ValueType>::~EcXmlMapType
   (
   )
{
}

// copy constructor
template<class KeyType, class ValueType>
EcXmlMapType<KeyType,ValueType>::EcXmlMapType
   (
   const EcXmlMapType<KeyType,ValueType>& orig
   ):
EcXmlObject(orig),
m_MapContainer(orig.m_MapContainer)
{
}

// assignment operator
template<class KeyType, class ValueType>
EcXmlMapType<KeyType,ValueType>& EcXmlMapType<KeyType,ValueType>::operator=
   (
   const EcXmlMapType<KeyType,ValueType>& orig
   )
{
   // self assignment.
   if (this==&orig)
   {
      return *this;
   }

   // call parent
   EcXmlObject::operator=(orig);

   m_MapContainer=orig.m_MapContainer;

   return *this;
}

// equality operator
template<class KeyType, class ValueType>
EcBoolean EcXmlMapType<KeyType,ValueType>::operator==
   (
   const EcXmlMapType<KeyType,ValueType>& orig
   ) const
{

   EcBoolean retVal=EcXmlObject::operator==(orig);

   if(retVal)
   {
      // get an iterator for this map, starting at the first pair
      typename MapContainer::const_iterator iter1 =
            mapContainer().begin();

      // get an iterator for the other map, starting at the first pair
      typename MapContainer::const_iterator iter2 =
            orig.mapContainer().begin();

      if(mapContainer().size()!=orig.mapContainer().size())
      {
         retVal=EcFalse;
      }
      else
      {
         // loop through all the entries in the map
         while(iter1!=mapContainer().end())
         {
            if(!(iter1->first==iter2->first))
            {
               retVal=EcFalse;
            }

            if(!(iter1->second==iter2->second))
            {
               retVal=EcFalse;
            }

            ++iter1;
            ++iter2;
         }
      }
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
//End of header methods.
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Function:    lookup()
// Description: Looks up a value corresponding to a given key
// I/O:         Sets the value if the key exists in the map.  Returns
//              EcTrue if the key exists in the map; otherwise returns
//              EcFalse.
/////////////////////////////////////////////////////////////////////////
template<class KeyType, class ValueType>
EcBoolean EcXmlMapType<KeyType,ValueType>::lookup
   (
   const KeyType& key,
   ValueType& value
   ) const
{
   EcBoolean retVal=EcFalse;

   // get a pointer to the desired value, NULL if nonexistent
   const ValueType* pValue=lookupPointer(key);

   // set the value if the pointer is nonNULL
   if(pValue)
   {
      value=*pValue;
      retVal=EcTrue;
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     lookupPointer()
// Description:  lookup a value pointer from a key.  Returns NULL if
//               the key is not in the map.  Use with care.
// I/O:          key input, value pointer output
/////////////////////////////////////////////////////////////////////////
template<class KeyType, class ValueType>
const ValueType* EcXmlMapType<KeyType,ValueType>::lookupPointer
   (
   const KeyType& key
   ) const
{
   const ValueType* retVal=0;

   // get an iterator for the map, starting at the location
   // specified by the token.
   typename MapContainer::const_iterator iter =
      mapContainer().find(key);

   // if we didn't find the value, an error occurred.
   if(iter!=mapContainer().end())
   {
      // set the value and return true
      retVal=&iter->second;
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     lookupPointer()
// Description:  lookup a value pointer from a key.  Returns NULL if
//               the key is not in the map. Non-const version. Use with care.
// I/O:          key input, value pointer output
/////////////////////////////////////////////////////////////////////////
template<class KeyType, class ValueType>
ValueType* EcXmlMapType<KeyType,ValueType>::lookupPointer
   (
   const KeyType& key
   )
{
   ValueType* retVal=0;

   // get an iterator for the map, starting at the location
   // specified by the token.
   typename MapContainer::iterator iter =
      mapContainer().find(key);

   // if we didn't find the value, an error occurred.
   if(iter!=mapContainer().end())
   {
      // set the value and return true
      retVal=&iter->second;
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:    add()
// Description: Adds a new key/value pair to the map.  If a key/value
//              pair with the same key already exists, it overwrites.
// I/O:         Input: key and value.
/////////////////////////////////////////////////////////////////////////
template<class KeyType, class ValueType>
void EcXmlMapType<KeyType,ValueType>::add
   (
   const KeyType& key,
   const ValueType& value
   )
{
   m_MapContainer[key]=value;
}

/////////////////////////////////////////////////////////////////////////
// Function:    erase()
// Description: Erases a key/value pair, if the key exists in the map
// I/O:         returns true if the key existed.
/////////////////////////////////////////////////////////////////////////
template<class KeyType, class ValueType>
EcBoolean EcXmlMapType<KeyType,ValueType>::erase
   (
   const KeyType& key
   )
{
   EcBoolean retVal=EcFalse;

   // get an iterator for the map, starting at the location
   // specified by the token.
   typename MapContainer::iterator iter =
      m_MapContainer.find(key);

   // if we didn't find the value, an error occurred.
   if(iter!=mapContainer().end())
   {
      // remove the key/value pair
      m_MapContainer.erase(iter);

      // successfully removed the data
      retVal=EcTrue;
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:    clear()
// Description: Erases all key/value pairs, leaving an empty map
/////////////////////////////////////////////////////////////////////////
template<class KeyType, class ValueType>
void EcXmlMapType<KeyType,ValueType>::clear
   (
   )
{
   m_MapContainer.clear();
}

/////////////////////////////////////////////////////////////////////////
// Function:    mapContainer()
// Description: Accessor to a const reference for the map container.  Also,
//              just in case it is ever needed, a non-const reference
//              version.  (Use with care.)
// I/O:         A reference to the map container is returned.
/////////////////////////////////////////////////////////////////////////
template<class KeyType, class ValueType>
const std::map<KeyType,ValueType>& EcXmlMapType<KeyType,ValueType>::
   mapContainer
   (
   ) const
{
   return m_MapContainer;
}

template<class KeyType, class ValueType>
typename EcXmlMapType<KeyType,ValueType>::MapContainer&
EcXmlMapType<KeyType,ValueType>::mapContainer
   (
   )

{
   return m_MapContainer;
}

/////////////////////////////////////////////////////////////////////////
//End mapContainer()
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
// Functions:    keyIndex()
// Description:  Gets the order number for a key.  Returns false if the
//               key does not exist.
// I/O:          input key, output index and error status
/////////////////////////////////////////////////////////////////////////
template<class KeyType, class ValueType>
EcBoolean EcXmlMapType<KeyType,ValueType>::keyIndex
   (
   const KeyType& key,
   EcU32& index
   ) const
{
   EcBoolean retVal=EcFalse;

   // xml-initialize index
   index=0;

   typename MapContainer::const_iterator iter=mapContainer().begin();

   // just walk through the entries looking.  This is not the fastest way
   // to do this.  A binary search would be better.
   while(iter!=mapContainer().end())
   {
      if(iter->first==key)
      {
         retVal=EcTrue;
         break;
      }

      ++index;
      ++iter;
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Functions:    indexKey()
// Description:  Gets the key at the given index (0,1,2,...)
//               Returns false if the index is out of range.
// I/O:          input index, output key and error status
/////////////////////////////////////////////////////////////////////////
template<class KeyType, class ValueType>
EcBoolean EcXmlMapType<KeyType,ValueType>::indexKey
   (
   const EcU32& index,
   KeyType& key
   ) const
{
   // quick error check
   if(index>=size())
   {
      return EcFalse;
   }

   // get an iterator
   typename MapContainer::const_iterator iter=
      mapContainer().begin();

   // put the iterator in the right location
   std::advance(iter,index);

   // set the value and return true
   key=iter->first;
   return EcTrue;
}


/////////////////////////////////////////////////////////////////////////
// Functions:    size()
// Description:  get the size of the map container
// I/O:          return size
/////////////////////////////////////////////////////////////////////////
template<class KeyType, class ValueType>
EcU32 EcXmlMapType<KeyType,ValueType>::size
   (
   ) const
{
   return EcU32(mapContainer().size());
}


/////////////////////////////////////////////////////////////////////////
// Function:    read()
// Description: Reads the object from an XML data stream.
// I/O:         Input stream, returns true if all went OK.
/////////////////////////////////////////////////////////////////////////
template<class KeyType, class ValueType>
EcBoolean EcXmlMapType<KeyType,ValueType>::read
   (
   EcXmlReader& stream
   )
{
   EcBoolean retVal=EcXmlObject::read(stream);

   // delete the old values of the vector so we can
   // push_back as we read the values.
   m_MapContainer.clear();

   // if not EMPTY_TAG for current element, process data
   if(retVal && stream.mode() != EcXmlFileReader::EMPTY_TAG)
   {
      // create and xmlInit a key/value pair for reading.
      KeyType key;
      ValueType value;

      // keep looping so long as there is valid next start tag.

      EcXmlFileReader::XML_READER_MODE mode = stream.readXml();
      if( EcXmlFileReader::ERROR_FOUND == mode)
      {
         return EcFalse;
      }

      while ( mode == EcXmlFileReader::START_TAG )
      {
         if( stream.element() == EcXml::EcElementToken )
         {
            // read the key

            mode = stream.readXml();
            if( mode != EcXmlFileReader::START_TAG )
            {
               EcPrint(Warning) << "EcXmlMapType Error: file not valid.\n\t"
                      << "Key map format not correct.\n\tFile: "
                      << stream.filename() << "\n\tLine: " << stream.lineCountOfFile();
               return EcFalse;
            }

            key.read(stream);

            // set the key/value pair in the map, using the placeholder value
            m_MapContainer[key]=value;

            // read the value of key

            mode = stream.readXml();
            if( mode == EcXmlFileReader::START_TAG || mode == EcXmlFileReader::EMPTY_TAG )
            {
               m_MapContainer[key].read(stream);
            }
            else
            {
               EcPrint(Warning) << "EcXmlMapType Error: file not valid.\n\t"
                      << "Key map format not correct.\n\tFile: "
                      << stream.filename() << "\n\tLine: " << stream.lineCountOfFile();
               return EcFalse;
            }

            { // clear attributes
               const EcU32 numAttributes = stream.remainingNumOfAttributes();
               for ( EcU32 ii=0; ii<numAttributes; ++ii )
               {
                  stream.attributeName(); 
                  stream.attributeValue();
               }
            }
         }
         else
         {
            EcPrint(Warning) << "EcXmlMapType Error: file not valid.\n\t"
                   << "Key map format not correct.\n\tFile: "
                   << stream.filename() << "\n\tLine: " << stream.lineCountOfFile();
            EcPrint(Warning) << "\tExpected " << EcXml::EcElementToken
                   << " but received " << stream.element() << ".";
            return EcFalse;
         }

         // read the end tag for the element
         mode = stream.readXml();
         if( mode != EcXmlFileReader::END_TAG )
         {
            EcPrint(Warning) << "EcXmlMapType Error: file not valid.\n\t"
                   << "Key map format not correct.\n\tFile: "
                   << stream.filename() << "\n\tLine: " << stream.lineCountOfFile();
            return EcFalse;
         }

         mode = stream.readXml();
         if( EcXmlFileReader::ERROR_FOUND == mode)
         {
            return EcFalse;
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
template<class KeyType, class ValueType>
EcBoolean EcXmlMapType<KeyType,ValueType>::write
   (
   EcXmlWriter& stream
   ) const
{
   EcBoolean retVal=EcXmlObject::write(stream);

   // get an iterator for the map, starting at the first pair
   typename std::map<KeyType,ValueType>::const_iterator iter =
         mapContainer().begin();

   // loop through all the entries in the map
   while(iter!=mapContainer().end())
   {
      // write the start tag for the map element
      stream.writeStartTagUsingParentNamespace(EcXml::EcElementToken);

      // write the key element
      stream.writeStartTagUsingParentNamespace(EcXml::EcKeyToken);
      (iter->first).write(stream);
      stream.writeEndTag();

      // write the value element
      stream.writeStartTagUsingParentNamespace(EcXml::EcValueToken);
      (iter->second).write(stream);
      stream.writeEndTag();

      // closes EcElementToken
      stream.writeEndTag();

      ++iter;
   }

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:     writeSchema
// Description:  writes the class schema to the schema creator
// I/O:          Input stream, output error status
/////////////////////////////////////////////////////////////////////////
template<class KeyType, class ValueType>
EcBoolean EcXmlMapType<KeyType,ValueType>::writeSchema
   (
   EcXmlSchema& stream
   ) const
{
   EcBoolean retVal=EcXmlObject::writeSchema(stream);

   // write the start tag for the map element
   stream.writeStartTagUsingParentNamespace
      (EcXml::EcElementToken, EcXmlSchemaElementType::UNBOUNDED);

   // write the key element
   stream.writeStartTagUsingParentNamespace(EcXml::EcKeyToken);
   KeyType().writeSchema(stream);
   stream.writeEndTag();

   // write the value element
   stream.writeStartTagUsingParentNamespace(EcXml::EcValueToken);
   ValueType().writeSchema(stream);
   stream.writeEndTag();

   // closes EcElementToken
   stream.writeEndTag();

   return retVal;
}

/////////////////////////////////////////////////////////////////////////
// Function:    nullValue()
// Description: Returns an empty map.
// I/O:         Output EcXmlMapType
/////////////////////////////////////////////////////////////////////////
template<class KeyType, class ValueType>
std::map<KeyType,ValueType> EcXmlMapType<KeyType,ValueType>::nullObject
   (
   )
{
   return std::map<KeyType,ValueType>();
}


/////////////////////////////////////////////////////////////////////////
// Function:    token()
// Description: Gets the xml token tag for this object.
/////////////////////////////////////////////////////////////////////////
template<class KeyType, class ValueType>
ECXML_DEFINE_TOKENS(EcXmlMapType<KeyType BOOST_PP_COMMA() ValueType>, EcXml::EcMapTypeToken)
