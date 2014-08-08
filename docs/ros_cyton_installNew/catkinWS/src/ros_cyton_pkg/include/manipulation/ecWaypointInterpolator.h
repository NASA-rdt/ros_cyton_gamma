#ifndef ecWaypointInterpolator_H_
#define ecWaypointInterpolator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecWaypointInterpolator.h
/// @class EcWaypointInterpolator
/// @brief An abstract base class for waypoint interpolator
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <foundCore/ecOrientation.h>
#include <foundCore/ecVector.h>
#include <xml/ecXmlCompType.h>

class EC_ACTIN_MANIPULATION_DECL EcWaypointInterpolator : public EcXmlCompoundType
{
public:
   /// Default constructor
   EcWaypointInterpolator
      (
      );

   /// Destructor
   virtual ~EcWaypointInterpolator
      (
      );

   /// Copy constructor
   EcWaypointInterpolator
      (
      const EcWaypointInterpolator& orig
      );

   /// Assignment operator
   EcWaypointInterpolator& operator=
      (
      const EcWaypointInterpolator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcWaypointInterpolator& orig
      ) const;

   /// register components
   virtual void registerComponents
      (
      );

   /**
    * @brief setPoints
    * @param p0 The entry point
    * @param p1 The middle point
    * @param p2 The exit point
    */
   virtual void setPoints
      (
      const EcVector& p0,
      const EcVector& p1,
      const EcVector& p2
      );

   /**
    * @brief setSpeeds
    * @param v0 The entry speed
    * @param v2 The exit speed
    */
   virtual void setSpeeds
      (
      EcReal v0,
      EcReal v2
      );

   /**
    * @brief setMaxAcceleration
    * @param acc The maximum acceleration
    */
   virtual void setMaxAcceleration
      (
      EcReal acc
      );

   /**
    * @brief needsDelay
    * @return
    */
   virtual EcBoolean needsDelay
      (
      ) const=0;

   /**
    * @brief setStartTime
    * @param[in] time
    */
   virtual void setStartTime
      (
      EcReal time
      );

   /**
    * @brief setOrientations
    * @param[in] o0
    * @param[in] o1
    * @param[in] o2
    * @return
    */
   virtual void setOrientations
      (
      const EcOrientation& o0,
      const EcOrientation& o1,
      const EcOrientation& o2
      );

   /**
    * @brief interpolate
    * @param time
    * @param position
    * @param velocity
    * @return
    */
   virtual EcBoolean interpolate
      (
      EcReal time,
      EcVector& position,
      EcVector& velocity
      ) const = 0;

   /**
    * @brief interpolate
    * @param time
    * @param orientation
    * @return
    */
   virtual EcBoolean interpolate
      (
      EcReal time,
      EcOrientation& orientation
      ) const = 0;

protected:
   EcVector    m_P0;       ///< Entry point
   EcVector    m_P1;       ///< Middle point
   EcVector    m_P2;       ///< Exit point
   EcReal      m_V0;       ///< Entry speed
   EcReal      m_V2;       ///< Exit speed
   EcReal      m_MaxAcc;   ///< Max acceleration
   EcReal      m_t0;       ///< Start time

   EcOrientation  m_O0;    ///< Entry orienation
   EcOrientation  m_O1;    ///< Middle orienation
   EcOrientation  m_O2;    ///< Exit orienation
};

#endif // ecWaypointInterpolator_H_
