
#ifndef ec_XmlEmbeddedString_H_
#define ec_XmlEmbeddedString_H_

//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlEmbeddedString.h
/// @class EcXmlEmbeddedString
/// @brief An XML wrapper to provide customized reading for embedded XML
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>
#include "ecXmlBasicType.h"

class EC_STABLE_XML_DECL EcXmlEmbeddedString : public EcXmlString
{
public:
   ///constructor
   EcXmlEmbeddedString
      (
      );

   /**
    * @brief EcXmlEmbeddedString constructor
    * @param val EsString passed to the EcXmlString base class constructor
    */
   EcXmlEmbeddedString
      (
      const EcString& val
      );

   /// @copydoc EcXmlObject::read(EcXmlReader&)
   /// Customize reading to support embedded XML.
   /// @return EcBoolean Success or failure of command
   EcBoolean read
      (
      EcXmlReader& stream ///< [in] Input stream to read from
      );
};

#endif // ec_XmlEmbeddedString_H_
