#ifndef ecGeneralForce_H_
#define ecGeneralForce_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecGeneralForce.h
/// @class EcGeneralForce
/// @brief A class describing generalized force.  It is
///        composed of 3D force and moment vectors.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVector.h>

class EcCoordinateSystemTransformation;
class EcOrientation;
class EcReArray;

/** Holds a description 3D force and moment pair.  A single point of
application is implied.
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcGeneralForce : public EcXmlCompoundType
{
public:
   /// default constructor
   EcGeneralForce
      (
      );

   /// constructor with a linear and angular component
   EcGeneralForce
      (
      const EcVector& linear,
      const EcVector& angular
      );

   /// destructor
   ~EcGeneralForce
      (
      );

   /// copy constructor
   EcGeneralForce
      (
      const EcGeneralForce& orig
      );

   /// assignment operator
   EcGeneralForce& operator=
      (
      const EcGeneralForce& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGeneralForce& orig
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

   /// add this general force to another and set this to the result.
   EcGeneralForce& operator+=
      (
      const EcGeneralForce& v2
      );

   /// subtract another general force from this and set this to the result.
   EcGeneralForce& operator-=
      (
      const EcGeneralForce& v2
      );

   /// add this general force to another and return the value.
   EcGeneralForce  operator+
      (
      const EcGeneralForce& v2
      ) const;

   /// subtract another general force from this and return the value.
   EcGeneralForce  operator-
      (
      const EcGeneralForce& v2
      ) const;

   /// scale the general force
   EcGeneralForce operator*
      (
      const EcReal& s
      ) const;

   /// scalar in place
   EcGeneralForce& operator*=
      (
      EcReal factor
      );

   /// general transformation.  Returns the transformed entity.
   EcGeneralForce& transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// rotation.  Returns the transformed entity
   EcGeneralForce& transformBy
      (
      const EcOrientation& orientatation
      );

   /// offset.  Returns the transformed entity
   EcGeneralForce& transformBy
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

   /// returns a value by index (0 - 5 ) - const version.
   /// The linear components are in 0-2 and the angular are in 3-5.
   EcReal operator[]
      (
      EcU32 index
      ) const;

   /// test for approximate equality
   EcBoolean approxEq
      (
      const EcGeneralForce& xform2,
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

   /// set both the linear and angular components
   /// to all zeros
   void setToZero
      (
      );

   /// get an zero force (as a reference to a static const member)
   static const EcGeneralForce& nullObject
      (
      );

protected:
   /// the linear component
   EcXmlVector      m_Linear;

   /// the angular component
   EcXmlVector      m_Angular;

   /// a zero value to return by reference
   static const EcGeneralForce m_theZeroGeneralForce;
};

/// a vector of general forces
typedef EcXmlVectorType<EcGeneralForce> EcGeneralForceVector;

/// a vector of vectors of general forces
typedef EcXmlVectorType<EcGeneralForceVector> EcGeneralForceVectorVector;

// -----------------------------------------------
// extra operators below
// -----------------------------------------------

/// expresses the general force in an offset, rotated frame
EC_FOUNDATION_FOUNDCOMMON_DECL EcGeneralForce operator *
   (
   const EcCoordinateSystemTransformation& xf,
   const EcGeneralForce& m
   );

/// expresses the general force in a rotated frame
EC_FOUNDATION_FOUNDCOMMON_DECL EcGeneralForce operator *
   (
   const EcOrientation& q,
   const EcGeneralForce& m
   );

/// returns the negative of a general force
EC_FOUNDATION_FOUNDCOMMON_DECL EcGeneralForce  operator -
   (
   const EcGeneralForce& gf
   );

#endif // ecGeneralForce_H_
