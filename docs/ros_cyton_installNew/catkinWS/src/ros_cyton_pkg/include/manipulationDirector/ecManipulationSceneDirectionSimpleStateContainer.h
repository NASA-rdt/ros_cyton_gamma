#ifndef ecManipulationSceneDirectionSimpleStateContainer_H_
#define ecManipulationSceneDirectionSimpleStateContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationSceneDirectionSimpleStateContainer.h
/// @class EcManipulationSceneDirectionSimpleStateContainer
/// @brief Container for manipulation scene direction states
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

class EcManipulationSceneDirectionSimpleState;

/// Container for manipulation scene direction states
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationSceneDirectionSimpleStateContainer :
   public EcXmlVariableElementType<EcManipulationSceneDirectionSimpleState>
{
public:
   /// default constructor
   EcManipulationSceneDirectionSimpleStateContainer
      (
      );

   /// destructor
   virtual ~EcManipulationSceneDirectionSimpleStateContainer
      (
      );

   /// copy constructor
   EcManipulationSceneDirectionSimpleStateContainer
      (
      const EcManipulationSceneDirectionSimpleStateContainer& orig
      );

   /// assignment operator
   EcManipulationSceneDirectionSimpleStateContainer& operator=
      (
      const EcManipulationSceneDirectionSimpleStateContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationSceneDirectionSimpleStateContainer& orig
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

   /// null object
   static EcManipulationSceneDirectionSimpleStateContainer nullObject
      (
      );
};

typedef EcXmlVectorType<EcManipulationSceneDirectionSimpleStateContainer>       EcManipulationSceneDirectionSimpleStateContainerVector;
typedef EcXmlVectorType<EcManipulationSceneDirectionSimpleStateContainerVector> EcManipulationSceneDirectionSimpleStateContainerVectorVector;

#endif // ecManipulationSceneDirectionSimpleStateContainer_H_
