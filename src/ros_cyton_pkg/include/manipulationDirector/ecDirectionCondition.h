#ifndef ecDirectionCondition_H_
#define ecDirectionCondition_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecDirectionCondition.h
/// @class EcDirectionCondition
/// @brief Virtual base class for direction conditions.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecBaseExpTreeElement.h>

// Forward declarations
class EcManipulationDirector;
class EcManipulationDirectorState;
class EcManipulationDirectorUpdateParams;

/// Virtual base class for direction conditions.
class EC_ACTIN_MANIPULATIONDIRECTOR_DECL EcDirectionCondition : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcDirectionCondition
      (
      );

   /// destructor
   virtual ~EcDirectionCondition
      (
      );

   /// copy constructor
   EcDirectionCondition
      (
      const EcDirectionCondition& orig
      );

   /// assignment operator
   EcDirectionCondition& operator=
      (
      const EcDirectionCondition& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcDirectionCondition& orig
      ) const;

   /// get a vector of role names that are referenced within this condition
   virtual EcStringVector roleNames
      (
      const EcManipulationDirector& director
      ) const = 0;

   /// test the condition
   virtual EcBoolean test
      (
      const EcManipulationDirector&             director,
      const EcManipulationDirectorUpdateParams& params,
      const EcString&                           role,
      const EcManipulationDirectorState&        dstate
      ) const = 0;

   /// return a text description of the condition
   virtual EcString text
      (
      ) const = 0;
};

#endif // ecDirectionCondition_H_
