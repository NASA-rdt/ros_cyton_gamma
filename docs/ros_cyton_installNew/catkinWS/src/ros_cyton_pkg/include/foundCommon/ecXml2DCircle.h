#ifndef ecXml2DCircle_H_
#define ecXml2DCircle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecXml2DCircle.h
/// @class EcXml2DCircle
/// @brief implementation of the EcXml2DCircle class;
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.

#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>


#include <foundCommon/ecXml2DShape.h>

/*!
\class EcXml2DCircle
\brief EcXml2DCircle - defines circle
\version 1.0
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcXml2DCircle : public EcXml2DShape
{
public:


   /// Constructor
   EcXml2DCircle
      (
      );

   /// Destructor
   virtual ~EcXml2DCircle
      (
      );

   /// Copy constructor
   EcXml2DCircle
      (
      const EcXml2DCircle& orig
      );

   /// Copy assignment operator
   EcXml2DCircle& operator=
      (
      const EcXml2DCircle& orig
      );

   /// Equality operator
   EcBoolean operator==
      (
      const EcXml2DCircle& orig
      ) const;

   /// Clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// Register components with the parent
   virtual void registerComponents
      (
      );

   /// Equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// Virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// Return a string token
   virtual const EcToken& token
      (
      ) const;

    /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   /// returns true if the shape allows arc else false
   virtual EcBoolean allowArcs
      (
      );

   /// returns the number of vertices used for the shape
   virtual EcU32 numVertices
      (
      );

   /// returns id for the shape
   virtual const EcString id
      (
      )const;

   /// copies the data into the newData
   virtual void copyData
      (
      EcXml2DShape* newData
      );

   /// returns true or face based on given point is inside the shape or not
   virtual EcBoolean contains
      (
      EcReal x,
      EcReal y
      );


protected:

   EcXmlReal m_CenterX;  ///< X coordinate of the rectangle center (pixels)
   EcXmlReal m_CenterY;  ///< Y Coordinate of the rectangle center (pixels)
   EcXmlReal m_Radius;   ///< radius of the cicle (pixels)

};

#endif //
