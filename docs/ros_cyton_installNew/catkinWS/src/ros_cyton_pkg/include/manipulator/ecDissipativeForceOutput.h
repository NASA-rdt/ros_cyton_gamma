#ifndef ecDissipativeForceOutput_H_
#define ecDissipativeForceOutput_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecDissipativeForceOutput.h
/// @class EcDissipativeForceOutput
/// @brief Holds the output data returned from the dissipative force processor
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecCoordSysXForm.h>
#include <foundCommon/ecGeneralForce.h>
#include <foundCommon/ecGeneralMotion.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>

class EcManipulatorLink;

/** Holds the output data returned from the dissipative force processor
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcDissipativeForceOutput : public EcXmlCompoundType
{
public:
   /// default constructor
   EcDissipativeForceOutput
      (
      );

   /// destructor
   virtual ~EcDissipativeForceOutput
      (
      );

   /// copy constructor
   EcDissipativeForceOutput
      (
      const EcDissipativeForceOutput& orig
      );

   /// assignment operator
   EcDissipativeForceOutput& operator=
      (
      const EcDissipativeForceOutput& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDissipativeForceOutput& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// clone
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

   /// get force imposed on body 1 in the primary frame
   virtual const EcGeneralForce& body1ForcePrimary
      (
      )const;

   /// set force imposed on body 1 in the primary frame
   virtual void setBody1ForcePrimary
      (
      const EcGeneralForce& force
      );

   /// get force imposed on body 2 in the primary frame
   virtual const EcGeneralForce& body2ForcePrimary
      (
      )const;

   /// set force imposed on body 2 in the primary frame
   virtual void setBody2ForcePrimary
      (
      const EcGeneralForce& force
      );

   /// get the flag indicating in if the collision is in kinetic/static mode
   virtual const EcBoolean& inStaticFrictionMode
      (
      )const;

   /// set force imposed on body 2 in the primary frame
   virtual void setInStaticFrictionMode
      (
      const EcBoolean& flag
      );

   /// @copydoc EcXmlObject::token()
   virtual const EcToken& token
      (
      ) const;

protected:
   /// flag indicating whether were in static friction mode
   EcBoolean m_InStaticFrictionMode;

   /// force imposed on body1 in the primary frame
   EcGeneralForce m_Body1ForcePrimary;

   /// force imposed on body2 in the primary frame
   EcGeneralForce m_Body2ForcePrimary;
};

#endif // ecDissipativeForceOutput_H_
