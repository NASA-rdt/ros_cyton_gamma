#ifndef ecXmlSetType_H_
#define ecXmlSetType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlSetType.h
/// @class EcXmlSetType
/// @brief An XML readable/writable set container.
//
//------------------------------------------------------------------------------
#include "ecXmlObject.h"

#include <set>

template<class ElementType>
class EcXmlSetType : public EcXmlObject
{
public:
   /// The SetContainer is a type definition based on std::set
   typedef std::set<ElementType> SetContainer;

   ///	#ECXMLOBJECT(cls) EcXmlObject class convenience macro
   ECXMLOBJECT(EcXmlSetType<ElementType>);

   /// single value constructor
   EcXmlSetType<ElementType>
      (
         const ElementType& value
      );

   /// find a value. Returns true if it is found, false otherwise.
   virtual EcBoolean find
      (
      const ElementType& key
      ) const;

   /// erase all key/value pairs, leaving an empty set
   virtual void clear
      (
      );

   /// get the size of the set container
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

   /// add an element to the set
   virtual void add
      (
      const ElementType& value
      );

   /// erases an element in the set
   virtual EcBoolean erase
      (
      const ElementType& key
      );

   /// get the set container
   virtual const SetContainer& setContainer
      (
      )const;

   /// get a null value
   static SetContainer nullObject
      (
      );

protected:
   /// the internal representation of the set.
   SetContainer m_SetContainer;
};

/// This template class is defined for the following:
typedef EcXmlSetType<EcXmlU32> EcXmlU32Set;

#endif // ecXmlSetType_H_
