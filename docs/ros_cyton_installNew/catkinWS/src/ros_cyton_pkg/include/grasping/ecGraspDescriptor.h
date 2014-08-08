#ifndef ecGraspDescriptor_H_
#define ecGraspDescriptor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspDescriptor.h
/// @class EcGraspDescriptor
/// @brief This structure contains the graso descriptor
/// @todo Accessors and mutators should be defined in the cpp file
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

/// Grasp descriptor
class EC_ACTIN_GRASPING_DECL EcGraspDescriptor
{
public:

   /// accessor for the family string
   const EcString& family
      (
      ) const
   {
      return m_Family;
   }

   /// mutator for the family string
   void setFamily
      (
      const EcString& family
      )
   {
      m_Family = family;
   }

   /// accessor for the index
   EcU32 index
      (
      ) const
   {
      return m_Index;
   }

   /// mutator for the index
   void setIndex
      (
      EcU32 index
      )
   {
      m_Index = index;
   }

protected:
   /// family descriptor
   EcString m_Family;     

   /// selector from family
   EcU32    m_Index;      
};

#endif // ecGraspDescriptor_H_
