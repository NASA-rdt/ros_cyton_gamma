#ifndef ecCameraControlAction_H_
#define ecCameraControlAction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecCameraControlAction.h
/// @class EcCameraControlAction
/// @brief This represents an action for an SVS camera.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecCameraControlSignals.h"
#include "ecManipulationAction.h"

#include <control/ecEndEffectorSet.h>
#include <foundCommon/ecDataMap.h>
#include <foundCore/ecConnectionManagerTypes.h>

class EC_ACTIN_MANIPULATION_DECL EcCameraControlAction : public EcManipulationAction
{
public:
   /// type definition of SetFocusDistanceSignalPtr
   typedef Ec::ConnectionManagerTypes::Signal<Ec::SignalSetFocusDistance::Type>::PtrType SetFocusDistanceSignalPtr;
   /// type definition of TriggerImageCaptureSignalPtr
   typedef Ec::ConnectionManagerTypes::Signal<Ec::SignalTriggerImageCapture::Type>::PtrType TriggerImageCaptureSignalPtr;

   /// default constructor
   EcCameraControlAction
      (
      );

   /// destructor
   virtual ~EcCameraControlAction
      (
      );

   /// copy constructor
   EcCameraControlAction
      (
      const EcCameraControlAction& orig
      );

   /// assignment operator
   EcCameraControlAction& operator=
      (
      const EcCameraControlAction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCameraControlAction& orig
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

   /// get the name of the camera to be controlled by the action
   virtual const EcString& cameraName
      (
      ) const;

   /// set the name of the camera to be controlled by the action
   virtual void setCameraName
      (
      const EcString& cameraName
      );

   /// get the focus distance to be set by the action. Negative value means no focus to be set.
   virtual EcReal focusDistance
      (
      ) const;

   /// set the focus distance to be set by the action
   virtual void setFocusDistance
      (
      EcReal value
      );

   /// get whether to capture the image by the action
   virtual EcBoolean captureImage
      (
      ) const;

   /// get whether to capture the image by the action
   virtual void setCaptureImage
      (
      EcBoolean value
      );

   /// get the pause duration in seconds
   virtual EcReal pauseDuration
      (
      ) const;

   /// set the pause duration in seconds
   virtual void setPauseDuration
      (
      EcReal value
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
   EcXmlString       m_CameraName;

   /// the focus distance
   EcXmlReal         m_FocusDistance;

   /// the flag indicating whether to capture an image
   EcXmlBoolean      m_CaptureImage;

   /// the duration of a pause
   EcXmlReal         m_PauseDuration;

   // non-XML
   mutable EcReal    m_StartTime;      ///< start time

   static const EcDataMap                 m_theNullDataMap;          ///< the null data map
   static const EcEndEffectorSet          m_theNullEndEffectorSet;   ///< the null end effector set
   static const EcU32Vector               m_theNullU32Vector;        ///< the null U32 vector

   SetFocusDistanceSignalPtr        m_SetFocusDistanceSignalPtr;     ///< pointer to set focus distance signal
   TriggerImageCaptureSignalPtr     m_TriggerImageCaptureSignalPtr;  ///< pointer to trigger image capture signal
};

#endif // ecCameraControlAction_H_
