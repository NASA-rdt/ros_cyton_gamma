#ifndef ec_HardwareCalibrationPointVector_H_
#define ec_HardwareCalibrationPointVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecHardwareCalibrationPointVector.h
/// @class Ec::HardwareCalibrationPointVector
/// @brief XML Vector container for Ec::HardwareCalibrationPoint
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>
#include "ecHardwareCalibrationPoint.h"
#include <xml/ecXmlVectorType.h>

#ifdef _MSC_VER
#  pragma warning(disable:4661)
#endif

namespace Ec
{
/// XML Vector container for Ec::HardwareCalibrationPoint
class EC_ACTIN_HWPLUGIN_DECL HardwareCalibrationPointVector : public EcXmlVectorType<HardwareCalibrationPoint>
{
public:
   /// type definition of PointIter
   typedef std::vector<HardwareCalibrationPoint>::iterator PointIter;
   /// type definition of cPointIter
   typedef std::vector<HardwareCalibrationPoint>::const_iterator cPointIter;
   /// type definition of PointIterPair
   typedef std::pair<PointIter, PointIter> PointIterPair;
   /// type definition of cPointIterPair
   typedef std::pair<cPointIter, cPointIter> cPointIterPair;

   /// xml object methods
   ECXMLOBJECT(HardwareCalibrationPointVector);
      
   /// @copydoc EcXmlCompoundType::read(EcXmlReader&)
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// Find the closest two calibration points and use them
   /// to define a linear extrapolation/interpolation to hardware units
   virtual const EcXmlReal actinToHardware
      (
      const EcXmlReal& actinJointValue
      ) const;

   /// Find the closest two calibration points and use them
   /// to define a linear extrapolation/interpolation to Actin units
   virtual const EcXmlReal hardwareToActin
      (
      const EcXmlReal& hardwareJointValue
      ) const;

   /// add HardwareCalibrationPoint
   virtual EcBoolean add
      (
      const EcXmlReal& actinJointValue,
      const EcXmlReal& hardwareJointValue
      );

   /// add HardwareCalibrationPoint
   virtual EcBoolean add
      (
      const HardwareCalibrationPoint& point
      );

protected:
   /// find the nearest calibration point
   virtual cPointIterPair findNearest
      (
      const HardwareCalibrationPoint& point,
      EcBoolean findNearestHardwareJointValues = EcFalse
      ) const;

   /// find the nearest calibration point
   virtual PointIterPair findNearest
      (
      const HardwareCalibrationPoint& point,
      EcBoolean findNearestHardwareJointValues = EcFalse
      );

   /**
    * @brief Determine if the 3 inputs are strictly monotonic.
    * @details Return true if firstPoint < middlePoint < lastPoint
    *          or firstPoint > middlePoint > lastPoint
    * @param[in] firstPoint
    * @param[in] middlePoint
    * @param[in] lastPoint
    * @return EcBoolean
    */
   virtual EcBoolean isStrictlyMonotonic
      (
      const EcXmlReal& firstPoint,
      const EcXmlReal& middlePoint,
      const EcXmlReal& lastPoint
      );
};

} // namespace Ec

#endif // ec_HardwareCalibrationPointVector_H_
