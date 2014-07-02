#ifndef ecShapeQueryDescriptor_H_
#define ecShapeQueryDescriptor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeQueryDescriptor.h
/// @class EcShapeQueryDescriptor
/// @brief Holds a descriptor class to describe a shape query
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <foundCommon/ecCoordSysXForm.h>
#include "ecLinkStateCacheKey.h"

// forward declarations
class EcShape;
class EcStatedSystem;


/** Holds a class to describe a shape query descriptor
*/
class EC_FOUNDATION_GEOMETRY_DECL EcShapeQueryDescriptor : public EcXmlCompoundType
{
public:
   /// type of distance algorithms
   typedef enum
   {
      GJK_DISTANCE,       /// Use GJK exclusively
      INTRINSIC_DISTANCE, /// Use Intrinsic computations except for
                          /// intersection depth
      OPTIMAL_DISTANCE    /// Switch between the two to optimize runtime
   } EcDistAlgorithmType;

   /// default constructor
   EcShapeQueryDescriptor
      (
      );

   /// destructor
   virtual ~EcShapeQueryDescriptor
      (
      );

   /// copy constructor
   EcShapeQueryDescriptor
      (
      const EcShapeQueryDescriptor& orig
      );

   /// assignment operator
   EcShapeQueryDescriptor& operator=
      (
      const EcShapeQueryDescriptor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShapeQueryDescriptor& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
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

   /// set the compute distance flag
   virtual void setProcessingMode
      (
      EcU32 mode
      );

   /// set the compute distance flag
   virtual void setComputeDistance
      (
      EcBoolean val
      );

   /// set the compute distance flag
   virtual void setComputeIntersectVolume
      (
      EcBoolean val
      );

   /// set the minimum distance
   virtual void setMinimumDistance
      (
      EcReal minDist
      );

   /// get the minimum distance
   virtual EcReal minimumDistance
      (
      ) const;

   /// set the distance query precision
   virtual void setDistanceQueryPrecision
      (
      EcU32 prec
      );

   /// get the distance query precision
   virtual const EcU32& distanceQueryPrecision
      (
      ) const;

   /// return the compute distance flag
   virtual EcBoolean computeDistance
      (
      )const;

   /// return the compute distance flag
   virtual EcBoolean computeIntersectVolume
      (
      ) const;

   /// return the processing mode
   virtual EcU32 processingMode
      (
      ) const;

   /// get the coordinate system transform. This is the transformation
   /// to put the shape being queried into the reference frame
   /// of this shape
   virtual const EcCoordinateSystemTransformation& xform
      (
      ) const ;

   /// get the coordinate system transform. This is the transformation
   /// to put the shape being queried into the reference frame
   /// of this shape
   virtual void setXform
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone
   virtual EcXmlObject* clone
      (
      ) const;

   /// set the shape pointer of the shape being queried
   virtual void setShape1Pointer
      (
         const EcShape* pShape
      );

   /// set the shape pointer of the shape being queried
   virtual void setShape2Pointer
      (
      const EcShape* pShape
      );

   /// get the shape 1 pointer of the shape being queried
   virtual const EcShape*&  shape1Pointer
      (
      const EcShape* pShape
      );

   /// get the shape 2 pointer of the shape being queried
   virtual const EcShape*& shape2Pointer
      (
      );

   /// return the shape pointer
   virtual const EcShape* shape1
      (
      ) const;

   /// return the shape pointer
   virtual const EcShape* shape2
      (
      ) const;

   /// the link key for shape 1
   virtual const EcLinkStateCacheKey& shape1LinkKey
      (
      )const;

   /// set the link key for shape 1
   virtual void setShape1LinkKey
      (
      const EcLinkStateCacheKey& key1
      );

   /// the link key for shape 2
   virtual const EcLinkStateCacheKey& shape2LinkKey
      (
      )const;

   /// set the link key for shape 2
   virtual void setShape2LinkKey
      (
      const EcLinkStateCacheKey& key2
      );

   virtual const EcToken& token
      (
      ) const;

protected:
   /// the minimum distance of separation between the two
   /// shapes being queried before attempting to transition to a higher
   /// fidelity model
   EcXmlReal m_MinimumDistanceThreshold;

   /// flag indicating wether to compute the distance
   /// between shapes
   EcXmlBoolean m_ComputeDistance;

   /// flag indicating wether or not to compute the intersection
   /// volume
   EcXmlBoolean m_ComputeIntersectionVolume;

   /// flag indicating wether to:
   /// 1. Use GJK exclusively
   /// 2. Use shape intrinsic distance calculations and
   ///    use GJK for intersection depth
   /// 3. Switch between GJK and intrinsic calculations to
   ///    optimize performance
   EcXmlU32 m_ProcessingMode;

   ///  the query precision level (this is the BVH level to use)
   EcU32 m_QueryPrecision;

   /// transformation that converts the from of the other shape
   /// into the frame of this shape
   EcCoordinateSystemTransformation m_ShapeTransformation;

   /// shape 1 link key
   EcLinkStateCacheKey m_Shape1LinkKey;

   /// shape 2 link key
   EcLinkStateCacheKey m_Shape2LinkKey;

   /// non-xml data
   /// pointer to the shape to interrogate
   const EcShape * m_pShape1;

   /// non-xml data
   /// pointer to the shape to interrogate
   const EcShape * m_pShape2;
};

#endif // ecShapeQueryDescriptor_H_
