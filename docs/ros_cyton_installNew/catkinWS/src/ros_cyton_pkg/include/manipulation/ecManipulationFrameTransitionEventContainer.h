#ifndef ecManipulationFrameTransitionEventContainer_H_
#define ecManipulationFrameTransitionEventContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationFrameTransitionEventContainer.h
/// @class EcManipulationFrameTransitionEventContainer
/// @brief Container for manipulation frame transition events
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcManipulationFrameTransitionEvent;

/// Container for manipulation frame transition events
class EC_ACTIN_MANIPULATION_DECL EcManipulationFrameTransitionEventContainer :
   public EcXmlVariableElementType<EcManipulationFrameTransitionEvent>
{
public:
   /// default constructor
   EcManipulationFrameTransitionEventContainer
      (
      );

   /// destructor
   virtual ~EcManipulationFrameTransitionEventContainer
      (
      );

   /// copy constructor
   EcManipulationFrameTransitionEventContainer
      (
      const EcManipulationFrameTransitionEventContainer& orig
      );

   /// assignment operator
   EcManipulationFrameTransitionEventContainer& operator=
      (
      const EcManipulationFrameTransitionEventContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationFrameTransitionEventContainer& orig
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
   static EcManipulationFrameTransitionEventContainer nullObject
      (
      );
};

#endif // ecManipulationFrameTransitionEventContainer_H_
