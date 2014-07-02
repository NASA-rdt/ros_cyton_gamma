#ifndef ecCameraProperties_H_
#define ecCameraProperties_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecEcCameraParameters.h
/// @class EcCameraParameters
/// @brief Holds a description of camera intrinsic and extrinsic parameters.
//
//------------------------------------------------------------------------------
#include <sensor/sensor_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <boost/array.hpp>
#include <opencv2/core/core.hpp>

/** Holds a description of a cameras intrinsic and extrisic parameters.
    The parameters are stored in OpenCV types including cv::Mat.
*/

class EC_SENSOR_SENSCORE_DECL EcCameraParameters
{
public:
   /// constructor
        EcCameraParameters
      (
      );

   /// destructor
   virtual ~EcCameraParameters
      (
      );

   /// copy constructor
   EcCameraParameters
      (
      const EcCameraParameters& orig
      );

   /// assignment operator
   EcCameraParameters& operator=
      (
      const EcCameraParameters& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCameraParameters& orig
      ) const;

   /// reads the camera parameters from file (xml or yaml)
   static void read
      (
      const EcString filename,
      EcCameraParameters& cameraParameters
      );

   /// writes the camera parameters to file (xml or yaml)
   static void write
      (
      const EcString filename,
      const EcCameraParameters& cameraParameters
      );

   /// gets the camera index
   virtual EcU32 index
      (
      ) const;


   /// sets the camera index
   virtual void setIndex
      (
      EcU32 index
      );

   /// gets the camera identifier string
   virtual const EcString& identifier
      (
      ) const;

   /// sets the camera identifier string
   virtual void setIdentifier
      (
      const EcString& Identifier
      );

   /// gets the camera matrix
   virtual const cv::Mat& cameraMatrix
      (
      ) const;

   ///sets the camera matrix
   virtual void setCameraMatrix
      (
      const cv::Mat& cameraMatrix
      );

   /// gets the distortion coefficients
   virtual const cv::Mat& distortionCoeffs
      (
      ) const;

   /// sets the distortion coefficients
   virtual void setDistortionCoeffs
      (
      const cv::Mat& dist
      );

    /// gets the pixel dimensions (size of a pixel in meters)
   virtual const boost::array<EcReal, 2>& pixelDimensions
      (
      ) const;

   /// sets the pixel dimensions (size of a pixel in meters)
   virtual void setPixelDimensions
      (
      const boost::array<EcReal, 2>& pixelDimensions
      );

   /// gets the sensor dimensions (size of the sensor in meters)
   virtual const boost::array<EcReal, 2>& sensorDimensions
      (
      ) const;

   /// sets the sensor dimensions (size of the sensor in meters)
   virtual void setSensorDimensions
      (
      const boost::array<EcReal, 2>& sensorDimensions
      );

   /// gets the image template of the camera
   virtual const cv::Mat& imageTemplate
      (
      ) const;

   /// gets the rotation matrix
   virtual const cv::Mat& rotationMat
      (
      ) const;

   /// sets the rotation matrix
   virtual void setRotationMat
      (
      const cv::Mat& rotationMat
      );

   /// gets the translation vector
   virtual const cv::Mat& translationVec
      (
      ) const;

   /// sets the translation vector
   virtual void setTranslationVec
      (
      const cv::Mat& translationVec
      );

   /// sets the image template of the camera
   virtual void setImageTemplate
      (
      const cv::Mat& imageTemplate
      );

   /// gets the reprojection error stats from calibration
   virtual  const boost::array<EcReal, 2>& reprojectionErrorStats
      (
      )const;

   /// sets the reprojection error stats from calibration
   virtual void setReprojectionErrorStats
      (
       const boost::array<EcReal, 2>& stats
      );

protected:
   EcU32 m_Index;                            ///< Camera index

   EcString m_Identifier;                    ///< Camera identifier string

   /// Intrinsic Parameters
   cv::Mat m_CameraMatrix;                   ///< 3 x 3 matrix of camera intrinsic parameters [fx,  0,  cx]
                                             ///<                                             [0 , fy,  cy]
                                             ///<                                             [0 ,  0,   1]
                                             ///<[fx, fy] represents the focal length in pixels
                                             ///<[cx, cy] is the principal point (image center)

   cv::Mat m_DistortionCoeffs;               ///< 4 x 1 or upto 6 x 1 Distortion coefficients [k1, k2,[k3,k4], p1, p2]

   boost::array<EcReal, 2> m_SensorDimensions;   ///< Physical sensor size [width, height] (m)

   boost::array<EcReal, 2> m_PixelDimensions; 	 ///< Physical pixel size [width (x), height (y)] (m)

   /// Extrinsic Parameters
   cv::Mat m_RotationMat;                   ///< 3 x 3 Rotation matrix

   cv::Mat m_TranslationVec;                ///< 3 x 1 Translation matrix (m)

   /// Image template
   cv::Mat m_ImageTemplate;                 ///< Image Template - holds a cv::Mat image of the type and size returned by this camera

   boost::array<EcReal, 2>  m_ReprojectionErrorStats;      ///< Average and standard deviation of reprojection error for calibration points using estimated camera parameters
};

namespace Ec
{
  typedef EcCameraParameters CameraParameters;
} // namespace Ec

#endif // ecCameraProperties_H_
