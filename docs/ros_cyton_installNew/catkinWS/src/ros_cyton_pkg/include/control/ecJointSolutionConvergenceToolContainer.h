#ifndef ecJointSolutionConvergenceToolContainer_H_
#define ecJointSolutionConvergenceToolContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecJointSolutionConvergenceToolContainer.h
/// @class EcJointSolutionConvergenceToolContainer
/// @brief Holds a container for a joint solution convergence tool.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecJointSolutionConvergenceTool.h"
#include <xml/ecXmlVarElemType.h>

/// type definition of XML variable vector of EcJointSolutionConvergenceTool to be used as a base class
typedef EcXmlVariableElementType<EcJointSolutionConvergenceTool> EcBaseJointSolutionConvergenceToolContainer;

/// Holds a container for a convergence tool
class EC_ACTIN_CONTROL_DECL EcJointSolutionConvergenceToolContainer : public EcBaseJointSolutionConvergenceToolContainer
{
public:
   /// default constructor
   EcJointSolutionConvergenceToolContainer
      (
      );

   /// destructor
   virtual ~EcJointSolutionConvergenceToolContainer
      (
      );

   /// copy constructor
   EcJointSolutionConvergenceToolContainer
      (
      const EcJointSolutionConvergenceToolContainer& orig
      );

   /// assignment operator
   EcJointSolutionConvergenceToolContainer& operator=
      (
      const EcJointSolutionConvergenceToolContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcJointSolutionConvergenceToolContainer& orig
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   /**
       \return string token that describes the XML object
   */
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   /**
       \return cloned XML object
   */
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );
};

#endif // ecJointSolutionConvergenceToolContainer_H_
