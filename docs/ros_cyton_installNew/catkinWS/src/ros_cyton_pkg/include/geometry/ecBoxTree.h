#ifndef ecBoxTree_H_
#define ecBoxTree_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecBoxTree.h
/// @class EcBoxTreeNode
/// @brief A bounding box tree.  This is a tree of axis aligned bounding
///        boxes for fast detection of static bodies in the environment.
///        The tree is built once on load.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecAxisAlignedBoundingBox.h"
#include <xml/ecXmlCompType.h>

class EcBBTreeHeuristic;

/** Holds a class to describe an axis aligned bounding box (AABB) tree
*/
class EC_FOUNDATION_GEOMETRY_DECL EcBoxTreeNode : public EcXmlCompoundType
{
public:
   /// default constructor
   EcBoxTreeNode
      (
      );

   /// constructor with values
   EcBoxTreeNode
      (
      const EcAxisAlignedBoundingBoxVector& bbVec,
      const std::vector<std::pair<EcU32,EcU32> > manipShapeIDPairVector,
      EcU32 depth,  //maximum tree depth
      const EcBBTreeHeuristic& heuristicData
      );

   /// destructor
   virtual ~EcBoxTreeNode
      (
      );

   /// copy constructor
   EcBoxTreeNode
      (
      const EcBoxTreeNode& orig
      );

   /// assignment operator
   EcBoxTreeNode& operator=
      (
      const EcBoxTreeNode& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBoxTreeNode& orig
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

   /// get an empty polygon
   static EcBoxTreeNode nullObject
      (
      );

   /// the creator function for this object
   static EcXmlObject* creator
      (
      ) ;

   /// returns a class token
   static const EcToken& classToken
      (
      );

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;


   /// virtual method returning the token for this object
   virtual const EcToken& token
      (
      )const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// renders tris that collide with the sphere
   virtual const std::vector<std::pair<EcU32,EcU32> >& checkForCollisions
      (
      const EcAxisAlignedBoundingBox& aabb
      ) const;

   /// Check if the AABB for this node intersects the AABB passed in.
   virtual EcBoolean checkIntersect
      (
      const EcAxisAlignedBoundingBox& aabb
      ) const;

protected:
   /// this nodes bounding box
   EcAxisAlignedBoundingBox m_AABB;

   /// child nodes of this node
   EcBoxTreeNode* m_vChildren[2];

   /// a vector containing a list of all the manip/ShapeID pairs that are contained
   /// in this AABB
   std::vector<std::pair<EcU32,EcU32> >      m_ManipShapeIDPairs;

   /// const values
   static const std::vector<std::pair<EcU32,EcU32> > m_theEmptyVector;
};

#endif // ecBoxTree_H_
