#ifndef ecContExpCore_H_
#define ecContExpCore_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpCore.h
/// @class EcControlExpressionCore
/// @brief The core velocity control algorithm is represented through
///        this class.  A matrix W, vector F, and scalar S are used to define the
///        control system.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecContExpContainer.h"
#include "ecCoreVelContTool.h"
#include "ecExpElement.h"
#include "ecSoftConstraintHandlerContainer.h"
#include <manipulator/ecManipActPosState.h>

/// The core velocity control algorithm is represented through this class.A matrix W, vector F, and scalar S are used to define the control system.
class EC_ACTIN_CONTROL_DECL EcControlExpressionCore : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionCore
      (
      );

   /// constructor from an EcControlExpressionContainer pointer
   EcControlExpressionCore
      (
      const EcControlExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionCore
      (
      );

   /// copy constructor
   EcControlExpressionCore
      (
      const EcControlExpressionCore& orig
      );

   /// assignment operator
   EcControlExpressionCore& operator=
      (
      const EcControlExpressionCore& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionCore& orig
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
   /// @return The velocity control data
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
   /// @return (EcControlExpressionContainer&)The control expression matrix container
   virtual const EcControlExpressionContainer& matrix
      (
      ) const;

   /// sets the matrix container
   /// @param[in] matrixContainer   (EcControlExpressionContainer&) value to set
   virtual void setMatrixContainer
      (
      const EcControlExpressionContainer& matrixContainer
      );

   /// sets the matrix element
   /// @param[in] matrixElement   (EcExpressionElement&) value to set
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
   /// @return (EcControlExpressionContainer&) The scalar value
   virtual const EcControlExpressionContainer& scalar
      (
      ) const;

   /// sets the scalar container
   /// @param[in] scalarContainer  (EcControlExpressionContainer&) value to set
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
   /// @return (EcSoftConstraintHandlerContainer&) The container for soft constraint handler
   virtual const EcSoftConstraintHandlerContainer& softConstraintHandler
      (
      ) const;

   /// sets the soft-constraint handler container
   /// @param[in] softConstraintHandlerContainer (EcSoftConstraintHandlerContainer&) value to set
   virtual void setSoftConstraintHandler
      (
      const EcSoftConstraintHandlerContainer& softConstraintHandlerContainer
      );

   /// sets the soft-constraint handler
   /// @param[in] softConstraintHandler (EcBaseSoftConstraintHandler&) The soft-constraint handler
   virtual void setSoftConstraintHandler
      (
      const EcBaseSoftConstraintHandler& softConstraintHandler
      );

   /// return a token
   /// @return (EcToken&) The xml token
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   /// @param[in] stream (EcXmlReader&) Stream to be read
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /// @param[in] stream (EcXmlWriter&) Xml stream to be writtern into file
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   /// @return (EcControlExpressionCore) The null object
   static EcControlExpressionCore nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The xml token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The xml object
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

   /// the matrix (W) parameter
   EcControlExpressionContainer  m_Matrix;

   /// the vector (F) parameter
   EcControlExpressionContainer  m_Vector;

   /// the scalar (S) parameter
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
};

#endif // ecContExpCore_H_
