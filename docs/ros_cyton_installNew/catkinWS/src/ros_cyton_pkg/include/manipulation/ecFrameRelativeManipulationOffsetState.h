#ifndef ecFrameRelativeManipulationOffsetState_H_
#define ecFrameRelativeManipulationOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecFrameRelativeManipulationOffsetState.h
/// @class EcFrameRelativeManipulationOffsetState
/// @brief This class provides a manipulation offset that is relative to
///        a manipulation offset in another frame.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecRelativeManipulationOffsetState.h"

/// This class provides a manipulation offset that is relative to a manipulation offset in another frame.
class EC_ACTIN_MANIPULATION_DECL EcFrameRelativeManipulationOffsetState : public EcRelativeManipulationOffsetState
{
public:
   /// default constructor
   EcFrameRelativeManipulationOffsetState
      (
      );

   /// destructor
   virtual ~EcFrameRelativeManipulationOffsetState
      (
      );

   /// copy constructor
   EcFrameRelativeManipulationOffsetState
      (
      const EcFrameRelativeManipulationOffsetState& orig
      );

   /// assignment operator
   EcFrameRelativeManipulationOffsetState& operator=
      (
      const EcFrameRelativeManipulationOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcFrameRelativeManipulationOffsetState& orig
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

#endif // ecFrameRelativeManipulationOffsetState_H_
