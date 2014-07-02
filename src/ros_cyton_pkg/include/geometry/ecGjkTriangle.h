#ifndef ecGjkTriangle_H_
#define ecGjkTriangle_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecGjkTriangle.h
/// @class EcGJKTriangle
/// @brief A class that defines a triangle used by the GJK algorithm
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecVector.h>
#include <vector>

/// A class that defines a triangle used by the GJK algorithm
class EC_FOUNDATION_GEOMETRY_DECL EcGJKTriangle
{
public:
   /// constructor
   EcGJKTriangle
      (
      );

   /// destructor
   ~EcGJKTriangle
      (
      );

   /// copy constructor
   EcGJKTriangle
      (
      const EcGJKTriangle& orig
      );

   /// assignment operator
   EcGJKTriangle& operator=
      (
      const EcGJKTriangle& orig
      );

   /// equal operator
   EcBoolean operator==
      (
      const EcGJKTriangle& orig
      ) const;

   /// reset to default
   void reset
      (
      );

   /**
    * @brief Access to vert index.
    * @param[in] vNumb
    * @return EcU32
    */
   inline EcU32 vertIndex
      (
      const EcU32& vNumb
      ) const
   {
      return m_IDs[vNumb];
   }

   /// set vert Index
   inline void setVertIndex
      (
      const EcU32& vNumb,
      const EcU32& vIndex
      )
   {
      m_IDs[vNumb] = vIndex;
   }

   /// access to Edge On Boundary
   inline const EcBoolean& edgeOnBoundary
      (
      const EcU32& vNumb
      ) const
   {
      return m_EdgeOnBoundary[vNumb];
   }

   /// set Edge On Boundary
   inline void setEdgeOnBoundary
      (
      const EcU32& vNumb,
      const EcBoolean& edgeOnBound
      )
   {
      m_EdgeOnBoundary[vNumb] = edgeOnBound;
   }

   /// access to closest vector
   inline const EcVector& closestV
      (
      ) const
   {
      return m_V;
   }

   /// non-const accessor to closest vector
   inline EcVector& closestV
      (
      )
   {
      return m_V;
   }


   /// set closest vector
   inline void setClosestV
      (
      const EcVector& v
      )
   {
      m_V = v;
   }

   /// get distance
   inline const EcReal& distanceSQ
      (
      ) const
   {
      return m_DistanceSQ;
   }

   /// set distance
   inline void setDistanceSQ
      (
      const EcReal& distSQ
      )
   {
      m_DistanceSQ = distSQ;
   }

   /// get Lambda
   inline const EcVector& lambda
      (
      ) const
   {
      return m_Lambda;
   }

   /// set Lambda
   inline void setLambda
      (
      const EcVector& lambda
      )
   {
      m_Lambda = lambda;
   }

   /// set Lambda
   inline void setLambda
      (
      const EcReal& lambda0,
      const EcReal& lambda1,
      const EcReal& lambda2
      )
   {
      m_Lambda[0] = lambda0;
      m_Lambda[1] = lambda1;
      m_Lambda[2] = lambda2;
   }

   /// set Lambda
   inline void setLambda
      (
      const EcU32&  index,
      const EcReal& val
      )
   {
      m_Lambda[index] = val;
   }

   /// set Lambda
   inline void setLambda
      (
      const EcRealVector&  lambda
      )
   {
      m_Lambda[0] = lambda[0];
      m_Lambda[1] = lambda[1];
      m_Lambda[2] = lambda[2];
   }

   /// get Lambda
   inline const EcReal& lambda
      (
      const EcU32&  index
      ) const
   {
      return m_Lambda[index];
   }

   /// get Dividable
   inline const EcBoolean& dividable
      (
      ) const
   {
      return m_Dividable;
   }

   /// set dividable
   inline void setDividable
      (
      const EcBoolean& dividable
      )
   {
      m_Dividable = dividable;
   }

protected:
   /// vertices ID for triangle
   EcInt32   m_IDs[3];
   /// status of each edge
   EcBoolean m_EdgeOnBoundary[3];
   /// closest vector of triangle
   EcVector  m_V;
   /// distance from triangle to origion
   EcReal    m_DistanceSQ;
   /// coefficient of 3 vertices for m_V
   EcVector  m_Lambda;
   /// if this triangle is subdividable
   EcBoolean m_Dividable;
};

#endif // ecGjkTriangle_H_
