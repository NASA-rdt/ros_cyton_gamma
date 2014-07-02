#ifndef ecManipTorque_H_
#define ecManipTorque_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipTorque.h
/// @class EcManipulatorTorque
/// @brief Holds a description of the intrisic torques/forces
///        applied to a manipulator.  This includes the joint torques/forces
///        and the general force applied to the base.  The base force is
///        represented in local DH coordinates.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecGeneralForce.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/// Holds a description of the intrisic torques/forces applied to a manipulator.
/** This includes the joint torques/forces and the general force applied to the base.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcManipulatorTorque : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorTorque
      (
      );

   /// destructor
   virtual ~EcManipulatorTorque
      (
      );

   /// copy constructor
   EcManipulatorTorque
      (
      const EcManipulatorTorque& orig
      );

   /// assignment operator
   EcManipulatorTorque& operator=
      (
      const EcManipulatorTorque& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorTorque& orig
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

   /// gets joint torques/forces - const version
   virtual const EcXmlRealVector& jointTorques
      (
      ) const;

   /// gets joint torques/forces - nonconst version
   virtual EcXmlRealVector& jointTorques
      (
      );

   /// sets joint torques/forces
   virtual void setJointTorques
      (
      const EcXmlRealVector& jointTorques
      );

   /// sets joint torques/forces from an EcReArray
   virtual void setJointTorques
      (
      const EcReArray& jointTorques
      );

   /// gets general force - const version
   virtual const EcGeneralForce& generalForce
      (
      ) const;

   /// gets general force - nonconst version
   virtual EcGeneralForce& generalForce
      (
      );

   /// sets general force
   virtual void setGeneralForce
      (
      const EcGeneralForce& generalForce
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
   static const EcManipulatorTorque& nullObject
      (
      );

protected:
   /// the vector of joint velocities
   EcXmlRealVector     m_JointTorques;

   /// the general velocity of the base
   EcGeneralForce      m_GeneralForce;

   /// an empty object
   static const EcManipulatorTorque m_theNullManipulatorTorque;
};

/// a vector of manipulator torques
typedef EcXmlVectorType<EcManipulatorTorque> EcManipulatorTorqueVector;

#endif // ecManipTorque_H_
