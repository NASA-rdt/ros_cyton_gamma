#ifndef ecConstantManipulationOffsetState_H_
#define ecConstantManipulationOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecConstantManipulationOffsetState.h
/// @class EcConstantManipulationOffsetState
/// @brief This class provides a manipulation offset that remains constant.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationOffsetState.h"

/// This class provides a manipulation offset that remains constant.
class EC_ACTIN_MANIPULATION_DECL EcConstantManipulationOffsetState : public EcManipulationOffsetState
{
public:
   /// default constructor
   EcConstantManipulationOffsetState
      (
      );

   /// destructor
   virtual ~EcConstantManipulationOffsetState
      (
      );

   /// copy constructor
   EcConstantManipulationOffsetState
      (
      const EcConstantManipulationOffsetState& orig
      );

   /// assignment operator
   EcConstantManipulationOffsetState& operator=
      (
      const EcConstantManipulationOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcConstantManipulationOffsetState& orig
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
};

#endif // ecConstantManipulationOffsetState_H_
