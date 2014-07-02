#ifndef ecXmlSchemaAttributeType_H_
#define ecXmlSchemaAttributeType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlSchemaAttributeType.h
/// @class EcXmlSchemaAttributeType
/// @brief Code for schema attributes
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecToken.h"

class EC_STABLE_XML_DECL EcXmlSchemaAttributeType
{
public:
   /// default constructor
   EcXmlSchemaAttributeType
      (
      );

   /// default destructor
   virtual ~EcXmlSchemaAttributeType
      (
      );

   /// copy constructor
   EcXmlSchemaAttributeType
      (
      const EcXmlSchemaAttributeType& orig
      );

   /// assignment operator
   EcXmlSchemaAttributeType& operator=
      (
      const EcXmlSchemaAttributeType& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcXmlSchemaAttributeType& orig
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
   EcToken m_ElementName; ///< Element Name
   EcString m_Type;        ///< Element type
};

#endif // ecXmlSchemaAttributeType_H_
