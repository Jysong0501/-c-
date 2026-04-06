#include <bits/stdc++.h>
using namespace std;


//string 求子串
void test01()
{
    string str = "abcdefg";
    string subStr = str.substr(3,4);

    cout<<"subStr = "<<subStr<<endl;
}

//实用操作
void test02()
{
    string email= "zhangsan@sina.com";

    //从邮箱地址中获取用户名信息

    int pos = email.find("@");
    string username = email.substr(0,pos);//从0开始截取pos个;

}
int main()
{

    test01();
    return 0;
}