#ifndef ecIndJointControllerContainer_H_
#define ecIndJointControllerContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecIndJointControllerContainer.h
/// @class EcIndividualJointControllerContainer
/// @brief Holds a container for a joint position finder.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseIndJointController.h"
#include <xml/ecXmlVarElemType.h>

/// type definition of EcBaseIndividualJointControllerContainer
typedef EcXmlVariableElementType<EcBaseIndividualJointController> EcBaseIndividualJointControllerContainer;

/// Holds a container for a position control system.
class EC_ACTIN_SIMULATION_DECL EcIndividualJointControllerContainer : public EcBaseIndividualJointControllerContainer
{
public:
   /// default constructor
   EcIndividualJointControllerContainer
      (
      );

   /// destructor
   virtual ~EcIndividualJointControllerContainer
      (
      );

   /// copy constructor
   EcIndividualJointControllerContainer
      (
      const EcIndividualJointControllerContainer& orig
      );

   /// assignment operator
   EcIndividualJointControllerContainer& operator=
      (
      const EcIndividualJointControllerContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcIndividualJointControllerContainer& orig
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
/// type definition of EcStringIndividualJointControllerContainerMap
typedef EcXmlMapType< EcXmlString, EcIndividualJointControllerContainer >   EcStringIndividualJointControllerContainerMap;

#endif // ecIndJointControllerContainer_H_
