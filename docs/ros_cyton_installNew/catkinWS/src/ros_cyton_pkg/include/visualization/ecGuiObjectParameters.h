#ifndef ecGuiObjectParameters_H_
#define ecGuiObjectParameters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGuiObjectParameters.h
/// @class EcGUIObjectParameters
/// @brief holds parameters for GUI objects such as guide frame and
///        center of interest.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCommon/ecColor.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <xml/ecXmlVector.h>

/// Holds parameters for GUI objects such as guide frame and center of interest.
class EC_FOUNDATION_VISUALIZATION_DECL EcGUIObjectParameters : public EcXmlCompoundType
{
public:
	EcGUIObjectParameters
      (
      );

	virtual ~EcGUIObjectParameters
      (
      );

      /// copy constructor
   EcGUIObjectParameters
      (
      const EcGUIObjectParameters& orig
      );

   /// assignment operator
   EcGUIObjectParameters& operator=
      (
      const EcGUIObjectParameters& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcGUIObjectParameters& orig
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
   static EcGUIObjectParameters nullObject
      (
      );

   /// get set functions of the member variables

   /// get Guide Frame Axis Length
   virtual EcReal guideFrameAxisLength
      (
      ) const;

   /// set Guide Frame Axis Length
   virtual void setGuideFrameAxisLength
      (
      EcReal guideFrameAxisLength
      );

   /// get COI Sphere Radius
   virtual EcReal COISphereRadius
      (
      ) const;

   /// set COI Sphere Radius
   virtual void setCOISphereRadius
      (
      EcReal coiSphereRadius
      );

protected:
   /// size of guide frame
   EcXmlReal                  m_GuideFrameAxisLength;

   /// radius of center of interest
   EcXmlReal                  m_COISphereRadius;
};

#endif // ecGuiObjectParameters_H_
