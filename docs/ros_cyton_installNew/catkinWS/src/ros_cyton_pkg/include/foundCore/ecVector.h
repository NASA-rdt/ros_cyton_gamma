#ifndef ecVector_H_
#define ecVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecVector.h
/// @class EcVector
/// @brief A three-element vector.
/// @details It provides utilities such as magnitude, dot product, and cross
///          product.  This class has inline and virtual methods for speed
///          optimization.
/// @todo Move operator>> and oeprator<< to cpp file.
//
//------------------------------------------------------------------------------
#include "ecConfig.h"  // Required to be first header.
#include "ecTypes.h"

class EC_STABLE_FOUNDCORE_DECL EcVector
{
public:
   /// constructor
   EcVector
      (
      );

   /// constructor from three reals
   EcVector
      (
      const EcReal& x,
      const EcReal& y,
      const EcReal& z
      );

   /// destructor
   ~EcVector
      (
      );

   /// copy constructor
   EcVector
      (
      const EcVector& orig
      );

   /// assignment operator
   EcVector& operator=
      (
      const EcVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcVector& orig
      ) const;

   /// add another vector to this vector and set this vector to the result
   inline EcVector& operator +=
      (
      const EcVector& v2
      )
   {
      m_Vector[0]+=v2.m_Vector[0];
      m_Vector[1]+=v2.m_Vector[1];
      m_Vector[2]+=v2.m_Vector[2];
      return *this;
   }

   /// subtract another vector from this vector and set this vector to the result
   inline EcVector& operator -=
      (
      const EcVector& v2
      )
   {
      m_Vector[0]-=v2.m_Vector[0];
      m_Vector[1]-=v2.m_Vector[1];
      m_Vector[2]-=v2.m_Vector[2];
      return *this;
   }

   /// multiply this vector times a scalar and set this vector to the result
   inline EcVector& operator *=
      (
      EcReal s
      )
   {
      m_Vector[0]*=s;
      m_Vector[1]*=s;
      m_Vector[2]*=s;
      return *this;
   }

   /// returns a vector equal to this vector plus another
   EcVector operator+
      (
      const EcVector& v2
      ) const;

   /// returns a vector equal to this vector minus another
   EcVector operator-
      (
      const EcVector& v2
      ) const;

   /// returns a vector which has been multiplied by
   /// the scalar a on an element by element basis
   inline EcVector operator*
      (
      const EcReal& a
      ) const
   {
      return EcVector(m_Vector[0]*a,m_Vector[1]*a,m_Vector[2]*a);
   }

   /// returns a vector which has been divided by
   /// the scalar a on an element by element basis
   EcVector operator/
      (
      const EcReal& a
      ) const;

   /// returns a vector equal to this vector cross another (vector cross product)
   EcVector cross
      (
      const EcVector& v2
      ) const;

	/// vector cross product
   /// @param[in] v2 This cross v2 is calculated.
   /// @param[out] vc vc equals this cross v2.
	void cross
		(
		const EcVector& v2,
		EcVector& vc
		) const;

   /// returns a vector equal to this vector dot another (vector dot product)
   EcReal dot
      (
      const EcVector& v2
      ) const;

   /// returns the magnitude of this vector
   EcReal mag
      (
      ) const;


   /// returns the product of the three elements
   EcReal prod
      (
      ) const;

   /// returns the magnitude squared of this vector (a fast operation)
   EcReal magSquared
      (
      ) const;

   /// returns a unit vector in the same direction as this vector
   EcVector unitVector
      (
      ) const;

   /// normalizes this vector
   EcVector& normalize
      (
      );

   /// tests that each element of this vector is within a tolerance of another
   EcBoolean approxEq
      (
      const EcVector& v2,
      EcReal tol
      ) const;

   /// find the Euclidean distance to another point
   EcReal distanceTo
      (
      const EcVector& vec
      ) const;

   /// find the Euclidean distance squared to another point
   EcReal distanceSquaredTo
      (
      const EcVector& vec
      ) const;

   /// compute a vector which points from this vector (point) to the other vector (point) with a given magnitude.
   /**
   \param[in] destination The destination point
   \param[in] mag The magnitude of the new vector
   \param[out] result The new vector
   */
   void computeDirectionalVector
      (
      const EcVector& destination,
      EcReal mag,
      EcVector& result
      ) const;

   /// returns the x value of the vector
   inline const EcReal& x
      (
      ) const
   {
      return m_Vector[0];
   }

   /// returns the y value of the vector
   inline const EcReal& y
      (
      ) const
   {
      return m_Vector[1];
   }

   /// returns the z value of the vector
   inline const EcReal& z
      (
      ) const
   {
      return m_Vector[2];
   }

   /// sets the x value of the vector
   inline void setX
      (
      const EcReal& val
      )
   {
      m_Vector[0]=val;
   }

   /// sets the y value of the vector
   inline void setY
      (
      const EcReal& val
      )
   {
      m_Vector[1]=val;
   }

   /// sets the z value of the vector
   inline void setZ
      (
      const EcReal& val
      )
   {
      m_Vector[2]=val;
   }

   /// sets all values of the vector
   inline void set
      (
      const EcReal& x,
      const EcReal& y,
      const EcReal& z
      )
   {
      m_Vector[0]=x;
      m_Vector[1]=y;
      m_Vector[2]=z;
   }

   /// sets all value to 0
   inline void setToZero
      (
      )
   {
      m_Vector[0]=0.0;
      m_Vector[1]=0.0;
      m_Vector[2]=0.0;
   }

   /// returns a value by index (0, 1, or 2) - const version.
   inline const EcReal& operator[]
      (
      EcU32 index
      ) const
   {
      return m_Vector[index];
   }

   /// returns a value by index (0, 1, or 2) - nonconst version.
   inline EcReal& operator[]
      (
      EcU32 index
      )
   {
      return m_Vector[index];
   }

   /// returns a zero vector
   static const EcVector& zeroVector
      (
      );

   /// returns [val, 0, 0]
   static EcVector xVector
      (
      const EcReal& val=1.0
      );

   /// returns [0, val, 0]
   static EcVector yVector
      (
      const EcReal& val=1.0
      );

   /// returns [0, 0, val]
   static EcVector zVector
      (
      const EcReal& val=1.0
      );

   ///perturb this vector by a random vector with mag()==scale
   void perturb
      (
      const EcReal scale
      );

protected:

   /// array holding the three vector elements
   EcReal m_Vector[3];

   /// a zero vector to return by reference
   static const EcVector m_theZeroVector;
};

// -----------------------------------------------
// read in and write out below
// -----------------------------------------------

/// reads the vector from a stream
inline std::ostream& operator<<
   (
   std::ostream& stream, const EcVector& vec
   )
{
   stream<<vec.x()<<" "<<vec.y()<<" "<<vec.z();
   return stream;
}

/// writes the vector to a stream
inline std::istream& operator>>
   (
   std::istream& stream, EcVector& vec
   )
{
   EcReal xx;
   EcReal yy;
   EcReal zz;
   stream>>xx;
   stream>>yy;
   stream>>zz;
   vec.set(xx,yy,zz);

   return stream;
}

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// multiplies a vector times a scalar, scalar first
inline EcVector operator *
   (
   const EcReal s,
   const EcVector& v1
   )
{
   return EcVector(v1.x()*s,v1.y()*s,v1.z()*s);
}

/// returns the negative of a vector
inline EcVector operator -
   (
   const EcVector& v1
   )
{
   return EcVector(-v1.x(),-v1.y(),-v1.z());
}

/// a vector of Euclidean vectors
typedef std::vector<EcVector>              EcVectorVector;

/// a vector of vectors of Euclidean vectors
typedef std::vector<EcVectorVector>        EcVectorVectorVector;

/// a vector of vectors of vectors of Euclidean vectors
typedef std::vector<EcVectorVectorVector>  EcVectorVector3D;

#endif // ecVector_H_
