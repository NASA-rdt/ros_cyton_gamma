#ifndef ecJointVelocityDataCaptureType_H_
#define ecJointVelocityDataCaptureType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecJointVelocityDataCaptureType.h
/// @class EcJointVelocityDataCaptureType
/// @brief A class for capturing joint velocities.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecDataCaptureType.h"

/// A class for capturing joint velocities.
/// For dynamic simulation, a joint velocity is obtained directly from dynamic simulator
/// For kinematic simulation, a joint velocity is computed using finite-differencing of the joint position
/// from the position control system. If a joint velocity that is a direct result from the conttrol is
/// desired, one should use EcControlOutputJointVelocityDataCaptureType instead.
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcJointVelocityDataCaptureType : public EcDataCaptureType
{
public:
   /// default constructor
   EcJointVelocityDataCaptureType
      (
      );

   /// destructor
   virtual ~EcJointVelocityDataCaptureType
      (
      );

   /// copy constructor
   EcJointVelocityDataCaptureType
      (
      const EcJointVelocityDataCaptureType& orig
      );

   /// assignment operator
   EcJointVelocityDataCaptureType& operator=
      (
      const EcJointVelocityDataCaptureType& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcJointVelocityDataCaptureType& orig
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
      const EcU32&      linkIndex
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
   mutable EcReal   m_LastTime;           ///< cache of the last time. used to compute the joint velocity
   mutable EcReal   m_LastJointPosition;  ///< cache of the last joint position. used to compute the joint velocity

   static const EcString      m_theDescription;    ///< description
   static const EcU32         m_theDataSize;       ///< data size
};

#endif // ecJointVelocityDataCaptureType_H_
