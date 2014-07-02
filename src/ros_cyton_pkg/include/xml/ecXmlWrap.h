#ifndef ecXmlWrap_H_
#define ecXmlWrap_H_
//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecXmlWrap.h
/// @brief This file provides XML Wrappers for classes
//
//------------------------------------------------------------------------------
#include <foundCore/ecConfig.h>  // Required to be first header.
#include "ecBaseExpTreeContainer.h"

#ifdef _MSC_VER
#  pragma warning(disable:4661) // no explicit template instantiation of base
#endif

/// Registers the xml object creator fo the class
#define REGISTER_CREATOR(cls) registerComponentCreator(cls::classToken(), cls::xmlObjectCreator)

/// Returns the class token of the XML object
#define CLASS_TOKEN(tok) static const EcToken& classToken() tok

/// Wraps an EcBaseExpressionTreeContainer
#define ECWRAP_BASEEXPTREECONTAINER(decl, name, cls, clsToken, registerCreators) \
class decl name : public EcBaseExpressionTreeContainer<cls> \
{ \
public: \
   explicit name(cls* ptr = EcNULL) : EcBaseExpressionTreeContainer<cls>() \
   { m_pTopElement = ptr; } \
   ~name() { m_pTopElement = EcNULL; } \
   void registerComponentCreators() registerCreators \
   \
   ECXMLOBJECT_CLONE(name) \
   ECXMLOBJECT_EQUALITY(name) \
   ECXMLOBJECT_NEWOBJECT(name) \
   ECXML_XMLOBJECTCREATOR(name) \
   virtual const EcToken& token() const { return classToken(); } \
   clsToken \
};

#endif // ecXmlWrap_H_
