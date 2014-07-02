#ifndef ecManipulationOffsetContainer_H_
#define ecManipulationOffsetContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationOffsetContainer.h
/// @class EcManipulationOffsetContainer
/// @brief Container for manipulation offsets
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcManipulationOffset;

/// Container for manipulation offsets
class EC_ACTIN_MANIPULATION_DECL EcManipulationOffsetContainer :
   public EcXmlVariableElementType<EcManipulationOffset>
{
public:
   /// default constructor
   EcManipulationOffsetContainer
      (
      );

   /// destructor
   virtual ~EcManipulationOffsetContainer
      (
      );

   /// copy constructor
   EcManipulationOffsetContainer
      (
      const EcManipulationOffsetContainer& orig
      );

   /// assignment operator
   EcManipulationOffsetContainer& operator=
      (
      const EcManipulationOffsetContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationOffsetContainer& orig
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
   static EcManipulationOffsetContainer nullObject
      (
      );
};

/// type definition of EcManipulationOffsetContainerVector
typedef EcXmlVectorType<EcManipulationOffsetContainer> EcManipulationOffsetContainerVector;

#endif // ecManipulationOffsetContainer_H_
