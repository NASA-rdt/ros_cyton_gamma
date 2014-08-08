#ifndef ecContExpStrOpt_H_
#define ecContExpStrOpt_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpStrOpt.h
/// @class EcControlExpressionStrengthOptimization
/// @brief This expression returns a vector that will drive joints
///        toward the position of optimal strenght based on the imposed forces.
///        The negative will drive joints toward the weakest position.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include "ecFiniteDifferenceTool.h"
#include "ecManipEndEffectorForce.h"
#include <measure/ecStrOptFunction.h>

/// This expression returns a vector that will drive joints toward a singularity. The negative will drive away from a singularity.
class EC_ACTIN_CONTROL_DECL EcControlExpressionStrengthOptimization : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionStrengthOptimization
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcControlExpressionStrengthOptimization
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionStrengthOptimization
      (
      );

   /// copy constructor
   EcControlExpressionStrengthOptimization
      (
      const EcControlExpressionStrengthOptimization& orig
      );

   /// assignment operator
   EcControlExpressionStrengthOptimization& operator=
      (
      const EcControlExpressionStrengthOptimization& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionStrengthOptimization& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
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

   /// return the value
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// return a token
   virtual const EcToken& token
      (
      ) const;

   /// set end effector forces
   virtual void setManipulatorEndEffectorForces
      (
      const EcManipulatorEndEffectorForce &value
      ) ;

   /// get end effector forces
   virtual const EcManipulatorEndEffectorForce &manipulatorEndEffectorForces
      (
      ) const ;

   /// set order for n-norm optimization
   virtual void setNormOrder
      (
         EcXmlReal value
      ) ;

   /// get order for n-norm optimization
   virtual EcXmlReal normOrder
      (
      ) const ;

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
   static EcControlExpressionStrengthOptimization nullObject
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
   /// sum of Nth norm for optimization
   EcXmlReal m_Nnorm ;

   /// strenght optimization function
   mutable EcStrengthOptimizationFunction m_StrengthOptimizationFunction ;

   /// holds manipulator end effector forces (single frame and point)
   mutable EcManipulatorEndEffectorForce m_ManipulatorEndEffectorForce ;

   /// utility finite-difference tool
   mutable EcFiniteDifferenceTool m_FiniteDifferenceTool;
};

#endif // ecContExpStrOpt_H_
