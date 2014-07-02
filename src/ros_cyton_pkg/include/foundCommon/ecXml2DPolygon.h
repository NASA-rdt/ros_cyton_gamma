#ifndef ecXml2DPolygon_H_
#define ecXml2DPolygon_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecXml2DPolygon.h
/// @class EcXml2DPolygon
/// @brief implementation of the EcXml2DPolygon class;
/// @todo accessor and mutator should pass by const reference
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.

#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

#include <foundCommon/ecXml2DShape.h>
#include <foundCommon/ecXml2DPoint.h>

/*!
\class EcXml2DPolygon
\brief EcXml2DPolygon - defines 2D polygon with 8 vertices
\version 1.0
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcXml2DPolygon : public EcXml2DShape
{
public:



   /// Constructor
   EcXml2DPolygon
      (
      );

   /// Destructor
   virtual ~EcXml2DPolygon
      (
      );

   /// Copy constructor
   EcXml2DPolygon
      (
      const EcXml2DPolygon& orig
      );

   /// Copy assignment operator
   EcXml2DPolygon& operator=
      (
      const EcXml2DPolygon& orig
      );

   /// Equality operator
   EcBoolean operator==
      (
      const EcXml2DPolygon& orig
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

   /// set the vertices
   void setPointVector
      (
      EcPointVector pointVector
      );

   /// get the vertices
   EcPointVector points
      (
      );

   /// returns true or face based on given point is inside the shape or not
   EcBoolean contains
      (
      EcReal x,
      EcReal y
      );



protected:

   /// the vertices
   EcPointVector   m_PointVector;
};

#endif // ecXml2DPolygon_H_
