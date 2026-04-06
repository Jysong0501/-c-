#include <iostream>
using namespace std;

class Building;
class Goodgay
{
    public:

    Goodgay();

    void visit1();//让visit函数可以访问Building中私有成员
    void visit2();//让visit函数不可以访问Building中私有成员
    Building *building;

};

class Building
{
    //告诉编译器 Goodgay类下的isit成员函数作为本来的好朋友,可以访问私有成员
    friend void Goodgay::visit1();

    public:
    Building();
    public:

    string m_sittingroom;//客厅

    private:
    string m_bedroom;//卧室
};

//类外实现成员函数
Building::Building()
{
    m_sittingroom = "客厅";
    m_bedroom = "卧室";
}
Goodgay::Goodgay()
{
    building = new Building;
}


void Goodgay::visit1()
{
    cout<<"visit函数正在访问 : "<<building ->m_sittingroom<<endl;
    cout<<"visit函数正在访问 : "<<building ->m_bedroom<<endl;
}
void Goodgay::visit2()
{
    cout<<"visit函数正在访问 : "<<building ->m_sittingroom<<endl;
    //cout<<"visit函数正在访问 : "<<building ->m_bedroom<<endl;
}


void test01()
{
    Goodgay gg;
    gg.visit1();
    gg.visit2();
}
int main()
{

    test01();
    return 0;
}