#ifndef ecReachTargetDataCaptureType_H_
#define ecReachTargetDataCaptureType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecReachTargetDataCaptureType.h
/// @class EcReachTargetDataCaptureType
/// @brief A class for capturing whether EE target location is reached.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecDataCaptureType.h"

#include <foundCommon/ecEndEffectorPlacement.h>
#include <manipulator/ecManipActiveState.h>

/// A class for capturing whether EE target location is reached.
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcReachTargetDataCaptureType : public EcDataCaptureType
{
public:
   /// default constructor
   EcReachTargetDataCaptureType
      (
      );

   /// destructor
   virtual ~EcReachTargetDataCaptureType
      (
      );

   /// copy constructor
   EcReachTargetDataCaptureType
      (
      const EcReachTargetDataCaptureType& orig
      );

   /// assignment operator
   EcReachTargetDataCaptureType& operator=
      (
      const EcReachTargetDataCaptureType& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcReachTargetDataCaptureType& orig
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// return a description. This is more human-readable than the token and should be used in GUI in place of the token.
   virtual const EcString& description
      (
      ) const;

   /// gets the translation tolerance. The desired and actual EE locations must be with this tolerance for the target to be considered reached.
   virtual EcReal translationTolerance
      (
      ) const;

   /// sets the translation tolerance.
   virtual void setTranslationTolerance
      (
      EcReal value
      );

   /// gets the orientation tolerance. The desired and actual EE locations must be with this tolerance for the target to be considered reached.
   virtual EcReal orientationTolerance
      (
      ) const;

   /// sets the orientation tolerance.
   virtual void setOrientationTolerance
      (
      EcReal value
      );

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
   /// The translation tolerance used to test reach
   EcXmlReal                  m_TranslationTolerance;

   /// The orientation tolerance used to test reach
   EcXmlReal                  m_OrientationTolerance;

   // non-XML data
   /// A utility active state
   mutable EcManipulatorActiveState    m_UtilityActiveState;

   /// The target EE location
   mutable EcEndEffectorPlacement      m_Target;

   /// The actual EE location
   mutable EcEndEffectorPlacement      m_Actual;

   static const EcString      m_theDescription;    ///< description
   static const EcU32         m_theDataSize;       ///< data size
};

#endif // ecReachTargetDataCaptureType_H_
