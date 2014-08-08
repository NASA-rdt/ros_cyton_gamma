#ifndef ecJointSolutionFinderContainer_H_
#define ecJointSolutionFinderContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecJointSolutionFinderContainer.h
/// @class EcJointSolutionFinderContainer
/// @brief Holds a container for a joint position finder.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecJointSolutionFinder.h"
#include <xml/ecXmlVarElemType.h>

/// type definition of XML variable vector of EcJointSolutionFinder to be used as a base class
typedef EcXmlVariableElementType<EcJointSolutionFinder> EcBaseJointSolutionFinderContainer;

/// Holds a container for a position control system.
class EC_ACTIN_CONTROL_DECL EcJointSolutionFinderContainer : public EcBaseJointSolutionFinderContainer
{
public:
   /// default constructor
   EcJointSolutionFinderContainer
      (
      );

   /// destructor
   virtual ~EcJointSolutionFinderContainer
      (
      );

   /// copy constructor
   EcJointSolutionFinderContainer
      (
      const EcJointSolutionFinderContainer& orig
      );

   /// assignment operator
   EcJointSolutionFinderContainer& operator=
      (
      const EcJointSolutionFinderContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcJointSolutionFinderContainer& orig
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

#include <xml/ecXmlMapType.h>

/// type definition of XML map of EcXmlU32 and EcJointSolutionFinderContainer
typedef EcXmlMapType< EcXmlU32, EcJointSolutionFinderContainer>   EcU32JointSolutionFinderContainerMap;

#endif // ecJointSolutionFinderContainer_H_
