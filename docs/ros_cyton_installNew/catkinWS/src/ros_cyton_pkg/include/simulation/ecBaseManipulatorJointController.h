#ifndef ecBaseManipulatorJointController_H_
#define ecBaseManipulatorJointController_H_
//------------------------------------------------------------------------------
// Copyright (c) 2006-2013 Energid Technologies. All rights reserved.
//
/// @file ecBaseManipulatorJointController.h
/// @class EcBaseManipulatorJointController
/// @brief Holds a base class for feedback controllers for an
///        entire manipulator.
//
//------------------------------------------------------------------------------
#include <actin/actin_config.h>  // Required to be first header.
#include <foundCore/ecTypes.h>
#include <xml/ecXmlEnumType.h>
#include <xml/ecXmlBasicType.h>
#include <xml/ecBaseExpTreeElement.h>

// forward declarations
class EcIndividualManipulator;
class EcManipulatorControlInput;
class EcManipulatorTorque;
class EcStatedSystem;
class EcPositionState;
class EcVelocityState;

/** Holds a base class for feedback controllers for an entire manipulator.
*/
class EC_ACTIN_SIMULATION_DECL EcBaseManipulatorJointController : public EcBaseExpressionTreeElement
{
public:
   /// default constructor
   EcBaseManipulatorJointController
      (
      );

   /// destructor
   virtual ~EcBaseManipulatorJointController
      (
      );

   /// copy constructor
   EcBaseManipulatorJointController
      (
      const EcBaseManipulatorJointController& orig
      );

   /// assignment operator
   EcBaseManipulatorJointController& operator=
      (
      const EcBaseManipulatorJointController& orig
      );

   /// equality operator
   EcBoolean operator==
      (
      const EcBaseManipulatorJointController& orig
      ) const;

   /// initialize XML components for reading and writing
   virtual EcBoolean xmlInit
      (
      );

   /// clone - a virtual constructor to an EcXmlObject pointer
   virtual EcXmlObject* clone
      (
      ) const=0;

   /// register components with the parent
   virtual void registerComponents
      (
      );

   /// gets the xml token used for writing out
   virtual const EcToken& token
      (
      ) const =0;

   /// equality - virtual equality to an EcXmlObject pointer
   virtual EcBoolean equality
      (
      const EcXmlObject* other
      ) const=0;

   /// virtual new that returns an EcXmlObject
   virtual EcXmlObject* newObject
      (
      ) const=0;

   /// gets on/off flag
   virtual EcBoolean isOn
      (
      ) const;

   /// sets the on/off flag
   virtual void setIsOn
      (
      EcBoolean isOn
      );

   /// set which control torques/inputs are specified and should NOT be computed in calculateControlTorques or calculateControlInputs methods. This should be called before calling those two calculate methods.
   /**
   For example, in a 3-dof robot, one may want to fix a control torque of joint 0 at 1.5 Nm and compute the control torques for the other two joints. Then, one would setControlTorqueFlags with:
   EcBooleanVector flags[3];
   flags[0] = EcTrue;
   flags[1] = EcFalse;
   flags[2] = EcFalse;

   If setSpecifyControlTorqueFlags is not called, then it's assumed that all control torques should be computed. In addition, if the size of flags is smaller than the size of control torques for a given manipulator, then the control torques for those extra joints will be computed.
   For example, if the robot has 5 joints and the flags given above are set, then control torques for joint 3 & 4 (the last two joints) would be computed.
   \return true. If the control class derived from this doesn't support the hybrid control (i.e. some control torques are directly specified while some are computed), then it should override this method and return false.
   */
   virtual EcBoolean setSpecifyControlTorqueFlags
      (
      const EcBooleanVector& flags
      );

   /// calculate control torques
   virtual void calculateControlTorques
      (
         const EcPositionState& actualPositionState,
         const EcVelocityState& actualVelocityState,
         const EcPositionState& desiredPositionState,
         const EcVelocityState& desiredVelocityState,
         const EcIndividualManipulator& manipulator,
         const EcStatedSystem& statedSystem,
         EcManipulatorTorque& manipulatorTorque
      ) const=0;

   /// calculate control inputs
   virtual void calculateControlInputs
      (
         const EcPositionState& actualPositionState,
         const EcVelocityState& actualVelocityState,
         const EcPositionState& desiredPositionState,
         const EcVelocityState& desiredVelocityState,
         const EcIndividualManipulator& manipulator,
         const EcStatedSystem& statedSystem,
         EcManipulatorControlInput& manipulatorControlInput
      ) const=0;

   /// read this object from an XML stream
   virtual EcBoolean read
      (
      EcXmlReader& stream
      );

   /// write this object to an XML stream
   virtual EcBoolean write
      (
      EcXmlWriter& stream
      ) const;

protected:
   /// on/off flag
   EcXmlBoolean               m_IsOn;

   /// non-XML
   EcBooleanVector            m_SpecifyControlTorqueFlags;  ///< flags indicating which control torques are specified
   EcU32                      m_NumExternalTorques;         ///< number of joints that use external torques
};

#endif // ecBaseManipulatorJointController_H_
