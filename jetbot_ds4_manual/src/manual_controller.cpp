#include "ros/ros.h" 
/*which includes:
    #include "ros/time.h"
    #include "ros/rate.h"
    #include "ros/init.h"
    #include "ros/node_handle.h"
    ...
*/

#include "std_msgs/Header.h"
#include "std_msgs/String.h"
#include <keyboard/Key.h>
#include <ds4_driver/Status.h>

int32_t button_r1 = 0;
int32_t button_r2 = 0;
int32_t button_dpad_left = 0;
int32_t button_dpad_right = 0;

std_msgs::String msg_command;


//-------------         Return the key      -------------//
void DS4_STATUS(const ds4_driver::Status& msg)
{

    button_r1 = msg.button_r1;
    button_r2 = msg.button_r2;
    button_dpad_left = msg.button_dpad_left;
    button_dpad_right = msg.button_dpad_right;
}


int main(int argc, char **argv)
{
    //-------------         Initialization      -------------//
    ros::init(argc, argv, "Manual_Control_Controller");
    ros::NodeHandle n;

    //-------------         Topics              -------------//
    ros::Subscriber sub_key_down = n.subscribe("/status", 1000, DS4_STATUS);
    ros::Publisher command_pub = n.advertise<std_msgs::String>("/jetbot_motors/cmd_str", 1000);

    //-------------         ROS Spinner         -------------//
    ros::AsyncSpinner spinner(4);
    spinner.start();

    //-------------         Control Loop         -------------//
    ros::Rate loop_rate(10);
    msg_command.data = "stop";
    while (ros::ok())
    {

        if (button_r1 !=0 ||  button_r2 !=0 || button_dpad_left != 0 || button_dpad_right !=0)
        {
            if (button_r1  == 1) msg_command.data = "forward";
            else if (button_r2  == 1) msg_command.data = "backward";
            else if (button_dpad_left  == 1) msg_command.data = "left";
            else if (button_dpad_right  == 1) msg_command.data = "right";
            else msg_command.data = "stop";
        }
        else msg_command.data = "stop";
        command_pub.publish(msg_command);     
        loop_rate.sleep();
    }
}

/*
ROS Headers:    http://docs.ros.org/en/indigo/api/roscpp/html/ros_8h.html 
jetbot_ros:     https://www.hackster.io/belochka/controlling-the-jetbot-robot-from-ros-014620 
                https://github.com/dusty-nv/jetbot_ros 
Keyboard:       https://github.com/ros-teleop/teleop_twist_keyboard 
                https://github.com/lrse/ros-keyboard 
Useful Later:   https://stackoverflow.com/questions/71808245/ros-subscriber-undefined-reference 
Experiences:    #1  If there is none in parameter of callback functions, ERROR
                #2  Cannot PUBLISH std::String, publish std_msgs::String instead: https://answers.ros.org/question/256448/why-cant-i-send-a-string-message-through-my-program/ 
*/