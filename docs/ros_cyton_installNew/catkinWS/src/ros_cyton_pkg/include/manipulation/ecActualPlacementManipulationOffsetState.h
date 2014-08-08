#ifndef ecActualPlacementManipulationOffsetState_H_
#define ecActualPlacementManipulationOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecActualPlacementManipulationOffsetState.h
/// @class EcActualPlacementManipulationOffsetState
/// @brief This class provides a manipulation offset that uses the actual EE placement.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationOffsetState.h"

#include <foundCommon/ecEndEffectorPlacement.h>

/// This class provides a manipulation offset that uses the initial actual EE placement and remains constant throughout the update.
class EC_ACTIN_MANIPULATION_DECL EcActualPlacementManipulationOffsetState : public EcManipulationOffsetState
{
public:
   /// default constructor
   EcActualPlacementManipulationOffsetState
      (
      );

   /// destructor
   virtual ~EcActualPlacementManipulationOffsetState
      (
      );

   /// copy constructor
   EcActualPlacementManipulationOffsetState
      (
      const EcActualPlacementManipulationOffsetState& orig
      );

   /// assignment operator
   EcActualPlacementManipulationOffsetState& operator=
      (
      const EcActualPlacementManipulationOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcActualPlacementManipulationOffsetState& orig
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
   EcEndEffectorPlacement m_Offset;       ///< end effector offset
};

#endif // ecActualPlacementManipulationOffsetState_H_
