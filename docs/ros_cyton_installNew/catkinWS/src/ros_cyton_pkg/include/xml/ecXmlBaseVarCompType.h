#ifndef ecXmlBaseVarCompType_H_
#define ecXmlBaseVarCompType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlBaseVarCompType.h
/// @class EcXmlBaseVariableCompoundType
/// @brief Holds a compound set of XML data.
/// @details Creator functions are registered for variable compound types
///         (holding unions, etc.).
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecXmlObject.h"
#include "ecXmlVectorType.h"
#include "ecXmlFactory.h"

class EC_STABLE_XML_DECL EcXmlBaseVariableCompoundType : public EcXmlObject
{
public:
   /// #ECDECLARE_BIGFOUR(EcCls) Macro declares a constructor, destructor,
   /// copy constructor, equal operator, and equality operator
   ECDECLARE_BIGFOUR(EcXmlBaseVariableCompoundType);
   ECXMLOBJECT_ACCEPT(EcXmlBaseVariableCompoundType)

   /// xml-initialize
   virtual EcBoolean xmlInit
      (
      );

   /// return a string token
   virtual const EcToken& token
      (
      ) const = 0;

   /// register all component creators - should be subclassed in child
   virtual void registerComponentCreators
      (
      ) = 0;

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

   /// write this object to an XML stream
   virtual EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

   /// gets the library names (minus extension)
   virtual const EcXmlStringVector& addLibraries
      (
      ) const;

   /// sets the library names (minus extension)
   virtual void setAddLibraries
      (
      const EcXmlStringVector& addLibraries
      );

   /// gets the creator map
   virtual const EcXmlCreatorMap& creatorMap
      (
      ) const;

protected:
   /// read an XML object from a stream after reading the start tag
   /// return value signals success or failure
   virtual EcBoolean readValueFromToken
      (
      const EcToken& token,
      EcXmlReader& stream
      ) = 0;

   /// process the add libraries
   virtual void processLibraries
      (
      );

   /// A map holding the relationship between string labels and subcomponents.
   EcXmlFactory m_XmlFactory;

   /// the arry of library names
   EcXmlStringVector m_AddLibraries;
};

#endif // ecXmlBaseVarCompType_H_
