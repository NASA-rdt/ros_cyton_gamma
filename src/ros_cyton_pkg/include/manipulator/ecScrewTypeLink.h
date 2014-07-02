#ifndef ecScrewTypeLink_H_
#define ecScrewTypeLink_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecScrewTypeLink.h
/// @class EcScrewTypeLink
/// @brief A type of joint to rotate and translate at the same time.
///        (i.e., simultaneous rotation about and translation along
///        a single axis).
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>
#include "ecLinkKinematics.h"
#include <xml/ecXmlVectorType.h>

/// A type of joint to rotate and translate at the same time.
class EC_FOUNDATION_MANIPULATOR_DECL EcScrewTypeLink : public EcLinkKinematics
{
public:
   /// default constructor
   EcScrewTypeLink
      (
      );

   /// destructor
   virtual ~EcScrewTypeLink
      (
      );

   /// copy constructor
   EcScrewTypeLink
      (
      const EcScrewTypeLink& orig
      );

   /// assignment operator
   EcScrewTypeLink& operator=
      (
      const EcScrewTypeLink& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcScrewTypeLink& orig
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

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
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

   /// get reference of pitch for screw link, defined as rotation per unit length
   virtual EcReal pitch
      (
      ) const;

   /// set pitch for screw link
   virtual void setPitch
      (
      EcReal pitch
      );

   /// calculate D-H transformation
   virtual const EcCoordinateSystemTransformation& calculateTransform
      (
      EcReal jointValue
      ) const;

   /// transform an inboard transformation to the link's DH frame
   /// The output is xform*DH(jointValue).
   virtual void transformBy
      (
      EcCoordinateSystemTransformation& xform,
      EcReal jointValue
      ) const;

   using EcLinkKinematics::approxEq;
   /// test for approximate equality
   virtual EcBoolean approxEq
      (
      const EcScrewTypeLink& dh2,
      EcReal tol
      ) const;

   /// computes the upper-bound DH frame distance for this joint
   virtual EcReal upperBoundDhFrameDistance
      (
      const EcJointActuator& jointActuator
      ) const;

   /// scale the kinematics by the specified distance-scale value
   /// (scaleFactor=1.0 does not change the object)
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

   /// get an zero offset
   static EcScrewTypeLink nullObject
      (
      );

protected:
   /// the precursory transformation
   EcCoordinateSystemTransformation m_Precursor;

   /// the pitch is defined as rotation per unit length
   EcXmlReal m_Pitch;

   /// the joint value for the stored transformation;
   mutable EcReal m_JointValueForStoredTransform;

   /// a validity flag for the transformation
   mutable EcBoolean m_StoredTransformValid;
};

/// an XML vector of DH parameters
typedef EcXmlVectorType<EcScrewTypeLink> EcScrewTypeLinkVector;

#endif // ecScrewTypeLink_H_
