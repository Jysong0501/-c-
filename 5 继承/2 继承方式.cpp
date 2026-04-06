#include <iostream>
using namespace std;

//继承方式

//公共继承
class Basel
{
    public:
    int m_a;

    protected:
    int m_b;

    private:
    int m_c;
};

class Son1:public Basel
{
    public:
    void func()
    {
        m_a = 10;//父类中的公共权限,到子类中依然是公共权限
        m_b = 10;//父类中的保护权限成员,到子类中依然是保护权限
        //m_c = 10;//父类中的私有权限成员,子类访问不到
    }
};

class Son2:protected Basel
{
    public:
    void func()
    {
        m_a = 100;//父类中的公共权限,到子类中变为保护权限
        m_b = 100;//父类中的保护权限成员,到子类中依然是保护权限
        //m_c = 10;//父类中的私有权限成员,子类访问不到
    }
};

class Son3:private Basel
{
    public:
    void func()
    {
        m_a = 100;//父类中的公共权限,到子类中 变为 私有成员
        m_b = 100;//父类中的保护权限成员,到子类中 变为 私有成员
        //m_c = 10;//父类中的私有成员,子类访问不到
    }
};



class GrandSon3 :public Son3
{
    public:
    void func()
    {
        //m_a = 1000; //到了Son3中 m_a变为私有,即使是儿子,也是访问不到
        //m_b = 1000; //到了Son3中 m_a变为私有,即使是儿子,也是访问不到
    }
};
class GrandSon1 :public Son1
{
    public:
    void func()
    {
        m_a = 1000; //到了Son3中 m_a变为私有,即使是儿子,也是访问不到
        m_b = 1000; //到了Son3中 m_a变为私有,即使是儿子,也是访问不到
    }
};
void test01()
{
    Son1 s1;
    s1.m_a = 100;
    //s1.m_b = 100;//到Son1中 m_b是保护权限,类外访问不到

}

void test02()
{
    Son2 s1;
    //s1.m_a = 1000;//在Son2中,m_a变为保护权限,因此类外访问不到
    //s1.m_b = 1000;//在Son2中,m_b保护权限,不可以访问
}

void test03()
{
    Son3 s1;
    //s1.m_a = 1000;//到Son3中 变为 私有成员
    //s1.m_b = 1000;//到Son3中 变为 私有成员
    //s1.m_c = 1000;//到Son3中 变为 私有成员
}