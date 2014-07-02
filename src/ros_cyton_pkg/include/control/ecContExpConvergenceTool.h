#ifndef ecContExpConvergenceTool_H_
#define ecContExpConvergenceTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpConvergenceTool.h
/// @class EcControlExpressionConvergenceTool
/// @brief A convergence tool that uses control expression approach
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecContExpContainer.h"
#include "ecJointSolutionConvergenceTool.h"

#include <manipulator/ecJacobianState.h>

// forward declarations

/// Holds a base class for a joint solution finder.
class EC_ACTIN_CONTROL_DECL EcControlExpressionConvergenceTool : public EcJointSolutionConvergenceTool
{
public:
   /// default constructor
   EcControlExpressionConvergenceTool
      (
      );

   /// destructor
   virtual ~EcControlExpressionConvergenceTool
      (
      );

   /// copy constructor
   EcControlExpressionConvergenceTool
      (
      const EcControlExpressionConvergenceTool& orig
      );

   /// assignment operator
   EcControlExpressionConvergenceTool& operator=
      (
      const EcControlExpressionConvergenceTool& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionConvergenceTool& orig
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

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// @copydoc EcJointSolutionConvergenceTool::setVelocityController()
   /// @param[in] value (EcVelocityController*) value to set
   virtual void setVelocityController
      (
      const EcVelocityController* value
      );

   /// return a token
   /// @return (EcToken&) The xml token
   virtual const EcToken& token
      (
      ) const;

   /// token for this class
   /// @return (EcToken&) The xml class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The xml object creator
   static EcXmlObject* creator
      (
      );

protected:
   /// @copydoc EcJointSolutionConvergenceTool::calculateJointDifferentials()
   /// @param[in] placementDifferentials   (EcManipulatorEndEffectorVelocity&) TODO
   /// @param[in] jointDifferentials (EcRealVector&) TODO
   virtual void calculateJointDifferentials
      (
      EcManipulatorEndEffectorVelocity& placementDifferentials,
      EcRealVector& jointDifferentials
      ) const;

   /// @copydoc EcJointSolutionConvergenceTool::isConverging()
   /// @return (EcBoolean) TODO
   virtual EcBoolean isConverging
      (
      ) const;

   /// the control expression used in the convergence step
   EcControlExpressionContainer     m_ControlExpressionContainer;
   /// TODO
   mutable EcReal                   m_PrevDifferentialMag;
   /// determinant of the matrix TODO
   mutable EcReal                   m_Determinant;
   /// TODO
   mutable EcReal                   m_PrevDeterminant;
   /// TODO
   mutable EcReArray                m_NullSpace;
   /// TODO
   mutable EcReArray                m_PrevNullSpace;
   /// TODO
   mutable EcReArray                m_UtilityArray;
   /// TODO
   mutable EcJacobianState          m_JacobianState;
   /// TODO
   mutable EcBoolean                m_FirstTime;
};

#endif // ecContExpConvergenceTool_H_
