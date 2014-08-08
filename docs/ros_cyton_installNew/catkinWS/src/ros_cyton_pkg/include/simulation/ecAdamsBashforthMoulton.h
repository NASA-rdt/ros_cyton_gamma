#ifndef ecAdamsBashforthMoulton_H_
#define ecAdamsBashforthMoulton_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecAdamsBashforthMoulton.h
/// @class EcAdamsBashforthMoulton
/// @brief Holds a class implementing Adams-Bashforth predictor,
///        Adams-Moulton corrector method for numerical integration
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseIntegrator.h"

#include <foundCommon/ecCoordSysXForm.h>

/// Holds a class implementing Adams-Bashforth predictor, Adams-Moulton corrector method for numerical integration.
/** The Adams-Bashforth predictor and Adams-Moulton corrector is used to integrate quantities with first and second derivatives. The Adams-Bashforth predictor is used to integrate the second derivatives to obtain the first derivatives and the Adams-Moulton corrector then uses the results to in an integration to obtain the quantities.
This class also support integration of first derivatives only by using the Adams-Bashforth corrector.
Note that one instance of this class MUST NOT be used to for the two purposes. That is, one should not call the two integrateOneStep methods on one instance.
*/
class EC_ACTIN_SIMULATION_DECL EcAdamsBashforthMoulton : public EcBaseIntegrator
{
public:
   /// default constructor
   EcAdamsBashforthMoulton
      (
      );

   /// destructor
   virtual ~EcAdamsBashforthMoulton
      (
      );

   /// copy constructor
   EcAdamsBashforthMoulton
      (
      const EcAdamsBashforthMoulton& orig
      );

   /// assignment operator
   EcAdamsBashforthMoulton& operator=
      (
      const EcAdamsBashforthMoulton& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcAdamsBashforthMoulton& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
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

   virtual const EcToken& token
      (
      ) const;

   /// reset integrator states
   virtual void reset
      (
      );

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// sets the integration order
   virtual void setIntegrationOrder
      (
      EcU32 integrationOrder
      );

   /// integrate one step forward
   /*
   Integrate acceleration and velocity to obtain velocity and position at the next time step.
   \param[in,out] position A vector containing the current positions. Upon return, will contain the positions at the next time step.
   \param[in,out] velocity A vector containing the current velocities. Upon return, will contain the velocities at the next time step.
   \param[in] acceleration A vector containing the current accelerations.
   \param[in] includeFlags A pointer to a vector containing flags indicating whether or not to integrate the motion at particular indices. For example, if the flag at index 1 is false, then the motion (acceleration, velocity, and position) at index 1 will NOT be integrated. If this pointer is not provided, then all motions will be integrated.
   */
   virtual EcBoolean integrateOneStep
      (
      EcXmlRealVector& position,
      EcXmlRealVector& velocity,
      const EcXmlRealVector& acceleration,
      const EcXmlBooleanVector* includeFlags=0
      );

   /// integrate one step forward
   /*
   Integrate general acceleration and general velocity to obtain velocity and position at the next time step.
   \param[in] transformation An orientation instance used to transform the general velocity to the same coordinates as the general position.
   \param[in,out] position A transform containing the current position. Upon return, will contain the position at the next time step.
   \param[in,out] velocity The current general velocity. Upon return, will contain the velocity at the next time step.
   \param[in] acceleration The current general acceleration.
   */
   virtual EcBoolean integrateOneStep
      (
      const EcOrientation& transformation,
      EcCoordinateSystemTransformation& position,
      EcGeneralVelocity& velocity,
      const EcGeneralAcceleration& acceleration
      );

   /// integrate one step forward
   /**
   Integrate the first derivatives to obtain the values at the next time step.
   \param[in,out] position A vector containing the current values. Upon return, will contain the values at the next time step.
   \param[in] velocity A vector containing the first derivatives. Upon return, will contain the velocities at the next time step.
   \param[in] includeFlags A pointer to a vector containing flags indicating whether or not to integrate the derivative at particular indices. For example, if the flag at index 1 is false, then the derivative at index 1 will NOT be integrated. If this pointer is not provided, then all derivatives will be integrated.
   */
   virtual EcBoolean integrateOneStep
      (
      EcXmlRealVector& position,
      const EcXmlRealVector& velocity,
      const EcXmlBooleanVector* includeFlags=0
      );

   /// update the current position buffer
   /**
   This is needed to keep quaternion normalized when integrating general motion.
   */
   virtual void setCurrentPosition
      (
      const EcXmlRealVector& position
      );

   /// update the current velocity buffer
   /**
   This is needed to keep quaternion rate normal to quaternion when integrating general motion.
   */
   virtual void setCurrentVelocity
      (
      const EcXmlRealVector& velocity
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   /// get a zero-information integrator
   static EcAdamsBashforthMoulton nullObject
      (
      );

protected:
   // non-XML data below

   /// past positions
   EcXmlRealVectorVector         m_Positions;

   /// past velocities
   EcXmlRealVectorVector         m_Velocities;

   /// past accelerations
   EcXmlRealVectorVector         m_Accelerations;

   /// past general positions
   EcCoordinateSystemTransformationVector      m_GeneralPositions;

   /// past general velocities
   EcGeneralVelocityVector    m_GeneralVelocities;

   /// past general accelerations
   EcGeneralVelocityVector    m_GeneralAccelerations;

   /// a marker of the current state
   EcU32Vector                   m_StateMarkers;

   /// the current integration order (used for marching to higher orders)
   EcU32                         m_CurrentIntegrationOrder;

   /// the maximum allowable integration order
   static const EcU32            m_theMaxIntegrationOrder;

   /// the minimum allowable integration order
   static const EcU32            m_theMinIntegrationOrder;
};

#endif // ecAdamsBashforthMoulton_H_
