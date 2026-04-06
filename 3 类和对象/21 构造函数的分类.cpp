#include <iostream>
using namespace std;

//1.构造函数的分类及调用
//分类
//  按照参数分类    无参构造(默认构造) 和 有参构造
//  按照类型分类    普通构造   拷贝构造
class Person
{

    public:
    //构造函数
    Person()
    {
        cout<<"Person的无参构造函数调用"<<endl;
    }

    Person(int a)
    {
        age = a;
        cout<<"Person的有参构造函数调用"<<endl;
    }


    //拷贝构造函数
    Person(const Person &p)
    {
        //将传入的人身上的所有属性,拷贝到我身上
        cout<<"Person的拷贝函数构造调用"<<endl;
        age = p.age;
    }


    ~Person()
    {
        cout<<"Person的析构函数调用"<<endl;
    }

    int age;
};


//调用
void test01()
{
    //1.括号法(常用)
    Person p1;//默认构造函数调用
    cout<<endl;
    Person p2(10);//有参构造函数调用
    cout<<endl;
    Person p3(p2);//拷贝函数构造
    cout<<endl;


    //注意事项
    //调用默认构造函数时候,不要加()
    //因为下面这行代码,编译器会认为是一个函数的声明,不会认为在创建对象
   /*
    Person p1();
    void func(); 
    */

    cout<<"p2的年龄为:"<<p2.age<<endl;
    cout<<"p3的年龄为:"<<p2.age<<endl;
    cout<<endl;

    //2.显示法
    Person p4;
    Person p5 = Person(10);//有参构造
    cout<<endl;
    Person p6 = Person(p5);//拷贝构造
    cout<<"mark1:"<<endl;
    Person(10); //匿名对象  特点:当前执行结束后,系统会立即回收调匿名对象
    cout<<"aa"<<endl;

    //注意事项2
    //不要利用拷贝构造函数  初始化匿名对象  编译器会认为Person(p3) ===Person P3;对象声明
//  Person(p6);


    //3.隐式转换法
    Person p7 = 10; //相当于写了  Person p7 = Person(10);
    cout<<endl;
    cout<<endl;
    Person p8 = p7;//拷贝构造
    cout<<endl;
}
int main()
{
    test01();
}