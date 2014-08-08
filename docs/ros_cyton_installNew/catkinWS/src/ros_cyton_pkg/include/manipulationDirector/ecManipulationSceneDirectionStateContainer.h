#ifndef ecManipulationSceneDirectionStateContainer_H_
#define ecManipulationSceneDirectionStateContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationSceneDirectionStateContainer.h
/// @class EcManipulationSceneDirectionStateContainer
/// @brief Container for manipulation scene direction states
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

class EcManipulationSceneDirectionState;

/// Container for manipulation scene direction states
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationSceneDirectionStateContainer :
   public EcXmlVariableElementType<EcManipulationSceneDirectionState>
{
public:
   /// default constructor
   EcManipulationSceneDirectionStateContainer
      (
      );

   /// destructor
   virtual ~EcManipulationSceneDirectionStateContainer
      (
      );

   /// copy constructor
   EcManipulationSceneDirectionStateContainer
      (
      const EcManipulationSceneDirectionStateContainer& orig
      );

   /// assignment operator
   EcManipulationSceneDirectionStateContainer& operator=
      (
      const EcManipulationSceneDirectionStateContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationSceneDirectionStateContainer& orig
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
   static EcManipulationSceneDirectionStateContainer nullObject
      (
      );
};

typedef EcXmlVectorType<EcManipulationSceneDirectionStateContainer>       EcManipulationSceneDirectionStateContainerVector;
typedef EcXmlVectorType<EcManipulationSceneDirectionStateContainerVector> EcManipulationSceneDirectionStateContainerVectorVector;

#endif // ecManipulationSceneDirectionStateContainer_H_
