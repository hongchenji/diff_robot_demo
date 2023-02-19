This project is based on gazebo and ros.

Author:Hongchen Ji Email:ueeso@student.kit.edu or hongchenji@gmail.com

Requirements:

-Install ROS

We recommend for these ROS integration tutorials you install (ros-noetic-desktop-full or ros-melodic-desktop-full) so that you have all the necessary packages.

See the ROS installation page https://wiki.ros.org/ROS/Installation for more details. Be sure to source your ROS setup.bash script by following the instructions on the ROS installation page.

-Install Gazebo

You can install Gazebo either from source or from pre-build Ubuntu debians.

See Install Gazebo https://classic.gazebosim.org/tutorials?cat=install. 

If installing from source, be sure to build the gazebo_X.Y (X.Y being your desired version) branch.

-...

Run the robot:
-copy the diff_wheeled_robot_gazebo folder into the /catkin_ws/src

-catkin_make/build in the /catkin_ws

-source devel/setup.bash

-there are two launch file in the /diff_wheeled_robot_gazebo/launch folder

-first use command:" roslaunch diff_wheeled_robot_gazebo world_init.launch " to init the gazebo environment and the differential robot

-second use the command " roslaunch diff_wheeled_robot_gazebo world_init.launch " to publish the speed.

-the speed is given in the velocity_params.yaml file in the /diff_wheeled_robot_gazebo/config folder.
