//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ecCytonCommands.cpp
//
//------------------------------------------------------------------------------
#include "ecCytonCommands.h"
#include <control/ecEndEffectorSet.h>
#include <control/ecFrameEndEffector.h>
#include <control/ecManipEndEffectorPlace.h>
#include <foundCore/ecApplication.h>
#include <foundCore/ecMacros.h>
#include <manipulation/ecManipulationActionManager.h>
#include <math.h>
#include <remoteCommand/ecRemoteCommand.h>
#include <xml/ecXmlObjectReaderWriter.h>
#include <iostream>

#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>

#define POINT_EE_SET 0
#define FRAME_EE_SET 1
#define JOINT_CONTROL_EE_SET 0xFFFFFFFF


const double GRIPPER_MIN = 0.0015;
const double GRIPPER_MAX = 0.015;

boost::mutex poseLock, executeLock;
EcCoordinateSystemTransformation myPose;
EcReal myGripper;


//------------------------------------------------------------------------------
// Callback function.  Sets a local variable with completion status.
static EcBoolean g_ManipulationComplete = EcFalse;
void manipCallback(EcBoolean status, void* data)
{
	std::cout << "Received sequence completed status of " << (status ? "SUCCESS" : "FAILURE") << std::endl;
	g_ManipulationComplete = EcTrue;
}

using namespace Ec;
//----------------------------------constructor--------------------------------
EcCytonCommands::EcCytonCommands
(
)
{

}
void EcCytonCommands::initialize(){

	EcManipulatorEndEffectorPlacement actualEEPlacement;
	getActualPlacement(actualEEPlacement);
	myPose = actualEEPlacement.offsetTransformations()[0].coordSysXForm();
	myGripper = 0.015;
	setExecuting(EcTrue);
}
//----------------------------------destructor---------------------------------
EcCytonCommands::~EcCytonCommands
(
)
{
}

//----------------------------------overloading = -----------------------------
EcBoolean EcCytonCommands::closeNetwork
(
)const
{
	shutdown();
	return EcTrue;
}

const EcCytonCommands& EcCytonCommands:: operator=
		(
				const EcCytonCommands& orig
		)const
{
	return *this;
}

//----------------------------------overloading == ----------------------------
EcBoolean EcCytonCommands:: operator==
		(
				const EcCytonCommands& orig
		)const
		{
	return EcTrue;
		}

//----------------------------------open network-------------------------------
EcBoolean EcCytonCommands::openNetwork
(
		const EcString& m_IpAddress
)const
{
	EcBoolean retVal = EcTrue;
	if(!init(m_IpAddress))
	{
		std::cerr << "Failed to init\n";
		return EcFalse;
	}
	retVal &= setManipulationCompletedCallback(manipCallback);
	return EcTrue;
}

//----------------------------------close network------------------------------
//----------------------------------joint get test------------------------
/*
EcRealVector EcCytonCommands::GetJointsExample
   ()const
{
   EcBoolean retVal=EcTrue;
   //setEndEffectorSet(JOINT_CONTROL_EE_SET);
   EcSLEEPMS(50);//500
   EcRealVector currentJoints;//vector of EcReals that holds the set of joint angles
   retVal &= getJointValues(currentJoints);

   size_t size = currentJoints.size();
   if(size < jointPosition.size())
   {
      size = currentJoints.size();
   }
   else if(size >= jointPosition.size())
   {
      size = jointPosition.size();
   }

   std::cout<<"Current Joint Angles: ( ";
   for(size_t ii=0; ii<size; ++ii)
   {
      std::cout << currentJoints[ii] << "," ;
      currentJoints[ii] = jointPosition[ii];
   }
   std::cout << " )" << std::endl;

   return currentJoints;
}
 */

//////
EcRealVector EcCytonCommands::GetJointsExample
(
)const
{
	EcBoolean retVal=EcTrue;
	//setEndEffectorSet(JOINT_CONTROL_EE_SET);
	EcSLEEPMS(500);
	EcRealVector currentJoints;//vector of EcReals that holds the set of joint angles
	retVal &= getJointValues(currentJoints);
	/*
   size_t size = currentJoints.size();

   std::cout<<"Current Joint Angles: ( ";
   for(size_t ii=0; ii<size; ++ii)
   {
      std::cout << currentJoints[ii] << "," ;
   }std::cout<<")"<<std::endl;
	 */
	return currentJoints;
}

EcRealVector EcCytonCommands::GetPoseExample
(
)const
{

	boost::mutex::scoped_lock lock(poseLock);
	EcManipulatorEndEffectorPlacement actualEEPlacement;
	getActualPlacement(actualEEPlacement);
	EcCoordinateSystemTransformation ecPose = actualEEPlacement.offsetTransformations()[0].coordSysXForm();
	EcVector translation = ecPose.translation();
	EcOrientation orientation = ecPose.orientation();
	EcRealVector pose;
	pose.resize(6);
	pose[0] = translation.x();
	pose[1] = translation.y();
	pose[2] = translation.z();

	orientation.get123Euler(pose[3],pose[4],pose[5]);
	//	pose[3] = orientation[0];
	//	pose[4] = orientation[1];
	//	pose[5] = orientation[2];

	return pose;

}

EcRealVector EcCytonCommands::GetDesiredPose
(
)const
{

	EcRealVector pose(6);

	boost::mutex::scoped_lock lock(poseLock);
	//EcManipulatorEndEffectorPlacement actualEEPlacement;
	//getActualPlacement(actualEEPlacement);
	//EcCoordinateSystemTransformation ecPose = actualEEPlacement.offsetTransformations()[0].coordSysXForm();
	EcVector translation = myPose.translation();
	EcOrientation orientation = myPose.orientation();
	pose[0] = translation.x();
	pose[1] = translation.y();
	pose[2] = translation.z();

	orientation.get123Euler(pose[3],pose[4],pose[5]);

	return pose;

}

//----------------------------------joint commands test------------------------
EcCoordinateSystemTransformation EcCytonCommands::move( )const{


	EcBoolean achieved = EcFalse;
	poseLock.lock();
	EcCoordinateSystemTransformation desiredPose = myPose;
	EcReal gripperPos = myGripper;
	/*if (myPose){
		std::cout<<"NULL POSE"<<std::endl;
		return false;
	}*/

	EcManipulatorEndEffectorPlacement actualEEPlacement,desiredEEPlacement;
	EcCoordinateSystemTransformation offset, zero, desiredCoord, actualCoord;
	zero.setTranslation(EcVector(0,0,0));

	EcEndEffectorPlacement desiredPlacement(desiredPose);
	getActualPlacement(actualEEPlacement);
	//EcEndEffectorPlacementVector state = actualEEPlacement.offsetTransformations();//commented out, not used
	//state[0]=desiredPlacement;//commented out, not used
	setDesiredPlacement(desiredPlacement,0,0);


	/*
/////////////////////////////////////////////////

	//setEndEffectorSet(FRAME_EE_SET); // frame end effector set index
	EcEndEffectorPlacement desiredPlacement(desiredPose);

		getActualPlacement(actualEEPlacement);
		EcEndEffectorPlacementVector state = actualEEPlacement.offsetTransformations();
		state[0]=desiredPlacement;

		desiredEEPlacement.setOffsetTransformations(state);
	   //set the trnaslation of the driving gripper finger
	   EcCoordinateSystemTransformation gripperfinger1trans = desiredEEPlacement.offsetTransformations()[1].coordSysXForm();
	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   //state[1].coordSysXForm();
	   gripperfinger1trans.setTranslation(EcVector(0,0,gripperPos));
	   EcEndEffectorPlacement finger1placement = state[1];
	   finger1placement.setCoordSysXForm(gripperfinger1trans);
	   //state[1]=finger1placement;



	   //desiredEEPlacement.setOffsetTransformations(state);
	setDesiredPlacement(desiredEEPlacement,0);
	 */

	poseLock.unlock();


	EcPrint(Debug) << "Moving "<<std::endl;
	//getActualPlacement(actualEEPlacement);
	actualCoord=actualEEPlacement.offsetTransformations()[0].coordSysXForm();
	getDesiredPlacement(desiredEEPlacement);
	desiredCoord=desiredEEPlacement.offsetTransformations()[0].coordSysXForm();


	//get the transformation between the actual and desired
	offset=(actualCoord.inverse()) * desiredCoord;
	return offset;/*
	//EcPrint(Debug)<<
	//std::cout<<"distance between actual and desired: "<<offset.translation().mag()<<std::endl;

	if(offset.approxEq(zero,.00001))
	{
	 EcPrint(Debug)<<"Achieved Pose"<<std::endl;
	 achieved = EcTrue;
	}
	else{
		//std::cout<<"Desired pose:  x: "<<desiredPose.translation().x()<< " y: " <<desiredPose.translation().y()<<" z: " <<desiredPose.translation().z()<<std::endl;
		//std::cout<<"distance between actual and desired: "<<offset.translation().mag()<<std::endl;
	}
	return achieved;*/
}

EcBoolean EcCytonCommands::ModifyMovementExample( vector<double> ee_rate , int ee_set)const{

	EcBoolean retVal=EcTrue;
	EcCoordinateSystemTransformation desiredPose;


	boost::mutex::scoped_lock lock(poseLock);
	EcVector currentTran = myPose.translation();
	//ee_rate.resize(current.size());//make sure same size
	for ( int i = 0; i < 3; i++ ){
		currentTran[i] += ee_rate[i];
	}
	desiredPose.setTranslation(currentTran);

	//std::cout<<"Desired pose:  x: "<<desiredPose.translation().x()<< " y: " <<desiredPose.translation().y()<<" z: " <<desiredPose.translation().z()<<std::endl;

	if( ee_set == FRAME_EE_SET){
		EcOrientation currentOrient = myPose.orientation();

		double roll, pitch, yaw;
		currentOrient.get123Euler(roll,pitch,yaw);

		roll+= ee_rate[3];
		pitch+= ee_rate[4];
		yaw+= ee_rate[5];

		std::cout<<"Orientation: < "<<roll<<" , "<<pitch<<" , "<<yaw<<" >"<<std::endl;

		currentOrient.setFrom123Euler(roll,pitch,yaw);
		desiredPose.setOrientation(currentOrient);
		setEndEffectorSet(FRAME_EE_SET);
	}
	else if ( ee_set == POINT_EE_SET){
		std::cout<<"Point_EE_mode";
		setEndEffectorSet(POINT_EE_SET);
	}
	myPose = desiredPose;


	if( fabs( ee_rate[6] ) > 0 ){
		myGripper += ee_rate[6];
		if( myGripper > GRIPPER_MAX){
			myGripper = GRIPPER_MAX;
		}
		else if( myGripper < GRIPPER_MIN){
			myGripper = GRIPPER_MIN;
		}

		std::cout<<"Setting Gripper to: "<<myGripper<<std::endl;
		moveGripperExample(myGripper);
	}

	return retVal;
}


EcBoolean EcCytonCommands::MovementExample( vector<double> ee_pose , int ee_set)const{

	EcBoolean retVal=EcTrue;
	//boost::mutex::scoped_lock lock(poseLock);
	//EcCoordinateSystemTransformation myPose;
	//myPose.setTranslation(EcVector(ee_pose[0],ee_pose[1],ee_pose[2]));
	EcCoordinateSystemTransformation desiredPose;
	desiredPose.setTranslation(EcVector(ee_pose[0],ee_pose[1],ee_pose[2]));
	if( ee_set == FRAME_EE_SET){
		EcOrientation orient;
		orient.setFrom123Euler(ee_pose[3],ee_pose[4],ee_pose[5]);//set roll, pitch,yaw
		desiredPose.setOrientation(orient);
		setEndEffectorSet(FRAME_EE_SET);
	}
	else if ( ee_set = POINT_EE_SET){
		setEndEffectorSet(POINT_EE_SET);
	}
	boost::mutex::scoped_lock lock(poseLock);
	myPose = desiredPose;

	return retVal;
}

EcBoolean EcCytonCommands::SnapExample( )const{

	EcBoolean retVal=EcTrue;


	setEndEffectorSet(FRAME_EE_SET);

	EcManipulatorEndEffectorPlacement actualEEPlacement;
	getActualPlacement(actualEEPlacement);
	EcCoordinateSystemTransformation ecPose = actualEEPlacement.offsetTransformations()[0].coordSysXForm();
	EcVector translation = ecPose.translation();
	EcOrientation orientation = ecPose.orientation();

	boost::mutex::scoped_lock lock(poseLock);

	myPose.setTranslation(translation);
	myPose.setOrientation(orientation);

	return retVal;
}

EcBoolean EcCytonCommands::MoveJointsExample
(
		const EcRealVector jointPosition,
		const EcReal angletolerance
)const
{
	if(!getExecuting()){
		return EcFalse;
	}
	EcBoolean retVal=EcTrue;
	setEndEffectorSet(JOINT_CONTROL_EE_SET);
	EcSLEEPMS(500);
	EcRealVector currentJoints;//vector of EcReals that holds the set of joint angles
	retVal &= getJointValues(currentJoints);

	size_t size = currentJoints.size();
	if(size < jointPosition.size())
	{
		size = currentJoints.size();
	}
	else if(size >= jointPosition.size())
	{
		size = jointPosition.size();
	}

	std::cout<<"Current Joint Angles: ( ";
	for(size_t ii=0; ii<size; ++ii)
	{
		std::cout << currentJoints[ii] << "," ;
		currentJoints[ii] = jointPosition[ii];
	}
	std::cout << " )" << std::endl;

	std::cout << "Desired joint Angles: ( ";
	for(size_t ii=0; ii<size; ++ii)
	{
		std::cout << currentJoints[ii] << "," ;
	}
	std::cout <<" )" << std::endl;

	retVal &= setJointValues(currentJoints);

	//Check if achived
	EcBooleanVector jointAchieved;
	jointAchieved.resize(size);
	EcBoolean positionAchieved = EcFalse;
	while(!positionAchieved && getExecuting())
	{
		EcPrint(Debug) << "Moving ";
		getJointValues(currentJoints);
		EcPrint(Debug) << "Current Joints: ";
		for(size_t ii=0; ii<size; ++ii)
		{

			EcPrint(Debug)  << " , " << currentJoints[ii];

			if( abs(jointPosition[ii]-currentJoints[ii])<angletolerance)
			{
				jointAchieved[ii]=EcTrue;
			}
		}
		EcPrint(Debug) <<std::endl;
		for(size_t ii=0; ii<size; ++ii)
		{
			if(!jointAchieved[ii])
			{
				positionAchieved=EcFalse;
				break;
			}
			else
			{
				positionAchieved=EcTrue;
			}
		}
	}
	std::cout<<" Final Joint Angles: (";
	for(size_t ii=0; ii<size; ++ii)
	{
		std::cout <<  currentJoints[ii] << "," ;
	}
	std::cout<<" ) " << std::endl;

	return retVal;
}

//-----------------------------Point Movement Example-------------------------
EcBoolean EcCytonCommands::pointMovementExample
(
		const EcCoordinateSystemTransformation& pose
)const
{

	if(!getExecuting()){
		return EcFalse;
	}
	std::cout<<"Desired pose:  x: "<<pose.translation().x()<< " y: " <<pose.translation().y()<<" z: " <<pose.translation().z()<<std::endl;

	setEndEffectorSet(POINT_EE_SET); // point end effector set index
	EcEndEffectorPlacement desiredPlacement(pose);
	EcManipulatorEndEffectorPlacement actualEEPlacement,desiredEEPlacement;
	EcCoordinateSystemTransformation offset, zero, desiredCoord, actualCoord;
	zero.setTranslation(EcVector(0,0,0));

	getActualPlacement(desiredEEPlacement);
	EcEndEffectorPlacementVector state = desiredEEPlacement.offsetTransformations();
	state[0]=desiredPlacement;
	setDesiredPlacement(desiredPlacement,0,0);

	EcBoolean achieved = EcFalse;
	while(!achieved && getExecuting())
	{
		EcPrint(Debug) << "Moving "<<std::endl;
		getActualPlacement(actualEEPlacement);
		actualCoord=actualEEPlacement.offsetTransformations()[0].coordSysXForm();
		getDesiredPlacement(desiredEEPlacement);
		desiredCoord=desiredEEPlacement.offsetTransformations()[0].coordSysXForm();

		//get the transformation between the actual and desired
		offset=(actualCoord.inverse()) * desiredCoord;
		EcPrint(Debug)<<"distance between actual and desired: "<<offset.translation().mag()<<std::endl;

		if(offset.approxEq(zero,.00001))
		{
			std::cout<<"Achieved Pose"<<std::endl;
			achieved = EcTrue;
		}
		else{
			//
		}
	}
	return achieved;
}
//an experimental function to move the elbow
//this works, but is still under heavy testing.
EcBoolean EcCytonCommands::pointElbowMovementExample
(
		const int this_joint_ee,
		const EcVector tran
)const
{

	std::cout<<"in.";
	if(!getExecuting()){
		return EcFalse;
	}
	std::cout<<"check.";
	//std::cout<<"Desired pose:  x: "<<pose.translation().x()<< " y: " <<pose.translation().y()<<" z: " <<pose.translation().z()<<std::endl;

	setEndEffectorSet(POINT_EE_SET); // point end effector set index
	//EcEndEffectorPlacement desiredPlacement(pose);
	EcManipulatorEndEffectorPlacement actualEEPlacement,desiredEEPlacement;
	EcCoordinateSystemTransformation offset, zero, desiredCoord, actualCoord;
	zero.setTranslation(EcVector(0,0,0));

	std::cout<<"vectors.";

	getActualPlacement(desiredEEPlacement);
	EcEndEffectorPlacementVector state = desiredEEPlacement.offsetTransformations();
	//state[3]=desiredPlacement;
	//setDesiredPlacement(desiredPlacement,0,0);

	std::cout<<"xforms.";

	///////////

	//set the trnaslation of the driving gripper finger
	EcCoordinateSystemTransformation elbowTrans = state[this_joint_ee].coordSysXForm();
	EcVector current = elbowTrans.translation();
	elbowTrans.setTranslation(tran+current);
	EcEndEffectorPlacement elbowPlacement = state[this_joint_ee];
	elbowPlacement.setCoordSysXForm(elbowTrans);
	state[this_joint_ee]=elbowPlacement;

	std::cout<<"placements.";
	desiredEEPlacement.setOffsetTransformations(state);

	//set the desired placement
	setDesiredPlacement(desiredEEPlacement,0);

	std::cout<<"exec."<<std::endl;
	////////

	EcBoolean achieved = EcFalse;
	while(!achieved && getExecuting())
	{
		EcPrint(Debug) << "Moving "<<std::endl;
		getActualPlacement(actualEEPlacement);
		actualCoord=actualEEPlacement.offsetTransformations()[3].coordSysXForm();
		getDesiredPlacement(desiredEEPlacement);
		desiredCoord=desiredEEPlacement.offsetTransformations()[3].coordSysXForm();

		//get the transformation between the actual and desired
		offset=(actualCoord.inverse()) * desiredCoord;
		//EcPrint(Debug)

		std::cout<<"distance between actual and desired: "<<offset.translation().mag()<<std::endl;

		if(offset.approxEq(zero,.00001))
		{
			std::cout<<"Achieved Pose"<<std::endl;
			achieved = EcTrue;
		}
		else{
			//
		}
	}
	return achieved;
}

EcBoolean _executing = EcTrue;
//-----------------------------Frame Movement Example-------------------------
EcBoolean EcCytonCommands::frameMovementExample
(
		const EcCoordinateSystemTransformation& pose
)const
{

	if(!getExecuting()){
		return EcFalse;
	}
	//std::cout<<"Desired pose:  x: "<<pose.translation().x()<< " y: " <<pose.translation().y()<<" z: " <<pose.translation().z()<<std::endl;

	setEndEffectorSet(FRAME_EE_SET); // frame end effector set index
	EcEndEffectorPlacement desiredPlacement(pose);
	EcManipulatorEndEffectorPlacement actualEEPlacement,desiredEEPlacement;
	EcCoordinateSystemTransformation offset, zero, desiredCoord, actualCoord;
	zero.setTranslation(EcVector(0,0,0));

	getActualPlacement(actualEEPlacement);
	EcEndEffectorPlacementVector state = actualEEPlacement.offsetTransformations();
	state[0]=desiredPlacement;
	setDesiredPlacement(desiredPlacement,0,0);

	EcBoolean achieved = EcFalse;


	while(!achieved && getExecuting())
	{
		EcPrint(Debug) << "Moving "<<std::endl;
		getActualPlacement(actualEEPlacement);
		actualCoord=actualEEPlacement.offsetTransformations()[0].coordSysXForm();
		getDesiredPlacement(desiredEEPlacement);
		desiredCoord=desiredEEPlacement.offsetTransformations()[0].coordSysXForm();

		//get the transformation between the actual and desired
		offset=(actualCoord.inverse()) * desiredCoord;
		EcPrint(Debug)<<"Distance between actual and desired: "<<offset.translation().mag()<<std::endl;

		if(offset.approxEq(zero,.00001))
		{
			EcPrint(Debug)<<"Achieved Pose"<<std::endl;
			achieved = EcTrue;
		}
		////added this:
		else{
			//std::cout<<"distance between actual and desired: "<<offset.translation().mag()<<std::endl;
		}
		////
	}

	return achieved;
}
bool _execute = false;
EcBoolean EcCytonCommands::getExecuting()const{
	boost::mutex::scoped_lock lock(executeLock);
	return _execute;
}
void EcCytonCommands::setExecuting(bool exec)const{
	boost::mutex::scoped_lock lock(executeLock);
	_execute = exec;
}

//-----------------------------move gripper test-------------------------
EcBoolean EcCytonCommands::moveGripperExample
(
		const EcReal gripperPos
)const
{
	if(!getExecuting()){
		return EcFalse;
	}
	EcBoolean retVal=EcTrue;

	//boost::mutex::scoped_lock lock(poseLock);
	//myGripper = gripperPos;

	EcManipulatorEndEffectorPlacement actualEEPlacement,desiredEEPlacement;

	setEndEffectorSet(FRAME_EE_SET); // frame end effector set index
	EcSLEEPMS(100);
	//get the current placement of the end effectors
	getActualPlacement(actualEEPlacement);

	//0 is the Wrist roll joint (point or frame end effector),
	//1 is the first gripper finger (linear constraint end effector)
	EcEndEffectorPlacementVector state = actualEEPlacement.offsetTransformations();

	//set the trnaslation of the driving gripper finger
	EcCoordinateSystemTransformation gripperfinger1trans = state[1].coordSysXForm();
	gripperfinger1trans.setTranslation(EcVector(0,0,gripperPos));
	EcEndEffectorPlacement finger1placement = state[1];
	finger1placement.setCoordSysXForm(gripperfinger1trans);
	state[1]=finger1placement;

	desiredEEPlacement.setOffsetTransformations(state);

	//set the desired placement
	setDesiredPlacement(desiredEEPlacement,0);
	std::cout<<"Moving Gripper to: "<<gripperPos<<std::endl;

	return retVal;
}

//-----------------------------manipulation action test-------------------------
EcBoolean EcCytonCommands::manipulationActionTest
(
		const EcString& filename,
		const EcString& actionName,
		const EcU32& timeInMS
)const
{
	EcManipulationActionManager actionManager;
	EcBoolean retVal = EcXmlObjectReaderWriter::readFromFile(actionManager, filename);

	if(!retVal)
	{
		return retVal;
	}

	retVal = setManipulationActionManager(actionManager);
	if(!retVal)
	{
		return retVal;
	}

	retVal = setManipulationAction(actionName);
	if(!retVal)
	{
		return retVal;
	}

	retVal = startManipulation();
	if(!retVal)
	{
		return retVal;
	}

	EcSLEEPMS(timeInMS);

	retVal = stopManipulation();
	if(!retVal)
	{
		return retVal;
	}
	return retVal;
}

// a pick and place example
EcBoolean EcCytonCommands::pickAndPlaceExample
(
		const EcString& cytonModel
)const
{
	EcRealVector initJoints(7);//vector of EcReals that holds the set of joint angles
	initJoints[1]=-.7;
	initJoints[3]=-.7;
	initJoints[5]=-.7;

	//Move Joints
	MoveJointsExample(initJoints,.000001);


	//open the gripper
	if(cytonModel == "1500" || cytonModel == "300" )
	{
		moveGripperExample(0.0149);
	}
	if(cytonModel == "1500R2" || cytonModel == "300PX" )
	{
		moveGripperExample(0.0149);
	}


	if(cytonModel == "1500" || cytonModel == "1500R2")
	{

		EcCoordinateSystemTransformation desiredPose;
		desiredPose.setTranslation(EcVector(0,.35,.2));
		EcOrientation orient;
		orient.setFrom123Euler(0,0,EcPi/2);//set roll, pitch,yaw
		desiredPose.setOrientation(orient);
		frameMovementExample(desiredPose);

		desiredPose.setTranslation(EcVector(.115,.35,.2));
		frameMovementExample(desiredPose);

		desiredPose.setTranslation(EcVector(.115,.35,.05));
		frameMovementExample(desiredPose);

		//close the gripper
		if(cytonModel == "1500" || cytonModel == "300" )
		{
			moveGripperExample(0.0015);
		}
		if(cytonModel == "1500R2" || cytonModel == "300PX" )
		{
			moveGripperExample(0.001);
		}
		EcSLEEPMS(1000);

		desiredPose.setTranslation(EcVector(.115,.35,.2));
		frameMovementExample(desiredPose);

		desiredPose.setTranslation(EcVector(0,.35,.2));
		frameMovementExample(desiredPose);

		orient.setFrom123Euler(0,0,EcPi);//set roll, pitch,yaw
		desiredPose.setOrientation(orient);
		frameMovementExample(desiredPose);

		desiredPose.setTranslation(EcVector(0,.35,.05));
		frameMovementExample(desiredPose);


		//Opem the gripper
		if(cytonModel == "1500" || cytonModel == "300" )
		{
			moveGripperExample(0.0149);
		}
		if(cytonModel == "1500R2" || cytonModel == "300PX" )
		{
			moveGripperExample(0.0149);
		}
		EcSLEEPMS(1000);

		desiredPose.setTranslation(EcVector(0,.35,.2));
		frameMovementExample(desiredPose);
	}

	if(cytonModel=="300" || cytonModel=="300PX" )
	{
		EcCoordinateSystemTransformation desiredPose;
		desiredPose.setTranslation(EcVector(0,.2,.15));
		EcOrientation orient;
		orient.setFrom123Euler(0,0,EcPi/2);//set roll, pitch,yaw
		desiredPose.setOrientation(orient);

		setEndEffectorSet(FRAME_EE_SET); // frame end effector set index

		frameMovementExample(desiredPose);

		desiredPose.setTranslation(EcVector(.1,.2,.15));
		frameMovementExample(desiredPose);

		desiredPose.setTranslation(EcVector(.1,.2,.05));
		frameMovementExample(desiredPose);

		//close the gripper
		if(cytonModel == "1500" || cytonModel == "300" )
		{
			moveGripperExample(0.0075);//(0.0015)//all the way closed
		}
		if(cytonModel == "1500R2" || cytonModel == "300PX" )
		{
			moveGripperExample(0.001);
		}
		EcSLEEPMS(1000);


		desiredPose.setTranslation(EcVector(.1,.2,.1));
		frameMovementExample(desiredPose);


		desiredPose.setTranslation(EcVector(0,.2,.15));
		frameMovementExample(desiredPose);

		orient.setFrom123Euler(0,0,EcPi);//set roll, pitch,yaw
		desiredPose.setOrientation(orient);
		frameMovementExample(desiredPose);

		desiredPose.setTranslation(EcVector(0,.2,.05));
		frameMovementExample(desiredPose);


		//open the gripper
		if(cytonModel == "1500" || cytonModel == "300" )
		{
			moveGripperExample(0.0149);
		}
		if(cytonModel == "1500R2" || cytonModel == "300PX" )
		{
			moveGripperExample(0.0149);
		}
		EcSLEEPMS(1000);

		desiredPose.setTranslation(EcVector(0,.2,.15));
		frameMovementExample(desiredPose);
	}
	return EcTrue;


}

// the stack example
EcBoolean EcCytonCommands::pickAndStackExample
(
		const EcString& cytonModel,double pick ,double stack
)const
{
	EcRealVector initJoints(7);//vector of EcReals that holds the set of joint angles
	initJoints[1]=-.7;
	initJoints[3]=-.7;
	initJoints[5]=-.7;

	//Move Joints
	MoveJointsExample(initJoints,.000001);


	//open the gripper
	if(cytonModel == "1500" || cytonModel == "300" )
	{
		moveGripperExample(0.0149);
	}
	if(cytonModel == "1500R2" || cytonModel == "300PX" )
	{
		moveGripperExample(0.0149);
	}


	if(cytonModel == "1500" || cytonModel == "1500R2")
	{
		//removed, see pickAndPlace
	}

	if(cytonModel=="300" || cytonModel=="300PX" )
	{
		EcCoordinateSystemTransformation desiredPose;
		desiredPose.setTranslation(EcVector(0,.2,.15));
		EcOrientation orient;
		orient.setFrom123Euler(0,0,EcPi/2);//set roll, pitch,yaw
		desiredPose.setOrientation(orient);

		setEndEffectorSet(FRAME_EE_SET); // frame end effector set index

		frameMovementExample(desiredPose);

		desiredPose.setTranslation(EcVector(.1,.2,.15));
		frameMovementExample(desiredPose);

		desiredPose.setTranslation(EcVector(.1,.2,pick));
		frameMovementExample(desiredPose);

		//close the gripper
		if(cytonModel == "1500" || cytonModel == "300" )
		{
			moveGripperExample(0.0076);//(0.0015)//all the way closed
		}
		if(cytonModel == "1500R2" || cytonModel == "300PX" )
		{
			moveGripperExample(0.001);
		}
		EcSLEEPMS(1000);


		desiredPose.setTranslation(EcVector(.1,.2,.1));
		frameMovementExample(desiredPose);


		desiredPose.setTranslation(EcVector(0,.2,.15));
		frameMovementExample(desiredPose);

		orient.setFrom123Euler(0,0,EcPi);//set roll, pitch,yaw
		desiredPose.setOrientation(orient);
		frameMovementExample(desiredPose);

		desiredPose.setTranslation(EcVector(0,.2,stack));
		frameMovementExample(desiredPose);


		//open the gripper
		if(cytonModel == "1500" || cytonModel == "300" )
		{
			moveGripperExample(0.0149);
		}
		if(cytonModel == "1500R2" || cytonModel == "300PX" )
		{
			moveGripperExample(0.0149);
		}
		EcSLEEPMS(1000);

		desiredPose.setTranslation(EcVector(0,.2,.15));
		frameMovementExample(desiredPose);
	}
	return EcTrue;
}

// the un-stack example
EcBoolean EcCytonCommands::pickAndUnStackExample
(
		const EcString& cytonModel,double pick ,double stack
)const
{
	EcRealVector initJoints(7);//vector of EcReals that holds the set of joint angles
	initJoints[1]=-.7;
	initJoints[3]=-.7;
	initJoints[5]=-.7;

	//Move Joints
	MoveJointsExample(initJoints,.000001);


	//open the gripper
	if(cytonModel == "1500" || cytonModel == "300" )
	{
		moveGripperExample(0.0149);
	}
	if(cytonModel == "1500R2" || cytonModel == "300PX" )
	{
		moveGripperExample(0.0149);
	}


	if(cytonModel == "1500" || cytonModel == "1500R2")
	{
		//removed, see pickAndPlace
	}

	if(cytonModel=="300" || cytonModel=="300PX" )
	{

		EcCoordinateSystemTransformation desiredPose;
		desiredPose.setTranslation(EcVector(0,.2,.15));
		EcOrientation orient;

		setEndEffectorSet(FRAME_EE_SET); // frame end effector set index

		orient.setFrom123Euler(0,0,EcPi);//set roll, pitch,yaw
		desiredPose.setOrientation(orient);
		frameMovementExample(desiredPose);

		desiredPose.setTranslation(EcVector(0,.2,stack));
		frameMovementExample(desiredPose);

		//close the gripper
		if(cytonModel == "1500" || cytonModel == "300" )
		{
			moveGripperExample(0.0076);//(0.0015)//all the way closed
		}
		if(cytonModel == "1500R2" || cytonModel == "300PX" )
		{
			moveGripperExample(0.001);
		}
		EcSLEEPMS(1000);

		//move up

		desiredPose.setTranslation(EcVector(0,.2,.15));
		frameMovementExample(desiredPose);

		//rotate

		orient.setFrom123Euler(0,0,EcPi/2);//set roll, pitch,yaw
		desiredPose.setOrientation(orient);

		frameMovementExample(desiredPose);


		//move over
		desiredPose.setTranslation(EcVector(.1,.2,.15));
		frameMovementExample(desiredPose);
		//move down
		desiredPose.setTranslation(EcVector(.1,.2,pick));
		frameMovementExample(desiredPose);
		//open gripper
		if(cytonModel == "1500" || cytonModel == "300" )
		{
			moveGripperExample(0.0149);//(0.0015)//all the way closed
		}
		if(cytonModel == "1500R2" || cytonModel == "300PX" )
		{
			moveGripperExample(0.0149);
		}
		EcSLEEPMS(1000);


		desiredPose.setTranslation(EcVector(0.1,.2,.15));
		frameMovementExample(desiredPose);
		////////move rotate open

		desiredPose.setTranslation(EcVector(0,.2,.15));
		frameMovementExample(desiredPose);
	}
	return EcTrue;
}

// some default hardware test, not yet used or tested
EcBoolean EcCytonCommands::hardwareEnableTest
(
		const EcBoolean flag
)const
{
	return setHardwareEnable(flag);
}

// this is a default function, but haven't had much success using it.
EcBoolean EcCytonCommands::resetToHome
(
)const
{

	EcRealVector joints;
	EcBoolean retVal = getJointValues(joints);

	size_t size = joints.size();

	// increment all joints except the last
	for(size_t ii=0; ii<size; ++ii)
	{
		joints[ii] = 0.0;
	}

	retVal &= setJointValues(joints);
	EcSLEEPMS(2000);

	return retVal;
}

/////



