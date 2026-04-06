#include <iostream>
using namespace std;

//对象的初始化和清理
//1.构造函数  尽心给出实话操作

class Person
{
    public:
    //1.1.构造函数
    //没有返回值 不用写void
    //函数名与类名相同
    //构造函数可以有参数,可以发生重载
    //创建对象的时候,构造函数会自动调用,而且只调用一次
    Person()
    {
        cout<<"Person 构造函数的调用1"<<endl;

    }



    //2.析构函数 进行清理的操作
    //没有返回值  不写void
    //函数名和类名相同 在名称前加~
    //析构函数可以有参数的,不可以发生重载
    //对象在销毁前,会自动调用个析构函数,而且只会调用一次
    ~Person()
    {
        cout<<"Person 的析构函数调用1"<<endl;
    }
};



//构造和析构都是必须有的实现,如果我们不提供,编译器会实现一个空实现的构造和析构
void test01()
{
    Person P;//在栈上的数据,test01执行完毕后,释放这个对象
    Person P2;
}


int main()
{
    test01();
    cout<<"1"<<endl;
    cout<<endl;
    Person P;//析构函数在结束后被调用


    system("pause");
    return 0;
    
}