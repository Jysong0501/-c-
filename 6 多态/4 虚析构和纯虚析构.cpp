#include <iostream>
using namespace std;
#include <string>
//虚析构和纯虚析构

class Animal
{
    public:
    Animal()
    {
        cout<<"Animal构造函数调用"<<endl;

    }
    //利用许析构可以解决 父类指针释放子类对象是不干净的问题
    // virtual ~Animal()
    // {
    //     cout<<"Animal析构函数调用"<<endl;
    // }

     //纯虚析构     需要声明也需要实现
     //有了纯虚析构之后,这个类也属于抽象类,无法实例化对象
     virtual ~Animal() = 0;

    //纯虚函数
    virtual void speak() = 0;

};

Animal::~Animal()
{
    cout<<"Animal纯虚析构函数调用"<<endl;
}
class Cat :public Animal
{
    public:
    Cat(string name)
    {
        cout<<"Cat构造函数调用"<<endl;
        m_name = new string (name);
    }

    virtual void speak()
    {
        cout<<"小猫在说话"<<endl;
    }

    ~Cat ()
    {
        if(m_name != NULL)
        {
            cout<<"Cat析构函数调用"<<endl;
            delete m_name;
            m_name = NULL;
        }
    }
    string *m_name;
};

void test01()
{
    Animal *animal = new Cat("Tom");
    animal ->speak();
    //父类指针在析构时候  不会调用 子类中析构函数,导致子类如果有堆区属性,出现内存泄漏
    delete animal;
}

int main()
{
    test01();

    return 0;
}