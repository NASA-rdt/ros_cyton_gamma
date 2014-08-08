#ifndef ecXmlFileReader_H_
#define ecXmlFileReader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlFileReader.h
/// @class EcXmlFileReader
/// @brief An XML parser object that can read a single file
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include <foundCore/ecConstants.h>
#include "ecToken.h"

#include <boost/scoped_array.hpp>
#include <istream>
#include <map>
#include <stack>

class EC_STABLE_XML_DECL EcXmlFileReader
{
public:
   /// XML Reader Mode
   enum XML_READER_MODE
   {
      EOF_FOUND,                 ///< End of file
      START_TAG,                 ///< Start tag found
      END_TAG,                   ///< End tag found
      EMPTY_TAG,                 ///< Empty tag found
      CONTENT,                   ///< Content found
      ERROR_FOUND                ///< Error found
   };

   /// Default constructor
   EcXmlFileReader
      (
      );

   /// Constructor with filename argument
   /**
      \param filename File for reading
      \param stream Stream used for reading
   */
   EcXmlFileReader
      (
      const EcString& filename,
      std::istream& stream
      );

   /// Default destructor
   virtual ~EcXmlFileReader
      (
      );

   /// copy constructor
   EcXmlFileReader
      (
      const EcXmlFileReader& orig
      );

   /// assignment operator
   EcXmlFileReader& operator=
      (
      const EcXmlFileReader& orig
      );

   /// Executive for XML processing
   /**
      \retval xmlReader mode
   */
   virtual XML_READER_MODE readXml
      (
      );

   /// Get input stream
   virtual std::istream& stream
      (
      ) const;

   /// Get file name
   /// char * is used because that is what is needed by
   /// EcERROR and EcWARN
   virtual const char* filename
      (
      ) const;

   /// Get error code
   virtual EcU32 errorCode
      (
      ) const;

   /// Set error code
   virtual void setErrorCode
      (
      EcU32 error
      );

   /// Get mode
   virtual XML_READER_MODE mode
      (
      ) const;

   /// Get element name
   virtual const EcToken& element
      (
      ) const;

   /// Get next attribute name
   virtual const EcToken& attributeName
      (
      ) const;

   /// Get next attribute name given key
   virtual const EcToken& attributeName
      (
      const EcToken& key
      ) const;

   /// Get next attribute value (then pop value -> nonconst)
   virtual const EcString& attributeValue
      (
      );

   /// Get next attribute value given key (then pop value -> nonconst)
   virtual const EcString& attributeValue
      (
      const EcToken& key
      );

   /// Get original size of attribute queue
   virtual EcU32 numOfAttributes
      (
      ) const;

   /// Get size of attribute name queue
   virtual EcU32 remainingNumOfAttributes
      (
      ) const;

   /// Get content
   virtual const EcString& content
      (
      ) const;

   /// Get next word of content
   virtual const EcString& contentByWord
      (
      ) const;

   /// Get number of items in content
   virtual const EcU32 contentCount
      (
      ) const;

   /// Test for content
   virtual EcBoolean isContentAvailable
      (
      ) const;

   /// Set content vector flag
   virtual void setContentVectorFlag
      (
      EcBoolean contentVectorFlag = EcTrue
      );

   /// Get line count
   virtual EcInt32 lineCountOfFile
      (
      ) const;

   /// Continue reading to matching end tag for current element
   /**
      \retval Error flag
   */
   virtual EcBoolean nextMatchingEndTag
      (
      );

   /// Get childen content as string
   /**
      \retval String containing children
   */
   virtual const EcString& getChildrenAsString
      (
      );

   /// Close stream
   virtual void close
      (
      );

   /// Get start tag (fast without error checking)
   /// Complex means tags with attributes
   virtual const EcString& getComplexStartTagFast
      (
      );

   /// Get start tag (fast without error checking)
   /// Simple means tags without attributes
   virtual const EcString& getSimpleStartTagFast
      (
      );

   /// Get next attribute value (fast without error checking)
   virtual const EcString& getAttributeValueFast
      (
      );

   /// Get last attribute value (fast without error checking)
   virtual const EcString& getLastAttributeValueFast
      (
      );

   /// Get next content word (fast without error checking)
   virtual const EcString& getContentByWordFast
      (
      );

   /// Get end tag (fast without error checking)
   virtual void getEndTagFast
      (
      );

protected:

   /// Get next input from stream
   /**
      \retval xmlReader mode
   */
   virtual EcXmlFileReader::XML_READER_MODE nextEvent
      (
      );

   /// What kind of tag?
   /**
      \param tag String containing tag
      \retval xmlReader mode
   */
   virtual EcXmlFileReader::XML_READER_MODE tagType
      (
      EcString& tag
      );

   /// Get element and attributes
   /**
      \param tag String containing tag
      \retval Error flag
   */
   virtual EcBoolean parseElementAndAttributes
      (
      EcString& tag
      );

   /// default namespace option
   enum DEFAULT_NAMESPACE_OPTION
   {
      ELEMENT,                   ///< for element
      ATTRIBUTE                  ///< for attribute
   };

   /// Swap namespace prefix with URI
   /**
      \param input String tag needing the switch
      \param option Treat element and attribute default differently
   */
   virtual const EcToken& swapNamespacePrefixWithUri
      (
      EcToken& input,
      DEFAULT_NAMESPACE_OPTION option = ELEMENT
      ) const;

   /// Get next word from input string
   /**
      \param input String containing data to be parsed
      \retval word
   */
   virtual const EcString& nextWord
      (
      EcString& input
      ) const;

   /// Get word count
   /**
      \param input String containing data to be parsed
      \retval number of words
   */
   virtual const EcU32 wordCount
      (
      const EcString& input
      ) const;

   /// Get quoted token
   /**
      \param input String containing data to be parsed
      \retval quoted token
   */
   virtual const EcString& nextQuotedToken
      (
      EcString& input
      ) const;

   /// Read file and count lines using getline()
   /**
      \param input String containing data to be parsed
      \param delim Search delimiter
      \param eatDelim Remove delimiter
      \retval Error flag
   */
   virtual EcBoolean getLineWithLineCount
      (
      EcString& input,
      const char delim,
      EcBoolean eatDelim
      );

   /// Is input a comment?
   /**
      \param input String containing data to be analyzed
      \retval Flag indicating comment or not
   */
   virtual EcBoolean isComment
      (
      EcString& input
      );

   /// Strip white space from bounds
   /**
      \param input String containing data to be parsed
   */
   virtual void stripWhiteSpaceFromBounds
      (
      EcString& input
      ) const;

   /// Strip leading white space
   /**
      \param input String containing data to be parsed
   */
   virtual void stripLeadingWhiteSpace
      (
      EcString& input
      ) const;

   /// Strip trailing white space
   /**
      \param input String containing data to be parsed
   */
   virtual void stripTrailingWhiteSpace
      (
      EcString& input
      ) const;

   /// Strip leading slash from input
   /**
      \param input String containing data to be parsed
   */
   virtual void stripLeadingSlash
      (
      EcString& input
      ) const;

   /// Strip trailing slash from input
   /**
      \param input String containing data to be parsed
   */
   virtual void stripTrailingSlash
      (
      EcString& input
      ) const;

   /// Strip quotes from input
   /**
      \param input String containing data to be parsed
   */
   virtual void stripQuotes
      (
      EcString& input
      ) const;

   /// Does input have data?
   /**
      \param input String containing data to be analyzed
      \retval Flag indicating white space or not
   */
   virtual EcBoolean isWhiteSpace
      (
      EcString& input
      ) const;

   /**
      \brief Emits a warning message
      \param message a const char array
    */
   virtual void warnMessage
      (
      const char* message
      ) const;

   /// Input stream
   std::istream& m_Stream;

   /// File name
   EcString m_Filename;

   /// Error code
   mutable EcU32 m_ErrorCode;    // TODO: need enums for codes

   /// XML reader mode
   mutable XML_READER_MODE m_XmlReaderMode;

   /// Structure containing element and namespace map
   struct ElementStruct
   {
      EcToken elementName;                         ///< element name
      std::map<EcString,EcString> namespaceMap;    ///< namespace map
   };

   /// A type definition for the stack type based on std::stack
   typedef std::stack<ElementStruct> ElementStackType;
   
   /// The element stack
   ElementStackType m_ElementStack;

   /// A type definition for the Attribute map using std::map
   typedef std::map<EcToken,EcString> AttributeMapType;
   AttributeMapType m_AttributeMap;                ///< Attribute map

   /// Number of attributes
   EcU32 m_NumOfAttributes;

   /// Content
   mutable EcString m_Content;

   /// Content vector flag
   EcBoolean m_ContentVectorFlag;

   /// File line count
   EcInt32 m_LineCount;

   /// End tag element name
   EcToken m_EndTag;

   /// Temporary return token (speeds up code)
   mutable EcToken m_ReturnToken;

   /// Temporary return string (speeds up code)
   mutable EcString m_ReturnString;

   /// Temporary utility input string
   EcString m_UtilityInputString;

   /// Index for m_UtilityInputString
   EcString::size_type m_UtilityInputStringLocation;

   /// Temporary attribute name
   mutable EcToken m_UtilityAttributeName;

   /// Temporary attribute value
   mutable EcToken m_UtilityAttributeValue;

   /// Temporary namespace prefix
   mutable EcString m_UtilityNamespacePrefix;

   /// Temporary empty token (speeds up code)
   static const EcToken m_theNullToken;

   /// Temporary empty string (speeds up code)
   static const EcString m_theNullString;

   /// The namespace string of the XML schema instance
   static const EcString m_schemaInstanceNamespace;

private:
   /// Make sure m_UtilityInputString contains a newline
   void ensureNewlineExists
      (
      );

   /// Get the current char from m_UtilityInputString
   /**
      \retval The current char
   */
   char getCurrentChar
      (
      );

   /// Move through the input stream to the end of the block
   void moveToBlockEnd
      (
      );

   /// Move through the input stream to the specified delimeter
   /**
      \param delim Character of the delimeter to move to
   */
   void moveToDelim
      (
      char delim
      );

   /// Move through the input stream to the specified index
   /**
      \param index The index in m_UtilityInputString where line counting should stop
   */
   void moveToIndex
      (
      EcString::size_type index
      );

   /// Move through the input stream to the next word
   void moveToNextWord
      (
      );

   /// Read a block from m_Stream into m_UtilityInputString
   void readBlock
      (
      EcBoolean allowStringAlloc
      );

   /// the char array buffer. NOTE: This can be static if we are not concerned about thread safety
   boost::scoped_array<char> m_charBuffer;
};

#endif // ecXmlFileReader_H_
