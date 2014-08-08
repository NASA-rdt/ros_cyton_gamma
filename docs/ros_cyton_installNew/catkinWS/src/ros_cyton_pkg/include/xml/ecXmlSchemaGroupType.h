#ifndef ecXmlSchemaGroupType_H_
#define ecXmlSchemaGroupType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlSchemaGroupType.h
/// @class EcXmlSchemaGroupType
/// @brief Code for schema group types
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecXmlSchemaElementType.h"

class EC_STABLE_XML_DECL EcXmlSchemaGroupType
{
public:
   /// default constructor
   EcXmlSchemaGroupType
      (
      );

   /// default destructor
   virtual ~EcXmlSchemaGroupType
      (
      );

   /// copy constructor
   EcXmlSchemaGroupType
      (
      const EcXmlSchemaGroupType& orig
      );

   /// assignment operator
   EcXmlSchemaGroupType& operator=
      (
      const EcXmlSchemaGroupType& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcXmlSchemaGroupType& orig
      ) const;

   /// test for convertibility
   virtual EcBoolean isTypeConvertible
      (
      const EcXmlSchemaGroupType& orig
      ) const;

   /// get element namespace
   virtual const EcString& getNamespace
      (
      ) const;

   /// set element namespace
   virtual void setNamespace
      (
      const EcString& namespaceInput
      );

   /// get group mode
   virtual const EcXmlSchemaElementType::XML_STARTTAG_OPTION startTagMode
      (
      ) const;

   /// set group mode
   virtual void setStartTagMode
      (
      const EcXmlSchemaElementType::XML_STARTTAG_OPTION startTagMode
      );

   /// get by index
   const EcXmlSchemaElementType& operator[]
      (
      EcU32 index
      ) const;

   /// set by index
   EcXmlSchemaElementType& operator[]
      (
      EcU32 index
      );

   /// get size
   virtual EcU32 size
      (
      ) const;

   /// get the vector container (const)
   virtual const EcXmlSchemaElementVector& elementVector
      (
      ) const;

   /// get the vector container (nonconst)
   virtual EcXmlSchemaElementVector& elementVector
      (
      );

   /// set the vector container (const)
   virtual void setElementVector
      (
      const EcXmlSchemaElementVector& vElement
      );

protected:
   EcString m_Namespace;                                 ///< Element Namespace
   EcXmlSchemaElementType::XML_STARTTAG_OPTION m_StartTagMode;   ///< Start tag mode
   EcXmlSchemaElementVector m_vElement;       ///< Vector of children elements
};

#endif // ecXmlSchemaGroupType_H_
