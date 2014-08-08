#ifndef ecManipulationDirectorSimpleState_H_
#define ecManipulationDirectorSimpleState_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationDirectorSimpleState.h
/// @class EcManipulationDirectorSimpleState
/// @brief Holds EcManipulationDirector simple state information
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationScriptSimpleState.h"

#include <xml/ecXmlCompType.h>

// Forward declaration
class EcManipulationDirector;

/// Holds EcManipulationDirector simple state information
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationDirectorSimpleState : public EcXmlCompoundType
{
public:
   /// default constructor
   EcManipulationDirectorSimpleState
      (
      );

   /// destructor
   virtual ~EcManipulationDirectorSimpleState
      (
      );

   /// copy constructor
   EcManipulationDirectorSimpleState
      (
      const EcManipulationDirectorSimpleState& orig
      );

   /// assignment operator
   EcManipulationDirectorSimpleState& operator=
      (
      const EcManipulationDirectorSimpleState& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationDirectorSimpleState& orig
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

   /// get the progress of the director
   EcReal progress
      (
      ) const;

   /// get the script state
   virtual const EcManipulationScriptSimpleState& scriptState
      (
      ) const;

   /// get the token
   virtual const EcToken& token
      (
      ) const;

protected:
   friend class EcManipulationDirector;

   /// Manipulation script state
   EcManipulationScriptSimpleState m_ScriptState;
};

#endif // ecManipulationDirectorSimpleState_H_
