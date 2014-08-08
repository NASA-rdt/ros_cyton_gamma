#ROS Cyton Gamma Package
##Modified by William Baker, GSFC - Summer 2014

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
./ros_cyton_server

#process to open ros client
cd ~/catkin_ws/build/bin
./ros_cyton_server
```
