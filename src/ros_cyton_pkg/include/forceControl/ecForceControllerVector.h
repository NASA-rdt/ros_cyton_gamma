#ifndef ecForceControllerVector_H_
#define ecForceControllerVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecForceControllerVector.h
/// @class EcForceControllerVector
/// @brief Holds a description of a vector of force controllers.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseForceController.h"
#include <xml/ecXmlVarVectType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// vector of EcBaseForceController
typedef EcXmlVariableVectorType<EcBaseForceController> EcBaseForceControllerVector;

/// Holds a description of a vector of force controllers.
class EC_ACTIN_FORCECONTROL_DECL EcForceControllerVector : public EcBaseForceControllerVector
{
public:
   /// default constructor
   EcForceControllerVector
      (
      );

   /// destructor
   virtual ~EcForceControllerVector
      (
      );

   /// copy constructor
   EcForceControllerVector
      (
      const EcForceControllerVector& orig
      );

   /// assignment operator
   EcForceControllerVector& operator=
      (
      const EcForceControllerVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcForceControllerVector& orig
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

   /// get a null object
   static EcForceControllerVector nullObject
      (
      );

   /// given a force controller token name, return a force controller object
   virtual EcBaseForceController* forceControllerFromToken
      (
      const EcToken& token
      );
};

#endif // ecForceControllerVector_H_
