#ifndef ecManipulatorLink_H_
#define ecManipulatorLink_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulatorLink.h
/// @class EcManipulatorLink
/// @brief A Class describing a robotic manipulator link.  This
///        includes a list of child links, a string identifier,
///        a Denavit-Hartenberg set, the physical extent, an
///        actuator description, and mass properties.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecArticulatedBodyDynamics.h"
#include "ecDamperProperties.h"
#include "ecJointActuator.h"
#include "ecLinkKinematicsContainer.h"
#include "ecLinkReferenceDescription.h"
#include "ecMultivariableJointStateConstraint.h"
#include "ecRigidBodyMass.h"
#include "ecSpringProperties.h"
#include "ecStateConstraintContainer.h"
#include <foundCommon/ecFoundCommonTypes.h>
#include <geometry/ecBasePhysicalExtent.h>
#include <geometry/ecPolyPhysicalExtent.h>
#include <geometry/ecShapeContainer.h>
#include <geometry/ecShapeQueryData.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

#include <boost/shared_ptr.hpp>

// for backward-compatibility
#include "ecJointActuatorContainer.h"
#include "ecOldJointActuator.h"

// forward declarations
class EcAxisAlignedBoundingBox;
class EcCollisionDescriptor;
class EcDataMap;
class EcIndividualManipulator;
class EcManipulatorActivePositionState;
class EcManipulatorActiveState;
class EcManipulatorLink;
class EcManipulatorTorque;
class EcManipulatorExternalForce;
class EcLinkPointEvent;
class EcStatedSystemStruct;
class EcSystemActiveState;

/// type definition of vector of const link pointers
typedef std::vector<const EcManipulatorLink*> EcManipulatorLinkConstPointerVector;

/// type definition of map of EcString and const link pointers
typedef std::map<EcString,const EcManipulatorLink*> EcManipulatorLinkConstPointerMap;

/// type definition of map of EcString and non-const link pointers
typedef std::map<EcString,EcManipulatorLink*> EcManipulatorLinkPointerMap;

/// type definition of XML map of EcXmlString and EcXmlVector
typedef EcXmlMapType<EcXmlString,EcXmlVector> EcNamedPoints;

/// type definition of map of EcXmlString and EcCoordinateSystemTransformation
typedef EcXmlMapType<EcXmlString,EcCoordinateSystemTransformation> EcNamedFrames;

/// type definition of XML vector of EcManipulatorActiveState
typedef EcXmlVectorType<EcManipulatorActiveState> EcManipulatorActiveStateVector;

/// type definition of XML vector of EcCollisionDescriptor
typedef EcXmlVectorType<EcCollisionDescriptor> EcCollisionDescriptorVector;

/// type definition of XML vector of EcAxisAlignedBoundingBox
typedef EcXmlVectorType<EcAxisAlignedBoundingBox> EcAxisAlignedBoundingBoxVector;

/// type definition of XML map of EcXmlString and EcRigidBodyMassProperties
typedef EcXmlMapType< EcXmlString, EcRigidBodyMassProperties >    EcRigidBodyMassPropertiesMap;

/// Holds a description of a manipulator link.
/** This description includes the physical extent and geometry of the link.
 Each link can have any number of child links, so a link is in general the root of a tree.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorLink : public EcXmlCompoundType
{
public:
   /// Copy of enumerations from foundCommon for backwards compatibility.
   enum
   {
      BASEINDEX = EcFoundCommon::BASEINDEX,
      VOIDINDEX = EcFoundCommon::VOIDINDEX
   };

   /// default constructor
   EcManipulatorLink
      (
      );

   /// destructor
   virtual ~EcManipulatorLink
      (
      );

   /// copy constructor
   EcManipulatorLink
      (
      const EcManipulatorLink& orig
      );

   /// assignment operator
   EcManipulatorLink& operator=
      (
      const EcManipulatorLink& orig
      );

   /// assignment operator, except the child links
   EcManipulatorLink& copyAllButChildLinksFrom
      (
      const EcManipulatorLink& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorLink& orig
      ) const;

   /// equality operator for referencing
   EcBoolean equalForReferencing
      (
      const EcManipulatorLink& orig
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

   /// re-register the system if needed
   virtual void reregisterSystem
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

   /// gets an identifying label
   virtual const EcString& label
      (
      ) const;

   /// sets an identifying label
   virtual void setLabel
      (
      const EcString& label
      );

   /// appends a string to all labels of all links including child links.
   /**
   \param[in] appendage A string to append.
   */
   virtual void appendToAllLabels
      (
      const EcString& appendage
      );

   /// set shape surface properties by the shape ID.
   virtual EcBoolean setSurfacesByShapeID
      (
      const EcU32& shapeID,
      const EcStringDataMapMap& surfaces
      );

   /// set shape surface properties if the name matched,
   /// visit the child link recursively.
   virtual EcBoolean setSurfaces
      (
      const EcString& linkName,
      const EcU32& shapeID,
      const EcStringDataMapMap& surfaces
      );

   /// set shape surface property string if the name matched,
   virtual EcBoolean setShapeSurfaceProperty
      (
      const EcString& linkName,
      const EcU32& shapeID,
      const EcString& surfaceProperty
      );

   /// set shape identifier string if the name matched,
   virtual EcBoolean setShapeIdentifier
      (
      const EcString& linkName,
      const EcU32& shapeID,
      const EcString& identifier
      );

   /// gets Denavit-Hartenberg parameters
   virtual const EcLinkKinematicsContainer& linkKinematicsContainer
      (
      ) const;

   /// sets Denavit-Hartenberg parameters
   virtual void setLinkKinematicsContainer
      (
      const EcLinkKinematicsContainer& linkKinematicsContainer
      );

   /// sets the top element of the link kinematics container
   virtual void setLinkKinematics
      (
      const EcLinkKinematics& linkKinematics
      );

   /// gets the child links
   virtual const EcXmlVectorType<EcManipulatorLink>& childLinks
      (
      ) const;

   /// sets the child links
   virtual void setChildLinks
      (
      const EcXmlVectorType<EcManipulatorLink>& childLinks
      );

   /// Adds a child link by copy at the end of the child links vector
   /**
   \param childLink The child link to be added.
   */
   virtual void addChild
      (
      const EcManipulatorLink& childLink
      );

   /// clear the child links vector
   virtual void clearChildLinks
      (
      );

   /// Adds a link by copy to the end of the first chain rooted at this link
   /**
   \param link The link to be added.
   */
   virtual void addLinkToEndOfChain
      (
      const EcManipulatorLink& link
      );

   /// gets the physical extent
   virtual const EcBasePhysicalExtent& physicalExtent
      (
      ) const;

   /// get the shape container (this may or may not be referenced)
   virtual  const EcShapeContainer & shapeContainer
      (
      ) const;

   /// get the member-variable shape container
   virtual  const EcShapeContainer & memberShapeContainer
      (
      ) const;

   /// set the shape container
   virtual void setShapeContainer
      (
      const EcShapeContainer& shapeContainer
      );

   /// sets the shape
   virtual void setShape
      (
      const EcShape& shape
      );

   /// set all properties from a shape
   virtual void setFromShape
      (
      const EcShape& shape
      );

   /// set all properties from a shape container
   virtual void setFromShapeContainer
      (
      const EcShapeContainer& shapeContainer
      );

   /// gets the primary frame in local coordinates
   virtual const EcCoordinateSystemTransformation& primaryFrame
      (
      ) const;

   /// sets the primary frame
   /**
   \param[in] primaryFrame The primary frame in local coordinates
   */
   virtual void setPrimaryFrame
      (
      const EcCoordinateSystemTransformation& primaryFrame
      );

   /// gets the joint actuator
   virtual const EcJointActuator& jointActuator
      (
      ) const;

   /// sets the joint actuator
   virtual void setJointActuator
      (
      const EcJointActuator& jointActuator
      );

   /// truncate values in the physical extents to the precision specified.
   virtual void truncateValues
      (
      const EcReal& precision = 1e-10
      );

   /// gets mass properties expressed in primary frame. This is the base mass properties combined with the mass properties in the map, which is the total mass properties of this link.
   /**
   \param[in] statedSystemStruct A pointer to the stated system struct. If not null, the returned mass properties will be the combined
         mass properties of this link plus a link, if any, that's attached to this link.
   */
   virtual const EcRigidBodyMassProperties& massProperties
      (
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// sets the total mass properties expressed in primary frame. This will set the base mass properties to massProperties
   /// and clear the mass properties map
   virtual void setMassProperties
      (
      const EcRigidBodyMassProperties& massProperties
      );

   /// gets the base mass properties expressed in primary frame
   virtual const EcRigidBodyMassProperties& baseMassProperties
      (
      ) const;

   /// sets the base mass properties expressed in primary frame
   virtual void setBaseMassProperties
      (
      const EcRigidBodyMassProperties& massProperties
      );

   /// gets the map of mass properties. The map contains mass properties in addition to the base mass properties.
   virtual const EcRigidBodyMassPropertiesMap& massPropertiesMap
      (
      ) const;

   /// sets the map of mass properties
   virtual void setMassPropertiesMap
      (
      const EcRigidBodyMassPropertiesMap& massPropMap
      );

   /// clear all the mass properties in the map
   virtual void clearMassPropertiesMap
      (
      );

   /// add mass properties expressed in primary frame and identified by identifier. This will change the total mass properties of the link.
   virtual void addMassProperties
      (
      const EcString& identifier,
      const EcRigidBodyMassProperties& massProperties
      );

   /// delete the mass properties identified by identifier. Returns true if deletion is successful and
   /// this will change the total mass properties of the link. Or returns false if identifier doesn't exist.
   virtual EcBoolean deleteMassProperties
      (
      const EcString& identifier
      );

   /// get functions for String properties
   virtual const EcSpringProperties& springProperties
      (
      ) const;

   /// set functions for String properties
   virtual void setSpringProperties
      (
      const EcSpringProperties& springProperties
      );

   /// get functions for damper properties
   virtual const EcDamperProperties& damperProperties
      (
      ) const;

   /// set functions for damper properties
   virtual void setDamperProperties
      (
      const EcDamperProperties& damperProperties
      );

   /// get the link reference description
   virtual const EcLinkReferenceDescription& linkReferenceDescription
      (
      ) const;

   /// set the link reference description
   virtual void setLinkReferenceDescription
      (
      const EcLinkReferenceDescription& linkReferenceDescription
      );

   /// calculate total joint torque from spring + damper
   /*
   \param[in,out] activeState The active state of the manipulator containing this actuator. Provides access to position, velocity, and actuator states of all joints in the manipulator.
   */
   virtual EcReal totalLocalTorque
      (
      EcManipulatorActiveState& activeState
      ) const;

   /// gets the mass properties expressed in the D-H frame
   /**
   \param[in] statedSystemStruct A pointer to the stated system struct. If not null, the returned mass properties will be the combined
         mass properties of this link plus a link, if any, that's attached to this link.
   */
   virtual const EcRigidBodyMassProperties& massPropertiesInDHFrame
      (
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// recalculate the mass properties expressed in the D-H frame
   virtual void updateDHMassProperties
      (
      );

   /// transform components (mass properties and shape).
   /// this has the same effect as setting the primary frame from identity to this value
   virtual void transformComponentsBy
      (
      const EcCoordinateSystemTransformation xform
      );

   /// gets parentLink
   virtual const EcManipulatorLink* parentLink
      (
      ) const;

   /// sets parentLink
   virtual void setParentLink
      (
      EcManipulatorLink* parentLink
      );

   /// gets the link index
   virtual EcU32 linkIndex
      (
      ) const;

   /// subtree Link count (count includes this link)
   /**
   \return The total number of links that belong to this link tree including this link.
   */
   virtual EcU32 subtreeLinkCount
      (
      ) const;


   /// get the collision avoidance metric for this link
   virtual EcReal lookupCollisionAvoidanceMetric
      (
      ) const;

   /// map this and all child links
   virtual EcBoolean mapLinks
      (
      EcManipulatorLinkConstPointerVector& linkVector,
      EcManipulatorLinkPointerMap& linkMap
      );

   /// get the link's D-H frame represented in the system frame
   /**
   \param[in,out] actPosState
   */
   virtual const EcCoordinateSystemTransformation& dhFrameInSystem
      (
      EcManipulatorActivePositionState& actPosState
      ) const;

   /// get the link's primary frame represented in the system frame
   virtual const EcCoordinateSystemTransformation& primaryFrameInSystem
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

   /// compute and return the general force that must be applied to the link to achieve
   /// the motion specified in the active state.
   /**
    * @param manipExtForce The external force
    * @param actState The manipulator active state
    * @param statedSystemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return the general force that must be applied to the link to achieve the motion
    */
   virtual const EcGeneralForce& dhFrameForceInLocal
      (
      const EcManipulatorExternalForce& manipExtForce,
      EcManipulatorActiveState& actState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// compute and return the composite rigid-body inertia of this and all outboard links
   /// represented in the link's D-H frame.
   /**
    * @param actState The manipulator active state
    * @param statedSystemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return the composite rigid-body inertia of this and all outboard links represented in the link's D-H frame
    */
   virtual const EcRigidBodyMassProperties& crbi
      (
      EcManipulatorActiveState& actState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// compute and return the articulated-body dynamics (articulated-body inertia and bias force)
   /// for this link represented in the link's D-H frame.
   /**
    * @param manipExtForce The external force
    * @param manipTorque The manipulator torque
    * @param actState The manipulator active state
    * @param statedSystemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return the articulated-body dynamics for this link represented in the link's D-H frame
    */
   virtual const EcArticulatedBodyDynamics& arbd
      (
      const EcManipulatorExternalForce& manipExtForce,
      const EcManipulatorTorque& manipTorque,
      EcManipulatorActiveState& actState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// add the arbd for this link to the parent's value.
   /**
    * @param parentArbd The articulated-body dynamics of the parent's link
    * @param manipExtForce The external force
    * @param manipTorque The manipulator torque
    * @param actState The manipulator active state
    * @param statedSystemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    */
   virtual void addArbdToParent
      (
      EcArticulatedBodyDynamics& parentArbd,
      const EcManipulatorExternalForce& manipExtForce,
      const EcManipulatorTorque& manipTorque,
      EcManipulatorActiveState& actState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// get the supplemental D-H frame acceleration represented in the local frame.
   /// this supplemental acceleration is the acceleration produced only by the
   /// base acceleration (if it exists) and joint accelerations.
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

   /// compute and return the joint acceleration for this link calculated using the arbi algorithm
   /**
    * @param manipExtForce The external force
    * @param manipTorque The manipulator torque
    * @param actState The manipulator active state
    * @param statedSystemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return the joint acceleration for this link
    */
   virtual EcReal arbiJointAcceleration
      (
      const EcManipulatorExternalForce& manipExtForce,
      const EcManipulatorTorque& manipTorque,
      EcManipulatorActiveState& actState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// Collect leaf links into a list of link pointers.
   /**
   \param[out] linkPointerVector The list of link pointers containing all leaf links.
   */
   virtual void collectLeafLinks
      (
      EcManipulatorLinkConstPointerVector& linkPointerVector
      ) const;

   /// reorganize this link for optimial rendering (only needs to be done once)
   virtual void optimizeForRendering
      (
      );

   /// lookup the surface property given a key, this checks the local shape
   /// associated with this link, then the manipulators mapping
   /**
   \param[in] key A string used to look up a surface property.
   \param[out] property The surface property associated with the key. Set to 0 if the key is not found.
   \return True if the key is found or false otherwise.
   */
   virtual EcBoolean lookup
      (
      const EcString& key,
      const EcDataMap*& property
      ) const;

   /// reorganize this and all child links for optimal rendering
   virtual void recursiveOptimizeForRendering
      (
      );

   /// get the shape query data
   virtual const EcShapeQueryData& queryData
      (
      )const;

   /// Returns the pointer to the manipulator that contains this link
   virtual const EcIndividualManipulator* manipulator
      (
      ) const;

   /// Sets the pointer to the individual manipulator that contains this link
   virtual void setManipulatorPointer
      (
      const EcIndividualManipulator* pManip
      ) const;

   /// returns the upper bound extent distance.  This is the distance from
   /// the DH frame to the polygon furthest away from the frame for this link
   virtual EcReal upperBoundExtentDistance
      (
      )const;

   /// returns the upper bound extent distance for the links that make
   /// up the sub-manipulator beneath this link
   virtual EcReal upperBoundSubmanipulatorExtentDistance
      (
      )const;

   /// compute and return the vector of bounding boxes describing the
   /// shape (or shapes) the represent this link.  This will always return
   /// one AABB unless the shape that defines the link is a union node, in
   /// which case it will return one AABB for each leaf node in the tree of
   /// unions.
   virtual void axisAlignedBoundingBoxVectorInSystem
      (
      EcManipulatorActivePositionState& state,
      EcAxisAlignedBoundingBoxVector& aabbVec,
      EcU32Vector& shapeIDVec
      )const;

   /// relabel a subtree based on the root label passed in
   virtual void relabelSubtree
      (
      const EcString& label,
      EcU32& index
      );

   /// delete all the bounding volumes in the bvh hierarchy
   virtual void deleteBoundingVolumes
      (
      ) ;

   /// returns the number of shapes associates with this link
   virtual EcInt32 numberOfShapes
      (
      )const;

   /// get the shape by the index passed in
   virtual const EcShape* shapeByIndex
      (
      const EcU32& index
      )const;

   /// get a shape by string identifier
   virtual const EcShape* shapeByIdentifier
      (
      const EcString& name
      )const;

   /// set the index for each shape associated with this link
   virtual EcBoolean mapShapes
      (
      );

   /// set the total number of shapes used to represent this link
   virtual void setNumShapes
      (
      const EcU32& nShapes
      );

   /// get the total number of shapes used to represent this link
   virtual const EcU32& numShapes
      (
      )const;

   /// gets the number of shapes used for the physical
   /// representation of the link.  This is one unless
   /// union nodes are used.
   virtual EcU32 numShapesInPhysicalRepresentation
      (
      )const;

   /// scale just this link by the specified value
   /// (scaleFactor=1.0 does not change the link)
   virtual void scaleIndividualLinkBy
      (
      EcReal scaleFactor
      );

   /// scale the link and all children by the specified value
   /// (scaleFactor=1.0 does not change the link)
   virtual void scaleBy
      (
      EcReal scaleFactor
      );

   /// transform this with respect to its parent by a general
   /// coordinate system transformation.  This transformation
   /// is inserted before the link placement.  If the kinematics
   /// class has a precursor P, the P=XForm*P;
   virtual EcBoolean transformLinkTreeBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// transform this link so that the primary frame transformation
   /// is that given, but the link does not change (i.e., if xform
   /// is identity, then the primary frame will coincide with the DH
   /// frame, but the link won't change).  After calling the primary
   /// frame equals xform.
   virtual EcBoolean transformPrimaryFrame
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// intersect a line segment with this link, returning the closest
   /// point along the line segment using the initial closest point
   /// provided in pointEvent.
   virtual void intersectLineSegment
      (
      const EcLineSegment& lineSegment,
      EcLinkPointEvent& pointEvent,
      EcManipulatorActiveState* pActState,
      EcU32 levelOfDetail=0
      ) const;

   /// assign the references for this links in this and the subtree
   /// from the map (as needed)
   virtual EcBoolean setLinkReferences
      (
      const EcManipulatorLinkPointerMap& linkMap
      );

   /// change this link and the subtree to use references where possible
   virtual EcBoolean useReferencesWherePossible
      (
      const EcManipulatorLinkConstPointerVector& linkVector
      );

   /// remove references to this link
   virtual EcBoolean removeLinkReferences
      (
      );

   /// try to guess the mass properties of this link using
   /// a bounding capsule and nominal density
   virtual void estimateMassProperties
      (
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

   /// get a null link
   static EcManipulatorLink nullObject
      (
      );

   /// get the nth none-bounding shape of this link.
   virtual const EcShape* getNthNonBoundingShape
      (
      const EcU32 n
      )const;

   /// get all bounding volumes
   virtual void boundingVolumes
      (
      EcShapeConstPointerVector& boundingShapes,
      const EcU32& bvhLevel = 1
      )const;

   /// delete all bounding volumes from the
   virtual void deleteAllBoundingVolumes
      (
      );

   /// set the new value for a joint limit
   /**
   \param[in] linkLabel The identifying label of the link (joint)
   \param[in] isLowerLimit True for a lower limit or false for upper limit
   \param[in] value The new value for the joint limit
   */
   virtual EcBoolean setJointLimit
      (
      const EcString& linkLabel,
      EcBoolean isLowerLimit,
      EcReal value
      );

   /// add a bounding volume to the shape in the shape container
   void addBoundingVolume
      (
      const EcShape::EcShapeValues& bv
      );

   /// copy the properties (link kinematics, mass properties, joint actuator, shape container, etc.) of this link to another link. This does not copy the child links. This should be used along with replaceLinkProperties method to efficiently modify some link properties of some link in the manipulator chain.
   /**
   \param[in] toLink The other link to which this link properties will be copied.
   */
   void copyLinkProperties
      (
      EcManipulatorLink& toLink
      ) const;

   /// replace the link properties (link kinematics, mass properties, joint actuator, shape container, etc.) of the link identified by linkLabel with the properties of newLink. This does not affect the child links of the link identified by linkLabel.
   /**
   \param[in] linkLabel The string identifier of the link whose properties are to be changed.
   \param[in] newLink A link whose properties will be used.
   \param[in] includeShapeContainer If true, the shape container of the link identified by linkLabel will be replaced by the shape container of newLink. Shape container is a special case because of it may be referenced, in which case it needs to be unreferenced. The default is false, i.e. the shape container will not be replaced.
   \return True if successful or false if linkLabel is invalid.
   */
   virtual EcBoolean replaceLinkProperties
      (
      const EcString& linkLabel,
      const EcManipulatorLink& newLink,
      EcBoolean includeShapeContainer=EcFalse
      );

   /// replace the mass properties of the link identified by linkLabel. This does not affect the child links of the link identified by linkLabel.
   /**
   \param[in] linkLabel The string identifier of the link whose properties are to be changed.
   \param[in] newLink   The mass properties that will be used.
   \return True if successful or false if linkLabel is invalid.
   */
   virtual EcBoolean replaceMassProperties
      (
      const EcString& linkLabel,
      const EcRigidBodyMassProperties& newLink
      );

   /// replace the joint actuator of the link identified by linkLabel. This does not affect the child links of the link identified by linkLabel.
   /**
   \param[in] linkLabel The string identifier of the link whose properties are to be changed.
   \param[in] jointActuator  The joint actuator that will be used.
   \return True if successful or false if linkLabel is invalid.
   */
   EcBoolean replaceJointActuator
      (
      const EcString& linkLabel,
      const EcJointActuator& jointActuator
      );

   /// set the properties of the surface identified by key for all the shapes in this link.
   /**
   \param[in] key A string to identify the surface material.
   \param[in] properties The surface properties to be set.
   \return True if key is found in at least one shape or false otherwise.
   */
   virtual EcBoolean setSurfaceProperties
      (
      const EcString& key,
      const EcDataMap& properties
      );

   /// get the link's force vector resulting from impact forces
   virtual const EcLineSegment& forceVectorInLocal
      (
      const EcManipulatorActiveState& activeState
      ) const;

   /// compute and return the link's center of mass velocity represented in the local frame
   /**
    * @param activeState The manipulator active state
    * @param statedSystemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return the link's center of mass velocity represented in the local frame
    */
   virtual const EcGeneralVelocity& comVelocityInLocal
      (
      EcManipulatorActiveState& activeState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// compute and return the link's center of mass acceleration represented in the local frame
   /**
    * @param activeState The manipulator active state
    * @param statedSystemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return the link's center of mass acceleration represented in the local frame
    */
   virtual const EcGeneralAcceleration& comAccelerationInLocal
      (
      EcManipulatorActiveState& activeState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// compute and return the spatial momentum at the center of mass of this link represented in the link's D-H frame.
   /**
    * @param activeState The manipulator active state
    * @param statedSystemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return the spatial momentum at the center of mass of this link represented in the link's D-H frame.
    */
   virtual const EcGeneralMotion& spatialMomentumInLocal
      (
      EcManipulatorActiveState& activeState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// compute and return the composite spatial momentum of this link and its outboard links represented in the link's D-H frame.
   /**
    * @param activeState The manipulator active state
    * @param statedSystemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return the composite spatial momentum of this link and its outboard links represented in the link's D-H frame.
    */
   virtual const EcGeneralMotion& compositeSpatialMomentumInLocal
      (
      EcManipulatorActiveState& activeState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// compute and return the rate of spatial momentum at the center of mass of this link represented in the link's D-H frame.
   /**
    * @param activeState The manipulator active state
    * @param statedSystemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return the rate of spatial momentum at the center of mass of this link represented in the link's D-H frame.
    */
   virtual const EcGeneralMotion& spatialMomentumRateInLocal
      (
      EcManipulatorActiveState& activeState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// compute and return the composite rate of spatial momentum of this link and its outboard links represented in the link's D-H frame.
   /**
    * @param activeState The manipulator active state
    * @param statedSystemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    * @return the composite rate of spatial momentum of this link and its outboard links represented in the link's D-H frame.
    */
   virtual const EcGeneralMotion& compositeSpatialMomentumRateInLocal
      (
      EcManipulatorActiveState& activeState,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// compute the moment around a point due to linear acceleration of this link and its outboard links
   virtual EcBoolean computeMomentFromLinearAcceleration
      (
      const EcVector& point,
      EcManipulatorActiveState& activeState,
      EcVector& moment,
      const EcStatedSystemStruct* statedSystemStruct=0
      ) const;

   /// returns the upper limit constraint for this link
   /**
   The constraint is in the general form of f(q)>=0, where q is the position state (base position plus joint positions). This allows, for example, the upper limit of this joint to be a function of the position of another joint. For example, if the upper limit of joint 1 is a linear function of joint 0 in the form of upperLim0 = 2*q1 + 1.5. Then, the constraint will be 2*q1+1.5-q0>=0. Thus, f(q) is -q0 + 2*q1 + 1.5, where q0 and q1 is the joint positions of joints 0 and 1, respectively.
   */
   virtual const EcBaseStateConstraint& upperLimitConstraint
      (
      ) const;

   /// sets the upper limit constraint for this link
   virtual void setUpperLimitConstraint
      (
      const EcBaseStateConstraint& value
      );

   /// returns the lower limit constraint for this link
   /**
   The constraint is in the general form of f(q)>=0, where q is the position state (base position plus joint positions). This allows, for example, the lower limit of this joint to be a function of the position of another joint. For example, if the lower limit of joint 1 is a linear function of joint 0 in the form of lowerLim0 = 2*q1 + 1.5. Then, the constraint will be q0-(2*q1+1.5)>=0. Thus, f(q) is q0 - 2*q1 - 1.5, where q0 and q1 is the joint positions of joints 0 and 1, respectively.
   */
   virtual const EcBaseStateConstraint& lowerLimitConstraint
      (
      ) const;

   /// sets the lower limit constraint for this link
   virtual void setLowerLimitConstraint
      (
      const EcBaseStateConstraint& value
      );

   /// returns the map of named points
   virtual const EcNamedPoints& namedPoints
      (
      ) const;

   /// sets the map of named points
   virtual void setNamedPoints
      (
      const EcNamedPoints& value
      );

   /// returns a point
   virtual EcBoolean lookupNamedPoint
      (
      const EcString& key,
      EcVector& point
      ) const;

   /// adds a point to the map
   virtual void addNamedPoint
      (
      const EcString& key,
      const EcVector& point
      );

   /// returns the map of named frames
   virtual const EcNamedFrames& namedFrames
      (
      ) const;

   /// sets the map of named frames
   virtual void setNamedFrames
      (
      const EcNamedFrames& value
      );

   /// returns a frame
   virtual EcBoolean lookupNamedFrame
      (
      const EcString& key,
      EcCoordinateSystemTransformation& frame
      ) const;

   /// adds a frame to the map
   virtual void addNamedFrame
      (
      const EcString& key,
      const EcCoordinateSystemTransformation& frame
      );

   /// returns whether this link is constrained
   virtual EcBoolean isConstrained
      (
      ) const;

   /// sets whether this link is constrained
   virtual void setIsConstrained
      (
      EcBoolean value
      );

protected:
   /// updates the default upper and lower limit constraints
   virtual void updateDefaultLimitConstraints
      (
      );

   /// recalculate the mass properties
   virtual void updateMassProperties
      (
      );

   /// return a pointer to the shape
   virtual EcShape* findShape
      (
      const EcString& linkName,
      const EcU32& shapeID
      );

protected:

   // XML data

   /// the identifying label
   EcXmlString                        m_Label;

   /// the general joint set for the link
   EcLinkKinematicsContainer          m_LinkKinematicsContainer;

   /// the vector of child links
   EcXmlVectorType<EcManipulatorLink> m_ChildLinks;

   /// the physical extent of the link
   boost::shared_ptr<EcShapeContainer> m_pShapeContainer;

   /// the actuator for the link
   EcJointActuator                    m_JointActuator;

   /// the actuator for the link -- deprecated
   EcOldJointActuator                 m_OldJointActuator;

   /// the actuator for the link -- deprecated
   EcJointActuatorContainer           m_JointActuatorContainer;

   /// the rigid-body mass properties of the link
   EcRigidBodyMassProperties          m_MassProperties;

   /// spring properties of this link
   EcSpringProperties                 m_SpringProperties;

   /// damper properties of this link
   EcDamperProperties                 m_DamperProperties;

   /// a reference information for this link
   EcLinkReferenceDescription         m_LinkReferenceDescription;

   /// container for the upper limit constraint
   EcStateConstraintContainer         m_UpperLimitConstraintContainer;

   /// container for the lower limit constraint
   EcStateConstraintContainer         m_LowerLimitConstraintContainer;

   /// Named points
   mutable EcNamedPoints                      m_NamedPoints;

   /// Named frames
   mutable EcNamedFrames                      m_NamedFrames;

   /// Constrained tag
   EcXmlBoolean                       m_IsConstrained;

   /// The map containing mass properties in addition to the base mass properties.
   /// The total mass properties of the link is obtained by combining the base with
   /// all mass properties in the map.
   EcRigidBodyMassPropertiesMap        m_MassPropertiesMap;

   // non-XML data

   /// a pointer to the parent link in the tree
   EcManipulatorLink*                 m_pParentLink;

   /// the depth-first link index
   EcU32                              m_LinkIndex;

   /// the rigid-body mass properties of the link expressed in the D-H frame
   EcRigidBodyMassProperties          m_MassPropertiesInDHFrame;

   /// number of shapes used to represent this link
   EcU32 m_NumberOfShapes;

   /// map of shape pointers for this link
   EcShapeConstPointerMap             m_ShapePointerMap;

   /// linear vector of shape pointers for this link
   EcShapePointerVector               m_ShapePointerVec;

   /// the default upper limit constraint
   EcMultivariableJointStateConstraint              m_DefaultUpperLimitConstraint;

   /// the default lower limit constraint
   EcMultivariableJointStateConstraint              m_DefaultLowerLimitConstraint;

   /// the total mass properties of the link (combining the base one with all the ones in the map)
   EcRigidBodyMassProperties           m_TotalMassProperties;

   /// a pointer to the individual manipulator that contains this link
   mutable const EcIndividualManipulator*     m_pManipulator;

   /// a pointer to a reference link
   mutable const EcManipulatorLink*    m_pReferenceLink;

   /// a dummy transformation
   static const EcCoordinateSystemTransformation m_theDummyTransformation;

   /// a dummy general velocity
   static const EcGeneralVelocity m_theDummyGeneralVelocity;

   /// a dummy general acceleration
   static const EcGeneralAcceleration m_theDummyGeneralAcceleration;

   /// a dummy general force
   static const EcGeneralForce m_theDummyGeneralForce;

   /// a dummy composite rigid-body inertia
   static const EcRigidBodyMassProperties m_theDummyCrbi;

   /// a dummy articulated rigid-body dynamics
   static const EcArticulatedBodyDynamics m_theDummyArbd;

   /// a dummy physical extent
   static const EcPolyPhysicalExtent  m_theDummyPhysicalExtent;

   /// a dummy spatial momentum
   static const EcGeneralMotion        m_theDummySpatialMomentum;

   /// a dummy spatial momentum rate
   static const EcGeneralMotion        m_theDummySpatialMomentumRate;

   /// the defauult collision avoidance metric
   static const EcReal m_theDefaultCollisionAvoidanceMetric;

   /// a utility transformation
   mutable EcCoordinateSystemTransformation m_Xform;

   /// a utility transformation for local work
   mutable EcCoordinateSystemTransformation m_XformLocal;

   /// a utility general velocity
   mutable EcGeneralVelocity m_GenVelocity;

   /// a utility general acceleration
   mutable EcGeneralAcceleration m_GenAcceleration;

   /// a utility spatial momentum
   mutable EcGeneralMotion m_SpatialMomentum;

   /// a utility spatial momentum rate
   mutable EcGeneralMotion m_SpatialMomentumRate;

   /// a utility general velocity for self motion of the link
   mutable EcGeneralMotion m_SelfGenMotion;

   /// the shape query descriptor
   mutable EcShapeQueryData m_QueryData;

   /// an array of flags indicating if a shape is swapped for cacheing
   mutable EcBooleanVector  m_ShapeSwappedVec;

   /// temporary point
   mutable EcXmlVector m_XmlPoint;

   /// the combined mass properties (combined with mass properties of link attached to this, if any)
   mutable EcRigidBodyMassProperties   m_CombinedMassProperties;

   /// offset transformations
   mutable EcCoordinateSystemTransformationVector m_Offsets;

   /// dependent manipulators
   mutable EcU32Vector m_DependentManipulators;
};

/// an XML vector of links
typedef EcXmlVectorType<EcManipulatorLink> EcManipulatorLinkVector;

/// a vector of link pointers
typedef std::vector<EcManipulatorLink*> EcManipulatorLinkPointerVector;

#endif // ecManipulatorLink_H_
