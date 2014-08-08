#ifndef ecJacobianTransposeConvergenceTool_H_
#define ecJacobianTransposeConvergenceTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecJacobianTransposeConvergenceTool.h
/// @class EcJacobianTransposeConvergenceTool
/// @brief A convergence tool that uses Jacobian transpose approach
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecJointSolutionConvergenceTool.h"

#include <matrixUtilities/ecReArray.h>


/// Holds a base class for a joint solution finder.
class EC_ACTIN_CONTROL_DECL EcJacobianTransposeConvergenceTool : public EcJointSolutionConvergenceTool
{
public:
   /// default constructor
   EcJacobianTransposeConvergenceTool
      (
      );

   /// destructor
   virtual ~EcJacobianTransposeConvergenceTool
      (
      );

   /// copy constructor
   EcJacobianTransposeConvergenceTool
      (
      const EcJacobianTransposeConvergenceTool& orig
      );

   /// assignment operator
   EcJacobianTransposeConvergenceTool& operator=
      (
      const EcJacobianTransposeConvergenceTool& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcJacobianTransposeConvergenceTool& orig
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

protected:
   /// \copydoc EcJointSolutionConvergenceTool::calculateJointDifferentials()
   virtual void calculateJointDifferentials
      (
      EcManipulatorEndEffectorVelocity& placementDifferentials,
      EcRealVector& jointDifferentials
      ) const;

   // non-XML data below
   mutable EcReArray          m_Jacobian;             ///< the Jacobian
   mutable EcReArray          m_JacobianTranspose;    ///< transpose of the Jacobian
   mutable EcRealVector       m_UtilityVector;        ///< the utility vector
};

#endif // ecJacobianTransposeConvergenceTool_H_
