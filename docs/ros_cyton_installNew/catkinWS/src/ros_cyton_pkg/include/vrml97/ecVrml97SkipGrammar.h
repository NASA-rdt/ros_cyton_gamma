#ifndef ecVrml97SkipGrammar_H_
#define ecVrml97SkipGrammar_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecVrml97SkipGrammar.h
//
//------------------------------------------------------------------------------
#include <boost/version.hpp>
#if BOOST_VERSION < 103800
#   include <boost/spirit/core.hpp>
#else
#   define BOOST_SPIRIT_USE_OLD_NAMESPACE
#   include <boost/spirit/include/classic_core.hpp>
#endif

//----------------------------------------------------------------------------
struct EcVrml97SkipGrammar : boost::spirit::grammar<EcVrml97SkipGrammar>
{
   template <typename ScannerT>
   struct definition
   {
      boost::spirit::rule<ScannerT> r_skip;

      definition
         (
         EcVrml97SkipGrammar const& /*self*/
         );

      const boost::spirit::rule<ScannerT>& start
         (
         ) const;
   };
};

// Template implementation
#include <vrml97/ecVrml97SkipGrammar.ipp>

#endif // ecVrml97SkipGrammar_H_
