#include <iostream>
using namespace std;

//类对象作为类成员

//手机类
class phone
{
    public:
    phone(string pname)
    {
        m_pname = pname;
        cout<<"Phone的构造函数调用"<<endl;
    }

    //手机品牌名称
    string m_pname;

    ~phone()
    {
        cout<<"Phone的构造函数调用"<<endl;
    }

};

//人类
class Person
{

    public:
    //Phone m_phone = pname  隐式转换法
    Person (string name,string pname):m_name(name),m_phone(pname)
    {
        cout<<"Person的构造函数调用"<<endl;
    }
    

    ~Person()
    {
        cout<<"Person的构造函数调用"<<endl;
    }
    //姓名
    string m_name;
    //手机
    phone m_phone;
};

//当其他类对象作为本类成员,构造时候先构造对象,再构造自身,析构的顺序与构造相反
void test01()
{
    Person p("张三","苹果MAX");

    cout<<p.m_name<<"拿着"<<p.m_phone.m_pname<<endl;
}
int main()
{
    test01();

    return 0;
}