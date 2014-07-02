#ifndef ecXmlSchema_H_
#define ecXmlSchema_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlSchema.h
/// @class EcXmlSchema
/// @brief Class for generating schemas
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecToken.h"
#include "ecXmlSchemaElement.h"
#include "ecXmlSchemaComplexType.h"
#include "ecXmlSchemaGlobalElementType.h"
#include "ecXmlSchemaGroupType.h"

#include <map>
#include <vector>

class EC_STABLE_XML_DECL EcXmlSchema
{
public:
   /// XML Schema Mode
   enum XML_SCHEMA_MODE
   {
      NEW_FILE,                  ///< Initial state
      START_TAG,                 ///< Start tag opened
      ATTRIBUTE_NAME,            ///< Attribute name written
      ATTRIBUTE_VALUE,           ///< Attribute value written
      CONTENT,                   ///< Content written
      END_TAG,                   ///< Tag closed
      ERROR_FOUND                ///< Error found
   };

   /// default constructor
   EcXmlSchema
      (
      );

   /// default destructor
   virtual ~EcXmlSchema
      (
      );

   /// copy constructor
   EcXmlSchema
      (
      const EcXmlSchema& orig
      );

   /// assignment operator
   EcXmlSchema& operator=
      (
      const EcXmlSchema& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcXmlSchema& orig
      ) const;

   /// new start tag
   /**
      \param elementName Element name
      \param mode Group mode (choice or sequence)
      \retval recursive element flag
   */
   virtual EcBoolean writeStartTag
      (
      const EcToken& elementName,
      const EcXmlSchemaElementType::XML_STARTTAG_OPTION mode =
         EcXmlSchemaElementType::SEQUENCE
      );

   /// new start tag
   /**
      \param elementName Element name
      \param mode Group mode (choice or sequence)
      \retval recursive element flag
   */
   virtual EcBoolean writeStartTagUsingParentNamespace
      (
      const EcString& elementName,
      const EcXmlSchemaElementType::XML_STARTTAG_OPTION mode =
         EcXmlSchemaElementType::SEQUENCE
      );

   /// new attribute name
   /**
      \param attributeName Attribute name
   */
   virtual void setAttributeName
      (
      const EcToken& attributeName
      );

   /// set type
   /**
      \param typeInfo Input type
   */
   virtual void setType
      (
      const std::type_info& typeInfo
      );

   /// new end tag
   virtual void writeEndTag
      (
      );

   /// new end tag for recursive element
   virtual void writeEndTagRecursive
      (
      );

   /// open a schema group
   virtual void openGroup
      (
      );

   /// close a schema group
   virtual void closeGroup
      (
      );

   /// write schema files
   /**
      \param xmlFilename Filename for output
      \retval error flag
   */
   virtual EcBoolean write
      (
      EcString xmlFilename
      );

   /// test if element registered
   /**
      \param name Element name
      \param type Element type
      \retval Is registered? True/False
   */
   virtual EcBoolean isRegistered
      (
      const EcToken& name,
      const EcString& type
      );

   /// remove element from registry
   /**
      \param name Element name
      \param type Element type
   */
   virtual void unRegister
      (
      const EcToken& name,
      const EcString& type
      );

   /// attribute type
   /**
      \param attributeType Attribute type
   */
   virtual void setAttributeType
      (
      const EcString& attributeType
      );

   /// Set content type
   /**
      \param contentType Content type
   */
   virtual void setContentType
      (
      const EcString& contentType
      );

   /// write element complex type description
   /**
      \param stream Output stream
      \param namespaceUri namespace of complex types to be written
   */
   virtual void writeComplexType
      (
      std::ostream& stream,
      EcString namespaceUri
      );

   /// put global element
   /**
      \param elementName Element name
      \param elementNamespace Element namespace
      \param elementType Element type
   */
   virtual void globalElement
      (
      EcToken  elementName,
      EcString elementNamespace,
      EcString elementType
      );

   /// convert namespace URI to namespace prefix
   /**
      \param elementNamespace URI
      \return prefix
   */
   virtual EcString convertNamespaceToPrefix
      (
      EcString elementNamespace
      );

   /// insert new simple type
   /**
      \param type Base type
      \param namespaceUri Namespace URI
      \retval new simple type
   */
   virtual EcString insertSimpleType
      (
      const EcString& type,
      const EcString& namespaceUri
      );

   /// insert new complex type
   /**
      \param type Element type for comparison
      \param name Input type name
      \retval new type name
   */
   virtual EcString insertComplexType
      (
      const EcXmlSchemaComplexType& type,
      const EcString& name
      );

   /// insert new element group type
   /**
      \param type Group type for comparison
      \param name Default name if not already registered
      \retval new type name
   */
   virtual EcString insertGroupType
      (
      const EcXmlSchemaGroupType& type,
      const EcString& name
      );

   /// update registry
   /**
      \param name Element name
      \param type Element type
      \param complexType Complex type name
      \param simpleType Simple type name
   */
   virtual void updateRegistry
      (
      const EcToken& name,
      const EcString& type,
      const EcString& complexType,
      const EcString& simpleType
      );

   /// get from registry
   /**
      \param name Element name
      \param type Element type
      \param complexType Complex type (output)
      \param simpleType Simple type (output)
   */
   virtual void getFromRegistry
      (
      const EcToken& name,
      const EcString& type,
      EcString& complexType,
      EcString& simpleType
      ) const;

protected:

   /// XML writer mode
   XML_SCHEMA_MODE m_XmlSchemaMode;

   /// root element
   EcXmlSchemaElement m_Root;

   /// current element for processing
   EcXmlSchemaElement* m_pCurrentElement;

   /// vector of global elements
   std::vector<EcXmlSchemaGlobalElementType> m_vElement;

   /// map of global simple types (basic type / expanded type pair)
   std::map<EcString,EcString> m_SimpleTypes;

   /// map of global complex types (name / complex type pair)
   std::map<EcString,EcXmlSchemaComplexType> m_ComplexTypes;

   /// map of global element groups (name / element group pair)
   std::map<EcString,EcXmlSchemaGroupType> m_ElementGroups;

   /// index for distinguishing group
   EcU32 m_GroupIndex;

   /// namespace map (URI / prefix pair)
   std::map<EcString,EcString> m_NamespaceMap;

   /// vector containing order of namespaces (who imports who)
   EcStringVector m_vNamespaceImportOrder;

   /// registered type info
   struct EcRegisterType
   {
      EcString typeidString;        ///< typeid info
      EcString xmlComplexType;      ///< XML type info
      EcString xmlSimpleType;       ///< XML type info
   };

   /// map of registered elements for stopping recursion (name / type pair)
   std::multimap<EcToken,EcRegisterType> m_RegisteredElements;
};

#endif // ecXmlSchema_H_
