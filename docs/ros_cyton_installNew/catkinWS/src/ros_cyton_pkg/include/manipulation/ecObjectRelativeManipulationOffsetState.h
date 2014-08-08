#ifndef ecObjectRelativeManipulationOffsetState_H_
#define ecObjectRelativeManipulationOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecObjectRelativeManipulationOffsetState.h
/// @class EcObjectRelativeManipulationOffsetState
/// @brief This class provides a manipulation offset that is relative to
///        the object to be manipulationed.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecRelativeManipulationOffsetState.h"

/// This class provides a manipulation offset that is relative to the object to be manipulationed.
class EC_ACTIN_MANIPULATION_DECL EcObjectRelativeManipulationOffsetState : public EcRelativeManipulationOffsetState
{
public:
   /// default constructor
   EcObjectRelativeManipulationOffsetState
      (
      );

   /// destructor
   virtual ~EcObjectRelativeManipulationOffsetState
      (
      );

   /// copy constructor
   EcObjectRelativeManipulationOffsetState
      (
      const EcObjectRelativeManipulationOffsetState& orig
      );

   /// assignment operator
   EcObjectRelativeManipulationOffsetState& operator=
      (
      const EcObjectRelativeManipulationOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcObjectRelativeManipulationOffsetState& orig
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

#endif // ecObjectRelativeManipulationOffsetState_H_
