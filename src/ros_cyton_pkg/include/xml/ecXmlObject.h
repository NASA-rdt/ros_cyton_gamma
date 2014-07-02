#ifndef ecXmlObject_H_
#define ecXmlObject_H_
//------------------------------------------------------------------------------
// Copyright (c) 2001-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlObject.h
/// @class EcXmlObject
/// @brief A base class for xml objects.
/// @details EcXmlObject is a base class that defines the common interface
///          for all XML objects in Actin with read, write,and xml-init functions.
///          It contains a collection of methods used to assist in serialization
///          of a class instance.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecMacros.h>
#include "ecXmlObjectVisitor.h"
#include "ecXmlTokens.h"

class EcXmlReader;
class EcXmlSchema;
class EcXmlWriter;

class EC_STABLE_XML_DECL EcXmlObject
{
public:

   /// #ECDECLARE_BIGFOUR(EcCls) Macro declares a constructor, destructor,
   /// copy constructor, equal operator, and equality operator
   ECDECLARE_BIGFOUR(EcXmlObject);

   ECXMLOBJECT_ACCEPT(EcXmlObject)

   /// clone
   virtual EcXmlObject* clone
      (
      ) const = 0;

   /// xml-initialize
   virtual EcBoolean xmlInit
      (
      );

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// read this attribute from an XML stream
   virtual EcBoolean readAttribute
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// write the schema for this object to an XML stream
   virtual EcBoolean writeSchema
      (
      EcXmlSchema& stream
      ) const;

   /// create schema
   virtual EcBoolean createSchema
      (
      const EcString& filename,
      const EcToken& objectName = EcXml::EcDefaultToken
      ) const;

   /// get XML initialized flag.  This bit is set on initialization.
   virtual EcBoolean xmlInitialized
      (
      ) const;

   /// set XML initialized flag.  This bit is set on initialization.
   virtual void setXmlInitialized
      (
      EcBoolean val = EcTrue
      );

   /// get specified flag.  This bit is set upon reading from an XML file.
   virtual EcBoolean specified
      (
      ) const;

   /// set specified flag.  This bit is set upon reading from an XML file.
   virtual void setSpecified
      (
      EcBoolean val = EcTrue
      );

   /// Return true/false for basic type
   virtual EcBoolean isBasicType
      (
      ) const;

   /// tests equality of XML object with default
   virtual EcBoolean equalsDefault
      (
      ) const;

   /// equality - a virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const = 0;

   /// creates new object - a virtual new to an EcXmlObject pointer
   virtual EcXmlObject* newObject
      (
      ) const = 0;

   /// gets the xml token used for writing out.
   virtual const EcToken& token
      (
      ) const = 0;

protected:
   /// the state of the object - eight boolean flags
   EcU8 m_State;

   /// the bit used to describe xml initialization
   static const EcU8 m_theXmlInitializedBit;

   /// the bit used to describe specification
   static const EcU8 m_theSpecifiedBit;
};

/// type definition of an expression element creator function
typedef EcXmlObject* (*EcXmlObjectCreator)();

/// type definition of a creator function map from std::map
typedef std::map<EcToken, EcXmlObjectCreator> EcXmlCreatorMap;

#endif // ecXmlObject_H_
