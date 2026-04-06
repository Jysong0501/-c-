#include <iostream>
using namespace std;

//左移运算符重载

class Person
{
    friend ostream & operator<<(ostream &cout,Person &p) ;
    public:

    Person(int a,int b)
    {
        m_a = a;
        m_b = b;
    }
    //利用成员函数重载 左移运算符   简化版本  (p)<<cout
    //不会利用成员函数重载<<运算符,因为无法实现 cout 在左侧
    //void operator<<(Person &p)
    
    private:
    int m_a;
    int m_b;

};
//只能利用全局函数重载左移运算符
ostream & operator<<(ostream &cout,Person &p) //本质 operator<<(cout , p)  简化cout<<p
{
    cout <<"m_a = "<<p.m_a<<" m_b = "<<p.m_b<<endl;
    return cout;
}


void test01()
{
    Person p(10,10);
    /* p.m_a = 10;
    p.m_b = 10; */

    cout<<p<<endl;
}
int main()
{
    test01();
    return 0;
}