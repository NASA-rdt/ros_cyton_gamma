#ifndef ecXmlMapType_H_
#define ecXmlMapType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlMapType.h
/// @class EcXmlMapType
/// @brief An XML readable/writable Map.
/// @tparam KeyType  the map key type
/// @tparam ValueType the map value type
/// @details Can map strings to strings, strings to 32-bit Integers, an strings
///          to Reals.  Potentially can easily map any XML Object type to any
///          other XML Object, but this will require implementing < for the key
///          type and adding specialization code to this class.
//
//------------------------------------------------------------------------------
#include "ecXmlBasicType.h"
#include "ecXmlVectorType.h"
#include <map>

template<class KeyType, class ValueType>
class EcXmlMapType : public EcXmlObject
{
public:
   typedef std::map<KeyType,ValueType> MapContainer;    ///< type definition of the MapContainer based on std::map
   typedef EcXmlMapType<KeyType,ValueType> class_type;  ///< type definition of the EcXmlMapType

   ///	#ECXMLOBJECT(cls) EcXmlObject class convenience macro
   ECXMLOBJECT(EcXmlMapType);
   ECXMLOBJECT_ACCEPT(EcXmlMapType)

   /// single value constructor
   EcXmlMapType<KeyType,ValueType>
      (
         KeyType key,
         ValueType value
      );

   /// lookup a value from a key.  Returns false if the key is not in the map.
   virtual EcBoolean lookup
      (
      const KeyType& key,
      ValueType& value
      ) const;

   /// lookup a value pointer from a key.  Returns NULL if the key is not in the map.
   /// Use with care.
   virtual const ValueType* lookupPointer
      (
      const KeyType& key
      ) const;


   /// lookup a value pointer from a key.  Returns NULL if the key is not in the map.
   /// Non-const version. Also use with care.
   virtual ValueType* lookupPointer
      (
      const KeyType& key
      );

   /// add a key/value pair
   virtual void add
      (
      const KeyType& key,
      const ValueType& value
      );

   /// erase a key/value pair, if the key exists in the map
   /// returns true if the key existed.
   virtual EcBoolean erase
      (
      const KeyType& key
      );

   /// erase all key/value pairs, leaving an empty map
   virtual void clear
      (
      );

   /// get the map container
   virtual const std::map<KeyType,ValueType>& mapContainer
      (
      ) const;

   /// get the map container -- nonconst
   virtual std::map<KeyType,ValueType>& mapContainer
      (
      );

   /// get the index (the order in the map) of a key.  Returns
   /// false if the key doesn't exist in the map.
   virtual EcBoolean keyIndex
      (
      const KeyType& key,
      EcU32& index
      ) const;

   /// get the key at an index location (the order in the map).
   /// Returns false if the index doesn't exist in the map.
   virtual EcBoolean indexKey
      (
      const EcU32& index,
      KeyType& key
      ) const;

   /// get the size of the map container
   virtual EcU32 size
      (
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// write this object to an XML schema
   virtual EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

   /// get a null value
   static std::map<KeyType,ValueType> nullObject
      (
      );

protected:
   /// the internal representation of the map.
   MapContainer m_MapContainer;
};

/// This template class is defined for the following:

/// A map with string keys and string values
typedef EcXmlMapType<EcXmlString,EcXmlString>           EcXmlStringStringMap;

/// A map with string keys and signed 32-bit integer values
typedef EcXmlMapType<EcXmlString,EcXmlInt32>            EcXmlStringInt32Map;

/// A map with string keys and unsigned 32-bit integer values
typedef EcXmlMapType<EcXmlString,EcXmlU32>              EcXmlStringU32Map;

/// A map with string keys and real values
typedef EcXmlMapType<EcXmlString,EcXmlReal>             EcXmlStringRealMap;

/// A map with string keys and boolean values
typedef EcXmlMapType<EcXmlString,EcXmlBoolean>          EcXmlStringBooleanMap;

/// A map with <string,string> map and real values
typedef EcXmlMapType<EcXmlString,EcXmlStringRealMap>    EcXmlStringStringRealMap;

/// A map with <string,string>  keys and boolean values
typedef EcXmlMapType<EcXmlString,EcXmlStringBooleanMap> EcXmlStringStringBooleanMap;

/// a map with string keys and real-vector values
typedef EcXmlMapType<EcXmlString,EcXmlRealVector>       EcXmlStringRealVectorMap;

/// a map with string keys and real-vector values
typedef EcXmlMapType<EcXmlString,EcXmlU32Vector>        EcXmlStringU32VectorMap;

#endif // ecXmlMapType_H_
