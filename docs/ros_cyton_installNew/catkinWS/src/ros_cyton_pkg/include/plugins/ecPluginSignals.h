#ifndef ec_PluginSignals_H_
#define ec_PluginSignals_H_
//------------------------------------------------------------------------------
// Copyright (c) 2012-2013 Energid Technologies. All rights reserved.
//
/// @file ecPluginSignals.h
/// @brief Provides traits classes for signals used by Ec::IODataBroker.
//
//------------------------------------------------------------------------------
#include <foundCore/ecFoundCoreSignals.h>  // Required to be first header.
#include "ecIOParams.h"

#include <manipulation/ecManipulationStatus.h>

#include <boost/mpl/string.hpp>
#include <boost/logic/tribool.hpp>

#ifndef WIN32
// Avoid getting warnings from gcc related to the use of multichar below.
// FIXME: I would like to use "diagnostic ignored"; however, the pragma does not seem to work.
//        system_header is a bit heavy-handed here.
//#  pragma GCC diagnostic ignored "-Wmultichar"
#  pragma GCC system_header
#endif

class EcCoordinateSystemTransformation;
class EcManipulationDirector;
class EcManipulationDirectorSimpleState;
class EcManipulatorAttachmentChange;
class EcPoseSet;
template <typename T> class EcXmlVectorType;
typedef EcXmlVectorType<EcPoseSet> EcPoseSetVector;   ///< XML vector of pose sets

namespace Ec
{
/// run states
enum RunStateEnum
{
   RunStatePause,    ///< pause
   RunStateStart,    ///< start
   RunStateStop,     ///< stop
   RunStateCancel,   ///< cancel
};

/// Plugin Messages (PM) used to pass data through the network transport
enum PluginParamTypeEnum
{
   // Default operation is a Get
   PM_SetModifier       = 0x8000, ///< Change operation from get to set

   // Plugin network enumerations start at 0x101
   PM_Ack               = 0x0100, ///< Acknowledgement message (EcBoolean)

   // hardwarePlugin messages
   PM_EmergencyStop,
   PM_HardwareEnable,             ///< (GS,EcBoolean)
   PM_Reset,

   // manipulationDirectorExecPlugin messages
   PM_ProgramRunState,            ///< (GS,RunStateEnum)
   PM_ProgramFinished,            ///< (EcBoolean)
   PM_ProgramUpdate,              ///< (time,status,director,directorstate)
   PM_ManipulationActionContainer,///< (EcManipulationActionContainer)
   PM_ManipulationDirector,       ///< (EcManipulationDirector)
   PM_ManipulationDirectorScript, ///< (EcManipulationScript)

   // manipulationActionExecPlugin message
   PM_ManipulationActionManager,  ///< (EcManipulationActionManager)
   PM_ManipulationAction,         ///< (EcString)

   // manipulationSequenceExecPlugin message
   PM_ManipulationSequence,       ///< (EcString)

   // networkPlugin messages
   PM_InitialState,               ///< (SG,EcManipulatorSystemState)
   PM_NetworkModifier,            ///< (NetworkMode)
   PM_SystemSimulationFromFile,   ///< (EcString)
   PM_Terminate,

   // pathPlugin message
   PM_ManipulationPathFile,       ///< (EcString)

   // control-related message
   PM_AttachmentChange,           ///< (EcU32, EcBoolean) Manipulator index and whether it was
                                  ///< attached (true) or detached (false)
   PM_EndEffectorSet,             ///< (EcU32) Active end-effector set index
};


// NOTE: Must split Name into groups of 4 (or fewer) characters.

//------------------------------------------------------------------------------
/// Signal for attachment changes. This has better granularity than SignalAttachmentMapChangeTraits
/// since it will specify which manipulator is attached or detached
struct SignalAttachmentChangeTraits
{
   typedef boost::mpl::string<'atta', 'chme', 'ntCh', 'ange'> Name;               ///< boost mpl string
   typedef void (Type)(const EcManipulatorAttachmentChange& attachmentChange);    ///< signal for attachment changes
};

//------------------------------------------------------------------------------
/// Signal for attachment map
struct SignalAttachmentMapChangeTraits
{
   typedef boost::mpl::string<'atta', 'chme', 'ntMa', 'pCha', 'nge'> Name; ///< boost mpl string
   typedef void (Type)();                                                  ///< signal for attachment map
};

//------------------------------------------------------------------------------
/// Signal for collision exclusion map
struct SignalCollisionMapChangeTraits
{
   typedef boost::mpl::string<'coll', 'isio', 'nMap', 'Chan', 'ge'> Name; ///< boost mpl string
   typedef void (Type)();                                                 ///< signal for collision exclusion map
};

//------------------------------------------------------------------------------
/// Signal for active control description
/// @param manipIndex
/// @param descIndex
struct SignalControlDescriptionChangeTraits
{
   typedef boost::mpl::string<'cont', 'rolD', 'escr', 'ipti', 'onCh', 'ange'> Name; ///< boost mpl string
   typedef void (Type)(const EcU32 manipIndex, const EcU32 descIndex);              ///< signal for active control description
};

//------------------------------------------------------------------------------
/// Signal for active control method
/// @param manipIndex
/// @param methodIndex
struct SignalControlMethodChangeTraits
{
   typedef boost::mpl::string<'cont', 'rolM', 'etho', 'dCha', 'nge'> Name; ///< boost mpl string
   typedef void (Type)(const EcU32 manipIndex, const EcU32 methodIndex);   ///< signal for active control method
};

//------------------------------------------------------------------------------
/// Signal for control stop state
struct SignalControlStopStateChangeTraits
{
   typedef boost::mpl::string<'cont', 'rolS', 'topS', 'tate', 'Chan', 'ge'> Name; ///< boost mpl string
   typedef void (Type)(const EcU32 manipIndex);                                   ///< signal for control stop state
};

//------------------------------------------------------------------------------
/// Signal for control system change
struct SignalControlSystemChangeTraits
{
   typedef boost::mpl::string<'cont', 'rolS', 'yste', 'mCha', 'nge'> Name; ///< boost mpl string
   typedef void (Type)();                                                  ///< signal for control system change
};

//------------------------------------------------------------------------------
/// Signal dictating coordinated move on/off
/// @param manipIndex
/// @param enabled
struct SignalCoordinatedMoveTraits
{
   typedef boost::mpl::string<'coor', 'dina', 'ted', 'Move'> Name;          ///< boost mpl string
   typedef void (Type)(const EcU32 manipIndex, const EcBoolean enabled);    ///< signal dictating coordinated move on/off
};

//------------------------------------------------------------------------------
/// Signal for endEffectorSet change
/// @param manipIndex
/// @param eeSetIndex
struct SignalEndEffectorSetTraits
{
   typedef boost::mpl::string<'endE', 'ffec', 'torS', 'et'> Name;        ///< boost mpl string
   typedef void (Type)(const EcU32 manipIndex, const EcU32 eeSetIndex);  ///< signal for end effector set change
};

//------------------------------------------------------------------------------
/// Signal for add manipulator
/// @param manipLabel
struct SignalManipulatorAddTraits
{
   typedef boost::mpl::string<'mani', 'pula', 'torA', 'dd'> Name; ///< boost mpl string
   typedef void (Type)(const EcString& manipLabel);               ///< signal for add manipulator
};

//------------------------------------------------------------------------------
/// Signal for delete manipulator
/// @param manipIndex
struct SignalManipulatorDeleteTraits
{
   typedef boost::mpl::string<'mani', 'pula', 'torD', 'elet', 'e'> Name; ///< boost mpl string
   typedef void (Type)(const EcU32 manipIndex);                          ///< signal for delete manipulator
};

//------------------------------------------------------------------------------
/// Signal to notify when manipulation sequence has completed.
/// @param success
struct SignalManipulationSequenceCompleteTraits
{
   typedef boost::mpl::string<'mani', 'pula', 'tion', 'Comp','lete'> Name; ///< boost mpl string
   typedef void (Type)(const EcBoolean success);                           ///< signal to notify when manipulation sequence has completed
};

//------------------------------------------------------------------------------
/// Signal to notify when manipulation sequence has been updated.
/// @param state
struct SignalManipulationSequenceUpdateTraits
{
   typedef boost::mpl::string<'mani', 'pula', 'tion', 'Upda','te'> Name; ///< boost mpl string
   typedef void (Type)(const EcManipulationDirectorSimpleState& state);  ///< signal to notify when manipulation sequence has been updated
};

//------------------------------------------------------------------------------
/// Signal for being notified when poses have been loaded
/// @param poses
struct SignalPosesLoadedTraits
{
   typedef boost::mpl::string<'pose', 'sLoa', 'ded'> Name; ///< boost mpl string
   typedef void (Type)(const EcPoseSetVector& poses);      ///< signal for being notified when poses have been loaded
};

//------------------------------------------------------------------------------
/// Signal for being notified when poses has changed
/// @param name
/// @param coord
struct SignalPoseChangeTraits
{
   typedef boost::mpl::string<'pose', 'Chan', 'ged'> Name;                                    ///< boost mpl string
   typedef void (Type)(const EcString& name, const EcCoordinateSystemTransformation& coord);  ///< signal for being notified when poses has changed
};

//------------------------------------------------------------------------------
/// Signal indicating simulation state has changed
/// @param changed
struct SignalSimulationChangeTraits
{
   typedef boost::mpl::string<'simu', 'lati', 'onCh', 'ange'> Name; ///< boost mpl string
   typedef void (Type)(const EcU32 changed);                        ///< signal indicating simulation state has changed
};

//------------------------------------------------------------------------------
/// Signal indicating simulation is running or not
/// @param enabled
struct SignalSimulationEnableTraits
{
   typedef boost::mpl::string<'simu', 'lati', 'onEn', 'able'> Name; ///< boost mpl string
   typedef void (Type)(const EcBoolean enabled);                    ///< signal indicating simulation is running or not
};

//------------------------------------------------------------------------------
/// Signal indicating that the simulation is paused
struct SignalSimulationPauseTraits
{
   typedef boost::mpl::string<'simu', 'lati', 'onPa', 'use'> Name; ///< boost mpl string
   typedef void (Type)();                                          ///< signal indicating that the simulation is paused
};

//------------------------------------------------------------------------------
/// Signal indicating that the simulation is running
struct SignalSimulationStartTraits
{
   typedef boost::mpl::string<'simu', 'lati', 'onSt', 'art'> Name; ///< boost mpl string
   typedef void (Type)();                                          ///< signal indicating that the simulation is running
};

//------------------------------------------------------------------------------
/// Signal indicating that the simulation state has changed
/// @param state
struct SignalSimulationStateTraits
{
   typedef boost::mpl::string<'simu', 'lati', 'onSt', 'ate'> Name; ///< boost mpl string
   typedef void (Type)(const Ec::SimulationRunState state);        ///< signal indicating that the simulation state has changed
};

//------------------------------------------------------------------------------
/// Signal indicating that the simulation is stopped
struct SignalSimulationStopTraits
{
   typedef boost::mpl::string<'simu', 'lati', 'onSt', 'op'> Name; ///< boost mpl string
   typedef void (Type)();                                         ///< signal indicating that the simulation is stopped
};

//------------------------------------------------------------------------------
/// Signal indicating that a simulation timestep has been completed
struct SignalSimulationTimeStepTraits
{
   typedef boost::mpl::string<'simu', 'lati', 'onTi', 'meSt', 'ep'> Name;  ///< boost mpl string
   typedef void (Type)(const EcReal time);                                 ///< time parameter
};

//------------------------------------------------------------------------------
/// Signal indicating that a remote command has been completed
struct SignalRemoteCommandResultTraits
{
   typedef boost::mpl::string<'remo', 'teco', 'mman', 'dres', 'ult'> Name; ///< boost mpl string
   typedef LogicalAndCompleteResults Combiner;                             ///< combiner logical and complete results
   /// result type function
   typedef LogicalAndCompleteResults::result_type (Type)(const EcU32 msgType, const EcXmlObject& obj);
};


} // namespace Ec


#endif // ec_PluginSignals_H_
