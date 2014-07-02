#ifndef ecContactRegion_H_
#define ecContactRegion_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecContactRegion.h
/// @class EcContactRegion
/// @brief Holds a description of a region of contact for a body.
///        It includes a  frame with its origin at the center of contact, with
///        z in the outward direction normal to the contact surface.  x and y
///        are the direction of the primary components of the second moment of
///        the contact surface.  The principal moments are included for x, y,
///        and z.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <geometry/ecPlane.h>

/// Holds a description of a region of contact for a body.
/** It includes a
 frame with its origin at the center of contact, with z in the outward direction
 normal to the contact surface.  x and y are the direction of the primary
 components of the second moment of the contact surface.  The principal
 moments are included for x, y, and z.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcContactRegion : public EcXmlCompoundType
{
public:
   /// default constructor
   EcContactRegion
      (
      );

   /// destructor
   virtual ~EcContactRegion
      (
      );

   /// copy constructor
   EcContactRegion
      (
      const EcContactRegion& orig
      );

   /// assignment operator
   EcContactRegion& operator=
      (
      const EcContactRegion& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcContactRegion& orig
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

   /// rotation.  Returns the transformed entity
   virtual const EcContactRegion& transformBy
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// get the contact frame
   virtual const EcCoordinateSystemTransformation& contactFrame
      (
      ) const;

   /// set the contact frame
   virtual void setContactFrame
      (
      const EcCoordinateSystemTransformation& contactFrame
      );

   /// set the contact frame translation
   virtual void setContactFrameTranslation
      (
      const EcVector& translation
      );

   /// set the contact frame orientation
   virtual void setContactFrameOrientation
      (
      const EcOrientation& orientation
      );

   /// get the perimeter moment along x
   virtual EcReal momentX
      (
      ) const;

   /// set the perimeter moment along x
   virtual void setMomentX
      (
      EcReal momentX
      );

   /// get the perimeter moment along y
   virtual EcReal momentY
      (
      ) const;

   /// set the perimeter moment along y
   virtual void setMomentY
      (
      EcReal momentY
      );

   /// get the perimeter moment along z
   virtual EcReal momentZ
      (
      ) const;

   /// set the perimeter moment along z
   virtual void setMomentZ
      (
      EcReal momentZ
      );

   /// get the principal plane
   /// (point at contact frame origin, normal along z)
   virtual EcPlane principalPlane
      (
      ) const;

   /// tests for approximate equality
   virtual EcBoolean approxEq
      (
      const EcContactRegion& sm2,
      EcReal tol
      ) const;

   /// @copydoc EcXmlObject::token()
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
   static EcContactRegion nullObject
      (
      );

protected:

   /// frame with z normal to the surface and
   /// x and y along the principal components,
   /// located at the center of contact.
   EcCoordinateSystemTransformation m_ContactFrame;

   /// perimeter moment along x in the contact frame
   EcXmlReal m_MomentX;

   /// perimeter moment along y in the contact frame
   EcXmlReal m_MomentY;

   /// perimeter moment along z in the contact frame
   EcXmlReal m_MomentZ;
};

#endif // ecContactRegion_H_
