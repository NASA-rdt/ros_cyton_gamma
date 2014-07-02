#ifndef ecColor_H_
#define ecColor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecColor.h
/// @class EcColor
/// @brief Holds a real-valued description of a color, with a transparency value.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

/** Holds a real-valued description of a color, with a transparency value.
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcColor : public EcXmlCompoundType
{
public:
   /// default constructor
   EcColor
      (
      );

   /// constructor from four reals
   EcColor
      (
      const EcReal r,
      const EcReal g,
      const EcReal b,
      const EcReal a
      );

   /// destructor
   virtual ~EcColor
      (
      );

   /// copy constructor
   EcColor
      (
      const EcColor& orig
      );

   /// assignment operator
   EcColor& operator=
      (
      const EcColor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcColor& orig
      ) const;

   /// support for sorting
   /// compares as if color were converted to a 32-bit number
   /// as [r g b a].
   EcBoolean operator<
      (
      const EcColor& other
      ) const;

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
   virtual EcReal red
      (
      ) const;

   /// sets the red value
   virtual void setRed
      (
      const EcReal red
      );

   /// gets the green value
   virtual EcReal green
      (
      ) const;

   /// sets the green value
   virtual void setGreen
      (
      const EcReal green
      );

   /// gets the blue value
   virtual EcReal blue
      (
      ) const;

   /// sets the blue value
   virtual void setBlue
      (
      const EcReal blue
      );

   /// gets the alpha value
   virtual EcReal alpha
      (
      ) const;

   /// sets the alpha value
   virtual void setAlpha
      (
      const EcReal alpha
      );

   /// sets the r,g,b, or a value by byte number
   virtual void setRgbaByByteNumber
      (
      const EcU32 byteNumber,
      const EcReal value
      );
   
   /// the (mostly) string token for this class
   virtual const EcToken& token
      (
      ) const;

   /// get a null object
   static EcColor nullObject
      (
      );

protected:

   /// red value
   EcXmlReal m_Red;   

   /// green value
   EcXmlReal m_Green; 

   /// blue value
   EcXmlReal m_Blue;  

   /// transparency value (0 is fully transparent)
   EcXmlReal m_Alpha; 
};

#endif // ecColor_H_
