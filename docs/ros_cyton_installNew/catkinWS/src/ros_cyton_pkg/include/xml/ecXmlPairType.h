#ifndef ecXmlPairType_H_
#define ecXmlPairType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlPairType.h
/// @class EcXmlPairType
/// @brief An XML readable/writable Pair.  Can hold any to types
///        of XML objects.
/// @tparam FirstType   the first XML object type of the pair
/// @tparam SecondType  the second XML object type of the pair
//
//------------------------------------------------------------------------------
#include "ecXmlBasicType.h"
#include "ecXmlVectorType.h"
#include <map>

template<class FirstType, class SecondType>
class EcXmlPairType : public EcXmlObject
{
public:
   /// convenience typedef of the pair container
   typedef std::pair<FirstType,SecondType> PairContainer;

   ///	#ECXMLOBJECT(cls) EcXmlObject class convenience macro
   ECXMLOBJECT(EcXmlPairType);
   ECXMLOBJECT_ACCEPT(EcXmlPairType)

   /// single value constructor
   EcXmlPairType<FirstType,SecondType>
      (
      FirstType first,
      SecondType second
      );

   /// get the first value
   virtual const FirstType& first
      (
      ) const;

   /// get the first value (nonconst)
   virtual FirstType& first
      (
      );

   /// set the first value
   virtual void setFirst
      (
      const FirstType& first
      );

   /// get the second value
   virtual const SecondType& second
      (
      ) const;

   /// get the second value (nonconst)
   virtual SecondType& second
      (
      );

   /// set the second value
   virtual void setSecond
      (
      const SecondType& second
      );

   /// set both first and second values
   virtual void set
      (
      const FirstType& first,
      const SecondType& second
      );

   /// gets a const reference to the pair container
   virtual const PairContainer& pairContainer
      (
      ) const { return m_PairContainer; }

   /// gets a non const reference to the pair container
   virtual PairContainer& pairContainer
      (
      ) { return m_PairContainer; }

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

   /// sets the XML tag names for the pair
   void setXmlTagNames
      (
      const EcString& first,
      const EcString& second
      );

protected:
   PairContainer m_PairContainer; ///< Internal representation
   EcStringStringPair m_TagNames; ///< XML tag names
};

/// This template class is defined for the following:

/// A map with string keys and string values
typedef EcXmlPairType<EcXmlString,EcXmlString>    EcXmlStringStringPair;

/// A map with string keys and unsigned 32-bit integer values
typedef EcXmlPairType<EcXmlString,EcXmlU32>       EcXmlStringU32Pair;

/// A pairs of U32
typedef EcXmlPairType<EcXmlU32,EcXmlU32>          EcXmlU32U32Pair;

/// A vector of XmlU32U32
typedef EcXmlVectorType<EcXmlU32U32Pair>          EcXmlU32U32PairVector;

/// A 2D vector of XmlU32U32
typedef EcXmlVectorType<EcXmlU32U32PairVector>    EcXmlU32U32PairVectorVector;

/// A pairs of real
typedef EcXmlPairType<EcXmlReal,EcXmlReal>        EcXmlRealRealPair;

/// A vector of XmlRealReal
typedef EcXmlVectorType<EcXmlRealRealPair>        EcXmlRealRealPairVector;



#endif // ecXmlPairType_H_
