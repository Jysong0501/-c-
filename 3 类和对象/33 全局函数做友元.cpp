#include <iostream>
using namespace std;
#include <string>

class Building
{
    //goodgay全局函数是Building好朋友,可以访问Building中私有成员
    friend void goodgay(Building *building);
    public:
    Building()
    {
        m_sittingroom = "客厅";
        m_bedroom = "卧室";
    }

    public:
    string m_sittingroom;//客厅

    private:
    string m_bedroom;

};

//全局函数
void goodgay(Building *building)
{
    cout<<"好基友全局函数 正在访问 :"<<building ->m_sittingroom<<endl;
    cout<<"好基友全局函数 正在访问 :"<<building ->m_bedroom<<endl;
}

void test01()
{
    Building building;
    goodgay(&building);
}

int main()
{
    test01();

    return 0;
}