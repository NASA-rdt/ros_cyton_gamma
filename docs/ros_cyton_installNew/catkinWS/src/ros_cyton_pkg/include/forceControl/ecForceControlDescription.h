#ifndef ecForceControlDescription_H_
#define ecForceControlDescription_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecForceControlDescription.h
/// @class EcForceControlDescription
/// @brief Holds a description of a force control description
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipSensorForce.h"
#include "ecForceControllerVector.h"

#include <foundCommon/ecCoordSysXForm.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

class EcEndEffectorSet;
class EcManipulatorEndEffectorPlacement;
class EcPositionControlSystem;
class EcStatedSystem;
class EcSystemActiveState;

class EC_ACTIN_FORCECONTROL_DECL EcForceControlDescription : public EcXmlCompoundType
{
public:

   /// default constructor
   EcForceControlDescription
      (
      );

   /// destructor
   virtual ~EcForceControlDescription
      (
      );

   /// copy constructor
   EcForceControlDescription
      (
      const EcForceControlDescription& orig
      );

   /// assignment operator
   EcForceControlDescription& operator=
      (
      const EcForceControlDescription& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcForceControlDescription& orig
      ) const;

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

   /// token
   virtual const EcToken& token
      (
      ) const;

   /// reset all the force controllers
   virtual void reset
      (
      );

   /// initialize the force control system with the vector of end-effector sets.
   virtual void initialize
      (
      const EcForceSensorSet& forceSensorSet,
      const EcEndEffectorSet& endEffectorSet
      );

   /// get the label of this control description
   virtual const EcString& label
      (
      ) const;

   /// set the label of this control description
   virtual void setLabel
      (
      const EcString& value
      );

   /// get the vector of force controllers
   virtual const EcForceControllerVector& forceControllers
      (
      ) const;

   /// set the vector of force controllers
   virtual void setForceControllers
      (
      const EcForceControllerVector& value
      );

   /// exchange a force controller with a new one, if the old one exists
   virtual EcBoolean exchange
      (
      EcU32 index,
      const EcBaseForceController& forceController
      );

   /// get whether a given force controller is on
   virtual EcBoolean isOn
      (
      EcU32 index
      ) const;

   /// turn on/off all force controllers
   virtual void setIsOn
      (
      EcBoolean isOn
      );

   /// turn on/off a group of force controllers
   virtual void setIsOn
      (
      const EcU32Vector& indices,
      EcBoolean isOn
      );

   /// turn on/off a group of force controllers
   virtual void setIsOn
      (
      const EcBooleanVector& controllersOn
      );

   /// turn on/off a force controller
   virtual void setIsOn
      (
      EcU32 index,
      EcBoolean isOn
      );


   /// adjust desiredPlacementVec to achieve the desired end-effector forces
   virtual EcBoolean adjustDesiredPlacement
      (
      EcReal deltaTime,
      EcU32 manipIndex,
      const EcManipulatorSensorForce& actualForce,
      const EcManipulatorSensorForce& desiredForce,
      const EcPositionControlSystem& posContSys,
      const EcManipulatorEndEffectorPlacement& actualPlacement,
      EcManipulatorEndEffectorPlacement& desiredPlacement
      ) const;

protected:
   /// the label
   EcXmlString                         m_Label;

   /// the vector of force controllers
   EcForceControllerVector             m_vForceControllers;

   // non-XML data
   /// utility xForm
   mutable EcCoordinateSystemTransformation  m_UtilityXForm;
};

/// vector of EcForceControlDescription
typedef EcXmlVectorType<EcForceControlDescription>        EcForceControlDescriptionVector;

/// vector of EcForceControlDescriptionVector 
typedef EcXmlVectorType<EcForceControlDescriptionVector>  EcForceControlDescriptionVectorVector;

#endif // ecForceControlDescription_H_
