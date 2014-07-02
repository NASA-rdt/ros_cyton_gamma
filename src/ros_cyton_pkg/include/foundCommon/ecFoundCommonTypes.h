#ifndef ecFoundCommonTypes_H_
#define ecFoundCommonTypes_H_
//------------------------------------------------------------------------------
// Copyright (c) 2009-2013 Energid Technologies. All rights reserved.
//
/// @file ecFoundCommonTypes.h
/// @brief Common types for the foundCommon project
/// @details namespace EcFoundCommon
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>
#include <foundCore/ecTypes.h>

// forward declarations

/// declaration for a readable/writable wrapper for rudimentary data types
template <typename T> class              EcXmlBasicType;

/// an XML-readable/writable wrapper around an EcReal
typedef EcXmlBasicType<EcReal>           EcXmlReal;

/// declaration for a readable/writable vector of objects
template <typename T> class              EcXmlVectorType;

/// an XML-readable/writable vector of EcReal values
typedef EcXmlVectorType<EcXmlReal>       EcXmlRealVector;

/// an XML-readable/writable vector of vectors of EcReal values
typedef EcXmlVectorType<EcXmlRealVector> EcXmlRealVectorVector;

/// forward declaration of the primary array type
class EcReArray;

namespace EcFoundCommon
{
   enum
   {
      BASEINDEX=0xFFFFFFFE,
      VOIDINDEX=0xFFFFFFFF
   };

   /// an enumeration of measurement units, linear and angular, position and derivatives
   enum UnitType
   {
      LENGTH,
      ANGLE,
      LINEAR_VELOCITY,
      ANGULAR_VELOCITY,
      LINEAR_ACCELERATION,
      ANGULAR_ACCELERATION,
      NUM_TYPES
   };

   /// A convenient method to convert from a vector of vectors to the EcReArray type
   /// @param[in] from The vector of vectors
   /// @param[out] to The EcReArray equivalent
   void EC_FOUNDATION_FOUNDCOMMON_DECL toReArray
      (
      const EcXmlRealVectorVector& from,
      EcReArray& to
      );
}

#endif // ecFoundCommonTypes_H_
