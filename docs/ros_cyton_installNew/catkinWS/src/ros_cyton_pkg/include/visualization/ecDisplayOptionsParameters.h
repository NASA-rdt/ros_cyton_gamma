#ifndef ecDisplayOptionsParameters_H_
#define ecDisplayOptionsParameters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecDisplayOptionsParameters.h
/// @class EcDisplayOptionsParameters
/// @brief parameters for displaying events such as selected end
///        effectors, collision and joint limit.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecColor.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVector.h>

/// Parameters for displaying events such as selected end effectors, collision and joint limit.
class EC_FOUNDATION_VISUALIZATION_DECL EcDisplayOptionsParameters : public EcXmlCompoundType
{
public:
   enum
   {
     END_EFFECTOR,
     JOINT_LIMIT,
     COLLISION
   };

	EcDisplayOptionsParameters();
	virtual ~EcDisplayOptionsParameters();

   /// copy constructor
   EcDisplayOptionsParameters
      (
      const EcDisplayOptionsParameters& orig
      );

   /// assignment operator
   EcDisplayOptionsParameters& operator=
      (
      const EcDisplayOptionsParameters& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDisplayOptionsParameters& orig
      ) const;

   ///equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// A virtual new that returns an EcXmlObject.
   virtual EcXmlObject* newObject
      (
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

   /// gets the is-on flag
   virtual EcBoolean isOn
      (
      ) const;

   /// sets the is-on flag
   virtual void setIsOn
      (
      EcBoolean isOn
      );

   /// gets the use user color flag
   virtual EcBoolean useUserColor
      (
      ) const;

   /// sets the use user color flag
   virtual void setUseUserColor
      (
      EcBoolean useUserColor
      );

   /// gets the frequency
   virtual EcXmlReal frequency
      (
      ) const;

   /// sets the frequency
   virtual void setFrequency
      (
      const EcXmlReal& frequency
      );

   /// gets the user color
   virtual const EcColor& userColor
      (
      ) const;

   /// sets the user color
   virtual void setUserColor
      (
      const EcColor& userColor
      );

   /// gets the priority
   virtual EcXmlU32 priority
      (
      ) const;

   /// sets the priority
   virtual void setPriority
      (
      const EcXmlU32& priority
      );

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
   static EcDisplayOptionsParameters nullObject
      (
      );

   /// get display color
   void getDisplayColor
      (
      EcF32* displayColor,
      const EcReal& time
      ) const;


protected:
   /// flashing frequency per second, 0 indicating no flashing
   EcXmlReal                     m_Frequency;

   /// user specified color
   EcColor                       m_UserColor;

   /// use user color or automatically generate
   EcXmlBoolean                  m_UseUserColor;

   /// priority, when same link is having more events,
   /// higher priority one will be displayed
   EcXmlU32                      m_Priority;

   /// on or off
   EcXmlBoolean                  m_IsOn;
};

#endif // ecDisplayOptionsParameters_H_
