#ifndef ecLinkInteractionsVector_H_
#define ecLinkInteractionsVector_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecLinkInteractionsVector.h
/// @class EcLinkInteractionsVector
/// @brief Holds a description of a vector of link interactions.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseLinkInteractions.h"
#include <xml/ecXmlVarVectType.h>

/// type definition of XML variable vector of EcBaseLinkInteractions to be used as a base class
typedef EcXmlVariableVectorType<EcBaseLinkInteractions>
   EcBaseLinkInteractionsVector;

/** Holds a description of a vector of link interactions.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcLinkInteractionsVector : public EcBaseLinkInteractionsVector
{
public:
   /// default constructor
   EcLinkInteractionsVector
      (
      );

   /// destructor
   virtual ~EcLinkInteractionsVector
      (
      );

   /// copy constructor
   EcLinkInteractionsVector
      (
      const EcLinkInteractionsVector& orig
      );

   /// assignment operator
   EcLinkInteractionsVector& operator=
      (
      const EcLinkInteractionsVector& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLinkInteractionsVector& orig
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
   static EcLinkInteractionsVector nullObject
      (
      );
};

#endif // ecLinkInteractionsVector_H_
