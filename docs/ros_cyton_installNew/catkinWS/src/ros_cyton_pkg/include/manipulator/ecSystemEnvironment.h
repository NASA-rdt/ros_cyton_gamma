#ifndef ecSystemEnvironment_H_
#define ecSystemEnvironment_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemEnvironment.h
/// @class EcSystemEnvironment
/// @brief The manipulator system environment.  Includes a gravity
///        vector and a coordinate transformation that gives a
///        system coordinates system with respect to the universal
///        coordinate system.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVector.h>
#include <geometry/ecBasePhysicalExtent.h>

/// Holds a description of a manipulator system environment.
/** This includes the gravity vector and a transformation from a universal frame
 to the system frame.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcSystemEnvironment : public EcXmlCompoundType
{
public:
   /// default constructor
   EcSystemEnvironment
      (
      );

   /// destructor
   virtual ~EcSystemEnvironment
      (
      );

   /// copy constructor
   EcSystemEnvironment
      (
      const EcSystemEnvironment& orig
      );

   /// assignment operator
   EcSystemEnvironment& operator=
      (
      const EcSystemEnvironment& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemEnvironment& orig
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

   /// gets coordinate system transformation
   virtual const EcCoordinateSystemTransformation& coordSysXForm
      (
      ) const;

   /// sets coordinate system transformation
   virtual void setCoordSysXForm
      (
      const EcCoordinateSystemTransformation& coordSysXForm
      );

   /// gets upward pointing gravity vector
   virtual const EcVector& upGravityVector
      (
      ) const;

   /// sets upward pointing gravity vector
   virtual void setUpGravityVector
      (
      const EcVector& gravityVector
      );

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

   /// gets a null link
   static EcSystemEnvironment nullObject
      (
      );

protected:
   /// the transformation from the universal to the system frame
   EcCoordinateSystemTransformation   m_CoordSysXForm;

   /// the acceleration due to gravity in the up direction
   /// (in the system frame)
   EcXmlVector                        m_UpGravityVector;
};

#endif // ecSystemEnvironment_H_
