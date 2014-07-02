#ifndef ecXmlVarVectType_H_
#define ecXmlVarVectType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlVarVectType.h
/// @class EcXmlVariableVectorType
/// @brief A template class that is XML readable/writable for holding
///        vectors of XML objects.
/// @details The elements in the variable vector can be any of the registered items in
///          registerComponentCreators()
//
//------------------------------------------------------------------------------
#include "ecXmlBaseVarCompType.h"

#include <vector>

template<class ElementType>
class EcXmlVariableVectorType : public EcXmlBaseVariableCompoundType
{
public:
   typedef std::vector<ElementType*> VectorContainer;   ///< VectorContainer type from std::vector

   /// #ECDECLARE_BIGFOUR(EcCls) Macro declares a constructor, destructor,
   /// copy constructor, equal operator, and equality operator
   ECDECLARE_BIGFOUR(EcXmlVariableVectorType<ElementType>);
   ECXMLOBJECT_ACCEPT(EcXmlVariableVectorType<ElementType>)

   /// constructor of vector size
   explicit EcXmlVariableVectorType<ElementType>
      (
      EcU32 size
      );

   /// get by index - const version
   virtual const ElementType& operator[]
      (
      EcU32 index
      ) const;

   /// get by index - nonconst version
   virtual ElementType& operator[]
      (
      EcU32 index
      );

   /// exhange one entry with another if the other exists
   virtual EcBoolean exchange
      (
      EcU32 index,
      const ElementType& newValue
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

   /// push a copy of an object onto the vector
   virtual void pushBack
      (
      const ElementType& element
      );

   /// get the vector container
   virtual const VectorContainer& vectorContainer
      (
      ) const;

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
      ElementType& obj
      );

   /// get the length of the vector
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

   /// write this object to an XML stream
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

protected:
   /// read an object from a stream after reading the start tag
   /// return value signals success or failure
   virtual EcBoolean readValueFromToken
      (
      const EcToken& token,
      EcXmlReader& stream
      );

   /// XML data
   VectorContainer m_VectorContainer;
};

#endif // ecXmlVarVectType_H_
