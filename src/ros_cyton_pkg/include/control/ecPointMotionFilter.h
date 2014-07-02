#ifndef ecPointMotionFilter_H_
#define ecPointMotionFilter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecPointMotionFilter.h
/// @class EcPointMotionFilter
/// @brief Holds a description of a point-motion filter system.  Given
///        an existing point, a desired point, a desired point velocity,
///        what is the best overall point velocity?  This uses proportional
///        scaling with capping.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseMotionFilter.h"

class EcPlanarVector;
class EcVector;

/** Holds a description of a point-motion filter system.  Given
 an existing point, a desired point, a desired point velocity,
 what is the best overall point velocity?  This uses proportional
 scaling with capping.
*/
class EC_ACTIN_CONTROL_DECL EcPointMotionFilter : public EcBaseMotionFilter
{
public:

   /// default constructor
   EcPointMotionFilter
      (
      );

   /// destructor
   virtual ~EcPointMotionFilter
      (
      );

   /// copy constructor
   EcPointMotionFilter
      (
      const EcPointMotionFilter& orig
      );

   /// assignment operator
   EcPointMotionFilter& operator=
      (
      const EcPointMotionFilter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPointMotionFilter& orig
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

   /// sets the acceleration and deceleration thresholds.
   virtual void setAccelerationAndDecelerationThresholds
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

   /// calculate a three-dimensional velocity that will make a tradeoff
   /// between driving the first point to the second and achieving
   /// the desired velocity.
   virtual EcBoolean calculate3DVelocity
      (
      const EcVector& from,
      const EcVector& to,
      const EcVector& desiredVelocity,
      const EcVector& lastVelocity,
      EcReal          timeStep,
      EcVector&       filteredVelocity
      ) const;

   /// filter three-dimensional velocity to approximate
   /// the desired velocity within the velocity and
   /// acceleration bounds.
   virtual EcBoolean filter3DVelocity
      (
      const EcVector& desiredVelocity,
      const EcVector& lastVelocity,
      EcReal          timeStep,
      EcVector&       filteredVelocity
      ) const;

   /// calculate a two-dimensional velocity that will make a tradeoff
   /// between driving the first point to the second and achieving
   /// the desired velocity.
   virtual EcBoolean calculate2DVelocity
      (
      const EcPlanarVector& from,
      const EcPlanarVector& to,
      const EcPlanarVector& desiredVelocity,
      const EcPlanarVector& lastVelocity,
      EcReal                timeStep,
      EcPlanarVector&       filteredVelocity
      ) const;

   /// filter two-dimensional velocity to approximate
   /// the desired velocity within the velocity and
   /// acceleration bounds.
   virtual EcBoolean filter2DVelocity
      (
      const EcPlanarVector& desiredVelocity,
      const EcPlanarVector& lastVelocity,
      EcReal                timeStep,
      EcPlanarVector&       filteredVelocity
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

   /// get a null object
   static EcPointMotionFilter nullObject
      (
      );

protected:


   /// limit the 3D velocity to be within bounds.
   virtual void limit3DVelocity
      (
      EcVector&       filteredVelocity
      ) const;

   /// limit the 2D velocity to be within bounds.
   virtual void limit2DVelocity
      (
      EcPlanarVector&       filteredVelocity
      ) const;

   /// limit the 3D acceleration to be within bounds.
   virtual void limit3DAcceleration
      (
      const EcVector& lastVelocity,
      const EcReal&   timeStep,
      EcVector&       filteredVelocity
      ) const;

   /// limit the 2D acceleration to be within bounds.
   virtual void limit2DAcceleration
      (
      const EcPlanarVector& lastVelocity,
      const EcReal&         timeStep,
      EcPlanarVector&       filteredVelocity
      ) const;

protected:
   /// a not-to-exceed velocity threshold.  The function of the
   /// difference between the returned and the desired point velocity,
   /// Sqrt[v.v], will not exceed this.
   EcXmlReal                          m_Threshold;

   /// the acceleration threshold
   EcXmlReal                          m_AccelerationThreshold;

   /// a additional deceleration threshold
   EcXmlReal                          m_DecelerationThreshold;

   /// a linear gain factor.  The linear velocity, when there
   /// is no explicit desired velocity and it doesn't exceed
   /// the threshold will be v=gain*offset.
   EcXmlReal                          m_LinearGain;
};

#endif // ecPointMotionFilter_H_
