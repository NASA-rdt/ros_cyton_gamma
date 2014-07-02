#ifndef ecRenderWindowParameters_H_
#define ecRenderWindowParameters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderWindowParameters.h
/// @class EcRenderWindowParameters
/// @brief Holds a description of display parameters for a
///        rendering window.
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <sensCore/ecPixel.h>

/** Holds a description of display parameters for a rendering window.
*/
class EC_RENDER_RENDCORE_DECL EcRenderWindowParameters : public EcXmlCompoundType
{
public:
   /// default constructor
   EcRenderWindowParameters
      (
      );

   /// destructor
   virtual ~EcRenderWindowParameters
      (
      );

   /// copy constructor
   EcRenderWindowParameters
      (
      const EcRenderWindowParameters& orig
      );

   /// assignment operator
   EcRenderWindowParameters& operator=
      (
      const EcRenderWindowParameters& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcRenderWindowParameters& orig
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

   /// get the window width
   virtual EcU32 width
      (
      ) const;

   /// set the window width
   virtual void setWidth
      (
      EcU32 width
      );

   /// get the window height
   virtual EcU32 height
      (
      ) const;

   /// set the window height
   virtual void setHeight
      (
      EcU32 height
      );

   /// get the upper left-hand corner
   virtual const EcPixel& upperLeftCorner
      (
      ) const;

   /// set the upper left-hand corner
   virtual void setUpperLeftCorner
      (
      const EcPixel& upperLeftCorner
      );

   /// get the number of color channels
   virtual EcU32 numChannels
      (
      ) const;

   /// get the number of color channels
   virtual void setNumChannels
      (
      EcU32 numChannels
      );

   /// get the background color
   virtual const EcXmlU8Vector& backgroundColor
      (
      ) const;

   /// set the background color
   virtual void setBackgroundColor
      (
      const EcXmlU8Vector& backgroundColor
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
   static EcRenderWindowParameters nullObject
      (
      );

protected:
   EcXmlU32          m_Width;
   EcXmlU32          m_Height;
   EcPixel           m_UpperLeftCorner;
   EcXmlU32          m_NumChannels;
   EcXmlU8Vector     m_BackgroundColor;
   EcXmlBoolean      m_UsePBuffering;
};

#endif // ecRenderWindowParameters_H_
