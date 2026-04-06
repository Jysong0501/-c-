#include <bits/stdc++.h>
using namespace std;
#include <string>
//string 字符串拼接


void test01()
{
    string str1="I";
    str1 +=" Love playing games ";//追加字符串
    cout<<"str1 ="<<str1<<endl;
    str1 +=':';//追加字符
    cout<<"str1 ="<<str1<<endl;

    string str2 = "LOL DNF";
    str1 += str2;
    cout<<"str1= "<<str1<<endl;

    string str3 = "I";
    str3.append(" love ");
    cout<<"str3 ="<< str3 <<endl;

    str3.append("game abcde",5);//把字符串的前n个拼接到该字符串(str3)的末尾
    cout<<"str3 ="<< str3 <<endl;

    str3.append(str2);
    cout<<"str3 ="<< str3 <<endl;

    str3.append(str2,0,3);//从str2 第0 个字符开始截取 3 个字符放到字符串(str3)末尾
    cout<<"str3 ="<< str3 <<endl;
    str3.append(str2,4,3);//从str2 第4 个字符开始截取 3 个字符放到字符串(str3)末尾
    cout<<"str3 ="<< str3 <<endl;
    //字符串的第一个字符算作 第0个

    
}
int main()
{
    test01();

    return 0;
}