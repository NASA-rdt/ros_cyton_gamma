#ifndef ecGraspQualityMeasure_H_
#define ecGraspQualityMeasure_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspQualityMeasure.h
/// @class EcGraspQualityMeasure
/// @brief Measure of grasp quality
/// @todo Accessors and mutators should be moved into the cpp file
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecGraspContactPointData.h"
#include <foundCommon/ecGeneralForce.h>
#include <matrixUtilities/ecReArray.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>
#include <xml/ecXmlVectorVector.h>

// Forward declarations

class EC_ACTIN_GRASPING_DECL EcGraspQualityMeasure : public EcXmlCompoundType
{
public:
   /// default constructor
   EcGraspQualityMeasure
      (
      );

   /// destructor
   virtual ~EcGraspQualityMeasure
      (
      );

   /// copy constructor
   EcGraspQualityMeasure
      (
      const EcGraspQualityMeasure& orig
      );

   /// assignment operator
   EcGraspQualityMeasure& operator=
      (
      const EcGraspQualityMeasure& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspQualityMeasure& orig
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

   /// default XML token
   virtual const EcToken& token
      (
      ) const;

   /// get the number of sides of the pyramid approximation of the friction cone
   virtual EcU8 numPyramideSides
      (
      ) const;

   /// set the number of sides of the pyramid approximation of the friction cone
   virtual void setNumPyramidSides
      (
      const EcU8 numSides
      );

   /// get the origin
   virtual const EcVector& origin
      (
      ) const;

   /// set the origin, usually it's the center of mass of the grasp object
   virtual void setOrigin
      (
      const EcVector& origin
      );

   /// get the contact point data
   virtual const EcGraspContactPointDataVector& contactPointData
      (
      ) const;

   /// set the contact point data
   virtual void setContactPointData
      (
      const EcGraspContactPointDataVector& contactPointData
      );

   /// get the wrench used to in computation of the grasp quality.
   /// Note: Currently, it's not being used
   virtual const EcGeneralForce& externalWrench
      (
      ) const;

   /// set the wrench used to in computation of the grasp quality.
   /// Note: Currently, it's not being used
   virtual void setExternalWrench
      (
      const EcGeneralForce& wrench
      );

   /// compute the grasp quality measure
   virtual void compute
      (
      );

   /// return whether the grasp is deemed stable
   virtual EcBoolean isGraspStable
      (
      ) const
   { return m_IsStable; }

   /// return the minimum offset of the wrench space convex hull, which can be used as a measure of how efficient this grasp is at handling the worst case
   virtual EcReal minimumOffset
      (
      ) const
   { return m_Epsilon; }

   /// return the volume of the wrench space convex hull, which can be used as an invariant average case quality measure for this grasp
   virtual EcReal volume
      (
      ) const
   { return m_Volume; }

   /// compute and return the points of 3D projection of the wrench space convex hull in which the torque coordinates are fixed to 0. Only valid if grasp is stable.
   virtual const EcXmlVectorVector& zeroTorqueProjection
      (
      );

   /// compute and return the points of 3D projection of the wrench space convex hull in which the torque coordinates are fixed to the torque values of the most difficult wrench for this grasp to apply (i.e. at the minimum offset). Only valid if grasp is stable.
   virtual const EcXmlVectorVector& minTorqueProjection
      (
      );

   /// compute and return the points of 3D projection of the wrench space convex hull in which the force coordinates are fixed to 0. Only valid if grasp is stable.
   virtual const EcXmlVectorVector& zeroForceProjection
      (
      );

   /// compute and return the points of 3D projection of the wrench space convex hull in which the force coordinates are fixed to the force values of the most difficult wrench for this grasp to apply (i.e. at the minimum offset). Only valid if grasp is stable.
   virtual const EcXmlVectorVector& minForceProjection
      (
      );

protected:
   /// the number of sides of the pyramid approximation of the friction cone
   EcXmlU8        m_NumPyramidSides;

   /// the origin, often the center of mass of the grasp object
   EcVector       m_Origin;

   /// contact points for the grasp
   EcGraspContactPointDataVector m_vContactPointData;

   /// the external force and moment for the grasp
   EcGeneralForce m_ExternalWrench;

   /// a flag indicating the grasp is stable
   EcBoolean      m_IsStable;

   /// the minimum offset of the wrench space convex hull
   EcReal         m_Epsilon;

   /// the volume of the wrench space convex hull, which can be used as an invariant average case quality measure for this grasp
   EcReal         m_Volume;

   /// the 6D halfspaces of the convex hull represented by the normals and offsets
   EcReArray      m_Halfspaces;     

   /// used in computeConvexHull to calculate the projection of the origin onto the minimum facet
   EcVector       m_MinForce;

   /// used in computeConvexHull to calculate the projection of the origin onto the minimum facet
   EcVector       m_MinTorque;

   /// a vector of vectors used in computeConvexHull()
   EcXmlVectorVector m_ProjectionPoints;

private:
   /// compute the wrench space convex hull
   void computeConvexHull
      (
      );

   /// compute and return the 3D projection of the wrench space convex hull
   void computeProjection
      (
      EcBoolean force,
      EcBoolean zero
      );
};

#endif // ecGraspQualityMeasure_H_
