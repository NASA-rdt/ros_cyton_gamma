#ifndef ecContExpEndMotionFilter_H_
#define ecContExpEndMotionFilter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpEndMotionFilter.h
/// @class EcControlExpressionEndEffectorMotionFilter
/// @brief This limits the ratio of a measure of the joint rates
///        to the hand motion.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include "ecContExpContainer.h"
#include "ecManipEndEffectorVel.h"
#include "ecEndEffectorTool.h"
#include <xml/ecXmlBasicType.h>

class EC_ACTIN_CONTROL_DECL EcControlExpressionEndEffectorMotionFilter : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionEndEffectorMotionFilter
      (
      );

   /// constructor from an EcControlExpressionContainer pointer
   EcControlExpressionEndEffectorMotionFilter
      (
      const EcControlExpressionContainer* containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionEndEffectorMotionFilter
      (
      );

   /// copy constructor
   EcControlExpressionEndEffectorMotionFilter
      (
      const EcControlExpressionEndEffectorMotionFilter& orig
      );

   /// assignment operator
   EcControlExpressionEndEffectorMotionFilter& operator=
      (
      const EcControlExpressionEndEffectorMotionFilter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionEndEffectorMotionFilter& orig
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
   /// @return (EcXmlObject*) The new xml object
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return the value
   /// @return (EcVelocityControlData&) The velocity control data
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// sets the container
   /// @param[in] container (EcXmlBaseVariableCompoundType*) value to set
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// gets the hand-velocity weights container
   /// @return TODO
   virtual const EcControlExpressionContainer& handVelocityWeights
      (
      ) const;

   /// sets the hand-velocity weights container
   /// @param[in] handVelocityWeightsContainer (EcControlExpressionContainer&) TODO
   virtual void setHandVelocityWeightsContainer
      (
      const EcControlExpressionContainer& handVelocityWeightsContainer
      );

   /// sets the hand-velocity weights element
   /// @return The hand velocity weights
   virtual void setHandVelocityWeightsElement
      (
      const EcExpressionElement& handVelocityWeightsElement
      );

   /// gets the joint-rate weights container
   /// @return TODO
   virtual const EcControlExpressionContainer& jointRateWeights
      (
      ) const;

   /// sets the joint-rate weights container
   /// @param[in] jointRateWeightsContainer (EcControlExpressionContainer&) value to set
   virtual void setJointRateWeightsContainer
      (
      const EcControlExpressionContainer& jointRateWeightsContainer
      );

   /// sets the joint-rate weights element
   /// @param[in] jointRateWeightsElement (EcExpressionElement&) value to set
   virtual void setJointRateWeightsElement
      (
      const EcExpressionElement& jointRateWeightsElement
      );

   /// gets the unfiltered rates
   /// @return TODO
   virtual const EcControlExpressionContainer& unfilteredRates
      (
      ) const;

   /// sets the unfiltered rates
   /// @param[in] unfilteredRatesContainer (EcControlExpressionContainer&) value to set
   virtual void setUnfilteredRatesContainer
      (
      const EcControlExpressionContainer& unfilteredRatesContainer
      );

   /// sets the unfiltered rates element
   /// param[in] unfilteredRatesElement (EcExpressionElement&) value to set
   virtual void setUnfilteredRatesElement
      (
      const EcExpressionElement& unfilteredRatesElement
      );

   /// gets the max ratio
   /// @return (EcReal) The maximum ratio of (joint-rate measure)/(hand-velocity measure)
   virtual EcReal maxRatio
      (
      ) const;

   /// sets the threshold
   /// @param[in] maxRatio (EcReal) value to set
   virtual void setMaxRatio
      (
      EcReal maxRatio
      );

   /// gets the use-infinity-norm flag
   /// @return TODO
   virtual EcBoolean useInfinityNorm
      (
      ) const;

   /// sets the use-infinity-norm flag
   /// @param[in] useInfinityNorm (EcBoolean) flag to set, defaulted to EcTrue
   virtual void setUseInfinityNorm
      (
      EcBoolean useInfinityNorm=EcTrue
      );

   /// return a token
   /// @return The xml token value
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   /// @param[in] stream (EcXmlReader&) The xml stream to be read
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /// @param[in] stream (EcXmlWriter&) The xml stream to be written into xml file
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   /// @return (EcControlExpressionEndEffectorMotionFilter) The null object
   static EcControlExpressionEndEffectorMotionFilter nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The xml object
   static EcXmlObject* creator
      (
      );

protected:
   /// function to calculate filtered rates
   /// @param[in] unfilteredRatesRef     (EcReArray&) TODO
   /// @param[in] handVelocityWeightsRef (EcReArray&) TODO
   /// @param[in] jointRateWeightsRef    (EcReArray&) TODO
   /// @return (EcBoolean) TODO
   virtual EcBoolean calculateFilteredRates
      (
      const EcReArray& unfilteredRatesRef,
      const EcReArray& handVelocityWeightsRef,
      const EcReArray& jointRateWeightsRef
      ) const;

   /// calculates a measure of the joint rates using either the 2-norm or the infinity norm.
   /// @param[in] unfilteredRatesRef  (EcReArray&) TODO
   /// @param[in] jointRateWeightsRef (EcReArray&) TODO
   /// @return (EcReal) The calculated joint rates TODO
   virtual EcReal calculateJointRateMeasure
      (
      const EcReArray& unfilteredRatesRef,
      const EcReArray& jointRateWeightsRef
      ) const;

   /// calculates a measure of the desired hand velocity using either the 2-norm or the infinity norm.
   /// @param[in] handVelocityWeightsRef (EcReArray&) TODO
   /// @return (EcReal) TODO
   virtual EcReal calculateHandVelocityMeasure
      (
      const EcReArray& handVelocityWeightsRef
      ) const;

   /// calculates a weighted measure of a motion array using either the 2-norm or the infinity norm.
   /// @param[in] motionRef (EcReArray&) TODO
   /// @param[in] weightsRef (EcReArray&) TODO
   /// @return (EcReal) TODO
   virtual EcReal measureArray
      (
      const EcReArray& motionRef,
      const EcReArray& weightsRef
      ) const;

protected:
   /// the hand-velocity weights
   EcControlExpressionContainer  m_HandVelocityWeights;

   /// the joint-rate weights
   EcControlExpressionContainer  m_JointRateWeights;

   /// the unfiltered joint rates
   EcControlExpressionContainer  m_UnfilteredRates;

   /// the maximum ratio of (joint-rate measure)/(hand-velocity measure)
   EcXmlReal                     m_MaxRatio;

   /// a flag indicating that infinity-norm should be used
   EcXmlBoolean                  m_UseInfinityNorm;

   /// non-XML data below

   /// utility hand-motion vector
   mutable EcRealVector m_UtilityHandMotionVector;

   /// utility hand motion array
   mutable EcReArray  m_UtilityHandMotionArray;
};

#endif // ecContExpEndMotionFilter_H_
