#include <iostream>
using namespace std;

//动物类

class Animals
{
    public:
    int m_age;
};

//利用虚继承  解决菱形继承的问题
//继承之前  加上关键字 virtual变为虚继承
//Animal类称为 虚基类
//羊类
class Sheep:virtual public Animals
{};

//驼类
class Tuo : public Animals{};

//羊驼类

class SheepTuo :public Sheep,public Tuo
{

};

void test01()
{
    SheepTuo st;
    st.Sheep::m_age = 18;
    st.Tuo::m_age = 28;

    //当菱形继承,两个父类拥有相同的数据,需要加以作用域区分
    cout<<"st.Sheep::m_age = "<<st.Sheep::m_age<<endl;
    cout<<"st.Tuo::m_age = "<<st.Sheep::m_age<<endl;

    //这份数据我们知道  只要有一份就可以,菱形继承导致数据有两份,资源浪费
}
int main()
{

    test01();
    return 0;
}