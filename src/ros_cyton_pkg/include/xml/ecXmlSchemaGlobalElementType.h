#ifndef ecXmlSchemaGlobalElementType_H_
#define ecXmlSchemaGlobalElementType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlSchemaGlobalElementType.h
/// @class EcXmlSchemaGlobalElementType
/// @brief Code for schema global element types
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecToken.h"

class EC_STABLE_XML_DECL EcXmlSchemaGlobalElementType
{
public:
   /// default constructor
   EcXmlSchemaGlobalElementType
      (
      );

   /// default destructor
   virtual ~EcXmlSchemaGlobalElementType
      (
      );

   /// copy constructor
   EcXmlSchemaGlobalElementType
      (
      const EcXmlSchemaGlobalElementType& orig
      );

   /// assignment operator
   EcXmlSchemaGlobalElementType& operator=
      (
      const EcXmlSchemaGlobalElementType& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcXmlSchemaGlobalElementType& orig
      ) const;

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

   /// get element type
   virtual const EcString& type
      (
      ) const;

   /// set element type
   virtual void setType
      (
      const EcString& type
      );

protected:
   EcToken  m_ElementName;   ///< element name
   EcString m_Namespace;     ///< element namespace
   EcString m_Type;          ///< element type
};

#endif // ecXmlSchemaGlobalElementType_H_
