#ifndef ecLatchedDoorLinks_H_
#define ecLatchedDoorLinks_H_
//------------------------------------------------------------------------------
// Copyright (c) 2007-2013 Energid Technologies. All rights reserved.
//
/// @file ecLatchedDoorLinks.h
/// @class EcLatchedDoorLinks
/// @brief Describes behavior of two links that form a latched door.
//
//------------------------------------------------------------------------------
#include <foundation/foundation_config.h>  // Required to be first header.
#include "ecBaseLinkInteractions.h"
#include "ecManipExternalForce.h"

#include <xml/ecXmlEnumType.h>

/**
\class EcLatchedDoorLinks
\brief Describes behavior of two links that form a latched door.

This class is used to calculate an appropriate amount of force that mimics the latching mechanism for a latched door. A latched door consists of two links - the door and the handle. This class uses the angle from the handle to compute the force that would keep the door closed using spring-damper. When the angle of the handle goes past a trigger angle, the door will be free to open. After the door is open (unlatched), the force will remain zero even if the angle of the handle returns back.
*/
class EC_FOUNDATION_MANIPULATOR_DECL EcLatchedDoorLinks : public EcBaseLinkInteractions
{
public:
   /// latch type enumeration
   enum {
      CLOSED_WITH_TURN,    ///< The door can only be closed with turning of the handle
      CLOSED_WITHOUT_TURN  ///< The door can only be closed without turning of the handle
   };

   /// register latch type enumeration
   virtual void registerLatchTypeEnumerations
      (
      );

   /// constructor
   EcLatchedDoorLinks
      (
      );

   /// destructor
   virtual ~EcLatchedDoorLinks
      (
      );

   /// copy constructor
   EcLatchedDoorLinks
      (
      const EcLatchedDoorLinks& orig
      );

   /// assignment operator
   EcLatchedDoorLinks& operator=
      (
      const EcLatchedDoorLinks& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcLatchedDoorLinks& orig
      ) const;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const;

   /// XML-initializes the class by registering the components
   virtual EcBoolean xmlInit
      (
      );

   /// A virtual constructor that returns an EcXmlObject.
   virtual EcXmlObject* clone
      (
      ) const;

   /// registers all the components for this class that are
   /// read and written to XML files.
   virtual void registerComponents
      (
      );

   /// Reads class data from an XML stream.
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// Writes class data to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

   /// get a null object
   static EcLatchedDoorLinks nullObject
      (
      );

   /// get the latch type
   virtual EcU32 latchType
      (
      ) const;

   /// set the latch type
   virtual void setLatchType
      (
      EcU32 value
      );

   /// get the spring constant that keeps the door close
   virtual EcReal springConstant
      (
      )const;

   /// set the spring constant that keeps the door close
   virtual void setSpringConstant
      (
      EcReal value
      );

   /// get the damper constant that keeps the door close
   virtual EcReal damperConstant
      (
      ) const;

   /// set the damper constant that keeps the door close
   virtual void setDamperConstant
      (
      EcReal value
      );

   /// get the manipulator index
   virtual EcU32  manipulatorIndex
      (
      ) const;

   /// set the manipulator index
   virtual void setManipulatorIndex
      (
      EcU32 manipulatorIndex
      );

   /// get the link index for the door link
   virtual EcU32  doorLinkIndex
      (
      ) const;

   /// set the link index for the door link
   virtual void setDoorLinkIndex
      (
      EcU32  linkIndex
      );

   /// get the link index for the door handle link
   virtual EcU32  handleLinkIndex
      (
      ) const;

   /// set the link index for the door handle link
   virtual void setHandleLinkIndex
      (
      EcU32  linkIndex
      );

   /// get the lower bound of the angle of the door handle that unlatches the door
   virtual EcReal unlatchingAngleLowerBound
      (
      ) const;

   /// set the lower bound of the angle of the door handle that unlatches the door
   virtual void setUnlatchingAngleLowerBound
      (
      EcReal value
      );

   /// get the upper bound of the angle of the door handle that unlatches the door
   virtual EcReal unlatchingAngleUpperBound
      (
      ) const;

   /// set the upper bound of the angle of the door handle that unlatches the door
   virtual void setUnlatchingAngleUpperBound
      (
      EcReal value
      );

   /// get the lower bound of the angle of the door that indicates that the door is closed
   virtual EcReal closedDoorAngleLowerBound
      (
      ) const;

   /// set the lower bound of the angle of the door that indicates that the door is closed
   virtual void setClosedDoorAngleLowerBound
      (
      EcReal value
      );

   /// get the upper bound of the angle of the door that indicates that the door is closed
   virtual EcReal closedDoorAngleUpperBound
      (
      ) const;

   /// set the upper bound of the angle of the door that indicates that the door is closed
   virtual void setClosedDoorAngleUpperBound
      (
      EcReal value
      );

   /// Calculate the general force that keeps the door from opening/closing and ADD the result to manipExtForceVec.
   /// @copydoc EcBaseLinkInteractions::forceBetweenLinks()
   virtual void forceBetweenLinks
      (
      EcSystemActiveState&              actState,
      const EcManipulatorSystem&        manipSystem,
      const EcReal&                     time,
      const EcManipulatorTorqueVector&  torqueVec,
      EcManipulatorExternalForceVector& manipExtForceVec
      ) const;

   /// a virtual function returning the token for this class
   virtual const EcToken& token
      (
      ) const;

   /// a static function returning the token for this class
   static const EcToken& classToken
      (
      );

   /// a creator function for this class
   static EcXmlObject* creator
      (
      );

protected:
   /// the latch type
   EcXmlEnumU32   m_LatchType;

   /// Spring constant
   EcXmlReal      m_SpringConstant;

   /// Damper Constant
   EcXmlReal      m_DamperConstant;

   /// Manipulator Index
   EcXmlU32       m_ManipulatorIndex;

   /// Link Index for door link
   EcXmlU32       m_DoorLinkIndex;

   /// Link Index for door handle link
   EcXmlU32       m_HandleLinkIndex;

   /// The lower bound of the angle of the door handle that unlatches the door
   EcXmlReal      m_UnlatchingAngleLowerBound;

   /// The upper bound of the angle of the door handle that unlatches the door
   EcXmlReal      m_UnlatchingAngleUpperBound;

   /// The lower bound of the angle of the door that indicates that the door is closed
   EcXmlReal      m_ClosedDoorAngleLowerBound;

   /// The upper bound of the angle of the door that indicates that the door is closed
   EcXmlReal      m_ClosedDoorAngleUpperBound;

   // non-XML
   /// a flag indicating whether or not this object has been initialized
   mutable EcBoolean      m_Init;

   /// a flag indicating whether or not the door is open
   mutable EcBoolean      m_Open;

   /// the middle of the range of angles of the door that indicates that the door is closed.
   mutable EcReal         m_ClosedDoorAngleMiddle;

protected:
   /// initialize with a door angle
   void init
      (
      EcReal doorAngle
      ) const;
};

/// describes a vector of reals
typedef EcXmlVectorType<EcLatchedDoorLinks>
   EcLatchedDoorLinksVector;

#endif // ecLatchedDoorLinks_H_
