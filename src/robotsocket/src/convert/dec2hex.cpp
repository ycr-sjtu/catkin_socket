#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include"robotsocket/harvestingRobotClient.h"

using namespace std;
 
//i要转化的十进制整数，width转化后的宽度，位数不足则补0 
string dec2hex(int i, int width)
 {
    stringstream ioss; //定义字符串流 
    string s_temp; //存放转化后字符
    ioss << hex << i; //以十六制形式输出 
    ioss >> s_temp; 
    if (width > s_temp.size()) { 
        string s_0(width - s_temp.size(), '0'); //位数不够则补0                 
        s_temp = s_0 + s_temp; //合并
    } 
    string s = s_temp.substr(s_temp.length() - width,   s_temp.length()); //取右width位 
    return s;
 }    
 
//
int char2bits(char ch)
{
    int bits = 0;
    if (ch >= 'a' && ch <= 'z') 
    {
        bits = ch - 'a' + 10;
    } 
    else if (ch >= 'A' && ch <= 'Z') 
    {
        bits = ch - 'A' + 10;
    } 
    else if (ch >= '0' && ch <= '9') 
    {
        bits = ch - '0';
    } 
    else
    {
        bits = -1;
    }
    return bits;
}
 
int hex2bytes(char *hex, char *bytes) 
{
    int len = strlen(hex);
    int nbytes = len/2;
 
    for (int n = 0; n < nbytes; ++ n) 
    {
        int lndx = n * 2;
        int rndx = lndx + 1;
        int lbits = char2bits(hex[lndx]);
        int rbits = char2bits(hex[rndx]);
        if (lbits == -1 || rbits == -1)
        {
            return -1;
        }
        bytes[n] = (lbits << 4) | rbits;
    }
 
    return nbytes;
}

//
void int2hex(int i, int length, char * hex)
{
	string s = dec2hex(i,length);
    char res[length];
    for(int i=0;i<length;i++){
        res[i]=s[i];
    }
    res[length]='\0';
    int nbytes = hex2bytes(res,hex);
    cout<<"int2hex: ";
    for (int i = 0 ; i < nbytes; ++ i) 
    {
        printf("%hhx ", hex[i]);
     }
    cout<<endl;
}

int main(){
    int i,length;
    while(cin>>i>>length){
        char hex[length];
        int2hex(i,length,hex);
    }
}