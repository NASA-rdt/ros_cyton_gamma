#ifndef ecOutputWriterVector_H_
#define ecOutputWriterVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecOutputWriterVector.h
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <xml/ecXmlVarVectType.h>

#include "ecBaseOutputWriter.h"

#ifdef _MSC_VER
// Disable warning about explicit instantiation of base class.
#  pragma warning(disable:4661)
#endif

/// XML Vector container for EcOutputWriterVector
class EC_ACTIN_SIMULATIONANALYSIS_DECL EcOutputWriterVector : public EcXmlVariableVectorType<EcBaseOutputWriter>
{
public:
   /// default constructor
   EcOutputWriterVector
      (
      );

   /// destructor
   virtual ~EcOutputWriterVector
      (
      );

   /// copy constructor
   EcOutputWriterVector
      (
      const EcOutputWriterVector& orig
      );

   /// assignment operator
   EcOutputWriterVector& operator=
      (
      const EcOutputWriterVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcOutputWriterVector& orig
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

   /// return if the writen denoted by token is included in the vector
   virtual EcBoolean isWriterIncluded
      (
      const EcToken& token
      ) const;

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
   static EcOutputWriterVector nullObject
      (
      );
};

#endif // ecOutputWriterVector_H_
