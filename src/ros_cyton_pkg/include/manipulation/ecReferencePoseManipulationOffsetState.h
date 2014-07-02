#ifndef ecReferencePoseManipulationOffsetState_H_
#define ecReferencePoseManipulationOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecReferencePoseManipulationOffsetState.h
/// @class EcReferencePoseManipulationOffsetState
/// @brief This class provides a state for EcReferencePoseManipulationOffset
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationOffsetState.h"

#include <foundCommon/ecEndEffectorPlacement.h>

/// This class provides a manipulation offset that remains constant.
class EC_ACTIN_MANIPULATION_DECL EcReferencePoseManipulationOffsetState : public EcManipulationOffsetState
{
public:
   /// default constructor
   EcReferencePoseManipulationOffsetState
      (
      );

   /// destructor
   virtual ~EcReferencePoseManipulationOffsetState
      (
      );

   /// copy constructor
   EcReferencePoseManipulationOffsetState
      (
      const EcReferencePoseManipulationOffsetState& orig
      );

   /// assignment operator
   EcReferencePoseManipulationOffsetState& operator=
      (
      const EcReferencePoseManipulationOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcReferencePoseManipulationOffsetState& orig
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

protected:
   /// the calculated offset
   EcEndEffectorPlacement m_Offset;
};

#endif // ecReferencePoseManipulationOffsetState_H_
