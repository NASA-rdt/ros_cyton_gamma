#ifndef ecExcavationParameters_H_
#define ecExcavationParameters_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecExcavationParameters.h
/// @class EcExcavationParameters
/// @brief A class containing excavation parameters
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecMacros.h>

/**
This class contains the run-time parameters that are used to compute excavation forces. This is different than EcToolParameters and EcSoilParameters in that the excavation parameters can vary during the operation whereas tool and soil parameters are fixed.
*/
class EC_ACTIN_SOILMECHANICS_DECL EcExcavationParameters
{
public:
   /// Macro declares a constructor, destructor,
   /// copy constructor, equal operator, and equality operator
   ECDECLARE_BIGFOUR(EcExcavationParameters);

   /// get the depth of the excavation tool
   virtual EcReal depth
      (
      ) const
   { return m_Depth; }

   /// set the depth of the excavation tool
   virtual void setDepth
      (
      EcReal value
      )
   { m_Depth=value; }

   /// get the rake angle of the excavation tool
   virtual EcReal rakeAngle
      (
      ) const
   { return m_RakeAngle; }

   /// set the rake angle of the excavation tool
   virtual void setRakeAngle
      (
      EcReal value
      )
   { m_RakeAngle=value; }

   /// get the surcharge mass in kg/m^2
   virtual EcReal surchargeMass
      (
      ) const
   { return m_SurchargeMass; }

   /// set the surcharge mass in kg/m^2
   virtual void setSurchargeMass
      (
      EcReal value
      )
   { m_SurchargeMass=value; }

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

   /// get the tool speed
   virtual EcReal toolSpeed
      (
      ) const
   { return m_ToolSpeed; }

   /// set the tool speed
   virtual void setToolSpeed
      (
      EcReal value
      )
   { m_ToolSpeed=value; }
protected:
   EcReal               m_Depth;          ///< the depth of the excavation tool
   EcReal               m_RakeAngle;      ///< the rake angle of the excavation tool
   EcReal               m_SurchargeMass;  ///< the surcharge mass in kg/m^2
   EcReal               m_Gravity;        ///< the gravity
   EcReal               m_ToolSpeed;      ///< the tool speed
};

#endif // ecExcavationParameters_H_
