#ifndef ecConsolePerformGraspCallbacks_H_
#define ecConsolePerformGraspCallbacks_H_
//------------------------------------------------------------------------------
// Copyright (c) 2002-2013 Energid Technologies. All rights reserved.
//
/// @file ecConsolePerformGraspCallbacks.h
/// @class EcConsolePerformGraspCallbacks
/// @brief Simple implementation of EcPerformGraspCallbacks
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.

#include "ecPerformGraspCallbacks.h"

class EcConsolePerformGraspCallbacks : public EcPerformGraspCallbacks
{
public:
   virtual void graspComplete
      (
      EcBoolean success
      );

   virtual void initializationFailed
      (
      );

   virtual void loopStart
      (
      EcReal time
      );
};

#endif // ecConsolePerformGraspCallbacks_H_
