#ifndef ecDirectionConditionContainer_H_
#define ecDirectionConditionContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecDirectionConditionContainer.h
/// @class EcDirectionConditionContainer
/// @brief Container for direction conditions
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>
#include <xml/ecXmlVectorType.h>

// Forward declarations
class EcDirectionCondition;
class EcManipulationDirector;
class EcManipulationDirectorState;
class EcManipulationDirectorUpdateParams;

/// Container for direction conditions
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcDirectionConditionContainer :
   public EcXmlVariableElementType<EcDirectionCondition>
{
public:
   /// default constructor
   EcDirectionConditionContainer
      (
      );

   /// destructor
   virtual ~EcDirectionConditionContainer
      (
      );

   /// copy constructor
   EcDirectionConditionContainer
      (
      const EcDirectionConditionContainer& orig
      );

   /// assignment operator
   EcDirectionConditionContainer& operator=
      (
      const EcDirectionConditionContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDirectionConditionContainer& orig
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
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// get a vector of role names that are referenced within this condition container
   virtual EcStringVector roleNames
      (
      const EcManipulationDirector& director
      ) const;

   /// test the condition container
   virtual EcBoolean test
      (
      const EcManipulationDirector&             director,
      const EcManipulationDirectorUpdateParams& params,
      const EcString&                           role,
      const EcManipulationDirectorState&        dstate
      ) const;

   /// return a text description of the condition container
   virtual EcString text
      (
      ) const;

   /// null object
   static EcDirectionConditionContainer nullObject
      (
      );
};

typedef EcXmlVectorType<EcDirectionConditionContainer> EcDirectionConditionContainerVector;

#endif // ecDirectionConditionContainer_H_
