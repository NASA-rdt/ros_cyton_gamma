#ifndef ecScalarMotionFilter_H_
#define ecScalarMotionFilter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecScalarMotionFilter.h
/// @class EcScalarMotionFilter
/// @brief Holds a description of a scalar-motion filter system.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseMotionFilter.h"

/** Holds a description of a scalar-motion filter system.  Given
 an existing value, a desired value, a desired speed,
 what is the best overall speed?  This uses proportional
 scaling with capping.
*/
class EC_ACTIN_CONTROL_DECL EcScalarMotionFilter : public EcBaseMotionFilter
{
public:

   /// default constructor
   EcScalarMotionFilter
      (
      );

   /// destructor
   virtual ~EcScalarMotionFilter
      (
      );

   /// copy constructor
   EcScalarMotionFilter
      (
      const EcScalarMotionFilter& orig
      );

   /// assignment operator
   EcScalarMotionFilter& operator=
      (
      const EcScalarMotionFilter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcScalarMotionFilter& orig
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

   /// gets the threshold
   virtual EcReal threshold
      (
      ) const;

   /// sets the threshold
   virtual void setThreshold
      (
      EcReal threshold
      );

   /// gets the acceleration threshold
   virtual EcReal accelerationThreshold
      (
      ) const;

   /// sets the acceleration threshold. This threshold is used to limit the filtered
   /// velocity such that no acceleration or deceleration exceeds this bound.
   virtual void setAccelerationThreshold
      (
      EcReal threshold
      );

   /// gets the deceleration threshold
   virtual EcReal decelerationThreshold
      (
      ) const;

   /// sets an additional deceleration threshold. This threshold is used to further limit the
   /// velocity such that deceleration when approaching a destination point
   /// doesn't exceed this value.  If it is larger than the acceleration threshold,
   /// the acceleration threshold is used.
   virtual void setDecelerationThreshold
      (
      EcReal threshold
      );

   /// gets the gain
   virtual EcReal gain
      (
      ) const;

   /// sets the gain
   virtual void setGain
      (
      EcReal gain
      );

   /// calculate a speed that will make a tradeoff
   /// between driving the first point to the second and achieving
   /// the desired velocity.
   virtual EcBoolean calculateVelocity
      (
      EcReal   from,
      EcReal   to,
      EcReal   desiredVelocity,
      EcReal   lastVelocity,
      EcReal   timeStep,
      EcReal&  filteredVelocity
      ) const;

   /// fitler the desired velocity by applying velocity and acceleration thresholds
   virtual EcBoolean filterVelocity
      (
      EcReal   desiredVelocity,
      EcReal   lastVelocity,
      EcReal   timeStep,
      EcReal&  filteredVelocity
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
   static EcScalarMotionFilter nullObject
      (
      );

protected:
   /// apply the filter
   virtual EcReal applyFilter
      (
      EcReal delta,
      EcReal gain,
      EcReal velocityThreshold,
      EcReal decelerationThreshold,
      EcReal timeStep,
      EcReal &filteredVelocity
      ) const;

   /// impose the velocity threshold
   void imposeVelocityThreshold
      (
      EcReal& filteredVelocity
      ) const;

   /// impose the acceleration threshold
   void imposeAccelerationThreshold
      (
      EcReal lastVelocity,
      EcReal integratedMaxDeltaVelocity,
      EcReal timeStep,
      EcReal& filteredVelocity
      ) const;

protected:
   /// a not-to-exceed velocity threshold.  The function of the
   /// difference between the returned and the desired point velocity,
   /// Sqrt[v.v], will not exceed this.
   EcXmlReal                          m_Threshold;

   /// the acceleration threshold
   EcXmlReal                          m_AccelerationThreshold;

   /// the deceleration threshold
   EcXmlReal                          m_DecelerationThreshold;

   /// a linear gain factor.  The linear velocity, when there
   /// is no explicit desired velocity and it doesn't exceed
   /// the threshold will be v=gain*offset.
   EcXmlReal                          m_Gain;
};

#endif // ecScalarMotionFilter_H_
