#ifndef ecIntegerColor_H_
#define ecIntegerColor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecIntegerColor.h
/// @class EcIntegerColor
/// @brief Holds an integer-valued description of a color, with
///        a transparency value.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlSetType.h>

/** Holds an integer-valued description of a color, with a transparency value.
*/
class EC_FOUNDATION_VISUALIZATION_DECL EcIntegerColor : public EcXmlCompoundType
{
public:
   /// default constructor
   EcIntegerColor
      (
      );

   /// constructor from four reals
   EcIntegerColor
      (
      EcU8 r,
      EcU8 g,
      EcU8 b,
      EcU8 a
      );

   /// constructor from a 32-bit unsigned integer
   /// set from a U32 value in form [rgba]
   /// Note: for little-endian systems, the most
   /// significant byte becomes a and the least
   /// significant becomes r
   EcIntegerColor
      (
      EcU32 integerValue
      );

   /// destructor
   virtual ~EcIntegerColor
      (
      );

   /// copy constructor
   EcIntegerColor
      (
      const EcIntegerColor& orig
      );

   /// assignment operator
   EcIntegerColor& operator=
      (
      const EcIntegerColor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcIntegerColor& orig
      ) const;

   /// support for sorting
   /// compares as if color were converted to a 32-bit number
   /// as [r g b a].
   EcBoolean operator<
      (
      const EcIntegerColor& other
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// gets the red value
   virtual EcU8 red
      (
      ) const;

   /// sets the red value
   virtual void setRed
      (
      EcU8 red
      );

   /// gets the green value
   virtual EcU8 green
      (
      ) const;

   /// sets the green value
   virtual void setGreen
      (
      EcU8 green
      );

   /// gets the blue value
   virtual EcU8 blue
      (
      ) const;

   /// sets the blue value
   virtual void setBlue
      (
      EcU8 blue
      );

   /// gets the alpha value
   virtual EcU8 alpha
      (
      ) const;

   /// sets the alpha value
   virtual void setAlpha
      (
      EcU8 alpha
      );

   /// get a U32 value in form [rgba]
   virtual EcU32 integerValue
      (
      ) const;

   /// set from a U32 value in form [rgba]
   virtual void setFromIntegerValue
      (
      EcU32 integerValue
      );

   /// set from a U32 value in reverse form [abgr]
   virtual void setFromIntegerValueReverse
      (
      EcU32 integerValue
      );

   /// sets the r,g,b, or a value by byte number
   virtual void setRgbaByByteNumber
      (
      EcU32 byteNumber,
      EcU8 value
      );

   virtual const EcToken& token
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

   /// get a null object
   static EcIntegerColor nullObject
      (
      );

protected:
   /// red color
   EcXmlU8            m_Red;

   /// green color
   EcXmlU8            m_Green;

   /// blue color
   EcXmlU8            m_Blue;

   /// transparency value
   EcXmlU8            m_Alpha;
};

/// a set of integer colors
typedef EcXmlSetType<EcIntegerColor> EcIntegerColorSet;

#endif // ecIntegerColor_H_
