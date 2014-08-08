#ifndef ecAndDirectionCondition_H_
#define ecAndDirectionCondition_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecAndDirectionCondition.h
/// @class EcAndDirectionCondition
/// @brief Concrete implementation of EcBinaryDirectionCondition for returning the logical AND of two conditions.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecBinaryDirectionCondition.h"

/// Concrete implementation of EcBinaryDirectionCondition for returning the logical AND of two conditions.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcAndDirectionCondition : public EcBinaryDirectionCondition
{
public:
   /// default constructor
   EcAndDirectionCondition
      (
      );

   /// destructor
   virtual ~EcAndDirectionCondition
      (
      );

   /// copy constructor
   EcAndDirectionCondition
      (
      const EcAndDirectionCondition& orig
      );

   /// assignment operator
   EcAndDirectionCondition& operator=
      (
      const EcAndDirectionCondition& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcAndDirectionCondition& orig
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

#endif // ecAndDirectionCondition_H_
