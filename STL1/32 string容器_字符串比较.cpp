#include <bits/stdc++.h>
using namespace std;


void test01()
{
    string str1 ="xello";
    string str2 = "hello";

    if(str1.compare(str2) == 0)
    {
        cout << "str1 等于 str2";
    } 
    else if(str1.compare(str2) > 0)//遇到第一对不相等的字符便停止比较
    {
        cout<< "str1 大于 str2";
    }
    else if(str1.compare(str2) < 0)
    {
        cout<< "str1 小于 str2";
    }
}
int main()
{

    test01();
    return 0;
}