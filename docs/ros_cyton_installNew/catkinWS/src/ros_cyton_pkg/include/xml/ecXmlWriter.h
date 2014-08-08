#ifndef ecXmlWriter_H_
#define ecXmlWriter_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlWriter.h
/// @class EcXmlWriter
/// @brief XML file writer
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.

#include "ecSignalTypes.h"
#include "ecXmlSchema.h"

#include <ostream>
#include <stack>
#include <typeinfo>

#include <foundCore/ecConnectionManagerTypes.h>

class EC_STABLE_XML_DECL EcXmlWriter
{
public:
   /// XML Writer Mode
   enum XML_WRITER_MODE
   {
      NEW_FILE,                  ///< Initial state
      START_TAG,                 ///< Start tag opened
      ATTRIBUTE_NAME,            ///< Attribute name written
      ATTRIBUTE_VALUE,           ///< Attribute value written
      CONTENT,                   ///< Content written
      END_TAG,                   ///< Tag closed
      ERROR_FOUND                ///< Error found
   };

   /// Define the different languages available.
   enum LANGUAGE
   {
      basicXML,                  ///< Basic XML file
      MCML_V1_0_0                ///< MCML v1.0.0 file
   };

   /// Default constructor
   EcXmlWriter
      (
      );

   /// Constructor with filename argument
   /**
      \param filename Destination file for writing
      \param stream Stream used to write to destination
   */
   EcXmlWriter
      (
      const EcString& filename,
      std::ostream& stream
      );

   /// Default destructor
   virtual ~EcXmlWriter
      (
      );

   /// copy constructor
   EcXmlWriter
      (
      const EcXmlWriter& orig
      );

   /// assignment operator
   EcXmlWriter& operator=
      (
      const EcXmlWriter& orig
      );

   /// open start tag
   /**
      \param elementName Element name
   */
   virtual void writeStartTag
      (
      const EcToken& elementName
      );

   /// open start tag
   /**
      Use parent's namespace
      \param elementName Element name
   */
   virtual void writeStartTagUsingParentNamespace
      (
      const EcToken& elementName
      );

   /// put attribute name
   /**
      \param attributeName Attribute name
   */
   virtual void setAttributeName
      (
      const EcToken& attributeName
      );

   /// set the number of columns for content
   /**
      \param size Number of columns
   */
   virtual void setNumOfContentColumns
      (
      const EcU32 size
      );

   /// put end tag
   /**
      \retval Error flag
   */
   virtual void writeEndTag
      (
      );

   /// get indent
   virtual const EcString& indent
      (
      ) const;

   /// set indent
   virtual void setIndent
      (
      const EcString &indent
      );

   /// get default indent
   static const EcString& defaultIndent
      (
      );

   /// set default indent
   static void setDefaultIndent
      (
      const EcString &indent
      );

   /// get header
   virtual const EcString& header
      (
      ) const;

   /// set header
   virtual void setHeader
      (
      const EcString &header
      );

   /// get default header
   static const EcString& defaultHeader
      (
      );

   /// set default header
   static void setDefaultHeader
      (
      const EcString &header
      );

   /// get style sheet
   virtual const EcString& styleSheet
      (
      ) const;

   /// set style sheet
   virtual void setStyleSheet
      (
      const EcString &styleSheet
      );

   /// get default style sheet
   static const EcString& defaultStyleSheet
      (
      );

   /// set default style sheet
   static void setDefaultStyleSheet
      (
      const EcString &styleSheet
      );

   /// get schema instance
   virtual const EcString& schemaInstance( ) const;

   /// set schema instance
   virtual void setSchemaInstance
      (
      const EcString &schemaInstance
      );

   /// get default schema instance
   static const EcString& defaultSchemaInstance
      (
      );

   /// set default schema instance
   static void setDefaultSchemaInstance
      (
      const EcString &schemaInstance
      );

   /// get schema location
   virtual const EcString& schemaLocation
      (
      ) const;

   /// set schema location
   virtual void setSchemaLocation
      (
      const EcString &schemaLocation
      );

   /// get default schema location
   static const EcString& defaultSchemaLocation
      (
      );

   /// set default schema location
   static void setDefaultSchemaLocation
      (
      const EcString &schemaLocation
      );

   /// Define the languages
   virtual void setLanguageSelection
      (
      LANGUAGE langaugeID
      );
   /// Define the default languages
   static void setDefaultLanguageSelection
      (
      LANGUAGE langaugeID
      );

   /// Get type information of content
   virtual void type
      (
      const std::type_info& typeInfo
      );

   /// put data
   /**
      Data could be attribute value or element content,
      which is determined by context
      \param data Input data
   */
   virtual void data
      (
      const EcString& data
      );

   /// Get write default flag
   virtual EcBoolean writeDefaultDataFlag
      (
      ) const;

   /// Set write default flag
   virtual void setWriteDefaultDataFlag
      (
      EcBoolean writeDefaultDataFlag
      );

   /// Set default for write default flag
   static void setDefaultForWriteDefaultDataFlag
      (
      EcBoolean writeDefaultDataFlag
      );

   /// set link total
   virtual void setLinkTotal
      (
      EcU32 linkTotal
      );

   /// reset link count to zero
   virtual void resetLinkCount
      (
      );

   /// Increment link count
   virtual void incrementLinkCount
      (
      );

   /// Internal buffer
   std::ostringstream m_Buffer;

protected:

   /// put attribute value (called from Data())
   /**
      \param data Attribute data
   */
   virtual void attributeValue
      (
      const EcString& data
      );

   /// put content (called from Data())
   /**
      \param data Attribute data
   */
   virtual void content
      (
      const EcString& data
      );

   /// set schema writer
   virtual void setSchemaWriter
      (
      const EcBoolean writeSchema
      );

   /// set default schema writer
   static void setDefaultSchemaWriter
      (
      const EcBoolean writeSchema
      );

   /// put header information
   /**
      \param elementName Root element name that is written at end of header
      \param namespaceUri URI for namespace definition
   */
   virtual void header
      (
      const EcToken& elementName,
      const EcString& namespaceUri
      );

   /// put header information
   /**
      Tabs are actually two spaces apiece
      \param size Number of tabs written
   */
   virtual void tab
      (
      const EcU32 size = 1
      );

   /// Output stream
   std::ostream& m_Stream;

   /// File name
   EcString m_FileName;

   /// XML writer mode
   XML_WRITER_MODE m_XmlWriterMode;

   /// Structure containing element and namespace map
   struct ElementStruct
   {
      EcToken elementName;                         ///< element name
      std::map<EcString,EcString> namespaceMap;    ///< namespace map
      EcString parentNamespace;                    ///< parent namespace
      EcString currentNamespace;                   ///< current namespace
   };

   /// Element name
   std::stack<ElementStruct> m_ElementStack;

   /// Default namespace
   EcString m_DefaultNamespace;

   /// Data container
   EcString m_Content;

   /// Data counter
   EcU32 m_ContentCount;

   /// Content columns
   EcU32 m_ContentColumns;

   /// Short File Flag
   EcBoolean m_WriteDefaultDataFlag;

   /// Default short File Flag
   static EcBoolean m_theWriteDefaultDataFlag;

   EcString    m_Indent;               ///< indent size
   EcString    m_Header;               ///< XML header
   EcString    m_StyleSheetLocation;   ///< style sheet location
   EcString    m_SchemaInstance;       ///< schema instance name
   EcString    m_SchemaLocation;       ///< schema location

   static EcString    m_theIndent;              ///< default indent size
   static EcString    m_theHeader;              ///< default XML header
   static EcString    m_theStyleSheetLocation;  ///< default style sheet location
   static EcString    m_theSchemaInstance;      ///< default schema instance name
   static EcString    m_theSchemaLocation;      ///< default schema location

   /// Schema generator
   EcXmlSchema m_Schema;

   /// Static flag for writing schema
   static EcBoolean m_theWriteSchema;

   /// Flag for writing schema
   EcBoolean m_WriteSchema;

   /// Content type name
   EcString m_Type;

   /// Pointer to signal status writer for front end GUI
   Ec::ConnectionManagerTypes::Signal<Ec::SignalReadWriteStatusTraits::Type>::PtrType m_SignalStatusPtr;
   
   /// Pointer to signal progress writer for front end GUI
   Ec::ConnectionManagerTypes::Signal<Ec::SignalReadWriteProgressTraits::Type>::PtrType m_SignalProgressPtr;

   EcU32 m_LinkTotal; ///< total number of links
   EcU32 m_LinkCount; ///< Link count
};

/// writes the basic value to the EcXmlWriter stream
template<class BasicType>
EcXmlWriter& operator<<
   (
   EcXmlWriter& stream, const BasicType& token
   )
{
   // get type information for schema
   stream.type(typeid(BasicType));

   // convert token to string
   stream.m_Buffer << token;

   // insert token into xmlWriter
   stream.data(stream.m_Buffer.str());

   // clear string buffer
   stream.m_Buffer.str("");

   return stream;
}

#endif // ecXmlWriter_H_
