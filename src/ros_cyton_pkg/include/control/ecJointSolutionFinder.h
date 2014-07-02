#ifndef ecJointSolutionFinder_H_
#define ecJointSolutionFinder_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecJointSolutionFinder.h
/// @class EcJointSolutionFinder
/// @brief A base class for a joint solution finder
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecJointSolutionConvergenceToolContainer.h"

#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVectorType.h>

// forward declarations
class EcManipulatorActiveState;
class EcManipulatorEndEffectorPlacement;
class EcPositionState;
class EcVelocityController;

/// Holds a base class for a joint solution finder.
class EC_ACTIN_CONTROL_DECL EcJointSolutionFinder : public EcXmlCompoundType
{
public:
   /// default constructor
   EcJointSolutionFinder
      (
      );

   /// destructor
   virtual ~EcJointSolutionFinder
      (
      );

   /// copy constructor
   EcJointSolutionFinder
      (
      const EcJointSolutionFinder& orig
      );

   /// assignment operator
   EcJointSolutionFinder& operator=
      (
      const EcJointSolutionFinder& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcJointSolutionFinder& orig
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// sets the pointer to the velocity controller to be used in this solution finder
   virtual void setVelocityController
      (
      const EcVelocityController* value
      );

   /// gets the convergence tool container
   virtual const EcJointSolutionConvergenceToolContainer& convergenceToolContainer
      (
      );

   /// sets the convergernce tool container
   virtual void setConvergenceToolContainer
      (
      const EcJointSolutionConvergenceToolContainer& value
      );

   /// sets the convergernce tool
   virtual void setConvergenceTool
      (
      const EcJointSolutionConvergenceTool& value
      );

   /// sets the indices of joints contained in the joint EE
   virtual void setJointEndEffectorIndices
      (
      const EcU32Vector& value
      );

   /// find a joint solution for a given goal placement and the current state. A valid solution must have each of the actual EE placement within
   /// the tolerance of the desired EE placement (using EE's own difference method).
   virtual EcBoolean findSolution
      (
      const EcPositionState& currentState,
      const EcManipulatorEndEffectorPlacement& goal,
      EcXmlRealVector& solution
      ) const=0;

protected:
   /// the joint solution convergence tool container
   EcJointSolutionConvergenceToolContainer   m_ConvergenceToolContainer;

   // non-XML data below
   /// pointer to the velocity controller
   const EcVelocityController*      m_pVelocityController;
   /// Indices of joints contained in the joint EE used in coordinated control
   EcU32Vector                      m_JointEeIndices;          
};

#endif // ecJointSolutionFinder_H_
