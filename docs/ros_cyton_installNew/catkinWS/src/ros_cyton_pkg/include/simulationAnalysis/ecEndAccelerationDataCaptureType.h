#ifndef ecEndAccelerationDataCaptureType_H_
#define ecEndAccelerationDataCaptureType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecEndAccelerationDataCaptureType.h
/// @class EcEndEffectorAccelerationDataCaptureType
/// @brief A class for capturing end effector velocity.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecDataCaptureType.h"

#include <manipulator/ecManipActiveState.h>

/// A class for capturing end effector velocity.
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcEndEffectorAccelerationDataCaptureType : public EcDataCaptureType
{
public:
   /// default constructor
   EcEndEffectorAccelerationDataCaptureType
      (
      );

   /// destructor
   virtual ~EcEndEffectorAccelerationDataCaptureType
      (
      );

   /// copy constructor
   EcEndEffectorAccelerationDataCaptureType
      (
      const EcEndEffectorAccelerationDataCaptureType& orig
      );

   /// assignment operator
   EcEndEffectorAccelerationDataCaptureType& operator=
      (
      const EcEndEffectorAccelerationDataCaptureType& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcEndEffectorAccelerationDataCaptureType& orig
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// return a description. This is more human-readable than the token and should be used in GUI in place of the token.
   virtual const EcString& description
      (
      ) const;

   /// capture the data
   virtual EcBoolean captureData
      (
      const EcSystemSimulation& simulation,
      const EcU32&      manipIndex,
      const EcU32&      eeIndex
      ) const;

   /// return the data size.  This will match the number of labels
   virtual const EcU32 dataSize
      (
      ) const;

   /// returns a type
   virtual EcU32 type
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
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

protected:
   /// A utility active state
   mutable EcManipulatorActiveState   m_UtilityActiveState;

   static const EcString      m_theDescription;    ///< description
   static const EcU32         m_theDataSize;       ///< data size
};

#endif // ecEndAccelerationDataCaptureType_H_
