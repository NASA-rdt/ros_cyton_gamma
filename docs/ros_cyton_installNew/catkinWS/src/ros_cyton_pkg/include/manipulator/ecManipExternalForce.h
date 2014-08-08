#ifndef ecManipExternalForce_H_
#define ecManipExternalForce_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipExternalForce.h
/// @class EcManipulatorExternalForce
/// @brief Holds a description of the external forces and moments
///        applied to a manipulator.  This includes a general force on each
///        link and a general force on the base.  The general forces are
///        represented in local coordinates.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecGeneralForce.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/// Holds a description of the external forces and moments applied to a manipulator.
/** This includes a general force on each link and a general force on the base.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorExternalForce : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorExternalForce
      (
      );

   /// destructor
   virtual ~EcManipulatorExternalForce
      (
      );

   /// copy constructor
   EcManipulatorExternalForce
      (
      const EcManipulatorExternalForce& orig
      );

   /// assignment operator
   EcManipulatorExternalForce& operator=
      (
      const EcManipulatorExternalForce& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorExternalForce& orig
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

   /// gets general force
   virtual const EcGeneralForceVector& linkForces
      (
      ) const;

   /// sets general force
   virtual void setLinkForces
      (
      const EcGeneralForceVector& linkForces
      );

   /// gets base force
   virtual const EcGeneralForce& baseForce
      (
      ) const;

   /// sets base force
   virtual void setBaseForce
      (
      const EcGeneralForce& baseForce
      );

   /// returns a value by index - const
   virtual const EcGeneralForce& operator[]
      (
      EcU32 index
      ) const;

   /// returns a value by index - nonconst
   virtual EcGeneralForce& operator[]
      (
      EcU32 index
      );

   /// resize the link-force vector
   virtual void resize
      (
      EcU32 size
      );

   /// set all forces and moments to zero
   virtual void setToZeros
      (
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
   static EcManipulatorExternalForce nullObject
      (
      );

protected:
   /// the vector of general forces on the links other than the base
   EcGeneralForceVector        m_LinkGeneralForces;

   /// the general force of the base
   EcGeneralForce              m_BaseGeneralForce;

   /// the null general force used for error recovery
   static const EcGeneralForce m_theNullGeneralForce;
};

/// a vector of manipulator torques
typedef EcXmlVectorType<EcManipulatorExternalForce>
   EcManipulatorExternalForceVector;

#endif // ecManipExternalForce_H_
