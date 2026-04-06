#include <iostream>
using namespace std;

//利用多态实现计算机
//1.组织结构清晰
//2.可读性强
//3.对于前期和后期拓展以及维护性高
//实现计算器抽象类
class Abstractcalculator
{
    public:
    virtual int getresult()
    {
        return 0;
    }

    int m_num1;
    int m_num2;
};

//加法计算器
class Addcalculator :public Abstractcalculator
{
    public:

    virtual int getresult()
    {
        return m_num1 + m_num2;
    }
};

//减法计算器类

class Subcalculator :public Abstractcalculator
{
    public:

    virtual int getresult()
    {
        return m_num1 - m_num2;
    }
};

class Mulcalculator :public Abstractcalculator
{
    public:

    virtual int getresult()
    {
        return m_num1 * m_num2;
    }
};



void test01()
{
    //多态使用条件
    //父类指针或者引用指向子类对象

    //加法运算
    Abstractcalculator *abc = new Addcalculator;
    abc->m_num1 = 10;
    abc->m_num2 = 10;

    cout<<abc->m_num1<<"+"<<abc->m_num2<<"="<<abc->getresult()<<endl;

    //用完后记得销毁
    delete abc;

    //减法运算
    abc = new Subcalculator;
    abc->m_num1 = 10;
    abc->m_num2 = 10;

    cout<<abc->m_num1<<"-"<<abc->m_num2<<"="<<abc->getresult()<<endl;
    delete abc;


    //乘法运算
    abc = new Mulcalculator;
    abc->m_num1 = 10;
    abc->m_num2 = 10;

    cout<<abc->m_num1<<"*"<<abc->m_num2<<"="<<abc->getresult()<<endl;
    delete abc;

}

int main()
{

    test01();

    return 0;
}