#ifndef ecXmlReader_H_
#define ecXmlReader_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlReader.h
/// @class EcXmlReader
/// @brief An XML file reader
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.

#include "ecBaseXmlFactory.h"
#include "ecSignalTypes.h"
#include "ecXmlFileReader.h"

#include <foundCore/ecConnectionManagerTypes.h>

class EC_STABLE_XML_DECL EcXmlReader
{
public:
   /// Default constructor
   EcXmlReader
      (
      );

   /// Constructor with filename argument
   EcXmlReader
      (
      const EcString& filename,
      std::istream& stream
      );

   /// Default destructor
   virtual ~EcXmlReader
      (
      );

   /// copy constructor
   EcXmlReader
      (
      const EcXmlReader& orig
      );

   /// assignment operator
   EcXmlReader& operator=
      (
      const EcXmlReader& orig
      );

   /// Opens an XML reader
   virtual void open
      (
      const EcString& filename,
      std::istream& stream
      );

   /// Executive for XML processing
   virtual EcXmlFileReader::XML_READER_MODE readXml
      (
      );

   /// Get version flag
   virtual EcBoolean versionFlag
      (
      ) const;

   /// Get mode
   virtual EcXmlFileReader::XML_READER_MODE mode
      (
      ) const;

   /// Get element name
   virtual const EcToken& element
      (
      ) const;

   /// Get next attribute name (then pop value -> nonconst)
   virtual const EcToken& attributeName
      (
      );

   /// Get next attribute name given key (then pop value -> nonconst)
   virtual const EcToken& attributeName
      (
      const EcToken& key
      );

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

   /// Get file name
   /// \return char * is returned due to the type needed by EcWARN
   virtual const char* filename
      (
      );

   /// Get line count
   virtual EcInt32 lineCountOfFile
      (
      ) const;

   /// Continue reading to matching end tag for current element
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

   /// Get input stream
   virtual std::istream& stream
      (
      ) const;

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

   /// Set (and delete) the factory pionter
   virtual void setFactoryPointer
      (
      EcBaseXmlFactory* pFactory
      );

   /// Get the factory pointer
   virtual const EcBaseXmlFactory* factoryPointer
      (
      ) const;

   /// register a single optional component with the factory
   /// returns true if a new factory is created
   virtual EcBoolean registerComponentCreator
      (
      const EcToken& token,
      EcXmlObjectCreator creator
      );

   /// Get error code
   virtual EcU32 errorCode
      (
      ) const;

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

protected:

   /// Test for open of include file
   virtual EcBoolean openFileTest
      (
      );

   /// Test for close of include file
   virtual EcBoolean closeFileTest
      (
      );

   /// Parse href into url, path, and file name
   virtual void parseHref
      (
      const EcString& href,
      EcString& url,
      EcString& path,
      EcString& file
      );

   /// Test compatibility of XML file
   virtual EcBoolean checkVersion
      (
      );

   /// XML factory creator.  Used internally
   virtual EcBaseXmlFactory* newFactory
      (
      ) const;

   /// Pointer to top (i.e., of stack) file reader
   std::stack<EcXmlFileReader> m_XmlFileReader;

   /// Perform version check
   EcBoolean m_VersionPerformCheckFlag;

   /// Is version valid?
   EcBoolean m_VersionFlag;

   /// A factory pointer
   EcBaseXmlFactory* m_pFactory;

   /// Signal pointer to read signal status for front end GUI
   Ec::ConnectionManagerTypes::Signal<Ec::SignalReadWriteStatusTraits::Type>::PtrType m_SignalStatusPtr;

   /// Signal pointer to read signal progress for front end GUI
   Ec::ConnectionManagerTypes::Signal<Ec::SignalReadWriteProgressTraits::Type>::PtrType m_SignalProgressPtr;

   EcU32 m_LinkTotal; ///< total number of links
   EcU32 m_LinkCount; ///< Link count
};

#endif // ecXmlReader_H_
