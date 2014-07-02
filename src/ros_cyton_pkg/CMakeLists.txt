cmake_minimum_required(VERSION 2.8.3)
project(ros_cyton_pkg)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Declare ROS messages and services
#add_message_files(FILES Num.msg)
#add_service_files(FILES AddTwoInts.srv)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

include(CytonBuildDefaults.cmake)



# Pull in rendering requirements
include_directories(${render_inc})
link_directories(${render_lib})



add_executable(ros_cyton_server src/ecCytonCommands.cpp src/ros_cyton_server.cpp)
target_link_libraries(ros_cyton_server ecManipulation ecManipulationDirector ecSimulation ecManipulator ecVisualization ecFoundCommon ecXmlReaderWriter ecXml ecFoundCore ecGeometry ecControl ecMatrixUtilities ecMeasure ecFunction boost_program_options-mt boost_system-mt ${toolkits}/../bin/remoteCommandClientPlugin.ecp ecRemoteCommand ${catkin_LIBRARIES})
add_dependencies(ros_cyton_server ros_cyton_pkg_generate_messages_cpp)

add_executable(ros_cyton_client_point_ee_demo src/ros_cyton_client_point_ee_demo.cpp)
target_link_libraries(ros_cyton_client_point_ee_demo ${catkin_LIBRARIES})
add_dependencies(ros_cyton_client_point_ee_demo ros_cyton_pkg_generate_messages_cpp)

add_executable(ros_cyton_client_frame_ee_demo src/ros_cyton_client_frame_ee_demo.cpp)
target_link_libraries(ros_cyton_client_frame_ee_demo ${catkin_LIBRARIES})
add_dependencies(ros_cyton_client_frame_ee_demo ros_cyton_pkg_generate_messages_cpp)


add_executable(ros_cyton_client_joint_demo src/ros_cyton_client_joint_demo.cpp)
target_link_libraries(ros_cyton_client_joint_demo ${catkin_LIBRARIES})
add_dependencies(ros_cyton_client_joint_demo ros_cyton_pkg_generate_messages_cpp)

add_executable(ros_cyton_client_gripper_demo src/ros_cyton_client_gripper_demo.cpp)
target_link_libraries(ros_cyton_client_gripper_demo ${catkin_LIBRARIES})
add_dependencies(ros_cyton_client_gripper_demo ros_cyton_pkg_generate_messages_cpp)

add_executable(ros_cyton_client_joystick_demo src/ros_cyton_client_joystick_demo.cpp)
target_link_libraries(ros_cyton_client_joystick_demo ${catkin_LIBRARIES})
add_dependencies(ros_cyton_client_joystick_demo ros_cyton_pkg_generate_messages_cpp)


