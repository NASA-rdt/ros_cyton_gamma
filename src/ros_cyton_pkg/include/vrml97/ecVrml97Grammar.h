#ifndef BOOST_PP_IS_ITERATING
//------------------------------------------------------------------------------
// Copyright (c) 2013 Energid Technologies. All rights reserved.
//
/// @file ecVrml97Grammar.h
//
//------------------------------------------------------------------------------

#ifndef ecVrml97Grammar_H_
#define ecVrml97Grammar_H_
//     Copyright (c) 2008-2011 Energid Technologies. All rights reserved. ////
//
// Filename:    ecVrml97Grammar.h
//
//
// Description:
//
// Contents:
//
/////////////////////////////////////////////////////////////////////////
#      include <foundation/foundation_config.h>
#      include <foundCore/ecTypes.h>

#      include <map>

#      include <boost/assign/list_of.hpp>
#      include <boost/preprocessor/comparison/greater.hpp>
#      include <boost/preprocessor/facilities/expand.hpp>
#      include <boost/preprocessor/iteration/iterate.hpp>
#      include <boost/preprocessor/punctuation/paren.hpp>
#      include <boost/preprocessor/seq.hpp>

#      include <boost/version.hpp>
#      if BOOST_VERSION < 103800
#         include <boost/spirit/core.hpp>
#         include <boost/spirit/tree/ast.hpp>
#         include <boost/spirit/utility.hpp>
#      else
#         define BOOST_SPIRIT_USE_OLD_NAMESPACE
#         include <boost/spirit/include/classic_core.hpp>
#         include <boost/spirit/include/classic_ast.hpp>
#         include <boost/spirit/include/classic_utility.hpp>
#      endif

//---
// Local macro definitions
//---

//----------------------------------------------------------------------------
// Grammar rules
//
// This macro contains a sequence of rule elements.  Each rule element is a
//    sequence that may contain either one or two data elements.  The first
//    data element is the rule name.  The second data element (if it exists)
//    is a descriptor string.  If the second data element does not exist, then
//    the rule name is used as the descriptor string.
//----------------------------------------------------------------------------
#      define EC_VRML97_grammarRules                     \
       ((VrmlScene                     )               ) \
       ((Statement                     )               ) \
       ((NodeStatement                 )               ) \
       ((NodeUseStatement              )               ) \
       ((RootNodeStatement             )               ) \
       ((NodeDefStatement              )               ) \
       ((ProtoStatement                )               ) \
       ((ProtoDeclaration              )               ) \
       ((ExternprotoDeclaration        )               ) \
       ((ProtoDefinition               )               ) \
       ((ProtoBody                     )               ) \
       ((RestrictedInterfaceDeclaration)               ) \
       ((InterfaceDeclaration          )               ) \
       ((ExternInterfaceDeclaration    )               ) \
       ((RouteStatement                )               ) \
       ((URLList                       )               ) \
                                                         \
       ((Node                          )               ) \
       ((ScriptDefinition              )               ) \
       ((ScriptBodyElement             )               ) \
       ((NodeDefinition                )               ) \
       ((NodeBodyElement               )               ) \
       ((ProtoTypeId                   ) ("ProtoType" )) \
       ((NodeNameId                    ) ("NodeName"  )) \
       ((NodeTypeId                    ) ("NodeType"  )) \
       ((FieldId                       ) ("Field"     )) \
       ((EventInId                     ) ("EventIn"   )) \
       ((EventOutId                    ) ("EventOut"  )) \
                                                         \
       ((FieldType                     )               ) \
       ((FieldValue                    )               ) \
       ((Bool                          )               ) \
       ((Float                         )               ) \
       ((Image                         )               ) \
       ((Integer                       )               ) \
       ((String                        )               ) \
       ((Vec2f                         )               ) \
       ((Vec3f                         )               ) \
       ((Vec4f                         )               ) \
       ((FloatArray                    )               ) \
       ((IntegerArray                  )               ) \
       ((NodeArray                     )               ) \
       ((StringArray                   )               ) \
                                                         \
       ((EmptyBrackets                 )               )

#      define EC_VRML97_nRules      BOOST_PP_SEQ_SIZE(EC_VRML97_grammarRules)
#      define EC_VRML97_rule(n)     BOOST_PP_SEQ_ELEM(n, EC_VRML97_grammarRules)
#      define EC_VRML97_currentRule EC_VRML97_rule(BOOST_PP_ITERATION())
#      define EC_VRML97_ruleName    BOOST_PP_SEQ_ELEM(0, EC_VRML97_currentRule)
#      define EC_VRML97_ruleType    BOOST_PP_CAT(EC_VRML97_ruleName, Type)
#      define EC_VRML97_ruleVar     BOOST_PP_CAT(r_, EC_VRML97_ruleName)

#      define EC_VRML97_expandedRule                                          \
          BOOST_PP_IIF                                                        \
          (                                                                   \
             BOOST_PP_GREATER(BOOST_PP_SEQ_SIZE(EC_VRML97_currentRule), 1),   \
             EC_VRML97_currentRule,                                           \
             (EC_VRML97_currentRule) (BOOST_PP_STRINGIZE(EC_VRML97_ruleName)) \
          )

#      define EC_VRML97_ruleString  BOOST_PP_SEQ_ELEM(1, EC_VRML97_expandedRule)

#      define EC_VRML97_ALGORITHM_GENERATOR() <vrml97/ecVrml97GrammarAlgorithm.h>

//----------------------------------------------------------------------------
class EC_FOUNDATION_VRML97_DECL EcVrml97Grammar : public boost::spirit::grammar<EcVrml97Grammar>
{
public:
   struct RuleID
   {
      enum
      {
         // Generate rule ids for EC_VRML97_grammarRules
#      define  EC_VRML97_ALGORITHM 1
#      include EC_VRML97_ALGORITHM_GENERATOR()
      };
   };

   typedef std::map<boost::spirit::parser_id, EcString> RuleNamesType;
   static const RuleNamesType& ruleNames
      (
      )
   {
      static RuleNamesType ruleNames = boost::assign::map_list_of
         // Generate rule name mappings for EC_VRML97_grammarRules
#      define  EC_VRML97_ALGORITHM 2
#      include EC_VRML97_ALGORITHM_GENERATOR()
         ;

      return ruleNames;
   }

   template <typename ScannerT>
   struct definition
   {
      typedef typename boost::spirit::lexeme_scanner
      <
         ScannerT
      >::type LexemeScannerT;

      // ISO-IEC-14772-VRML97 Specification

      // A.1 VRML lexical elements (Keywords)
      boost::spirit::strlit<>
         r_IS,
         r_TO,
         r_EventIn,
         r_EventOut,
         r_ExposedField,
         r_Field;

      // A.1 VRML lexical elements (Terminal symbols)
      boost::spirit::chlit<>
         r_Period,
         r_OpenBrace,
         r_CloseBrace,
         r_OpenBracket,
         r_CloseBracket;

      // A.3 Nodes
      boost::spirit::rule<LexemeScannerT>
         r_IdFirstChar,
         r_IdNextChar;

      // Helper rules
      boost::spirit::rule<LexemeScannerT>
         r_SignDigit,
         r_HexValue,
         r_HexDigit;

      // Generate rule declarations for EC_VRML97_grammarRules
#      define  EC_VRML97_ALGORITHM 3
#      include EC_VRML97_ALGORITHM_GENERATOR()

      definition
         (
         const EcVrml97Grammar& /*self*/
         );

      const VrmlSceneType& start
         (
         ) const;
   };
};

// Template implementation
#include <vrml97/ecVrml97Grammar.ipp>

//---
// Clean up local macro definitions
//---

#      undef EC_VRML97_ALGORITHM_GENERATOR
#      undef EC_VRML97_ruleString
#      undef EC_VRML97_expandedRule
#      undef EC_VRML97_ruleVar
#      undef EC_VRML97_ruleType
#      undef EC_VRML97_ruleName
#      undef EC_VRML97_currentRule
#      undef EC_VRML97_rule
#      undef EC_VRML97_nRules
#      undef EC_VRML97_grammarRules

#   endif // ecVrml97Grammar_H_

//---
// Preprocessor repetition algorithms
//---

#else // BOOST_PP_IS_ITERATING
#   if (EC_VRML97_ALGORITHM == 1)
         // Generated rule id
         EC_VRML97_ruleName = BOOST_PP_INC(BOOST_PP_ITERATION()),
#   elif (EC_VRML97_ALGORITHM == 2)
         // Generated rule name mapping
         (boost::spirit::parser_id(RuleID::EC_VRML97_ruleName), EC_VRML97_ruleString)
#   elif (EC_VRML97_ALGORITHM == 3)

      // Generated rule declaration
      typedef typename boost::spirit::rule
      <
         ScannerT,
         boost::spirit::parser_context<>,
         boost::spirit::parser_tag<RuleID::EC_VRML97_ruleName>
      > EC_VRML97_ruleType;
      EC_VRML97_ruleType EC_VRML97_ruleVar;
#   elif (EC_VRML97_ALGORITHM == 4)
      // Generated debug rule statement
      BOOST_PP_EXPAND(BOOST_SPIRIT_DEBUG_RULE BOOST_PP_LPAREN() EC_VRML97_ruleVar BOOST_PP_RPAREN());
#   endif

#endif // BOOST_PP_IS_ITERATING
