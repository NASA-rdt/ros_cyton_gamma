#ifndef ecCollisionForceContainer_H_
#define ecCollisionForceContainer_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecCollisionForceContainer.h
/// @class EcCollisionForceContainer
/// @brief Holds an Rtpg logical expression tree.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <xml/ecBaseExpTreeContainer.h>
#include "ecBaseCollisionForceProcessor.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// Holds an collision force container
class EC_FOUNDATION_MANIPULATOR_DECL EcCollisionForceContainer : public EcBaseExpressionTreeContainer<EcBaseCollisionForceProcessor>
{
public:
   /// default constructor
   EcCollisionForceContainer
      (
      );

   /// destructor
   virtual ~EcCollisionForceContainer
      (
      );

   /// copy constructor
   EcCollisionForceContainer
      (
      const EcCollisionForceContainer& orig
      );

   /// assignment operator
   EcCollisionForceContainer& operator=
      (
      const EcCollisionForceContainer& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCollisionForceContainer& orig
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

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// get a null object
   static EcCollisionForceContainer nullObject
      (
      );
};

#endif // ecCollisionForceContainer_H_
