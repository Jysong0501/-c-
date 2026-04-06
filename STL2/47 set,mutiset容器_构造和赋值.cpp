#include <iostream>
using namespace std;
#include <set>

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


    //插入数据 只有inset方式
    s1.insert(10);
    s1.insert(40);
    s1.insert(30);
    s1.insert(20);
    s1.insert(30);

     //遍历容器
     //set容器特点:所有元素插入时候自动被排序
     //set容器不允许插入重复值
     printset(s1);


     //拷贝构造
     set<int>s2(s1);
     printset(s2);

     //赋值
     set<int>s3;
     s3 = s2;
}
int main()
{


    return 0;
}