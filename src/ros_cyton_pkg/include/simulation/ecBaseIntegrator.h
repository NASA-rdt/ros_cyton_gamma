#ifndef ecBaseIntegrator_H_
#define ecBaseIntegrator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseIntegrator.h
/// @class EcBaseIntegrator
/// @brief Holds a base class for numerical integrator, used primarily
///        in dynamic simulation.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecOrientation.h>
#include <foundCommon/ecGeneralMotion.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlEnumType.h>
#include <xml/ecXmlVectorType.h>

/// Holds a base class for numerical integrator, used primarily in dynamic simulation.
class EC_ACTIN_SIMULATION_DECL EcBaseIntegrator : public EcXmlCompoundType
{
public:
   enum
   {
      FIRST_DERIVATIVES_ONLY,          //< integrate first derivatives only
      FIRST_AND_SECOND_DERIVATIVES,    //< integrate first and second derivatives
      GENERAL_MOTION                   //< integrate general motion
   };

   /// default constructor
   EcBaseIntegrator
      (
      );

   /// destructor
   virtual ~EcBaseIntegrator
      (
      );

   /// copy constructor
   EcBaseIntegrator
      (
      const EcBaseIntegrator& orig
      );

   /// assignment operator
   EcBaseIntegrator& operator=
      (
      const EcBaseIntegrator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseIntegrator& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const=0;

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

   /// reset integrator states
   virtual void reset
      (
      )=0;

   /// gets the time step
   virtual EcReal timeStep
      (
      ) const;

   /// sets the time step
   virtual void setTimeStep
      (
      EcReal timeStep
      );

   /// gets the integration order
   virtual EcU32 integrationOrder
      (
      ) const;

   /// sets the integration order
   virtual void setIntegrationOrder
      (
      EcU32 integrationOrder
      );

   /// gets the integration type
   virtual EcU32 integrationType
      (
      ) const;

   /// sets the integration type
   virtual void setIntegrationType
      (
      EcU32 value
      );

   /// integrate one step forward
   /**
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
      )=0;

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
      )=0;

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
      )=0;

   /// update the current position buffer
   /**
   This is needed to keep quaternion normalized when integrating general motion.
   */
   virtual void setCurrentPosition
      (
      const EcXmlRealVector& position
      )=0;

   /// update the current velocity buffer
   /**
   This is needed to keep quaternion rate normal to quaternion when integrating general motion.
   */
   virtual void setCurrentVelocity
      (
      const EcXmlRealVector& velocity
      )=0;

protected:
   /// registers enumeration strings for the simulation type
   virtual void registerEnumerations
      (
      );

protected:
   /// the integration time step
   EcXmlReal                  m_TimeStep;

   /// the integration order
   EcXmlU32                   m_IntegrationOrder;

   /// the integration type
   EcXmlEnumU32               m_IntegrationType;
};

#endif // ecBaseIntegrator_H_
