#ifndef ecContExpAbCore_H_
#define ecContExpAbCore_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpAbCore.h
/// @class EcControlExpressionABCore
/// @brief The core velocity control algorithm is represented through
///        this class.  A matrix A, vector B, and scalar S are used to define the
///        control system.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecContExpContainer.h"
#include "ecCoreVelContTool.h"
#include "ecExpElement.h"
#include "ecSoftConstraintHandlerContainer.h"
#include "ecJacobianTool.h"

class EC_ACTIN_CONTROL_DECL EcControlExpressionABCore : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionABCore
      (
      );

   /// constructor from an EcControlExpressionContainer pointer
   /// @param[in] containerPointer (EcControlExpressionContainer*) TODO
   EcControlExpressionABCore
      (
      const EcControlExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionABCore
      (
      );

   /// copy constructor
   EcControlExpressionABCore
      (
      const EcControlExpressionABCore& orig
      );

   /// assignment operator
   /// @param[in] orig   (EcControlExpressionABCore&) control expression object
   EcControlExpressionABCore& operator=
      (
      const EcControlExpressionABCore& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionABCore& orig
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
   /// @return (EcVelocityControlData&) The velocity control data
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// sets the container
   /// @param[in] container (EcXmlBaseVariableCompoundType*) value to set
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// gets the matrix
   /// @return matrix (EcControlExpressionContainer&) TODO
   virtual const EcControlExpressionContainer& matrix
      (
      ) const;

   /// sets the matrix container
   /// @param[in] matrixContainer (EcControlExpressionContainer&) value to set
   virtual void setMatrixContainer
      (
      const EcControlExpressionContainer& matrixContainer
      );

   /// sets the matrix element
   /// @param[in] matrixElement (EcExpressionElement&) value to set
   virtual void setMatrixElement
      (
      const EcExpressionElement& matrixElement
      );

   /// gets the vector
   /// @return (EcControlExpressionContainer&) The control expression container
   virtual const EcControlExpressionContainer& vector
      (
      ) const;

   /// sets the vector container
   /// @param[in] vectorContainer (EcControlExpressionContainer&) value to set
   virtual void setVectorContainer
      (
      const EcControlExpressionContainer& vectorContainer
      );

   /// sets the vector element
   /// @param[in] vectorElement (EcExpressionElement&) value to set
   virtual void setVectorElement
      (
      const EcExpressionElement& vectorElement
      );

   /// gets the scalar
   /// @return The scalar component
   virtual const EcControlExpressionContainer& scalar
      (
      ) const;

   /// sets the scalar container
   ///  @param[in] scalarContainer (EcControlExpressionContainer&) value to set
   virtual void setScalarContainer
      (
      const EcControlExpressionContainer& scalarContainer
      );

   /// sets the scalar element
   /// @param[in] scalarElement (EcExpressionElement&) value to set
   virtual void setScalarElement
      (
      const EcExpressionElement& scalarElement
      );

   /// gets the soft-constraint handler container
   /// @return (EcSoftConstraintHandlerContainer&) The soft constraint handler container
   virtual const EcSoftConstraintHandlerContainer& softConstraintHandler
      (
      ) const;

   /// sets the soft-constraint handler container
   /// @param[in] softConstraintHandlerContainer   (EcSoftConstraintHandlerContainer&) value to set
   virtual void setSoftConstraintHandler
      (
      const EcSoftConstraintHandlerContainer& softConstraintHandlerContainer
      );

   /// sets the soft-constraint handler
   virtual void setSoftConstraintHandler
      (
      const EcBaseSoftConstraintHandler& softConstraintHandler
      );

   /// return a token
   /// @return const EcToken& The token
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   /// @param[in] stream (EcXmlReader&) stream to be read from the xml file
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /// @param[in] stream (EcXmlWriter&) stream to be written into the xml file
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   /// @return (EcControlExpressionABCore) The null object
   static EcControlExpressionABCore nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) the creator object
   static EcXmlObject* creator
      (
      );

protected:
   /// calculates the rates
   /// @param[in] array (EcVelocityControlData&) TODO
   virtual void calculateJointRates
      (
      EcVelocityControlData& array
      ) const;

   /// the matrix (A=Nj^T W) parameter
   EcControlExpressionContainer  m_Matrix;

   /// the vector (B=Nj^T F) parameter
   EcControlExpressionContainer  m_Vector;

   /// the scalar (S = alpha) parameter
   EcControlExpressionContainer  m_Scalar;

   /// the soft-constraint handler container
   EcSoftConstraintHandlerContainer m_SoftConstraintHandler;

   /// utility velocity control tool
   mutable EcCoreVelocityControlTool m_VelContTool;

   /// utility vector to hold the vector
   mutable EcRealVector m_UtilityLinearVector;

   /// utility vector to hold the joint rates
   mutable EcRealVector m_UtilityJointRateVector;

   /// utility vector to hold the null-space component
   mutable EcRealVector m_UtilityNullSpaceComponent;

   /// utility hand-motion vector
   mutable EcRealVector m_UtilityHandMotion;

   /// utility active position state for recovery
   mutable EcManipulatorActivePositionState m_UtilityManipulatorActivePositionState;

   /// utility Jacobian tool
   mutable EcJacobianTool m_JacobianTool;
};

#endif // ecContExpAbCore_H_
