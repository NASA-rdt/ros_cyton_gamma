#ifndef ecGraspFrameTransitionEventStateContainer_H_
#define ecGraspFrameTransitionEventStateContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspFrameTransitionEventStateContainer.h
/// @class EcGraspFrameTransitionEventStateContainer
/// @brief Container for grasp frame transition events
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcGraspFrameTransitionEventState;

/// Container for grasp frame transition events
class EC_ACTIN_GRASPING_DECL EcGraspFrameTransitionEventStateContainer :
   public EcXmlVariableElementType<EcGraspFrameTransitionEventState>
{
public:
   /// default constructor
   EcGraspFrameTransitionEventStateContainer
      (
      );

   /// destructor
   virtual ~EcGraspFrameTransitionEventStateContainer
      (
      );

   /// copy constructor
   EcGraspFrameTransitionEventStateContainer
      (
      const EcGraspFrameTransitionEventStateContainer& orig
      );

   /// assignment operator
   EcGraspFrameTransitionEventStateContainer& operator=
      (
      const EcGraspFrameTransitionEventStateContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspFrameTransitionEventStateContainer& orig
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
   static EcGraspFrameTransitionEventStateContainer nullObject
      (
      );
};

#endif // ecGraspFrameTransitionEventStateContainer_H_
