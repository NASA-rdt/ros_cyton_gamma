#ifndef ecContExpSingAvoid_H_
#define ecContExpSingAvoid_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpSingAvoid.h
/// @class EcControlExpressionSingularityAvoidance
/// @brief This expression returns a vector that will drive joints
///        toward a singularity.  The negative will drive away from a singularity.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include "ecFiniteDifferenceTool.h"
#include <measure/ecSingProxFunction.h>

/// This expression returns a vector that will drive joints toward a singularity.  The negative will drive away from a singularity.
class EC_ACTIN_CONTROL_DECL EcControlExpressionSingularityAvoidance : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionSingularityAvoidance
      (
      );

   /// constructor from an EcExpressionContainer pointer
   /// @param[in] containerPointer (EcExpressionContainer*) expression container pointer
   EcControlExpressionSingularityAvoidance
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionSingularityAvoidance
      (
      );

   /// copy constructor
   EcControlExpressionSingularityAvoidance
      (
      const EcControlExpressionSingularityAvoidance& orig
      );

   /// assignment operator
   EcControlExpressionSingularityAvoidance& operator=
      (
      const EcControlExpressionSingularityAvoidance& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionSingularityAvoidance& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   /// @return (EcXmlObject*) the xml object pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   /// @param[in] other (EcXmlObject*) The xml object pointer
   /// @return (EcBoolean) Flag indicating the status
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   /// @return (EcXmlObject*) The xml object pointer
   virtual EcXmlObject* newObject
      (
      ) const;

   /// get the input weights
   /// @return (EcXmlRealVector&) TODO
   virtual const EcXmlRealVector& inputWeights
      (
      ) const;

   /// set the input weights
   /// @param[in] inputWeights (EcXmlRealVector&) Value to set the input weights
   virtual void setInputWeights
      (
      const EcXmlRealVector& inputWeights
      );

   /// get the output weights
   /// @return outputWeights (EcXmlRealVector&) TODO
   virtual const EcXmlRealVector& outputWeights
      (
      ) const;

   /// set the output weights
   /// @param[in] outputWeights (EcXmlRealVector&) TODO
   virtual void setOutputWeights
      (
      const EcXmlRealVector& outputWeights
      );

   /// return the value
   /// @return (EcVelocityControlData&) The velocity control data
   virtual const EcVelocityControlData& value
      (
      ) const;

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// return a token
   /// @return (EcToken&) the xml token
   virtual const EcToken& token
      (
      ) const;

   /// read this object from an XML stream
   /// @param[in] stream (EcXmlReader&) stream to be read from xml file
   /// @return flag indicating the status
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   /// @param[in] stream (EcXmlWriter&) stream to be written into xml file
   /// @return Flag indicating the status
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   /// @return (EcControlExpressionSingularityAvoidance) The control expression singularity avoidance null object
   static EcControlExpressionSingularityAvoidance nullObject
      (
      );

   /// token for this class
   /// @return (EcToken&) The xml class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The xml object
   static EcXmlObject* creator
      (
      );

protected:
   /// a vector of input weights
   EcXmlRealVector m_InputWeights;

   /// a vector of output weights
   EcXmlRealVector m_OutputWeights;

   /// utility finite-difference tool
   mutable EcFiniteDifferenceTool m_FiniteDifferenceTool;

   /// utility function
   mutable EcSingularityProximityFunction m_SingularityProximityFunction;
};

#endif // ecContExpSingAvoid_H_
