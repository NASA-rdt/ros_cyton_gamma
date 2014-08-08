#ifndef ecProxyActionState_H_
#define ecProxyActionState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecProxyActionState.h
/// @class EcProxyActionState
/// @brief A state is a placeholder for current control parameters
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationActionState.h"

#include <control/ecManipEndEffectorPlace.h>

// Forward declarations

class EC_ACTIN_MANIPULATION_DECL EcProxyActionState : public EcManipulationActionState
{
public:
   /// default constructor
   EcProxyActionState
      (
      );

   /// destructor
   virtual ~EcProxyActionState
      (
      );

   /// copy constructor
   EcProxyActionState
      (
      const EcProxyActionState& orig
      );

   /// assignment operator
   EcProxyActionState& operator=
      (
      const EcProxyActionState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcProxyActionState& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// get the token
   virtual const EcToken& token
      (
      ) const;

   /// get the current end-effector set index
   virtual EcU32 currentEndEffectorSet
      (
      ) const;

   /// set the current end-effector set index
   virtual void setCurrentEndEffectorSet
      (
      EcU32 value
      );

   /// get the current control description index
   virtual EcU32 currentControlDescription
      (
      ) const;

   /// set the current control description index
   virtual void setCurrentControlDescription
      (
      EcU32 value
      );

   /// get the current control method index
   virtual EcU32 currentControlMethod
      (
      ) const;

   /// set the current control method index
   virtual void setCurrentControlMethod
      (
      EcU32 value
      );

   /// get the desired end-effector placement
   virtual const EcManipulatorEndEffectorPlacement& desiredPlacement
      (
      ) const;

   /// set the current control method indexdesired end-effector placement
   virtual void setDesiredPlacement
      (
      const EcManipulatorEndEffectorPlacement& value
      );

   /// get the progress
   virtual EcReal progress
      (
      ) const;

   /// set the progress
   virtual void setProgress
      (
      EcReal value
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   EcXmlU32                          m_CurrentEndEffectorSet;        ///< current end effector set
   EcXmlU32                          m_CurrentControlDescription;    ///< current control description
   EcXmlU32                          m_CurrentControlMethod;         ///< current control method
   EcManipulatorEndEffectorPlacement m_DesiredPlacement;             ///< desired placement
   EcXmlReal                         m_Progress;                     ///< progress
};

#endif // ecProxyActionState_H_
