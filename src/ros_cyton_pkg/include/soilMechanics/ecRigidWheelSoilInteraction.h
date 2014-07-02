#ifndef ecRigidWheelSoilInteraction_H_
#define ecRigidWheelSoilInteraction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecRigidWheelSoilInteraction.h
/// @class EcRigidWheelSoilInteraction
/// @brief Defines a class for computing interaction force between
///        rigid wheel and soil
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseRigidWheelSoilInteraction.h"
#include <function/ecGaussQuadrature.h>

#include <foundCommon/ecDataMap.h>

/// Defines a class for computing interaction force between rigid wheel and soil
class EC_ACTIN_SOILMECHANICS_DECL EcRigidWheelSoilInteraction : public EcBaseRigidWheelSoilInteraction
{
public:
   /// default constructor
   EcRigidWheelSoilInteraction
      (
      );

   /// destructor
   virtual ~EcRigidWheelSoilInteraction
      (
      );

   /// copy constructor
   EcRigidWheelSoilInteraction
      (
      const EcRigidWheelSoilInteraction& orig
      );

   /// assignment operator
   EcRigidWheelSoilInteraction& operator=
      (
      const EcRigidWheelSoilInteraction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcRigidWheelSoilInteraction& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// get an empty object
   static EcRigidWheelSoilInteraction nullObject
      (
      );

    /// return a string token
   virtual const EcToken& token
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

   /// \copydoc EcBaseRigidWheelSoilInteraction::requiredWheelProperties()
   virtual const EcStringVector& requiredWheelProperties
      (
      ) const;

   /// \copydoc EcBaseRigidWheelSoilInteraction::requiredSoilProperties()
   virtual const EcStringVector& requiredSoilProperties
      (
      ) const;

   /// \copydoc EcBaseRigidWheelSoilInteraction::setWheelProperties()
   virtual EcBoolean setWheelProperties
      (
      const EcWheelProperties& wheelProps
      );

   /// \copydoc EcBaseRigidWheelSoilInteraction::setSoilProperties()
   virtual EcBoolean setSoilProperties
      (
      const EcSoilProperties& soilProps
      );

   /// \copydoc EcBaseRigidWheelSoilInteraction::setParameters()
   virtual void setParameters
      (
      const EcMobilityParameters& params
      );

   /// \copydoc EcBaseRigidWheelSoilInteraction::tractiveForce()
   virtual EcReal tractiveForce
      (
      ) const;

   /// \copydoc EcBaseRigidWheelSoilInteraction::resistiveForce()
   virtual EcReal resistiveForce
      (
      ) const;

   /// \copydoc EcBaseRigidWheelSoilInteraction::lateralForce()
   virtual EcReal lateralForce
      (
      ) const;

   /// \copydoc EcBaseRigidWheelSoilInteraction::verticalForce()
   virtual EcReal verticalForce
      (
      ) const;

   /// \copydoc EcBaseRigidWheelSoilInteraction::wheelTorque()
   virtual EcReal wheelTorque
      (
      ) const;

protected:
   /// compute intermediate data
   virtual void computeIntermediateData
      (
      );

   /// compute and return the normal stress under the wheel at a given angle
   virtual EcReal normalStress
      (
      EcReal theta
      ) const;

   /// compute and return the tangential shear stress under the wheel at a given angle
   virtual EcReal tangentialShearStress
      (
      EcReal theta,
      EcReal normalStress
      ) const;

   /// compute and return the lateral shear stress under the wheel at a given angle
   virtual EcReal lateralShearStress
      (
      EcReal theta,
      EcReal normalStress
      ) const;

   /// compute and return the tangential shear deformation under the wheel at a given angle
   virtual EcReal tangentialShearDeformation
      (
      EcReal theta
      ) const;

   /// compute and return the lateral shear deformation under the wheel at a given angle
   virtual EcReal lateralShearDeformation
      (
      EcReal theta
      ) const;

   /// compute an return the soil compaction resistance
   virtual EcReal soilCompaction
      (
      ) const;

   /// compute an return the bulldozing resistance
   virtual EcReal bulldozingResistance
      (
      ) const;

   /// base class for integrand function object used for numerical integration
   class Integrand : public EcRealRealUnaryFunction
   {
   public:
      /// default constructor
      Integrand
         (
         ):
      m_pInteractionModel(EcNULL)
      {}

      /// set the rigid wheel-soil interaction
      void setModel
         (
         const EcRigidWheelSoilInteraction* model
         )
      { m_pInteractionModel=model; }
   protected:
      /// const pointer to the rigid wheel-soil interaction
      const EcRigidWheelSoilInteraction* m_pInteractionModel;
   };

   /// tractive force integrand function object
   class TractiveForceIntegrand : public Integrand
   {
   public:
      /// Overloaded operator() returning the integrand value for tractive force at a given wheel angle
      /**
       * @param theta Wheel angle
       * @return tractive force integrand value
       */
      EcReal operator()
         (
         EcReal theta
         )const;
   };

   /// resistive force integrand function object
   class ResistiveForceIntegrand : public Integrand
   {
   public:
      /// Overloaded operator() returning the integrand value for resistive force at a given wheel angle
      /**
       * @param theta Wheel angle
       * @return resistive force integrand value
       */
      EcReal operator()
         (
         EcReal theta
         )const;
   };

   /// lateral force integrand function object
   class LateralForceIntegrand : public Integrand
   {
   public:
      /// Overloaded operator() returning the integrand value for lateral force at a given wheel angle
      /**
       * @param theta Wheel angle
       * @return lateral force integrand value
       */
      virtual EcReal operator()
         (
         EcReal theta
         )const;
   };

   /// vertical force integrand function object
   class VerticalForceIntegrand : public Integrand
   {
   public:
      /// Overloaded operator() returning the integrand value for vertical force at a given wheel angle
      /**
       * @param theta Wheel angle
       * @return vertical force integrand value
       */
      virtual EcReal operator()
         (
         EcReal theta
         )const;
   };

   /// wheel torque integrand function object
   class WheelTorqueIntegrand : public Integrand
   {
   public:
      /// Overloaded operator() returning the integrand value for wheel torque at a given wheel angle
      /**
       * @param theta Wheel angle
       * @return wheel torque integrand value
       */
      virtual EcReal operator()
         (
         EcReal theta
         )const;
   };
protected:

   // non-XML data
   EcGaussQuadrature    m_GaussQuadrature;            ///< integrator
   EcReal               m_WheelRadius;                ///< the wheel radius
   EcReal               m_WheelWidth;                 ///< the wheel width
   EcReal               m_SoilCohesion;               ///< the soil cohesion
   EcReal               m_SoilInternalFrictionAngle;  ///< the soil interal friction angle
   EcReal               m_SoilShearDeformationModulus;///< the soil shear deformation modulus
   EcReal               m_SoilCohesiveModulus;        ///< the soil cohesive modulus
   EcReal               m_SoilFrictionalModulus;      ///< the soil friction modulus
   EcReal               m_SoilSinkageExponent;        ///< the soil sinkage exponent
   EcReal               m_SoilSinkageRatio;           ///< the soil sinkage ratio
   EcReal               m_SoilSpecificMass;           ///< the soil specific mass
   EcReal               m_Sinkage;                    ///< the sinkage
   EcReal               m_SlipRatio;                  ///< the slip ratio
   EcReal               m_SlipAngle;                  ///< the slip angle
   EcReal               m_Gravity;                    ///< the gravity

   // internal (intermediate) data
   EcReal               m_EntryAngle;                 ///< entry angle
   EcReal               m_ExitAngle;                  ///< exit angle
   EcReal               m_MaxNormalStressAngle;       ///< maximum normal stress angle
   EcReal               m_PressureSinkageFactor;      ///< pressure sinkage pressure
   EcReal               m_WheelArea;                  ///< wheel area
   TractiveForceIntegrand        m_TractiveForceIntegrand;  ///< integrand for tractive force
   ResistiveForceIntegrand       m_ResistiveForceIntegrand; ///< integrand for resistive force
   LateralForceIntegrand         m_LateralForceIntegrand;   ///< integrand for lateral force
   VerticalForceIntegrand        m_VerticalForceIntegrand;  ///< integrand for vertical force
   WheelTorqueIntegrand          m_WheelTorqueIntegrand;    ///< integrand for wheel torque

   const static EcStringVector   m_theRequiredWheelProperties; ///< the list of required wheel properties
   const static EcStringVector   m_theRequiredSoilProperties;  ///< the list of required soil properties
};

#endif // ecRigidWheelSoilInteraction_H_
