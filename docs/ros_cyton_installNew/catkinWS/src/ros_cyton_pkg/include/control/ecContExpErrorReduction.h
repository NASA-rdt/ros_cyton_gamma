#ifndef ecContExpErrorReduction_H_
#define ecContExpErrorReduction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecContExpErrorReduction.h
/// @class EcControlExpressionErrorReduction
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlBasicType.h>
#include "ecExpElement.h"
#include "ecExpContainer.h"
#include "ecFiniteDifferenceTool.h"
#include "ecManipEndEffectorForce.h"
#include <measure/ecErrorReductionFunction.h>

/// This expression returns a vector that will drive joints toward a singularity.  The negative will drive away from a singularity.
class EC_ACTIN_CONTROL_DECL EcControlExpressionErrorReduction : public EcExpressionElement
{
public:
   /// default constructor
   EcControlExpressionErrorReduction
      (
      );

   /// constructor from an EcExpressionContainer pointer
   EcControlExpressionErrorReduction
      (
      const EcExpressionContainer*  containerPointer
      );

   /// destructor
   virtual ~EcControlExpressionErrorReduction
      (
      );

   /// copy constructor
   EcControlExpressionErrorReduction
      (
      const EcControlExpressionErrorReduction& orig
      );

   /// assignment operator
   EcControlExpressionErrorReduction& operator=
      (
      const EcControlExpressionErrorReduction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcControlExpressionErrorReduction& orig
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

   /// registers components with the parent
   virtual void registerComponents
      (
      );

   /// return a token
   virtual const EcToken& token
      (
      ) const;

   /// set end effector forces
   /// @param[in] value (EcManipulatorEndEffectorForce&) TODO
   virtual void setManipulatorEndEffectorForces
      (
      const EcManipulatorEndEffectorForce &value
      ) ;

   /// get end effector forces
   /// @return (EcManipulatorEndEffectorForce) TODO
   virtual const EcManipulatorEndEffectorForce &manipulatorEndEffectorForces
      (
      ) const ;

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
   /// @return The null object
   static EcControlExpressionErrorReduction nullObject
      (
      );

   /// set the a matrix as defined in 1.5.9.2 of the robotic control management technical description document
   /// param[in] value (EcXmlRealVectorVector&) matrix to set A matrix
   virtual void setAMatrix
      (
         EcXmlRealVectorVector& value
      ) ;

   /// get the A matrix
   /// @return The A matrix as defined in 1.5.9.2 of the robotic control management technical description document TODO
   virtual const EcXmlRealVectorVector& aMatrix
      (
      ) const ;

   /// set the covariance matrix
   /// @param[in] value (EcXmlRealVectorVector&) value to set the covariance matrix
   virtual void setCovarianceMatrix
      (
         EcXmlRealVectorVector& value
      );

   /// get the covariance matrix
   /// @return The covariance matrix
   virtual const EcXmlRealVectorVector& covarianceMatrix
      (
      ) const ;

   /// token for this class
   /// @return The class token
   static const EcToken& classToken
      (
      );

   /// static creator function
   /// @return (EcXmlObject*) The xml object created
   static EcXmlObject* creator
      (
      );

protected:
   /// the A matrix as described in 1.5.9.2 of the robotic control management technical description document
   mutable EcXmlRealVectorVector m_A ;

   /// the covariance matrix describing the joint rate error
   mutable EcXmlRealVectorVector m_CovMatrix ;

   /// the A matrix as described in 1.5.9.2 of the robotic control management technical description document
   mutable EcReArray m_UtilA ;

   /// the covarience matrix describing the joint rate error
   mutable EcReArray m_UtilCovMatrix ;

   /// error optimization function
   mutable EcErrorReductionFunction m_ErrorReductionFunction ;

   /// holds manipulator end effector forces (single frame and point)
   mutable EcManipulatorEndEffectorForce m_ManipulatorEndEffectorForce ;

   /// utility finite-difference tool
   mutable EcFiniteDifferenceTool m_FiniteDifferenceTool;
};

#endif // ecContExpErrorReduction_H_
