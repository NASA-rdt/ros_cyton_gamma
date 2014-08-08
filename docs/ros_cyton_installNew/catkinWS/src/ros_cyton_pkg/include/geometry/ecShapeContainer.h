#ifndef ecShapeContainer_H_
#define ecShapeContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecShapeContainer.h
/// @class EcShapeContainer
/// @brief Holds a description on a shape container
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <matrixUtilities/ecReArray.h>
#include <xml/ecBaseExpTreeContainer.h>
#include "ecShape.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcShapePointEvent;
class EcStatedSystem;

/** Holds a container for all shapes
*/
class EC_FOUNDATION_GEOMETRY_DECL EcShapeContainer : public EcBaseExpressionTreeContainer<EcShape>
{
public:
   /// default constructor
   EcShapeContainer
      (
      );

   /// destructor
   virtual ~EcShapeContainer
      (
      );

   /// copy constructor
   EcShapeContainer
      (
      const EcShapeContainer& orig
      );

   /// assignment operator
   EcShapeContainer& operator=
      (
      const EcShapeContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcShapeContainer& orig
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// sets the container for the tree below to an alternate
   /// value.
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// gets a pointer to the stated system
   virtual const EcStatedSystem* statedSystem
      (
      ) const;

   /// sets the stated system
   virtual void setStatedSystem
      (
      const EcStatedSystem* system
      );

   /// scale the object in the container by the specified value
   /// (scaleFactor=1.0 does not change the object)
   virtual void scaleSelfBy
      (
      EcReal scaleFactor
      );

   /// scale the shape in the container and its lower-fidelity representation shape by the specified value
   /// (scaleFactor=1.0 does not change the object)
   virtual void scaleBy
      (
      EcReal scaleFactor
      );

   /// transform the shape by the given coordinate system transformation
   virtual void transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// intersect a line segment with the contained shape, returning the closest
   /// point along the line segment using the initial closest point
   /// provided in pointEvent.
   virtual void intersectLineSegment
      (
      const EcLineSegment& lineSegment,
      EcShapePointEvent& pointEvent,
      EcU32 levelOfDetail=0
      ) const;

   /// add a bounding volume to this shape
   virtual void addBoundingVolume
      (
      const EcShape::EcShapeValues& bv
      ) ;

   /// add an explicit bounding volume defined prior to this call
   virtual void addExplicitBoundingVolume
      (
      const EcShape& bvShape
      ) ;

   /// delete all the bounding volumes in the hierarchy
   virtual void deleteBoundingVolumes
      (
      ) ;

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
   static EcShapeContainer nullObject
      (
      );



protected:
   /// set the container pointer for the top element to this
   virtual void setTopElementContainerToThis
      (
      );

   /// a pointer to a stated manipulator system
   const EcStatedSystem* m_pSystem;
};

#endif // ecShapeContainer_H_
