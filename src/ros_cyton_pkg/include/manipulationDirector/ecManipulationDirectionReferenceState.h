#ifndef ecManipulationDirectionReferenceState_H_
#define ecManipulationDirectionReferenceState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationDirectionReferenceState.h
/// @class EcManipulationDirectionReferenceState
/// @brief Concrete implementation of EcManipulationSceneDirectionState for holding EcManipulationDirectionReference state information.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecManipulationSceneDirectionState.h"
#include <manipulationDirector/ecManipulationSceneDirectionStateContainer.h>

// Forward declarations
class EcManipulationDirection;
class EcManipulationDirectionReference;

/// Concrete implementation of EcManipulationSceneDirectionState for holding EcManipulationDirectionReference state information.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationDirectionReferenceState : public EcManipulationSceneDirectionState
{
public:
   /// default constructor
   EcManipulationDirectionReferenceState
      (
      );

   /// destructor
   virtual ~EcManipulationDirectionReferenceState
      (
      );

   /// copy constructor
   EcManipulationDirectionReferenceState
      (
      const EcManipulationDirectionReferenceState& orig
      );

   /// assignment operator
   EcManipulationDirectionReferenceState& operator=
      (
      const EcManipulationDirectionReferenceState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationDirectionReferenceState& orig
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

   /// get the direction
   virtual const EcManipulationDirection* direction
      (
      ) const;

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
   friend class EcManipulationDirectionReference;

   const EcManipulationDirection* m_pDirection;

   EcManipulationSceneDirectionStateContainer m_DirectionStateContainer;
};

#endif // ecManipulationDirectionReferenceState_H_
