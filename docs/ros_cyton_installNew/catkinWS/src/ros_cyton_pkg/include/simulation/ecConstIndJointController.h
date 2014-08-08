#ifndef ecConstIndJointController_H_
#define ecConstIndJointController_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecConstIndJointController.h
/// @class EcConstantIndividualJointController
/// @brief Holds a description of a constant controller for a single joint.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseIndJointController.h"

/// Holds a description of a feedback controller for a single joint.
class EC_ACTIN_SIMULATION_DECL EcConstantIndividualJointController : public EcBaseIndividualJointController
{
public:
   /// default constructor
   EcConstantIndividualJointController
      (
      );

   /// destructor
   virtual ~EcConstantIndividualJointController
      (
      );

   /// copy constructor
   EcConstantIndividualJointController
      (
      const EcConstantIndividualJointController& orig
      );

   /// assignment operator
   EcConstantIndividualJointController& operator=
      (
      const EcConstantIndividualJointController& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcConstantIndividualJointController& orig
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

   /// gets the constant
   virtual EcReal constant
      (
      ) const;

   /// sets the constant
   virtual void setConstant
      (
      EcReal value
      );

   /// calculates the control torque/force
   virtual EcReal control
      (
      EcReal actualPosition,
      EcReal desiredPosition,
      EcReal actualVelocity,
      EcReal desiredVelocity=0.0,
      EcReal extraneousInput=0.0
      ) const;

   /// gets the xml token used for writing out.
   virtual const EcToken& token
      (
      ) const;

   /// get a null object
   static EcConstantIndividualJointController nullObject
      (
      );

   /// create an object with default values
   static EcConstantIndividualJointController defaultObject
      (
      );


   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// the control parameters
   EcXmlReal             m_Constant;
};

#endif // ecConstIndJointController_H_
