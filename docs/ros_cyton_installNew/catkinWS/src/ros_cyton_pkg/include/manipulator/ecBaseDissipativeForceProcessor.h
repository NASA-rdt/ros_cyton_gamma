#ifndef ecBaseDissipativeForceProcessor_H_
#define ecBaseDissipativeForceProcessor_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseDissipativeForceProcessor.h
/// @class EcBaseDissipativeForceProcessor
/// @brief Defines a base class for all dissipative force processors
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecBaseExpTreeElement.h>
#include "ecFrictionCoefficientLookupTool.h"

class EcDissipativeForceInput;
class EcGeneralForce;
class EcDissipativeForceOutput;

/// Defines a base class for all dissipative force processors
class EC_FOUNDATION_MANIPULATOR_DECL EcBaseDissipativeForceProcessor : public EcBaseExpressionTreeElement
{
public:
   /// constructor
	EcBaseDissipativeForceProcessor
      (
      );

   /// destructor
	virtual ~EcBaseDissipativeForceProcessor
      (
      );

   /// copy constructor
   EcBaseDissipativeForceProcessor
      (
      const EcBaseDissipativeForceProcessor& orig
      );

   /// assignment operator
   EcBaseDissipativeForceProcessor& operator=
      (
      const EcBaseDissipativeForceProcessor& orig
      );

   /// equal operator
   EcBoolean operator==
      (
      const EcBaseDissipativeForceProcessor& orig
      ) const;

   /// register xml components
   virtual void registerComponents
      (
      );

   /// set the friction coefficient LUT
   virtual void setFrictionCoefficientLUT
      (
      const EcFrictionCoefficientLookupTool& lut
      );

   /// get the friction coefficient LUT - const version
   virtual const EcFrictionCoefficientLookupTool& frictionCoefficientLUT
      (
      )const;

   /// get the friction coefficient LUT - nonconst version
   virtual EcFrictionCoefficientLookupTool& frictionCoefficientLUT
      (
      );

   /// compute the dissipative force
   /**
    * @param inputData The information needed to compute the dissipative force
    * @param outputData The output data returned from the dissipative force processor
    * @return True if successful or false otherwise
    */
   virtual EcBoolean process
      (
      const EcDissipativeForceInput& inputData,
      EcDissipativeForceOutput& outputData
      )const = 0;

protected:
   /// tool for looking up and/or deriving friction coefficients for
   /// pairs of material types
   EcFrictionCoefficientLookupTool m_FrictionLookupTool;
};

#endif // ecBaseDissipativeForceProcessor_H_
