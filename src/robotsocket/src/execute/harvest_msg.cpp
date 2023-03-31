#include "ros/ros.h"
#include "robotsocket/harvestingRobotClient.h"
#include "robotsocket/harvest_action.h"
#include "robotsocket/harvest_vel.h"
#include "robotsocket/harvest_state.h"

void harvest_conveyor_cmd(double voltage,char* cmd){
    cmd[0]=0x3c;
    cmd[1]=0x30;
    cmd[2]=0x37;
    cmd[3]=0x7c;

    int vol=(voltage+10)/20*65535;
    // 需要一个int转16进制的函数，转成2位数的char
    // cmd[4] = ?
    // cmd[5] = ?

    cmd[6]=0x80;
    cmd[7]=0x00;
    cmd[8]=0x00;
    cmd[9]=0x00;
    cmd[10]=0x00;
    cmd[11]=0x00;
    cmd[12]=0x3e;
    cmd[13] = '\0';
}

void harvest_vel_cmd(double left_vel, double right_vel, char* cmd){
    cmd[0]=0x3c;
    cmd[1]=0x30;
    cmd[2]=0x36;
    cmd[3]=0x7c;

    int left_vel_cmd=(left_vel+10)/20*65535;
    int right_vel_cmd=(right_vel+10)/20*65535;
    // 需要一个int转16进制的函数，转成2位数的char
    // cmd[4] = ?
    // cmd[5] = ?
    // cmd[6]=?;
    // cmd[7]=?;

    cmd[8]=0x00;
    cmd[9]=0x00;
    cmd[10]=0x00;
    cmd[11]=0x00;
    cmd[12]=0x3e;
    cmd[13] = '\0';
}

void harvest_pub(){

} 