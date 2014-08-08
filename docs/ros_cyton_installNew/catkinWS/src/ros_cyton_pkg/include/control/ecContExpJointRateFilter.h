#ifndef ecContExpJointRateFilter_H_
#define ecContExpJointRateFilter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpJointRateFilter.h
/// @class EcControlExpressionJointRateFilter
/// @brief This expression element caps the weighted infinity
///        norm of the joint rates.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include "ecContExpContainer.h"

// forward declaration
class EcIndividualManipulator;

/// This caps the weighted infinity norm of the joint rates.
class EC_ACTIN_CONTROL_DECL EcControlExpressionJointRateFilter : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionJointRateFilter
      (
      );

   /// constructor from an EcControlExpressionContainer pointer
   EcControlExpressionJointRateFilter
      (
      const EcControlExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionJointRateFilter
      (
      );

   /// copy constructor
   EcControlExpressionJointRateFilter
      (
      const EcControlExpressionJointRateFilter& orig
      );

   /// assignment operator
   EcControlExpressionJointRateFilter& operator=
      (
      const EcControlExpressionJointRateFilter& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionJointRateFilter& orig
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
   /// @return (EcVelocityControlData&) The velocity control data
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// sets the container
   /// @param[in] container (EcXmlBaseVariableCompoundType*) value to set the container
   virtual void setContainer
      (
      const EcXmlBaseVariableCompoundType* container
      );

   /// gets the weights
   /// @return (EcControlExpressionContainer&) The weights of the control expression container
   virtual const EcControlExpressionContainer& weights
      (
      ) const;

   /// sets the weights container
   /// @param[in] weightsContainer (EcControlExpressionContainer&) set the weights into the container
   virtual void setWeightsContainer
      (
      const EcControlExpressionContainer& weightsContainer
      );

   /// sets the weights element
   /// @param[in] weightsElement (EcExpressionElement&) value to set each element of weights
   virtual void setWeightsElement
      (
      const EcExpressionElement& weightsElement
      );

   /// gets the unfiltered rates
   /// @return (EcControlExpressionContainer&) the unfiltered joint rates
   virtual const EcControlExpressionContainer& unfilteredRates
      (
      ) const;

   /// sets the unfiltered rates
   /// @param[in] unfilteredRatesContainer (EcControlExpressionContainer&) value to set the unfiltered rates container
   virtual void setUnfilteredRatesContainer
      (
      const EcControlExpressionContainer& unfilteredRatesContainer
      );

   /// sets the unfiltered rates element
   /// @param[in] unfilteredRatesElement (EcExpressionElement&) Sets each element of the unfiltered rates container
   virtual void setUnfilteredRatesElement
      (
      const EcExpressionElement& unfilteredRatesElement
      );

   /// gets the threshold
   /// @return (EcReal) TODO:What threshold?
   virtual EcReal threshold
      (
      ) const;

   /// sets the threshold
   /// @param[in] threshold (EcReal) value to set the the threshold
   virtual void setThreshold
      (
      EcReal threshold
      );

   /// Use joint rate information in manipulator to automaticaly assign appropriate values for weights and threshold.
   /// @param[in] manip (EcIndividualManipulator&) TODO
   virtual void assignParametersFromManip
      (
      const EcIndividualManipulator& manip
      );

   /// return a token
   /// @return (EcToken&) The xml token
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   /// @param[in] stream (EcXmlReader&) stream to be read from xml file
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /// @param[in] stream (EcXmlWriter&) stream to be written into xml file
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   /// @return (EcControlExpressionJointRateFilter) The null object
   static EcControlExpressionJointRateFilter nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The xml objecct pointer
   static EcXmlObject* creator
      (
      );

protected:
   /// the weights
   EcControlExpressionContainer  m_Weights;

   /// the unfiltered joint rates
   EcControlExpressionContainer  m_UnfilteredRates;

   /// the threshold
   EcXmlReal m_Threshold;
};

#endif // ecContExpJointRateFilter_H_
