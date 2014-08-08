#ifndef ecMobilityParameters_H_
#define ecMobilityParameters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecMobilityParameters.h
/// @class EcMobilityParameters
/// @brief A class containing mobility parameters
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>

/**
This class contains the run-time parameters that are used to compute mobility forces. This is different than EcWheelParameters and EcSoilParameters in that the mobility parameters usually vary during the operation whereas tool and soil parameters are fixed. This class can be extended if a specific mobility model requires more run-time parameters.
*/
class EC_ACTIN_SOILMECHANICS_DECL EcMobilityParameters
{
public:
   /// Macro declares a constructor, destructor,
   /// copy constructor, equal operator, and equality operator
   ECDECLARE_BIGFOUR(EcMobilityParameters);

   /// get the sinkage
   virtual EcReal sinkage
      (
      ) const
   { return m_Sinkage; }

   /// set the sinkage
   virtual void setSinkage
      (
      EcReal value
      )
   { m_Sinkage=value; }

   /// get the slip ratio
   virtual EcReal slipRatio
      (
      ) const
   { return m_SlipRatio; }

   /// set the slip ratio
   virtual void setSlipRatio
      (
      EcReal value
      )
   { m_SlipRatio=value; }

   /// get the slip angle
   virtual EcReal slipAngle
      (
      ) const
   { return m_SlipAngle; }

   /// set the slip angle
   virtual void setSlipAngle
      (
      EcReal value
      )
   { m_SlipAngle=value; }

   /// get the gravity
   virtual EcReal gravity
      (
      ) const
   { return m_Gravity; }

   /// set the gravity
   virtual void setGravity
      (
      EcReal value
      )
   { m_Gravity=value; }

protected:
   EcReal               m_Sinkage;     ///< the sinkage
   EcReal               m_SlipRatio;   ///< the slip ratio
   EcReal               m_SlipAngle;   ///< the slip angle
   EcReal               m_Gravity;     ///< the gravity
};

#endif // ecMobilityParameters_H_
