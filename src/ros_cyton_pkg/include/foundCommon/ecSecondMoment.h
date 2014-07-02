#ifndef ecSecondMoment_H_
#define ecSecondMoment_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecSecondMoment.h
/// @class EcSecondMoment
/// @brief Represents a 3D second moment.  To do this, it uses
///        six quatities, Jxx, Jyy, Jzz, Jxy, Jxz, Jyz.  When
///        organized into the traditional symmetric 3x3 matrix
///        these give the following:
///        |Jxx Jxy Jxz|
///        J = |Jxy Jyy Jyz|
///        |Jxy Jyz Jzz|
///        Jxx= Integrate[y*y + z*z dm]
///        Jyy= Integrate[x*x + z*z dm]
///        Jzz= Integrate[x*x + y*y dm]
///        Jxy=-Integrate[x*y dm]
///        Jxz=-Integrate[x*z dm]
///        Jyz=-Integrate[y*z dm]
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecSpatialMatrix.h"
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

// forward declarations
class EcReArray;

/** Holds a second moment.  This is a positive semidefinite 3x3
 symmetric matrix.  Only six values are unique, and only six values are
 stored in this class.
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcSecondMoment : public EcXmlCompoundType
{
public:
   /// default constructor
   EcSecondMoment
      (
      );

   /// constructor with all components
   EcSecondMoment
      (
      const EcReal& jxx,
      const EcReal& jyy,
      const EcReal& jzz,
      const EcReal& jxy=0.0,
      const EcReal& jxz=0.0,
      const EcReal& jyz=0.0
      );

   /// destructor
   virtual ~EcSecondMoment
      (
      );

   /// copy constructor
   EcSecondMoment
      (
      const EcSecondMoment& orig
      );

   /// assignment operator
   EcSecondMoment& operator=
      (
      const EcSecondMoment& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSecondMoment& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
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

   /// adds another second moment to this and sets this to the result
   EcSecondMoment& operator+=
      (
      const EcSecondMoment& v2
      );

   /// subtracts another second moment from this and sets this to the result
   EcSecondMoment& operator-=
      (
      const EcSecondMoment& v2
      );

   /// adds another second moment to this and returns the result
   EcSecondMoment  operator+
      (
      const EcSecondMoment& v2
      ) const;

   /// subtracts another second moment from this and returns the result
   EcSecondMoment  operator-
      (
      const EcSecondMoment& v2
      ) const;

   /// scales all the entries by the specified real value
   const EcSecondMoment& operator *=
      (
      EcReal s
      );

   /// transforms a vector
   EcVector operator*
      (
      const EcVector& vec
      ) const;

   /// rotation.  Returns the transformed entity
   virtual EcSecondMoment& transformBy
      (
      const EcOrientation& orientatation
      );

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// gets the xx value
   virtual EcReal jxx
      (
      ) const;

   /// gets the yy value
   virtual EcReal jyy
      (
      ) const;

   /// gets the zz value
   virtual EcReal jzz
      (
      ) const;

   /// gets the xy value
   virtual EcReal jxy
      (
      ) const;

   /// gets the xz value
   virtual EcReal jxz
      (
      ) const;

   /// gets the yz value
   virtual EcReal jyz
      (
      ) const;

   /// get the inertia as a symmetric spatial matrix
   virtual EcSpatialMatrix spatialMatrix
      (
      ) const;

   /// get the inertia as a real array
   virtual void getArray
      (
      EcReArray& array
      ) const;

   /// sets all six values
   virtual void set
      (
      EcReal jxx,
      EcReal jyy,
      EcReal jzz,
      EcReal jxy=0.0,
      EcReal jxz=0.0,
      EcReal jyz=0.0
      );

   /// set the inertia from a spatial matrix
   /// note: only the upper right-hand portion of the
   /// matrix is used.
   virtual void setFromSpatialMatrix
      (
      const EcSpatialMatrix& matrix
      );

   /// get the principal axes for the second moment
   virtual EcBoolean getPrincipalAxes
      (
      EcOrientation& principalAxes
      ) const;

   /// checks validity (as positive definiteness)
   virtual EcBoolean isValid
      (
      ) const;

   /// make the second moment valid by minimally tweaking its elements. Does nothing if it's already valid.
   virtual void makeValid
      (
      );

   /// tests for approximate equality
   virtual EcBoolean approxEq
      (
      const EcSecondMoment& sm2,
      EcReal tol
      ) const;

   /// a (mostly string) token for this class
   virtual const EcToken& token
      (
      ) const;

   /// reads this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// writes this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// gets an zero second moment
   static EcSecondMoment nullObject
      (
      );

   /// gets an x second moment
   static EcSecondMoment xSecondMoment
      (
      EcReal value
      );

   /// gets a y second moment
   static EcSecondMoment ySecondMoment
      (
      EcReal value
      );

   /// gets a z second moment
   static EcSecondMoment zSecondMoment
      (
      EcReal value
      );

   /// gets a diagonal second moment
   static EcSecondMoment diagonalSecondMoment
      (
      EcReal xxValue,
      EcReal yyValue,
      EcReal zzValue
      );

protected:

   /// position (0,0) in the matrix
   EcXmlReal      m_Jxx;

   /// position (0,1) in the matrix
   EcXmlReal      m_Jyy;

   /// position (0,2) in the matrix
   EcXmlReal      m_Jzz;

   /// position (0,1) and (1,0) in the matrix
   EcXmlReal      m_Jxy;

   /// position (0,2) and (2,0) in the matrix
   EcXmlReal      m_Jxz;

   /// position (1,2) and (2,1) in the matrix
   EcXmlReal      m_Jyz;
};

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the second moment in a rotated frame
EC_FOUNDATION_FOUNDCOMMON_DECL EcSecondMoment transform
   (
   const EcOrientation& q,
   const EcSecondMoment& m
   );

/// treats the second moment as a 3x3 matrix and multiplies
/// it on the right by another 3x3 matrix
EC_FOUNDATION_FOUNDCOMMON_DECL EcSpatialMatrix operator*
   (
   const EcSecondMoment& secondMoment,
   const EcSpatialMatrix& spatialMatrix
   );

/// treats the second moment as a 3x3 matrix and multiplies
/// it on the left by another 3x3 matrix
EC_FOUNDATION_FOUNDCOMMON_DECL EcSpatialMatrix operator*
   (
   const EcSpatialMatrix& spatialMatrix,
   const EcSecondMoment& secondMoment
   );

#endif // ecSecondMoment_H_
