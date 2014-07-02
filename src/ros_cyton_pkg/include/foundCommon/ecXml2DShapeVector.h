#ifndef ecXml2DShapeVector_H_
#define ecXml2DShapeVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2005-2013 Energid Technologies. All rights reserved.
//
/// @file ecXml2DShapeVector.h
/// @class EcXml2DShapeVector
/// @brief implementation of the EcXml2DShapeVector class.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecXml2DShape.h"
#include <xml/ecXmlVarVectType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// a vector of 2D shapes (any object subclassed from EcXml2DShape)
typedef EcXmlVariableVectorType<EcXml2DShape> EcBase2DShapeVector;

/*!
\class EcXml2DShapeVector
\brief This is vector EcXml2DShapes
\ It can have EcXml2DRectangle, EcXml2DEllipse, EcXml2DPolygon, EcXml2DCircle are derived from EcXml2DShape
\version 1.0
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcXml2DShapeVector: public EcBase2DShapeVector
{
public:
   /// constructor
   EcXml2DShapeVector
      (
      );

   /// destructor
   virtual ~EcXml2DShapeVector
      (
      );

   /// copy constructor
   EcXml2DShapeVector
      (
      const EcXml2DShapeVector& orig
      );

   /// assignment operator
   EcXml2DShapeVector& operator=
      (
      const EcXml2DShapeVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcXml2DShapeVector& orig
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

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

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
   static EcXml2DShapeVector nullObject
      (
      );
};

#endif // ecXml2DShapeVector_H_
