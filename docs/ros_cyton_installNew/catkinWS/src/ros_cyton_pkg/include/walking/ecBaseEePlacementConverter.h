#ifndef ecBaseEePlacementConverter_H_
#define ecBaseEePlacementConverter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseEePlacementConverter.h
/// @class EcBaseEndEffectorPlacementConverter
/// @brief Base class for end-effector placement converter
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecTrajGeneratorVector.h"

#include <control/ecEndEffectorSet.h>

class EcEndEffectorSet;
class EcIndividualManipulator;
class EcManipulatorEndEffectorPlacement;
class EcPositionControlSystem;

/**
\class EcBaseEndEffectorPlacementConverter
\brief
*/
class EC_ACTIN_WALKING_DECL EcBaseEndEffectorPlacementConverter : public EcXmlCompoundType
{
public:
   /// default constructor
   EcBaseEndEffectorPlacementConverter
      (
      );

   /// destructor
   virtual ~EcBaseEndEffectorPlacementConverter
      (
      );

   /// copy constructor
   EcBaseEndEffectorPlacementConverter
      (
      const EcBaseEndEffectorPlacementConverter& orig
      );

   /// assignment operator
   EcBaseEndEffectorPlacementConverter& operator=
      (
      const EcBaseEndEffectorPlacementConverter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseEndEffectorPlacementConverter& orig
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// returns the token for this class
   virtual const EcToken& token
      (
      ) const = 0;

   /// gets the manipulator index
   virtual EcU32 manipulatorIndex
      (
      ) const;

   /// sets the manipulator index
   virtual void setManipulatorIndex
      (
      EcU32 value
      );

   /// gets the end-effector set
   virtual const EcEndEffectorSet& endEffectorSet
      (
      ) const;

   /// sets the end-effector set
   virtual void setEndEffectorSet
      (
      const EcEndEffectorSet& value
      );

   /// gets relative link data
   virtual const EcEndEffectorRelativeLinkData& relativeLinkData
      (
      EcU32 endEffectorIndex
      ) const;

   /// sets relative link data
   virtual EcBoolean setRelativeLinkData
      (
      EcU32 endEffectorIndex,
      const EcEndEffectorRelativeLinkData& relData
      );

   /// gets the time step for trajectory generation
   virtual EcReal trajectoryTimeStep
      (
      ) const;

   /// sets the time step for trajectory generation
   virtual void setTrajectoryTimeStep
      (
      EcReal value
      );

   /// gets the trajectory generator vector
   virtual const EcTrajectoryGeneratorVector& trajectoryGeneratorVector
      (
      ) const;

   /// sets the trajectory generator vector
   virtual void setTrajectoryGeneratorVector
      (
      const EcTrajectoryGeneratorVector& value
      );

   /// converts end-effector placement. This converts the desired EE placement of the EE set defined in this converter to the desired EE placement of the EE set defined in and expected from the control system.
   /**
   \param[in] time
   \param[in] manip
   \param[in, out] posControl The active control description could be changed depending on whether the robot needs to walk.
   \param[in] activeState
   \param[in] eePlacementIn
   \param[out] eePlacementOut
   */
   virtual EcBoolean convertEndEffectorPlacement
      (
      EcReal time,
      const EcIndividualManipulator& manip,
      EcPositionControlSystem& posControl,
      EcManipulatorActiveState&  activeState,
      const EcManipulatorEndEffectorPlacement& eePlacementIn,
      EcManipulatorEndEffectorPlacement& eePlacementOut
      ) = 0;

   /// converts end-effector velocity. This converts the desired EE velocity of the EE set defined in this converter to the desired EE velocity of the EE set defined in and expected from the control system.
   /**
   \param[in] time
   \param[in] manip
   \param[in] posControl
   \param[in] activeState
   \param[in] eeVelocityIn
   \param[out] eeVelocityOut
   */
   virtual EcBoolean convertEndEffectorVelocity
      (
      EcReal time,
      const EcIndividualManipulator& manip,
      const EcPositionControlSystem& posControl,
      EcManipulatorActiveState&  activeState,
      const EcManipulatorEndEffectorVelocity& eeVelocityIn,
      EcManipulatorEndEffectorVelocity& eeVelocityOut
      ) = 0;

protected:
   /// the manipulator index
   EcXmlU32                m_ManipulatorIndex;

   /// the end-effector set with which the simulation interacts
   EcEndEffectorSet        m_EndEffectorSet;

   /// the time step for trajectory generation
   EcXmlReal               m_TrajectotryTimeStep;

   /// the vector of trajectory generators
   EcTrajectoryGeneratorVector   m_TrajectoryGeneratorVector;
};

#endif // ecBaseEePlacementConverter_H_
