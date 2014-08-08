#ifndef ecBasicDirectionSimpleState_H_
#define ecBasicDirectionSimpleState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecBasicDirectionSimpleState.h
/// @class EcBasicDirectionSimpleState
/// @brief Concrete implementation of EcManipulationSceneDirectionSimpleState for holding basic state information.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecManipulationSceneDirectionSimpleState.h"

#include <xml/ecXmlBasicType.h>

/// Concrete implementation of EcManipulationSceneDirectionSimpleState for holding basic state information.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcBasicDirectionSimpleState : public EcManipulationSceneDirectionSimpleState
{
public:
   /// default constructor
   EcBasicDirectionSimpleState
      (
      );

   /// destructor
   virtual ~EcBasicDirectionSimpleState
      (
      );

   /// copy constructor
   EcBasicDirectionSimpleState
      (
      const EcBasicDirectionSimpleState& orig
      );

   /// assignment operator
   EcBasicDirectionSimpleState& operator=
      (
      const EcBasicDirectionSimpleState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBasicDirectionSimpleState& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// get the progress
   virtual EcReal progress
      (
      ) const;

   /// set the progress
   virtual void setProgress
      (
      EcReal value
      );

   /// get the current Item at play
   virtual EcU32 currentItemAtPlay
      (
      ) const;

   /// set current Item at play
   virtual void setCurrentItemAtPlay
      (
      EcU32 value
      );

   /// return a string token
   virtual const EcToken& token
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
   /// Progress of the direction (0.0 = not started, 1.0 = completed)
   EcXmlReal m_Progress;

   /// current Item Index
   EcXmlU32 m_CurrentItem;
};

#endif // ecBasicDirectionSimpleState_H_
