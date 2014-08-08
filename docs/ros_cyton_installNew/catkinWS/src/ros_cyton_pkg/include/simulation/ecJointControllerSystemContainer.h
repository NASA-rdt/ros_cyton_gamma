#ifndef ecJointControllerSystemContainer_H_
#define ecJointControllerSystemContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecJointControllerSystemContainer.h
/// @class EcJointControllerSystemContainer
/// @brief Holds a container for a system-level joint controller.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecBaseJointControllerSys.h"

/// Holds a container for a system-level joint controller.
class EC_ACTIN_SIMULATION_DECL EcJointControllerSystemContainer : public EcBaseExpressionTreeContainer<EcBaseJointControllerSystem>
{
public:
   /// default constructor
   EcJointControllerSystemContainer
      (
      );

   /// destructor
   virtual ~EcJointControllerSystemContainer
      (
      );

   /// copy constructor
   EcJointControllerSystemContainer
      (
      const EcJointControllerSystemContainer& orig
      );

   /// assignment operator
   EcJointControllerSystemContainer& operator=
      (
      const EcJointControllerSystemContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcJointControllerSystemContainer& orig
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// pass-through to EcBaseJointControllerSystem::setSpecifyControlTorqueFlags
   virtual EcBoolean setSpecifyControlTorqueFlags
      (
      const EcBooleanVectorVector& flags
      );

   /// calculates control torques
   virtual void calculateControlTorques
      (
      const EcStatedSystem& statedSystem,
      const EcManipulatorSystemState& desiredState,
      EcManipulatorTorqueVector& manipulatorTorqueVector
      ) const;

   /// calculates control inputs
   virtual void calculateControlInputs
      (
      const EcStatedSystem& statedSystem,
      const EcManipulatorSystemState& desiredState,
      EcManipulatorControlInputVector& manipulatorControlInputVector
      ) const;

   /// merge operation
   virtual EcBoolean mergeWith
      (
      const EcJointControllerSystemContainer& other,
      const EcStatedSystem& otherStatedSystem
      );

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

   /// get a null object
   static EcJointControllerSystemContainer nullObject
      (
      );
};

#endif // ecJointControllerSystemContainer_H_
