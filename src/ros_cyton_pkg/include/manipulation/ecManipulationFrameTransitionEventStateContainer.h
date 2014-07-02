#ifndef ecManipulationFrameTransitionEventStateContainer_H_
#define ecManipulationFrameTransitionEventStateContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationFrameTransitionEventStateContainer.h
/// @class EcManipulationFrameTransitionEventStateContainer
/// @brief Container for manipulation frame transition events
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcManipulationFrameTransitionEventState;

/// Container for manipulation frame transition events
class EC_ACTIN_MANIPULATION_DECL EcManipulationFrameTransitionEventStateContainer :
   public EcXmlVariableElementType<EcManipulationFrameTransitionEventState>
{
public:
   /// default constructor
   EcManipulationFrameTransitionEventStateContainer
      (
      );

   /// destructor
   virtual ~EcManipulationFrameTransitionEventStateContainer
      (
      );

   /// copy constructor
   EcManipulationFrameTransitionEventStateContainer
      (
      const EcManipulationFrameTransitionEventStateContainer& orig
      );

   /// assignment operator
   EcManipulationFrameTransitionEventStateContainer& operator=
      (
      const EcManipulationFrameTransitionEventStateContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationFrameTransitionEventStateContainer& orig
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
   static EcManipulationFrameTransitionEventStateContainer nullObject
      (
      );
};

#endif // ecManipulationFrameTransitionEventStateContainer_H_
