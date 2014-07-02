#ifndef ecConditionalDirection_H_
#define ecConditionalDirection_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecConditionalDirection.h
/// @class EcConditionalDirection
/// @brief Concrete implementation of EcManipulationDirection for running conditional directions from the director.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecDirectionConditionContainer.h"
#include "ecManipulationDirection.h"
#include "ecManipulationSceneDirectionContainer.h"
#include "ecManipulationSceneDirectionStateContainer.h"

// Forward declarations
class EcConditionalDirectionState;

/// Concrete implementation of EcManipulationDirection for running conditional directions from the director.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcConditionalDirection : public EcManipulationDirection
{
public:
   /// default constructor
   EcConditionalDirection
      (
      );

   /// destructor
   virtual ~EcConditionalDirection
      (
      );

   /// copy constructor
   EcConditionalDirection
      (
      const EcConditionalDirection& orig
      );

   /// assignment operator
   EcConditionalDirection& operator=
      (
      const EcConditionalDirection& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcConditionalDirection& orig
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

   /// get the directions
   virtual const EcManipulationSceneDirectionContainerVector& directions
      (
      ) const;

   /// set the directions
   virtual void setDirections
      (
      const EcManipulationSceneDirectionContainerVector& directions
      );

   /// get the exceptions corresponding to the directions
   virtual const EcManipulationSceneDirectionContainerVectorVector& directionExceptions
      (
      ) const;

   /// set the exceptions corresponding to the directions
   virtual void setDirectionExceptions
      (
      const EcManipulationSceneDirectionContainerVectorVector& exceptions
      );

   /// set the exceptions corresponding to a specific direction
   virtual void setDirectionExceptions
      (
      EcU32 index,
      const EcManipulationSceneDirectionContainerVector& exceptions
      );

   /// add a direction (without associated exceptions)
   virtual void addDirection
      (
      const EcManipulationSceneDirection& direction
      );

   /// add a direction and associated exception
   virtual void addDirection
      (
      const EcManipulationSceneDirection& direction,
      const EcManipulationSceneDirection& exception
      );

   /// add a direction and associated exceptions
   virtual void addDirection
      (
      const EcManipulationSceneDirection&                direction,
      const EcManipulationSceneDirectionContainerVector& exceptions
      );

   /// get the persistentconditions
   virtual const EcDirectionConditionContainerVector& persistentConditions
      (
      ) const;

   /// set the persistent conditions
   virtual void setPersistentConditions
      (
      const EcDirectionConditionContainerVector& conditions
      );

   /// get the exceptions corresponding to the persistent conditions
   virtual const EcManipulationSceneDirectionContainerVectorVector& persistentConditionExceptions
      (
      ) const;

   /// set the exceptions corresponding to the persistent conditions
   virtual void setPersistentConditionExceptions
      (
      const EcManipulationSceneDirectionContainerVectorVector& exceptions
      );

   /// set the exceptions corresponding to a specific persistent condition
   virtual void setPersistentConditionExceptions
      (
      EcU32 index,
      const EcManipulationSceneDirectionContainerVector& exceptions
      );

   /// add a persistent condition (without associated exceptions)
   virtual void addPersistentCondition
      (
      const EcDirectionCondition& condition
      );

   /// add a persistent condition and associated exception
   virtual void addPersistentCondition
      (
      const EcDirectionCondition&         condition,
      const EcManipulationSceneDirection& exception
      );

   /// add a persistent condition and associated exceptions
   virtual void addPersistentCondition
      (
      const EcDirectionCondition&                        condition,
      const EcManipulationSceneDirectionContainerVector& exceptions
      );

   /// get the postconditions
   virtual const EcDirectionConditionContainerVector& postConditions
      (
      ) const;

   /// set the postconditions
   virtual void setPostConditions
      (
      const EcDirectionConditionContainerVector& conditions
      );

   /// get the exceptions corresponding to the postconditions
   virtual const EcManipulationSceneDirectionContainerVectorVector& postConditionExceptions
      (
      ) const;

   /// set the exceptions corresponding to the postconditions
   virtual void setPostConditionExceptions
      (
      const EcManipulationSceneDirectionContainerVectorVector& exceptions
      );

   /// set the exceptions corresponding to a specific postcondition
   virtual void setPostConditionExceptions
      (
      EcU32 index,
      const EcManipulationSceneDirectionContainerVector& exceptions
      );

   /// add a postcondition (without associated exceptions)
   virtual void addPostCondition
      (
      const EcDirectionCondition& condition
      );

   /// add a postcondition and associated exception
   virtual void addPostCondition
      (
      const EcDirectionCondition&         condition,
      const EcManipulationSceneDirection& exception
      );

   /// add a postcondition and associated exceptions
   virtual void addPostCondition
      (
      const EcDirectionCondition&                        condition,
      const EcManipulationSceneDirectionContainerVector& exceptions
      );

   /// get the preconditions
   virtual const EcDirectionConditionContainerVector& preConditions
      (
      ) const;

   /// set the preconditions
   virtual void setPreConditions
      (
      const EcDirectionConditionContainerVector& conditions
      );

   /// get the exceptions corresponding to the preconditions
   virtual const EcManipulationSceneDirectionContainerVectorVector& preConditionExceptions
      (
      ) const;

   /// set the exceptions corresponding to the preconditions
   virtual void setPreConditionExceptions
      (
      const EcManipulationSceneDirectionContainerVectorVector& exceptions
      );

   /// set the exceptions corresponding to a specific precondition
   virtual void setPreConditionExceptions
      (
      EcU32 index,
      const EcManipulationSceneDirectionContainerVector& exceptions
      );

   /// add a precondition (without associated exceptions)
   virtual void addPreCondition
      (
      const EcDirectionCondition& condition
      );

   /// add a precondition and associated exception
   virtual void addPreCondition
      (
      const EcDirectionCondition&         condition,
      const EcManipulationSceneDirection& exception
      );

   /// add a precondition and associated exceptions
   virtual void addPreCondition
      (
      const EcDirectionCondition&                        condition,
      const EcManipulationSceneDirectionContainerVector& exceptions
      );

   void removePreCondition(EcU32 index);
   void removePersistentCondition(EcU32 index);
   void removeDirection(EcU32 index);
   void removePostCondition(EcU32 index);

   void clearPreConditions();
   void clearPersistentConditions();
   void clearDirections();
   void clearPostConditions();

   void swapPreConditions(EcU32 indexA, EcU32 indexB);
   void swapPersistentConditions(EcU32 indexA, EcU32 indexB);
   void swapDirections(EcU32 indexA, EcU32 indexB);
   void swapPostConditions(EcU32 indexA, EcU32 indexB);

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
   virtual void determineActiveDirections
      (
      EcConditionalDirectionState&                        adstate,
      EcManipulationSceneDirectionStateContainerVector*&  pScv,
      const EcManipulationSceneDirectionContainerVector*& pDcv
      ) const;

   virtual EcManipulationStatus::Enum updateActiveDirections
      (
      EcReal                                    time,
      const EcManipulationDirector&             director,
      const EcManipulationDirectorUpdateParams& params,
      const EcString&                           role,
      EcManipulationDirectorState&              dstate,
      EcManipulationSceneDirectionState&        sdstate
      ) const;

   virtual void updateProgress
      (
      EcManipulationSceneDirectionState& sdstate
      ) const;

   /// preconditions to test
   EcDirectionConditionContainerVector               m_PreConditions;

   /// exception directions to execute on precondition failure
   EcManipulationSceneDirectionContainerVectorVector m_PreConditionExceptions;

   /// persistent conditions to test
   EcDirectionConditionContainerVector               m_PersistentConditions;

   /// exception directions to execute on persistent condition failure
   EcManipulationSceneDirectionContainerVectorVector m_PersistentConditionExceptions;

   /// postconditions to test
   EcDirectionConditionContainerVector               m_PostConditions;

   /// exception directions to execute on postcondition failure
   EcManipulationSceneDirectionContainerVectorVector m_PostConditionExceptions;

   /// directions to execute during the nominal execution of this direction
   EcManipulationSceneDirectionContainerVector       m_Directions;

   /// exception directions to execute on direction failure
   EcManipulationSceneDirectionContainerVectorVector m_DirectionExceptions;
};

#endif // ecConditionalDirection_H_
