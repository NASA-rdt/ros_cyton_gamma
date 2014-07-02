#ifndef ecSG3DInputData_H_
#define ecSG3DInputData_H_
//------------------------------------------------------------------------------
// Copyright (c) 2008-2013 Energid Technologies. All rights reserved.
//
/// @file ecSG3DInputData.h
/// @brief Create a class to hold 3D input information to be used
///        within an OSG event handler.  Class needs to be based
///        upon osg::Referenced to handle cleanup.
//
//------------------------------------------------------------------------------
#include <foundCommon/ecCoordSysXForm.h>
#include <rendCore/ecRenderTypes.h>
#include <osg/Referenced>

class EcSG3DInputData : public osg::Referenced
{
public:
   EcSG3DInputData
      (
      const EcCoordinateSystemTransformation cst
      ):
   osg::Referenced(),
   m_CoordinateSystemTransformation(cst),
   m_ButtonState(0)
   {
   }

   EcSG3DInputData
      (
      const EcCoordinateSystemTransformation cst,
      const EcU32 buttonState
      ):
   osg::Referenced(),
   m_CoordinateSystemTransformation(cst),
   m_ButtonState(buttonState)
   {
   }

   const EcCoordinateSystemTransformation &coordinateSystemTransformation
      (
      ) const
   {
      return m_CoordinateSystemTransformation;
   }

   const EcU32 &buttonState
      (
      ) const
   {
      return m_ButtonState;
   }

protected:
   virtual ~EcSG3DInputData
      (
      ) {}

   EcCoordinateSystemTransformation m_CoordinateSystemTransformation;
   EcU32 m_ButtonState;
};

#endif // ecSG3DInputData_H_
