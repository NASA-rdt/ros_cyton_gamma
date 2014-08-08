#ifndef ecBaseControlInputConverter_H_
#define ecBaseControlInputConverter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseControlInputConverter.h
/// @class EcBaseControlInputConverter
/// @brief Holds a base class for a system that converts control torques
///        to control inputs.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <manipulator/ecManipSystem.h>
#include <manipulator/ecManipTorque.h>
#include <xml/ecBaseExpTreeElement.h>
#include "ecManipControlInput.h"
#include "ecManipJointController.h"

// forward declarations
class EcManipulatorSystemState;

/** Holds a base class for a system that converts control torques to control inputs.
*/
class EC_ACTIN_SIMULATION_DECL EcBaseControlInputConverter : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcBaseControlInputConverter
      (
      );

   /// destructor
   virtual ~EcBaseControlInputConverter
      (
      );

   /// copy constructor
   EcBaseControlInputConverter
      (
      const EcBaseControlInputConverter& orig
      );

   /// assignment operator
   EcBaseControlInputConverter& operator=
      (
      const EcBaseControlInputConverter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseControlInputConverter& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const=0;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// set the system pointer
   virtual void setSystemPointer
      (
      const EcManipulatorSystem* systemPointer
      );

   /// calculates control inputs
   virtual void calculateControlInputs
      (
      const EcStatedSystem& statedSystem,
      const EcManipulatorSystemState& desiredState,
      const EcManipulatorTorqueVector& manipulatorTorqueVector,
      EcManipulatorControlInputVector& manipulatorControlInputVector
      ) const=0;

   /// merge with another generic joint controller system
   virtual EcBoolean mergeWith
      (
      const EcBaseControlInputConverter* pOther,
      const EcStatedSystem& otherStatedSystem
      )=0;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

protected:
   /// pointer to the manipulator system
   const EcManipulatorSystem* m_SystemPointer;
};

#endif // ecBaseControlInputConverter_H_
