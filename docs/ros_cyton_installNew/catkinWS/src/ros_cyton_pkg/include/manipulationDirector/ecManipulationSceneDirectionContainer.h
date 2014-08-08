#ifndef ecManipulationSceneDirectionContainer_H_
#define ecManipulationSceneDirectionContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationSceneDirectionContainer.h
/// @class EcManipulationSceneDirectionContainer
/// @brief Container for manipulation scene directions
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>
#include <xml/ecXmlVectorType.h>

class EcManipulationSceneDirection;

/// Container for manipulation scene directions
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationSceneDirectionContainer :
   public EcXmlVariableElementType<EcManipulationSceneDirection>
{
public:
   /// default constructor
   EcManipulationSceneDirectionContainer
      (
      );

   /// destructor
   virtual ~EcManipulationSceneDirectionContainer
      (
      );

   /// copy constructor
   EcManipulationSceneDirectionContainer
      (
      const EcManipulationSceneDirectionContainer& orig
      );

   /// assignment operator
   EcManipulationSceneDirectionContainer& operator=
      (
      const EcManipulationSceneDirectionContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationSceneDirectionContainer& orig
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
   static EcManipulationSceneDirectionContainer nullObject
      (
      );
};

typedef EcXmlVectorType<EcManipulationSceneDirectionContainer>       EcManipulationSceneDirectionContainerVector;
typedef EcXmlVectorType<EcManipulationSceneDirectionContainerVector> EcManipulationSceneDirectionContainerVectorVector;

#endif // ecManipulationSceneDirectionContainer_H_
