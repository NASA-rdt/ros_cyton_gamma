#ifndef ecXmlBasicType_H_
#define ecXmlBasicType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlBasicType.h
/// @class EcXmlBasicType
/// @brief A template class for basic types that can be read and
///        written to XML streams.
/// @details This class is nonvirtual for speed optimization.  These objects are
///         just stand-ins for rudimentary C++ types (double, float, int, etc.)
///         that can read/write themselves.
//
//------------------------------------------------------------------------------
#include "ecBaseXmlBasicType.h"

class EcAngle;
class EcNonNegReal;

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

template<class BasicType>
class EcXmlBasicType : public EcBaseXmlBasicType
{
public:
   /// default constructor
   EcXmlBasicType<BasicType>
      (
      );

   /// constructor from the basic type (implicit construction okay)
   EcXmlBasicType<BasicType>
      (
      const BasicType& val
      );

   /// destructor
   ~EcXmlBasicType<BasicType>
      (
      );

   /// copy constructor
   EcXmlBasicType<BasicType>
      (
      const EcXmlBasicType<BasicType>& orig
      );

   /// assignment operator
   EcXmlBasicType<BasicType>& operator=
      (
      const EcXmlBasicType<BasicType>& orig
      );

   /// assignment operator using basic type
   inline EcXmlBasicType<BasicType>& operator=
      (
      const BasicType& val
      )
   {
      m_Value = val;
      return *this;
   }

   /// equality operator
   EcBoolean operator==
      (
      const EcXmlBasicType<BasicType>& orig
      ) const;

   /// cast to the const basic type
   inline operator const BasicType&
      (
      ) const
   {
      return m_Value;
   }

   /// less-than operator
   EcBoolean operator<
      (
      const EcXmlBasicType<BasicType>& orig
      ) const;

   /// clone
   EcXmlObject* clone
      (
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   EcXmlObject* newObject
      (
      ) const;

   /// read
   /// @param[out] stream Input XML stream to read from
   /// @return EcBoolean
   EcBoolean read
      (
      EcXmlReader& stream
      );

   /// read
   EcBoolean readAttribute
      (
      EcXmlReader& stream
      );

   /// write
   /// @param[out] stream Output XML stream to write to
   /// @return EcBoolean
   EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// write schema
   EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

   /// Return true/false for basic type
   EcBoolean isBasicType
      (
      ) const;

   /// get the value - const version
   inline const BasicType& value
      (
      ) const
   {
      return m_Value;
   }

   /// get the value - nonconst version
   inline BasicType& value
      (
      )
   {
      return m_Value;
   }

   /// set the value
   inline void setValue
      (
      const BasicType& val
      )
   {
      m_Value=val;
   }

   /// get a null value
   static EcXmlBasicType<BasicType> nullObject
      (
      );

   /// token to use when writing out to xml.
   const EcToken& token
      (
      ) const;

   /// set the value from a string
   virtual void setValueFromString
      (
      const EcString& string
      );

   /// support for visitor pattern
   ECXMLOBJECT_NVACCEPT(EcXmlBasicType<BasicType>)

protected:

   BasicType m_Value;      ///< Basic value
};

/// This template class is defined for the following:

/// a real that can read and write to an XML stream.
typedef EcXmlBasicType<EcReal>          EcXmlReal;

/// a time value that can read and write to an XML stream.
typedef EcXmlBasicType<EcTime>          EcXmlTime;

/// an unsigned 32-bit integer that can read and write to an XML stream.
typedef EcXmlBasicType<EcU32>           EcXmlU32;

/// an signed 32-bit integer that can read and write to an XML stream.
typedef EcXmlBasicType<EcInt32>         EcXmlInt32;

/// an unsigned 16-bit integer that can read and write to an XML stream.
typedef EcXmlBasicType<EcU16>           EcXmlU16;

/// an signed 16-bit integer that can read and write to an XML stream.
typedef EcXmlBasicType<EcInt16>         EcXmlInt16;

/// an unsigned 8-bit integer that can read and write to an XML stream.
typedef EcXmlBasicType<EcU8>            EcXmlU8;

/// a signed 8-bit integer that can read and write to an XML stream.
typedef EcXmlBasicType<EcInt8>          EcXmlInt8;

/// an angle that can read and write to an XML stream.
typedef EcXmlBasicType<EcAngle>         EcXmlAngle;

/// a nonnegative real value that can read and write to an XML stream.
typedef EcXmlBasicType<EcNonNegReal>    EcXmlNonNegReal;

/// a character string that can read and write to an XML stream.
typedef EcXmlBasicType<EcString>        EcXmlString;

/// a boolean that can read and write to an XML stream.
typedef EcXmlBasicType<EcBoolean>       EcXmlBoolean;

/// writes the basic value to stream
template<class BasicType>
std::ostream& operator<<
   (
   std::ostream& stream,
   const EcXmlBasicType<BasicType>& orig
   )
{
   stream << orig.value();

   return stream;
}

// Make sure and specify that this library exports these symbols so that they
// are not duplicated elsewhere.  Only needed on windows
#  if defined(WIN32) && defined(EC_BUILD_SHARED_LIBS) && !defined(stableFoundation_xml_EXPORTS)
extern template class EC_DECL_IMPORTS EcXmlBasicType<EcReal>;
extern template class EC_DECL_IMPORTS EcXmlBasicType<EcU32>;
extern template class EC_DECL_IMPORTS EcXmlBasicType<EcInt32>;
extern template class EC_DECL_IMPORTS EcXmlBasicType<EcU16>;
extern template class EC_DECL_IMPORTS EcXmlBasicType<EcInt16>;
extern template class EC_DECL_IMPORTS EcXmlBasicType<EcInt8>;
extern template class EC_DECL_IMPORTS EcXmlBasicType<EcU8>;
extern template class EC_DECL_IMPORTS EcXmlBasicType<EcString>;
extern template class EC_DECL_IMPORTS EcXmlBasicType<EcBoolean>;
#  endif

#endif // ecXmlBasicType_H_
