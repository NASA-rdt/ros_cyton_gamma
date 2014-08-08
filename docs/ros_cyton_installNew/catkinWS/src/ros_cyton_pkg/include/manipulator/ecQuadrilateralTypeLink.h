#ifndef ecQuadrilateralTypeLink_H_
#define ecQuadrilateralTypeLink_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecQuadrilateralTypeLink.h
/// @class EcQuadrilateralTypeLink
/// @brief A type of joint that converts a linear motion into an
///        angular motion using a quadrilateral-shaped mechanism. This
///        is conceptually the same as the slider-crank mechanism.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecLinkKinematics.h"

/// A class to describe type of joint that converts a linear motion into
/// an angular motion using a quadrilateral-shaped mechanism. This is conceptually
/// the same as the slider-crank mechanism.
class EC_FOUNDATION_MANIPULATOR_DECL EcQuadrilateralTypeLink : public EcLinkKinematics
{
public:
   /// joint type enumeration
   enum {
      FIXED_SLIDER,    ///< The slider joint is fixed (grounded, not moving).
      PIVOTED_SLIDER   ///< The slider joint is pivoted.
   };

   /// register joint type enumeration
   virtual void   registerJointTypeEnumerations
      (
      );

   /// default constructor
   EcQuadrilateralTypeLink
      (
      );

   /// destructor
   virtual ~EcQuadrilateralTypeLink
      (
      );

   /// copy constructor
   EcQuadrilateralTypeLink
      (
      const EcQuadrilateralTypeLink& orig
      );

   /// assignment operator
   EcQuadrilateralTypeLink& operator=
      (
      const EcQuadrilateralTypeLink& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcQuadrilateralTypeLink& orig
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

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// get joint type
   virtual EcU32 jointType
      (
      ) const;

   /// set joint type
   virtual void setJointType
      (
      EcU32 value
      );

   /// get Precursor
   virtual const EcCoordinateSystemTransformation& precursor
      (
      ) const;

   /// set Precursor
   virtual void setPrecursor
      (
      const EcCoordinateSystemTransformation& value
      );

   /// get the nominal length of the slider at joint position=0.
   virtual EcReal nominalLength
      (
      ) const;

   /// set the nominal length of the slider at joint position=0.
   virtual void setNominalLength
      (
      EcReal value
      );

   /// get the length of the side which is perpendicular to the grounded side.
   virtual EcReal d1Length
      (
      ) const;

   /// set the length of the side which is perpendicular to the grounded side.
   virtual void setD1Length
      (
      EcReal value
      );

   /// get the length of the side opposite d1.
   virtual EcReal d2Length
      (
      ) const;

   /// set the length of the side opposite d1.
   virtual void setD2Length
      (
      EcReal value
      );

   /// get the length of the side opposite the slider.
   virtual EcReal oppositeLength
      (
      ) const;

   /// set the length of the side opposite the slider.
   virtual void setOppositeLength
      (
      EcReal value
      );

   /// gets the distance of point A relative to reference point O in the Z direction
   virtual EcReal zDistanceA
      (
      ) const;

   /// sets the distance of point A relative to reference point O in the Z direction
   virtual void setZDistanceA
      (
      EcReal value
      );

   /// gets the distance of point B relative to reference point O in the Z direction
   virtual EcReal zDistanceB
      (
      ) const;

   /// sets the distance of point B relative to reference point O in the Z direction
   virtual void setZDistanceB
      (
      EcReal value
      );

   /// gets the distance of point C relative to reference point O in the Z direction
   virtual EcReal zDistanceC
      (
      ) const;

   /// sets the distance of point C relative to reference point O in the Z direction
   virtual void setZDistanceC
      (
      EcReal value
      );

   /// calculate D-H transformation
   /**
   \param[in] jointValue The joint value used to calculate the DH transformation.
   \return The DH transformation at jointValue.
   */
   virtual const EcCoordinateSystemTransformation& calculateTransform
      (
      EcReal jointValue
      ) const;

   /// transform an inboard transformation to the link's DH frame
   /// The output is xform*DH(jointValue).
   /**
   \param[in,out] xform The output transformation which is xform*DH(jointValue).
   \param[in] jointValue The joint value used to calculate the DH transformation.
   */
   virtual void transformBy
      (
      EcCoordinateSystemTransformation& xform,
      EcReal jointValue
      ) const;

   /// get the frame velocity of the DH frame, relative to
   /// the parent, that is produced by the specified joint velocity.
   /// The answer is locally represented.
   virtual const EcGeneralMotion& calculateVelocity
      (
      EcReal jointValue,
      EcReal jointVelocity
      ) const;

   /// get the acceleration in the DH frame, w.r.t. the parent frame,
   /// represented locally.
   /// Note that the velocity calculated from calculateVelocity is w.r.t.
   /// the local frame.  Therefor the derivative of that is not the answer
   /// here.  The transformation (only the orientation part) from current
   /// frame to the parent frame needs to be applied to the velocity first,
   /// followed by time derivative, then convert back to the current frame.
   virtual const EcGeneralAcceleration& calculateAcceleration
      (
      EcReal jointValue,
      EcReal jointVelocity,
      EcReal jointAcceleration
      ) const;

   using EcLinkKinematics::approxEq;
   /// test for approximate equality
   virtual EcBoolean approxEq
      (
      const EcQuadrilateralTypeLink& kin2,
      EcReal tol
      ) const;

   /// computes the upper-bound DH frame distance for this joint
   virtual EcReal upperBoundDhFrameDistance
      (
      const EcJointActuator& jointActuator
      )const;

   /// scale the kinematics by the specified distance-scale value
   /// (scaleFactor=1.0 does not change the kinematics)
   virtual void scaleBy
      (
      EcReal scaleFactor
      );

   /// transform this by a general coordinate system transformation.  This
   /// transformation is inserted before the link placement.  For
   /// precursor P, this gives P=XForm*P;
   virtual void transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// return the scale factor for the joint parameter (=1 for
   /// a distance-based parameter, 0 for non-distance-based)
   virtual EcReal jointParameterScalability
      (
      )const;

   /// change the inboard frame by an offset. This is to account for uncertainty in link measurements, both linear and angular. If offset is identity, then this does nothing.
   virtual void changeInboardFrameBy
      (
      const EcCoordinateSystemTransformation& offset
      );

   /// computes and returns the transformation of the frame at point C (see documentation for details). This frame is aligned with the reference frame at O. Only the translation is different. This is useful for intra-link rendering and collision detection.
   virtual const EcCoordinateSystemTransformation& frameATransform
      (
      EcReal jointValue
      ) const;

   /// computes and returns the transformation of the frame at point B (see documentation for details). This is useful for intra-link rendering and collision detection
   virtual const EcCoordinateSystemTransformation& frameBTransform
      (
      EcReal jointValue
      ) const;

   /// computes and returns the transformation of the frame at point C (see documentation for details). This is useful for intra-link rendering and collision detection
   virtual const EcCoordinateSystemTransformation& frameCTransform
      (
      EcReal jointValue
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

   /// \copydoc EcLinkKinematics::unitType
   virtual EcU32 unitType
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

   /// get the null object
   static EcQuadrilateralTypeLink nullObject
      (
      );

protected:
   /// compute cos(theta) from sin(theta)
   /**
   \param[in] sinTheta sin(theta)
   \param[in] p The length p, which is the length of the slider for FIXED_SLIDER or the length of the opposite side of the slider for PIVOTED_SLIDER
   */
   EcReal cosThetaFromSinTheta
      (
      EcReal sinTheta,
      EcReal p
      ) const;

   /// invalidate all the transforms that have been computed
   void invalidateAllTransforms
      (
      );

protected:

   /// the joint type - rotational or prismatic
   EcXmlEnumU32                     m_JointType;

   /// the precursory transformation
   EcCoordinateSystemTransformation m_Precursor;

   /// the length of the slider at joint position = 0.0
   EcXmlReal      m_NominalLength;

   /// The length of the side which is perpendicular to the grounded side. It is denoted as d1.
   EcXmlReal      m_D1Length;

   /// The length of the side opposite d1. It is denoted as d2.
   EcXmlReal      m_D2Length;

   /// The length of the side opposite the slider. It is denoted as either p or q depending on the joint type. If the joint type is FIXED_SLIDER, then this is q. If the joint type is PIVOTED_SLIDER, then this is p.
   EcXmlReal      m_OppositeLength;

   /// the distance of point A relative to reference point O in the Z direction
   EcXmlReal      m_ZDistanceA;

   /// the distance of point B relative to reference point O in the Z direction
   EcXmlReal      m_ZDistanceB;

   /// the distance of point C relative to reference point O in the Z direction
   EcXmlReal      m_ZDistanceC;

   /// non-XML data members
   /// the joint value for the stored D-H transformation;
   mutable EcReal m_JointValueForStoredTransform;

   /// a validity flag for the transformation
   mutable EcBoolean m_StoredDhTransformValid;

   /// this is the transformation of the frame at point A
   mutable EcCoordinateSystemTransformation m_FrameATransform;

   /// this is the transformation of the frame at point B
   mutable EcCoordinateSystemTransformation m_FrameBTransform;

   /// this is the transformation of the frame at point C
   mutable EcCoordinateSystemTransformation m_FrameCTransform;

   /// the joint value for the stored transformation of frame B;
   mutable EcReal m_JointValueForStoredFrameBTransform;

   /// a validity flag for the frame B transform
   mutable EcBoolean m_StoredFrameBTransformValid;

   // the following values are computed and stored.
   /// this is nominal length + joint position. It is repeatedly use in the calculations so we should cache its value. It is denoted as either p or q depending on the joint type. If the joint type is FIXED_SLIDER, then this is p. If the joint type is PIVOTED_SLIDER, then this is q.
   mutable EcReal m_SliderLength;

   /// sin(theta) where theta is the angle corresponding to the current joint position.
   mutable EcReal m_SinTheta;

   /// cos(theta)
   mutable EcReal m_CosTheta;

   /// time derivative of theta
   mutable EcReal m_ThetaDot;

   /// The length D = (d1^2+d2^2+p^2-q^2)/(2*d2)
   mutable EcReal m_D;

   /// the denominator when computing velocity and acceleration
   mutable EcReal m_Denominator;
};

/// an XML vector of DH parameters
typedef EcXmlVectorType<EcQuadrilateralTypeLink> EcQuadrilateralTypeLinkVector;

#endif // ecQuadrilateralTypeLink_H_
