#ifndef ecManipControlInput_H_
#define ecManipControlInput_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipControlInput.h
/// @class EcManipulatorControlInput
/// @brief Holds a description of the control inputs
///        applied to a manipulator.  This includes the joint control inputs
///        and the general input applied to the base.  The base control input is
///        represented in local DH coordinates.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCommon/ecGeneralForce.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

/// Holds a description of the control inputs applied to a manipulator.
/** This includes the joint control inputs and the general input applied to the base.
*/
class EC_ACTIN_SIMULATION_DECL EcManipulatorControlInput : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulatorControlInput
      (
      );

   /// destructor
   virtual ~EcManipulatorControlInput
      (
      );

   /// copy constructor
   EcManipulatorControlInput
      (
      const EcManipulatorControlInput& orig
      );

   /// assignment operator
   EcManipulatorControlInput& operator=
      (
      const EcManipulatorControlInput& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulatorControlInput& orig
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
   virtual const EcXmlRealVector& jointControlInputs
      (
      ) const;

   /// gets joint torques/forces - nonconst version
   virtual EcXmlRealVector& jointControlInputs
      (
      );

   /// sets joint torques/forces
   virtual void setJointControlInputs
      (
      const EcXmlRealVector& jointControlInputs
      );

   /// sets joint torques/forces from an EcReArray
   virtual void setJointControlInputs
      (
      const EcReArray& jointControlInputs
      );

   /// gets general force - const version
   virtual const EcGeneralForce& generalControlInput
      (
      ) const;

   /// gets general force - nonconst version
   virtual EcGeneralForce& generalControlInput
      (
      );

   /// sets general force
   virtual void setGeneralControlInput
      (
      const EcGeneralForce& generalControlInput
      );

   /// gets the xml token used for writing out
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
   static EcManipulatorControlInput nullObject
      (
      );

protected:
   /// the vector of joint control inputs
   EcXmlRealVector     m_JointControlInputs;

   /// the general input of the base
   EcGeneralForce      m_GeneralControlInput;
};

/// a vector of manipulator control inputs
typedef EcXmlVectorType<EcManipulatorControlInput> EcManipulatorControlInputVector;

#endif // ecManipControlInput_H_
