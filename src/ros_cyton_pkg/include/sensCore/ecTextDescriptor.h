#ifndef ecTextDescriptor_H_
#define ecTextDescriptor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecTextDescriptor.h
/// @class EcTextDescriptor
/// @brief Hold a class for describing a text box to be rendered
///        to an EcImage
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include "ecPixel.h"
#include <xml/ecXmlCompType.h>

/// Hold a class for describing a text box to be rendered to an EcImage
class EC_SENSOR_SENSCORE_DECL EcTextDescriptor : public EcXmlCompoundType
{
public:

   typedef EcPixel EcCharSize;

   /// default constructor
   EcTextDescriptor
      (
      );

   /// default constructor
   EcTextDescriptor
      (
      const EcString& text,
      const EcPixel& bottomLeft
      );

   /// destructor
   virtual ~EcTextDescriptor
      (
      );

   /// copy constructor
   EcTextDescriptor
      (
      const EcTextDescriptor& orig
      );

   /// assignment operator
   EcTextDescriptor& operator=
      (
      const EcTextDescriptor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcTextDescriptor& orig
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

   /// get the rendering mode
   virtual const EcU32& renderingMode
      (
      );

   /// set the rendering mode
   virtual void setRenderingMode
      (
      EcU32 mode
      );

   /// get the font
   virtual const EcU32& font
      (
      )const;

   /// set the font
   virtual void setFont
      (
      const EcU32 font
      );

   /// get the text
   virtual const EcString& text
      (
      )const ;

   /// set the text
   virtual void setText
      (
      const EcString& text
      );

   /// get the lower-left anchor of the text
   virtual const EcPixel& textPosition
      (
      )const;

   /// set the lower-left anchor of the text
   virtual void setTextPosition
      (
      const EcPixel& position
      );
   /// get the point size of the text
   virtual const EcCharSize pointSize
      (
      )const;

   /// set the point size of the text
   virtual void setPointSize
      (
      const EcU32 charWdt,
      const EcU32 charHt=0// if char height  = 0, means, charHt=charWdt
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
   static EcTextDescriptor nullObject
      (
      );

protected:
   /// specifies the processing mode to use
   EcXmlU32   m_RenderingMode;

   /// specifies the font to use
   EcXmlU32   m_FontID;

   /// specifies the width of the font, single char
   EcXmlU32 m_CharWidth;

   /// specifies the height of the font, single char
   EcXmlU32 m_CharHeight;

   /// text to render
   EcXmlString m_Text;

   /// bottom left pixel
   EcPixel m_BottomLeft;
};

/// A vector of image blocks
typedef EcXmlVectorType<EcTextDescriptor> EcTextDescriptorVector;

#endif // ecTextDescriptor_H_
