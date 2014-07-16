//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ros_cyton_client_ee_demo.cpp
//
//------------------------------------------------------------------------------


#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Float32MultiArray.h"
#include "std_msgs/Float64MultiArray.h"

#include "sensor_msgs/Joy.h"

#include <sstream>
#include <iostream>
#include <vector>


///Global declaration of publishers
ros::Publisher mode_pub;
ros::Publisher ee_type_pub;
ros::Publisher ee_pos_pub;
ros::Publisher joint_val_pub;
ros::Publisher gripper_val_pub;
ros::Publisher execute_pub;

#define DO_NOT_MODIFY 1001
int JOINT_WRIST = 1;

bool changed = false;
bool isChanged(){
	return changed;
}
void setChanged(bool val){
	changed = val;
}

///Function will send end effector pose, name of end effector to ros_cyton_server
///@param[in] end_effector (String) Name of endeffector
///@parm[in] ee_pose_array (double[]) end effector pose array(x,y,z,roll,pitch,yaw)
///@return[out] status Return the status of function
bool Send_EE_Pose(std::string end_effector,double ee_pose_array[])

{

	std::vector<double> ee_pos(6);
	std_msgs::String ee_type_msg;
	std_msgs::String mode_msg;
	std_msgs::String execute;
	std_msgs::Float64MultiArray ee_pose;

	ee_pos.insert(ee_pos.begin(),ee_pose_array,ee_pose_array+6);
	if(end_effector == "point_end_effector")
	{

		std::stringstream ss1;
		ss1 << "point_end_effector";
		ee_type_msg.data = ss1.str();
		ee_pose.data=ee_pos;

	}

	else if(end_effector == "frame_end_effector")
	{

		std::stringstream ss1;
		ss1 << "frame_end_effector";
		ee_type_msg.data = ss1.str();
		ee_pose.data=ee_pos;
	}


	std::stringstream ss;
	ss <<"ik_mode";
	mode_msg.data = ss.str();
	std::stringstream ss1;
	ss1 <<"yes";
	execute.data = ss1.str();

	///Sending messages
	mode_pub.publish(mode_msg);
	ee_type_pub.publish(ee_type_msg);
	ee_pos_pub.publish(ee_pose);
	execute_pub.publish(execute);	


	return true;
}


///Function will send end effector pose, name of end effector to ros_cyton_server
///@param[in] end_effector (String) Name of endeffector
///@parm[in] ee_pose_array (double[]) end effector pose array(x,y,z,roll,pitch,yaw)
///@return[out] status Return the status of function
bool Modify_EE_Pose(std::string end_effector,double ee_pose_array[])

{

	ROS_INFO("Modifying a move of End Effector.");
	setChanged(true);
	std::vector<double> ee_pos(6);
	std_msgs::String ee_type_msg;
	std_msgs::String mode_msg;
	std_msgs::String execute;
	std_msgs::Float64MultiArray ee_pose;

	ee_pos.insert(ee_pos.begin(),ee_pose_array,ee_pose_array+6);
	if(end_effector == "point_end_effector")
	{

		std::stringstream ss1;
		ss1 << "point_end_effector";
		ee_type_msg.data = ss1.str();
		ee_pose.data=ee_pos;

	}

	else if(end_effector == "frame_end_effector")
	{

		std::stringstream ss1;
		ss1 << "frame_end_effector";
		ee_type_msg.data = ss1.str();
		ee_pose.data=ee_pos;
	}

	
	std::stringstream ss;
	ss <<"ik_mode";
	mode_msg.data = ss.str();
	/*std::stringstream ss1;
	ss1 <<"yes";
	execute.data = ss1.str();
	 */
	///Sending messages
	mode_pub.publish(mode_msg);
	ee_type_pub.publish(ee_type_msg);
	ee_pos_pub.publish(ee_pose);


	return true;
}




///Function will send joint values to ros_cyton_server
///@param[in] joint_values (double []) Joint values except gripper
///@return[out] status Return the status of function
bool Send_Joint_Pose(double joint_pose_array[])
{

	std::vector<double> joint_pos(7);
	std_msgs::String mode_msg;
	std_msgs::String execute;
	std_msgs::Float64MultiArray joint_pose;

	joint_pos.insert(joint_pos.begin(),joint_pose_array,joint_pose_array+7);


	joint_pose.data = joint_pos;

	std::stringstream ss;
	ss <<"joint_mode";
	mode_msg.data = ss.str();

	std::stringstream ss1;
	ss1 <<"yes";
	execute.data = ss1.str();

	///Sending messages
	mode_pub.publish(mode_msg);
	joint_val_pub.publish(joint_pose);
	execute_pub.publish(execute);	

	return true;
}
bool Modify_Joint_Pose(int limb, double value){
	std::vector<double> joint_pos(7);
		std_msgs::String mode_msg;
		std_msgs::String execute;
		std_msgs::Float64MultiArray joint_pose;

		joint_pos.assign(7,DO_NOT_MODIFY);//seven values at ridiculous threshold
		if(limb < 8) joint_pos[limb] = value;//set
		//joint_pos.insert(joint_pos.begin(),joint_pose_array,joint_pose_array+7);
		ROS_INFO("Setting Joint_%d to %f",limb,value);

		joint_pose.data = joint_pos;

		std::stringstream ss;
		ss <<"joint_mode";
		mode_msg.data = ss.str();

		///Sending messages
		mode_pub.publish(mode_msg);
		joint_val_pub.publish(joint_pose);
}

const double GRIPPER_MIN = 0.0015;
const double GRIPPER_MAX = 0.015;
const float GRIPPER_GAIN = 0.001;
double gripper_value = 0.0085;//somewhere in the middle?{ 0.00625 , 0.008, 0.015 };

///Function will send the gripper value 
///@param[in] value (double) Gripper value
///@return[out] status(bool) Status of the function
bool Send_Gripper_Value(double value)

{
	std_msgs::Float64 gripper_val;
	gripper_val.data = value;

	gripper_val_pub.publish(gripper_val);


	return true;
}


///Function will adjust the gripper value 
///@param[in] value (double) Gripper value
///@return[out] status(bool) Status of the function
bool Modify_Gripper_Value(double value)

{

	if( value < GRIPPER_MIN){
		value = GRIPPER_MIN;//set to min limit
	}
	else if( value > GRIPPER_MAX){
		value = GRIPPER_MAX;//set to max limit
	}

	std_msgs::Float64 gripper_val;//create data to send
	gripper_val.data = value;//set data equal to value

	ROS_INFO("Modifying Gripper Value to %f",value);
	setChanged(true);
	gripper_val_pub.publish(gripper_val);


	return true;
}


float AXIS_GAIN = 0.001;

double pos_array[6] = {0.00501075,0.0586387,0.41778,-1.15601,-0.00276855,-3.13846};

double saved_pos_array[4][6] = {
		{0.00501075 , 0.0586387 , 0.41778 , -1.15601 , -0.00276855 , -3.13846},
		{0.03501075 , 0.0586387 , 0.41778 , -0.15601 , -0.00276855 , -3.13846},
		{0.04500000 , -0.261000 , 0.06400 , 0.000000 , 0.000000000 , 0.000000},
		{0.04500000 , -0.261000 , 0.06400 , 0.020000 , 0.020000000 , 0.200000},
};

float map(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


bool handle_button( unsigned button, int state){
	bool handled = false;
	switch(button){
	case 0://A button
		if(state > 0)
		{
			ROS_INFO("OPENNING GRIPPER");//open gripper
			handled = Modify_Gripper_Value(0.001);
		}
		break;
	case 1://B button
		if(state > 0){
			ROS_INFO("CLOSING GRIPPER");//open gripper
			handled = Modify_Gripper_Value(-0.001);
		}
		break;
	case 2://B button
		if(state > 0){
			JOINT_WRIST--;
			if(JOINT_WRIST < 0) JOINT_WRIST = 0;
			ROS_INFO("Switching control to Joint_%d",JOINT_WRIST);//open gripper
		}
		break;
	case 3://B button
		if(state > 0){
			JOINT_WRIST++;
			if(JOINT_WRIST > 7) JOINT_WRIST = 7;
			ROS_INFO("Switching control to Joint_%d",JOINT_WRIST);//open gripper
		}
		break;
	}
	return handled;
}

bool handle_axis( unsigned axis, float value ){
	bool handled = false;
	double newVal = 0.0;
	switch(axis){
	case 0:
		newVal = pos_array[axis] + ( AXIS_GAIN * value );
		ROS_INFO("Moving X-plane by %.3f with gain %.2f from %.3f -> %.3f",value,AXIS_GAIN,pos_array[axis],newVal);
		pos_array[axis] = newVal;
		handled = true;
		break;
	case 1:
		newVal = pos_array[axis] + ( AXIS_GAIN * value );
		ROS_INFO("Moving Y-plane by %.3f with gain %.2f from %.3f -> %.3f",value,AXIS_GAIN,pos_array[axis],newVal);
		pos_array[axis] = newVal;
		handled = true;
		break;
	case 2:
		newVal = pos_array[axis] + ( AXIS_GAIN * value );
		ROS_INFO("Moving Z-plane by %.3f with gain %.2f from %.3f -> %.3f",value,AXIS_GAIN,pos_array[axis],newVal);
		pos_array[axis] = newVal;
		handled = true;
		break;
	}
	return handled;
}

void handle_command( const std_msgs::Int32::ConstPtr& msg){
	int command = msg->data;

		std_msgs::String execute;
		std::stringstream ss1;

	switch(command){
	case 0:
		//this wont happen
		break;
	case 1:
		ss1 <<"test";
		execute.data = ss1.str();
		execute_pub.publish(execute);

		break;
	case 2:
		Modify_EE_Pose("point_end_effector", saved_pos_array[1]);
		break;
	case 3:
		Modify_EE_Pose("point_end_effector", saved_pos_array[2]);
		break;
	case 4:
		Modify_EE_Pose("point_end_effector", saved_pos_array[3]);
		break;
	case 5:
		Modify_EE_Pose("point_end_effector", pos_array);
		break;
	default:
		ROS_INFO("COMMAND: %d",command);
	}
}

void handle_joystick( const sensor_msgs::Joy::ConstPtr& msg){
	bool moved = false;
	for(unsigned i = 0; i < msg->axes.size(); i++){
		if( handle_axis(i,msg->axes[i]) ){
			moved = true;//ROS_INFO("Axis %d is now at position: %f",i,msg->axes[i]);//
		}
	}
	if (moved){//if a joystick was moved
		Modify_EE_Pose("point_end_effector",pos_array);
	}
	for(unsigned i = 0; i < msg->buttons.size(); i++){
		handle_button(i,msg->buttons[i]);
		//ROS_INFO("Button %d is now: %d",i,msg->buttons[i]);}
	}
}
void handle_rotate( const std_msgs::Float32::ConstPtr& msg){
	//ROS_INFO("Rotating %f",msg->data);

	//Modify_Joint_Pose(JOINT_WRIST,msg->data);
}
void handle_scale( const std_msgs::Float32::ConstPtr& msg){
	//float value = map(msg->data,0.1f,10,GRIPPER_MIN,GRIPPER_MAX);
	//ROS_INFO("Mapping Scale from %f to %f.",msg->data,value);
	//Modify_Gripper_Value( value );
}
void handle_joint_feedback( const std_msgs::Float64MultiArray::ConstPtr& msg){
	ROS_INFO("Got joint feedback.");//
}

//A function to map a value from a range to a new range
bool sendExecute(){
	if( ! isChanged() ){
		return false;
	}
	setChanged(false);

	std_msgs::String execute;
	std::stringstream ss1;
	ss1 <<"yes";
	execute.data = ss1.str();
	execute_pub.publish(execute);

	ROS_INFO("Executing a move of End Effector.");
	return true;
}

int main(int argc, char **argv)
{
	/**
	 * The ros::init() function needs to see argc and argv so that it can perform
	 * any ROS arguments and name remapping that were provided at the command line. For programmatic
	 * remappings you can use a different version of init() which takes remappings
	 * directly, but for most command-line programs, passing argc and argv is the easiest
	 * way to do it.  The third argument to init() is the name of the node.
	 *
	 * You must call one of the versions of ros::init() before using any other
	 * part of the ROS system.
	 */
	// %Tag(INIT)%
	ros::init(argc, argv, "ros_cyton_client");
	// %EndTag(INIT)%

	/**
	 * NodeHandle is the main access point to communications with the ROS system.
	 * The first NodeHandle constructed will fully initialize this node, and the last
	 * NodeHandle destructed will close down the node.
	 */
	// %Tag(NODEHANDLE)%
	ros::NodeHandle n;
	// %EndTag(NODEHANDLE)%

	/**
	 * The advertise() function is how you tell ROS that you want to
	 * publish on a given topic name. This invokes a call to the ROS
	 * master node, which keeps a registry of who is publishing and who
	 * is subscribing. After this advertise() call is made, the master
	 * node will notify anyone who is trying to subscribe to this topic name,
	 * and they will in turn negotiate a peer-to-peer connection with this
	 * node.  advertise() returns a Publisher object which allows you to
	 * publish messages on that topic through a call to publish().  Once
	 * all copies of the returned Publisher object are destroyed, the topic
	 * will be automatically unadvertised.
	 *
	 * The second parameter to advertise() is the size of the message queue
	 * used for publishing messages.  If messages are published more quickly
	 * than we can send them, the number here specifies how many messages to
	 * buffer up before throwing some away.
	 */
	// %Tag(PUBLISHER)%
	mode_pub = n.advertise<std_msgs::String>("mode", 1);
	ee_type_pub = n.advertise<std_msgs::String>("end_effector_type", 1);
	ee_pos_pub = n.advertise<std_msgs::Float64MultiArray>("ee_pose", 1);
	joint_val_pub = n.advertise<std_msgs::Float64MultiArray>("joint_array", 1);
	gripper_val_pub = n.advertise<std_msgs::Float64>("gripper_value", 1);
	execute_pub = n.advertise<std_msgs::String>("execute", 1);

	ros::Subscriber sub_joy = n.subscribe("joy",5,handle_joystick);
	ros::Subscriber sub_cmd = n.subscribe("shield_commands/pos",50,handle_command);
	ros::Subscriber sub_rot = n.subscribe("shield_commands/rotate",5,handle_rotate);
	ros::Subscriber sub_scale = n.subscribe("shield_commands/scale",5,handle_scale);
	ros::Subscriber sub_joint = n.subscribe("joint_array/feedback",5,handle_joint_feedback);




	//ros::spin();
	ros::Rate loop_rate(2);

	while (ros::ok())
	{
		sendExecute();
		//Send_EE_Pose("frame_end_effector",pos_array);
		ros::spinOnce();
		loop_rate.sleep();

	}


	return 0;
}


