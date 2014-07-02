#ifndef ecXml2DShape_H_
#define ecXml2DShape_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecXml2DShape.h
/// @class EcXml2DShape
/// @brief implementation of the EcXml2DShape class; base class for all the 2D shapes
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.

#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

/*!
\class EcXml2DShape
\brief EcXml2DShape - base class for all the 2D shapes
\ Rectangle, ellipse, polygon, circle are derived from EcXml2DShape
\version 1.0
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcXml2DShape : public EcXmlCompoundType
{
public:


   /// Constructor
   EcXml2DShape
      (
      );

   /// Destructor
   virtual ~EcXml2DShape
      (
      );

   /// Copy constructor
   EcXml2DShape
      (
      const EcXml2DShape& orig
      );

   /// Copy assignment operator
   EcXml2DShape& operator=
      (
      const EcXml2DShape& orig
      );

   /// Equality operator
   EcBoolean operator==
      (
      const EcXml2DShape& orig
      ) const;


   ///set the name
   void setName
      (
      const EcString& name
      );

   ///returns the name
   const EcString& name
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



   /// Return a string token
   virtual const EcToken& token
      (
      ) const;

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
      )=0;

   /// sets bit flag for Shape
   void setShapeFlags
      (
      EcU32 flags
      );

   /// returns the bit flag that defines the properties of the shape
   EcU32 shapeFlags
      (
      ) const;

protected:


   EcXmlString   m_Name;          ///< name given to identify the region of interest
   EcXmlU32      m_ShapeBitFlags;  ///< Arbitrary bitflags to delineate different  classes
};

#endif // ecXml2DShape_H_

