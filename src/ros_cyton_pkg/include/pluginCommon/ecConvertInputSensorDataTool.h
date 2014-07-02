#ifndef ecConvertInputSensorDataTool_H_
#define ecConvertInputSensorDataTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecConvertInputSensorDataTool.h
/// @class EcConvertInputSensorDataTool
/// @brief Tool to convert raw sensor data from input device
//
//------------------------------------------------------------------------------
#include <foundCommon/ecCoordSysXForm.h>

class EcNetworkHandler;
class EcBase3DInputDevice;

/**
This class is used to convert raw sensor data from an input device to a
3D mouse movement. It may be more appropriate to move this to foundation/inputDevice.
*/
class EcConvertInputSensorDataTool
{
public:
   /// Constructor.
   EcConvertInputSensorDataTool
      (
      );

   /// Destructor.
   ~EcConvertInputSensorDataTool
      (
      );

   /// gets the translation scaling factor
   virtual EcReal translationScale
      (
      ) const;

   /// sets the translation scaling factor
   virtual void setTranslationScale
      (
      EcReal value
      );

   /// set the orientation from input device frame to global frame
   virtual void setToGlobal
      (
      const EcOrientation& value
      );

   /// set the orientation from input device frame to EE frame
   virtual void setToEndEffector
      (
      const EcOrientation& value
      );

   /// converts the raw EE position and orientation from the input device
   virtual EcBoolean convertSensorData
      (
      EcCoordinateSystemTransformation& sensorData
      );

protected:
   /// add the raw input data
   virtual void addRawInputData
      (
      const EcCoordinateSystemTransformation& xform
      );

   /// calculate the movement
   virtual EcBoolean calcMovement
      (
      EcCoordinateSystemTransformation& xform
      );

protected:
   EcReal         m_TranslationScale;
   EcOrientation  m_ToGlobal;
   EcOrientation  m_ToEE;

   /// Hold onto last 2 input data sets for use in calculations.
   EcCoordinateSystemTransformation       m_SensorData0;
   EcCoordinateSystemTransformation       m_SensorData1;

   EcReal         m_NumInputDataSets;
};

#endif // ecConvertInputSensorDataTool_H_
