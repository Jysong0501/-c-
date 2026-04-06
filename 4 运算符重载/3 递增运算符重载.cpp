#include <iostream>
using namespace std;


//重载递增运算符

//自定义整形
class Myinteger
{
    friend ostream & operator<<(ostream& cout,Myinteger myint); 
    public:
    Myinteger()
    {
        m_num = 0;
    }

    //重载前置++运算符  返回用引用是为了一直对一个数据进行递增操作
    Myinteger& operator++()
    {
        //先进性++运算
        m_num++;

        //再将自身做返回
        return *this;
    }
    //重载后置++运算符
    Myinteger operator++(int )//int 代表占位参数,可以用于区分前置和后置递增
    {
        //先 记录当时结果
        Myinteger temp = *this;
        //后 递增
        m_num++;
        //最后将记录结果做返回
    
        return temp;
}

    private:

    int m_num;
};


//重载<<运算符
ostream & operator<<(ostream& cout,Myinteger myint)
{
    cout<<myint.m_num;
    return cout; 
}
void test01()
{
    Myinteger myint;
    cout<<++myint<<endl;
}

void test02()
{
    Myinteger myint;
    cout <<myint++<<endl;
    cout <<myint<<endl;
}
int main()
{

    cout<<"T1: "<<endl;
    test01();
    cout<<"T2: "<<endl;
    test02();

    return 0;
}