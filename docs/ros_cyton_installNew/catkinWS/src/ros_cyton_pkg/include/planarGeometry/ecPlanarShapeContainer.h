#ifndef ecPlanarShapeContainer_H_
#define ecPlanarShapeContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecPlanarShapeContainer.h
/// @class EcPlanarShapeContainer
/// @brief A container to hold planar shapes
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecPlanarShape.h"

#include <xml/ecBaseExpTreeContainer.h>
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// A container to hold planar shapes
class EC_FOUNDATION_PLANARGEOMETRY_DECL EcPlanarShapeContainer : public EcXmlVariableElementType<EcPlanarShape>
{
public:
   /// default constructor
   EcPlanarShapeContainer
      (
      );

   /// destructor
   virtual ~EcPlanarShapeContainer
      (
      );

   /// copy constructor
   EcPlanarShapeContainer
      (
      const EcPlanarShapeContainer& orig
      );

   /// assignment operator
   EcPlanarShapeContainer& operator=
      (
      const EcPlanarShapeContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPlanarShapeContainer& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
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

   /// get an empty container
   static EcPlanarShapeContainer nullObject
      (
      );

   /// the creator function for this object
   static EcXmlObject* creator
      (
      );

   /// returns a class token
   static const EcToken& classToken
      (
      );

   /// virtual method returning the token for this object
   virtual const EcToken& token
      (
      ) const;
};

#endif // ecPlanarShapeContainer_H_
