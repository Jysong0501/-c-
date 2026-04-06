#include <iostream>
using namespace std;
#include <string>

//类做友元

class Building;

class Goodgay
{
    public:
    Goodgay();

    void visit();//参观函数 访问Building中的属性

    Building *building;
};

class Building
{
    //Goodgay类是本类的好朋友,可以访问本类中私有的成员
    friend class Goodgay;
    public:
    Building();

    public:
    string m_sittingroom;//客厅

    private:
    string m_bedroom;
};

//类外写成员函数
Building::Building()
{
    m_sittingroom = "客厅";
    m_bedroom = "卧室";
}


Goodgay::Goodgay()
{
    //创建建筑物对象
    building = new Building;
}

void Goodgay::visit()
{
    cout<<"好基友类正在访问: "<<building->m_sittingroom<<endl;
    cout<<"好基友类正在访问: "<<building->m_bedroom<<endl;
}

void test01()
{
    Goodgay gg;
    gg.visit();
}
int main()
{
    test01();
    return 0;
}