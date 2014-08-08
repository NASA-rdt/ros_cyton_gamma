#ifndef ecBaseXmlFactory_H_
#define ecBaseXmlFactory_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseXmlFactory.h
/// @class EcBaseXmlFactory
/// @brief An abstract base class for XML object factories.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

class EcToken;
class EcXmlObject;
typedef EcXmlObject* (*EcXmlObjectCreator)();     ///< type definition of an expression element creator function

class EC_STABLE_XML_DECL EcBaseXmlFactory
{
public:
   /// default constructor
   EcBaseXmlFactory
      (
      );

   /// destructor
   virtual ~EcBaseXmlFactory
      (
      );

   /// copy constructor
   EcBaseXmlFactory
      (
      const EcBaseXmlFactory& orig
      );

   /// assignment operator
   EcBaseXmlFactory& operator=
      (
      const EcBaseXmlFactory& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseXmlFactory& orig
      ) const;

   /// register a single optional component
   virtual void registerComponentCreator
      (
      const EcToken& token,
      EcXmlObjectCreator creator
      ) = 0;

   /// create a new object from its token
   virtual EcXmlObject* newObjectFromToken
      (
      const EcToken& token
      ) const = 0;
};

#endif // ecBaseXmlFactory_H_
