#ifndef ecPathAction_H_
#define ecPathAction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecPathAction.h
/// @class EcPathAction
/// @brief This represents a path
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationAction.h"

#include <control/ecEndEffectorSet.h>
#include <control/ecManipEndEffectorPlacePath.h>
#include <control/ecPositionStatePath.h>
#include <control/ecCoordinatedJointEndEffectorTool.h>
#include <foundCommon/ecDataMap.h>

// Forward declarations

/// A joint sequence.
class EC_ACTIN_MANIPULATION_DECL EcPathAction : public EcManipulationAction
{
public:
   /// enumerations for the path playback mode
   enum
   {
      STATE=0,
      END_EFFECTOR=1
   };

   /// default constructor
   EcPathAction
      (
      );

   /// destructor
   virtual ~EcPathAction
      (
      );

   /// copy constructor
   EcPathAction
      (
      const EcPathAction& orig
      );

   /// assignment operator
   EcPathAction& operator=
      (
      const EcPathAction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPathAction& orig
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

   /// get the position state path
   virtual const EcPositionStatePath& positionStatePath
      (
      ) const;

   /// set the position state path
   virtual void setPositionStatePath
      (
      const EcPositionStatePath& value
      );

   /// get the end-effector path
   virtual const EcManipulatorEndEffectorPlacementPath& endEffectorPath
      (
      ) const;

   /// set the end-effector path
   virtual void setEndEffectorPath
      (
      const EcManipulatorEndEffectorPlacementPath& value
      );

   /// get the control description index
   virtual EcU32 controlDescriptionIndex
      (
      ) const;

   /// set the control description index
   virtual void setControlDescriptionIndex
      (
      EcU32 value
      );

   /// get the control method index
   virtual EcU32 controlMethodIndex
      (
      ) const;

   /// set the control method index
   virtual void setControlMethodIndex
      (
      EcU32 value
      );

   /// get the end-effector set index
   virtual EcU32 endEffectorSetIndex
      (
      ) const;

   /// set the end-effector set index
   virtual void setEndEffectorSetIndex
      (
      EcU32 value
      );

   /// get the path playback mode
   virtual EcU32 pathPlaybackMode
      (
      ) const;

   /// set the path playback mode
   virtual void setPathPlaybackMode
      (
      EcU32 value
      );

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
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

   /// @copydoc EcManipulationAction::progress()
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
   /// playback the state path
   /// @return True if all the points in the path have been executed or false otherwise
   EcBoolean statePathPlayback
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      EcManipulationActionState& astate
      ) const;

   /// playback the end-effector path
   /// @return True if all the points in the path have been executed or false otherwise
   EcBoolean endEffectorPathPlayback
      (
      EcReal time,
      const EcManipulationUpdateParams& params,
      EcManipulationActionState& astate
      ) const;

   /// returns whether the robot has reached either the start or end point of the path
   EcBoolean pointReached
      (
      EcBoolean start,
      const EcManipulationUpdateParams& params
      ) const;

   // XML data
   EcPositionStatePath     m_StatePath;                  ///< state path
   EcManipulatorEndEffectorPlacementPath  m_EndEffectorPath;      ///< end-effector path
   EcXmlU32                m_ControlDescriptionIndex;    ///< control description index used in the path action
   EcXmlU32                m_ControlMethodIndex;         ///< control method index used in the path action
   EcXmlU32                m_EndEffectorSetIndex;        ///< end-effector set index used in the EE path
   EcXmlEnumU32            m_PathPlaybackMode;           ///< mode for path playback

   // non-XML data
   EcReal                  m_Tolerance;                              ///< tolerance
   mutable EcCoordinatedJointEndEffectorTool m_CoordJointEndTool;    ///< coordinate joint end tool
   mutable EcBoolean       m_CoordJointEndToolInit;                  ///< if the coordinate joint end tool is initialized
   mutable EcManipulatorEndEffectorPlacement m_DesiredEndPlacement;  ///< desired end placement
   mutable EcReal          m_StartTime;                              ///< start time
   mutable EcBoolean       m_PathStarted;                            ///< if path is started
   mutable EcPositionState          m_UtilityPosState;               ///< utility position state
   mutable EcEndEffectorPlacement   m_UtilityPlacement;              ///< utility placement
   mutable EcU32Vector     m_ProfiledEndEffectorIndices;             ///< profiled end effector indices

   // static utility data
   static const EcDataMap                 m_theNullDataMap;       ///< the null data map
   static const EcU32Vector               m_theNullU32Vector;     ///< the null U32 vector
};


#endif // ecPathAction_H_
