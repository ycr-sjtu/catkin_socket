#include <ros/ros.h>
#include"socket_state/socketstate.h"

int main(int argc, char **argv)
{
        ros::init(argc, argv,"pub");
        ros::NodeHandle nd;
        ros::Publisher publish = nd.advertise<socket_state::socketstate>("/socketstate", 10);
        ros::Rate loop_rate(10);
        while (ros::ok())
        {
                socket_state::socketstate msg;
                msg.x = 123.456;
                msg.y = 123.456;
                msg.state = 1;

                publish.publish(msg);
                loop_rate.sleep();
        }

        return 0;
}