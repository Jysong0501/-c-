#include <bits/stdc++.h>
using namespace std;
//设计一个圆类,求圆的周长
const double PI = 3.14;
//class表示设计一个类,类后面紧跟着的就是类名称
class Circle
{
    //访问权限
    //公共权限
    public:
    //属性
    //半径
    int m_r;
    //行为
    //获取圆的周长
    double calculateZC()
    {
        return 2*PI*m_r;
    }

};
class Person
{
    //写入共有
    public:
    void setname(string name)
    {
        m_name=name;
    }
    string getname()
    {
        return m_name;
    }
    int getage()
    {
        return age;
    }
    //属性私有
    private:
    string m_name;
    int age=18;
    string idol;



};

int main()
{
     //通过圆类,穿件具体的圆(对象)
    //实例化(通过一个类  创建一个对象的过程)
    Circle c1;
    //给圆对象 的属性进行赋值
    c1.m_r = 10;

    cout <<"圆的周长为:"<<c1.calculateZC()<<endl;
 
    Person p;
    p.setname("张三");
    cout<<p.getname()<<endl;
    cout<<p.getage();
}