//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecVrml97SkipGrammar.ipp
//
//------------------------------------------------------------------------------

//----------------------------------------------------------------------------
template <typename ScannerT>
EcVrml97SkipGrammar::definition<ScannerT>::definition
   (
   EcVrml97SkipGrammar const& /*self*/
   )
{
   // The '#' (0x23) character begins a comment wherever it appears
   //     outside of the first line of the VRML file or quoted
   //     SFString or MFString fields.  The '#' character and all
   //     characters until the next line terminator comprise the
   //     comment and are treated as whitespace.
   //
   // The carriage return (0x0d), linefeed (0x0a), space (0x20),
   //     tab (0x09), and comma (0x2c) characters are whitespace
   //     characters wherever they appear outside of quoted SFString
   //     or MFString fields.

   r_skip = boost::spirit::no_node_d[boost::spirit::comment_p("\x23")]
          | boost::spirit::no_node_d[boost::spirit::chset<>("\xd\xa\x20\x9\x2c")];

   BOOST_SPIRIT_DEBUG_RULE(r_skip);
}

//---
// EcVrml97SkipGrammar::definition public methods
//---

//----------------------------------------------------------------------------
template <typename ScannerT>
const typename boost::spirit::rule<ScannerT>&
EcVrml97SkipGrammar::definition<ScannerT>::start
   (
   ) const
{
   return r_skip;
}
