#ifndef ecBaseXmlBasicType_H_
#define ecBaseXmlBasicType_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseXmlBasicType.h
/// @class EcBaseXmlBasicType
/// @brief Holds the parent class for all XML basic types.
/// @details The XML basic type is an XML object that actually holds the data
///          and doesn't have any children or elements.
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecXmlObject.h"

class EC_STABLE_XML_DECL EcBaseXmlBasicType : public EcXmlObject
{
public:
   /// set the value from a string
   virtual void setValueFromString
      (
      const EcString& string
      ) = 0;
};

#endif // ecBaseXmlBasicType_H_
