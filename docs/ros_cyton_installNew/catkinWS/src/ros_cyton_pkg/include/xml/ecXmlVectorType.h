#ifndef ecXmlVectorType_H_
#define ecXmlVectorType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlVectorType.h
/// @class EcXmlVectorType
/// @brief A template class that is XML readable/writable for holding
///        vectors of XML objects.
//
//------------------------------------------------------------------------------
#include "ecXmlBasicType.h"

template<class ElementType>
class EcXmlVectorType : public EcXmlObject
{
public:
   typedef typename std::vector<ElementType> VectorContainer;  ///< VectorContainer type from std::vector

   ///	#ECXMLOBJECT(cls) EcXmlObject class convenience macro
   ECXMLOBJECT(EcXmlVectorType<ElementType>);
   ECXMLOBJECT_ACCEPT(EcXmlVectorType<ElementType>)

   /// constructor of vector size
   explicit EcXmlVectorType<ElementType>
      (
      EcU32 size
      );

   /// constructor of vector size with elements
   /// initialized to val
   EcXmlVectorType<ElementType>
      (
      EcU32 size,
      ElementType val
      );

   /// get by index
   const ElementType& operator[]
      (
      EcU32 index
      ) const;

   /// set by index
   ElementType& operator[]
      (
      EcU32 index
      );

   /// push a copy of an object onto the vector
   virtual void pushBack
      (
      const ElementType& element
      );

   /// erase one element
   virtual EcBoolean erase
      (
      const EcU32 index
      );

   /// erase a range of elements
   virtual EcBoolean erase
      (
      const EcU32 first,
      const EcU32 last
      );

   /// get the vector container
   virtual const VectorContainer& vectorContainer
      (
      ) const;

   /// get the vector container -- nonconst
   virtual VectorContainer& vectorContainer
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

   /// grow the vector container if necessary, but do not shrink
   virtual void resizeToAtLeast
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
      const ElementType& obj
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

   /// write the header for this object to an ostream
   virtual EcBoolean writeHeaderToStream
      (
      std::ostream& stream,
      EcXmlWriter*& pWriter,
      const EcString& streamName,
      const EcToken& objectName=EcXml::EcDefaultToken
      ) const;

   /// write the body (the elements) of this vector to an ostream
   virtual EcBoolean writeBodyToStream
      (
      EcXmlWriter* pWriter
      ) const;

   /// append an element to an ostream
   virtual EcBoolean appendElementToStream
      (
      EcXmlWriter* pWriter,
      const ElementType& element
      ) const;

   /// write the footer of this object to an ostream and free
   /// the memory in the writer
   virtual EcBoolean writeFooterToStream
      (
      EcXmlWriter*& pWriter
      ) const;

   /// get a null vector
   static EcXmlVectorType<ElementType> nullObject
      (
      );

   /// append the passed in vector to the end of this vector
   virtual void append
      (
      const EcXmlVectorType<ElementType>& other
      );

protected:
   /// XML data
   VectorContainer m_VectorContainer;
};

/// This template class is defined for the following:

/// describes a vector of unsigned 32-bit integers
typedef EcXmlVectorType<EcXmlU32>              EcXmlU32Vector;

/// describes an array of unsigned 32-bit integers
typedef EcXmlVectorType<EcXmlU32Vector>        EcXmlU32VectorVector;

/// describes an 3D array of unsigned 32-bit integers
typedef EcXmlVectorType<EcXmlU32VectorVector>  EcXmlU32Vector3D;

/// describes a vector of signed 32-bit integers
typedef EcXmlVectorType<EcXmlInt32>            EcXmlInt32Vector;

/// describes an array of signed 32-bit integers
typedef EcXmlVectorType<EcXmlInt32Vector>      EcXmlInt32VectorVector;

/// describes a vector of signed 16-bit integers
typedef EcXmlVectorType<EcXmlInt16>            EcXmlInt16Vector;

/// describes a vector of unsigned 16-bit integers
typedef EcXmlVectorType<EcXmlU16>              EcXmlU16Vector;

/// describes a vector of signed 8-bit integers
typedef EcXmlVectorType<EcXmlInt8>             EcXmlInt8Vector;

/// describes a vector of unsigned 8-bit integers
typedef EcXmlVectorType<EcXmlU8>               EcXmlU8Vector;

/// describes an array of signed 32-bit integers
typedef EcXmlVectorType<EcXmlU8Vector>         EcXmlU8VectorVector;

/// describes a vector of reals
typedef EcXmlVectorType<EcXmlReal>             EcXmlRealVector;

/// describes an array of reals
typedef EcXmlVectorType<EcXmlRealVector>       EcXmlRealVectorVector;

/// describes a vector of strings
typedef EcXmlVectorType<EcXmlString>           EcXmlStringVector;

/// describes a 2D vector of strings
typedef EcXmlVectorType<EcXmlStringVector>     EcXmlStringVectorVector;

/// describes a 3D vector of strings
typedef EcXmlVectorType<EcXmlStringVectorVector> EcXmlStringVector3D;

/// describes a vector of booleans
typedef EcXmlVectorType<EcXmlBoolean>          EcXmlBooleanVector;

/// describes a vector of booleans
typedef EcXmlVectorType<EcXmlBooleanVector>    EcXmlBooleanVectorVector;

/// describes an array of real vectors
typedef EcXmlVectorType<EcXmlRealVectorVector> EcXmlRealVector3D;

#endif // ecXmlVectorType_H_
