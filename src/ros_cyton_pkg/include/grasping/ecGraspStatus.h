#ifndef ecGraspStatus_H_
#define ecGraspStatus_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecGraspStatus.h
/// @brief This namespace contains the grasp status enumeration
/// @details namespace EcGraspStatus
//
//------------------------------------------------------------------------------

namespace EcGraspStatus
{

/// An enumeration of the status of a grasp: failed, in progress, finished, an so forth.
enum Enum
{
   FAILED = 0,
   IN_PROGRESS,
   KEY_PROGRESS,
   SUCCESS
};

}

#endif // ecGraspStatus_H_
