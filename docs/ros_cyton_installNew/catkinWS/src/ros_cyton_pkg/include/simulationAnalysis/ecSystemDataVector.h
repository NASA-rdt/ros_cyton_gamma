#ifndef ecSystemDataVector_H_
#define ecSystemDataVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecSystemDataVector.h
/// @class EcSystemDataVector
/// @brief Holds a vector of various types of system data.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecBaseSystemDataComponent.h"
#include <xml/ecXmlVarVectType.h>

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// type definition of EcBaseSystemDataVector
typedef EcXmlVariableVectorType<EcBaseSystemDataComponent> EcBaseSystemDataVector;

/** Holds a vector of various types of system data.
*/
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcSystemDataVector : public EcBaseSystemDataVector
{
public:
   /// default constructor
   EcSystemDataVector
      (
      );

   /// destructor
   virtual ~EcSystemDataVector
      (
      );

   /// copy constructor
   EcSystemDataVector
      (
      const EcSystemDataVector& orig
      );

   /// assignment operator
   EcSystemDataVector& operator=
      (
      const EcSystemDataVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcSystemDataVector& orig
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
   static EcSystemDataVector nullObject
      (
      );
};

#endif // ecSystemDataVector_H_
