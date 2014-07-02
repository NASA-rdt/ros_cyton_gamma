#ifndef ecDisplayOptions_H_
#define ecDisplayOptions_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecDisplayOptions.h
/// @class EcDisplayOptions
/// @brief An xml based class for displaying selected end effectors, collision and joint limit
///        events.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecDisplayOptionsParameters.h"
#include "ecJointLimitDisplayParameters.h"
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVector.h>
#include <xml/ecXmlVectorType.h>

/// Display options for selected end effectors, collision and joint limit events.
class EC_FOUNDATION_VISUALIZATION_DECL EcDisplayOptions : public EcXmlCompoundType
{
public:

	/// The display event type
   enum DisplayEvent
      {
      EVENT_NONE,
      END_EFFECTOR,
      COLLISION,
      JOINT_LIMIT
      };

	EcDisplayOptions();
	virtual ~EcDisplayOptions();

   /// copy constructor
   EcDisplayOptions
      (
      const EcDisplayOptions& orig
      );

   /// assignment operator
   EcDisplayOptions& operator=
      (
      const EcDisplayOptions& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDisplayOptions& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   ///equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// A virtual new that returns an EcXmlObject.
   virtual EcXmlObject* newObject
      (
      ) const;

   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcDisplayOptions nullObject
      (
      );


   /// get set functions of the member variables

   /// get end effector display options parameters
   virtual const EcDisplayOptionsParameters& endEffectorDisplayOptionParas
      (
      ) const;

   /// set end effector display options parameters
   virtual void setEndEffectorDisplayOptionParas
      (
      const EcDisplayOptionsParameters& endEffectorDisplayOptionParas
      );

   /// get joint limit display options parameters
   virtual const EcJointLimitDisplayParameters& jointLimitDisplayOptionParas
      (
      ) const;

   /// set joint limit display parameters
   virtual void setJointLimitDisplayOptionParas
      (
      const EcJointLimitDisplayParameters& jointLimitDisplayOptionParas
      );

   /// get collision display options parameters
   virtual const EcDisplayOptionsParameters& collisionDisplayOptionParas
      (
      ) const;

   /// set collision display options parameters
   virtual void setCollisionDisplayOptionParas
      (
      const EcDisplayOptionsParameters& collisionDisplayOptionParas
      );

   /// get flag of status for end effector ([arm][link])
   virtual const EcXmlBooleanVectorVector& endDisplayFlagVec2D
      (
      ) const;

   /// set flag of status for end effector ([arm][link])
   virtual void setEndDisplayFlagVec2D
      (
      const EcXmlBooleanVectorVector& endDisplayFlagVec2D
      );

   /// reset flag of status for end effector ([arm][link]) to EcFalse
   virtual void resetEndDisplayFlagVec2D
      (
      );

   /// set flag for selected end effector
   virtual void setEndDisplayFlag
      (
      const EcU32 manipIndex,
      const EcU32 linkIndex
      );

   /// get flag of status for joint limit  ([arm][link])
   virtual const EcXmlBooleanVectorVector& jointLimitDisplayFlagVec2D
      (
      ) const;

   /// set flag of status for joint limit  ([arm][link])
   virtual void setJointLimitDisplayFlagVec2D
      (
      const EcXmlBooleanVectorVector& jointLimitDisplayFlagVec2D
      );

   /// reset flag of status for joint limit  ([arm][link]) to EcFalse
   virtual void resetJointLimitDisplayFlagVec2D
      (
      );

   /// get flag of status for collision  ([arm][link])
   virtual const EcXmlBooleanVectorVector& collisionDisplayFlagVec2D
      (
      ) const;

   /// set flag of status for collision  ([arm][link])
   virtual void setCollisionDisplayFlagVec2D
      (
      const EcXmlBooleanVectorVector& collisionDisplayFlagVec2D
      );

   /// set flag of status for collision  ([arm][link]) to EcFalse
   virtual void resetCollisionDisplayFlagVec2D
      (
      );

   /// set flags manipulator size
   virtual void setFlagsManipulatorSize
      (
      const EcU32& manipSize
      );

   /// set flags link size
   void setFlagsLinkSize
      (
      const EcU32& manipIndex,
      const EcU32& linkSize
      );

   /// reset all flags
   void resetAllFlags
      (
      );

   /// set current time
   virtual void setTime
      (
      const EcReal& time
      );

   /// set manipulator index
   virtual void setManipIndex
      (
      const EcU32& manipIndex
      );

   /// set link index
   virtual void setLinkIndex
      (
      const EcU32& linkIndex
      );

   /// get display color
   virtual void getDisplayColor
      (
      EcF32* displayColor
      ) const;

   /// set flag of status for collision
   virtual void setCollisionDisplayFlag
      (
      const EcU32 manipIndex,
      const EcU32 linkIndex
      );

   /// set flag for selected end effector
   virtual void setJointLimitDisplayFlag
      (
      const EcU32 manipIndex,
      const EcU32 linkIndex
      );

protected:
   /// end effector display options parameters
   EcDisplayOptionsParameters          m_EndEffectorDisplayOptionParas;

   /// joint limit display options parameters
   EcJointLimitDisplayParameters       m_JointLimitDisplayOptionParas;

   /// collision display options parameters
   EcDisplayOptionsParameters          m_CollisionDisplayOptionParas;

   /// flag of status for end effector ([arm][link])
   EcXmlBooleanVectorVector                m_EndDisplayFlagVec2D;

   /// flag of status for joint limit  ([arm][link])
   EcXmlBooleanVectorVector                m_JointLimitDisplayFlagVec2D;

   /// flag of status for collision  ([arm][link])
   EcXmlBooleanVectorVector                m_CollisionDisplayFlagVec2D;

   /// none XML variables
   /// current time
   EcReal                              m_Time;

   /// manipulator index
   EcU32                               m_ManipIndex;

   /// link index
   EcU32                               m_LinkIndex;
};

#endif // ecDisplayOptions_H_
