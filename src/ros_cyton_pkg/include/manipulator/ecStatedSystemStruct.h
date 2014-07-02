#ifndef ecStatedSystemStruct_H_
#define ecStatedSystemStruct_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecStatedSystemStruct.h
/// @class EcStatedSystemStruct
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

// forward declaration
class EcStatedSystem;

/// A convenience class that contains a stated system and the index of a manipulator of interest
class EC_FOUNDATION_MANIPULATOR_DECL EcStatedSystemStruct
{
public:
   /// constructor
   EcStatedSystemStruct
      (
      const EcStatedSystem* pStatedSystem,
      EcU32 manipulatorIndex
      ):
      m_pStatedSystem(pStatedSystem),
      m_ManipulatorIndex(manipulatorIndex)
   {
   }

   /// The pointer to the stated system
   inline const EcStatedSystem* statedSystemPtr
      (
      ) const
   {
      return m_pStatedSystem;
   }

   /// The manipulator index
   inline EcU32 manipulatorIndex
      (
      ) const
   {
      return m_ManipulatorIndex;
   }

protected:
   const EcStatedSystem*   m_pStatedSystem;  ///< The pointer to the stated system
   EcU32    m_ManipulatorIndex;              ///< The manipulator index
};

#endif // ecStatedSystemStruct_H_
