#ifndef ecMatrixDTool_H_
#define ecMatrixDTool_H_
//------------------------------------------------------------------------------
// Copyright (c) 2003-2013 Energid Technologies. All rights reserved.
//
/// @file ecMatrixDTool.h
/// @class EcMatrixDTool
/// @brief Provides a tool for calculating matrix D, which is
///        the matrix such that D Ab gives the joint torques and D^T q-dot
///        gives momentum.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecManipActiveState.h"

// forward declarations
class EcIndividualManipulator;
class EcManipulatorLink;
class EcPositionState;
class EcStatedSystemStruct;

/** Provides a tool for calculating matrix D, which is the matrix such
 that D Ab gives the joint torques and D^T q-dot gives momentum.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcMatrixDTool
{
public:
   /// default constructor
   EcMatrixDTool
      (
      );

   /// destructor
   virtual ~EcMatrixDTool
      (
      );

   /// copy constructor
   EcMatrixDTool
      (
      const EcMatrixDTool& orig
      );

   /// assignment operator
   EcMatrixDTool& operator=
      (
      const EcMatrixDTool& orig
      );

   /// get manipulator
   virtual const EcIndividualManipulator* manipulator
      (
      ) const;

   /// set manipulator
   virtual void setManipulator
      (
      const EcIndividualManipulator* manipulator
      );

   /// set the position state.  This is only used if no external active
   /// state is provided
   virtual void setPositionState
      (
      const EcPositionState& positionState
      );

   /// calculate the matrix D, using (and setting) the
   /// active position state that is provided.  If the pointer is
   /// null, an internal active state is used.
   /**
    * @param activeState The manipulator active state
    * @param systemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    */
   virtual const EcReArray& matrixD
      (
      EcManipulatorActiveState*  activeState=0,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// calculate the matrix D, using (and setting) the
   /// active position state that is provided.
   /**
    * @param activeState The manipulator active state
    * @param systemStruct The stated system struct for use when there are other manipulators
    *          attached to this link. If so, the mass properties of the attached manipulators will
    *          be included in the calculation. If this parameter is null or there's not attached manipulator,
    *          then only this link's mass properties are used.
    */
   virtual const EcReArray& matrixD
      (
      EcManipulatorActiveState&  activeState,
      const EcStatedSystemStruct* systemStruct=0
      );

   /// transform matrix D by a rotation.  This takes a matrix D
   /// represented in the outboard frame of the rotation and expresses
   /// it in the inboard frame.
   virtual void transformMatrixD
      (
      const EcReArray& matrixDFrom,
      const EcOrientation& orientation,
      EcReArray& matrixDTo
      ) const;

   /// get a null object
   static EcMatrixDTool nullObject
      (
      );

protected:

   /// resize member variables
   virtual void resize
      (
      );

protected:
   /// a pointer to the manipulator
   const EcIndividualManipulator*    m_pManipulator;

   /// an active state used when none is provided
   EcManipulatorActiveState          m_ActiveState;

   /// the matrix D
   EcReArray                         m_MatrixD;
};

#endif // ecMatrixDTool_H_
