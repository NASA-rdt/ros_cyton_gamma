#ifndef ecStatedSystem_H_
#define ecStatedSystem_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecStatedSystem.h
/// @class EcStatedSystem
/// @brief A description of a manipulator system with a state.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecManipSysState.h"
#include "ecManipSystem.h"
#include "ecManipulatorProximityTool.h"
#include "ecManipulatorSystemConfiguration.h"
#include "ecPropagationResultData.h"
#include <geometry/ecShapeStateCacheKey.h>
#include <xml/ecXmlCompType.h>

// forward declarations
class EcShapeQueryData;
class EcShapeStateCacheKey;
class EcSystemActiveState;
class EcSystemPointEvent;

/// Holds a description of the manipulator system and its state.
class EC_FOUNDATION_MANIPULATOR_DECL EcStatedSystem : public EcXmlCompoundType
{
public:
   /// collision avoidance modes
   enum {NOCOLLISIONAVOIDANCE,
         SYSTEMCOLLISIONAVOIDANCE,
         MANIPULATORCOLLISIONAVOIDANCE};

   /// default constructor
   EcStatedSystem
      (
      );

   /// destructor
   virtual ~EcStatedSystem
      (
      );

   /// copy constructor
   /**
   \param[in] orig       StatedSystem to copy from
   \param[in] copySystem Specify whether to copy the underlying system or simply reference-count it. By default, this is false, i.e. it will only reference-counting the system.
   */
   EcStatedSystem
      (
      const EcStatedSystem& orig,
      EcBoolean copySystem = EcFalse
      );

   /// assignment operator
   EcStatedSystem& operator=
      (
      const EcStatedSystem& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStatedSystem& orig
      ) const;

   /// merge operation
   virtual EcBoolean mergeWith
      (
      const EcStatedSystem& orig
      );

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// registers components with the parent
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

   /// gets the system
   virtual const EcManipulatorSystem& system
      (
      ) const;

   /// sets the system
   virtual void setSystem
      (
      const EcManipulatorSystem& system
      );

   /// sets the system pointer (and later deletes this pointer)
   virtual void setAndDeleteSystemPointer
      (
      EcManipulatorSystem* pSystem
      );

   /// sets all data from a system.  Uses the midpoint between
   /// joint limits to set the state positions.
   virtual void setFromSystem
      (
      const EcManipulatorSystem& system
      );

   /// sets all data from a single manipulator.  Uses the midpoint between
   /// joint limits to set the state positions.
   virtual void setFromManipulator
      (
      const EcIndividualManipulator& manipulator
      );

   /// clears this stated system and initializes it for having a single
   /// manipulator.  This manipulator is returned by reference so that it
   /// can be set externally without the use of a copy.  After this reference
   /// is set, finalizeForSingleManipulator() must be called.
   /// Use with caution.
   virtual EcIndividualManipulator& clearAndInitializeForOneManipulator
      (
      );

   /// with the first manipulator properly set, this method sets the proper
   /// state.  It should be used only with clearAndInitializeForOneManipulator().
   virtual void finalizeOneManipulator
      (
      );

   /// add a manipulator with the specified position and velocity states
   virtual void addManipulator
      (
      const EcIndividualManipulator& manipulator,
      const EcPositionState& positionState,
      const EcVelocityState& velocityState
      );

   /// add a manipulator using default position and velocity states
   virtual void addManipulator
      (
      const EcIndividualManipulator& manipulator
      );

   /// exchange an existing manipulator with a new manipulator having the
   /// specified position and velocity states
   virtual EcBoolean exchangeManipulator
      (
      EcU32 manipulatorIndex,
      const EcIndividualManipulator& manipulator,
      const EcPositionState& positionState,
      const EcVelocityState& velocityState
      );

   /// add a shape as a manipulator, with the specified position and orientation
   /// returns the index of the new manipulator
   virtual EcU32 addShapeAsManipulator
      (
      const EcShape& shape,
      const EcCoordinateSystemTransformation& pose,
      const EcString& label,
      const EcDataMap& color = EcDataMap::boundingColor()
      );

   /// set the self collisin map for manipulator manipID
   virtual EcBoolean setSelfCollisionMap
      (
      const EcManipulatorSelfCollisionLinkMap& map,
      const EcU32& manipID
      );

   /// delete a manipulator and corresponding position and velocity states by label.
   /**
   \param[in] manipLabel The string label of the manipulator to be deleted. In case of manipulators with duplicated label, the first manipulator with the label matched with manipLabel will be deleted.
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

   /// gets upward pointing gravity vector and other environmental data
   virtual const EcSystemEnvironment& environment
      (
      ) const;

   /// sets upward pointing gravity vector and other environmental data
   virtual void setEnvironment
      (
      const EcSystemEnvironment& environment
      );

   /// gets the state
   virtual const EcManipulatorSystemState& state
      (
      ) const;

   /// sets the state
   virtual void setState
      (
      const EcManipulatorSystemState& state
      );

   /// sets a position state for an individual manipulator
   virtual void setIndividualPositionState
      (
      EcU32 manipulatorIndex,
      const EcPositionState& positionState
      );

   /// sets a base position and orientation for an individual manipulator
   virtual void setIndividualCoordinateSystemTransformation
      (
      EcU32 manipulatorIndex,
      const EcCoordinateSystemTransformation& xform
      );

   /// sets a velocity state for an individual manipulator
   virtual void setIndividualVelocityState
      (
      EcU32 manipulatorIndex,
      const EcVelocityState& velocityState
      );

   /// rotate the linear and angular velocity of the base of one manipulator
   virtual void rotateIndividualBaseVelocity
      (
      EcU32 manipulatorIndex,
      const EcOrientation& orient
      );

   /// zeros a velocity state for an individual manipulator
   virtual void zeroIndividualVelocityState
      (
      EcU32 manipulatorIndex
      );

   /// sets position states
   virtual void setPositionStates
      (
      const EcPositionStateVector& positionStates
      );

   /// sets velocity states
   virtual void setVelocityStates
      (
      const EcVelocityStateVector& velocityStates
      );

   /// gets the configuration, which changes intermittently -- const version
   virtual const EcManipulatorSystemConfiguration& configuration
      (
      ) const;

   /// gets the configuration, which changes intermittently -- non-const version
   virtual EcManipulatorSystemConfiguration& configuration
      (
      );

   /// sets the configuration
   virtual void setConfiguration
      (
      const EcManipulatorSystemConfiguration& value
      );

   /// propagate its own internal state in time.  This keeps the same
   /// velocity state and integrates the position state
   /// using forward Euler.
   virtual void propagateSelfTo
      (
      EcReal newTime,
      EcSystemActiveState* pActState=EcNULL
      );

   /// propagate its own internal state in time.  This keeps the same
   /// velocity state and integrates the position state
   /// using forward Euler.  Diagnostic data is returned.
   /// Collisions are not avoided.
   virtual void propagateSelfTo
      (
      EcReal newTime,
      EcPropagationResultDataVector& resultDataVector,
      EcSystemActiveState* pActState=EcNULL
      );

   /// propagate its own internal state in time.  This keeps the same
   /// velocity state and integrates the position state
   /// using forward Euler.  Diagnostic data is returned.
   /// Collisions are avoided.
   virtual void propagateSelfTo
      (
      EcReal newTime,
      EcPropagationResultDataVector& resultDataVector,
      EcSystemActiveState* pActState,
      EcU32 collisionAvoidanceMode,
      const EcReal& collisionBreakthroughThreshold,
	  const EcU32& bvLevel,
      const EcReal& precision
      );

   /// Propagates the given state in time.  This keeps the same
   /// velocity state and integrates the position state
   /// using forward Euler.
   virtual void propagateTo
      (
      EcReal newTime,
      EcManipulatorSystemState& state,
      EcSystemActiveState* pActState=EcNULL
      ) const;

   /// Propagates the given state in time.  This keeps the same
   /// velocity state and integrates the position state
   /// using forward Euler.  Diagnostic data is returned.
   /// this method does not avoid collisions.
   virtual void propagateTo
      (
      EcReal newTime,
      EcManipulatorSystemState& state,
      EcPropagationResultDataVector& resultDataVector,
      EcSystemActiveState& actState
      ) const;

   /// Propagates the given state in time adhering to the specified
   /// collision avoidance mode.  This keeps the same
   /// velocity state and integrates the position state
   /// using forward Euler.  Diagnostic data is returned
   virtual void propagateTo
      (
      EcReal newTime,
      EcManipulatorSystemState& state,
      EcPropagationResultDataVector& resultDataVector,
      EcSystemActiveState& actState,
      EcU32 collisionAvoidanceMode,
      const EcReal& collisionBreakthroughThreshold,
	  const EcU32& bvLevel,
      const EcReal& precision
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

   /// propagate a single state by delta-t.  This keeps the same
   /// velocity state and integrates the position state
   /// using forward Euler.  The manipulator number is given by index.
   /// Diagnostic data is returned.
   virtual void propagateSingleStateBy
      (
      EcU32 index,
      const EcVelocityState& velocityState,
      EcReal deltaT,
      EcPositionState& positionState,
      EcPropagationResultData& resultData
      ) const;

   /// propagate a single velocity state by delta-t using the acceleration state. The manipulator number is given by index.
   virtual void propagateSingleVelocityStateBy
      (
      EcU32 index,
      const EcAccelerationState& accelerationState,
      EcReal deltaT,
      EcVelocityState& velocityState
      ) const;

   /// Add a zero state that is compatible with the system.
   virtual void addCompatibleState
      (
      );

   /// Add a state that has each joint position halfway between joint limits.
   virtual void setToMidpointState
      (
      );

   /// Extend the state with zeros or contract
   /// to a size that agrees with the system size.
   virtual void rightSizeState
      (
      EcManipulatorSystemState& state
      ) const;

   /// calculate a bounding sphere.  This bounding sphere is not a function
   /// of the joint positions (though it is a function of the manipulator
   /// base positions and orientations.
   virtual EcSphere absoluteBoundingSphere
      (
      ) const;

   /// get a shape by the key. the key is (manipID,linkID,shapeID)
   const EcShape* shapeByKey
      (
      const EcShapeStateCacheKey& key
      )const;

   /// Set shape surface properties by the key.
   virtual EcBoolean setSurfacesByKey
      (
      const EcShapeStateCacheKey& key,
      const EcStringDataMapMap& surfaces
      );

   /// gets deformation states - const version
   /// gets the vector of the modified shape key
   virtual const EcShapeStateCacheKeyVector& modifiedShapeKeyVec
      (
      )const;

   /// gets the vector of the modified shape key (non const version)
   virtual EcShapeStateCacheKeyVector& modifiedShapeKeyVec
      (
      );

   /// sets the vector of deformed shape key
   virtual void setModifiedShapeKeyVec
      (
      const EcShapeStateCacheKeyVector& modifiedShapeKeyVec
      );

   /// add the modified shape key
   virtual void addModifiedShapeKeyVec
      (
      const EcShapeStateCacheKey& modifiedShapeKey
      );

   /// gets the flag for the transparent rendering
   virtual EcBoolean isTransparentDisplay
      (
      ) const;

   /// sets the flag for the transparent rendering
   virtual void setIsTransparentDisplay
      (
      const EcBoolean change
      ) const;

   /// intersect a line segment with the full system
   virtual void intersectLineSegment
      (
      const EcLineSegment& lineSegment,
      EcSystemPointEvent& pointEvent,
      EcSystemActiveState* pActState,
      EcU32 levelOfDetail=0
      ) const;

   /// scale an individual manipulator by the given distance factor
   /// scaleFactor 1.0 leaves the manipulator unchanged.
   virtual EcBoolean scaleManipulatorBy
      (
      EcU32 manipulatorIndex,
      EcReal scaleFactor
      );

   /// find and convert explicit manipulator link descriptions to references
   /// where possible
   virtual EcBoolean findAndConvertToReferences
      (
      );

   /// get the joint dof of the manipulator at index *index*
   virtual const EcU32 jointDof
      (
      const EcU32& index
      )const;

   /// set the new value for a joint limit
   /**
   \param[in] manipulatorIndex The index of the manipulator
   \param[in] linkLabel The identifying label of the link (joint)
   \param[in] isLowerLimit True for a lower limit or false for upper limit
   \param[in] value The new value for the joint limit
   \return True if successful or false if linkLabel is invalid
   */
   virtual EcBoolean setJointLimit
      (
      EcU32 manipulatorIndex,
      const EcString& linkLabel,
      EcBoolean isLowerLimit,
      EcReal value
      );

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

   /// generate a collision report based on the
   /// current state of the system.
   virtual EcBoolean generateCollisionReport
      (
      EcPropagationResultDataVector& collisions,
	  const EcU32& bvLevel = 1,
      const EcReal& precision=0
      )const;

   /// returns true if the system has recently been modified. This is useful for rendering since it needs to grab internal pointers of the system and if it has been modified, those pointers will be invalid. Rendering can check it and if the system has just been modified, it can grab new pointers.
   virtual EcBoolean isSystemModified
      (
      ) const;

   /// sets isSystemModified to false. Rendering should call this after it's done grabbing new pointers to the system internals.
   virtual void resetIsSystemModified
      (
      ) const;

   /// truncate values in the physical extents to the precision specified.
   virtual void truncateValues
      (
      const EcReal& precision = 1e-10
      );

   /// get a null stated system
   static EcStatedSystem nullObject
      (
      );

   /// change the Ambient Alpha value for a surface given a Shape key (assumed shapeID = 0)
   virtual void changeAmbientAlpha
      (
      const EcShapeStateCacheKey& key,
      const EcReal &transparencyLevel
      );

   /// change the Ambient Alpha value for a surface given a Shape key (assumed shapeID = 0)
   virtual void changeDiffuseAlpha
      (
      const EcShapeStateCacheKey& key,
      const EcReal &transparencyLevel
      );

   /// change the Ambient Alpha value for a surface given a Shape key (assumed shapeID = 0)
   virtual void changeSpecularAlpha
      (
      const EcShapeStateCacheKey& key,
      const EcReal &transparencyLevel
      );

   /// change the Ambient Alpha value for a surface given a Shape key (assumed shapeID = 0)
   virtual void changeEmissionAlpha
      (
      const EcShapeStateCacheKey& key,
      const EcReal &transparencyLevel
      );

   /// get the selected Shape Key vector for rendering their member's transparency
   virtual const EcShapeStateCacheKeyVector& selectedShapeKeyVector
      (
      ) const;

   /// set the selected Shape Key vector for rendering their member's transparency
   virtual void setSelectedShapeKeyVector
      (
      const EcShapeStateCacheKeyVector &keyVector
      );

   /// get the transparency level
   virtual const EcReal transparencyAlpha
      (
      ) const;

   /// set the transparency level
   virtual void setTransparencyAlpha
      (
      const EcReal alphaValue
      );

   /// check if there's any change in the AnatomySelector dialog
   virtual EcBoolean isSelectionDataChanged
      (
      ) const;

   /// set the flag telling if there's any change in the AnatomySelector dialog
   virtual void setIsSelectionDataChanged
      (
      const EcBoolean change
      ) const;

   /// set the static (system) collision exclusion map
   virtual void setCollisionExclusionMap
      (
      const EcSystemCollisionExclusionMap& value
      );

   /// set the dynamic (runtime) collision exclusion map
   virtual void setDynamicCollisionExclusionMap
      (
      const EcSystemCollisionExclusionMap& value
      );

   /// set the manipulator attachment map
   virtual void setManipulatorAttachmentMap
      (
      const EcManipulatorAttachmentMap& value
      );

   /// get the manipulator index from base link label
   virtual EcBoolean lookupManipulatorIndexFromLabel
      (
      const EcString& label,
      EcU32& manipIndex
      ) const;

   /// returns a boolean describing if two links on two DIFFERENT manipulators can collide.
   /// This uses both static (in system) and dynamic (in configuration) collision exclusion map.
   virtual EcBoolean canCollide
      (
      EcU32 manip1Index,
      EcU32 link1Index,
      EcU32 manip2Index,
      EcU32 link2Index
      ) const;

protected:
   /// ensure a match in the numbers of manipulators
   virtual EcBoolean validateTopLevelDimensions
      (
      );

   /// ensure a match in the sizes of manipulators
   virtual EcBoolean validateLowLevelDimensions
      (
      );

   /// update reference counting data to prepare for modification
   virtual void aboutToModifySystem
      (
      );

   /// initialize the system if it is not already initialized
   virtual EcBoolean initializeSystem
      (
      );

   /// re-register the system if needed
   virtual void reregisterSystem
      (
      );

   /// get a newed system pointer
   virtual EcManipulatorSystem* newManipulatorSystem
      (
      ) const;


   /// check for manipulator collisions
   virtual EcBoolean checkForCollisions
      (
      EcSystemActiveState& systemActiveState,
      const EcReal& collisionBreakthroughThreshold,
      const EcU32& bvLevel,
	  const EcReal& precision,
      EcPropagationResultDataVector& results
      )const;

   /// a pointer to the system, which does not change
   EcManipulatorSystem*             m_pSystem;

   /// a reference count for the system
   EcU32*                           m_pSystemReferenceCount;

   /// the state, which changes constantly
   EcManipulatorSystemState         m_State;

   /// the configuration, which changes intermittently
   EcManipulatorSystemConfiguration m_Configuration;

   /// a utility vector of position states used for collision detection
   mutable EcPositionStateVector                   m_LastPositionStateVector;

   /// a utility vector of position states used for collision detection
   mutable EcSystemActiveState*                    m_pCurrentSystemActiveState;

   /// a pointer to a utility vector of position states used for static collision detection
   /// (i.e. assuming no position control)
   mutable EcSystemActiveState*                    m_pStaticSystemActiveState;

   /// a utility vector of propagation information results for iteration
   mutable EcPropagationResultDataVector           m_IterativeResultsVector;

   /// a utility vector of propagation information results
   mutable EcPropagationResultDataVector           m_UtilityResultsDataVector;

   /// a null system to return when the pointers are not valid
   static const EcManipulatorSystem                m_theNullSystem;

   /// vector to store the modified shapes by key
   EcShapeStateCacheKeyVector                      m_ModifiedShapeKeyVec;

   /// a flag indicating whether or not the system has just been modified
   mutable EcBoolean                               m_IsSystemModified;

   /// vector to store selected viewable shapes by key
   EcShapeStateCacheKeyVector                      m_SelectedShapeKeyVector;

   /// alpha value for transparency
   EcReal                                          m_TransparencyAlpha;

   /// change made by user via AnatomySelector Dialog
   mutable EcBoolean                               m_IsSelectionDataChanged;

   /// picked for visualization parameter changes
   mutable EcBoolean                               m_IsTransparentDisplay;

   /// the proximity tool used to compute distances
   mutable EcManipulatorProximityTool              m_ProximityTool;
};

/// A vector of stated systems
typedef EcXmlVectorType<EcStatedSystem> EcStatedSystemVector;

#endif // ecStatedSystem_H_
