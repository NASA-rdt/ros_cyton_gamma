#ifndef ecBasePositionDataCaptureType_H_
#define ecBasePositionDataCaptureType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecBasePositionDataCaptureType.h
/// @class EcBasePositionDataCaptureType
/// @brief A class for capturing base positions.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecDataCaptureType.h"

/// A class for capturing base positions.
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcBasePositionDataCaptureType : public EcDataCaptureType
{
public:
   /// default constructor
   EcBasePositionDataCaptureType
      (
      );

   /// destructor
   virtual ~EcBasePositionDataCaptureType
      (
      );

   /// copy constructor
   EcBasePositionDataCaptureType
      (
      const EcBasePositionDataCaptureType& orig
      );

   /// assignment operator
   EcBasePositionDataCaptureType& operator=
      (
      const EcBasePositionDataCaptureType& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBasePositionDataCaptureType& orig
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

#endif // ecBasePositionDataCaptureType_H_
