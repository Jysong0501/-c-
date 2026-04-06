#include <iostream>
using namespace std;
#include <set>


//set容器 大小和交换
void printset(set <int>&s)
{
    for(set<int>::const_iterator it = s.begin();it !=s.end();it ++)
    {
        cout<<* it <<" ";
    }
    cout<<endl;
}

void test01()
{
    set<int>s1;

    //插入数据
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    //打印容器
    printset(s1);

    if(s1.empty())
    {
        cout<<"s1为空"<<endl;
    }
    else
    {
        cout<<"s2不为空"<<endl;
    }
}

//交换
void test02()
{
    set<int>s1;

    //插入数据
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    set<int>s2;

    //插入数据
    s2.insert(100);
    s2.insert(200);
    s2.insert(300);
    s2.insert(400);
    cout<<"交换前: "<<endl;
    printset(s1);
    printset(s2);

    cout<<"交换后: "<<endl;
    s1.swap(s2);
    printset(s1);
    printset(s2);

}
int main()
{

    test01();
    return 0;
}