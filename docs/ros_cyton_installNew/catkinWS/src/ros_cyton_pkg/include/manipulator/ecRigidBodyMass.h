#ifndef ecRigidBodyMass_H_
#define ecRigidBodyMass_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecRigidBodyMass.h
/// @class EcRigidBodyMassProperties
/// @brief Represents rigid body mass properties: mass, first
///        moment, and second moment.  The second moment is with
///        respect to the origin of the representation (not with
///        respect to the center of mass).
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecGeneralForce.h>
#include <foundCore/ecNonnegReal.h>
#include <matrixUtilities/ecReArray.h>
#include <foundCommon/ecSecondMoment.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

// forward declarations
class EcCapsule;
class EcGeneralMotion;
class EcXmlVector;
class EcEllipsoid;

/** Holds rigid body mass properties.  The mass properties is a
 set of 10 unique values: mass, first moment of inertia, and
 second moment of inertia.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcRigidBodyMassProperties : public EcXmlCompoundType
{
public:
   /// default constructor
   EcRigidBodyMassProperties
      (
      );

   /// constructor with all components
   EcRigidBodyMassProperties
      (
      const EcXmlNonNegReal& mass,
      const EcXmlVector& firstMoment,
      const EcSecondMoment& secondMoment
      );

   /// destructor
   virtual ~EcRigidBodyMassProperties
      (
      );

   /// copy constructor
   EcRigidBodyMassProperties
      (
      const EcRigidBodyMassProperties& orig
      );

   /// assignment operator
   EcRigidBodyMassProperties& operator=
      (
      const EcRigidBodyMassProperties& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcRigidBodyMassProperties& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
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

   /// add another mass properties to this and set this to the result
   EcRigidBodyMassProperties& operator+=
      (
      const EcRigidBodyMassProperties& mp2
      );

   /// subtract another mass properties from this and set this to the result
   EcRigidBodyMassProperties& operator-=
      (
      const EcRigidBodyMassProperties& mp2
      );

   /// add another mass properties to this and return the result
   EcRigidBodyMassProperties  operator+
      (
      const EcRigidBodyMassProperties& mp2
      ) const;

   /// subtract another mass properties from this and return the result
   EcRigidBodyMassProperties  operator-
      (
      const EcRigidBodyMassProperties& mp2
      ) const;

   /// general transformation.  Returns the transformed entity.
   virtual EcRigidBodyMassProperties& transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// rotation.  Returns the transformed entity
   virtual EcRigidBodyMassProperties& transformBy
      (
      const EcOrientation& orientation
      );

   /// offset.  Returns the transformed entity
   /// Note that this takes mass properties represented at the tip of
   /// the transformation vector and expresses it at the origin.
   virtual EcRigidBodyMassProperties& transformBy
      (
      const EcVector& translation
      );

   /// calculates the force on the rigid body needed to produce the velocity and acceleration
   virtual EcGeneralForce calculateForce
      (
      const EcGeneralMotion& vel,
      const EcGeneralMotion& acc
      ) const;

   /// calculates the force on the rigid body needed to produce the acceleration
   /// with no velocity
   virtual EcGeneralForce calculateForce
      (
      const EcGeneralMotion& acc
      ) const;

   /// calculates the acceleration of the rigid body given the velocity and applied force
   virtual EcGeneralMotion calculateAcceleration
      (
      const EcGeneralMotion& vel,
      const EcGeneralForce& genForce
      ) const;

   /// calculates the acceleration produced by the specified force when there is no
   /// velocity
   virtual EcGeneralMotion calculateAcceleration
      (
      const EcGeneralForce& genForce
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets mass
   virtual const EcNonNegReal& mass
      (
      ) const;

   /// gets the first moment
   virtual const EcVector& firstMoment
      (
      ) const;

   /// gets the second moment
   /// expressed at the point of application, not at the center of mass.
   virtual const EcSecondMoment& secondMoment
      (
      ) const;

   /// gets the inverse of the second moment
   /// expressed at the center of mass, not at the point of application.
   virtual const EcSpatialMatrix& invSecondMoment
      (
      ) const;

   /// sets mass, first moment, and second moment
   /**
   \param[in] mass The mass.
   \param[in] firstMoment The first moment of inertia.
   \param[in] secondMoment The second moment of inertia. It is expressed at the point of application, not the center of mass.
   \param[in] checkValidity If true, the validity of the second moment is checked and if it's invalid, an attempt will be made to make it valid. This is the default. If checkValidity is false, then there'll be no attempt to make the mass properties valid. The supplied values will be used as is.
   */
   virtual void set
      (
      EcNonNegReal mass,
      const EcVector& firstMoment,
      const EcSecondMoment& secondMoment,
      EcBoolean checkValidity=EcTrue
      );

   /// get the center-of-mass vector
   virtual void getCenterOfMass
      (
      EcVector& centerOfMass
      ) const;

   /// get the principal frame
   /// this frame is centered at the center of mass
   /// and is oriented along the principal axes of ineria, with
   /// the x-axis having the maximum moment of ineria, and the z-axis
   /// having the minimum.
   virtual EcBoolean getPrincipalFrame
      (
      EcCoordinateSystemTransformation& principalFrame
      ) const;

   /// checks validity.
   virtual EcBoolean isValid
      (
      ) const;

   /// the Cholesky decomposition of the spatial inertia matrix.
   /// (i.e., lower-triangular L such that L*L^T=|mI H^T|
   ///                                           |H   J |
   virtual const EcReArray& spatialCholeskyDecomposition
      (
      ) const;

   /// get the spatial inertia as a 6x6 array
   virtual void getArray
      (
      EcReArray& array
      ) const;

   /// test for approximate equality
   virtual EcBoolean approxEq
      (
      const EcRigidBodyMassProperties& sm2,
      EcReal tol
      ) const;

   /// scale the mass properties by a distance scale factor
   /// this assumes constant density, so that mass scales with
   /// the cube of the scale factor, for example
   virtual void scaleBy
      (
      EcReal scaleFactor
      );

   /// return an approximating ellipsoid and the corresponding
   /// mass density
   virtual void getEllipsoid
      (
      EcEllipsoid& ellipsoid,
      EcReal& massDensity
      ) const;

   /// make the rigid body mass valid by tweaking its elements. This does nothing if it's already valid.
   virtual void makeValid
      (
      );

   /// @copydoc EcXmlObject::token()
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

   /// get an zero second moment
   static EcRigidBodyMassProperties nullObject
      (
      );

   /// standard mass property object
   static EcRigidBodyMassProperties defaultObject
      (
      );

   /// a point mass with zero offset
   static EcRigidBodyMassProperties pointMass
      (
      EcReal mass
      );

   /// a uniform sphere with a given mass and radius
   /// centered at the origin
   static EcRigidBodyMassProperties uniformSolidSphere
      (
      EcReal mass,
      EcReal radius
      );

   /// a uniform hemisphere with a given mass and radius, with
   /// axis along the z axis and flat portion aligned with the
   /// x-y plane.  The hemisphere protrudes in the direction of
   /// the positive z-axis.
   static EcRigidBodyMassProperties uniformSolidHemisphere
      (
      EcReal mass,
      EcReal radius
      );

   /// a uniform shell with a given mass and radius
   /// centered at the origin
   static EcRigidBodyMassProperties uniformSphericalShell
      (
      EcReal mass,
      EcReal radius
      );

   /// a uniform elipsoid aligned with the axes, with given
   /// semiaxes along x, y, and z centered at the origin
   static EcRigidBodyMassProperties uniformSolidAxisAlignedEllipsoid
      (
      EcReal mass,
      EcReal semiaxisX,
      EcReal semiaxisY,
      EcReal semiaxisZ
      );

   /// a uniform rectangular prism aligned with the axes, with given
   /// lengths along x, y, and z.
   /// centered at the origin
   static EcRigidBodyMassProperties uniformSolidAxisAlignedRectangularPrism
      (
      EcReal mass,
      EcReal lengthAlongX,
      EcReal lengthAlongY,
      EcReal lengthAlongZ
      );

   /// a uniform solid cylinder with axis the z-axis with radius and
   /// end-to-end length as specified
   /// centered at the origin
   static EcRigidBodyMassProperties uniformSolidAxisAlignedCylinder
      (
      EcReal mass,
      EcReal radius,
      EcReal length
      );

   /// a uniform solid torus encircling the z-axis
   /// centered at the origin
   static EcRigidBodyMassProperties uniformSolidAxisAlignedTorus
      (
      EcReal mass,
      EcReal bigRadius,
      EcReal littleRadius
      );

   /// a uniform capsule with a given mass
   static EcRigidBodyMassProperties uniformSolidCapsule
      (
      EcReal mass,
      const EcCapsule& capsule
      );

protected:

   /// computes the inverse of the second moment of inertia
   virtual void computeSecondMomentInverse
      (
      )const;

   /// scalar mass
   EcXmlNonNegReal m_Mass;

   /// vector first moment
   EcXmlVector     m_FirstMoment;

   /// second moment (equivalent to a symmectric 3x3 matrix)
   /// expressed at the point of application, not at the center of mass.
   EcSecondMoment  m_SecondMoment;

   /// the inverse of the moment of inertia, added here for speed
   mutable EcSpatialMatrix m_InverseSecondMoment;

   /// flag indicating if the inverse second moment matrix is valid
   mutable EcBoolean       m_InverseSecondMomentValid;

   // mutable values for efficiency below (avoid reuse in derived classes)
   mutable EcReArray m_SpatialCholeskyDecomposition;        ///< The spatial Cholesky decomposition
   mutable EcBoolean m_IsSpatialCholeskyDecompositionValid; ///< The spatial Cholesky decomposition valid flag
};

/// an XML vector of mass properties
typedef EcXmlVectorType<EcRigidBodyMassProperties>
   EcRigidBodyMassPropertiesVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the second moment in a transformed frame
EC_FOUNDATION_MANIPULATOR_DECL EcRigidBodyMassProperties transform
   (
   const EcCoordinateSystemTransformation& xform,
   const EcRigidBodyMassProperties& mp
   );

/// expresses the second moment in a rotated frame
EC_FOUNDATION_MANIPULATOR_DECL EcRigidBodyMassProperties transform
   (
   const EcOrientation& q,
   const EcRigidBodyMassProperties& mp
   );

/// expresses the second moment in an offset frame
EC_FOUNDATION_MANIPULATOR_DECL EcRigidBodyMassProperties transform
   (
   const EcVector& off,
   const EcRigidBodyMassProperties& mp
   );

#endif // ecRigidBodyMass_H_
