#ifndef ecXml2DPoint_H_
#define ecXml2DPoint_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecXml2DPoint.h
/// @class EcXml2DPoint
/// @brief implementation of the EcXml2DPoint class;
/// @todo should numVertices return 1?
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.

#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

#include <foundCommon/ecXml2DShape.h>

/*!
\class EcXml2DPoint
\brief EcXml2DPoint - defines a point in X-Y plain
\version 1.0
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcXml2DPoint : public EcXmlCompoundType
{
public:


   /// Constructor
   EcXml2DPoint
      (
      );

   /// Destructor
   virtual ~EcXml2DPoint
      (
      );

   /// Copy constructor
   EcXml2DPoint
      (
      const EcXml2DPoint& orig
      );

   /// Copy assignment operator
   EcXml2DPoint& operator=
      (
      const EcXml2DPoint& orig
      );

   /// Equality operator
   EcBoolean operator==
      (
      const EcXml2DPoint& orig
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

   /// Returns zero
   virtual EcU32 numVertices
      (
      );

   /// Returns the string "Point"
   virtual EcString id
      (
      );

   /// sets the X co-ordinate of the point
   void setX
      (
      EcReal x
      );

   /// returns the X co-ordinate of the point
   EcReal x
      (
      );

   /// sets the Y co-ordinate of the point
   void setY
      (
      EcReal y
      );

   /// returns the Y co-ordinate of the point
   EcReal y
      (
      );





protected:

   /// the x-coordinate of the point
   EcXmlReal  m_X;

   /// the y-coordinate of the point
   EcXmlReal  m_Y;


};

/// an XML readable/writable vector of EcXml2DPoint objects
typedef  EcXmlVectorType<EcXml2DPoint>  EcPointVector;

#endif // ecXml2DPoint_H_
