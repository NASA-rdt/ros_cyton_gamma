#ifndef ecManipulationOffsetStateContainer_H_
#define ecManipulationOffsetStateContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationOffsetStateContainer.h
/// @class EcManipulationOffsetStateContainer
/// @brief Container for manipulation offsets
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcManipulationOffsetState;

/// Container for manipulation offsets
class EC_ACTIN_MANIPULATION_DECL EcManipulationOffsetStateContainer :
   public EcXmlVariableElementType<EcManipulationOffsetState>
{
public:
   /// default constructor
   EcManipulationOffsetStateContainer
      (
      );

   /// destructor
   virtual ~EcManipulationOffsetStateContainer
      (
      );

   /// copy constructor
   EcManipulationOffsetStateContainer
      (
      const EcManipulationOffsetStateContainer& orig
      );

   /// assignment operator
   EcManipulationOffsetStateContainer& operator=
      (
      const EcManipulationOffsetStateContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationOffsetStateContainer& orig
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
   static EcManipulationOffsetStateContainer nullObject
      (
      );
};

/// type definition of EcManipulationOffsetStateContainerVector
typedef EcXmlVectorType<EcManipulationOffsetStateContainer> EcManipulationOffsetStateContainerVector;

#endif // ecManipulationOffsetStateContainer_H_
