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
#include <math.h>


///Global declaration of publishers
ros::Publisher mode_pub;
ros::Publisher ee_type_pub;
ros::Publisher ee_pos_pub;
ros::Publisher ee_rate_pub;
ros::Publisher joint_val_pub;
ros::Publisher gripper_val_pub;
ros::Publisher execute_pub;

#define DO_NOT_MODIFY 1001
int JOINT_WRIST = 1;

std::vector<double> ee_pose(6);
std::vector<double> ee_rates(6);
std::vector<double> joint_values(7);
std::vector<double> joint_rates(7);

const double GRIPPER_MIN = 0.0015;
const double GRIPPER_MAX = 0.015;
const float GRIPPER_GAIN = 0.001;
float DEADZONE  = 0.125;
//somewhere in the middle?{ 0.00625 , 0.008, 0.015 };

///Function will send the gripper value
///@param[in] value (double) Gripper value
///@return[out] status(bool) Status of the function
///Function will adjust the gripper value
///@param[in] value (double) Gripper value
///@return[out] status(bool) Status of the function
float AXIS_GAIN[] = {0.001 , 0.001 , 0.001 , 0.001 , 0.001 , 0.001 , 0.001 , 0.001 };

//	AXIS NUMBER:	{0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 };
int axis_map[] =	{0 , 1 , 2 , 5 , 4 , 4 , 3 , 5 };//6 does not exist


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
bool Modify_EE_Pose(std::string end_effector,std::vector<double> _pose)

{

	ROS_INFO("Moving to < %.3f , %.3f , %.3f >",ee_pose[0],ee_pose[1],ee_pose[2]);

	std_msgs::Float64MultiArray pose;
	pose.data=_pose;
	ee_pos_pub.publish(pose);


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

bool Send_Gripper_Value(double value)

{
	std_msgs::Float64 gripper_val;
	gripper_val.data = value;

	gripper_val_pub.publish(gripper_val);


	return true;
}


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

	gripper_val_pub.publish(gripper_val);


	return true;
}


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
			//handled = Modify_Gripper_Value(0.001);
		}
		break;
	case 1://B button
		if(state > 0){
			ROS_INFO("CLOSING GRIPPER");//open gripper
			//handled = Modify_Gripper_Value(-0.001);
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
bool Send_EE_Rates(){

	for(int axis = 0; axis < ee_rates.size(); axis++){
		ee_pose[axis_map[axis]] += ee_rates[axis_map[axis]];//^^
	}
	std_msgs::Float64MultiArray msg;
	msg.data=ee_rates;
	ee_rate_pub.publish(msg);
	msg.data=ee_pose;
	ee_rate_pub.publish(msg);

	return true;
}
void handle_joystick( const sensor_msgs::Joy::ConstPtr& msg){
	bool moved = false;
	ROS_INFO("Current pose is: < %.3f , %.3f , %.3f >",ee_pose[0],ee_pose[1],ee_pose[2]);
	/*ee_rates[0] =
			for(unsigned i = 0; i < msg->axes.size(); i++){
				if( handle_axis(i,msg->axes[i]) ){
					moved = true;//ROS_INFO("Axis %d is now at position: %f",i,msg->axes[i]);//
				}
			}*/
	for(unsigned i = 0; i < msg->axes.size()-1; i++){//first 4 axis, and not the last
		ROS_INFO("Modifying axis %d.",i);
		if( fabs(msg->axes[i]) > DEADZONE ){
			moved = true;//ROS_INFO("Axis %d is now at position: %f",i,msg->axes[i]);//
			ee_rates[axis_map[i]] = ( AXIS_GAIN[axis_map[i]] * msg->axes[i] );

		}
		else{
			ee_rates[axis_map[i]] = 0;
		}
		if ( i == 3 ){
			i+=2;//skip 4 and 5
		}
	}
	float value = map(msg->axes[4] , 1.0 , -1.0 , 0.0 , -1.0 );
		  value += map(msg->axes[5] , 1.0 , -1.0 , 0.0 , 1.0 );
	ee_rates[4] = ( AXIS_GAIN[4] * value );

	if (moved){//if a joystick was moved
		ROS_INFO("Modifying pose by: < %.3f , %.3f , %.3f >",msg->axes[0],msg->axes[1],msg->axes[2]);
		Modify_EE_Pose("point_end_effector",ee_pose);
	}
	for(unsigned i = 0; i < msg->buttons.size(); i++){
		handle_button(i,msg->buttons[i]);
		//ROS_INFO("Button %d is now: %d",i,msg->buttons[i]);}
	}
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
		//Send_EE_Pose("point_end_effector", saved_pos_array[1]);
		break;
	case 3:
		//end_EE_Pose("point_end_effector", saved_pos_array[2]);
		break;
	case 4:
		//Send_EE_Pose("point_end_effector", saved_pos_array[3]);
		break;
	case 5:
		//Send_EE_Pose("point_end_effector", pos_array);
		break;
	default:
		ROS_INFO("COMMAND: %d",command);
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
	//ROS_INFO("Got joint feedback.");//
	joint_values = msg->data;
}
void handle_pose_feedback( const std_msgs::Float64MultiArray::ConstPtr& msg){
	//ROS_INFO("Got Pose feedback.");//
	ee_pose = msg->data;
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
	ee_rate_pub = n.advertise<std_msgs::Float64MultiArray>("ee_rates", 1);
	joint_val_pub = n.advertise<std_msgs::Float64MultiArray>("joint_array", 1);
	gripper_val_pub = n.advertise<std_msgs::Float64>("gripper_value", 1);
	execute_pub = n.advertise<std_msgs::String>("execute", 1);

	ros::Subscriber sub_joy = n.subscribe("joy",5,handle_joystick);
	ros::Subscriber sub_cmd = n.subscribe("shield_commands/pos",50,handle_command);
	//ros::Subscriber sub_rot = n.subscribe("shield_commands/rotate",5,handle_rotate);
	//ros::Subscriber sub_scale = n.subscribe("shield_commands/scale",5,handle_scale);
	ros::Subscriber sub_joint = n.subscribe("joint_array/feedback",5,handle_joint_feedback);
	ros::Subscriber sub_pose = n.subscribe("ee_pose/feedback",5,handle_pose_feedback);




	//ros::spin();
	ros::Rate loop_rate(30);

	while (ros::ok())
	{
		ros::spinOnce();
		Send_EE_Rates();
		loop_rate.sleep();
	}


	return 0;
}


