#include <iostream>
using namespace std;
#include <stack>

//栈stack容器
//类比queue


void test01()
{

    stack<int>s;
    //特点:符合先进后出数据结构

    //入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    //只要栈不为空,查看栈顶,并且执行出栈操作

    cout<<"栈的大小为:"<<s.size()<<endl;
    while(!s.empty())
    {
        cout<<"栈顶元素为:"<<s.top()<<endl;

        //出栈
        s.pop();
    }
    cout<<"栈的大小为:"<<s.size()<<endl;


}

int main()
{

    test01();
    return 0;
}