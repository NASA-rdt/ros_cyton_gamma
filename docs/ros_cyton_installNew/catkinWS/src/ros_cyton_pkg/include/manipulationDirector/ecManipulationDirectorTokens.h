#ifndef ecManipulationDirectorTokens_H_
#define ecManipulationDirectorTokens_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecManipulationDirectorTokens.h
/// @brief Tokens for manipulation project
/// @details namespace ManipulationDirectorTokens
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>
#include <xml/ecToken.h>

/// Tokens for manipulation project
namespace EcManipulationDirectorTokens
{
   ECTOKEN_DEFINITIONS(EC_ACTIN_MANIPULATIONDIRECTOR_DECL,
      // Namespace for this class.  Used in later definitions.
      (ns, "http://www.energid.com/namespace/ct#")

      // Elements
      (EcActionDirectionToken,                                ns + "actionDirection")
      (EcActionDirectionStateToken,                           ns + "actionDirectionState")
      (EcActionDirectoryToken,                                ns + "actionDirectory")
      (EcActionParametersToken,                               ns + "actionParameters")
      (EcActionPathToken,                                     ns + "actionPath")
      (EcActiveSceneToken,                                    ns + "activeScene")
      (EcAdvanceToNextSceneToken,                             ns + "advanceToNextScene")
      (EcAndDirectionConditionToken,                          ns + "andDirectionCondition")
      (EcAssignObjectRoleDirectionToken,                      ns + "assignObjectRoleDirection")
      (EcAttachedRoleToken,                                   ns + "attachedRole")
      (EcAttachToDirectionToken,                              ns + "attachToDirection")
      (EcBaseRoleToken,                                       ns + "baseRole")
      (EcBaseLinkToken,                                       ns + "baseLink")
      (EcBasicDirectionSimpleStateToken,                      ns + "basicDirectionSimpleState")
      (EcCastToken,                                           ns + "cast")
      (EcCollisionExclusionDirectionToken,                    ns + "collisionExclusionDirection")
      (EcCommandToken,                                        ns + "command")
      (EcConditionalDirectionToken,                           ns + "conditionalDirection")
      (EcConditionalDirectionStateToken,                      ns + "conditionalDirectionState")
      (EcCueTypeToken,                                        ns + "cueType")
      (EcCueRoleToken,                                        ns + "cueRole")
      (EcCueDirectionIndexToken,                              ns + "cueDirectionIndex")
      (EcScriptCurrentItemToken,                              ns + "scriptCurrentItemIndex")
      (EcScriptSimpleStateCurrentItemToken,                   ns + "scriptSimpleStateCurrentItemIndex")
      (EcCurrentItemIndexToken,                               ns + "currentItemIndex")
      (EcDirectionConditionContainerToken,                    ns + "directionConditionContainer")
      (EcDirectionExceptionsToken,                            ns + "directionExceptions")
      (EcDirectionPathToken,                                  ns + "directionPath")
      (EcDirectionsToken,                                     ns + "directions")
      (EcDirectorObjectContainerToken,                        ns + "directorObjectContainer")
      (EcDirectorObjectDirectoryToken,                        ns + "directorObjectDirectory")
      (EcExclusionMapToken,                                   ns + "exclusionMap")
      (EcHasAttachmentConditionToken,                         ns + "hasAttachmentCondition")
      (EcIsAttachedToConditionToken,                          ns + "isAttachedToCondition")
      (EcLhsConditionContainerToken,                          ns + "lhsConditionContainer")
      (EcLoopFlagToken,                                       ns + "loopFlag")
      (EcManipulationActionDirectorObjectToken,               ns + "manipulationActionDirectorObject")
      (EcManipulationDirectionReferenceToken,                 ns + "manipulationDirectionReference")
      (EcManipulationDirectionReferenceStateToken,            ns + "manipulationDirectionReferenceState")
      (EcManipulationDirectorToken,                           ns + "manipulationDirector")
      (EcManipulationDirectorSimpleStateToken,                ns + "manipulationDirectorSimpleState")
      (EcManipulationDirectorStateToken,                      ns + "manipulationDirectorState")
      (EcManipulationSceneToken,                              ns + "manipulationScene")
      (EcManipulationSceneSimpleStateToken,                   ns + "manipulationSceneSimpleState")
      (EcManipulationSceneStateToken,                         ns + "manipulationSceneState")
      (EcManipulationSceneCueToken,                           ns + "manipulationSceneCue")
      (EcManipulationSceneDirectionContainerToken,            ns + "manipulationSceneDirectionContainer")
      (EcManipulationSceneDirectionDirectorObjectToken,       ns + "manipulationSceneDirectionDirectorObject")
      (EcManipulationSceneDirectionSimpleStateContainerToken, ns + "manipulationSceneDirectionSimpleStateContainer")
      (EcManipulationSceneDirectionStateContainerToken,       ns + "manipulationSceneDirectionStateContainer")
      (EcManipulationSceneDirectorObjectToken,                ns + "manipulationSceneDirectorObject")
      (EcManipulationScriptToken,                             ns + "manipulationScript")
      (EcManipulationScriptSimpleStateToken,                  ns + "manipulationScriptSimpleState")
      (EcManipulationScriptStateToken,                        ns + "manipulationScriptState")
      (EcNotDirectionConditionToken,                          ns + "notDirectionCondition")
      (EcObjectDirectoryToken,                                ns + "objectDirectory")
      (EcObjectMapToken,                                      ns + "objectMap")
      (EcObjectRoleToken,                                     ns + "objectRole")
      (EcOrDirectionConditionToken,                           ns + "orDirectionCondition")
      (EcPersistentConditionExceptionsToken,                  ns + "persistentConditionExceptions")
      (EcPersistentConditionsToken,                           ns + "persistentConditions")
      (EcPostConditionExceptionsToken,                        ns + "postConditionExceptions")
      (EcPostConditionsToken,                                 ns + "postConditions")
      (EcPreConditionExceptionsToken,                         ns + "preConditionExceptions")
      (EcPreConditionsToken,                                  ns + "preConditions")
      (EcProgressToken,                                       ns + "progress")
      (EcRhsConditionContainerToken,                          ns + "rhsConditionContainer")
      (EcRoleActiveDirectionMapToken,                         ns + "roleActiveDirectionMap")
      (EcRoleCuesMapToken,                                    ns + "roleCuesMap")
      (EcRoleDirectionsMapToken,                              ns + "roleDirectionsMap")
      (EcRoleDirectionStatesMapToken,                         ns + "roleDirectionStatesMap")
      (EcRoleObjectRoleMapToken,                              ns + "roleObjectRoleMap")
      (EcRoleWaitingStateMapToken,                            ns + "roleWaitingStateMap")
      (EcScenesToken,                                         ns + "scenes")
      (EcSceneStatesToken,                                    ns + "sceneStates")
      (EcScriptToken,                                         ns + "script")
      (EcScriptStateToken,                                    ns + "scriptState")
      (EcSetAttachmentDirectionToken,                         ns + "setAttachmentDirection")
      (EcSubdirectoryMapToken,                                ns + "subdirectoryMap")
      (EcTagToken,                                            ns + "tag")
      (EcWrappedConditionContainerToken,                      ns + "wrappedConditionContainer")
      (EcXorDirectionConditionToken,                          ns + "xorDirectionCondition")

      // Enumerations ... don't need namespace
      (EcDirectionFailureToken,                               "directionFailure")
      (EcExcludeCommandToken,                                 "excludeCommand")
      (EcFollowingCueToken,                                   "followingCue")
      (EcIncludeCommandToken,                                 "includeCommand")
      (EcNoFailureToken,                                      "noFailure")
      (EcPersistentConditionFailureToken,                     "persistentConditionFailure")
      (EcPostConditionFailureToken,                           "postConditionFailure")
      (EcPreConditionFailureToken,                            "preConditionFailure")
      (EcSimultaneousCueToken,                                "simultaneousCue")
   )
}

#endif // ecManipulationDirectorTokens_H_
