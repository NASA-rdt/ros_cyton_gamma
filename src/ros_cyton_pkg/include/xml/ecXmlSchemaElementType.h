#ifndef ecXmlSchemaElementType_H_
#define ecXmlSchemaElementType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlSchemaElementType.h
/// @class EcXmlSchemaElementType
/// @brief An Xml schema element type
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecConstants.h>
#include "ecToken.h"

class EC_STABLE_XML_DECL EcXmlSchemaElementType
{
public:
   /// Start Tag Mode
   enum XML_STARTTAG_OPTION
   {
      CHOICE,                    ///< Choice mode
      SEQUENCE,                  ///< Sequence mode
      UNBOUNDED                  ///< Unbounded mode
   };

   /// default constructor
   EcXmlSchemaElementType
      (
      );

   /// default destructor
   virtual ~EcXmlSchemaElementType
      (
      );

   /// copy constructor
   EcXmlSchemaElementType
      (
      const EcXmlSchemaElementType& orig
      );

   /// assignment operator
   EcXmlSchemaElementType& operator=
      (
      const EcXmlSchemaElementType& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcXmlSchemaElementType& orig
      ) const;

   /// test for convertibility
   virtual EcBoolean isTypeConvertible
      (
      const EcXmlSchemaElementType& orig,
      const EcBoolean testGroup = EcFalse
      ) const;

   /// convert nillable types
   void convertType
      (
      const EcXmlSchemaElementType& orig
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

   /// get start tag mode
   virtual const XML_STARTTAG_OPTION startTagMode
      (
      ) const;

   /// set group mode
   virtual void setStartTagMode
      (
      const XML_STARTTAG_OPTION startTagMode
      );

   /// get group index
   virtual const EcU32 groupIndex
      (
      ) const;

   /// set group index
   virtual void setGroupIndex
      (
      const EcU32 groupIndex
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

   /// get min occurs
   virtual const EcU32 minOccurs
      (
      ) const;

   /// set min occurs
   virtual void setMinOccurs
      (
      const EcU32 minOccurs
      );

   /// get nillable parameter
   virtual const EcBoolean nillable
      (
      ) const;

   /// set nillable parameter
   virtual void setNillable
      (
      const EcBoolean nillable
      );

protected:

   /// element name
   EcToken  m_ElementName;

   /// namespace name
   EcString m_Namespace;

   /// start-tag mode
   XML_STARTTAG_OPTION m_StartTagMode;

   /// integer group index
   EcU32 m_GroupIndex;

   /// the element type
   EcString m_Type;

   /// the minimum occurences
   EcU32 m_MinOccurs;

   /// flag indicating whether or not the element can be empty
   EcBoolean m_Nillable;
};

/// A type definition for a vector of EcXmlSchemaElements using std::vector
typedef std::vector<EcXmlSchemaElementType> EcXmlSchemaElementVector;

#endif // ecXmlSchemaElementType_H_
