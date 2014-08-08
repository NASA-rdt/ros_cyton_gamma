//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecVrml97GrammarAlgorithm.h
//
//------------------------------------------------------------------------------
#if !defined(EC_VRML97_ALGORITHM)
#   error You must define EC_VRML97_ALGORITHM prior to including EC_VRML97_ALGORITHM_GENERATOR()
#else
#   define  BOOST_PP_ITERATION_LIMITS (0, EC_VRML97_nRules - 1)
#   define  BOOST_PP_FILENAME_1       <vrml97/ecVrml97Grammar.h>
#   include BOOST_PP_ITERATE()
#   undef   EC_VRML97_ALGORITHM
#endif // EC_VRML97_ALGORITHM
