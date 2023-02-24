#include <ros/ros.h>
#include"socket_state/socketstate.h"

void subscriberCallback(const socket_state::socketstate::ConstPtr& msg)
{
        printf("x=%f,y=%f,state=%d\n",msg->x,msg->y,msg->state);
}
int main(int argc, char **argv)
{
        ros::Subscriber subscriber;
        ros::init(argc, argv,"sub");
        ros::NodeHandle nd;
        subscriber = nd.subscribe("/socketstate", 5, &subscriberCallback);
        ros::Rate loop_rate(10);
        while (ros::ok())
        {
               loop_rate.sleep();
                ros::spinOnce();
        }

        return 0;
}
