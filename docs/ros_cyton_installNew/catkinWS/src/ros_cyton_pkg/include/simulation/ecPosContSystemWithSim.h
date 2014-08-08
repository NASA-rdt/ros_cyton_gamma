#ifndef ecPosContSystemWithSim_H_
#define ecPosContSystemWithSim_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecPosContSystemWithSim.h
/// @class EcPositionControlSystemWithSimulation
/// @brief Holds a description of a position control system, which
///        using a look-forward simulator to determine if the commanded
///        end effector placement is possible.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecSysSimulation.h"
#include <control/ecPosContSystem.h>

/// Holds a description of a position control system
/** Uses a look-forward simulator to determine if the commanded
    end effector placement is possible
*/
class EC_ACTIN_SIMULATION_DECL EcPositionControlSystemWithSimulation : public EcPositionControlSystem
{
public:
   /// default constructor
   EcPositionControlSystemWithSimulation
      (
      );

   /// destructor
   virtual ~EcPositionControlSystemWithSimulation
      (
      );

   /// copy constructor
   EcPositionControlSystemWithSimulation
      (
      const EcPositionControlSystemWithSimulation& orig
      );

   /// assignment operator
   EcPositionControlSystemWithSimulation& operator=
      (
      const EcPositionControlSystemWithSimulation& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPositionControlSystemWithSimulation& orig
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   /**
       \param other XML object to compare with
       \retval equality test result
   */
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   /**
       \retval cloned XML object
   */
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// sets simulation
   /**
       \param simulation simulation for looking forward
   */
   virtual void setSimulation
      (
      const EcSystemSimulation& simulation
      );

   /// sets simulation run time
   /**
       \param simRunTime Simulation run time.  If not set, run time is calculated.
   */
   virtual void setSimRunTime
      (
      const EcXmlReal& simRunTime
      );

   /// sets simulation run time scale factor
   /**
       \param simRunTimeScaleFactor Scale factor for increasing simulation run time.
                                    Only used if m_SimRunTime not set.
   */
   virtual void setSimRunTimeScaleFactor
      (
      const EcXmlReal& simRunTimeScaleFactor
      );

   /// sets simulation step count
   /**
       \param steps number of simulation steps
   */
   virtual void setSteps
      (
      const EcXmlU32& steps
      );

   /// sets simulation tolerance
   /**
       \param tol tolerance for simulation convergence test
   */
   virtual void setTol
      (
      const EcXmlReal& tol
      );

   /// sets the desired end-effector placements
   /// test placement with simulation before setting
   /**
       \param desiredPlacementVector commanded placement vector
   */
   virtual void setDesiredPlacementVector
      (
      const EcManipulatorEndEffectorPlacementVector& desiredPlacementVector
      );

   /// reset desired placement to something safe
   /// if test in setDesiredPlacementVector fails
   virtual void setSafePlacementVector
      (
      );

   /// self test
   /**
       \retval self test result
   */

   /// get a null object
   /**
       \retval uninitialized position control system
   */
   static EcPositionControlSystemWithSimulation nullObject
      (
      );

   /// get a test object
   /**
       \retval position control system
   */

   /// return a token
   /**
       \retval token that describes the XML object
   */
   virtual const EcToken& token
      (
      ) const;

   /// token for this class
   /**
       \retval token that describes the XML object
   */
   static const EcToken& classToken
      (
      );

   /// static creator function
   /**
       \retval XML object created during XML loading
   */
   static EcXmlObject* creator
      (
      );

protected:
   /// Position control simulation
   EcSystemSimulation      m_Simulation;

   /// Maximum simulation time
   EcXmlReal               m_SimRunTime;

   /// Simulation time scale factor
   EcXmlReal               m_SimRunTimeScaleFactor;

   /// Maximum number of simulated steps
   EcXmlU32                m_Steps;

   /// Tolerance
   EcXmlReal               m_Tol;

   /// Saved version of the desired end-effector placements.
   /// While the saved version is constant, the simulation is idle for
   /// reduced processing.
   EcManipulatorEndEffectorPlacementVector   m_DesiredPlacementVectorSaved;

   /// System state object needed by the simulation
   mutable EcManipulatorSystemState m_DynamicState;
};

#endif // ecPosContSystemWithSim_H_
