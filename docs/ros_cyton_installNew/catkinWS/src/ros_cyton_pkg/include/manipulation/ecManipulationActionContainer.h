#ifndef ecManipulationActionContainer_H_
#define ecManipulationActionContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationActionContainer.h
/// @class EcManipulationActionContainer
/// @brief Container for manipulation actions
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcManipulationAction;

/// Container for manipulation actions
class EC_ACTIN_MANIPULATION_DECL EcManipulationActionContainer :
   public EcXmlVariableElementType<EcManipulationAction>
{
public:
   /// default constructor
   EcManipulationActionContainer
      (
      );

   /// destructor
   virtual ~EcManipulationActionContainer
      (
      );

   /// copy constructor
   EcManipulationActionContainer
      (
      const EcManipulationActionContainer& orig
      );

   /// assignment operator
   EcManipulationActionContainer& operator=
      (
      const EcManipulationActionContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationActionContainer& orig
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
   static EcManipulationActionContainer nullObject
      (
      );
};

#endif // ecManipulationActionContainer_H_
