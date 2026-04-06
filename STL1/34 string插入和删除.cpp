#include <bits/stdc++.h>
using namespace std;


//字符串 插入和删除
void test01()
{
    string str = "hello";

    //插入
    str.insert(1,"111");
    cout<<"str = "<<str<<endl;

    //删除
    str.erase(1,3);
    cout<<"str = "<<str<<endl;


    //*插入和删除的起始下标都是从0开始
}
int main()
{
    test01();

    return 0;
}