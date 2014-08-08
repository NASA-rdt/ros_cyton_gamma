#ifndef ecGraspFrameTransitionEventContainer_H_
#define ecGraspFrameTransitionEventContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspFrameTransitionEventContainer.h
/// @class EcGraspFrameTransitionEventContainer
/// @brief Container for grasp frame transition events
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarElemType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

class EcGraspFrameTransitionEvent;

/// Container for grasp frame transition events
class EC_ACTIN_GRASPING_DECL EcGraspFrameTransitionEventContainer :
   public EcXmlVariableElementType<EcGraspFrameTransitionEvent>
{
public:
   /// default constructor
   EcGraspFrameTransitionEventContainer
      (
      );

   /// destructor
   virtual ~EcGraspFrameTransitionEventContainer
      (
      );

   /// copy constructor
   EcGraspFrameTransitionEventContainer
      (
      const EcGraspFrameTransitionEventContainer& orig
      );

   /// assignment operator
   EcGraspFrameTransitionEventContainer& operator=
      (
      const EcGraspFrameTransitionEventContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGraspFrameTransitionEventContainer& orig
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
   static EcGraspFrameTransitionEventContainer nullObject
      (
      );
};

#endif // ecGraspFrameTransitionEventContainer_H_
