#ifndef ecPositionControlOutputFilterVector_H_
#define ecPositionControlOutputFilterVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecPositionControlOutputFilterVector.h
/// @class EcPositionControlOutputFilterVector
/// @brief Holds a description of a vector of filters for the output of
///        position control.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBasePositionControlOutputFilter.h"
#include <xml/ecXmlVarVectType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// type definition of XML variable vector of EcBasePositionControlOutputFilter to be used as a base class
typedef EcXmlVariableVectorType<EcBasePositionControlOutputFilter> EcBasePositionControlOutputFilterVector;

class EC_ACTIN_CONTROL_DECL EcPositionControlOutputFilterVector : public EcBasePositionControlOutputFilterVector
{
public:

   /// default constructor
   EcPositionControlOutputFilterVector
      (
      );

   /// destructor
   virtual ~EcPositionControlOutputFilterVector
      (
      );

   /// copy constructor
   EcPositionControlOutputFilterVector
      (
      const EcPositionControlOutputFilterVector& orig
      );

   /// assignment operator
   EcPositionControlOutputFilterVector& operator=
      (
      const EcPositionControlOutputFilterVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPositionControlOutputFilterVector& orig
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// register all component creators
   virtual void registerComponentCreators
      (
      );
};

#endif // ecPositionControlOutputFilterVector_H_
