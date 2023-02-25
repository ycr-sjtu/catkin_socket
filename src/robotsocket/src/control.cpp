#include "robotsocket/robotsocket.h"
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include"turtlesim/Pose.h"
#include"robotsocket/state.h"
#include "sensor_msgs/NavSatFix.h"
#include"nav_msgs/Path.h"

void RobotSocket::forward()
{
    ROS_INFO("forward");
    /* 为这个进程节点创建句柄 */
    ros::NodeHandle n;
    /* 创建发布者对象 */
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000, true);

    /* 要发布的消息: 让乌龟以1.0的线速度前进 */
    geometry_msgs::Twist msg;
    msg.linear.x = 1.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;

    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 0.0;

    // 发布消息
    pub.publish(msg);

    /* 剩下的时间睡眠 */
    ros::Duration(0.5).sleep();
};

void RobotSocket::back()
{
    ROS_INFO("back");
    /* 为这个进程节点创建句柄 */
    ros::NodeHandle n;
    /* 创建发布者对象 */
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000, true);

    /* 要发布的消息: 让乌龟以1.0的线速度后退 */
    geometry_msgs::Twist msg;
    msg.linear.x = -1.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;

    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 0.0;

    // 发布消息
    pub.publish(msg);

    /* 剩下的时间睡眠 */
    ros::Duration(0.5).sleep();
};

void RobotSocket::left(){
    ROS_INFO("left"); 
    /* 为这个进程节点创建句柄 */
    ros::NodeHandle n;
    /* 创建发布者对象 */
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000, true);

    /* 要发布的消息: 让乌龟以1.0的线速度左转 */
    geometry_msgs::Twist msg;
    msg.linear.x = 0.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;

    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 1.0;

    // 发布消息
    pub.publish(msg);

    /* 剩下的时间睡眠 */
    ros::Duration(0.5).sleep();
};

void RobotSocket::right(){
    ROS_INFO("right");
    /* 为这个进程节点创建句柄 */
    ros::NodeHandle n;
    /* 创建发布者对象 */
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000, true);

    /* 要发布的消息: 让乌龟以1.0的线速度右转 */
    geometry_msgs::Twist msg;
    msg.linear.x = 0.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;

    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = -1.0;

    // 发布消息
    pub.publish(msg);

    /* 剩下的时间睡眠 */
    ros::Duration(0.5).sleep();
};
    
// 发布停止msg, state=1停止
void RobotSocket::stop(){
    ROS_INFO("stop");
    ros::NodeHandle n;
    ros::Publisher publish = n.advertise<robotsocket::state>("/state", 10, true);
    robotsocket::state msg;
    msg.state = 1;
    while(publish.getNumSubscribers()<1);
    publish.publish(msg);
    ros::Duration(0.5).sleep();
};

// 发布入库msg, state=2 入库
void RobotSocket::warehouse(){
    ROS_INFO("warehouse");
    ros::NodeHandle n;
    ros::Publisher publish = n.advertise<robotsocket::state>("/state", 10, true);
    robotsocket::state msg;
    msg.state = 2;
    while(publish.getNumSubscribers()<1);
    publish.publish(msg);
    ros::Duration(0.5).sleep();
};

//发布目的地msg, state = 0 作业
void RobotSocket::robot_pub(double target_x,double target_y){
    ROS_INFO("working");
    ros::NodeHandle n;
    ros::Publisher publish = n.advertise<robotsocket::state>("/state", 10, true);
    robotsocket::state msg;
     msg.x = target_x;
    msg.y = target_y;
    msg.state = 0;
    while(publish.getNumSubscribers()<1);
    publish.publish(msg);
    ros::Duration(0.5).sleep();
}

double sub_x,sub_y,sub_lon,sub_lat;

void subscriberCallback(const sensor_msgs::NavSatFix::ConstPtr& gps){
        printf("latitude=%.10f, longitude=%.10f\n",gps->latitude,gps->longitude);
        sub_lat = gps->latitude;
        sub_lon = gps->longitude;
}

void subscriberCallback2(const nav_msgs::Path::ConstPtr& path){
        printf("x=%f, y=%f\n",path->poses.back().pose.position.x,path->poses.back().pose.position.y);
        sub_x = path->poses.back().pose.position.x;
        sub_y = path->poses.back().pose.position.y;
}

//订阅x，y，lon，lat, state
void RobotSocket::robot_sub(double * x, double * y, double * lon, double * lat){
    ros::NodeHandle n;
    ros::Subscriber subscriber = n.subscribe("/fix", 10, &subscriberCallback);
    ros::Subscriber subscriber2 = n.subscribe("/gps_path", 10, &subscriberCallback2);
    ros::spin();
    * x = sub_x;
    * y = sub_y;
    * lon = sub_lon;
    * lat = sub_lat;
}

int state;

void subscriberCallback_state(const robotsocket::state::ConstPtr& msg){
    state = msg->state;
}

//订阅工作状态state
void RobotSocket::state_sub(atomic_bool * working_signal){   
    int state=0;
    ros::NodeHandle n;
    ros::Subscriber subscriber = n.subscribe("/state", 10, &subscriberCallback_state);
    ros::Rate loop_rate(10);
    while (ros::ok())
        {
            loop_rate.sleep();
            ros::spinOnce();
            if(state==1){
                * working_signal=false;
                break;
            }
        }
}