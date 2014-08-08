#ifndef ecImpedanceControlFunction_H_
#define ecImpedanceControlFunction_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecImpedanceControlFunction.h
/// @class EcImpedanceControlFunction
/// @brief Impedance control algorithm for force control
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecForceControlFunction.h"
#include <foundCommon/ecGeneralForce.h>
#include <foundCommon/ecGeneralMotion.h>
#include <xml/ecXmlVectorType.h>

/// e = K^-1*( f - M e_dd - B e_d )
class EC_ACTIN_FORCECONTROL_DECL EcImpedanceControlFunction : public EcForceControlFunction
{
public:

   /// default constructor
   EcImpedanceControlFunction
      (
      );

   /// destructor
   virtual ~EcImpedanceControlFunction
      (
      );

   /// copy constructor
   EcImpedanceControlFunction
      (
      const EcImpedanceControlFunction& orig
      );

   /// assignment operator
   EcImpedanceControlFunction& operator=
      (
      const EcImpedanceControlFunction& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcImpedanceControlFunction& orig
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

   /// token
   virtual const EcToken& token
      (
      ) const;

   /// get M
   virtual const EcXmlRealVector& M
      (
      ) const;

   /// set M
   virtual void setM
      (
      const EcXmlRealVector& value
      );

   /// get B
   virtual const EcXmlRealVector& B
      (
      ) const;

   /// set B
   virtual void setB
      (
      const EcXmlRealVector& value
      );

   /// get K
   virtual const EcXmlRealVector& K
      (
      ) const;

   /// set K
   virtual void setK
      (
      const EcXmlRealVector& value
      );

   /// \copydoc EcForceControlFunction::reset()
   virtual void reset
      (
      );

   /// \copydoc EcForceControlFunction::computeDifferential()
   virtual EcBoolean computeDifferential
      (
      EcReal deltaTime,
      const EcXmlRealVector& measuredForce,
      const EcXmlRealVector& desiredForce,
      EcRealVector& differential
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

   /// the M term in e = K^-1*( f - M e_dd - B e_d )
   EcXmlRealVector         m_M;
   
   /// the B term in e = K^-1*( f - M e_dd - B e_d )
   EcXmlRealVector         m_B;

   /// the K term in e = K^-1*( f - M e_dd - B e_d )
   EcXmlRealVector         m_K;

   // non-XML data
   /// previous evaluation of Diff = ((desiredForce-measuredForce) - M*DiffDotDot - B*DiffDot)/K 
   mutable EcRealVector         m_PrevDiff;
   /// time derivative of Diff 
   mutable EcRealVector         m_DiffDot;
   /// previous time derivative of Diff 
   mutable EcRealVector         m_PrevDiffDot;
   /// 2nd time derivative of Diff 
   mutable EcRealVector         m_DiffDotDot;
};

#endif // ecImpedanceControlFunction_H_
