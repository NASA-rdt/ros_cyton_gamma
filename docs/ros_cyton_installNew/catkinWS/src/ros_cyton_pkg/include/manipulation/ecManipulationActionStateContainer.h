#ifndef ecManipulationActionStateContainer_H_
#define ecManipulationActionStateContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationActionStateContainer.h
/// @class EcManipulationActionStateContainer
/// @brief Container for manipulation action states
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcManipulationActionState;

/// Container for manipulation action states
class EC_ACTIN_MANIPULATION_DECL EcManipulationActionStateContainer :
   public EcXmlVariableElementType<EcManipulationActionState>
{
public:
   /// default constructor
   EcManipulationActionStateContainer
      (
      );

   /// destructor
   virtual ~EcManipulationActionStateContainer
      (
      );

   /// copy constructor
   EcManipulationActionStateContainer
      (
      const EcManipulationActionStateContainer& orig
      );

   /// assignment operator
   EcManipulationActionStateContainer& operator=
      (
      const EcManipulationActionStateContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationActionStateContainer& orig
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
   static EcManipulationActionStateContainer nullObject
      (
      );
};

#endif // ecManipulationActionStateContainer_H_
