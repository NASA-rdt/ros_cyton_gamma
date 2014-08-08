#ifndef ecSystemActiveBoundingBoxState_H_
#define ecSystemActiveBoundingBoxState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemActiveBoundingBoxState.h
/// @class EcSystemActiveBoundingBoxState
/// @brief Class for holding the system wide active bounding box
///        state.  This maintains a sorted list of bounding boxes
///        for each link and base in the system that can be used
///        for fast intersection testing.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <geometry/ecIntervalIntersectionProcessor.h>
#include <shapeProximity/ecAxisAlignedBoundingBoxTool.h>
#include <xml/ecXmlCompType.h>

// forward declarations
class EcIndividualManipulator;
class EcManipulatorActiveState;
class EcManipulatorActivePositionState;
class EcManipulatorLink;
class EcManipulatorSystem;
class EcShapeStateCacheKey;

/// type definition of XML vector of EcManipulatorActiveState
typedef EcXmlVectorType<EcManipulatorActiveState>   EcManipulatorActiveStateVector;

/// type definition of XML vector of EcManipulatorActivePositionState
typedef EcXmlVectorType<EcManipulatorActivePositionState>   EcManipulatorActivePositionStateVector;

/** Holds the active bounding box state of the system.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcSystemActiveBoundingBoxState : public EcXmlCompoundType
{
public:
   /// manip-link pair, uniquely defines a link in the system
   typedef std::pair<EcU32,EcU32> EcManipLinkPair;

   /// defines a collision between two links in the system
   typedef std::pair<EcManipLinkPair,EcManipLinkPair> EcCollisionPair;

   /// default constructor
   EcSystemActiveBoundingBoxState
      (
      );

   /// destructor
   virtual ~EcSystemActiveBoundingBoxState
      (
      );

   /// copy constructor
   EcSystemActiveBoundingBoxState
      (
      const EcSystemActiveBoundingBoxState& orig
      );

   /// assignment operator
   EcSystemActiveBoundingBoxState& operator=
      (
      const EcSystemActiveBoundingBoxState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemActiveBoundingBoxState& orig
      ) const;


   /// convert an interval ID to a shape-key ID.  A shape-key ID is of the form
   /// (manipID,linkID,shapeID) and an interval ID is an unwrapped value
   /// based on links and manipulators.  The shapeID is currently not used
   /// since the AABBs contain links, not shapes.
   virtual void intervalIDtoShapeKeyID
      (
      const EcU32& intervalID,
      const EcManipulatorSystem& system,
      EcShapeStateCacheKey& shapeID
      )const;

   /// convert a shape-key ID to an interval ID.  A shape-key ID is of the form
   /// (manipID,linkID,shapeID) and an interval ID is an unwrapped value
   /// based on links and manipulators.  The shapeID is currently not used
   /// since the AABBs contain links, not shapes.
   virtual void shapeKeyIDToIntervalID
      (
      const EcShapeStateCacheKey& shapeID,
      const EcManipulatorSystem& system,
      EcU32& intervalID
      )const;

   /// build the database of Axis Aligned Bounding Boxes (AABBs) for
   /// the entire stated system.  This build the AABBs at the link level,
   /// i.e. one AABB for each link and performs an initial sort-and-sweep
   /// step.
   virtual void buildAABBDatabase
      (
      const EcManipulatorSystem& system,
      EcManipulatorActiveStateVector& actState
      );

   /// returns flag indicating that the database has been initialized
   virtual EcBoolean isInitialized
      (
      )const;

   /// get the list of intersections
   const std::vector<EcCollisionPair>&  intersectionList
      (
      const EcManipulatorSystem& system,
      EcManipulatorActiveStateVector& actStateVec
      );

   /// set the initialization flag
   virtual void setIsInitialized
      (
      EcBoolean isInit
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

   /// invalidates all of the state
   virtual void invalidateAll
      (
      );

   /// update the AABB for this link
   virtual void updateLinkPosition
      (
      const EcManipulatorLink& link,
      const EcIndividualManipulator& manip,
      EcManipulatorActivePositionState& actState
      );

   /// update the positions of all the AABBs in the system
   virtual void updateBoxPositions
      (
      const EcManipulatorSystem& system,
      EcManipulatorActiveStateVector& posStateVec
      );

   /// sort the database of AABBs
   /// this set is performed once per time step at most
   virtual void sortDatabase
      (
      );

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

   /// set the tolerance value
   virtual void setTolerance
      (
      const EcReal& value
      );

   /// get the tolerance
   virtual const EcReal& tolerance
      (
      )const;

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
   static EcSystemActiveBoundingBoxState nullObject
      (
      );


protected:

   /// type definition of EcU32U32Pair as EcStartIndexNumLinksPair
   typedef EcU32U32Pair EcStartIndexNumLinksPair;

   /// holds the database of bounding boxes
   /// the data in the AABB vectors (internal to the class) is ordered as follows:
   /// [(manip0,link0),(manip0,link1),...(manip0,base),(manip1,link0)..(manipN,base)]
   EcIntervalIntersectionProcessor m_BoundingBoxDatabase;

   /// hold an array of pairs indexed by manipulator ID.  The pair
   /// contains (startingLinearIndexIntoAABBvector,numberOfLinks)
   /// for fast (manip,link)-->aabbIndex conversion
   std::vector<EcStartIndexNumLinksPair>        m_ManipToAABBIndexLUT;

   /// LUT for fast aabbIndex-->(manip,link) conversion
   std::vector<EcManipLinkPair>                 m_AABBIndexToManipLinkLUT;

   /// an array containing a list of intersecting AABBs.
   mutable std::vector<EcCollisionPair> m_IntersectingBoxes;

   /// a utility bounding box
   mutable EcAxisAlignedBoundingBox m_UtilityAABB;

   /// flag indicating if the database has been initialized yet
   EcBoolean m_IsInitialized;

   /// flag indicating if the database contains valid (up to date) data
   EcBoolean m_DataValid;

   /// the max distance between bounding boxes used to declare an intersection
   /// default is 0.
   EcReal m_Tolerance;

   /// pointer to the last active position state vector
   EcManipulatorActivePositionStateVector*   m_pLastActivePositionStateVector;

   /// tolerance used to test approximate equality
   EcReal m_TestTolerance;

   /// the axis-aligned bounding box tool
   mutable EcAxisAlignedBoundingBoxTool      m_AABBTool;
};

#endif // ecSystemActiveBoundingBoxState_H_
