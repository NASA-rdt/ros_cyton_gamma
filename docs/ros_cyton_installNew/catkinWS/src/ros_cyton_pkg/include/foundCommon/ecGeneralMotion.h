#ifndef ecGeneralMotion_H_
#define ecGeneralMotion_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecGeneralMotion.h
/// @brief A general motion class -- to be applied to general
///        velocity and general acceleration.
/// @details State EcGeneralMotion
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecVector.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVector.h>

// forward declaration
class EcCoordinateSystemTransformation;
class EcOrientation;
class EcReArray;

/** Holds a 3D linear and angular motion pair.  This class can be
 used to represent velocity or acceleration.
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcGeneralMotion : public EcXmlCompoundType
{
public:
   /// default constructor
   EcGeneralMotion
      (
      );

   /// constructor with a linear and angular component
   EcGeneralMotion
      (
      const EcVector& linear,
      const EcVector& angular
      );

   /// destructor
   ~EcGeneralMotion
      (
      );

   /// copy constructor
   EcGeneralMotion
      (
      const EcGeneralMotion& orig
      );

   /// assignment operator
   EcGeneralMotion& operator=
      (
      const EcGeneralMotion& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGeneralMotion& orig
      ) const;

   /// initialize XML components for reading and writing
   EcBoolean xmlInit
      (
      );

   /// clone - a constructor to an EcXmlObject pointer
   EcXmlObject* clone
      (
      ) const;

   /// equality - equality to an EcXmlObject pointer
   EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// new that returns an EcXmlObject
   EcXmlObject* newObject
      (
      ) const;

   /// add this general motion to another and set this to the result.
   EcGeneralMotion& operator+=
      (
      const EcGeneralMotion& v2
      );

   /// subtract another general motion from this and set this to the result.
   EcGeneralMotion& operator-=
      (
      const EcGeneralMotion& v2
      );

   /// add this general motion to another and return the result.
   EcGeneralMotion  operator+
      (
      const EcGeneralMotion& v2
      ) const;

   /// subtract another general motion from this and return the result.
   EcGeneralMotion  operator-
      (
      const EcGeneralMotion& v2
      ) const;

   /// scale the general motion
   EcGeneralMotion operator*
      (
      const EcReal& s
      ) const;

   /// scalar in place
   EcGeneralMotion& operator*=
      (
      EcReal factor
      );

   /// general transformation.  Returns transformed entity.
   EcGeneralMotion& transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// rotation.  Returns the transformed entity
   EcGeneralMotion& transformBy
      (
      const EcOrientation& orientatation
      );

   /// offset.  Returns the transformed entity
   EcGeneralMotion& transformBy
      (
      const EcVector& transformation
      );

   /// register components with the parent
   void registerComponents
      (
      );

   /// get linear component
   inline const EcVector& linear
      (
      ) const
   {
      return m_Linear.value();
   }

   /// set linear component
   inline void setLinear
      (
      const EcVector& value
      )
   {
      m_Linear=value;
   }

   /// set the x linear value
   inline void setLinearX
      (
      EcReal value
      )
   {
      m_Linear.value().setX(value);
   }

   /// set the y linear value
   inline void setLinearY
      (
      EcReal value
      )
   {
      m_Linear.value().setY(value);
   }

   /// set the z linear value
   inline void setLinearZ
      (
      EcReal value
      )
   {
      m_Linear.value().setZ(value);
   }

   /// get angular component
   inline const EcVector& angular
      (
      ) const
   {
      return m_Angular.value();
   }

   /// set angular component
   inline void setAngular
      (
      const EcVector& value
      )
   {
      m_Angular=value;
   }

   /// set the x angular value
   inline void setAngularX
      (
      EcReal value
      )
   {
      m_Angular.value().setX(value);
   }

   /// set the y angular value
   inline void setAngularY
      (
      EcReal value
      )
   {
      m_Angular.value().setY(value);
   }

   /// set the z angular value
   inline void setAngularZ
      (
      EcReal value
      )
   {
      m_Angular.value().setZ(value);
   }

   /// add to the linear component
   inline void addLinear
      (
      const EcVector& value
      )
   {
      m_Linear.value()+=value;
   }

   /// add to the angular component
   inline void addAngular
      (
      const EcVector& value
      )
   {
      m_Angular.value()+=value;
   }

   /// set a value by index (0 - 5)
   /// The linear components are in 0-2 and the angular are in 3-5.
   void setScalarValue
      (
      EcU32 index,
      EcReal value
      );

   /// returns a value by index (0 - 5) - const version.
   /// The linear components are in 0-2 and the angular are in 3-5.
   EcReal operator[]
      (
      EcU32 index
      ) const;

   /// test for approximate equality
   EcBoolean approxEq
      (
      const EcGeneralMotion& xform2,
      EcReal tol
      ) const;

   /// copy into a 6x1 array
   void copyToArray
      (
      EcReArray& array
      ) const;

   /// copy from a 6x1 array
   void copyFromArray
      (
      const EcReArray& array
      );

   /// a (mostly string) token for this class
   virtual const EcToken& token
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

   /// read this object from a binary stream
   EcBoolean readBin
      (
      std::istream& stream
      );

   /// write this object to a binary stream
   EcBoolean writeBin
      (
      std::ostream& stream
      ) const;

   /// get an zero motion
   static const EcGeneralMotion& nullObject
      (
      );

protected:
   /// 3D linear component
   EcXmlVector      m_Linear;

   /// 3D angular component
   EcXmlVector      m_Angular;

   /// a zero value to return by reference
   static const EcGeneralMotion m_theZeroGeneralMotion;
};

/// typedefs for velocity and acceleration:

/// a general velocity
typedef EcGeneralMotion EcGeneralVelocity;

/// a general acceleration
typedef EcGeneralMotion EcGeneralAcceleration;

/// a vector of general velocities
typedef EcXmlVectorType<EcGeneralVelocity> EcGeneralVelocityVector;

/// a vector of general accelerations
typedef EcXmlVectorType<EcGeneralAcceleration> EcGeneralAccelerationVector;


// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// express the general motion in an offset, rotated frame
/// i.e., transforms from the outer to the inner frame
EC_FOUNDATION_FOUNDCOMMON_DECL EcGeneralMotion operator *
   (
   const EcCoordinateSystemTransformation& t,
   const EcGeneralMotion& m
   );

/// express the general motion in a rotated frame
EC_FOUNDATION_FOUNDCOMMON_DECL EcGeneralMotion operator *
   (
   const EcOrientation& q,
   const EcGeneralMotion& m
   );

/// scale the general motion
EC_FOUNDATION_FOUNDCOMMON_DECL EcGeneralMotion operator *
   (
   EcReal s,
   const EcGeneralMotion& m
   );

/// returns the negative of a general force
EC_FOUNDATION_FOUNDCOMMON_DECL EcGeneralMotion  operator -
   (
   const EcGeneralMotion& gm
   );

#endif // ecGeneralMotion_H_
