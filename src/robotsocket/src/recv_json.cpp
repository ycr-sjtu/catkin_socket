#include "robotsocket/robotsocket.h"
#include <iostream>
#include <jsoncpp/json/json.h>
using namespace std;

/* 02指令的json处理函数
收到指令为{"x":"7","y":"7","id":"1"}
发送指令为{"id":"1","lat":"1","lon":"1","runningspeed":"1","recoveryRate":"60.3","status":"01","x":"1","y":"1"}
*/

void RobotSocket::recv2_json(char *str, char *myJsonChar)
{

    // jsoncpp 解析json字符串
    cout << "收到的消息为: " << str << endl;

    Json::Reader reader(Json::Features::strictMode());
    Json::Value _root;
    std::string sBuffer = (char *)str;

    if (!reader.parse(sBuffer, _root))
    {
        cout << "json解析错误" << endl;
    }
    else
    {
        cout << "json解析成功" << endl;
    }

    // double转string
    stringstream position_x, position_y, position_lon, position_lat;
    string str_x, str_y, str_lon, str_lat;
    position_x << setprecision(12) << position[0];
    position_y << setprecision(12) << position[1];
    position_lon << setprecision(11) << position[2];
    position_lat << setprecision(12) << position[3];
    str_x = position_x.str();
    str_y = position_y.str();
    str_lon = position_lon.str();
    str_lat = position_lat.str();

    // jsoncpp 初始化json对象
    Json::Value myJson;
    myJson["runningSpeed"] = "1";
    myJson["recoveryRate"] = "60.3";
    myJson["x"] = str_x;
    myJson["y"] = str_y;
    myJson["lon"] = str_lon;
    myJson["lat"] = str_lat;
    myJson["id"] = _root["id"];
    myJson["status"] = "01";

    // jsoncpp json对象转换成字符串
    Json::FastWriter _Writer;
    std::string myJsonStr = _Writer.write(myJson);

    // string转char
    for (int i = 0; i < myJsonStr.length(); i++)
    {
        myJsonChar[i] = myJsonStr[i];
    }
    myJsonChar[myJsonStr.length() - 1] = '\0';
    printf("json_char: %s\n", myJsonChar);
};

void RobotSocket::recv2_json_start(char *str, char *myJsonChar)
{

    // jsoncpp 解析json字符串
    cout << "收到的消息为: " << str << endl;

    Json::Reader reader(Json::Features::strictMode());
    Json::Value _root;
    std::string sBuffer = (char *)str;

    if (!reader.parse(sBuffer, _root))
    {
        cout << "json解析错误" << endl;
    }
    else
    {
        cout << "json解析成功" << endl;
    }
    
    // double转string
    stringstream position_x, position_y, position_lon, position_lat;
    string str_x, str_y, str_lon, str_lat;
    position_x << setprecision(12) << position[0];
    position_y << setprecision(12) << position[1];
    position_lon << setprecision(11) << position[2];
    position_lat << setprecision(12) << position[3];
    str_x = position_x.str();
    str_y = position_y.str();
    str_lon = position_lon.str();
    str_lat = position_lat.str();

    // jsoncpp 初始化json对象
    Json::Value myJson;
    myJson["runningSpeed"] = "1";
    myJson["recoveryRate"] = "60.3";
    myJson["x"] = str_x;
    myJson["y"] = str_y;
    myJson["lon"] = str_lon;
    myJson["lat"] = str_lat;
    myJson["id"] = _root["id"];
    myJson["status"] = "01";

    // jsoncpp json对象转换成字符串
    Json::FastWriter _Writer;
    std::string myJsonStr = _Writer.write(myJson);

    // string转char
    for (int i = 0; i < myJsonStr.length(); i++)
    {
        myJsonChar[i] = myJsonStr[i];
    }
    myJsonChar[myJsonStr.length() - 1] = '\0';
    printf("json_char: %s\n", myJsonChar);

    string target_x = _root.get("x","").asString();
    string target_y = _root.get("y","").asString();

    target[0] = std::stod(target_x);
    target[1] = std::stod(target_y);
};

/* 03指令的json处理函数
发送指令为{"runningSpeed":"1","recoveryRate":"60","x":"0","y":"0","lon":"0","lat":"0","status":"02"}
*/

void RobotSocket::recv3_json(char *myJsonChar)
{
    // double转string
    stringstream position_x, position_y, position_lon, position_lat;
    string str_x, str_y, str_lon, str_lat;
    position_x << setprecision(12) << position[0];
    position_y << setprecision(12) << position[1];
    position_lon << setprecision(11) << position[2];
    position_lat << setprecision(12) << position[3];
    str_x = position_x.str();
    str_y = position_y.str();
    str_lon = position_lon.str();
    str_lat = position_lat.str();

    // jsoncpp 初始化json对象
    Json::Value myJson;
    myJson["runningSpeed"] = "1";
    myJson["recoveryRate"] = "60";
    myJson["x"] = str_x;
    myJson["y"] = str_y;
    myJson["lon"] = str_lon;
    myJson["lat"] = str_lat;
    myJson["status"] = "02";

    // jsoncpp json对象转换成字符串
    Json::FastWriter _Writer;
    std::string myJsonStr = _Writer.write(myJson);

    // string转char
    for (int i = 0; i < myJsonStr.length(); i++)
    {
        myJsonChar[i] = myJsonStr[i];
    }
    myJsonChar[myJsonStr.length() - 1] = '\0';
    printf("json_char: %s\n", myJsonChar);
};

/* 04指令的json处理函数
发送指令为{"runningSpeed":"8.6","recoveryRate":"0","x":"5","y":"5","lon":"5","lat":"5","status":"01"}
*/

void RobotSocket::recv4_json(char *myJsonChar)
{
    // double转string
    stringstream position_x, position_y, position_lon, position_lat;
    string str_x, str_y, str_lon, str_lat;
    position_x << setprecision(12) << position[0];
    position_y << setprecision(12) << position[1];
    position_lon << setprecision(11) << position[2];
    position_lat << setprecision(12) << position[3];
    str_x = position_x.str();
    str_y = position_y.str();
    str_lon = position_lon.str();
    str_lat = position_lat.str();

    // jsoncpp 初始化json对象
    Json::Value myJson;
    myJson["runningSpeed"] = "8";
    myJson["recoveryRate"]= "0";
    myJson["x"] = str_x;
    myJson["y"] = str_y;
    myJson["lon"] = str_lon;
    myJson["lat"] = str_lat;
    myJson["status"] = "01";

    // jsoncpp json对象转换成字符串
    Json::FastWriter _Writer;
    std::string myJsonStr = _Writer.write(myJson);

    // string转char
    for (int i = 0; i < myJsonStr.length(); i++)
    {
        myJsonChar[i] = myJsonStr[i];
    }
    myJsonChar[myJsonStr.length() - 1] = '\0';
    printf("json_char: %s\n", myJsonChar);
};

