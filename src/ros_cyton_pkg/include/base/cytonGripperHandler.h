#ifndef cyton_GripperHandler_H_
#define cyton_GripperHandler_H_
//     Copyright (c) 2011 Energid Technologies. All rights reserved. ////
//
// Filename:    cytonGripperHandler.h
//
// Description: Cyton-specific control for gripper.  Currently supports
//              upto 2 grippers.
//
/////////////////////////////////////////////////////////////////////////
#include <foundCore/ecTypes.h>

#include <QtCore/QObject>

namespace cyton
{

class BaseIO;

class GripperHandler : public QObject
{
   Q_OBJECT

public:
   GripperHandler
      (
      QObject* parent,
      BaseIO* plugin
      );

   /// Retrieve gripper value
   EcReal getGripperValue
      (
      const EcU32 index = 0
      );

   /// Aligns gripper values to simulation.
   void syncToSimulation
      (
      );
  
public Q_SLOTS:
   void gripper1Open() { moveGripper(0, -1); } ///< Keymap slot to open gripper 1
   void gripper1Close(){ moveGripper(0,  1); } ///< Keymap slot to close gripper 1
   void gripper2Open() { moveGripper(1, -1); } ///< Keymap slot to open gripper 2
   void gripper2Close(){ moveGripper(1,  1); } ///< Keymap slot to close gripper 2

protected:
   EcBoolean moveGripper
      (
      const EcU32 index,
      const EcInt32 direction
      );

   struct GripperStruct
   {
      EcU32  linkIndex; ///< Link index tied to gripper
      EcU32  eeIndex;   ///< EE index tied to gripper
      EcReal value;     ///< Current gripper value
      EcReal minValue;  ///< Minimum gripper value
      EcReal maxValue;  ///< Maximum gripper value
      EcReal increment; ///< Step size for gripper movement
   };
   typedef std::vector<GripperStruct> GripperVector;

   GripperVector m_vGrippers; ///< Currently configured grippers
   BaseIO* m_pPlugin;         ///< Owning plugin for API support
};

} // namespace cyton

#endif // cyton_GripperHandler_H_
