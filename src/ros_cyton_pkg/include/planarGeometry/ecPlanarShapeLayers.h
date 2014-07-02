#ifndef ecPlanarShapeLayers_H_
#define ecPlanarShapeLayers_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecPlanarShapeLayers.h
/// @brief A collection of EcPlanarhape objects arranged in layers from bottom to top
/// @details EcPlanarShapeLayers
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecPlanarShapeVector.h"

/// A collection of EcPlanarhape objects arranged in layers from bottom to top
class EC_FOUNDATION_PLANARGEOMETRY_DECL EcPlanarShapeLayers : public EcXmlCompoundType
{
public:
   /// default constructor - should not be used
   EcPlanarShapeLayers
      (
      );

   /// destructor
   virtual ~EcPlanarShapeLayers
      (
      );

   /// copy constructor
   EcPlanarShapeLayers
      (
      const EcPlanarShapeLayers& orig
      );

   /// assignment operator
   EcPlanarShapeLayers& operator=
      (
      const EcPlanarShapeLayers& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPlanarShapeLayers& orig
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

   /// get the number of layers
   virtual EcU32 numLayers
      (
      ) const;

   /// get a layer
   virtual EcPlanarShape* layerAt
      (
      EcU32 layer
      );

   /// get a const layer
   virtual const EcPlanarShape* layerAt
      (
      EcU32 layer
      ) const;

   /// get all the layers
   virtual const EcPlanarShapeVector& layers
      (
      ) const;

   /// return the layer identifiers
   virtual EcStringVector layerIdentifiers
      (
      ) const;

   /// check the intersection with a point
   virtual const EcPlanarShape* checkIntersect
      (
      const EcPlanarVector& point
      ) const;

   /// add a shape as the bottom layer
   virtual void addLayerToBottom
      (
      const EcPlanarShape& shape
      );

   /// add a shape as the top layer
   virtual void addLayerToTop
      (
      const EcPlanarShape& shape
      );

   /// remove all layers
   virtual void clearLayers
      (
      );

   /// move a layer one step closer to the bottom
   /**
   \return True if index is valid and can be demoted or false otherwise.
   */
   virtual EcBoolean demoteLayer
      (
      EcU32 index
      );

   /// move a layer one step closer to the top
   /**
   \return True if index is valid and can be promoted or false otherwise.
   */
   virtual EcBoolean promoteLayer
      (
      EcU32 index
      );

   /// remove a layer at index
   /**
   \return True if index is valid or false otherwise.
   */
   virtual EcBoolean removeLayer
      (
      EcU32 index
      );

   /// determine if an identifier is currently used in a layer
   /**
   \return True if the identifier is currently used in a layer
   */
   virtual EcBoolean hasIdentifier
      (
      const EcString& identifier
      ) const;

   /// find an identifier that is not currently used in a layer
   /**
   \return Unique identifier string
   */
   virtual EcString uniqueIdentifier
      (
      const EcString& identifierBase
      ) const;

   /// get an empty object
   static EcPlanarShapeLayers nullObject
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

protected:
   /// vector of the shapes
   EcPlanarShapeVector m_ShapeVector;
};

#endif // ecPlanarShapeLayers_H_
