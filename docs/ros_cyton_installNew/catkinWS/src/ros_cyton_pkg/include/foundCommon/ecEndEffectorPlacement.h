#ifndef ecEndEffectorPlacement_H_
#define ecEndEffectorPlacement_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecEndEffectorPlacement.h
/// @class EcEndEffectorPlacement
/// @brief A description of an end-effector placement
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecCoordSysXForm.h"

/** Holds a class to describe an end-effector placement, which can be either a vector of reals or
    a coordinate system transformation.
*/
class EC_FOUNDATION_FOUNDCOMMON_DECL EcEndEffectorPlacement : public EcXmlCompoundType
{
public:
   /// default constructor
   EcEndEffectorPlacement
      (
      );

   /// constructor to convert EcCoordinateSystemTransformation to this class
   EcEndEffectorPlacement
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// destructor
   ~EcEndEffectorPlacement
      (
      );

   /// copy constructor
   EcEndEffectorPlacement
      (
      const EcEndEffectorPlacement& orig
      );

   /// assignment operator
   EcEndEffectorPlacement& operator=
      (
      const EcEndEffectorPlacement& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcEndEffectorPlacement& orig
      ) const;

   /// convert to EcCoordinateSystemTransformation
   operator EcCoordinateSystemTransformation
      (
      ) const
   {
      return m_CoordSysXForm;
   }

   /// clone - a constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// read the value from an unregistered token
   virtual EcBoolean readValueFromSpecialToken
      (
      const EcToken& token,
      EcXmlReader& stream
      );

   /// equality - equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// a (mostly string) token for this class
   virtual const EcToken& token
     (
     ) const;

   /// get data, which is a vector of reals. This is used for end-effectors whose placements do not
   /// naturally take the form of EcCoordinateSystemTransformation
   inline const EcXmlRealVector& data
      (
      ) const
   {
      return m_Data;
   }

   /// get data -- non-const version
   inline EcXmlRealVector& data
      (
      )
   {
      return m_Data;
   }

   /// set data
   void setData
      (
      const EcXmlRealVector& value
      );

   /// get coordinate system transformation
   inline const EcCoordinateSystemTransformation& coordSysXForm
      (
      ) const
   {
      return m_CoordSysXForm;
   }

   /// get coordinate system transformation -- non-const
   inline EcCoordinateSystemTransformation& coordSysXForm
      (
      )
   {
      return m_CoordSysXForm;
   }

   /// set coordinate system transformation
   void setCoordSysXForm
      (
      const EcCoordinateSystemTransformation& value
      );

   /// interpolation between two placements
   EcBoolean interpolation
      (
      const EcEndEffectorPlacement& placement1,
      const EcEndEffectorPlacement& placement2,
      EcReal factor
      );

   /// test for approximate equality of the placement.
   /// If the size of data in placment2 is not equal to that in this, it will return false.
   /// If the data size is greater than zero, only the equality of data portions will be evaluated and
   /// the method will return true if the data portions of the two are approximately equal.
   /// if the data size is zero, then the coordSysXForm portions will be evaluated.
   EcBoolean approxEq
      (
      const EcEndEffectorPlacement& placement2,
      EcReal tol
      ) const;

   /// get a static const reference
   static const EcEndEffectorPlacement& identity
      (
      );

protected:

   /// the data representation of end-effector placement
   EcXmlRealVector      m_Data;

   /// the spatial placement
   EcCoordinateSystemTransformation       m_CoordSysXForm;

   // non-XML
   /// an identity to return by reference
   static const EcEndEffectorPlacement    m_theIdentity;
};

/// a vector of end-effector placements
typedef EcXmlVectorType<EcEndEffectorPlacement>
   EcEndEffectorPlacementVector;

/// a vector of vectors of end-effector placements
typedef EcXmlVectorType<EcEndEffectorPlacementVector>
   EcEndEffectorPlacementVectorVector;

#endif // ecEndEffectorPlacement_H_
