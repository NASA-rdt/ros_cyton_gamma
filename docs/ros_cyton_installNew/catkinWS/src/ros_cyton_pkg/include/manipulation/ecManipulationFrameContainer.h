#ifndef ecManipulationFrameContainer_H_
#define ecManipulationFrameContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationFrameContainer.h
/// @class EcManipulationFrameContainer
/// @brief Container for manipulation frames
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

class EcManipulationFrame;

/// Container for manipulation frames
class EC_ACTIN_MANIPULATION_DECL EcManipulationFrameContainer :
   public EcXmlVariableElementType<EcManipulationFrame>
{
public:
   /// default constructor
   EcManipulationFrameContainer
      (
      );

   /// destructor
   virtual ~EcManipulationFrameContainer
      (
      );

   /// copy constructor
   EcManipulationFrameContainer
      (
      const EcManipulationFrameContainer& orig
      );

   /// assignment operator
   EcManipulationFrameContainer& operator=
      (
      const EcManipulationFrameContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationFrameContainer& orig
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
   static EcManipulationFrameContainer nullObject
      (
      );
};

/// type definition of EcManipulationFrameContainerVector
typedef EcXmlVectorType<EcManipulationFrameContainer> EcManipulationFrameContainerVector;

#endif // ecManipulationFrameContainer_H_
