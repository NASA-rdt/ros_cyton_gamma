#ifndef ecXmlFactory_H_
#define ecXmlFactory_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlFactory.h
/// @class EcXmlFactory
/// @brief Holds a factory for creating XML objects.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecBaseXmlFactory.h"
#include "ecXmlObject.h"
#include "ecToken.h"
#include <map>

class EC_STABLE_XML_DECL EcXmlFactory : public EcBaseXmlFactory
{
public:
   /// default constructor
   EcXmlFactory
      (
      );

   /// destructor
   virtual ~EcXmlFactory
      (
      );

   /// copy constructor
   EcXmlFactory
      (
      const EcXmlFactory& orig
      );

   /// assignment operator
   EcXmlFactory& operator=
      (
      const EcXmlFactory& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcXmlFactory& orig
      ) const;

   /// register a single optional component
   virtual void registerComponentCreator
      (
      const EcToken& token,
      EcXmlObjectCreator creator
      );

   /// create a new object from its token
   virtual EcXmlObject* newObjectFromToken
      (
      const EcToken& token
      ) const;

   /// gets the creator map
   virtual const EcXmlCreatorMap& creatorMap
      (
      ) const;

protected:
   /// A map holding the relationship between string labels and subcomponents.
   EcXmlCreatorMap m_CreatorMap;
};

#endif // ecXmlFactory_H_
