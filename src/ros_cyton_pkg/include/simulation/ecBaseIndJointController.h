#ifndef ecBaseIndJointController_H_
#define ecBaseIndJointController_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseIndJointController.h
/// @class EcBaseIndividualJointController
/// @brief Base class for a controller for a single joint.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlBasicType.h>

/// Holds a description of a feedback controller for a single joint.
class EC_ACTIN_SIMULATION_DECL EcBaseIndividualJointController : public EcXmlCompoundType
{
public:
   /// default constructor
   EcBaseIndividualJointController
      (
      );

   /// destructor
   virtual ~EcBaseIndividualJointController
      (
      );

   /// copy constructor
   EcBaseIndividualJointController
      (
      const EcBaseIndividualJointController& orig
      );

   /// assignment operator
   EcBaseIndividualJointController& operator=
      (
      const EcBaseIndividualJointController& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseIndividualJointController& orig
      ) const;

   /// \copydoc EcBaseExpressionTreeElement::registerComponents()
   virtual void registerComponents
      (
      );

   /// gets on/off flag
   virtual EcBoolean isOn
      (
      ) const;

   /// sets the on/off flag
   virtual void setIsOn
      (
      EcBoolean isOn
      );

   /// gets direct control flag. If this is true, then the value returned by control() method is
   /// supposed to be used directly as control torque/force. In some circumstances, it can be used
   /// in other purposes (such as in feed-forward controller).
   virtual EcBoolean directControl
      (
      ) const;

   /// sets direct control flag
   virtual void setDirectControl
      (
      EcBoolean value
      );

   /// calculates the control torque/force
   virtual EcReal control
      (
      EcReal actualPosition,
      EcReal desiredPosition,
      EcReal actualVelocity,
      EcReal desiredVelocity=0.0,
      EcReal extraneousInput=0.0
      ) const = 0;

protected:
   
   EcXmlBoolean         m_IsOn;              ///< On/Off Flag for the controller 
   EcXmlBoolean         m_DirectControl;     ///< The direct control flag
};

#endif // ecBaseIndJointController_H_
