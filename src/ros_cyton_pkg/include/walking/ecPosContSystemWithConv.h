#ifndef ecPosContSystemWithConv_H_
#define ecPosContSystemWithConv_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecPosContSystemWithConv.h
/// @brief Position control system with EE placement converter
/// @details EcPositionControlSystemWithConverter
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <control/ecPosContSystem.h>
#include "ecEePlacementConverterVector.h"

/**
\class EcPositionControlSystemWithConverter
\brief EcPositionControlSystem with end-effector placement converter
*/
class EC_ACTIN_WALKING_DECL EcPositionControlSystemWithConverter : public EcPositionControlSystem
{
public:
   /// default constructor
   EcPositionControlSystemWithConverter
      (
      );

   /// destructor
   virtual ~EcPositionControlSystemWithConverter
      (
      );

   /// copy constructor
   EcPositionControlSystemWithConverter
      (
      const EcPositionControlSystemWithConverter& orig
      );

   /// constructor from base
   EcPositionControlSystemWithConverter
      (
      const EcPositionControlSystem& orig
      );

   /// assignment operator
   EcPositionControlSystemWithConverter& operator=
      (
      const EcPositionControlSystemWithConverter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPositionControlSystemWithConverter& orig
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   /**
       \param other XML object to test against
       \return equality test result
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
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   using EcPositionControlSystem::mergeWith;
   /// adds control description of input container to
   /// current control description
   /**
   \param[in] orig container to merge with
   \return error flag
   */
   virtual EcBoolean mergeWith
      (
      const EcPositionControlSystemWithConverter& orig
      );

   /// gets the placement converter vector
   virtual const EcEndEffectorPlacementConverterVector& placementConverterVector
      (
      ) const;

   /// sets the placement converter vector
   virtual void setPlacementConverterVector
      (
      const EcEndEffectorPlacementConverterVector& value
      );

   /// gets the desired end-effector placements
   /**
       \return commanded placement vector
   */
   virtual const EcManipulatorEndEffectorPlacementVector& desiredPlacementVector
      (
      ) const;

   /// sets the desired end-effector placements
   /**
       \param desiredPlacementVector commanded placement vector
   */
   virtual void setDesiredPlacementVector
      (
      const EcManipulatorEndEffectorPlacementVector& desiredPlacementVector
      );

   /// sets an individual desired end-effector placement
   virtual void setDesiredPlacement
      (
      const EcManipulatorEndEffectorPlacement& desiredPlacement,
      const EcU32 manipulatorIndex
      );

   /// gets an individual desired end-effector placement.  Returns
   /// identity if the indices are not valid.
   /**
       \param manipulatorIndex manipulator selection
       \param endEffectorIndex end effector selection
       \return commanded placement for one end effector
   */
   virtual const EcEndEffectorPlacement& desiredPlacement
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex
      ) const;

   /// sets an individual desired end-effector placement (returns True for success)
   /**
       \param manipulatorIndex manipulator selection
       \param endEffectorIndex end effector selection
       \param placementInRelative commanded placement for one end-effector in the primary frame of the end-effector's relative link. If the end-effector is not relative, then it's the placement in the system coordinates.
       \return error flag
   */
   virtual EcBoolean setDesiredPlacement
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex,
      const EcEndEffectorPlacement& placementInRelative
      );

   using EcPositionControlSystem::addDesiredPlacement;
   /// add desired placement
   virtual void addDesiredPlacement
      (
      const EcU32& manipulatorIndex,
      const EcManipulatorEndEffectorPlacement& placement
      );

   /// gets the relative link data.  Returns identity if the indices
   /// are not valid.
   /**
       \param manipulatorIndex index for selecting the manipulator
       \param endEffectorIndex index for selecting the end effector
       \return relative link data for end effector
   */
   virtual const EcEndEffectorRelativeLinkData& endEffectorRelativeLinkData
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex
      ) const;

   /// sets the relative link data
   /**
       \param manipulatorIndex index for selecting the manipulator
       \param endEffectorIndex index for selecting the end effector
       \param relData relative link data for end effector
       \return error flag
   */
   virtual EcBoolean setEndEffectorRelativeLinkData
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex,
      const EcEndEffectorRelativeLinkData& relData
      );

   /// gets the desired end-effector velocities
   /**
       \return commanded velocity vector
   */
   virtual const EcManipulatorEndEffectorVelocityVector& desiredVelocityVector
      (
      ) const;

   /// sets the desired end-effector velocities
   /**
       \param desiredVelocityVector commanded velocity vector
   */
   virtual void setDesiredVelocityVector
      (
      const EcManipulatorEndEffectorVelocityVector& desiredVelocityVector
      );

   /// sets an individual desired end-effector velocity
   virtual void setDesiredVelocity
      (
      const EcManipulatorEndEffectorVelocity& desiredVelocity,
      const EcU32 manipulatorIndex
      );

   /// sets an individual desired end-effector velocity (returns True for success)
   /**
       \param manipulatorIndex manipulator selection
       \param endEffectorIndex end effector selection
       \param velocity commanded velocity for one end effector
       \return error flag
   */
   virtual EcBoolean setDesiredVelocity
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex,
      const EcXmlRealVector& velocity
      );

   /// zeros the desired velocity vector
   virtual void zeroDesiredVelocityVector
      (
      );

   /// set the passed value to a zero desired velocity vector
   virtual void setToZeroDesiredVelocityVector
      (
      EcManipulatorEndEffectorVelocityVector& desiredVelocityVector
      ) const;

   /// gets an end effector set
   /**
       \param manipulatorIndex index for selecting manipulator
       \return end effector data for one manipulator
   */
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcU32 manipulatorIndex
      ) const;

   /// sets an end effector set
   /**
       \param endEffectorSet end effector data for one manipulator
       \param manipulatorIndex index for selecting manipulator
   */
   virtual void setEndEffectorSet
      (
      const EcEndEffectorSet& endEffectorSet,
      const EcU32 manipulatorIndex
      );

   /// gets an individual actual end-effector placement
   /**
       \param manipulatorIndex manipulator selection
       \param endEffectorIndex end effector selection
       \return end effector placement
   */
   virtual const EcEndEffectorPlacement& actualPlacement
      (
      EcU32 manipulatorIndex,
      EcU32 endEffectorIndex
      ) const;

   /// gets the actual end-effector placements
   /**
       \return current placement vector
   */
   virtual const EcManipulatorEndEffectorPlacementVector& actualPlacementVector
      (
      ) const;

   /// sets the actual end-effector placements
   /**
       \param actualPlacementVector current placement vector
   */
   virtual void setActualPlacementVector
      (
      const EcManipulatorEndEffectorPlacementVector& actualPlacementVector
      );

   /// calculate a new manipulator state
   /**
    \param[in] time current time
    \param[in] state state for rendering
    \return error flag
   */
   virtual EcBoolean calculateState
      (
      EcReal time,
      EcManipulatorSystemState& state
      );

   /// self test
   /**
   \return self test result
   */

   /// read this object from an XML stream
   /**
   \param stream XML reader stream
   \return error flag
   */
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /**
   \param stream XML writer stream
   \return error flag
   */
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   /**
   \return uninitialized position control system
   */
   static EcPositionControlSystemWithConverter nullObject
      (
      );

   /// get a test object
   /**
   \return position control system
   */

   /// return a token
   /**
       \return token that describes the XML object
   */
   virtual const EcToken& token
      (
      ) const;

   /// token for this class
   /**
       \return token that describes the XML object
   */
   static const EcToken& classToken
      (
      );

   /// static creator function
   /**
       \return XML object created during XML loading
   */
   static EcXmlObject* creator
      (
      );

protected:
   /// finds and returns the end-effector placement converter for a given manipulator. const version.
   virtual const EcBaseEndEffectorPlacementConverter* endEffectorPlacementConverter
      (
      EcU32 manipIndex
      ) const;

   /// finds and returns the end-effector placement converter for a given manipulator. non-const version.
   virtual EcBaseEndEffectorPlacementConverter* endEffectorPlacementConverter
      (
      EcU32 manipIndex
      );

   /// initialize XML components for reading and writing system states and desired end-effector states
   /**
       \return error flag
   */
   virtual EcBoolean initializeStates
      (
      );

   /// calculate the new placement vector from the new system state
   virtual void calculateNewPlacements
      (
      );

   /// copy the desired placement and velocity vectors from the converter
   virtual void copyConverterDesiredVectors
      (
      );

protected:
   /// the end-effector placement converter vector
   EcEndEffectorPlacementConverterVector        m_PlacementConverterVector;

   // non-XML data
   /// the desired end-effector placements as input of the converter
   EcManipulatorEndEffectorPlacementVector      m_ConverterDesiredPlacementVector;

   /// the desired end-effector velocity as input of the converter
   EcManipulatorEndEffectorVelocityVector       m_ConverterDesiredVelocityVector;

   /// the new actual end-effector placement of the converter
   EcManipulatorEndEffectorPlacementVector      m_ConverterActualPlacementVector;

   /// a utility vector of end-effector tools of the converter
   EcEndEffectorToolVector                      m_ConverterEndEffectorTools;
};

#endif // ecPosContSystemWithConv_H_
