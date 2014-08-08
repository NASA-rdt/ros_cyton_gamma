#ifndef ecPlanarVector_H_
#define ecPlanarVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecPlanarVector.h
/// @class EcPlanarVector
/// @brief A two-dimensional vector
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// forward declarations
class EcVector;

/** Holds a description of a planar vector (2-D)
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcPlanarVector : public EcXmlCompoundType
{
public:
   /// default constructor
   EcPlanarVector
      (
      );

   /// constructor from two reals
   EcPlanarVector
      (
      const EcReal& x,
      const EcReal& y
      );

   /// destructor
   virtual ~EcPlanarVector
      (
      );

   /// copy constructor
   EcPlanarVector
      (
      const EcPlanarVector &params
      );

   /// assignment operator
   EcPlanarVector& operator=
      (
      const EcPlanarVector &params
      );

   /// cast to non-XML orientation
   operator const EcVector&
      (
      ) const;

   /// equality operator
   EcBoolean operator==
      (
      const EcPlanarVector &params
      ) const;

   /// inequality operator
   EcBoolean operator!=
      (
      const EcPlanarVector &params
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

   /// add another vector to this vector and set this vector to the result
   EcPlanarVector& operator +=
      (
      const EcPlanarVector& v2
      );

   /// subtract another vector from this vector and set this vector to the result
   EcPlanarVector& operator -=
      (
      const EcPlanarVector& v2
      );

   /// multiply this vector times a scalar and set this vector to the result
   EcPlanarVector& operator *=
      (
      EcReal s
      );

   /// returns a vector equal to this vector plus another
   EcPlanarVector operator+
      (
      const EcPlanarVector& v2
      ) const;

   /// returns a vector equal to this vector minus another
   EcPlanarVector operator-
      (
      const EcPlanarVector& v2
      ) const;

   /// returns a vector equal to this vector dot another (vector dot product)
   virtual EcReal dot
      (
      const EcPlanarVector& v2
      ) const;

   /// returns the magnitude of this vector
   virtual EcReal mag
      (
      ) const;

   /// returns the magnitude squared of this vector (a fast operation)
   virtual EcReal magSquared
      (
      ) const;

   /// returns a unit vector in the same direction as this vector
   virtual EcPlanarVector unitVector
      (
      ) const;

   /// tests that each element of this vector is within a tolerance of another
   virtual EcBoolean approxEq
      (
      const EcPlanarVector& vec2,
      EcReal tol
      ) const;

   /// find the Euclidean distance to another point
   virtual EcReal distanceTo
      (
      const EcPlanarVector& other
      ) const;

   /// find the Euclidean distance squared to another point
   virtual EcReal distanceSquaredTo
      (
      const EcPlanarVector& other
      ) const;

   /// set this to be the projection of a vector onto the xy plane
   virtual void setToProjectionOf
      (
      const EcVector& vector
      );

   /// returns a value by index (0 or 1) - const version.
   const EcReal& operator[]
      (
      EcU32 index
      ) const;

   /// returns a value by index (0 or 1) - nonconst version.
   EcReal& operator[]
      (
      EcU32 index
      );

   /// get X
   virtual EcReal x
      (
      ) const;

   /// set X
   virtual void setX
      (
      EcReal x
      );

   /// get Y
   virtual EcReal y
      (
      ) const;

   /// set Y
   virtual void setY
      (
      EcReal y
      );

   /// a (mostly string) token for this class
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

   /// read this object from a binary stream
   virtual EcBoolean readBin
      (
      std::istream& stream
      );

   /// write this object to a binary stream
   virtual EcBoolean writeBin
      (
      std::ostream& stream
      ) const;

   /// get an identity transformation
   static EcPlanarVector nullObject
      (
      );

protected:
   /// the raw X vector value, for use in XML read/write
   EcXmlReal      m_X;

   /// the raw X vector value, for use in XML read/write
   EcXmlReal      m_Y;
};

/// A vector of planar vectors
typedef EcXmlVectorType<EcPlanarVector> EcPlanarVectorVector;

/// A 2D vector of planar vectors
typedef EcXmlVectorType<EcPlanarVectorVector>
   EcPlanarVector3D;

/// A 3D vector of planar vectors
typedef EcXmlVectorType<EcPlanarVectorVector>
   EcPlanarVector4D;


// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// multiplies a vector times a scalar, vector first
inline EC_FOUNDATION_FOUNDCOMMON_DECL EcPlanarVector operator *
   (
   const EcPlanarVector& v1,
   const EcReal s
   )
{
   return EcPlanarVector(v1.x()*s,v1.y()*s);
}

/// multiplies a vector times a scalar, scalar first
inline EC_FOUNDATION_FOUNDCOMMON_DECL EcPlanarVector operator *
   (
   const EcReal s,
   const EcPlanarVector& v1
   )
{
   return EcPlanarVector(v1.x()*s,v1.y()*s);
}

/// returns the negative of a vector
inline EC_FOUNDATION_FOUNDCOMMON_DECL EcPlanarVector operator -
   (
   const EcPlanarVector& v1
   )
{
   return EcPlanarVector(-v1.x(),-v1.y());
}

#endif // ecPlanarVector_H_
