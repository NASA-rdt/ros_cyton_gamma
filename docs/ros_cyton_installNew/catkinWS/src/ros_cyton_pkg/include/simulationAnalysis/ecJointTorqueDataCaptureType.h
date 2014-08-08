#ifndef ecJointTorqueDataCaptureType_H_
#define ecJointTorqueDataCaptureType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecJointTorqueDataCaptureType.h
/// @class EcJointTorqueDataCaptureType
/// @brief A class for capturing joint torques.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecDataCaptureType.h"

/// A class for capturing joint torques.
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcJointTorqueDataCaptureType : public EcDataCaptureType
{
public:
   /// default constructor
   EcJointTorqueDataCaptureType
      (
      );

   /// destructor
   virtual ~EcJointTorqueDataCaptureType
      (
      );

   /// copy constructor
   EcJointTorqueDataCaptureType
      (
      const EcJointTorqueDataCaptureType& orig
      );

   /// assignment operator
   EcJointTorqueDataCaptureType& operator=
      (
      const EcJointTorqueDataCaptureType& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcJointTorqueDataCaptureType& orig
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
   static const EcString      m_theDescription;    ///< description
   static const EcU32         m_theDataSize;       ///< data size
};

#endif // ecJointTorqueDataCaptureType_H_
