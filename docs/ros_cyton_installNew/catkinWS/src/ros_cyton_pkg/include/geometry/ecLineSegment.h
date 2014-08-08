#ifndef ecLineSegment_H_
#define ecLineSegment_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecLineSegment.h
/// @class EcLineSegment
/// @brief Holds a class to describe a 3D line segment.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVector.h>

// forward declarations
class EcCoordinateSystemTransformation;

/** Holds a class to describe a 3D line segment.
*/
class EC_FOUNDATION_GEOMETRY_DECL EcLineSegment : public EcXmlCompoundType
{
public:
   /// default constructor
   EcLineSegment
      (
      );

   /// constructor from endpoints
   EcLineSegment
      (
      const EcVector& endpoint0,
      const EcVector& endpoint1
      );

   /// destructor
   ~EcLineSegment
      (
      );

   /// copy constructor
   EcLineSegment
      (
      const EcLineSegment& orig
      );

   /// assignment operator
   EcLineSegment& operator=
      (
      const EcLineSegment& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLineSegment& orig
      ) const;

   /// initialize XML components for reading and writing
   EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   EcXmlObject* newObject
      (
      ) const;

   /// get an endpoint by index
   const EcVector& endpoint
      (
      EcU32 index
      ) const;

   /// set endpoint 0
   void setEndpoint0
      (
      const EcVector& endpoint0
      );

   /// get endpoint 0
   inline const EcVector& endpoint0
      (
      ) const
   {
      return m_Endpoint0;
   }

   /// set endpoint 1
   void setEndpoint1
      (
      const EcVector& endpoint1
      );

   /// get endpoint 1
   inline const EcVector& endpoint1
      (
      ) const
   {
      return m_Endpoint1;
   }

   /// set both endpoints
   void setEndpoints
      (
      const EcVector& endpoint0,
      const EcVector& endpoint1
      );

   /// center of the line segment
   EcVector center
      (
      ) const;

   /// get the delta between the endpoints
   inline const EcVector& delta
      (
      ) const
   {
      return m_Delta;
   }

   /// transform by a coordinate system transformation
   void transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// get the length of the line segment
   EcReal length
      (
      ) const;

   /// get the length squared of the line segment
   EcReal lengthSquared
      (
      ) const;

   /// get the distance to a point
   EcReal distanceTo
      (
      const EcVector& vec
      ) const;

   /// get the distance squared to a point
   EcReal distanceSquaredTo
      (
      const EcVector& vec
      ) const;

   /// get the distance squared to a point
   /// t-value: less than 0 and the nearest point on the line is off
   /// the endpoint0 end of the segment; greater than 1 and the nearest
   /// point is off the endpoint1 end.
   EcReal distanceSquaredTo
      (
      const EcVector& vec,
      EcReal& tValue
      ) const;

   /// get the distance squared from the line through this
   /// segment to the point
   EcReal distanceSquaredFromLineTo
      (
      const EcVector& vec
      ) const;

   /// get the distance squared from the line through this
   /// segment to the point.  This version also returns the
   /// t-value: less than 0 and the nearest point on the line is off
   /// the endpoint0 end of the segment; greater than 1 and the nearest
   /// point is off the endpoint1 end.
   EcReal distanceSquaredFromLineTo
      (
      const EcVector& vec,
      EcReal& tValue
      ) const;

   /// get the distance squared from the line through this
   /// segment to the line through another segment.  This
   /// version also returns the t-value for both this and
   /// the other line: less than 0 and the nearest point on the line is off
   /// the endpoint0 end of the segment; greater than 1 and the nearest
   /// point is off the endpoint1 end.
   EcReal distanceSquaredLineToLine
      (
      const EcLineSegment& other,
      EcReal& thisTValue,
      EcReal& otherTValue
      ) const;

   /// get the distance to another line segment
   EcReal distanceTo
      (
      const EcLineSegment& other
      ) const;

   /// get the distance squared to another line segment
   EcReal distanceSquaredTo
      (
      const EcLineSegment& other
      ) const;

   /// get the distance squared, returning parametric
   /// values describing where the closest point resides
   /// on this line segment and the other
   EcReal distanceSquaredTo
      (
      const EcLineSegment& other,
      EcReal& thisTValue,
      EcReal& otherTValue
      ) const;

   /// get the non-degenerate distance squared, returning parametric
   /// values describing where the closest point resides
   /// on this line segment and the other
   EcReal nondegenerateDistanceSquaredTo
      (
      const EcLineSegment& other,
      EcReal& thisTValue,
      EcReal& otherTValue
      ) const;

   /// swap endpoints
   void swapEndpoints
      (
      );

   /// compute the point on the line segment based on a t-value
   void computePointOnLineSegment
      (
      EcReal tValue,
      EcVector& point
      ) const;

   /// get token
   const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get an empty object
   static EcLineSegment nullObject
      (
      );

protected:

   /// get the distance squared to another line segment when neither this
   /// nor the other is degenerate.  That is, both segments must have
   /// distinct endpoints to use this function.
   EcReal nondegenerateDistanceSquaredTo
      (
      const EcLineSegment& other
      ) const;

protected:

   /// the first endpoint
   EcXmlVector m_Endpoint0;

   /// the second endpoint
   EcXmlVector m_Endpoint1;

   /// non-XML data below

   /// the vector from endpoint0 to endpoint1
   EcVector m_Delta;

   /// the length squared of m_Delta;
   EcReal   m_LengthSquared;
};

/// A vector of line segments
typedef EcXmlVectorType<EcLineSegment> EcLineSegmentVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the line segment in an offset, rotated frame
EC_FOUNDATION_GEOMETRY_DECL EcLineSegment operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcLineSegment& m
   );

#endif // ecLineSegment_H_
