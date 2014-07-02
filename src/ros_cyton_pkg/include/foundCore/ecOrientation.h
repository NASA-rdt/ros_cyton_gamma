#ifndef ecOrientation_H_
#define ecOrientation_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecOrientation.h
/// @class EcOrientation
/// @brief Description of a 3D rotation
/// @details It stores the data as a quaternion but provides utility functions for working with DCM
///           matrices and Euler angles.  The quaternion representation is that for
///           which (1,0,0,0) corresponds to no rotation.
//
//------------------------------------------------------------------------------
#include "ecConfig.h"  // Required to be first header.
#include "ecTypes.h"
#include <vector>

class EcVector;

/// A tolerance value for the sum of the magnitude squared of the
/// quaternion entries.
const EcReal EcTOLERANCE = 1e-12;

class EC_STABLE_FOUNDCORE_DECL EcOrientation
{
public:
   /// constructor
   EcOrientation
      (
      );

   /// constructor from four reals: w, x, y, and z
   EcOrientation
      (
      const EcReal& w,
      const EcReal& x,
      const EcReal& y,
      const EcReal& z
      );

   /// destructor
   ~EcOrientation
      (
      );

   /// copy constructor
   EcOrientation
      (
      const EcOrientation& orig
      );

   /// assignment operator
   EcOrientation& operator=
      (
      const EcOrientation& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcOrientation& orig
      ) const;

   /// clone - a constructor.  This allocates memory for the new object.
   EcOrientation* clone
      (
      ) const;

   /// transforms this orientation by another on the right
   /**
   Transforms this orientation by another as in this = this * orient2.
   \param[in] orient2 The orientation used to transform this orientation.
   \return This EcOrientation object after transformation.
   */
   EcOrientation& operator *=
      (
      const EcOrientation& orient2
      );

   /// returns a transformation equal to this transformed on the right by another
   /**
   \param[in] orient2 The orientation used in transformation with this orientation.
   \return An orientation = this * orient2.
   */
   EcOrientation operator*
      (
      const EcOrientation& orient2
      ) const;

   /// transforms a vector and return the result
   /**
   \param[in] vec A vector used in transformation.
   \return The transformed vector.
   */
   EcVector operator*
      (
      const EcVector& vec
      ) const;

   /// transforms a vector in place.
   /**
   \param[in,out] vec A vector to be transformed.
   */
   void transform
      (
      EcVector& vec
      ) const;

   /// transforms a vector and puts the result in the second argument
   /// The same vector may be used for to and from.
   /**
   \param[in] from A vector used in transformation.
   \param[out] to The result of the transformation.
   */
   void transform
      (
      const EcVector& from,
      EcVector& to
      ) const;

   /// transforms two vectors - more efficient than transforming individually
   /// The same vector object may be used for both to and from to transform
   /// in place.
   /**
   \param[in] firstFrom This is the first vector to be transformed.
   \param[out] firstTo This is the transformation of firstFrom.
   \param[in] secondFrom This is the second vector to be transformed.
   \param[out] secondTo This is the transformation of secondFrom.
   */
   void transform
      (
      const EcVector& firstFrom,
      EcVector& firstTo,
      const EcVector& secondFrom,
      EcVector& secondTo
      ) const;

   /// tests for approximate equality of orientations (note: not of quaterions, which may be +/-)
   /**
   \param[in] orient2 This is the EcOrientation to be compared with this.
   \param[in] tol This is the numerical tolerance used in quaternion space. The difference two norm is compared.
   */
   EcBoolean approxEq
      (
      const EcOrientation& orient2,
      EcReal tol=EcTOLERANCE
      ) const;

   /// finds the angle and axis between two quaternions.
   /**
   Finds the angle and axis between this orientation and another.
   \param[in] q2 The other orientation.
   \param[out] theta Upon return, the angle in radians between the two orientation.
   \param[out] axis Upon return, the axis between the two orientation.
   */
   EcBoolean angleAxisBetween
      (
      const EcOrientation& q2,
      EcReal&     theta,
      EcVector&   axis
      ) const;

   /// Finds hyperspherical surface interpolation between the two quaternions.
   /// Can be called on an object with self as the first argument (orient1)
   /**
   Finds hyperspherical surface interpolation between the two quaternions and sets the result in this orientation.
   \param[in] orient1 The first orientation. Can be itself.
   \param[in] orient2 The second orientation.
   \param[in] factor A real number between 0 and 1 will from orient1 to orient2. A number outside of 0 and 1 will extrapolate the two quaternions.
   */
   void interpolation
      (
      const EcOrientation& orient1,
      const EcOrientation& orient2,
      const EcReal& factor
      );

   /// gets the inverse of the orientation
   /**
   \return The inverse of this orientation.
   */
   EcOrientation inverse
      (
      )const;

   /// inverts this in place
   /**
   \return This orientation after inversion.
   */
   EcOrientation& invert
      (
      );

   /// gets the first quaternion value
   inline const EcReal& w
      (
      ) const
   {
      return m_Quaternion[0];
   }

   /// gets the second quaternion value
   inline const EcReal& x
      (
      ) const
   {
      return m_Quaternion[1];
   }

   /// gets the third quaternion value
   inline const EcReal& y
      (
      ) const
   {
      return m_Quaternion[2];
   }

   /// gets the fourth quaternion value
   inline const EcReal& z
      (
      ) const
   {
      return m_Quaternion[3];
   }

   /// sets a quaternion value directly
   inline void set
      (
      const EcReal& w,
      const EcReal& x,
      const EcReal& y,
      const EcReal& z
      )
   {
      m_Quaternion[0]=w;
      m_Quaternion[1]=x;
      m_Quaternion[2]=y;
      m_Quaternion[3]=z;
      normalize();
   }

   /// sets a quaternion value from an array
   /**
   \param[in] vec A vector of four values mapped to quaterion w, x, y, and z.
   */
   void set
      (
      const EcRealVector& vec
      );

   /// sets from yaw, pitch, roll Euler angles
   /**
   \param[in] psi Yaw about z-axis.
   \param[in] theta Pitch about y-axis.
   \param[in] phi Roll about x-axis.
   */
   void setFrom321Euler
      (
      const EcReal& psi,
      const EcReal& theta,
      const EcReal& phi
      );

   /// gets yaw, pitch, roll Euler angles
   /**
   \param[out] psi Yaw about z-axis.
   \param[out] theta Pitch about y-axis.
   \param[out] phi Roll about x-axis.
   */
   void get321Euler
      (
      EcReal& psi,
      EcReal& theta,
      EcReal& phi
      ) const;

   /// sets from roll, pitch, yaw Euler angles
   /**
   \param[in] phi Roll about x-axis.
   \param[in] theta Pitch about y-axis.
   \param[in] psi Yaw about z-axis.
   */
   void setFrom123Euler
      (
      const EcReal& phi,
      const EcReal& theta,
      const EcReal& psi
      );

   /// gets roll, pitch, yaw Euler angles
   /**
   \param[out] phi Roll about x-axis.
   \param[out] theta Pitch about y-axis.
   \param[out] psi Yaw about z-axis.
   */
   void get123Euler
      (
      EcReal& phi,
      EcReal& theta,
      EcReal& psi
      ) const;

   /// sets from pitch, yaw, roll Euler angles
   /**
   \param[in] theta Pitch about y-axis.
   \param[in] psi Yaw about z-axis.
   \param[in] phi Roll about x-axis.
   */
   void setFrom231Euler
      (
      const EcReal& theta,
      const EcReal& psi,
      const EcReal& phi
      );

   /// sets the rotation based on an angle and an axis. The axis
   /// must be normalized before calling this function.
   /**
   \param[in] angle The outboard frame is rotated this much about the axis.
   \param[in] axis The unit-vector axis of rotation.
   */
   void setFromAngleAxis
      (
      EcReal angle,
      const EcVector& axis
      );

   /// gets the angle and axis for an orientation
   /**
   \param[out] angle The outboard frame is rotated this much about the axis.
   \param[out] axis The unit-vector axis of rotation.
   */
   void getAngleAxis
      (
      EcReal& angle,
      EcVector& axis
      ) const;

   /// sets the rotation from a Rodrigues vector (also called Gibbs vector)
   /// p = k tan(theta/2), for axis k and angle theta
   /**
   \param[in] vector The Rodrigues vector.
   */
   void setFromRodriguesVector
      (
      const EcVector& vector
      );

   /// gets the Rodrigues vector (also called Gibbs vector)
   /// p = k tan(theta/2), for axis k and angle theta
   /// returns an approximation when theta=Pi.
   /**
   \param[out] vector The Rodrigues vector.
   */
   void getRodriguesVector
      (
      EcVector& vector
      );

   /// gets any quaternion element by index
   /**
   \param[in] index {0=w, 1=x, 2=y, 3=z}
   */
   const EcReal& operator[]
      (
      EcU32 index
      ) const;

   /// gets the rows of a DCM matrix corresponding to the orientation. These
   /// are unit norm and orthogonal. row0 x row1 = row2.
   /**
   \param[out] row0 The first row of the DCM representation of the rotation.
   \param[out] row1 The second row of the DCM representation of the rotation.
   \param[out] row2 The third row of the DCM representation of the rotation.
   */
   void getDcmRows
      (
      EcVector& row0,
      EcVector& row1,
      EcVector& row2
      ) const;

   /// sets the orientation from DCM rows
   /**
   \param[in] row0 The first row of the DCM representation of the rotation.
   \param[in] row1 The second row of the DCM representation of the rotation.
   \param[in] row2 The third row of the DCM representation of the rotation.
   */
   void setFromDcmRows
      (
      const EcVector& row0,
      const EcVector& row1,
      const EcVector& row2
      );

   /// gets the columns of a DCM matrix corresponding to the orientation. These
   /// are unit norm and orthogonal. col0 x col1 = col2.
   /**
   \param[out] col0 The first column of the DCM representation of the rotation.
   \param[out] col1 The second column of the DCM representation of the rotation.
   \param[out] col2 The third column of the DCM representation of the rotation.
   */
   void getDcmColumns
      (
      EcVector& col0,
      EcVector& col1,
      EcVector& col2
      ) const;

   /// sets the orientation from DCM columns
   /**
   \param[out] col0 The first column of the DCM representation of the rotation.
   \param[out] col1 The second column of the DCM representation of the rotation.
   \param[out] col2 The third column of the DCM representation of the rotation.
   */
   void setFromDcmColumns
      (
      const EcVector& col0,
      const EcVector& col1,
      const EcVector& col2
      );

   /// integrates an angular velocity.
   /// The angular velocity is expressed in the moving
   /// coordinate system.
   /**
   Integrates an angular velocity and then sets the result as this orientation.
   \param[in] angularVelocity The angular velocity in rad/s in the moving coordinate system.
   \param[in] time The time to integrate.
   */
   void integrateLocalFrameAngularVelocity
      (
      const EcVector& angularVelocity,
      EcReal time
      );

   /// integrates an angular velocity.
   /// The angular velocity is expressed in the reference
   /// (nonmoving) coordinate system.
   /**
   Integrates an angular velocity and then sets the result as this orientation.
   \param[in] angularVelocity The angular velocity in rad/s in the reference coordinate system.
   \param[in] time The time to integrate.
   */
   void integrateReferenceFrameAngularVelocity
      (
      const EcVector& angularVelocity,
      EcReal time
      );

   /// calculate quaternion rate from angular velocity.
   /**
   \param[in] angularVelocity The angular velocity in rad/s in the moving coordinate system.
   \param[out] vQuaternionRate Upon return, the vector of size 4 containing the quaternion rate
   */
   void quaternionRateFromLocalFrameAngularVelocity
      (
      const EcVector& angularVelocity,
      EcRealVector& vQuaternionRate
      ) const;

   /// calculate quaternion rate from angular velocity.
   /**
   \param[in] angularVelocity The angular velocity in rad/s in the reference coordinate system.
   \param[out] vQuaternionRate Upon return, the vector of size 4 containing the quaternion rate
   */
   void quaternionRateFromReferenceFrameAngularVelocity
      (
      const EcVector& angularVelocity,
      EcRealVector& vQuaternionRate
      ) const;

   /// calculate quaternion acceleration from angular velocity and acceleration expressed in the moving coordinate system.
   /**
   \param[in] angularVelocity The angular velocity in rad/s in the moving coordinate system.
   \param[in] angularAcceleration The angular acceleration in rad/s in the moving coordinate system.
   \param[out] vQuaternionAcceleration Upon return, the vector of size 4 containing the quaternion acceleration
   */
   void quaternionAccelerationFromLocalFrameAngularMotion
      (
      const EcVector& angularVelocity,
      const EcVector& angularAcceleration,
      EcRealVector& vQuaternionAcceleration
      ) const;

   /// calculate quaternion acceleration from angular velocity and acceleration expressed in the reference coordinate system.
   /**
   \param[in] angularVelocity The angular velocity in rad/s in the reference coordinate system.
   \param[in] angularAcceleration The angular acceleration in rad/s in the reference coordinate system.
   \param[out] vQuaternionAcceleration Upon return, the vector of size 4 containing the quaternion acceleration
   */
   void quaternionAccelerationFromReferenceFrameAngularMotion
      (
      const EcVector& angularVelocity,
      const EcVector& angularAcceleration,
      EcRealVector& vQuaternionAcceleration
      ) const;

   /// calculate angular velocity from quaternion rate.
   /// The angular velocity is expressed in the moving
   /// coordinate system.
   /**
   \param[in] vQuaternionRate A vector representing the quaternion rate. Must be of size 4.
   \param[out] angularVelocity Upon return, an EcVector object containing the angular velocity in rad/s in the moving coordinate frame.
   */
   void localFrameAngularVelocityFromQuaternionRate
      (
      const EcRealVector& vQuaternionRate,
      EcVector& angularVelocity
      ) const;

   /// calculate angular velocity from quaternion rate.
   /// The angular velocity is expressed in the stationary
   /// reference coordinate system.
   /**
   \param[in] vQuaternionRate A vector representing the quaternion rate. Must be of size 4.
   \param[out] angularVelocity Upon return, an EcVector object containing the angular velocity in rad/s in the reference coordinate frame.
   */
   void referenceFrameAngularVelocityFromQuaternionRate
      (
      const EcRealVector& vQuaternionRate,
      EcVector& angularVelocity
      ) const;

   /// gets the outboard x-axis (the first column of the DCM matrix)
   EcVector xAxis
      (
      ) const;

   /// gets the outboard y-axis (the second column of the DCM matrix)
   EcVector yAxis
      (
      ) const;

   /// gets the outboard z-axis (the third column of the DCM matrix)
   EcVector zAxis
      (
      ) const;

   /// gets an identity orientation
   static const EcOrientation& identity
      (
      );

   /// returns a w quaternion (i.e., [1,0,0,0])
   static EcOrientation wQuaternion
      (
      );

   /// returns a x quaternion (i.e., [0,1,0,0])
   static EcOrientation xQuaternion
      (
      );

   /// returns a y quaternion (i.e., [0,0,1,0])
   static EcOrientation yQuaternion
      (
      );

   /// returns a z quaternion (i.e., [0,0,0,1])
   static EcOrientation zQuaternion
      (
      );

   /// returns an x rotation (i.e., a rotation by angle about the 3D x-axis)
   static EcOrientation xRotation
      (
      EcReal angle
      );

   /// returns a y rotation (i.e., a rotation by angle about the 3D y-axis)
   static EcOrientation yRotation
      (
      EcReal angle
      );

   /// returns a z rotation (i.e., a rotation by angle about the 3D z-axis)
   static EcOrientation zRotation
      (
      EcReal angle
      );

protected:

   /// takes the magnitude of the internal representation
   EcReal magSquared
      (
      ) const;

   /// normalizes the internal representation
   void normalize
      (
      );

protected:
   /// the internal representation of the quaternion
   EcReal m_Quaternion[4];

   /// an identity rotation that can be returned by const reference
   static const EcOrientation m_theIdentity;
};


// -----------------------------------------------
// read in and write out below
// -----------------------------------------------

/// reads in a quaternion from a stream
inline EC_STABLE_FOUNDCORE_DECL std::ostream& operator<<
   (
   std::ostream& stream,
   const EcOrientation& val
   )
{
   stream << val.w() << " " << val.x() << " " << val.y() << " " << val.z();
   return stream;
}

/// writes out a quaternion to a stream
inline EC_STABLE_FOUNDCORE_DECL std::istream& operator>>
   (
   std::istream& stream,
   EcOrientation& val
   )
{
   EcReal ww, xx, yy, zz;
   stream >> ww >> xx >> yy >> zz;
   val.set(ww, xx, yy, zz);

   return stream;
}

#endif // ecOrientation_H_
