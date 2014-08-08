#ifndef ecLinkRelativeGraspOffsetState_H_
#define ecLinkRelativeGraspOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkRelativeGraspOffsetState.h
/// @class EcLinkRelativeGraspOffsetState
/// @brief This class provides a grasp offset that is relative to
///        a specified link on the object to be grasped.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecRelativeGraspOffsetState.h"

/// This class provides a grasp offset that is relative to a specified link on the object to be grasped.
class EC_ACTIN_GRASPING_DECL EcLinkRelativeGraspOffsetState : public EcRelativeGraspOffsetState
{
public:
   /// default constructor
   EcLinkRelativeGraspOffsetState
      (
      );

   /// destructor
   virtual ~EcLinkRelativeGraspOffsetState
      (
      );

   /// copy constructor
   EcLinkRelativeGraspOffsetState
      (
      const EcLinkRelativeGraspOffsetState& orig
      );

   /// assignment operator
   EcLinkRelativeGraspOffsetState& operator=
      (
      const EcLinkRelativeGraspOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkRelativeGraspOffsetState& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
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

   /// register XML member variables
   virtual void registerComponents
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );
};

#endif // ecLinkRelativeGraspOffsetState_H_
