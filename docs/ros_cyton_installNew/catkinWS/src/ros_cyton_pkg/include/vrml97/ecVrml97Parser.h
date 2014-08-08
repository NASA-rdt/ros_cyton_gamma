#ifndef ecVrml97Parser_H_
#define ecVrml97Parser_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecVrml97Parser.h
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>
#include <foundCore/ecTypes.h>

#include <boost/function.hpp>

#include <boost/version.hpp>
#if BOOST_VERSION < 103800
#   include <boost/spirit/tree/common.hpp>
#else
#   define BOOST_SPIRIT_USE_OLD_NAMESPACE
#   include <boost/spirit/include/classic_common.hpp>
#endif

//----------------------------------------------------------------------------
struct EC_FOUNDATION_VRML97_DECL EcVrml97Parser
{
   typedef EcString::const_iterator                  IteratorT;
   typedef boost::spirit::tree_parse_info<IteratorT> ParseInfo;
   typedef boost::function3<void, IteratorT, IteratorT, const ParseInfo&> ParseInfoHandler;

   EcBoolean operator()
      (
      const EcString&   fileName,
      ParseInfoHandler& handler
      );
};

#endif // ecVrml97Parser_H_
