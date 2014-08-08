#ifndef ecCollisionForceProcessorVector_H_
#define ecCollisionForceProcessorVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecCollisionForceProcessorVector.h
/// @class EcCollisionForceProcessorVector
/// @brief XML vector container for EcCollisionForceProcessor
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include <xml/ecXmlVarVectType.h>
#include <manipulator/ecBaseCollisionForceProcessor.h>

/// type definition of EcBaseCollisionForceProcessorVector
typedef EcXmlVariableVectorType<EcBaseCollisionForceProcessor> EcBaseCollisionForceProcessorVector;

/** XML vector container for EcCollisionForceProcessor
*/
class EC_ACTIN_SIMULATION_DECL EcCollisionForceProcessorVector : public EcBaseCollisionForceProcessorVector
{
public:
   /// default constructor
   EcCollisionForceProcessorVector
      (
      );

   /// destructor
   virtual ~EcCollisionForceProcessorVector
      (
      );

   /// copy constructor
   EcCollisionForceProcessorVector
      (
      const EcCollisionForceProcessorVector& orig
      );

   /// assignment operator
   EcCollisionForceProcessorVector& operator=
      (
      const EcCollisionForceProcessorVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcCollisionForceProcessorVector& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
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

   /// get an empty object
   static EcCollisionForceProcessorVector nullObject
      (
      );

    /// return a string token
   virtual const EcToken& token
      (
      ) const;

   /// token for this class
   static const EcToken& classToken
      (
      );

   /// register all component creators
   virtual void registerComponentCreators
      (
      );
};

#endif // ecCollisionForceProcessorVector_H_
