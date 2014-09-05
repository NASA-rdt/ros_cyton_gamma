#ROS Cyton Gamma Package
##Modified by William Baker, GSFC - Summer 2014

### About This Package:
The Cyton Viewer is a program supplied by Robai.  Obtain the latest install version from Robai directly.
ROS communicates to the Viewer throug ha plugin.  Load the RemoteCommandServer plugin in the Cyton Viewer by using the load plugin dropdown menu.
Next, start the ROS master, cyton_server node, and cyton_client_joystick_helper.
In order for the joysticks to be connected into ROS you will need to launch the 'joy_node' from the ros 'joy' package.
refer to the ROS 'joy' wiki page for more info, or see the ros_controller_gui repository for examples of how to get the joysticks running with ROS


### What needs to be installed:
This version runs on ROS hydro distro.
There is a ROS package from Robai, see the Robai Google Group 'Cyton Robots' for more info:
https://groups.google.com/forum/#!forum/cyton-robots
specifically this topic seemed to help:
https://groups.google.com/forum/#!topic/cyton-robots/sOQftI10lf0 

###Launching the Cyton Viewer and ROS Nodes:
####Note: run each section of code in a new terminal.
```
#process to open the cytonViewer
cd ~/robot/gamma_300/bin
sudo chmod 777 /dev/ttyUSB0 #give write access to arm
#./cytonSetup #this only needs to be run first time
./cytonViewer

#process to open an ROS Master
roscore #starts the ROS Master

#process to open ros-cyton server
cd ~/catkin_ws/build/bin
./ros_cyton_server -c 300 
#./ros_cyton_server -c 1500 #for gamma 1500

#process to open ros client
cd ~/catkin_ws/build/bin
./ros_cyton_client_joystick_helper
```

Note: login details hint: 'nasa'
