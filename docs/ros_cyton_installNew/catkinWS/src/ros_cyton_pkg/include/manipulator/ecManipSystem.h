#ifndef ecManipSystem_H_
#define ecManipSystem_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipSystem.h
/// @class EcManipulatorSystem
/// @brief The complete manipulator system.  This includes any
///        number of individual robots and a description of the
///        environment (location/translation & gravity vector).
///        It does not include system state.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecIndManipulator.h"
#include "ecLinkInteractionsVector.h"
#include "ecOldManipulatorAttachmentMap.h"
#include "ecSystemEnvironment.h"
#include "ecSystemCollisionExclusionMap.h"
#include <xml/ecXmlCompType.h>
#include <geometry/ecBoxTree.h>

// forward declarations
class EcManipulatorSystemState;
class EcShapeStateCacheKey;

/// Holds a description of an entire manipulator system.
/** The system can include any number of bifurcating manipulators
    with any base location.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorSystem : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorSystem
      (
      );

   /// destructor
   virtual ~EcManipulatorSystem
      (
      );

   /// copy constructor
   EcManipulatorSystem
      (
      const EcManipulatorSystem& orig
      );

   /// assignment operator
   EcManipulatorSystem& operator=
      (
      const EcManipulatorSystem& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorSystem& orig
      ) const;

   /// merge operation
   virtual EcBoolean mergeWith
      (
      const EcManipulatorSystem& other
      );

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

   /// gets the number of joint degrees of freedom in the system.
   virtual EcU32 jointDof
      (
      ) const;

   /// gets the number of joint degrees of freedom for a manipulator in the system.
   virtual const EcU32 jointDof
      (
      const EcU32& index
      )const;

   /// gets the number of joint and base pose degrees of freedom in the system.
   virtual EcU32 jointAndBaseDof
      (
      ) const;

   /// gets upward pointing gravity vector and other environmental data
   virtual const EcSystemEnvironment& environment
      (
      ) const;

   /// sets upward pointing gravity vector and other environmental data
   virtual void setEnvironment
      (
      const EcSystemEnvironment& environment
      );

   /// gets manipulators
   virtual const EcIndividualManipulatorVector& manipulators
      (
      ) const;

   /// sets manipulators
   virtual void setManipulators
      (
      const EcIndividualManipulatorVector& manipulators
      );

   /// adds one manipulator
   virtual void addManipulator
      (
      const EcIndividualManipulator& manipulator
      );

   /// exchange an existing manipulator (specified by index) with a new manipulator
   virtual EcBoolean exchangeManipulator
      (
      EcU32 manipulatorIndex,
      const EcIndividualManipulator& manipulator
      );

   /// exchange an existing manipulator (specified by label) with a new manipulator. Note that
   /// the labels are not guaranteed to be unique so the first manipulator with that given label
   /// will be exchanged
   virtual EcBoolean exchangeManipulator
      (
      const EcString& manipulatorLabel,
      const EcIndividualManipulator& manipulator
      );

   /// deletes a manipulator from the system
   /**
   \param[in] manipLabel The string label of the manipulator to be deleted.
   \return The index of the deleted manipulator if the manipulator was found and successfully deleted. If the manipulator was not found, then this returns -1.
   */
   virtual EcInt32 deleteManipulator
      (
      const EcString& manipLabel
      );

   /// delete a manipulator and corresponding position and velocity states by index.
   /**
   \param[in] manipIndex The index of the manipulator to be deleted.
   \return True if manipIndex is valid and the manipulator is successfully deleted or false otherwise.
   */
   virtual EcBoolean deleteManipulator
      (
      EcU32 manipIndex
      );

   /// gets a pointer to the manipulator with the specified identifier
   /// returns NULL if it doesn't exist.
   virtual const EcIndividualManipulator* manipulatorByIdentifier
      (
      const EcString& label
      ) const;

   /// set the manipIndex for each manipulator
   virtual void mapManipulators
      (
      );

   /// build a bounding box tree that contains all the fixed-base
   /// base only manipulators.  These are environmental
   /// obstacles.
   virtual EcBoolean buildBoundingBoxTreeFromEnvironment
      (
      EcManipulatorActiveStateVector& actState
      );

   /// sets everything from a single manipulator.  Y-up is assumed for the
   /// environment.
   virtual void setFromIndividualManipulator
      (
      const EcIndividualManipulator& manipulator
      );

   /// get link interaction vector
   virtual const EcLinkInteractionsVector & linkInteractionsVector
      (
      ) const;

   /// set link interaction  vector
   virtual void setLinkInteractionsVector
      (
      const EcLinkInteractionsVector& linkInteractionsVector
      );

   /// get the collision exclusion map
   virtual const EcSystemCollisionExclusionMap& collisionExclusionMap
      (
      ) const;

   /// set the collision exclusion map
   virtual void setCollisionExclusionMap
      (
      const EcSystemCollisionExclusionMap& value
      );

   /// get the manipulator attachment map -- deprecated
   virtual const EcOldManipulatorAttachmentMap& manipulatorAttachmentMap
      (
      ) const;

   /// propagate full state by delta-t.  This keeps the same
   /// velocity state and integrates the position state
   /// using forward Euler.  Time is incremented.
   virtual void propagateStateBy
      (
      EcManipulatorSystemState& state,
      EcReal deltaT
      ) const;

   /// propagate a single state by delta-t.  This keeps the same
   /// velocity state and integrates the position state
   /// using forward Euler.  The manipulator number is given by index.
   virtual void propagateSingleStateBy
      (
      EcU32 index,
      const EcVelocityState& velocityState,
      EcReal deltaT,
      EcPositionState& positionState
      ) const;

   /// Extend the state with zeros or contract
   /// to a size that agrees with the system size.
   virtual void rightSizeState
      (
      EcManipulatorSystemState& state
      ) const;

   /// check compatibility with a state
   virtual EcBoolean isCompatible
      (
      const EcManipulatorSystemState& state
      ) const;

   /// calculate a bounding sphere given an external state.
   /// This bounding sphere is a function of the base positions
   /// and orientations, but not the joint positions.
   virtual EcSphere absoluteBoundingSphere
      (
      const EcManipulatorSystemState& state
      ) const;

   /// get the number of manipulators in the system
   virtual EcU32 numberOfManipulators
      (
      )const;

   /// process the link interactions if required
   virtual void processLinkInteractions
      (
      EcSystemActiveState& actState,
      const EcReal& time,
      const EcManipulatorTorqueVector& torqueVec
      )const;

   /// get the level in the bounding volume heirarch being used
   /// for collision detection (returns 0 if no collision detection
   /// processor specified)
   virtual const EcU32 collisionDetectionPrecisionLevel
      (
      )const;

   /// find and convert explicit manipulator link descriptions to references
   virtual EcBoolean findAndConvertToReferences
      (
      );

   /// set shape surface properties by the key.
   virtual EcBoolean setSurfacesByKey
      (
      const EcShapeStateCacheKey& key,
      const EcStringDataMapMap& surfaces
      );

   /// set the new value for a joint limit
   /**
   \param[in] manipulatorIndex The index of the manipulator
   \param[in] linkLabel The identifying label of the link (joint)
   \param[in] isLowerLimit True for a lower limit or false for upper limit
   \param[in] value The new value for the joint limit
   */
   virtual EcBoolean setJointLimit
      (
      EcU32 manipulatorIndex,
      const EcString& linkLabel,
      EcBoolean isLowerLimit,
      EcReal value
      );

   /// returns a boolean describing whether two links on two DIFFERENT manipulators can collide
   /// based on the static collision exclusion map in this manipulator system
   virtual EcBoolean canCollide
      (
      EcU32 manip1Index,
      EcU32 link1Index,
      EcU32 manip2Index,
      EcU32 link2Index
      ) const;

   /// replace the link properties (link kinematics, mass properties, joint actuator, shape container, etc.) of the link identified by linkLabel with the properties of newLink.
   /**
   \param[in] manipulatorIndex The index of the manipulator to which the link belongs.
   \param[in] linkLabel The string identifier of the link whose properties are to be changed.
   \param[in] newLink A link whose properties will be used.
   \param[in] includeShapeContainer If true, the shape container of the link identified by linkLabel will be replaced by the shape container of newLink. Shape container is a special case because of it may be referenced, in which case it needs to be unreferenced. The default is false, i.e. the shape container will not be replaced.
   \return True if successful or false if linkLabel is invalid.
   */
   virtual EcBoolean replaceLinkProperties
      (
      EcU32 manipulatorIndex,
      const EcString& linkLabel,
      const EcManipulatorLink& newLink,
      EcBoolean includeShapeContainer=EcFalse
      );

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
   static EcManipulatorSystem nullObject
      (
      );

   /// truncate values in the physical extents to the precision specified.
   virtual void truncateValues
      (
      const EcReal& precision = 1e-10
      );

   /// get the number of shapes in each link of each manipulator in the system
   virtual void getNumberOfShapes
      (
      EcInt32Vector3D& systemNumShapes
      ) const;

   /// set the self collisin map for manipulator manipID
   EcBoolean setSelfCollisionMap
      (
      const EcManipulatorSelfCollisionLinkMap& map,
      const EcU32& manipID
      );

   /// Count all the links in all manipulators in the system
   ///               return: total link count
   EcU32 countAllReadableLinks
      (
      ) const;

protected:
   /// update references to prepare for modification
   /**
   \param[in] manipLabel The string label of the manipulator that is about to be modified.
   \return True if successful.
   */
   virtual EcBoolean aboutToModifyManipulator
      (
      const EcString& manipLabel
      );

   /// update references to prepare for modification
   /**
   \param[in] manipulatorIndex The index of the manipulator that is about to be modified.
   \return True if successful.
   */
   virtual EcBoolean aboutToModifyManipulator
      (
      EcU32 manipulatorIndex
      );

   /// compute the collision detection precision level
   virtual void computeCollisionDetectionPrecisionLevel
      (
      );

   /// Get the DH parameters for the robot in Craig's formalism
   ///               format: a, alpha, d
   ///               if the link kinematics do not support Craig's notation, then
   ///               the values are empty
   EcBoolean getCraigDhParameters
      (
      EcRealVectorVector& dhParameters
      ) const;

protected:

   /// a vector of manipulators
   EcIndividualManipulatorVector   m_Manipulators;

   /// the environment for the system
   EcSystemEnvironment       m_Environment;

   /// the vector of objects between links
   EcLinkInteractionsVector  m_LinkInteractionVector;

   /// the collision exclusion map
   EcSystemCollisionExclusionMap    m_CollisionExclusionMap;

   /// the manipulator attachment map
   EcOldManipulatorAttachmentMap    m_ManipAttachmentMap;

   /// the count of all links in all manipulators, used only for tracking load progress
   /// this is calculated right before writing.
   mutable EcXmlU32 m_TotalReadableLinkCount;

   ///----Non-XML

   // the precision level used for collision detection
   // set to zero by default
   EcU32 m_CollisionDetectionPrecisionLevel;

   /// the bounding box tree for environment obstacles
   EcBoxTreeNode     m_BoundingBoxTree;
};

#endif // ecManipSystem_H_
