#ifndef ecRelativeManipulationOffset_H_
#define ecRelativeManipulationOffset_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecRelativeManipulationOffset.h
/// @class EcRelativeManipulationOffset
/// @brief This class is an abstract interface for relative manipulation offsets.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include "ecManipulationOffset.h"

#include <foundCommon/ecCoordSysXForm.h>
#include <foundCommon/ecEndEffectorPlacement.h>

/// This class is an abstract interface for relative manipulation offsets.
class EC_ACTIN_MANIPULATION_DECL EcRelativeManipulationOffset : public EcManipulationOffset
{
public:
   enum
   {
      UNDEFINED_FRAME,
      SYSTEM_FRAME,
      OBJECT_FRAME
   };

   /// default constructor
   EcRelativeManipulationOffset
      (
      );

   /// destructor
   virtual ~EcRelativeManipulationOffset
      (
      );

   /// copy constructor
   EcRelativeManipulationOffset
      (
      const EcRelativeManipulationOffset& orig
      );

   /// assignment operator
   EcRelativeManipulationOffset& operator=
      (
      const EcRelativeManipulationOffset& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcRelativeManipulationOffset& orig
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

   /// use the object frame as the manipulation frame
   virtual void setObjectFrameAsManipulationFrame
      (
      );

   /// test whether the object frame is being used as the manipulation frame
   virtual EcBoolean objectFrameAsManipulationFrame
      (
      ) const;

   /// use the system frame as the manipulation frame
   virtual void setSystemFrameAsManipulationFrame
      (
      );

   /// test whether the system frame is being used as the manipulation frame
   virtual EcBoolean systemFrameAsManipulationFrame
      (
      ) const;

   /// get the x axis of the manipulation frame for the specified offset
   virtual const EcXmlVector& manipulationFrameXAxisVector
      (
      ) const;

   /// set the x axis of the manipulation frame for the specified offset
   virtual void setManipulationFrameXAxisVector
      (
      const EcXmlVector& axis
      );

   /// get the x axis source frame of the manipulation frame for the specified offset
   virtual EcU32 manipulationFrameXAxisSourceFrame
      (
      ) const;

   /// set the x axis source frame of the manipulation frame for the specified offset
   virtual void setManipulationFrameXAxisSourceFrame
      (
      EcU32 sourceFrame
      );

   /// set the x axis of the manipulation frame for the specified offset
   virtual void setManipulationFrameXAxis
      (
      const EcXmlVector& axisVector,
      EcU32 sourceFrame
      );

   /// get the y axis of the manipulation frame for the specified offset
   virtual const EcXmlVector& manipulationFrameYAxisVector
      (
      ) const;

   /// set the y axis of the manipulation frame for the specified offset
   virtual void setManipulationFrameYAxisVector
      (
      const EcXmlVector& axis
      );

   /// get the y axis source frame of the manipulation frame for the specified offset
   virtual EcU32 manipulationFrameYAxisSourceFrame
      (
      ) const;

   /// set the y axis source frame of the manipulation frame for the specified offset
   virtual void setManipulationFrameYAxisSourceFrame
      (
      EcU32 sourceFrame
      );

   /// set the y axis of the manipulation frame for the specified offset
   virtual void setManipulationFrameYAxis
      (
      const EcXmlVector& axisVector,
      EcU32 sourceFrame
      );

   /// get the z axis of the manipulation frame for the specified offset
   virtual const EcXmlVector& manipulationFrameZAxisVector
      (
      ) const;

   /// set the z axis of the manipulation frame for the specified offset
   virtual void setManipulationFrameZAxisVector
      (
      const EcXmlVector& axis
      );

   /// get the z axis source frame of the manipulation frame for the specified offset
   virtual EcU32 manipulationFrameZAxisSourceFrame
      (
      ) const;

   /// set the z axis source frame of the manipulation frame for the specified offset
   virtual void setManipulationFrameZAxisSourceFrame
      (
      EcU32 sourceFrame
      );

   /// set the z axis of the manipulation frame for the specified offset
   virtual void setManipulationFrameZAxis
      (
      const EcXmlVector& axisVector,
      EcU32 sourceFrame
      );

   /// register XML member variables
   virtual void registerComponents
      (
      );

   /// get a flag indicating of the manipulation frame is valid
   virtual EcString validManipulationFrame
      (
      ) const;

   /// get the current offset transformation
   virtual const EcEndEffectorPlacement& currentOffsetTransformation
      (
      const EcManipulationOffsetState& ostate
      ) const;

   /// get the goal offset transformation
   virtual const EcEndEffectorPlacement& goalOffsetTransformation
      (
      const EcManipulationOffsetState& ostate
      ) const;

protected:
   /// calculate manipulation frame
   virtual EcCoordinateSystemTransformation calculateManipulationFrame
      (
      const EcCoordinateSystemTransformation& frame
      ) const;

   /// the relative offset
   EcCoordinateSystemTransformation m_RelativeOffset;

   /// the x axis of the manipulation frame for the specified offset
   EcXmlVector                      m_XAxisVector;

   /// the x axis source frame of the manipulation frame for the specified offset
   EcXmlEnumU32                     m_XAxisSourceFrame;

   /// the y axis of the manipulation frame for the specified offset
   EcXmlVector                      m_YAxisVector;

   /// the y axis source frame of the manipulation frame for the specified offset
   EcXmlEnumU32                     m_YAxisSourceFrame;

   /// the z axis of the manipulation frame for the specified offset
   EcXmlVector                      m_ZAxisVector;

   /// the z axis source frame of the manipulation frame for the specified offset
   EcXmlEnumU32                     m_ZAxisSourceFrame;
};

#endif // ecRelativeManipulationOffset_H_
