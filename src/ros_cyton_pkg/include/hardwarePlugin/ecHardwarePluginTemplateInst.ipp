//------------------------------------------------------------------------------
// Copyright (c) 2011-2013 Energid Technologies. All rights reserved.
//
/// @file ecHardwarePluginTemplateInst.ipp
/// @brief Template instantiation of setParam, getParam and param methods.
///        These items are the only valid combinations of CommandType and
///        variable type that we allow.  Performs compile-time checking
///        of parameters to ensure proper usage.
/// @details Plugin template instantiations of allowed types.
///
/// NOTE - The use of generic types that can be declared in other ways is
/// discouraged.  For example an EcU32 may be specified as an EcInt32 or
/// another compatible type.  This causes the user to explicitly cast it into
/// and EcU32 to resolve the symbol and might not necessarily be intuitive.
/// Forcing it to a typedef or other type is preferable to remove potential
/// confusion.
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Provide convenience macros to forward declare specific parameter types.
//------------------------------------------------------------------------------

/// setParam that takes 2 additional arguments
#define FWD_DECL_S2PARAM(T1,T2) \
   EC_ACTIN_HWPLUGIN_PRETEMPLATE_DECL template EC_ACTIN_HWPLUGIN_DECL EcBoolean \
   Plugin::setParam<T1|HardwareUnits,T2>(const EcU32, const EcU32, const T2&)
/// getParam that takes 2 additional arguments
#define FWD_DECL_G2PARAM(T1,T2) \
   EC_ACTIN_HWPLUGIN_PRETEMPLATE_DECL template EC_ACTIN_HWPLUGIN_DECL EcBoolean \
   Plugin::getParam<T1|HardwareUnits,T2>(const EcU32, const EcU32, T2&) const

/// setParam that takes 1 additional argument
#define FWD_DECL_S1PARAM(T1,T2) \
   EC_ACTIN_HWPLUGIN_PRETEMPLATE_DECL template EC_ACTIN_HWPLUGIN_DECL EcBoolean \
   Plugin::setParam<T1|HardwareUnits,T2>(const EcU32, const T2&)
/// getParam that takes 1 additional argument
#define FWD_DECL_G1PARAM(T1,T2) \
   EC_ACTIN_HWPLUGIN_PRETEMPLATE_DECL template EC_ACTIN_HWPLUGIN_DECL EcBoolean \
   Plugin::getParam<T1|HardwareUnits,T2>(const EcU32, T2&) const

/// setParam that takes no additional arguments
#define FWD_DECL_S0PARAM(T1,T2) \
   EC_ACTIN_HWPLUGIN_PRETEMPLATE_DECL template EC_ACTIN_HWPLUGIN_DECL EcBoolean \
   Plugin::setParam<T1|HardwareUnits,T2>(const T2&)
/// getParam that takes no additional arguments
#define FWD_DECL_G0PARAM(T1,T2) \
   EC_ACTIN_HWPLUGIN_PRETEMPLATE_DECL template EC_ACTIN_HWPLUGIN_DECL EcBoolean \
   Plugin::getParam<T1|HardwareUnits,T2>(T2&) const

/// Build up smaller macros into consolidated get/set ones.
#define FWD_DECL_SG2PARAM(T1,T2) FWD_DECL_S2PARAM(T1,T2);FWD_DECL_G2PARAM(T1,T2)
#define FWD_DECL_SG1PARAM(T1,T2) FWD_DECL_S1PARAM(T1,T2);FWD_DECL_G1PARAM(T1,T2)
#define FWD_DECL_SG0PARAM(T1,T2) FWD_DECL_S0PARAM(T1,T2);FWD_DECL_G0PARAM(T1,T2)


FWD_DECL_SG1PARAM(InitJointAngle, EcRealVector);
FWD_DECL_SG0PARAM(InitJointAngle, EcRealVector); // Uses m_ManipIndex

FWD_DECL_SG1PARAM(JointAngle,     EcRealVector);
FWD_DECL_SG0PARAM(JointAngle,     EcRealVector); // Uses m_ManipIndex

FWD_DECL_SG1PARAM(JointVelocity,  EcRealVector);
FWD_DECL_SG0PARAM(JointVelocity,  EcRealVector); // Uses m_ManipIndex

#undef FWD_DECL_SG2PARAM
#undef FWD_DECL_SG1PARAM
#undef FWD_DECL_SG0PARAM
#undef FWD_DECL_S2PARAM
#undef FWD_DECL_S1PARAM
#undef FWD_DECL_S0PARAM
#undef FWD_DECL_G2PARAM
#undef FWD_DECL_G1PARAM
#undef FWD_DECL_G0PARAM
