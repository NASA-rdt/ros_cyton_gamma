#ifndef ecIntervalIntersectionProcessor_H_
#define ecIntervalIntersectionProcessor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecIntervalIntersectionProcessor.h
/// @class EcIntervalIntersectionProcessor
/// @brief Tests for interval overlap between links using AABBs.  This
///        is a fast test: O(n log n+m) where n is the number of intervals
///        and m is the number of collisions.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecAxisAlignedBoundingBox.h"
#include "ecIntervalEndPoint.h"
#include <xml/ecXmlVector.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

#include <fstream>
#include <iostream>
#include <set>
#include <vector>

class EcCapsule;

/** Holds a class to describe an interval processor, used for collision
    detection.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcIntervalIntersectionProcessor : public EcXmlCompoundType
{
public:
   /// A pair of EcU32
   typedef std::pair<EcU32,EcU32> EcBoxPair;

   /// default constructor
   EcIntervalIntersectionProcessor
      (
      );

   /// constructor with array of AABBs
   EcIntervalIntersectionProcessor
      (
      const EcAxisAlignedBoundingBoxVector& bbVec
      );

   /// destructor
   virtual ~EcIntervalIntersectionProcessor
      (
      );

   /// copy constructor
   EcIntervalIntersectionProcessor
      (
      const EcIntervalIntersectionProcessor& orig
      );

   /// assignment operator
   EcIntervalIntersectionProcessor& operator=
      (
      const EcIntervalIntersectionProcessor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcIntervalIntersectionProcessor& orig
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

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
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

   /// get an empty polygon
   static EcIntervalIntersectionProcessor nullObject
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

   /// virtual method returning the token for this object
   virtual const EcToken& token
      (
      )const;

   /// insert an AABB.  Resize to contain the shape passed in in system
   /// coordinates
   virtual void initialize
      (
      const EcAxisAlignedBoundingBoxVector& bbVec
      );

   /// update an AABB.  Resize to contain the shape passed in in system
   /// coordinates
   virtual void updateAABB
      (
      const EcAxisAlignedBoundingBox& box,
      const EcU32& index
      );

   /// get an AABB.  Resize to contain the shape passed in in system
   /// coordinates
   virtual const EcAxisAlignedBoundingBox& getAABB
      (
      const EcU32& index
      );

   /// update the sorted arrays of endpoints.  This is called when all
   /// the AABBs for this iteration have been moved
   virtual void update
      (
      );

   /// return the intersecting AABBs
   virtual const std::set<EcBoxPair>& intersections
      (
      )const;

   /// returns a vector of intersecting boxes
   virtual const std::vector<EcBoxPair>&
   intersectionsVec
      (
      )const;

   /// build the vector of intersecting boxes
   virtual void buildIntersectionVector
      (
      );

   /// delete box pair from results list
   virtual void deletePair
      (
      const EcBoxPair& boxpair
      );

   /// insert box pair from results list
   virtual void insertPair
      (
      const EcBoxPair& boxpair
      );

protected:

#undef  DEBUG_INTERVAL_PROC
#if defined(DEBUG_INTERVAL_PROC)
   virtual void dumpDebugData(const EcString& str)const;
   /// this is for debug
   mutable ofstream m_fout ;
#endif


   /// vector of axis aligned bounding boxes
   EcAxisAlignedBoundingBoxVector m_vAABBs;

   /// x-vector of endpoints
   std::vector<EcIntervalEndPoint> m_XEndPoint;

   /// y-vector of endpoints
   std::vector<EcIntervalEndPoint> m_YEndPoint;

   /// z-vector of endpoints
   std::vector<EcIntervalEndPoint> m_ZEndPoint;

   // The intervals are indexed 0 <= i < n.  The end point array has 2*n
   // entries.  The original 2*n interval values are ordered as b[0], e[0],
   // b[1], e[1], ..., b[n-1], e[n-1].  When the end point array is sorted,
   // the mapping between interval values and end points is lost.  In order
   // to modify interval values that are stored in the end point array, we
   // need to maintain the mapping.  This is done by the following lookup
   // table of 2*n entries.  The value m_Lookup[2*i] is the index of b[i]
   // in the end point array.  The value m_Lookup[2*i+1] is the index of
   // e[i] in the end point array.

   /// x-lookup array
   EcU32Vector m_XLookup;

   /// y-lookup array
   EcU32Vector m_YLookup;

   /// z-lookup array
   EcU32Vector m_ZLookup;

   /// collection of overlapping intervals
   std::set<EcBoxPair> m_Overlap;

   /// collection of overlapping intervals
   EcU32VectorVector m_OverlapArray;

   /// collection of overlapping intervals
   std::vector<EcBoxPair> m_OverlapVector;

   /// collection of overlapping intervals
   EcBooleanVectorVector m_OverlapFlagArray;

   /// static constants
   /// dummy bounding box for error recovery
   static const EcAxisAlignedBoundingBox m_theDummyBoundingBox;

protected:
   /// member functions

   /// insertion sort used for sorting partially sorted endpoints
   void insertionSort
      (
      std::vector<EcIntervalEndPoint>& endPoints,
      EcU32Vector& lookup
      );

   /// mutable endpoint values used internally
   mutable EcIntervalEndPoint m_E1;
   /// mutable endpoint values used internally
   mutable EcIntervalEndPoint m_E0;
   /// mutable endpoint values used internally
   mutable EcIntervalEndPoint m_Key;
};

#endif // ecIntervalIntersectionProcessor_H_
