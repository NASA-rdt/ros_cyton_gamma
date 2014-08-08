#ifndef ecImageSensor_H_
#define ecImageSensor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecImageSensor.h
/// @class EcImageSensor
/// @brief Holds a basic description of an image sensor.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecXmlBasicType.h>
#include <xml/ecXmlCompType.h>
#include <manipulator/ecLinkAttachment.h>

#include "ecSensorNoiseVector.h"

/**
\class EcImageSensor
\brief An abstract class that holds a basic description of an image sensor.
*/
class EC_FOUNDATION_IMAGESENSOR_DECL EcImageSensor : public EcXmlCompoundType
{
public:
   /// default constructor
   EcImageSensor
      (
      );

   /// constructor with values
   EcImageSensor
      (
      EcU32 width,
      EcU32 height,
      EcReal frameRate
      );

   /// destructor
   virtual ~EcImageSensor
      (
      );

   /// copy constructor
   EcImageSensor
      (
      const EcImageSensor& orig
      );

   /// assignment operator
   EcImageSensor& operator=
      (
      const EcImageSensor& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcImageSensor& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const = 0;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// returns the token for this class
   virtual const EcToken& token
      (
      ) const = 0;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const = 0;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const = 0;

   /// get the display type of the image sensor display. An image sensor display is the one that actually displays (either from actual imagery or rendering) the image.
   virtual const EcString& displayType
      (
      ) const;

   /// get the label
   virtual const EcString& label
      (
      ) const;

   /// set the label
   virtual void setLabel
      (
      const EcString& label
      );

   /// set the size of the image in pixels
   virtual void setImageSize
      (
      EcU32 width,
      EcU32 height
      );

   /// get the width in pixels
   virtual EcU32 width
      (
      ) const;

   /// set the width in pixels
   virtual void setWidth
      (
      EcU32 width
      );

   /// get the height in pixels
   virtual EcU32 height
      (
      ) const;

   /// set the height in pixels
   virtual void setHeight
      (
      EcU32 height
      );

   /// get the number of channels
   virtual EcU32 numChannels
      (
      ) const;

   /// set the number of channels
   virtual void setNumChannels
      (
      EcU32 numChannels
      );

   /// get the frame rate in Hz
   virtual EcReal frameRate
      (
      ) const;

   /// set the frame rate in Hz
   virtual void setFrameRate
      (
      EcReal frameRate
      );

   /// get the index of the manipulator to which this image sensor is attached
   virtual EcU32 manipulatorIndex
      (
      ) const;

   /// set the index of the manipulator to which this image sensor is attached
   virtual void setManipulatorIndex
      (
      EcU32 manipIndex
      );

   /// get the identifying label of the link to which this image sensor is attached
   virtual const EcString& linkIdentifier
      (
      ) const;

   /// set the identifying label of the link to which this image sensor is attached
   virtual void setLinkIdentifier
      (
      const EcString& linkId
      );

   /// get the frame of the image sensor with respect to the link's primary frame. The image sensor location is at the origin. The line of sight is in the x-direction and the up direction is the y-direction.
   virtual const EcCoordinateSystemTransformation& frame
      (
      ) const;

   /// set the frame of the image sensor with respect to the link's primary frame
   virtual void setFrame
      (
      const EcCoordinateSystemTransformation& frame
      );

   /// get the field of view (in radians)
   virtual EcReal fieldOfView
      (
      ) const;

   /// set the field of view (in radians)
   virtual void setFieldOfView
      (
      EcReal fovInRadians
      );

   /// Set the near clip plane.
   virtual void setNearClipPlane
      (
      EcReal valueInMeters
      );

   /// Get the near clip plane.
   virtual EcReal nearClipPlane
      (
      ) const;

   /// Set the far clip plane.
   virtual void setFarClipPlane
      (
      EcReal valueInMeters
      );

   /// Get the far clip plane.
   virtual EcReal farClipPlane
      (
      ) const;

   /// get the vector of all types of noise associated with this image sensor.
   virtual const EcSensorNoiseVector& sensorNoiseVector
      (
      ) const;

   /// set the vector of all types of noise associated with this image sensor. This will also initialize the sensor noise vector with this image sensor.
   virtual void setSensorNoiseVector
      (
      const EcSensorNoiseVector& sensorNoiseVector
      );

   /// returns whether or not noise is applicable to this type of image sensor
   virtual EcBoolean isNoiseApplicable
      (
      ) const = 0;

   /// calculate the frame in the system coordinates.
   /**
   \param[in] manipulator The manipulator to which this image sensor is attached.
   \param[in,out] activeState An active state which will be updated (if necessary) upon return.
   \param[out] frame Upon return, the frame in the system coordinates.
   */
   virtual void calculateFrame
      (
      const EcIndividualManipulator& manipulator,
      EcManipulatorActiveState&  activeState,
      EcCoordinateSystemTransformation& frame
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

protected:
   /// initialize the sensor noise vector
   virtual void initSensorNoiseVector
      (
      );

protected:
   /// The type of the associated image sensor display
   EcXmlString          m_DisplayType;

   /// The label of this image sensor
   EcXmlString          m_Label;

   /// The width in pixels
   EcXmlU32             m_Width;

   /// The height in pixels
   EcXmlU32             m_Height;

   /// The number of channels
   EcXmlU32             m_NumChannels;

   /// The frame rate in Hz
   EcXmlReal            m_FrameRate;

   /// The link attachment
   EcLinkAttachment     m_LinkAttachment;

   /// the field of view in radians
   EcXmlReal      m_FieldOfView;

   /// The vector of all types of noise associated with this image sensor
   EcSensorNoiseVector  m_vSensorNoise;

   /// The near clip plane.
   EcXmlReal      m_NearClipPlane;

   /// The far clip plane.
   EcXmlReal      m_FarClipPlane;
};

#endif // ecImageSensor_H_
