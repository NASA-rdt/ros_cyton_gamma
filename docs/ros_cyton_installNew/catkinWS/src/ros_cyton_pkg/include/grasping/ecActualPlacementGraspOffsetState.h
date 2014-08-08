#ifndef ecActualPlacementGraspOffsetState_H_
#define ecActualPlacementGraspOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecActualPlacementGraspOffsetState.h
/// @class EcActualPlacementGraspOffsetState
/// @brief This class provides a grasp offset that uses the actual EE placement.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspOffsetState.h"

#include <foundCommon/ecEndEffectorPlacement.h>

/// This class provides a grasp offset that uses the initial actual EE placement and remains constant throughout the update.
class EC_ACTIN_GRASPING_DECL EcActualPlacementGraspOffsetState : public EcGraspOffsetState
{
public:
   /// default constructor
   EcActualPlacementGraspOffsetState
      (
      );

   /// destructor
   virtual ~EcActualPlacementGraspOffsetState
      (
      );

   /// copy constructor
   EcActualPlacementGraspOffsetState
      (
      const EcActualPlacementGraspOffsetState& orig
      );

   /// assignment operator
   EcActualPlacementGraspOffsetState& operator=
      (
      const EcActualPlacementGraspOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcActualPlacementGraspOffsetState& orig
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

   /// get the offset
   virtual const EcEndEffectorPlacement& offset
      (
      ) const;

   /// set the offset
   virtual void setOffset
      (
      const EcEndEffectorPlacement& offset
      );

   /// register XML member variables
   virtual void registerComponents
      (
      );

   /// get the current offset transformation
   virtual const EcEndEffectorPlacement& currentOffsetTransformation
      (
      ) const;

   /// get the goal offset transformation
   virtual const EcEndEffectorPlacement& goalOffsetTransformation
      (
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:

   /// a grasp offset that remains constant throughout the update
   EcEndEffectorPlacement m_Offset;
};

#endif // ecActualPlacementGraspOffsetState_H_
