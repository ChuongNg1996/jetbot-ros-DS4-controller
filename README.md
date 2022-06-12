# Simple DS4 Manual Controller for Jetbot
A simple implementation of DUALSHOCK 4 controller for Jetbot

## Installation & Implementation
* Install Python & C++.
* [Install ROS](http://wiki.ros.org/melodic/Installation/Ubuntu) (any version).
* At /usr/home/"name" ("name" is arbitrary), create a ROS workspace. On terminal: 
   ```sh
   mkdir -p ~/catkin_ws/src
   ```
* Go to the created ROS workspace, clone the [jetbot_ros](https://github.com/dusty-nv/jetbot_ros) repo (choose the correct path for your ROS, e.g. mine is ROS Melodic, so `-b melodic` was added) and `jetbot-ros-DS4-controller` package and build them. On terminal: 
   ```sh
   cd ~/catkin_ws/src
   git clone https://github.com/dusty-nv/jetbot_ros -b melodic
   git clone [https://github.com/ChuongNg1996/jetbot-ros-object-following](https://github.com/ChuongNg1996/jetbot-ros-DS4-controller)
   cd ..
   catkin_make
   ```
* Run the ROS launch file:
   ```sh
   
   ```
## API
To be updated

## Debugging 
* Use `rostopic list` to see available ROS topics.
* Use `rostopic echo /jetbot_motors/cmd_str` to see if the messages are read.

## Other
* To make the commands run on startup, Ubuntu users can use `Startup Application` (beside `systemd`). Open `Startup Application` -> Add -> Name: `ROS Launch` (or anything) and Command: `terminator -e "bash -i -c 'sleep 3 && roslaunch jetbot_ros jetbot_motor.launch' "` -> Add -> Close.
