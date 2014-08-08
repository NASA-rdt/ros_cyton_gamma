#ifndef ecRelativeGraspOffset_H_
#define ecRelativeGraspOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecRelativeGraspOffset.h
/// @class EcRelativeGraspOffset
/// @brief This class is an abstract interface for relative grasp offsets.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecGraspOffset.h"

#include <foundCommon/ecCoordSysXForm.h>
#include <foundCommon/ecEndEffectorPlacement.h>

/// This class is an abstract interface for relative grasp offsets.
class EC_ACTIN_GRASPING_DECL EcRelativeGraspOffset : public EcGraspOffset
{
public:
   enum
   {
      UNDEFINED_FRAME,
      SYSTEM_FRAME,
      OBJECT_FRAME
   };

   /// default constructor
   EcRelativeGraspOffset
      (
      );

   /// destructor
   virtual ~EcRelativeGraspOffset
      (
      );

   /// copy constructor
   EcRelativeGraspOffset
      (
      const EcRelativeGraspOffset& orig
      );

   /// assignment operator
   EcRelativeGraspOffset& operator=
      (
      const EcRelativeGraspOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcRelativeGraspOffset& orig
      ) const;

   /// get the relative offset
   virtual const EcCoordinateSystemTransformation& relativeOffset
      (
      ) const;

   /// set the relative offset
   virtual void setRelativeOffset
      (
      const EcCoordinateSystemTransformation& relativeOffset
      );

   /// use the object frame as the grasping frame
   virtual void setObjectFrameAsGraspingFrame
      (
      );

   /// test whether the object frame is being used as the grasping frame
   virtual EcBoolean objectFrameAsGraspingFrame
      (
      ) const;

   /// use the system frame as the grasping frame
   virtual void setSystemFrameAsGraspingFrame
      (
      );

   /// test whether the system frame is being used as the grasping frame
   virtual EcBoolean systemFrameAsGraspingFrame
      (
      ) const;

   /// get the x axis of the grasping frame for the specified offset
   virtual const EcXmlVector& graspingFrameXAxisVector
      (
      ) const;

   /// set the x axis of the grasping frame for the specified offset
   virtual void setGraspingFrameXAxisVector
      (
      const EcXmlVector& axis
      );

   /// get the x axis source frame of the grasping frame for the specified offset
   virtual EcU32 graspingFrameXAxisSourceFrame
      (
      ) const;

   /// set the x axis source frame of the grasping frame for the specified offset
   virtual void setGraspingFrameXAxisSourceFrame
      (
      EcU32 sourceFrame
      );

   /// set the x axis of the grasping frame for the specified offset
   virtual void setGraspingFrameXAxis
      (
      const EcXmlVector& axisVector,
      EcU32 sourceFrame
      );

   /// get the y axis of the grasping frame for the specified offset
   virtual const EcXmlVector& graspingFrameYAxisVector
      (
      ) const;

   /// set the y axis of the grasping frame for the specified offset
   virtual void setGraspingFrameYAxisVector
      (
      const EcXmlVector& axis
      );

   /// get the y axis source frame of the grasping frame for the specified offset
   virtual EcU32 graspingFrameYAxisSourceFrame
      (
      ) const;

   /// set the y axis source frame of the grasping frame for the specified offset
   virtual void setGraspingFrameYAxisSourceFrame
      (
      EcU32 sourceFrame
      );

   /// set the y axis of the grasping frame for the specified offset
   virtual void setGraspingFrameYAxis
      (
      const EcXmlVector& axisVector,
      EcU32 sourceFrame
      );

   /// get the z axis of the grasping frame for the specified offset
   virtual const EcXmlVector& graspingFrameZAxisVector
      (
      ) const;

   /// set the z axis of the grasping frame for the specified offset
   virtual void setGraspingFrameZAxisVector
      (
      const EcXmlVector& axis
      );

   /// get the z axis source frame of the grasping frame for the specified offset
   virtual EcU32 graspingFrameZAxisSourceFrame
      (
      ) const;

   /// set the z axis source frame of the grasping frame for the specified offset
   virtual void setGraspingFrameZAxisSourceFrame
      (
      EcU32 sourceFrame
      );

   /// set the z axis of the grasping frame for the specified offset
   virtual void setGraspingFrameZAxis
      (
      const EcXmlVector& axisVector,
      EcU32 sourceFrame
      );

   /// register XML member variables
   virtual void registerComponents
      (
      );

   /// get a flag indicating of the grasping frame is valid
   virtual EcString validGraspingFrame
      (
      ) const;

   /// get the current offset transformation
   virtual const EcEndEffectorPlacement& currentOffsetTransformation
      (
      const EcGraspOffsetState& ostate
      ) const;

   /// get the goal offset transformation
   virtual const EcEndEffectorPlacement& goalOffsetTransformation
      (
      const EcGraspOffsetState& ostate
      ) const;

protected:

   /// calculates the frame based on an input frame whose position is
   /// used for the output.
   virtual EcCoordinateSystemTransformation calculateGraspingFrame
      (
      const EcCoordinateSystemTransformation& frame
      ) const;

   /// the relative offset
   EcCoordinateSystemTransformation m_RelativeOffset;

   /// the x axis of the grasping frame for the specified offset
   EcXmlVector                      m_XAxisVector;

   /// the x axis source frame of the grasping frame for the specified offset
   EcXmlEnumU32                     m_XAxisSourceFrame;

   /// the y axis of the grasping frame for the specified offset
   EcXmlVector                      m_YAxisVector;

   /// the y axis source frame of the grasping frame for the specified offset
   EcXmlEnumU32                     m_YAxisSourceFrame;

   /// the z axis of the grasping frame for the specified offset
   EcXmlVector                      m_ZAxisVector;

   /// the z axis source frame of the grasping frame for the specified offset
   EcXmlEnumU32                     m_ZAxisSourceFrame;
};

#endif // ecRelativeGraspOffset_H_
