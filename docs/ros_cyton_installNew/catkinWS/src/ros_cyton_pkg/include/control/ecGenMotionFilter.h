#ifndef ecGenMotionFilter_H_
#define ecGenMotionFilter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecGenMotionFilter.h
/// @class EcGeneralMotionFilter
/// @brief Holds a description of a general-motion filter system.  Given
///        an existing frame, a desired frame, a desired frame (or point)
///        velocity, what is the best overall general velocity (or point
///        velocity).  This uses proportional scaling with capping.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseMotionFilter.h"

#include <xml/ecXmlVector.h>

class EcCoordinateSystemTransformation;
class EcGeneralMotion;
/// type definition of EcGeneralVelocity
typedef EcGeneralMotion EcGeneralVelocity;
class EcVector;

/// Holds a description of a general-motion filter system.
/** Given an existing frame, a desired frame, a desired frame (or point)
 velocity, what is the best overall general velocity (or point
 velocity).  This uses proportional scaling with capping.
*/
class EC_ACTIN_CONTROL_DECL EcGeneralMotionFilter : public EcBaseMotionFilter
{
public:

   /// default constructor
   EcGeneralMotionFilter
      (
      );

   /// destructor
   virtual ~EcGeneralMotionFilter
      (
      );

   /// copy constructor
   EcGeneralMotionFilter
      (
      const EcGeneralMotionFilter& orig
      );

   /// assignment operator
   EcGeneralMotionFilter& operator=
      (
      const EcGeneralMotionFilter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGeneralMotionFilter& orig
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

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// gets the offset
   virtual const EcVector& offset
      (
      ) const;

   /// sets the offset
   virtual void setOffset
      (
      const EcVector& offset
      );

   /// \deprecated gets the angular weight
   virtual EcReal angularWeight
      (
      ) const;

   /// \deprecated sets the angular weight
   virtual void setAngularWeight
      (
      EcReal angularWeight
      );

   /// \deprecated gets the threshold
   virtual EcReal threshold
      (
      ) const;

   /// \deprecated sets the threshold
   virtual void setThreshold
      (
      EcReal threshold
      );

   /// gets the linear velocity threshold
   virtual EcReal linearVelocityThreshold
      (
      ) const;

   /// sets the linear velocity threshold.
   virtual void setLinearVelocityThreshold
      (
      EcReal threshold
      );

   /// gets the angular velocity threshold
   virtual EcReal angularVelocityThreshold
      (
      ) const;

   /// sets the angular velocity threshold.
   virtual void setAngularVelocityThreshold
      (
      EcReal threshold
      );

   /// gets the linear acceleration threshold
   virtual EcReal linearAccelerationThreshold
      (
      ) const;

   /// sets the linear acceleration threshold.
   virtual void setLinearAccelerationThreshold
      (
      EcReal threshold
      );

   /// gets the angular acceleration threshold
   virtual EcReal angularAccelerationThreshold
      (
      ) const;

   /// sets the angular acceleration threshold.
   virtual void setAngularAccelerationThreshold
      (
      EcReal threshold
      );

   /// gets the linear deceleration threshold
   virtual EcReal linearDecelerationThreshold
      (
      ) const;

   /// sets an additional linear deceleration threshold. This threshold is used to further limit the
   /// velocity such that deceleration when approaching a destination point
   /// doesn't exceed this value.  If it is larger than the linear acceleration threshold,
   /// the linear acceleration threshold is used.
   virtual void setLinearDecelerationThreshold
      (
      EcReal threshold
      );

   /// gets the angular deceleration threshold
   virtual EcReal angularDecelerationThreshold
      (
      ) const;

   /// sets an additional angular deceleration threshold. This threshold is used to further limit the
   /// velocity such that deceleration when approaching a destination point
   /// doesn't exceed this value.  If it is larger than the angular acceleration threshold,
   /// the angular acceleration threshold is used.
   virtual void setAngularDecelerationThreshold
      (
      EcReal threshold
      );

   /// gets the linear gain
   virtual EcReal linearGain
      (
      ) const;

   /// sets the linear gain
   virtual void setLinearGain
      (
      EcReal linearGain
      );

   /// gets the angular gain
   virtual EcReal angularGain
      (
      ) const;

   /// sets the angular gain
   virtual void setAngularGain
      (
      EcReal angularGain
      );

   /// calculate a general motion that will make a tradeoff
   /// between driving the first frame to the second and achieving
   /// the desired general motion.
   /// \param[in] from
   /// \param[in] to
   /// \param[in] desiredVelocity
   /// \param[in] lastVelocity
   /// \param[in] timeStep
   /// \param[in] filteredVelocity
   /// \param[in] coordinatedMotion If true, the linear and angular motions will be time scaled so
   ///      they complete approximately at the same time.
   /// \param[in] freeSpinInZ
   /// \param[in] applyFilter
   virtual EcBoolean calculateGeneralMotion
      (
      const EcCoordinateSystemTransformation& from,
      const EcCoordinateSystemTransformation& to,
      const EcGeneralVelocity& desiredVelocity,
      const EcGeneralVelocity& lastVelocity,
      EcReal timeStep,
      EcGeneralVelocity& filteredVelocity,
      EcBoolean coordinatedMotion = EcTrue,
      EcBoolean freeSpinInZ = EcFalse,
      EcBoolean applyFilter = EcTrue
      ) const;

   /// fitler the desired velocity by applying velocity and acceleration thresholds
   virtual EcBoolean filterVelocity
      (
      const EcGeneralVelocity& desiredVelocity,
      const EcGeneralVelocity& lastVelocity,
      EcReal timeStep,
      EcGeneralVelocity& filteredVelocity
      ) const;

   /// the token
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

   /// get a null object
   static EcGeneralMotionFilter nullObject
      (
      );

protected:
   /// apply the filter
   virtual EcReal applyFilter
      (
      const EcVector &delta,
      EcReal gain,
      EcReal velocityThreshold,
      EcReal decelerationThreshold,
      EcReal timeStep,
      EcVector &filteredVelocity
      ) const;

   /// impose the linear/angular velocity thresholds
   void imposeVelocityThresholds
      (
      EcReal linearVelThreshold,
      EcReal angularVelThreshold,
      EcVector& linearVelocity,
      EcVector& angularVelocity
      ) const;

   /// impose the linear/angular acceleration thresholds
   void imposeAccelerationThresholds
      (
      const EcGeneralMotion& lastVelocity,
      EcReal linearAccThreshold,
      EcReal angularAccThreshold,
      EcReal integratedMaxDeltaLinearVelocity,
      EcReal integratedMaxDeltaAngularVelocity,
      EcReal timeStep,
      EcVector& linearVelocity,
      EcVector& angularVelocity
      ) const;
protected:

   /// an offset vector.  This point in one frame will move
   /// directly toward the same point in another frame.
   EcXmlVector                        m_Offset;

   /// the linear velocity threshold
   EcXmlReal                          m_LinearVelocityThreshold;
   /// the angular velocity threshold
   EcXmlReal                          m_AngularVelocityThreshold;

   /// the linear acceleration threshold
   EcXmlReal                          m_LinearAccelerationThreshold;
   /// the angular acceleration threshold
   EcXmlReal                          m_AngularAccelerationThreshold;

   /// the linear deceleration threshold
   EcXmlReal                          m_LinearDecelerationThreshold;
   /// the angular deceleration threshold
   EcXmlReal                          m_AngularDecelerationThreshold;

   /// a linear gain factor.  The linear velocity, when there
   /// is no explicit desired velocity and it doesn't exceed
   /// the threshold will be v=gain*offset.
   EcXmlReal                          m_LinearGain;

   /// an angular gain factor.  The angular velocity, when there
   /// is no explicit desired velocity and it doesn't exceed
   /// the threshold will be v=gain*offset.
   EcXmlReal                          m_AngularGain;

   /// the cosine threshold.  When cos(theta) is larger than this,
   /// sin(theta) is assumed to be approximately equal to theta
   static const EcReal                m_theCosThreshold;

   /// the following members are deprecated.
   /// a weight for the angular velocity, used in assessing
   /// threshold exceedance.
   EcXmlReal                          m_AngularWeight;

   /// a not-to-exceed threshold.  The function of the difference
   /// between the returned and the desired general velocity,
   /// Sqrt[v.v + m_AngularWeight^2*w.w], will not exceed this.
   EcXmlReal                          m_Threshold;
};

/// a vector of individual velocity control descriptions
typedef EcXmlVectorType<EcGeneralMotionFilter>
   EcGeneralMotionFilterVector;

#endif // ecGenMotionFilter_H_
