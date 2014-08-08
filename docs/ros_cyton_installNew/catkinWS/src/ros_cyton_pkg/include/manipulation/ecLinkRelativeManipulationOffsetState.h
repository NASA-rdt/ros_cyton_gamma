#ifndef ecLinkRelativeManipulationOffsetState_H_
#define ecLinkRelativeManipulationOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkRelativeManipulationOffsetState.h
/// @class EcLinkRelativeManipulationOffsetState
/// @brief This class provides a manipulation offset that is relative to
///        a specified link on the object to be manipulationed.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecRelativeManipulationOffsetState.h"

/// This class provides a manipulation offset that is relative to a specified link on the object to be manipulationed.
class EC_ACTIN_MANIPULATION_DECL EcLinkRelativeManipulationOffsetState : public EcRelativeManipulationOffsetState
{
public:
   /// default constructor
   EcLinkRelativeManipulationOffsetState
      (
      );

   /// destructor
   virtual ~EcLinkRelativeManipulationOffsetState
      (
      );

   /// copy constructor
   EcLinkRelativeManipulationOffsetState
      (
      const EcLinkRelativeManipulationOffsetState& orig
      );

   /// assignment operator
   EcLinkRelativeManipulationOffsetState& operator=
      (
      const EcLinkRelativeManipulationOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkRelativeManipulationOffsetState& orig
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

#endif // ecLinkRelativeManipulationOffsetState_H_
