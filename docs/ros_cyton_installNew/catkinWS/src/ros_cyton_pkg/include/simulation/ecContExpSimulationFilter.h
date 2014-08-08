#ifndef ecContExpSimulationFilter_H_
#define ecContExpSimulationFilter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpSimulationFilter.h
/// @class EcControlExpressionSimulationFilter
/// @brief This simulates forward in time to verify the effectiveness
///        of the current joint rate commands.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecDynSimulatorSystem.h"
#include "ecJointControllerSystem.h"
#include <control/ecContExpContainer.h>
#include <control/ecExpElement.h>

/// This simulates forward in time to verify the effectiveness of the current joint rate commands.
class EC_ACTIN_SIMULATION_DECL EcControlExpressionSimulationFilter : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionSimulationFilter
      (
      );

   /// constructor from an EcControlExpressionContainer pointer
   EcControlExpressionSimulationFilter
      (
      const EcControlExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionSimulationFilter
      (
      );

   /// copy constructor
   EcControlExpressionSimulationFilter
      (
      const EcControlExpressionSimulationFilter& orig
      );

   /// assignment operator
   EcControlExpressionSimulationFilter& operator=
      (
      const EcControlExpressionSimulationFilter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionSimulationFilter& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

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

   /// return the value
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// test against threshold
   virtual EcBoolean testThreshold
      (
      const EcVelocityControlData& unfilteredJointRates,
      const EcXmlRealVector& simJointPositions,
      const EcReArray& weights,
      const EcReal threshold
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// initialize XML enumerations
   virtual void  registerEnumerations
      (
      );

   /// sets the container
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// gets the unfiltered rates
   virtual const EcControlExpressionContainerVector& unfilteredRates
      (
      ) const;

   /// sets the unfiltered rates
   virtual void setUnfilteredRatesContainer
      (
      const EcControlExpressionContainerVector& unfilteredRatesContainer
      );

   /// sets the unfiltered rates element
   virtual void setUnfilteredRatesElement
      (
      const EcExpressionElement& unfilteredRatesElement
      );

   /// gets the weights
   virtual const EcControlExpressionContainer& weights
      (
      ) const;

   /// sets the weights container
   virtual void setWeightsContainer
      (
      const EcControlExpressionContainer& weightsContainer
      );

   /// sets the weights element
   virtual void setWeightsElement
      (
      const EcExpressionElement& weightsElement
      );

   /// sets the joint controller
   virtual void setJointController
      (
      const EcJointControllerSystem& jointController
      );

   /// sets the dynamic simulation
   virtual void setDynamicSimulation
      (
      const EcDynamicSimulatorSystem& dynamicSimulation
      );

   /// sets the threshold
   virtual void thresholdPushBack
      (
      const EcReal threshold
      );

   /// return a token
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcControlExpressionSimulationFilter nullObject
      (
      );

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );

protected:
   /// Threshold test options
   enum THRESHOLD_OPTION
   {
      ONENORM,           ///< 1-norm
      TWONORM,           ///< 2-norm
      INFNORM            ///< Infinity norm
   };

   /// the unfiltered joint rates
   EcControlExpressionContainerVector  m_UnfilteredRates;

   /// the weights
   EcControlExpressionContainer  m_Weights;

   /// joint controller
   EcJointControllerSystem m_JointController;

   /// dynamic simulation
   mutable EcDynamicSimulatorSystem m_DynamicSimulation;

   /// threshold for joint rate error
   EcXmlRealVector m_Threshold;

   /// threshold option
   EcXmlEnumU16 m_ThresholdOption;

   /// container for desired state
   mutable EcManipulatorSystemState m_DesiredState;

   /// holds joint torques
   mutable EcManipulatorTorqueVector m_ManipulatorTorque;

   /// holds joint limit results
   mutable EcPropagationResultData m_PropagationResultData;
};

#endif // ecContExpSimulationFilter_H_
