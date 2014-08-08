#ifndef ecBaseSoftConstraintHandler_H_
#define ecBaseSoftConstraintHandler_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseSoftConstraintHandler.h
/// @class EcBaseSoftConstraintHandler
/// @brief Holds a description of a base soft end-effector
///        constraint handler.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecBaseExpTreeElement.h>

class EcReArray;
class EcControlExpressionContainer;

/// Holds a description of a base soft end-effector constraint handler TODO
class EC_ACTIN_CONTROL_DECL EcBaseSoftConstraintHandler : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcBaseSoftConstraintHandler
      (
      );

   /// destructor
   virtual ~EcBaseSoftConstraintHandler
      (
      );

   /// copy constructor
   EcBaseSoftConstraintHandler
      (
      const EcBaseSoftConstraintHandler& orig
      );

   /// assignment operator
   EcBaseSoftConstraintHandler& operator=
      (
      const EcBaseSoftConstraintHandler& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseSoftConstraintHandler& orig
      ) const;

   /// take the input values and integrate soft-constraint optimization
   /// this method is for use with the primary core
   /// @param[in] matrixIn   (EcReArray&) input matrix TODO
   /// @param[in] vectorIn   (EcReArray&) input vector TODO
   /// @param[in] scalarIn   (EcReArray&) scalar values TODO
   /// @param[in] pContainerIn   (EcControlExpressionContainer*) TODO
   /// @param[out] pMatrixOut   (EcReArray*&) TODO
   /// @param[out] pVectorOut   (EcReArray*&) TODO
   /// @param[out] pScalarOut   (EcReArray*&) TODO
   virtual void integrateSoftConstraints
      (
      const EcReArray& matrixIn,
      const EcReArray& vectorIn,
      const EcReArray& scalarIn,
      const EcControlExpressionContainer* pContainerIn,
      const EcReArray*& pMatrixOut,
      const EcReArray*& pVectorOut,
      const EcReArray*& pScalarOut
      ) const = 0;

   /// take the input values and integrate soft-constraint optimization
   /// this method is for use with the AB core
   /// @param[in] matrixIn   (EcReArray&) input matrix TODO
   /// @param[in] vectorIn   (EcReArray&) input vector TODO
   /// @param[in] scalarIn   (EcReArray&) scalar values TODO
   /// @param[in] pContainerIn   (EcControlExpressionContainer*) TODO
   /// @param[out] pMatrixOut   (EcReArray*&) TODO
   /// @param[out] pVectorOut   (EcReArray*&) TODO
   /// @param[out] pScalarOut   (EcReArray*&) TODO
   virtual void integrateSoftConstraintsAB
      (
      const EcReArray& matrixIn,
      const EcReArray& vectorIn,
      const EcReArray& scalarIn,
      const EcControlExpressionContainer* pContainerIn,
      const EcReArray*& pMatrixOut,
      const EcReArray*& pVectorOut,
      const EcReArray*& pScalarOut
      ) const = 0;
};

#endif // ecBaseSoftConstraintHandler_H_
