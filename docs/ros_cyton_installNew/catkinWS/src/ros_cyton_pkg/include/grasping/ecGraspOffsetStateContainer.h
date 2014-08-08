#ifndef ecGraspOffsetStateContainer_H_
#define ecGraspOffsetStateContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspOffsetStateContainer.h
/// @class EcGraspOffsetStateContainer
/// @brief Container for grasp offsets
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcGraspOffsetState;

/// Container for grasp offsets
class EC_ACTIN_GRASPING_DECL EcGraspOffsetStateContainer :
   public EcXmlVariableElementType<EcGraspOffsetState>
{
public:
   /// default constructor
   EcGraspOffsetStateContainer
      (
      );

   /// destructor
   virtual ~EcGraspOffsetStateContainer
      (
      );

   /// copy constructor
   EcGraspOffsetStateContainer
      (
      const EcGraspOffsetStateContainer& orig
      );

   /// assignment operator
   EcGraspOffsetStateContainer& operator=
      (
      const EcGraspOffsetStateContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspOffsetStateContainer& orig
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
   static EcGraspOffsetStateContainer nullObject
      (
      );
};

/// an XML readable/writable vector of EcGraspOffsetStateContainer objects
typedef EcXmlVectorType<EcGraspOffsetStateContainer> EcGraspOffsetStateContainerVector;

#endif // ecGraspOffsetStateContainer_H_
