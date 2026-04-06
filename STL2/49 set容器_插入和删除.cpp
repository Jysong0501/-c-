#include <iostream>
using namespace std;
#include <set>


//set容器 插入和删除
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
    s1.insert(30);
    s1.insert(10);
    s1.insert(20);
    s1.insert(40);

    //打印容器
    printset(s1);

    //删除
    s1.erase(s1.begin());
    printset(s1);

    //删除重载版本
    s1.erase(30);
    printset(s1);

    //清空
    s1.erase(s1.begin(),s1.end());
    //或
    s1.clear();
    printset(s1);

}


int main()
{

    test01();
    return 0;
}