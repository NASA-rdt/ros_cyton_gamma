#ifndef ecFrameRelativeGraspOffsetState_H_
#define ecFrameRelativeGraspOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecFrameRelativeGraspOffsetState.h
/// @class EcFrameRelativeGraspOffsetState
/// @brief This class provides a grasp offset that is relative to
///        a grasp offset in another frame.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecRelativeGraspOffsetState.h"

/// This class provides a grasp offset that is relative to a grasp offset in another frame.
class EC_ACTIN_GRASPING_DECL EcFrameRelativeGraspOffsetState : public EcRelativeGraspOffsetState
{
public:
   /// default constructor
   EcFrameRelativeGraspOffsetState
      (
      );

   /// destructor
   virtual ~EcFrameRelativeGraspOffsetState
      (
      );

   /// copy constructor
   EcFrameRelativeGraspOffsetState
      (
      const EcFrameRelativeGraspOffsetState& orig
      );

   /// assignment operator
   EcFrameRelativeGraspOffsetState& operator=
      (
      const EcFrameRelativeGraspOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcFrameRelativeGraspOffsetState& orig
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

#endif // ecFrameRelativeGraspOffsetState_H_
