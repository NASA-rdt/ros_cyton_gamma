#ifndef ecIndManipulator_H_
#define ecIndManipulator_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecIndManipulator.h
/// @class EcIndividualManipulator
/// @brief An individual manipulator is described through this class.
///        It includes a string label, a physical extent of the base,
///        a list of top-most links, and a dynamic reference frame.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecGeneralBoundObjectVector.h"
#include "ecManipReferenceDescription.h"
#include "ecManipSelfCollisionLinkMap.h"
#include "ecManipulatorLink.h"
#include "ecStateConstraintVector.h"
#include "ecStateEqualityConstraintVector.h"
#include "ecStoppingCriterionVector.h"
#include "ecPropagationResultData.h"

#include <geometry/ecSphere.h>

// forward declarations
class EcAccelerationState;
class EcManipulatorPointEvent;
class EcMassMatrixTool;
class EcPropagationResultData;

/** Holds a description of an individual (branching) robotic manipulator.
 The manipulator as a defined base and a vector of links directly
 connected to the base.  Each of these links can hold a bifurcating tree
 of links beneath it.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcIndividualManipulator : public EcManipulatorLink
{
public:
   /// default constructor
   EcIndividualManipulator
      (
      );

   /// destructor
   virtual ~EcIndividualManipulator
      (
      );

   /// copy constructor
   EcIndividualManipulator
      (
      const EcIndividualManipulator& orig
      );

   /// assignment operator
   EcIndividualManipulator& operator=
      (
      const EcIndividualManipulator& orig
      );

   /// assignment operator, except the child links
   EcIndividualManipulator& copyAllButChildLinksFrom
      (
      const EcIndividualManipulator& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcIndividualManipulator& orig
      ) const;

   /// equality operator for manipulator referencing
   /// (exlcludes label equality)
   EcBoolean equalForReferencing
      (
      const EcIndividualManipulator& orig
      ) const;

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

   /// gets the child links - overridded to get reference's children
   /// if needed
   virtual const EcXmlVectorType<EcManipulatorLink>& childLinks
      (
      ) const;

   /// sets the child links - overridden to remap the manipulator
   virtual void setChildLinks
      (
      const EcXmlVectorType<EcManipulatorLink>& childLinks
      );

   /// add a child link by copy - overridden to remap the manipulator
   virtual void addChild
      (
      const EcManipulatorLink& childLink
      );

   /// set everything from a link object
   virtual void setFromLink
      (
      const EcManipulatorLink& link
      );

   /// clear the child links vector
   virtual void clearChildLinks
      (
      );

   /// add a link by copy to the end of the first chain rooted
   /// at this link - overridden to remap the manipulator
   virtual void addLinkToEndOfChain
      (
      const EcManipulatorLink& link
      );

   /// gets coordinate system transformation
   virtual const EcCoordinateSystemTransformation& coordSysXForm
      (
      ) const;

   /// sets coordinate system transformation
   virtual void setCoordSysXForm
      (
      const EcCoordinateSystemTransformation& coordSysXForm
      );

   /// gets the absolute bounding sphere
   virtual const EcSphere& absoluteBoundingSphere
      (
      ) const;

   /// sets the absolute bounding sphere
   virtual void setAbsoluteBoundingSphere
      (
      const EcSphere& absoluteBoundingSphere
      );

   /// sets the absolute bounding sphere
   virtual void buildSelfCollisionLinkMap
      (
      );

   /// fits the bounding sphere appropriately based on the manipulator
   virtual void fitAbsoluteBoundingSphere
      (
      );

   /// gets the fixed-base flag
   virtual EcBoolean isFixedBase
      (
      ) const;

   /// sets the fixed-base flag
   virtual void setIsFixedBase
      (
      EcBoolean isFixedBase
      );

   /// gets the flag indicating to optimize on load
   virtual EcBoolean optimizeOnLoad
      (
      ) const;

   /// sets the absolute bounding sphere
   virtual void setOptimizeOnLoad
      (
      EcBoolean optimizeOnLoad
      );

   /// gets the is-controllable flag
   virtual EcBoolean isControllable
      (
      ) const;

   /// sets the is-controllable flag
   virtual void setIsControllable
      (
      EcBoolean isControllable
      );

   /// gets the manipulator reference description
   virtual const EcManipulatorReferenceDescription& manipulatorReferenceDescription
      (
      ) const;

   /// sets the manipulator reference description
   virtual void setManipulatorReferenceDescription
      (
      const EcManipulatorReferenceDescription& manipulatorReferenceDescription
      );

   /// gets the index for this link
   virtual EcU32 linkIndex
      (
      ) const;

   /// gets the manipulator index for this manipulator
   virtual EcU32 manipulatorIndex
      (
      )const;

   /// set the manipulator index
   void setManipulatorIndex
      (
      EcU32 manipIndex
      );

   /// gets the number of degrees of freedom in the manipulator, excluding
   /// the position and orientation of the base.
   virtual EcU32 jointDof
      (
      ) const;

   /// gets the number of degrees of freedom in the manipulator, including
   /// the position and orientation of the base.
   virtual EcU32 jointAndBaseDof
      (
      ) const;

   /// gets the total of degrees of freedom in the manipulator.  If the
   /// manipulator is fixed base, it returns the number of joints (same as
   /// jointDof()), otherwise it returns the number of joints plus the
   /// degrees of freedom in the base (in this case it is the same as
   /// jointAndBaseDof()).
   virtual EcU32 totalDof
      (
      ) const;

   /// the fast test for collisions
   virtual const EcBooleanVectorVector& linkCollisionTest
      (
      ) const;

   /// get the link's D-H frame represented in the system frame
   /// this is overridden from the parent to set the base value
   virtual const EcCoordinateSystemTransformation& dhFrameInSystem
      (
      EcManipulatorActivePositionState& actPosState
      ) const;

   /// get the link's D-H frame velocity represented in the system frame.
   /// The point of application of this motion is the origin of the D-H
   /// frame.
   virtual const EcGeneralVelocity& dhFrameVelocityInSystem
      (
      EcManipulatorActiveState& actState
      ) const;

   /// get the link's D-H frame velocity represented in the local frame
   virtual const EcGeneralVelocity& dhFrameVelocityInLocal
      (
      EcManipulatorActiveState& actState
      ) const;

   /// get the link's primary frame velocity represented in the system frame
   /// The point of application of this motion is the origin of the primary
   /// frame.
   virtual const EcGeneralVelocity& primaryFrameVelocityInSystem
      (
      EcManipulatorActiveState& actState
      ) const;

   /// get the link's D-H frame acceleration represented in the local frame
   virtual const EcGeneralAcceleration& dhFrameAccelerationInLocal
      (
      EcManipulatorActiveState& actState
      ) const;

   /// @copydoc EcManipulatorLink::dhFrameForceInLocal()
   virtual const EcGeneralForce& dhFrameForceInLocal
      (
      const EcManipulatorExternalForce& manipExtForce,
      EcManipulatorActiveState& actState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// @copydoc EcManipulatorLink::crbi()
   virtual const EcRigidBodyMassProperties& crbi
      (
      EcManipulatorActiveState& actState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// get the Cholesky Decomposition (L such that L*L^T=M) of the 6x6
   /// spatial representation of the composite rigid-body inertia (as
   /// represented in the DH frame).
   /**
    * @param actState The manipulator active state
    * @param statedSystemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return the Cholesky Decomposition
    */
   virtual const EcReArray& crbiSpatialCholeskyDecomposition
      (
      EcManipulatorActiveState& actState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// @copydoc EcManipulatorLink::arbd()
   virtual const EcArticulatedBodyDynamics& arbd
      (
      const EcManipulatorExternalForce& manipExtForce,
      const EcManipulatorTorque& manipTorque,
      EcManipulatorActiveState& actState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// get the supplemental D-H frame acceleration represented in the local frame.
   /// this supplemental acceleration is the difference between the true acceleration
   /// produced by the manipulator torque and external forces and the acceleration
   /// calculated from the acceleration state.
   /**
    * @param manipExtForce The external force
    * @param manipTorque The manipulator torque
    * @param actState The manipulator active state
    * @param statedSystemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return the supplemental D-H frame acceleration represented in the local frame.
    */
   virtual const EcGeneralAcceleration& arbiSupplementalDhFrameAccelerationInLocal
      (
      const EcManipulatorExternalForce& manipExtForce,
      const EcManipulatorTorque& manipTorque,
      EcManipulatorActiveState& actState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// get the acceleration of the base using the arbi algorithm in base-frame coordinates.
   /**
    * @param manipExtForce The external force
    * @param manipTorque The manipulator torque
    * @param actState The manipulator active state
    * @param statedSystemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return the acceleration of the base
    */
   virtual const EcGeneralAcceleration& arbiBaseAccelerationInLocal
      (
      const EcManipulatorExternalForce& manipExtForce,
      const EcManipulatorTorque& manipTorque,
      EcManipulatorActiveState& actState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// gets the index of a link with the specified identifier
   /// returns VOIDINDEX if it doesn't exist.
   virtual EcU32 linkIndexByIdentifier
	   (
	   const EcString& label
	   ) const;

   /// gets a pointer to the link with the specified identifier
   /// returns NULL if it doesn't exist.
   virtual const EcManipulatorLink* linkByIdentifier
      (
      const EcString& label
      ) const;

   /// gets a pointer to the link with the specified index
   /// returns NULL if the index is out of range.
   virtual const EcManipulatorLink* linkByIndex
      (
      const EcU32 index
      ) const;

   /// changes the label of one of the manipulator's links
   virtual EcBoolean changeLinkLabel
      (
      const EcString& fromLabel,
      const EcString& toLabel
      );

   /// propagate a position state with a given velocity and time
   /**
    * @param velocityState The velocity state used to propagate the position state
    * @param deltaT The time increment
    * @param[out] positionState The position state after propagation
    */
   virtual void propagateState
      (
      const EcVelocityState& velocityState,
      EcReal deltaT,
      EcPositionState& positionState
      ) const;

   /// propagate a position state with a given velocity and time and return diagnostic information
   /**
    * @param velocityState The velocity state used to propagate the position state
    * @param deltaT The time increment
    * @param[out] positionState The position state after propagation
    * @param[out] propagationResultData The diagnostic information (whether joint limits have been hit)
    *             that results from propagation.
    */
   virtual void propagateState
      (
      const EcVelocityState& velocityState,
      EcReal deltaT,
      EcPositionState& positionState,
      EcPropagationResultData& propagationResultData
      ) const;

   /// propagate a velocity state with a given acceleration and time
   /**
    * @param accelerationState The acceleration state used to propagate the velocity state
    * @param deltaT The time increment
    * @param[out] velocityState The velocity state after propagation
    */
    virtual void propagateVelocityState
      (
      const EcAccelerationState& accelerationState,
      EcReal deltaT,
      EcVelocityState& velocityState
      ) const;

   /// intersect a line segment with the manipulator, returning the closest
   /// point along the line segment, based on an initial closest point as
   /// provided in pointEvent.
   virtual void intersectLineSegmentWithManipulator
      (
      const EcLineSegment& lineSegment,
      EcManipulatorPointEvent& pointEvent,
      EcManipulatorActiveState* pActState,
      EcU32 levelOfDetail=0
      ) const;

   /// find and convert all explicit link descriptions to references
   virtual EcBoolean findAndConvertToReferences
      (
      );

   /// we are about to modify a link shape.  Find and fix all references to this shape
   /**
    * @param label The label of the link to be modified
    * @return True if the link by the given label exists or false otherwise
    */
   virtual EcBoolean aboutToModifyLink
      (
      const EcString& label
      );

   /// replace a link and all its children
   /**
    * @param linkLabel The label of the link to be replaced
    * @param newLink The link used to replace
    * @return True if the link by the given label exists or false otherwise
    */
   virtual EcBoolean replaceLinkAndChildren
      (
      const EcString& linkLabel,
      const EcManipulatorLink& newLink
      );

   /// replace the kinematics for a link, accessed by index
   virtual EcBoolean replaceLinkKinematics
      (
      EcU32 linkIndex,
      const EcLinkKinematics& newKinematics
      );

   /// replace the kinematics for a link, accessed by label
   virtual EcBoolean replaceLinkKinematics
      (
      const EcString& linkLabel,
      const EcLinkKinematics& newKinematics
      );

   /// replace the shape for a link, accessed by index
   virtual EcBoolean replaceLinkShape
      (
      EcU32 linkIndex,
      const EcShape& newShape
      );

   /// replace the shape for a link, accessed by label
   virtual EcBoolean replaceLinkShape
      (
      const EcString& linkLabel,
      const EcShape& newShape
      );

   /// change the primary frame for a link, accessed by index
   virtual EcBoolean replaceLinkPrimaryFrame
      (
      EcU32 linkIndex,
      const EcCoordinateSystemTransformation& newXForm
      );

   /// change the primary frame for a link, accessed by label
   virtual EcBoolean replaceLinkPrimaryFrame
      (
      const EcString& linkLabel,
      const EcCoordinateSystemTransformation& newXForm
      );

   using EcManipulatorLink::transformPrimaryFrame;
   /// transform the link so that the primary frame transformation
   /// is that given, but the link does not change (i.e., if xform
   /// is identity, then the primary frame will coincide with the DH
   /// frame, but the link won't change).
   virtual EcBoolean transformPrimaryFrame
      (
      const EcString& linkLabel,
      const EcCoordinateSystemTransformation& xform
      );

   /// transform all primary frames to identity.  This is eqivalent to
   /// calling transformPrimaryFrame with identity for all links
   virtual EcBoolean transformAllPrimaryFramesToIdentity
      (
      );

   /// transform components (mass properties and shape) of a link in the tree.
   /// this has the same effect as setting the primary frame from identity to this value
   virtual EcBoolean transformLinkComponentsBy
      (
      const EcString& linkLabel,
      const EcCoordinateSystemTransformation& xform
      );

   /// transform a subtree with respect to the top link's parent by a general
   /// coordinate system transformation.  This transformation
   /// is inserted before the link placement.
   virtual EcBoolean transformLinkSubtreeBy
      (
      const EcString& linkLabel,
      const EcCoordinateSystemTransformation& xform
      );

   /// configure a manipulator reference, if present
   virtual EcBoolean configureManipulatorReference
      (
      const EcXmlVectorType<EcIndividualManipulator>& manipulatorVector
      );

   /// get the general bound objects
   virtual const EcGeneralBoundObjectVector& generalBoundObjects
      (
      )const;

   /// set the general bound objects
   virtual void setGeneralBoundObjects
      (
      const EcGeneralBoundObjectVector& objs
      );

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

   /// get link vector
   virtual const EcManipulatorLinkConstPointerVector& getLinkPointerVector
      (
      ) const;

   /// get link map
   virtual const EcManipulatorLinkPointerMap& getLinkPointerMap
      (
      ) const;
   /// map all links in the manipulator
   virtual EcBoolean mapManipulator
      (
      );

   /// map all links in the manipulator
   virtual EcBoolean mapManipulator
      (
      EcManipulatorLinkConstPointerVector& linkVector,
      EcManipulatorLinkPointerMap& linkMap
      );

   /// gets surface property collection
   virtual const EcStringDataMapMap& surfaces
      (
      ) const;

   using EcManipulatorLink::setSurfaces;
   /// set the surface properties collection for this shape
   virtual void setSurfaces
      (
      const EcStringDataMapMap& surfaces
      );

   /// set the self-collision link map
   virtual void setSelfCollisionLinkMap
      (
      const EcManipulatorSelfCollisionLinkMap& map
      );

   /// get the self-collision link map
   virtual const EcManipulatorSelfCollisionLinkMap& selfCollisionLinkMap
      (
      )const;

   /// lookup up surface properties given a key
   EcBoolean lookup
      (
      const EcString& key,
      const EcDataMap*& property
      ) const;

   /// add a capsule bounding volume to the BVH for each link, if
   /// it doesn't already exist
   void addCapsuleBoundingVolumeToLinks
      (
      )const;

   /// add a capsule bounding volume to the BVH for each link, if
   /// it doesn't already exist
   void addSphereBoundingVolumeToLinks
      (
      )const;

   /// Add an EcBoundingBox bounding volume to each of the links
   /// within the BVH if it doesn't already have one
   void addBoundingBoxToLinks
      (
      )const;

   /// Add an convex hull bounding volume to each of the links
   /// within the BVH if it doesn't already have one
   void addConvexHullToLinks
      (
      );

   /// build the lightweight logical array of link interactions
   virtual void mapLinkCollisionCandidates
      (
      );

   /// set shape surface properties by the IDs.
   virtual EcBoolean setSurfacesByIDs
      (
      const EcU32& linkID,
      const EcU32& shapeID,
      const EcStringDataMapMap& surfaces
      );

   /// returns a boolean describing if two links can collide
   virtual EcBoolean canCollide
      (
      EcU32 linkID1,
      EcU32 linkID2
      )const;

   /// set the properties of the surface identified by key.
   /**
   \param[in] key A string to identify the surface material.
   \param[in] properties The surface properties to be set.
   \return True if key is found or false otherwise.
   */
   virtual EcBoolean setSurfaceProperties
      (
      const EcString& key,
      const EcDataMap& properties
      );

   /// computes and returns the center of mass of the manipulator in system coordinates.
   virtual EcVector getCenterOfMassInSystem
      (
      EcManipulatorActiveState& activeState
      ) const;

   /// truncate values in the physical extents to the precision specified.
   virtual void truncateValues
      (
      const EcReal& precision = 1e-10
      );

   /// simplify the manipulator by replacing link shapes with capsules.
   /**
   \param[in] color Specify the color to use. Default to defaultManipColor.
   */
   virtual void simplifyLinkShapesWithCapsules
      (
      const EcDataMap& color=EcDataMap::defaultManipColor()
      );

   /// simplify the manipulator by replacing link shapes with convex hulls.
   /**
   \param[in] color Specify the color to use. Default to defaultManipColor.
   */
   virtual void simplifyLinkShapesWithConvexHulls
      (
      const EcDataMap& color=EcDataMap::defaultManipColor()
      );

   /// simplify the manipulator by replacing link shapes with the existing bounding volumes
   /**
   \param[in] color Specify the color to use. Default to defaultManipColor.
   \param[in] keepShape If true, then the existing shapes on links with no bounding volumes will be kept. Otherwise, there will be no shapes on links with no bounding volumes.
   */
   virtual void simplifyLinkShapesWithBoundingVolumes
      (
      const EcDataMap& color=EcDataMap::defaultManipColor(),
      EcBoolean keepShape=EcTrue
      );

   /// get the link's center of mass velocity represented in the local frame
   virtual const EcGeneralVelocity& comVelocityInLocal
      (
      EcManipulatorActiveState& activeState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// get the link's center of mass acceleration represented in the local frame
   virtual const EcGeneralAcceleration& comAccelerationInLocal
      (
      EcManipulatorActiveState& activeState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// get the spatial momentum at the center of mass of this link represented in the link's D-H frame.
   virtual const EcGeneralMotion& spatialMomentumInLocal
      (
      EcManipulatorActiveState& activeState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// get the composite spatial momentum of this link and its outboard links represented in the link's D-H frame.
   virtual const EcGeneralMotion& compositeSpatialMomentumInLocal
      (
      EcManipulatorActiveState& activeState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// get the rate of spatial momentum at the center of mass of this link represented in the link's D-H frame.
   virtual const EcGeneralMotion& spatialMomentumRateInLocal
      (
      EcManipulatorActiveState& activeState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// get the composite rate of spatial momentum of this link and its outboard links represented in the link's D-H frame.
   virtual const EcGeneralMotion& compositeSpatialMomentumRateInLocal
      (
      EcManipulatorActiveState& activeState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// Compute the zero moment point (ZMP) of this manipulator on plane. Gravity is provided explicitly and must not be included in activeState.
   /**
   \param[in] gravity The gravity vector.
   \param[in] plane The plane on which ZMP is computed. Must be in system coordinates.
   \param[in] activeState The active state of this manipulator.
   \param[out] zmp The zero moment point in system coordinates.
   \param[in] statedSystemStruct
   */
   virtual void computeZeroMomentPoint
      (
      const EcVector& gravity,
      const EcPlane& plane,
      EcManipulatorActiveState& activeState,
      EcVector& zmp,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// Compute the zero moment point (ZMP) of this manipulator on plane. Gravity is assumed to be included as the acceleration of the base in activeState in the form of up gravity, i.e. if the gravity is g in the -Z direction, then the base acceleration should be g in the +Z direction.
   /**
   \param[in] plane The plane on which ZMP is computed. Must be in system coordinates.
   \param[in] activeState The active state of this manipulator.
   \param[out] zmp The zero moment point in system coordinates.
   \param[in] statedSystemStruct
   */
   virtual void computeZeroMomentPoint
      (
      const EcPlane& plane,
      EcManipulatorActiveState& activeState,
      EcVector& zmp,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// Compute the total kinetic energy of all links (including base) of the manipulator.
   /**
   \param[in] activeState The active state of this manipulator.
   \param[in] massMatrixTool A pointer to EcMassMatrixTool instance. If it's not provided, one will be created internally. For more efficient calculation, one should be passed in.
   \return The total kinetic energy.
   */
   virtual EcReal computeKineticEnergy
      (
      EcManipulatorActiveState& activeState,
      EcMassMatrixTool* massMatrixTool=0
      ) const;

   /// gets the state constraints.
   /**
   These are the constraints that limit the motion of the robot in through inequalities, including the motions of the joints or the mobile base. For example, a constraint can be created to keep the robot from getting too close to a wall. Although this task could also be accomplished by obstacle avoidance, using the constraint approach is potentially much faster. Each constraint must be in the form of f(q) >= 0, where q is the position state (base position plus joint positions).
   Note that these constraints are in addition to the upper and lower limit constraints that exist in each of the manipulator link.
   */
   virtual const EcStateConstraintVector& stateConstraints
      (
      ) const;

   /// sets the state constraints.
   virtual void setStateConstraints
      (
      const EcStateConstraintVector& value
      );

   /// gets the state equality constraints.
   /**
   These are the constraints that limit the motion of the robot through equalities, including the motions of the joints or the mobile base. For example, a constraint can be created to keep the robot from getting too close to a wall. Although this task could also be accomplished by obstacle avoidance, using the constraint approach is potentially much faster. Each constraint must be in the form of f(q) >= 0, where q is the position state (base position plus joint positions).
   Note that these constraints are in addition to the upper and lower limit constraints that exist in each of the manipulator link.
   */
   virtual const EcStateEqualityConstraintVector& stateEqualityConstraints
      (
      ) const;

   /// sets the state equality constraints.
   virtual void setStateEqualityConstraints
      (
      const EcStateEqualityConstraintVector& value
      );

   /// gets the stopping criteria.
   virtual const EcStoppingCriterionVector& stoppingCriteria
      (
      ) const;

   /// sets the stopping criteria.
   virtual void setStoppingCriteria
      (
      const EcStoppingCriterionVector& stoppingCriteria
      );

   /// gets the vector of link indices in order of how to display them
   virtual const EcXmlU32Vector& displayLinkIndices
      (
      ) const;

   /// sets the vector of link indices in order of how to display them
   virtual void setDisplayLinkIndices
      (
      const EcXmlU32Vector& value
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

   /// get a null link
   static EcIndividualManipulator nullObject
      (
      );

   /// get the DH parameters for the robot in Craig's formalism
   /// format: a, alpha, d
   /// if the link kinematics do not support Craig's notation, then
   /// the values are empty
   virtual EcBoolean getCraigDhParameters
      (
      EcRealVector& dhSet
      ) const;

   /// set the bounding volume of a link in the manipulator.
   /**
   This method will set the given shape as the bounding volume of the link specified by the given label.
   \param[in] linkLabel The label of the link to which to set bounding volume
   \param[in] bvShape The shape of the bounding volume
   \param[in] pSurface The surface properties to be used for the bounding volume. If not given, the bounding volume will have the default bounding color and will assume other surface properties, such as surface spring and damper constants, from the link.
   \return True if linkLabel is valid and the bounding volume is successfully set or false otherwise.
   */
   virtual EcBoolean setBoundingVolume
      (
      const EcString&          linkLabel,
      const EcShape&           bvShape,
      const EcDataMap*         pSurface=EcNULL
      );

protected:

   /// used to manipulate the link map
   EcBoolean makeIndicesCompatible
      (
      EcU32& index1,  // index of link
      EcU32& index2   // index of link
      )const;

   /// the the coordinate system transformation from the system reference frame
   EcCoordinateSystemTransformation         m_CoordSysXForm;

   /// the absolute bounding sphere.  No matter what the joint values (within joint limits),
   /// the manipulator will lie within this sphere (described in the base (not system)
   /// coordinate frame)
   EcSphere                                 m_AbsoluteBoundingSphere;

   /// a flag indicating whether or not the base is fixed or free
   EcXmlBoolean                             m_IsFixedBase;

   /// a flag indicating whether or not to optimize upon loading.  Optimization takes up-front
   /// time, but may improve run-time performance.  It only needs to be done once.
   EcXmlBoolean                             m_OptimizeOnLoad;

   /// a flag indicating whether or not this manipulator is controllable
   EcXmlBoolean                             m_IsControllable;

   /// a description of the
   EcManipulatorReferenceDescription        m_ManipulatorReferenceDescription;

   /// a vector holding general bound objects
   EcGeneralBoundObjectVector               m_GeneralBoundObjects;

   /// a vector of state inequality constraints
   EcStateConstraintVector                  m_vStateConstraints;

   /// a vector of state equality constraints
   EcStateEqualityConstraintVector          m_vStateEqualityConstraints;

   /// a vector of stopping criteria
   EcStoppingCriterionVector                m_vStoppingCriteria;

   /// a vector of link indices in order of how to display them
   EcXmlU32Vector                           m_vDisplayLinkIndices;

   // non-XML data

   /// organization of the links into a depth-first vector
   EcManipulatorLinkConstPointerVector      m_LinkPointerVector;

   /// organization of the links into a string-based map
   EcManipulatorLinkPointerMap              m_LinkPointerMap;

   /// a map of surface properties by string key for the manipulator
   EcStringDataMapMap                       m_Surfaces;

   /// a mapping of which links can collide with which others
   EcManipulatorSelfCollisionLinkMap        m_SelfCollisionLinkMap;

   /// a static zero acceleration
   static const EcGeneralAcceleration       m_theZeroAcceleration;

   /// the index of this manipulator
   mutable  EcU32                           m_ManipIndex;

   /// a 2D array of link collision
   mutable EcBooleanVectorVector            m_LinkCollisionTest;

   /// a pointer to a reference manipulator
   mutable const EcIndividualManipulator*   m_pReferenceManipulator;

   /// a utility value for holding propagation results
   mutable EcPropagationResultData          m_UtilityPropagationResultData;

   /// a utility value for holding a string key
   mutable EcXmlString                      m_UtilityKey;
};

/// a vector of individual manipulators
typedef EcXmlVectorType<EcIndividualManipulator> EcIndividualManipulatorVector;

#endif // ecIndManipulator_H_
