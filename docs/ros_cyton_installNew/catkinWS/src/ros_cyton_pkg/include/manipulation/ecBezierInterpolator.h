#ifndef ecBezierInterpolator_H_
#define ecBezierInterpolator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecBezierInterpolator.h
/// @class EcBezierInterpolator
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecWaypointInterpolator.h"

/// Waypoint interpolator using Bezier curve.
class  EC_ACTIN_MANIPULATION_DECL EcBezierInterpolator : public EcWaypointInterpolator
{
public:
   /// Default constructor
   EcBezierInterpolator
      (
      );

   /// Destructor
   virtual ~EcBezierInterpolator
      (
      );

   /// Copy constructor
   EcBezierInterpolator
      (
      const EcBezierInterpolator& orig
      );

   /// Assignment operator
   EcBezierInterpolator& operator=
      (
      const EcBezierInterpolator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBezierInterpolator& orig
      ) const;

   /// Clone -- virtual constructor of EcBezierInterpolator
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components
   virtual void registerComponents
      (
      );

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// creates new object - a virtual new to an EcXmlObject pointer
   virtual EcXmlObject* newObject
      (
      ) const;

   /// gets the xml token used for writing out.
   virtual const EcToken& token
      (
      ) const;

   /// @copydoc EcWaypointInterpolator::setPoints
   virtual void setPoints
      (
      const EcVector& p0,
      const EcVector& p1,
      const EcVector& p2
      );

   /// @copydoc EcWaypointInterpolator::setSpeeds
   virtual void setSpeeds
      (
      EcReal v0,
      EcReal v2
      );

   /// @copydoc EcWaypointInterpolator::setMaxAcceleration
   virtual void setMaxAcceleration
      (
      EcReal acc
      );

   /// @copydoc EcWaypointInterpolator::setStartTime
   virtual void setStartTime
      (
      EcReal time
      );

   /// @copydoc EcWaypointInterpolator::needsDelay
   virtual EcBoolean needsDelay
      (
      ) const;

   /// @copydoc EcWaypointInterpolator::setOrientations
   virtual void setOrientations
      (
      const EcOrientation& o0,
      const EcOrientation& o1,
      const EcOrientation& o2
      );

   /// @copydoc EcWaypointInterpolator::interpolate(EcReal, EcVector&, EcVector&) const
   virtual EcBoolean interpolate
      (
      EcReal time,
      EcVector& position,
      EcVector& velocity
      ) const;

   /// @copydoc EcWaypointInterpolator::interpolate(EcReal, EcOrientation&) const
   virtual EcBoolean interpolate
      (
      EcReal time,
      EcOrientation& orientation
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// compute the S parameter
   EcReal computeS
      (
      EcReal time
      ) const;

   EcVector    m_P0P1;           ///< vector from P0 to P1
   EcVector    m_P1P2;           ///< vector from P1 to P2
   EcBoolean   m_IsValid;        ///< if the interpolator is valid
   EcReal      m_C0;             ///< normalized speed
   EcReal      m_C1;             ///< normalized speed
   EcReal      m_Acc;            ///< acceleration

   EcVector    m_AngleAxis;      ///< angle axis
   EcReal      m_TimeAtHalf;     ///< time when the point moves halfway
};

#endif // ecBezierInterpolator_H_
