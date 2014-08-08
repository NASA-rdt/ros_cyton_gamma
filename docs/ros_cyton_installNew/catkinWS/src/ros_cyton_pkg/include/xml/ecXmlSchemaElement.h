#ifndef ecXmlSchemaElement_H_
#define ecXmlSchemaElement_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlSchemaElement.h
/// @class EcXmlSchemaElement
/// @brief Class defines each element of the schema
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include "ecToken.h"
#include "ecXmlSchemaAttributeType.h"
#include "ecXmlSchemaElementType.h"

#include <ostream>
#include <vector>

class EcXmlSchema;

class EC_STABLE_XML_DECL EcXmlSchemaElement
{
public:
   /// default constructor
   EcXmlSchemaElement
      (
      );

   /// constructor
   /**
      \param pContainer Container pointer
      \param pParent Pointer to parent
   */
   EcXmlSchemaElement
      (
      EcXmlSchema* pContainer,
      EcXmlSchemaElement* pParent = 0
      );

   /// default destructor
   virtual ~EcXmlSchemaElement
      (
      );

   /// copy constructor
   EcXmlSchemaElement
      (
      const EcXmlSchemaElement& orig
      );

   /// assignment operator
   EcXmlSchemaElement& operator=
      (
      const EcXmlSchemaElement& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcXmlSchemaElement& orig
      ) const;

   /// new start tag
   /**
      \param elementName Element name
      \param mode Group mode (choice or sequence)
      \param groupIndex Group index
      \retval schema element
   */
   virtual EcXmlSchemaElement* writeStartTag
      (
      const EcToken& elementName,
      const EcXmlSchemaElementType::XML_STARTTAG_OPTION mode
         = EcXmlSchemaElementType::SEQUENCE,
      const EcU32 groupIndex =0
      );

   /// put name
   /**
      \param elementName Element name
      \param mode Group mode (choice or sequence)
      \param groupIndex Group index
      \retval schema element
   */
   virtual EcXmlSchemaElement* setName
      (
      const EcToken& elementName,
      const EcXmlSchemaElementType::XML_STARTTAG_OPTION mode
         = EcXmlSchemaElementType::SEQUENCE,
      const EcU32 groupIndex =0
      );

   /// get name
   /**
      \retval Element name
   */
   virtual const EcToken& elementName
      (
      ) const;

   /// input typeid
   /**
      \param typeidInfo Type id information
   */
   void setTypeIdString
      (
      const EcString& typeidInfo
      );

   /// new attribute name
   /**
      \param attributeName Attribute name
   */
   virtual void setAttributeName
      (
      const EcToken& attributeName
      );

   /// attribute type
   /**
      \param attributeType Attribute type
   */
   virtual void setAttributeType
      (
      const EcString& attributeType
      );

   /// get content type
   /**
      \retval Content type
   */
   virtual const EcString& contentType
      (
      ) const;

   /// Set content type
   /**
      \param contentType Content type
   */
   virtual void setContentType
      (
      const EcString& contentType
      );

   /// new end tag
   virtual EcXmlSchemaElement* writeEndTag
      (
      );

   /// new end tag
   virtual EcXmlSchemaElement* writeEndTagRecursive
      (
      );

   /// return type of element
   virtual EcXmlSchemaElementType elementType
      (
      ) const;

   /// set container and parent pointer
   /**
      \param container Container pointer
      \param parent Parent pointer
   */
   virtual void setPointers
      (
      const EcXmlSchema* container,
      const EcXmlSchemaElement* parent
      );

   /// get namespace
   /**
      \retval namespace string
   */
   virtual const EcString& getNamespace
      (
      ) const;

   /// get pointer to parent
   /**
      \retval pointer of parent
   */
   virtual EcXmlSchemaElement* parent
      (
      ) const;

   /// test for recursive element names
   /**
      \param elementName Name of element
      \retval true/false
   */
   virtual EcBoolean isRecursiveElement
      (
      const EcToken& elementName
      ) const;

protected:

   /// Pointer to schema container
   EcXmlSchema* m_pContainer;

   /// Pointer to parent
   EcXmlSchemaElement* m_pParent;

   /// Element Name
   EcToken m_ElementName;

   /// Namespace
   EcString m_Namespace;

   /// Start tag mode (none, sequence, choice, or unbounded)
   EcXmlSchemaElementType::XML_STARTTAG_OPTION m_StartTagMode;

   /// Group index for tying together elements into groups
   EcU32 m_GroupIndex;

   /// Element content type (empty unless content available)
   EcString m_ContentType;

   /// Element content type (typeid)
   EcString m_TypeidInfo;

   /// Element complex type
   EcString m_ComplexType;

   /// Children element information
   std::vector<EcXmlSchemaElement> m_vChildren;

   /// Attribute information
   std::vector<EcXmlSchemaAttributeType> m_vAttribute;
};

#endif // ecXmlSchemaElement_H_
