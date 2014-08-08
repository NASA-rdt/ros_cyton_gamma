#ifndef ecCytonCommands_H_
#define ecCytonCommands_H_
//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecCytonCommands.h
/// @class EcNetworkCommunicationTester
/// @brief Holds the quick-start code described in the Users Guide.
//
//------------------------------------------------------------------------------
#include <foundCore/ecTypes.h>
#include <foundCommon/ecCoordSysXForm.h>
#include <vector>
using namespace std;

/// This class uses the remote commands API to communicate with the 
//  ActinViewer/CytonViewer or ActinRT with the remoteCommandServerPlugin loaded.
class EcCytonCommands
{
public:

	/// constructor
	EcCytonCommands
	(
	);

	/// destructor
	virtual ~EcCytonCommands
	(
	);

	/// copy constructor
	EcCytonCommands
	(
			const EcCytonCommands& orig
	);

	/// overloading = operator
	const EcCytonCommands& operator=
			(
					const EcCytonCommands& orig
			)const;

	/// overloading == operator
	EcBoolean operator==
			(
					const EcCytonCommands& orig
			)const;

	/// initialize the network
	/// @param[in] ipAddress          (EcString&) address of the network to be connected to.
	/// @return                       (EcBoolean) which returns the status of command
	virtual EcBoolean openNetwork
	(
			const EcString& ipAddress
	)const;

	/// shut down the network
	/// @return    flag (EcBoolean) which returns the status of command
	virtual EcBoolean closeNetwork
	(
	)const;

	/// test joint values communication over the network
	/// @return    flag  (EcBoolean) which returns the status of command
	virtual EcBoolean MoveJointsExample
	(
			const EcRealVector jointPosition,
			const EcReal angletolerance
	)const;

	// returns a vector of the current joint positions
	virtual EcRealVector GetJointsExample
	(
	)const;

	// returns a vector of the current pose of the end effector
	virtual EcRealVector GetPoseExample
	(
	)const;


	/// set the control descriptor for the simulation file on the server
	/// @param[in] endEffectorSetId  (EcU32) of the end effector set
	/// @return    flag              (EcBoolean) which returns the status of command
	virtual EcBoolean moveGripperExample
	(
			const EcReal gripperPos
	)const;

	// Test executing manipulation actions
	// @param[in] filename (EcString&) manipulation action manager filename
	// @param[in] actionName (EcString&) manipulation action name
	// @param[in] timeInMS (EcString&) manipulation action time
	// @return    flag     (EcBoolean) which returns the status of command
	virtual EcBoolean manipulationActionTest
	(
			const EcString& filename,
			const EcString& actionName,
			const EcU32& timeInMS
	)const;

	/// move the robot using point EE set (only constrains position (x,y,z))
	/// @return         (EcBoolean) flag which returns the status of command
	virtual EcBoolean pointMovementExample
	(
			const EcCoordinateSystemTransformation& pose
	)const;

	/// move the robot using frame EE set (constrains x,y,z, and roll, pitch, yaw)
	/// @return         (EcBoolean) flag which returns the status of command
	virtual EcBoolean frameMovementExample
	(
			const EcCoordinateSystemTransformation& pose
	)const;

	///sample sequence of remote command actions to pick up and place an object
	// @param[in] cytonModel (EcString&) cyton version (300, 300PX, 1500, 1500R2)
	/// @return         (EcBoolean) flag which returns the status of command
	virtual EcBoolean pickAndPlaceExample
	(
			const EcString& cytonModel
	)const;
	///sample sequence of remote command actions to pick up and place an object
	// @param[in] cytonModel (EcString&) cyton version (300, 300PX, 1500, 1500R2)
	/// @return         (EcBoolean) flag which returns the status of command
	virtual EcBoolean pickAndStackExample
	(
			const EcString& cytonModel,
			double pick,
			double stack
	)const;

	///sample sequence of remote command actions to pick up and place an object
	// @param[in] cytonModel (EcString&) cyton version (300, 300PX, 1500, 1500R2)
	/// @return         (EcBoolean) flag which returns the status of command
	virtual EcBoolean pickAndUnStackExample
	(
			const EcString& cytonModel,
			double pick,
			double stack
	)const;


	/// enable hardware test
	/// @param[in] flag     (EcBoolean) Whether to enable/disable hardware
	/// @return    flag     (EcBoolean)which returns the status of command
	virtual EcBoolean hardwareEnableTest
	(
			const EcBoolean flag
	)const;

	/// move the robot to home position(zero joint angles for all the joints)
	virtual EcBoolean resetToHome
	(
	)const;

	/// move the robot to home position(zero joint angles for all the joints)
	virtual EcBoolean MovementExample
	(
			vector<double> ee_pose,
			const int ee_set
	)const;

	/// snaps the savedPose to the current robot position
	virtual EcBoolean SnapExample
	(
	)const;

	/// move the end effector of the robot in relation to its current position
	virtual EcBoolean ModifyMovementExample
	(
			vector<double> ee_rate,
			const int ee_set
	)const;

	/// move the robot to the current saved position()
	virtual EcCoordinateSystemTransformation move
	(
	)const;

	/// initializes the settings
	virtual void initialize
	(   );

	/// returns the executing variable, can be set using next fucntion
	virtual EcBoolean getExecuting
	(
	)const;

	// set the executing variable
	virtual void setExecuting
	(
			EcBoolean exec
	)const;

	//an experimental function to move the elbow
	virtual EcBoolean pointElbowMovementExample
	(
			const int joint,
			const EcVector tran
	)const;

	// a function to return the saved pose of the robot
	EcRealVector GetDesiredPose
	(
	)const;


protected:

};

#endif //ecCytonCommands_H_
