//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecVrml97Grammar.ipp
//
//------------------------------------------------------------------------------


//---
// EcVrml97Grammar::definition constructor
//---

//----------------------------------------------------------------------------
template <typename ScannerT>
EcVrml97Grammar::definition<ScannerT>::definition
   (
   const EcVrml97Grammar& /*self*/
   ) :
   // A.1 VRML lexical elements (Keywords)
   r_IS           ("IS"),
   r_TO           ("TO"),
   r_EventIn      ("eventIn"),
   r_EventOut     ("eventOut"),
   r_ExposedField ("exposedField"),
   r_Field        ("field"),

   // A.1 VRML lexical elements (Terminal symbols)
   r_Period       ('.'),
   r_OpenBrace    ('{'),
   r_CloseBrace   ('}'),
   r_OpenBracket  ('['),
   r_CloseBracket (']')
{
#define EC_VRML97_ruleInBraces(rule)                          \
    boost::spirit::no_node_d[r_OpenBrace]   >> rule >>        \
    boost::spirit::no_node_d[r_CloseBrace]

#define EC_VRML97_ruleInBrackets(rule)                        \
    boost::spirit::no_node_d[r_OpenBracket] >> rule >>        \
    boost::spirit::no_node_d[r_CloseBracket]

#define EC_VRML97_lexemeLeafRule(rule)                        \
    boost::spirit::lexeme_d[boost::spirit::leaf_node_d[rule]]

   //---
   // A.2 General
   //---

   r_VrmlScene                      = +r_Statement >> boost::spirit::end_p;

   r_Statement                      = r_ProtoStatement
                                    | r_RouteStatement
                                    | r_NodeStatement;

   r_NodeStatement                  = r_NodeUseStatement
                                    | r_RootNodeStatement;

   r_NodeUseStatement               = boost::spirit::str_p("USE") >> r_NodeNameId;

   r_RootNodeStatement              = r_NodeDefStatement
                                    | r_Node;

   r_NodeDefStatement               = boost::spirit::str_p("DEF") >> r_NodeNameId >> r_Node;

   r_ProtoStatement                 = boost::spirit::str_p("PROTO")       >> r_ProtoTypeId >> r_ProtoDeclaration       >> r_ProtoDefinition
                                    | boost::spirit::str_p("EXTERNPROTO") >> r_ProtoTypeId >> r_ExternprotoDeclaration >> r_URLList;

   r_ProtoDeclaration               = EC_VRML97_ruleInBrackets(+r_InterfaceDeclaration);

   r_ExternprotoDeclaration         = EC_VRML97_ruleInBrackets(+r_ExternInterfaceDeclaration);

   r_ProtoDefinition                = EC_VRML97_ruleInBraces(r_ProtoBody);

   r_ProtoBody                      = +r_ProtoStatement >> r_RootNodeStatement >> +r_Statement;

   r_RestrictedInterfaceDeclaration = r_EventIn  >> r_FieldType >> r_EventInId
                                    | r_EventOut >> r_FieldType >> r_EventOutId
                                    | r_Field    >> r_FieldType >> boost::spirit::root_node_d[r_FieldId] >> r_FieldValue;

   r_InterfaceDeclaration           = r_ExposedField >> r_FieldType >> r_FieldId >> r_FieldValue
                                    | r_RestrictedInterfaceDeclaration;

   r_ExternInterfaceDeclaration     = r_EventIn      >> r_FieldType >> r_EventInId
                                    | r_EventOut     >> r_FieldType >> r_EventOutId
                                    | r_ExposedField >> r_FieldType >> r_FieldId
                                    | r_Field        >> r_FieldType >> r_FieldId;

   r_RouteStatement                 = boost::spirit::str_p("ROUTE") >> r_NodeNameId >> r_Period >> r_EventOutId >> r_TO >> r_NodeNameId >> r_Period >> r_EventInId;

   r_URLList                        = r_StringArray;

   //---
   // A.3 Nodes
   //---

   r_Node              = boost::spirit::str_p("Script") >> r_ScriptDefinition
                       | boost::spirit::root_node_d[r_NodeTypeId] >> r_NodeDefinition;

   r_ScriptDefinition  = EC_VRML97_ruleInBraces(+r_ScriptBodyElement);

   r_ScriptBodyElement = r_EventIn  >> r_FieldType >> r_EventInId  >> r_IS >> r_EventInId
                       | r_EventOut >> r_FieldType >> r_EventOutId >> r_IS >> r_EventOutId
                       | r_Field    >> r_FieldType >> r_FieldId    >> r_IS >> r_FieldId
                       | r_RestrictedInterfaceDeclaration
                       | r_NodeBodyElement;

   r_NodeDefinition    = EC_VRML97_ruleInBraces(+r_NodeBodyElement);

   r_NodeBodyElement   = r_EventInId  >> r_IS >> r_EventInId
                       | r_EventOutId >> r_IS >> r_EventOutId
                       | r_FieldId    >> r_IS >> r_FieldId
                       | r_RouteStatement
                       | r_ProtoStatement
                       | boost::spirit::root_node_d[r_FieldId] >> r_FieldValue;

   r_ProtoTypeId       = EC_VRML97_lexemeLeafRule(r_IdFirstChar >> *r_IdNextChar);
   r_NodeNameId        = EC_VRML97_lexemeLeafRule(r_IdFirstChar >> *r_IdNextChar);
   r_NodeTypeId        = EC_VRML97_lexemeLeafRule(r_IdFirstChar >> *r_IdNextChar);
   r_FieldId           = EC_VRML97_lexemeLeafRule(r_IdFirstChar >> *r_IdNextChar);
   r_EventInId         = EC_VRML97_lexemeLeafRule(r_IdFirstChar >> *r_IdNextChar);
   r_EventOutId        = EC_VRML97_lexemeLeafRule(r_IdFirstChar >> *r_IdNextChar);

   // FIXME: Any ISO-10646 character encoded using UTF-8 except:
   //    0x30-0x39, 0x0-0x20,
   //    0x22, 0x23, 0x27, 0x2b, 0x2c, 0x2d, 0x2e,
   //    0x5b, 0x5c, 0x5d, 0x7b, 0x7d, 0x7f
   r_IdFirstChar = boost::spirit::alpha_p;
   //r_IdFirstChar = r_IdNextChar - boost::spirit::chset<>("\x30-\x39\x2b\x2d");

   // FIXME: Any number of ISO-10646 characters except:
   //    0x0-0x20,
   //    0x22, 0x23, 0x27, 0x2c, 0x2e,
   //    0x5b, 0x5c, 0x5d, 0x7b, 0x7d, 0x7f
   r_IdNextChar = boost::spirit::alnum_p | boost::spirit::ch_p('_') | boost::spirit::ch_p('-');
   //r_IdNextChar = boost::spirit::anychar_p - boost::spirit::chset<>("\x0-\x20\x22\x23\x27\x2c\x2e\x5b\x5c\x5d\x7b\x7d\x7f");

   //---
   // A.4 Fields
   //---

   r_FieldType        = boost::spirit::str_p("MFColor")
                      | boost::spirit::str_p("MFFloat")
                      | boost::spirit::str_p("MFInt32")
                      | boost::spirit::str_p("MFNode")
                      | boost::spirit::str_p("MFRotation")
                      | boost::spirit::str_p("MFString")
                      | boost::spirit::str_p("MFTime")
                      | boost::spirit::str_p("MFVec2f")
                      | boost::spirit::str_p("MFVec3f")
                      | boost::spirit::str_p("SFBool")
                      | boost::spirit::str_p("SFColor")
                      | boost::spirit::str_p("SFFloat")
                      | boost::spirit::str_p("SFImage")
                      | boost::spirit::str_p("SFInt32")
                      | boost::spirit::str_p("SFNode")
                      | boost::spirit::str_p("SFRotation")
                      | boost::spirit::str_p("SFString")
                      | boost::spirit::str_p("SFTime")
                      | boost::spirit::str_p("SFVec2f")
                      | boost::spirit::str_p("SFVec3f");

   r_FieldValue       = r_EmptyBrackets
                      | r_NodeArray
                      | r_StringArray
                      | r_IntegerArray
                      | r_FloatArray
                      | r_NodeStatement
                      | r_String
                      //| r_Image
                      | r_Vec4f
                      | r_Vec3f
                      | r_Vec2f
                      | r_Float
                      | r_Integer
                      | r_Bool
                      | boost::spirit::str_p("NULL");

   r_Bool             = boost::spirit::str_p("TRUE")
                      | boost::spirit::str_p("FALSE");

   // [+/-]?((([0-9]+(\.)?)|([0-9]*\.[0-9]+))([eE][+\-]?[0-9]+)?)
   r_Float            = boost::spirit::real_p;

   // FIXME: r_Integer >> r_Integer >> r_Integer ...
   r_Image            = r_Integer >> r_Integer >> *r_Integer;

   // [+\-]?(([0-9]+)|(0[xX][0-9a-fA-F]+))
   r_Integer          = EC_VRML97_lexemeLeafRule(!r_SignDigit >> r_HexValue)
                      | boost::spirit::int_p;

   // FIXME: ".*" ... double-quotes must be \", backslashes must be \\...
   r_String           = EC_VRML97_lexemeLeafRule(boost::spirit::inner_node_d[boost::spirit::confix_p('"', *boost::spirit::c_escape_ch_p, '"')]);

   r_Vec2f            = r_Float >> r_Float;

   r_Vec3f            = r_Float >> r_Float >> r_Float;

   r_Vec4f            = r_Float >> r_Float >> r_Float >> r_Float;

   r_FloatArray       = EC_VRML97_ruleInBrackets(+r_Float);

   r_IntegerArray     = EC_VRML97_ruleInBrackets(+r_Integer);

   r_NodeArray        = EC_VRML97_ruleInBrackets(+r_NodeStatement);

   r_StringArray      = EC_VRML97_ruleInBrackets(+r_String);

   //---
   // Helper rules
   //---

   // [+/-]?
   r_SignDigit        = boost::spirit::ch_p('+')
                      | boost::spirit::ch_p('-');

   // 0[xX][0-9a-fA-F]+
   r_HexValue         =  boost::spirit::ch_p('0')
                      >> boost::spirit::as_lower_d[boost::spirit::ch_p('x')]
                      >> +r_HexDigit;

   // [0-9a-fA-F]
   r_HexDigit         = boost::spirit::range_p('0', '9')
                      | boost::spirit::range_p('a', 'f')
                      | boost::spirit::range_p('A', 'F');

   r_EmptyBrackets    =  boost::spirit::no_node_d[r_OpenBracket]
                      >> boost::spirit::no_node_d[r_CloseBracket];

   //---
   // Debug code
   //---

   // A.1 VRML lexical elements (Keywords)
   BOOST_SPIRIT_DEBUG_RULE(r_IS);
   BOOST_SPIRIT_DEBUG_RULE(r_TO);
   BOOST_SPIRIT_DEBUG_RULE(r_EventIn);
   BOOST_SPIRIT_DEBUG_RULE(r_EventOut);
   BOOST_SPIRIT_DEBUG_RULE(r_ExposedField);
   BOOST_SPIRIT_DEBUG_RULE(r_Field);

   // A.1 VRML lexical elements (Terminal symbols)
   BOOST_SPIRIT_DEBUG_RULE(r_Period);
   BOOST_SPIRIT_DEBUG_RULE(r_OpenBrace);
   BOOST_SPIRIT_DEBUG_RULE(r_CloseBrace);
   BOOST_SPIRIT_DEBUG_RULE(r_OpenBracket);
   BOOST_SPIRIT_DEBUG_RULE(r_CloseBracket);

   // A.3 Nodes
   BOOST_SPIRIT_DEBUG_RULE(r_IdFirstChar);
   BOOST_SPIRIT_DEBUG_RULE(r_IdNextChar);

   // Helper rules
   BOOST_SPIRIT_DEBUG_RULE(r_SignDigit);
   BOOST_SPIRIT_DEBUG_RULE(r_HexValue);
   BOOST_SPIRIT_DEBUG_RULE(r_HexDigit);

   // Generate debug rule statements for EC_VRML97_grammarRules
#define  EC_VRML97_ALGORITHM 4
#include EC_VRML97_ALGORITHM_GENERATOR()

#undef EC_VRML97_lexemeLeafRule
#undef EC_VRML97_ruleInBrackets
#undef EC_VRML97_ruleInBraces
}

//---
// EcVrml97Grammar::definition public methods
//---

//----------------------------------------------------------------------------
template <typename ScannerT>
const typename EcVrml97Grammar::definition<ScannerT>::VrmlSceneType&
EcVrml97Grammar::definition<ScannerT>::start
   (
   ) const
{
   return r_VrmlScene;
}
