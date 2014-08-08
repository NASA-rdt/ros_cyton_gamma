#ifndef ecSimulationExpander_H_
#define ecSimulationExpander_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecSimulationExpander.h
/// @class EcSimulationExpander
/// @brief Holds a tool for expanding physical components into
///        stated systems and simulations.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>

class EcBasePhysicalExtent;
class EcIndividualManipulator;
class EcJointControllerSystemContainer;
class EcManipulatorLink;
class EcPositionControlSystem;
class EcStatedSystem;
class EcSystemSimulation;
class EcVelocityControlSystem;
class EcVisualizableStatedSystem;

/** Holds a tool for expanding physical components into stated systems and simulations.
*/
class EC_ACTIN_CONVERTSIMULATION_DECL EcSimulationExpander : public EcXmlCompoundType
{
public:
   /// default constructor
   EcSimulationExpander
      (
      );

   /// destructor
   virtual ~EcSimulationExpander
      (
      );

   /// copy constructor
   EcSimulationExpander
      (
      const EcSimulationExpander& orig
      );

   /// assignment operator
   EcSimulationExpander& operator=
      (
      const EcSimulationExpander& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSimulationExpander& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

   /// convert an individual manipulator to a simulation
   /**
   \param[in] manipulator manipulator
   \param[out] simulation simulation
   \retval error status
   */
   virtual EcBoolean convertIndividualManipulatorToSimulation
      (
      const EcIndividualManipulator&  manipulator,
      EcSystemSimulation&  simulation
      ) const;

   /// convert a visualizable stated system to a simulation
   /**
   \param[in] visStatedSystem visualizable stated system
   \param[out] simulation simulation
   \retval error status
   */
   virtual EcBoolean convertVisualizableStatedSystemToSimulation
      (
      const EcVisualizableStatedSystem&  visStatedSystem,
      EcSystemSimulation&  simulation
      ) const;

   /// convert a physical extent to a simulation
   /**
   \param[in] physicalExtent physical extent
   \param[out] simulation simulation
   \retval error status
   */
   virtual EcBoolean convertExtentToSimulation
      (
      const EcBasePhysicalExtent& physicalExtent,
      EcSystemSimulation&  simulation
      ) const;

   /// convert a visualizable stated system to a simulation using the provided position control system
   /**
   \param[in] visStatedSystem visualizable stated system
   \param[in] posContSys position control system
   \param[out] simulation simulation
   \retval error status
   */
   virtual EcBoolean convertVisualizableStatedSystemToSimulation
      (
      const EcVisualizableStatedSystem&  visStatedSystem,
      const EcPositionControlSystem& posContSys,
      EcSystemSimulation&  simulation
      ) const;

   /// build a default position control system for a given visualizable stated system
   /**
   \param[in] visStatedSystem visualizable stated system.
   \param[in] massMatrix If true, the control core will use mass matrix. Otherwise, it will use a diagonal matrix with 1 as elements.
   \param[in] scalar The scalar in the control core.
   */
   virtual EcPositionControlSystem buildPositionControlSystem
      (
      const EcVisualizableStatedSystem&  visStatedSystem,
      EcBoolean massMatrix=EcTrue,
      EcReal scalar=-1.0
      ) const;

   /// a token unique to this class
   /**
   \retval class token
   */
   static const EcToken& classToken
      (
      );

   /// get an empty object
   /**
   \retval empty simulation expander
   */
   static EcSimulationExpander nullObject
      (
      );

protected:

   /// convert a stated system to a position control system
   /**
   \param[in] system stated system
   \param[out] positionControlSystem position control system
   \param[in] massMatrix If true, the control core will use mass matrix. Otherwise, it will use a diagonal matrix with 1 as elements.
   \param[in] scalar The scalar in the control core.
   \retval error status
   */
   virtual EcBoolean buildPositionControlSystem
      (
      const EcStatedSystem& system,
      EcPositionControlSystem& positionControlSystem,
      EcBoolean massMatrix=EcTrue,
      EcReal scalar=-1.0
      ) const;

   /// build a joint controller from a stated system
   /**
   \param[in] system stated system
   \param[out] jointControllerContainer joint controller
   \retval error status
   */
   virtual EcBoolean buildJointController
      (
      const EcStatedSystem& system,
      EcJointControllerSystemContainer& jointControllerContainer
      ) const;
};

#endif // ecSimulationExpander_H_
