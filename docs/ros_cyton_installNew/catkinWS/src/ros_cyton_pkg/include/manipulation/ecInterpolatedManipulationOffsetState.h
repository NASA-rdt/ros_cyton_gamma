#ifndef ecInterpolatedManipulationOffsetState_H_
#define ecInterpolatedManipulationOffsetState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecInterpolatedManipulationOffsetState.h
/// @class EcInterpolatedManipulationOffsetState
/// @brief This class provides a manipulation offset that is interpolated.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationOffsetState.h"
#include "ecManipulationOffsetStateContainer.h"

#include <foundCommon/ecEndEffectorPlacement.h>

/// This class provides a manipulation offset that is interpolated.
class EC_ACTIN_MANIPULATION_DECL EcInterpolatedManipulationOffsetState : public EcManipulationOffsetState
{
public:
   /// default constructor
   EcInterpolatedManipulationOffsetState
      (
      );

   /// destructor
   virtual ~EcInterpolatedManipulationOffsetState
      (
      );

   /// copy constructor
   EcInterpolatedManipulationOffsetState
      (
      const EcInterpolatedManipulationOffsetState& orig
      );

   /// assignment operator
   EcInterpolatedManipulationOffsetState& operator=
      (
      const EcInterpolatedManipulationOffsetState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcInterpolatedManipulationOffsetState& orig
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

   /// get the target offset
   virtual EcManipulationOffsetState* targetOffsetState
      (
      );

   /// get the target offset
   virtual const EcManipulationOffsetState* targetOffsetState
      (
      ) const;

   /// set the target offset
   virtual void setTargetOffsetState
      (
      const EcManipulationOffsetStateContainer& targetOffsetState
      );

   /// get the initialization time
   virtual EcReal initializationTime
      (
      ) const;

   /// set the interpolation time
   virtual void setInitializationTime
      (
      EcReal time
      );

   /// get the initial offset
   virtual const EcEndEffectorPlacement& initialOffset
      (
      ) const;

   /// set the initial offset
   virtual void setInitialOffset
      (
      const EcEndEffectorPlacement& offset
      );

   /// get the current offset
   virtual const EcEndEffectorPlacement& currentOffset
      (
      ) const;

   /// set the current offset
   virtual void setCurrentOffset
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
   /// target offset for the inerpolation
   EcManipulationOffsetStateContainer      m_TargetOffsetState;

   /// time at initialization
   EcXmlReal                        m_InitializationTime;

   /// offset at the time of initialization
   EcEndEffectorPlacement m_InitialOffset;

   /// current offset
   EcEndEffectorPlacement m_CurrentOffset;
};

#endif // ecInterpolatedManipulationOffsetState_H_
