#ifndef ecManipulationSceneCue_H_
#define ecManipulationSceneCue_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationSceneCue.h
/// @class EcManipulationSceneCue
/// @brief Contains a cue used for synchronization between roles in a scene
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlEnumType.h>
#include <xml/ecXmlVectorType.h>

/// Contains a cue used for synchronization between roles in a scene
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationSceneCue : public EcXmlCompoundType
{
public:
   enum
   {
      FOLLOWING_CUE,
      SIMULTANEOUS_CUE
   };

   /// default constructor
   EcManipulationSceneCue
      (
      );

   /// destructor
   virtual ~EcManipulationSceneCue
      (
      );

   /// copy constructor
   EcManipulationSceneCue
      (
      const EcManipulationSceneCue& orig
      );

   /// assignment operator
   EcManipulationSceneCue& operator=
      (
      const EcManipulationSceneCue& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationSceneCue& orig
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

   /// get the type of the cue
   virtual EcU32 type
      (
      ) const;

   /// set the type of the cue
   virtual void setType
      (
      EcU32 type
      );

   /// get the role providing the cue
   virtual const EcString& role
      (
      ) const;

   /// set the role providing the cue
   virtual void setRole
      (
      const EcString& role
      );

   /// get the role direction index providing the cue
   virtual EcU32 directionIndex
      (
      ) const;

   /// set the role direction index providing the cue
   virtual void setDirectionIndex
      (
      EcU32 index
      );

   /// get the token
   virtual const EcToken& token
      (
      ) const;

protected:
   /// the type of the cue (simultaneous or follow)
   EcXmlEnumU32 m_Type;

   /// the role providing the cue
   EcXmlString  m_Role;

   /// the role direction index providing the cue
   EcXmlU32     m_DirectionIndex;
};

typedef EcXmlVectorType<EcManipulationSceneCue> EcManipulationSceneCueVector;

#endif // ecManipulationSceneCue_H_
