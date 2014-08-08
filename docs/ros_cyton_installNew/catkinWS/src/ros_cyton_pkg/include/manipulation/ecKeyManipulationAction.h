#ifndef ecKeyManipulationAction_H_
#define ecKeyManipulationAction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecKeyManipulationAction.h
/// @class EcKeyManipulationAction
/// @brief This represents an action for an SVS camera.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationAction.h"

#include <control/ecEndEffectorSet.h>
#include <foundCommon/ecDataMap.h>
#include <foundCore/ecConnectionManagerTypes.h>

class EC_ACTIN_MANIPULATION_DECL EcKeyManipulationAction : public EcManipulationAction
{
public:
   

   /// default constructor
   EcKeyManipulationAction
      (
      );

   /// destructor
   virtual ~EcKeyManipulationAction
      (
      );

   /// copy constructor
   EcKeyManipulationAction
      (
      const EcKeyManipulationAction& orig
      );

   /// assignment operator
   EcKeyManipulationAction& operator=
      (
      const EcKeyManipulationAction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcKeyManipulationAction& orig
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

   /// get the name of the manipulation direction to be controlled by the action
   virtual const EcString& keyName
      (
      ) const;

   /// set the name of the manipulation direction to be controlled by the action
   virtual void setKeyName
      (
      const EcString& name
      );

   

   /// get the token
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

   //---
   // Implementation of EcManipulationAction interface
   //---

   /// initialize the manipulation sequence
   virtual EcBoolean init
      (
      EcManipulationActionStateContainer& astateContainer
      ) const;

   /// update the manipulation sequence
   virtual EcManipulationStatus::Enum update
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      EcManipulationActionState& astate
      ) const;

   /// Return the ative control description index to be used for the manipulation
   virtual EcU32 activeControlDescription
      (
      const EcManipulationActionState& astate
      ) const;

   /// Return the ative control method index to be used for the manipulation
   virtual EcU32 activeControlMethod
      (
      const EcManipulationActionState& astate
      ) const;

   /// Return the ative end-effector set index to be used for the manipulation
   virtual EcU32 activeEndEffectorSet
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the data map
   virtual const EcDataMap& dataMap
      (
      const EcManipulationActionState& astate
      ) const;

   /// this method does nothing
   virtual void findDataMapReferences
      (
      EcStringRealMap& references
      ) const;

   /// get the end effector set
   virtual const EcEndEffectorSet& endEffectorSet
      (
      const EcManipulationUpdateParams& params,
      const EcManipulationActionState&  astate
      ) const;

   /// get the end effector placement
   virtual const EcManipulatorEndEffectorPlacement& endEffectorPlacement
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the overall progress of this action
   virtual EcReal progress
      (
      const EcManipulationActionState& astate
      ) const;

   /// get the status string
   virtual EcString statusString
      (
      const EcManipulationActionState& astate,
      const EcString& separator
      ) const;

   /// @copydoc EcManipulationAction::profiledPositionEndEffectorIndices()
   virtual const EcU32Vector& profiledPositionEndEffectorIndices
      (
      const EcManipulationActionState& astate
      ) const;

protected:
   /// the name of the camera to be controlled by the action
   EcXmlString       m_KeyName;

  

   // non-XML
 
   static const EcDataMap                 m_theNullDataMap;          ///< the null data map
   static const EcEndEffectorSet          m_theNullEndEffectorSet;   ///< the null end effector set
   static const EcU32Vector               m_theNullU32Vector;        ///< the null U32 vector
 
};

#endif // ecKeyManipulationAction_H_
