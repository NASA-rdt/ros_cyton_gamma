#ifndef ecXmlVectorVector_H_
#define ecXmlVectorVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlVectorVector.h
/// @class EcXmlVectorVector
/// @brief A template class that is XML readable/writable for holding
///        vectors of XML objects.
/// @details Holds a vector of EcVectors that can read and write to an XML stream.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecVector.h>
#include <xml/ecXmlVectorType.h>

class EC_STABLE_XML_DECL EcXmlVectorVector : public EcXmlObject
{
public:
   ///	#ECXMLOBJECT(cls) EcXmlObject class convenience macro
   ECXMLOBJECT(EcXmlVectorVector);
   ECXMLOBJECT_ACCEPT(EcXmlVectorVector)

   /// constructor of vector size
   explicit EcXmlVectorVector
      (
      EcU32 size
      );

   /// constructor of vector size with elements
   /// initialized to val
   EcXmlVectorVector
      (
      EcU32 size,
      EcVector val
      );

   /// get by index
   const EcVector& operator[]
      (
      EcU32 index
      ) const;

   /// set by index
   EcVector& operator[]
      (
      EcU32 index
      );

   /// push a copy of an object onto the vector
   virtual void pushBack
      (
      const EcVector& element
      );

   /// get the vector container
   virtual const EcVectorVector& vectorContainer
      (
      ) const;

   /// get the vector container -- nonconst
   virtual EcVectorVector& vectorContainer
      (
      );

   /// reserve space in the vector container
   virtual void reserve
      (
      EcU32 size
      );

   /// resize the vector container
   virtual void resize
      (
      EcU32 size
      );

   /// clear all entries in the vector container
   virtual void clear
      (
      );

   /// assign an object to a range of values
   virtual void assign
      (
      EcU32 size,
      EcVector& obj
      );

   /// get the length of the vector
   virtual EcU32 size
      (
      ) const;

   /// left rotate by the specified amount
   /// returns true if successful
   virtual EcBoolean leftRotate
      (
      EcU32 amount
      );

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

   /// write schema
   virtual EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

   /// get a null vector
   static EcXmlVectorVector nullObject
      (
      );

protected:
   /// XML data
   EcVectorVector m_VectorContainer;
};

/// describes a vector of point collections
typedef EcXmlVectorType<EcXmlVectorVector>   EcXmlVectorVectorVector;

/// describes a vector of point collections
typedef EcXmlVectorType<EcXmlVectorVectorVector> EcXmlVectorVector3D;

#endif // ecXmlVectorVector_H_
