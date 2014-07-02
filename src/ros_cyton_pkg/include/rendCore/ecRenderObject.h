#ifndef ecRenderObject_H_
#define ecRenderObject_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecRenderObject.h
//
//------------------------------------------------------------------------------
#include <render/render_config.h>  // Required to be first header.

#include <foundCommon/ecColor.h>
#include <foundCore/ecVector.h>

// Forward declarations.
class EcSGWindow;
struct ObjectStruct;

class EC_RENDER_RENDCORE_DECL EcRenderObject
{
public:
   /// Specify a specific type for identifier.
   typedef EcU32 ObjectIndex;

   /// Creates a spherical object in the window.
   /// \param[in] window      Rendering window to insert object.
   /// \param[in] position    Location to place sphere.
   /// \param[in] radius      Radius of sphere in meters.
   /// \param[in] color       Color of sphere.
   /// \param[in] duration    Number of frames before object is deleted.  0 means forever.
   /// \return    ObjectIndex Returns 0 on failure or a unique identifier on success.
   static ObjectIndex addGlobalSphere
      (
      EcSGWindow *window,
      const EcVector &position = EcVector(0.0,0.0,0.0),
      const EcReal radius = 1.0,
      const EcColor &color = EcColor(0.2,0.8,0.0,1.0),
      const EcU32 duration = 0
      );

   /// Given a valid index, updates the objects position in the window.
   /// \param[in] index     Valid ObjectIndex to modify.
   /// \param[in] position  New position to move to.
   /// \return    EcBoolean Success or failure of command.
   static EcBoolean updateObjectPosition
      (
      const ObjectIndex index,
      const EcVector &position
      );

   /// Given a valid index, removes the object from the window.
   /// \param[in] index     Valid ObjectIndex to remove.
   /// \return    EcBoolean Success or failure of command.
   static EcBoolean removeObject
      (
      const ObjectIndex index
      );

protected:
   typedef std::map<EcRenderObject::ObjectIndex, ObjectStruct>  ObjectMap;
   static ObjectIndex s_GlobalObjectIndex;
   static ObjectMap s_GlobalObjectMap;
};

#endif // ecRenderObject_H_
