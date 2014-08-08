#ifndef ecXmlSchemaComplexType_H_
#define ecXmlSchemaComplexType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlSchemaComplexType.h
/// @class EcXmlSchemaComplexType
/// @brief Code for schema complex types
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecXmlSchemaAttributeType.h"
#include "ecXmlSchemaElementType.h"

class EC_STABLE_XML_DECL EcXmlSchemaComplexType
{
public:
   /// default constructor
   EcXmlSchemaComplexType
      (
      );

   /// default destructor
   virtual ~EcXmlSchemaComplexType
      (
      );

   /// copy constructor
   EcXmlSchemaComplexType
      (
      const EcXmlSchemaComplexType& orig
      );

   /// assignment operator
   EcXmlSchemaComplexType& operator=
      (
      const EcXmlSchemaComplexType& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcXmlSchemaComplexType& orig
      ) const;

   /// test for convertibility
   EcBoolean isTypeConvertible
      (
      const EcXmlSchemaComplexType& orig
      ) const;

   /// convert nillable types
   void convertType
      (
      const EcXmlSchemaComplexType& orig
      );

   /// get element name
   virtual const EcToken& elementName
      (
      ) const;

   /// set element name
   virtual void setElementName
      (
      const EcToken& elementName
      );

   /// get element namespace
   virtual const EcString& getNamespace
      (
      ) const;

   /// set element namespace
   virtual void setNamespace
      (
      const EcString& namespaceInput
      );

   /// get content type
   virtual const EcString& contentType
      (
      ) const;

   /// set content type
   virtual void setContentType
      (
      const EcString& contentType
      );

   /// get element by index
   const EcXmlSchemaElementType& element
      (
      EcU32 index
      ) const;

   /// set element by index
   EcXmlSchemaElementType& setElement
      (
      EcU32 index
      );

   /// push a copy of an object onto the vector
   virtual void pushBack
      (
      const EcXmlSchemaElementType& element
      );

   /// get element size
   virtual EcU32 elementSize
      (
      ) const;

   /// get the element vector container (const)
   virtual const std::vector<EcXmlSchemaElementType>& elementVector
      (
      ) const;

   /// get the element vector container (nonconst)
   virtual std::vector<EcXmlSchemaElementType>& elementVector
      (
      );

   /// set the element vector container (const)
   virtual void setElementVector
      (
      const std::vector<EcXmlSchemaElementType>& vElement
      );

   /// get attribute by index
   const EcXmlSchemaAttributeType& attribute
      (
      EcU32 index
      ) const;

   /// set attribute by index
   EcXmlSchemaAttributeType& setAttribute
      (
      EcU32 index
      );

   /// get attribute size
   virtual EcU32 attributeSize
      (
      ) const;

   /// get the attribute vector container (const)
   virtual const std::vector<EcXmlSchemaAttributeType>&
      attributeVector
      (
      ) const;

   /// get the vector container (nonconst)
   virtual std::vector<EcXmlSchemaAttributeType>& attributeVector
      (
      );

   /// set the vector container (const)
   virtual void setAttributeVector
      (
      const std::vector<EcXmlSchemaAttributeType>& vAttribute
      );

protected:
   EcToken  m_ElementName;                               ///< Element name
   EcString m_Namespace;                                 ///< Namespace
   EcString m_ContentType;                               ///< Type of content if any
   std::vector<EcXmlSchemaElementType> m_vElement;       ///< Vector of children elements
   std::vector<EcXmlSchemaAttributeType> m_vAttribute;   ///< Attribute name
};

#endif // ecXmlSchemaComplexType_H_
