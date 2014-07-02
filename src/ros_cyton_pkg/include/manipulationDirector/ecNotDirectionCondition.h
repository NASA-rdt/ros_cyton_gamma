#ifndef ecNotDirectionCondition_H_
#define ecNotDirectionCondition_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecNotDirectionCondition.h
/// @class EcNotDirectionCondition
/// @brief Concrete implementation of EcUnaryDirectionCondition for returning the negative test of a wrapped condition.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecUnaryDirectionCondition.h"

/// Concrete implementation of EcUnaryDirectionCondition for returning the negative test of a wrapped condition.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcNotDirectionCondition : public EcUnaryDirectionCondition
{
public:
   /// default constructor
   EcNotDirectionCondition
      (
      );

   /// destructor
   virtual ~EcNotDirectionCondition
      (
      );

   /// copy constructor
   EcNotDirectionCondition
      (
      const EcNotDirectionCondition& orig
      );

   /// assignment operator
   EcNotDirectionCondition& operator=
      (
      const EcNotDirectionCondition& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcNotDirectionCondition& orig
      ) const;

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// test the condition
   virtual EcBoolean test
      (
      const EcManipulationDirector&             director,
      const EcManipulationDirectorUpdateParams& params,
      const EcString&                           role,
      const EcManipulationDirectorState&        dstate
      ) const;

   /// return a text description of the condition
   virtual EcString text
      (
      ) const;

   /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// static creator function
   static EcXmlObject* creator
      (
      );
};

#endif // ecNotDirectionCondition_H_
