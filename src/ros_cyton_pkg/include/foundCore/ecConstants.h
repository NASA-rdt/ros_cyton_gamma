#ifndef ecConstants_H_
#define ecConstants_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecConstants.h
/// @brief A collection of constant values, both physics and programming constants.
//
//------------------------------------------------------------------------------
#include "ecTypes.h"
/**\namespace Ec
 * \brief Energid common namespace
*/

/// version of code base
const EcString    EcVersion            = "3.0.0";

/// gives a representation of true
const EcBoolean   EcTrue               = true;

/// gives a representation of false
const EcBoolean   EcFalse              = false;

/// gives an accurate value for the number Pi
const EcReal      EcPi                 = 3.14159265358979324;

/// gives an accurate value for two times Pi
const EcReal      Ec2Pi                = 6.28318530717958650;

/// gives an accurate value for Pi divided by two
const EcReal      EcHalfPi             = 1.57079632679489662;

/// gives an accurate value for the number E
const EcReal      EcE                  = 2.71828182845904524;

/// gives an accurate value for the square root of 2
const EcReal      EcSqrt2              = 1.41421356237309505;

/// gives an accurate value for the square root of 3
const EcReal      EcSqrt3              = 1.73205080756887729;

/// a big 64-bit floating-point number
const EcReal      EcBIG                = 1e300;

/// a small 64-bit floating-point number
const EcReal      EcSMALL              = 1e-300;

/// a small number to measure numerical errors
const EcReal      EcNANO               = 1e-9;

/// a small number to measure numerical errors
const EcReal      EcMICRO              = 1e-6;

/// a small number to measure numerical errors
const EcReal      EcMILLI              = 1e-3;

/// multiplicative conversion from inches to meters
const EcReal      EcIN2M               = 0.02540000000000000;

/// multiplicative conversion from meters to inches
const EcReal      EcM2IN               = 39.37007874015748;

/// multiplicative conversion from radians to degrees
const EcReal      EcRAD2DEG            = 57.29577951308232088;

/// multiplicative conversion from degrees to radians
const EcReal      EcDEG2RAD            = 0.0174532925199432958;

/// the biggest 32-bit unsigned integer (4294967295)
const EcU32       EcMAXU32             = 0xFFFFFFFF;

/// the biggest 32-bit signed integer (2147483647)
const EcInt32     EcMAXINT32           = 0x7FFFFFFF;

/// the smallest 32-bit signed integer (-2147483648)
const EcInt32     EcMININT32           = -2147483647 -1;

/// a null pointer variable
#define EcNULL                         0

#endif // ecConstants_H_
