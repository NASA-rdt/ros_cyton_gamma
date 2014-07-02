#ifndef ecXmlEnumType_H_
#define ecXmlEnumType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlEnumType.h
/// @class EcXmlEnumType
/// @brief A template class for basic enumeration types that can be read from and
///        written to XML streams.
//
//------------------------------------------------------------------------------
#include "ecBaseXmlBasicType.h"
#include <foundCore/ecNonnegReal.h>

template<class BasicType>
class EcXmlEnumType : public EcBaseXmlBasicType
{
public:
   /// #ECDECLARE_BIGFOUR(EcCls) Macro declares a constructor, destructor,
   /// copy constructor, equal operator, and equality operator
   ECDECLARE_BIGFOUR(EcXmlEnumType<BasicType>);
   ECXMLOBJECT_ACCEPT(EcXmlEnumType<BasicType>)

   /// constructor from the basic type (implicit construction okay)
   EcXmlEnumType<BasicType>
      (
      const BasicType& val
      );

   /// assignment operator using basic type
   EcXmlEnumType<BasicType>& operator=
      (
      const BasicType& val
      );

   /// cast to the const basic type
   operator const BasicType&
      (
      ) const;

   /// less-than operator
   EcBoolean operator<
      (
      const EcXmlEnumType<BasicType>& orig
      ) const;

   /// clone
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// read
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// read
   EcBoolean readAttribute
      (
      EcXmlReader& stream
      );

   /// write
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// write schema
   virtual EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

   /// Return true/false for basic type
   virtual EcBoolean isBasicType
      (
      ) const;

   /// get the value - const version
   virtual const BasicType& value
      (
      ) const;

   /// get the value - nonconst version
   virtual BasicType& value
      (
      );

   /// set the value
   virtual void setValue
      (
      const BasicType& val
      );

   /// get the enumeration
   virtual const EcString &enumString
      (
      ) const;

   /// get the enumeration (based on input value)
   virtual const EcString &enumString
      (
      const BasicType &val
      ) const;

   /// set the enumeration
   virtual void  setEnumString
      (
      const BasicType &enumVal,
      const EcString &enumText
      );

   /// find the enumeration
   virtual EcBoolean findEnumString
      (
      const EcString &enumText,
      BasicType &value
      );

   /// set the value from a string
   virtual void setValueFromString
      (
      const EcString& string
      );

   /// get a null value
   static EcXmlEnumType<BasicType> nullObject
      (
      );

   /// token to use when writing out to xml.
   const EcToken& token
      (
      ) const;

protected:

   BasicType               m_Value;             ///< Basic value
   std::vector<BasicType>  m_vEnumConstants;    ///< enum constants
   EcStringVector          m_vEnumStrings;      ///< list of enums
};

/// This template class is defined for the following:

/// An enumerated unsigned value that can read and write to an XML stream.
typedef EcXmlEnumType<EcU32>        EcXmlEnumU32;

/// An enumerated int value that can read and write to an XML stream.
typedef EcXmlEnumType<EcInt32>      EcXmlEnumInt32;

/// An enumerated 16-bit unsigned integer that can read and write to an XML stream.
typedef EcXmlEnumType<EcU16>        EcXmlEnumU16;

/// An enumerated 16-bit integer that can read and write to an XML stream.
typedef EcXmlEnumType<EcInt16>      EcXmlEnumInt16;

/// An enumerated 8-bit unsigned integer that can read and write to an XML stream.
typedef EcXmlEnumType<EcU8>         EcXmlEnumU8;

/// An enumerated nonnegative floating-point number that can read and write to an XML stream.
typedef EcXmlEnumType<EcNonNegReal> EcXmlEnumNonNegReal;

/// An enumerated boolean that can read and write to an XML stream.
typedef EcXmlEnumType<EcBoolean>    EcXmlEnumBoolean;

#endif // ecXmlEnumType_H_
