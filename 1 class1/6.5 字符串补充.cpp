#include <iostream>
using namespace std;
int main()
{

    char test01[]="s";    //ture      test01为字符串常量（使用双引号）
    //char test2="s"     //false
    char test03='s';      //ture    test03为字符常量（使用单引号）



    //1.
    string s;//定义一个名字为s的字符串常量
    string str;
    s += str; 
    //或者
    s.append(str);//在字符串s后面拼接str
    s.append(str,10);
    return 0;
}