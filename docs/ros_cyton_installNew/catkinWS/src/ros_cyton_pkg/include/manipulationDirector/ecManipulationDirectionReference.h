#ifndef ecManipulationDirectionReference_H_
#define ecManipulationDirectionReference_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationDirectionReference.h
/// @class EcManipulationDirectionReference
/// @brief Concrete implementation of EcManipulationDirection that references a manipulation direction stored within the director's object directory.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecManipulationDirection.h"

/// Concrete implementation of EcManipulationDirection that references a manipulation direction stored within the director's object directory.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcManipulationDirectionReference : public EcManipulationDirection
{
public:
   /// default constructor
   EcManipulationDirectionReference
      (
      );

   /// destructor
   virtual ~EcManipulationDirectionReference
      (
      );

   /// copy constructor
   EcManipulationDirectionReference
      (
      const EcManipulationDirectionReference& orig
      );

   /// assignment operator
   EcManipulationDirectionReference& operator=
      (
      const EcManipulationDirectionReference& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcManipulationDirectionReference& orig
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

   /// get the path of the desired direction within the object directory
   virtual const EcString& directionPath
      (
      ) const;

   /// set the path of the desired direction within the object directory
   virtual void setDirectionPath
      (
      const EcString& path
      );

   /// get the descriptor for this direction
   virtual const EcString descriptor
      (
      ) const;

   /// get a vector of role names that are referenced within this direction
   virtual EcStringVector roleNames
      (
      const EcManipulationDirector& director
      ) const;

   /// initialize the direction
   virtual EcBoolean init
      (
      const EcManipulationDirector&               director,
      const EcString&                             role,
      EcManipulationSceneDirectionStateContainer& dstateContainer
      ) const;

   /// update the direction
   virtual EcManipulationStatus::Enum update
      (
      EcReal                                    time,
      const EcManipulationDirector&             director,
      const EcManipulationDirectorUpdateParams& params,
      const EcString&                           role,
      EcManipulationDirectorState&              dstate,
      EcManipulationSceneDirectionState&        sdstate
      ) const;

   /// convert the direction state
   virtual void convert
      (
      const EcManipulationSceneDirectionStateContainer& dstateContainer,
      EcManipulationSceneDirectionSimpleStateContainer& sdstateContainer
      ) const;

   /// get a flag indicating if this direction is currently active
   virtual EcBoolean isActive
      (
      const EcManipulationSceneDirectionState& dstate
      ) const;

   /// get the active control description index to be used for the manipulation
   virtual EcU32 activeControlDescription
      (
      const EcManipulationSceneDirectionState& dstate
      ) const;

   /// get the active control method index to be used for the manipulation
   virtual EcU32 activeControlMethod
      (
      const EcManipulationSceneDirectionState& dstate
      ) const;

   /// get the active end-effector set index to be used for the manipulation
   virtual EcU32 activeEndEffectorSet
      (
      const EcManipulationSceneDirectionState& dstate
      ) const;

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      const EcManipulationSceneDirectionState& dstate
      ) const;

   /// get the end effector placement
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPlacement
      (
      const EcManipulationSceneDirectionState& dstate
      ) const;

   /// get the progress of this direction
   virtual EcReal progress
      (
      const EcManipulationSceneDirectionState& dstate
      ) const;

   /// get the status string
   virtual EcString statusString
      (
      const EcManipulationSceneDirectionState& dstate,
      const EcString& separator
      ) const;

   /// \copydoc EcManipulationDirection::profiledPositionEndEffectorIndices()
   virtual const EcU32Vector& profiledPositionEndEffectorIndices
      (
      const EcManipulationSceneDirectionState& astate
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
   /// path of the desired direction within the object directory
   EcXmlString m_DirectionPath;
};

#endif // ecManipulationDirectionReference_H_
