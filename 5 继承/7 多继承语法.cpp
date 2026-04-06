#include <iostream>
using namespace std;

//多继承语法

class Base1
{
    public:
    Base1()
    {
        m_a = 100;
    }

    int m_a ;
};

class Base2
{
    public:
    Base2()
    {
        m_a = 100;
    }

    int m_a ;
};
//子类  需要集成Base1和Base2
class Son:public Base1,public Base2
{
public:


    int m_c;
    int m_d;

};

void test01()
{
    Son s;
    cout<<"sizeof Son = "<<sizeof(s)<<endl;

    //当父类中出现同名成员,需要加作用域区分
    cout<<"Base1::m_a = "<<s.Base1::m_a<<endl;
    cout<<"Base2::m_a = "<<s.Base2::m_a<<endl;
}
int main()
{
    test01();

    return 0;
}