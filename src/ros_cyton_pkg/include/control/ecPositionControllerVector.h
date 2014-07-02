#ifndef ecPositionControllerVector_H_
#define ecPositionControllerVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecPositionControllerVector.h
/// @class EcPositionControllerVector
/// @brief Holds a description of a vector of general position controllers.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecPositionController.h"
#include <xml/ecXmlVarVectType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// type definition of XML variable vector of EcPositionController to be used as a base class
typedef EcXmlVariableVectorType<EcPositionController> EcBasePositionControllerVector;

/// Holds a description of a vector of general end effectors.
class EC_ACTIN_CONTROL_DECL EcPositionControllerVector : public EcBasePositionControllerVector
{
public:
   /// default constructor
   EcPositionControllerVector
      (
      );

   /// destructor
   virtual ~EcPositionControllerVector
      (
      );

   /// copy constructor
   EcPositionControllerVector
      (
      const EcPositionControllerVector& orig
      );

   /// assignment operator
   EcPositionControllerVector& operator=
      (
      const EcPositionControllerVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcPositionControllerVector& orig
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

#endif // ecPositionControllerVector_H_
