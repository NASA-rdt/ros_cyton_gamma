#ifndef EcStoppingCriterionVector_H_
#define EcStoppingCriterionVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecStoppingCriterionVector.h
/// @class EcStoppingCriterionVector
/// @brief Holds a description of a vector of criteria for
///        stopping a single manipulator.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseStoppingCriterion.h"
#include <xml/ecXmlVarVectType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// type definition of XML variable vector of EcBaseStoppingCriterion to be used as a base class
typedef EcXmlVariableVectorType<EcBaseStoppingCriterion> EcBaseStoppingCriterionVector;

/** Holds a vector of criteria for stopping a manipulator.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcStoppingCriterionVector : public EcBaseStoppingCriterionVector
{
public:
   /// default constructor
   EcStoppingCriterionVector
      (
      );

   /// destructor
   virtual ~EcStoppingCriterionVector
      (
      );

   /// copy constructor
   EcStoppingCriterionVector
      (
      const EcStoppingCriterionVector& orig
      );

   /// assignment operator
   EcStoppingCriterionVector& operator=
      (
      const EcStoppingCriterionVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcStoppingCriterionVector& orig
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

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// register all component creators
   virtual void registerComponentCreators
      (
      );

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcStoppingCriterionVector nullObject
      (
      );
};

/// type definition of XML map of EcXmlString and EcStoppingCriterionVector
typedef EcXmlMapType<EcXmlString,EcStoppingCriterionVector>EcStringStoppingCriterionVectorMap;

#endif // EcStoppingCriterionVector_H_
