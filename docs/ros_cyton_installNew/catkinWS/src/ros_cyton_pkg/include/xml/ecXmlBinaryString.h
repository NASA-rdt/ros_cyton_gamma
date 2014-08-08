//------------------------------------------------------------------------------
// Copyright (c) 2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlBinaryString.h
/// @class EcXmlBinaryString
/// @brief XML wrapper to provide customized serialization for binary strings.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>
#include "ecXmlBasicType.h"

class EC_STABLE_XML_DECL EcXmlBinaryString : public EcXmlString
{
public:
   /// Constructor
   EcXmlBinaryString
      (
      );

   /// Constructor with initializer value
   EcXmlBinaryString
      (
      const EcString& val
      );

   /// Read the value from an EcXmlReader stream
   EcBoolean read
      (
      EcXmlReader& stream
      );

   /// Write the value to an EcXmlReader stream
   EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// Takes an XML-encoded string and converts to binary form.
   void setFromString
      (
      const EcString& data ///< [in] Valid XML-encoded string
      );

   /// Converts from a binary string to a valid XML string.
   /// @return EcString Valid XML string
   EcString toString
      (
      ) const;

protected:
   static const EcString m_EncodeTable; ///< Base64 encoding table
   static EcInt8 m_DecodeTable[256];    ///< Base64 decoding table
};
