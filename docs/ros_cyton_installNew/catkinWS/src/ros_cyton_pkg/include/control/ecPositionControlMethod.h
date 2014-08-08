#ifndef ecPositionControlMethod_H_
#define ecPositionControlMethod_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecPositionControlMethod.h
/// @class EcPositionControlMethod
/// @brief Holds a description of a position control method
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlCompType.h>

// forward declarations
class EcPositionController;

/// Holds a description of a position control method
class EC_ACTIN_CONTROL_DECL EcPositionControlMethod : public EcXmlCompoundType
{
public:
   /// default constructor
   EcPositionControlMethod
      (
      );

   /// destructor
   virtual ~EcPositionControlMethod
      (
      );

   /// copy constructor
   EcPositionControlMethod
      (
      const EcPositionControlMethod& orig
      );

   /// assignment operator
   EcPositionControlMethod& operator=
      (
      const EcPositionControlMethod& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPositionControlMethod& orig
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

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// sets the pointer to the position controller assoicated with this control method
   virtual void setPositionController
      (
      EcPositionController* value
      );

   /// return a token
   virtual const EcToken& token
      (
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

   /// perform steps before the calculateState is called
   virtual void preCalculateStateCondition
      (
      );

   /// perform steps after the calculateState is called
   virtual void postCalculateStateCondition
      (
      );

   /// calculate the velocity state
   virtual void calculateVelocityState
      (
      );

   /// connect components
   virtual void connectComponents
      (
      );

   /// return whether the controller is converging towards the desired end-effector placement
   virtual EcBoolean isConverging
      (
      ) const;

   /// reset convergence test
   virtual void resetConvergenceTest
      (
      ) const;

protected:
   /// pointer to the position controller assoicated with this control method
   EcPositionController*   m_pController;

   // the following two data are used to determine convergence
   mutable EcU8       m_NumCyclesStart;  ///< number of cycles of it moving before we consider the robot to actually start a motion towards goal
   mutable EcU8       m_NumCyclesStop;   ///< number of cycles of it not moving before we consider the robot to actually stop and therefore not converging
};

#endif // ecPositionControlMethod_H_
