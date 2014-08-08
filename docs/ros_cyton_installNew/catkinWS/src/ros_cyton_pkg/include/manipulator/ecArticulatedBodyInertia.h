#ifndef ecArticulatedBodyInertia_H_
#define ecArticulatedBodyInertia_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecArticulatedBodyInertia.h
/// @class EcArticulatedBodyInertia
/// @brief Holds articulated rigid body mass properties.  These include
///        a 3x3 symmetric linear term, a 3x3 symmetric angular term, and a cross
///        term.  If these were formed into a 6x6 spatial inertia matrix, it
///        would be as follows:
///        | Jl   Jc |
///        J = |         |
///        | Jc^T Ja |
///        Note that for rigid bodies, Jc = H^T, where H is the cross-product matrix
///        for the first moment of inertia.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <matrixUtilities/ecReArray.h>
#include <foundCommon/ecSecondMoment.h>
#include <foundCommon/ecSpatialMatrix.h>
#include <xml/ecXmlCompType.h>

// forward declarations
class EcCoordinateSystemTransformation;
class EcGeneralForce;
class EcGeneralMotion;
class EcRigidBodyMassProperties;

/** Holds articulated rigid body mass properties.  These include a
 3x3 symmetric linear term, a 3x3 symmetric angular term, and a cross
 term.  If these were formed into a 6x6 spatial inertia matrix, it
 would be as follows:

     | Jl   Jc |
 J = |         |
     | Jc^T Ja |

 Note that for rigid bodies, Jc = H^T, where H is the cross-product matrix
 for the first moment of inertia.

*/
class EC_FOUNDATION_MANIPULATOR_DECL EcArticulatedBodyInertia : public EcXmlCompoundType
{
public:
   /// default constructor
   EcArticulatedBodyInertia
      (
      );

   /// constructor with all components
   EcArticulatedBodyInertia
      (
      const EcSecondMoment&      linearMatrix,
      const EcSecondMoment&      angularMatrix,
      const EcSpatialMatrix&     crossMatrix,
      EcBoolean                  isRigid=EcFalse
      );

   /// constructor from rigid-body inertia
   explicit EcArticulatedBodyInertia
      (
      const EcRigidBodyMassProperties&  rigidBodyInertia
      );

   /// destructor
   virtual ~EcArticulatedBodyInertia
      (
      );

   /// copy constructor
   EcArticulatedBodyInertia
      (
      const EcArticulatedBodyInertia& orig
      );

   /// assignment operator
   EcArticulatedBodyInertia& operator=
      (
      const EcArticulatedBodyInertia& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcArticulatedBodyInertia& orig
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

   /// add another mass properties to this and set this to the result.
   /// the result is the inertia of a body formed by rigidly connecting
   /// the handle of this articulated body with that of another
   EcArticulatedBodyInertia& operator+=
      (
      const EcArticulatedBodyInertia& ap2
      );

   /// subtract another mass properties from this and set this to the result
   /// cancels the effect of +=
   EcArticulatedBodyInertia& operator-=
      (
      const EcArticulatedBodyInertia& ap2
      );

   /// add another mass properties to this and return the result
   /// the result is the inertia of a body formed by rigidly connecting
   /// the handle of this articulated body with that of another
   EcArticulatedBodyInertia  operator+
      (
      const EcArticulatedBodyInertia& ap2
      ) const;

   /// subtract another mass properties from this and return the result
   /// cancels the effect of +
   EcArticulatedBodyInertia  operator-
      (
      const EcArticulatedBodyInertia& ap2
      ) const;

   /// general transformation.  Returns the transformed entity.
   virtual EcArticulatedBodyInertia& transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// rotation.  Returns the transformed entity
   virtual EcArticulatedBodyInertia& transformBy
      (
      const EcOrientation& orientation
      );

   /// offset.  Returns the transformed entity
   /// Note that this takes mass properties represented at the tip of
   /// the transformation vector and expresses it at the origin.
   virtual EcArticulatedBodyInertia& transformBy
      (
      const EcVector& translation
      );

   /// general transformation.  Returns the transformed entity.
   /// This is an alternative (slower) method for testing.
   virtual EcArticulatedBodyInertia& transformBy2
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// joins this articlulated body with another through a joint.  This
   /// is changed to represent the inertia that results from jointing
   /// this with other through the joint defined by jointUnitAcceleration.
   virtual EcArticulatedBodyInertia& joinWith
      (
      const EcArticulatedBodyInertia& other,
      const EcGeneralMotion& jointUnitAcceleration,
      const EcReal& effectiveMotorInertia
      );

   /// joins this articlulated body with another through a joint.  Also
   /// returns two intermediate quantities--an intermediate frame force
   /// and an intermediate joint force
   virtual EcArticulatedBodyInertia& joinWith
      (
      const EcArticulatedBodyInertia& other,
      const EcGeneralMotion& jointUnitAcceleration,
      const EcReal& effectiveMotorInertia,
      EcGeneralForce& frameForce,
      EcReal& jointForce
      );

   /// sets this articlulated body to equal another passed through a joint.
   /// Also returns two intermediate quantities--an intermediate frame force
   /// and an intermediate joint force
   virtual EcArticulatedBodyInertia& setToTransformedValue
      (
      const EcArticulatedBodyInertia& other,
      const EcGeneralMotion& jointUnitAcceleration,
      const EcReal& effectiveMotorInertia,
      EcGeneralForce& frameForce,
      EcReal& jointForce
      );

   /// calculates the force on the rigid body needed to produce the acceleration
   /// with no velocity.
   virtual EcGeneralForce calculateForce
      (
      const EcGeneralMotion& acc
      ) const;

   /// calculates the force on the rigid body needed to produce the acceleration
   /// with no velocity.  Optimized for sparse input (a number of acceleration
   /// terms equal zero).
   virtual EcGeneralForce calculateForceSparse
      (
      const EcGeneralMotion& acc
      ) const;

   /// calculates the acceleration of the rigid body produced by the acceleration.
   /// Solves F=Ia*A for A by inverting Ia.
   virtual EcGeneralMotion calculateAcceleration
      (
      const EcGeneralForce& genForce
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets linear matrix as second moment
   virtual const EcSecondMoment& linearMatrix
      (
      ) const;

   /// gets angular matrix as second moment
   virtual const EcSecondMoment& angularMatrix
      (
      ) const;

   /// gets cross matrix
   virtual const EcSpatialMatrix& crossMatrix
      (
      ) const;

   /// gets the is-rigid flag
   virtual EcBoolean isRigid
      (
      ) const;

   /// sets general quantities
   virtual void set
      (
      const EcSecondMoment&    linearMatrix,
      const EcSecondMoment&    angularMatrix,
      const EcSpatialMatrix&   crossMatrix
      );

   /// sets using rigid body mass properties
   virtual void setFromRigidBody
      (
      const EcRigidBodyMassProperties& rigidBodyMass
      );

   /// sets from an EcReArray
   virtual void setFromArray
      (
      const EcReArray& array
      );

   /// get an EcReArray
   virtual void getArray
      (
      EcReArray& array
      ) const;

   /// test for approximate equality
   virtual EcBoolean approxEq
      (
      const EcArticulatedBodyInertia& sm2,
      EcReal tol
      ) const;

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
   static EcArticulatedBodyInertia nullObject
      (
      );

protected:
   /// linear second moment (equivalent to a symmectric 3x3 matrix)
   EcSecondMoment      m_LinearMatrix;

   /// angular second moment (equivalent to a symmectric 3x3 matrix)
   EcSecondMoment      m_AngularMatrix;

   /// cross term (three row vectors)
   EcSpatialMatrix     m_CrossMatrix;

   /// a flag indicating that this is a (strict) rigid body
   EcXmlBoolean        m_IsRigid;

   // non-XML data below (used for calculating acceleration from force)
   mutable EcReArray   m_UtilityInertiaArray;      ///< Utility inertia array
   mutable EcReArray   m_UtilityLArray;            ///< Utility array
   mutable EcReArray   m_UtilityAcceleration;      ///< Utility acceleration
   mutable EcReArray   m_UtilityForce;             ///< Utility force
};

/// an XML vector of mass properties
typedef EcXmlVectorType<EcArticulatedBodyInertia> EcArticulatedBodyInertiaVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the second moment in a transformed frame
EC_FOUNDATION_MANIPULATOR_DECL EcArticulatedBodyInertia transform
   (
   const EcCoordinateSystemTransformation& xform,
   const EcArticulatedBodyInertia& mp
   );

/// expresses the second moment in a rotated frame
EC_FOUNDATION_MANIPULATOR_DECL EcArticulatedBodyInertia transform
   (
   const EcOrientation& q,
   const EcArticulatedBodyInertia& mp
   );

/// expresses the second moment in an offset frame
EC_FOUNDATION_MANIPULATOR_DECL EcArticulatedBodyInertia transform
   (
   const EcVector& off,
   const EcArticulatedBodyInertia& mp
   );

#endif // ecArticulatedBodyInertia_H_
