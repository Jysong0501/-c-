#include <iostream>
using namespace std;
#include <deque>

#include <algorithm>//标准算法头文件

void printdeque(const deque <int>&d)
{
    for(deque<int>::const_iterator it = d.begin();it!=d.end();it++)
    {
        //*it = 100 ; 容器中的数据不可以修改了
        cout<<*it<<" ";

    }
    cout<<endl;
}
//deque 构造函数
void test01()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }
    printdeque(d1);


    deque<int>d2(d1.begin(),d1.end());
    printdeque(d2);

    deque<int>d3(10,100);
    printdeque(d3);

    deque<int>d4(d3);
    printdeque(d4);
}


//deque容器赋值操作

void test02()
{
    deque<int>d01;
    for(int i=0;i<10;i++)
    {
        d01.push_back(i);
    }
    printdeque(d01);

    //operator=赋值
    deque<int>d02;
    d02 = d01;
    printdeque(d02);

    //assign赋值
    deque<int>d03;
    d03.assign(d01.begin(),d01.end());
    printdeque(d03);

    deque<int>d04;
    d04.assign(10,100);
    printdeque(d04);
}



//deque容器大小操作
void test03()
{
    deque<int>d1;
    for(int i =0;i<10;i++)
    {
        d1.push_back(i);
    }
    printdeque(d1);

    if(d1.empty())
    {
        cout<<"d1为空"<<endl;
    }
    else
    {
        cout<<"d1不为空"<<endl;
        cout<<"d1的大小为:"<<d1.size()<<endl;
        //deque没有容量概念
    }

    //重新定义大小
    d1.resize(15,1);
    printdeque(d1);


    d1.resize(5);
    printdeque(d1);
}



// deque容器 插入和删除
//两端操作
void test04()
{
    deque<int>d1;

    //尾插
    d1.push_back(10);
    d1.push_back(20);

    //头插
    d1.push_front(100);
    d1.push_front(200);

    printdeque(d1);

    //尾删
    d1.pop_back();

    //头删
    d1.pop_front();

    printdeque(d1);
}

void test05()
{
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    printdeque(d1);


    //insert插入
    d1.insert(d1.begin(),100);
    printdeque(d1);
    d1.insert(d1.begin(),2,10000);
    printdeque(d1);



    //按照区间进行插入
    deque<int>d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(),d2.begin(),d2.end());
    printdeque(d2);

}

void test06()
{
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_front(100);
    d1.push_front(200);
    
    //删除
    deque<int>::iterator it = d1.begin();
    it++;
    d1.erase(it);
    printdeque(d1);



    //按区间删除
    /* d1.erase(d1.begin(),d1.end());
    printdeque(d1); */

    d1.clear();
    printdeque(d1);



}

//deque容器 数据存取

void test07()
{
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(100);
    d.push_back(200);
    d.push_back(300);

    //通过[]方式访问元素
    for(int i=0;i<d.size();i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;


    //通过at方式访问元素
    for(int i=0;i<d.size();i++)
    {
        cout<<d.at(i)<<" ";

    }
    cout<<endl;

    cout<<"第一个元素为: "<<d.front()<<endl;
    cout<<"最后一个元素为"<<d.back()<<endl;


    
}



//deque排序

void test08()
{
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(100);
    d.push_back(200);
    d.push_back(300);

    //300 200 100 10 20 30
    cout<<"排序前:"<<endl;
    printdeque(d);

    //排序  默认排序规则 从小大大升序
    //对于支持随机访问的迭代器的容器,都可以用sort算法直接对其进行排序
    //vector容器也可以利用sort进行排序
    sort(d.begin(),d.end());
    cout<<"排序后:"<<endl;
    printdeque(d);
    

}
int main()
{

    cout<<"test01 :";
    test01();
    cout<<endl<<"test02 :"<<endl;
    test02();
    cout<<endl<<"test03 :"<<endl;
    test03();
    cout<<endl<<"test04 :"<<endl;
    test04();
    cout<<endl<<"test05 :"<<endl;
    test05();
    cout<<endl<<"test06 :"<<endl;
    test06();
    cout<<endl<<"test07 :"<<endl;
    test07();
    cout<<endl<<"test08 :"<<endl;
    test08();


}