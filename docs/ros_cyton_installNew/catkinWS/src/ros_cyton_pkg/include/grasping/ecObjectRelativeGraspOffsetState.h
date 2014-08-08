#ifndef ecObjectRelativeGraspOffsetState_H_
#define ecObjectRelativeGraspOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecObjectRelativeGraspOffsetState.h
/// @class EcObjectRelativeGraspOffsetState
/// @brief This class provides a grasp offset that is relative to
///        the object to be grasped.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecRelativeGraspOffsetState.h"

/// This class provides a grasp offset that is relative to the object to be grasped.
class EC_ACTIN_GRASPING_DECL EcObjectRelativeGraspOffsetState : public EcRelativeGraspOffsetState
{
public:
   /// default constructor
   EcObjectRelativeGraspOffsetState
      (
      );

   /// destructor
   virtual ~EcObjectRelativeGraspOffsetState
      (
      );

   /// copy constructor
   EcObjectRelativeGraspOffsetState
      (
      const EcObjectRelativeGraspOffsetState& orig
      );

   /// assignment operator
   EcObjectRelativeGraspOffsetState& operator=
      (
      const EcObjectRelativeGraspOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcObjectRelativeGraspOffsetState& orig
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

#endif // ecObjectRelativeGraspOffsetState_H_
