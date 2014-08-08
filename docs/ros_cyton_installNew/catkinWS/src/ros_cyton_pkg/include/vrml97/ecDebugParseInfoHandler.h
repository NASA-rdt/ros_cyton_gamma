#ifndef ecDebugParseInfoHandler_H_
#define ecDebugParseInfoHandler_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecDebugParseInfoHandler.h
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>

#include <boost/version.hpp>
#if BOOST_VERSION < 103800
#   include <boost/spirit/tree/common.hpp>
#else
#   define BOOST_SPIRIT_USE_OLD_NAMESPACE
#   include <boost/spirit/include/classic_common.hpp>
#endif

//----------------------------------------------------------------------------
class EC_FOUNDATION_VRML97_DECL EcDebugParseInfoHandler
{
public:
   typedef EcString::const_iterator                  IteratorT;
   typedef boost::spirit::tree_parse_info<IteratorT> ParseInfo;

   explicit EcDebugParseInfoHandler
      (
      std::ostream& os
      );

   void operator()
      (
      IteratorT        begin,
      IteratorT        end,
      const ParseInfo& info
      );

private:
   std::ostream& m_os;
};

#endif // ecDebugParseInfoHandler_H_
