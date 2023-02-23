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

    // jsoncpp 初始化json对象
    Json::Value myJson;
    myJson["runningSpeed"] = "1";
    myJson["recoveryRate"] = "60.3";
    myJson["x"] = "1";
    myJson["y"] = "1";
    myJson["lon"] = "1";
    myJson["lat"] = "1";
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

// 修改：
// 输出double target_x, double target_y，输入x, y, lon, lat
void RobotSocket::recv2_json_start(char *str, char *myJsonChar, double * target_x, double * target_y)
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

    // jsoncpp 初始化json对象
    Json::Value myJson;
    myJson["runningSpeed"] = "1";
    myJson["recoveryRate"] = "60.3";
    myJson["x"] = "1";
    myJson["y"] = "1";
    myJson["lon"] = "1";
    myJson["lat"] = "1";
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

    string x = _root.get("x","").asString();
    string y = _root.get("y","").asString();

    * target_x = std::stod(x);
    * target_y = std::stod(y);
};

/* 03指令的json处理函数
发送指令为{"runningSpeed":"1","recoveryRate":"60","x":"0","y":"0","lon":"0","lat":"0","status":"02"}
*/

void RobotSocket::recv3_json(char *myJsonChar)
{

    // jsoncpp 初始化json对象
    Json::Value myJson;
    myJson["runningSpeed"] = "1";
    myJson["recoveryRate"] = "60";
    myJson["x"] = "0";
    myJson["y"] = "0";
    myJson["lon"] = "0";
    myJson["lat"] = "0";
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
    // jsoncpp 初始化json对象
    Json::Value myJson;
    myJson["runningSpeed"] = "8";
    myJson["recoveryRate"]= "0";
    myJson["x"] = "5";
    myJson["y"] = "5";
    myJson["lon"] = "5";
    myJson["lat"] = "5";
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

