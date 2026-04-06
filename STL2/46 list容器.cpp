#include <iostream>
using namespace  std;
#include <list>
#include <algorithm>
//链表优点:可以对任意位置进行快速插入和删除元素
//链表缺点:容器遍历速度,没有数组快;占用空间比数组大

void printlist(list <int>&L)
{
    for(list<int>::const_iterator it = L.begin();it !=L.end();it ++)
    {
        cout<<* it <<" ";
    }
    cout<<endl;
}


//list函数构造
void test01()
{
    //创建list容器
    list<int>L1;//默认构造

    //添加数据
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    //遍历容器
    printlist(L1);

    //区间方式构造  
    list<int>L2(L1.begin(),L1.end());
    printlist(L2);

    //拷贝构造
    list<int>L3(L2);
    printlist(L3);

    //n个elem
    list<int>L4(10,1000);
    printlist(L4);

}

//list容器赋值和互换
//赋值
void test02()
{
    list<int>L1;

    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    printlist(L1);

    list<int>L2;
    L2 = L1;//operator = 赋值
    printlist(L2);


    list<int>L3;
    L3.assign(L2.begin(),L2.end());
    printlist(L3);

    list<int>L4;
    L4.assign(10,100);
    printlist(L4);

}

//交换
void test03()
{
    list<int>L1;

    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    list<int>L2;
    L2.assign(10,100);

    cout<<"交换前: "<<endl;
    printlist(L1);
    printlist(L2);

    L1.swap(L2);
    cout<<"交换后: "<<endl;
    printlist(L1);
    printlist(L2);
}



//list容器大小操作
void test04()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    printlist(L1);

    //判断容器是否为空
    if(L1.empty())
    {
        cout<<"L1为空"<<endl;
    }
    else
    {
        cout<<"L1不为空"<<endl;
        cout<<"L1的元素个数为:"<<L1.size()<<endl;
    }

    //重新指定大小
    L1.resize(10);
    L1.resize(10,10000);
    printlist(L1);

    L1.resize(2);
    printlist(L1);

}


//list插入和删除
void test05()
{
    /*
    push_back(elem);        //在容器尾部加入一个元素
    pop_back()  ;       //删除容器中最后一个元素
    push_front(elem);       //在容器开头插入一个元素
    pop_front();        //从容器开头移除第一个元素
    insert(pos,elem);       //在pos位置插elem元素的拷贝，返回新数据的位置。
    insert(pos,n,elem)      ;//在pos位置插入n个elem数据，无返回值。
    insert(pos,beg,end);        //在pos位置插入[beg,end]区间的数据，无返回值。
    clear();//移除容器的所有数据
    erase(beg,end);     //删除[beg,end]区间的数据，返回下一个数据的位置。
    erase(pos);     //删除pos位置的数据，返回下一个数据的位置。
    remove(elem);       //删除容器中所有与elem值匹配的元素。
    */

    list<int>L;

    //尾插
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);

    printlist(L);

    //头插
    L.push_front(100);
    L.push_front(200);
    L.push_front(300);

    printlist(L);

    //尾删
    L.pop_back();
    printlist(L);

    //头删
    L.pop_front();
    printlist(L);

    //insert插入
    list<int>::iterator it = L.begin();
    L.insert(++it,1000);
    printlist(L);

    //删除
    it = L.begin();
    L.erase(it);

    printlist(L);

    //移除
    L.push_back(10000);
    printlist(L);
    L.remove(10000);//删除所有此元素
    printlist(L);

    //清空
    L.clear();
    printlist(L);
}

//list容器 数据存取
void test06()
{
    list<int>L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    //L1[0] 不可以用[]访问list容器中元素
    //L1.at(0)  不可以用at方式访问list容器中的元素

    //原因是list本质是链表,不是用连续线性空间存储数据,迭代器也是不支持随机访问的

    cout<<"第一个元素为:"<<L1.front()<<endl;
    cout<<"最后一个元素为:"<<L1.back()<<endl;

    //验证迭代器是不支持随机访问的
    list<int>::iterator it = L1.begin();
    //it = it+1;   不支持随机访问
    it++;//支持双向
    it--;//
}


//list容器 反转和排序
void test07()
{
    //反转
    list<int>L1;

    L1.push_back(20);
    L1.push_back(10);
    L1.push_back(50);
    L1.push_back(40);
    L1.push_back(30);

    cout<<"反转前:"<<endl;
    printlist(L1);

    //反转
    L1.reverse();
    cout<<"反转后:"<<endl;
    printlist(L1);
    
}


bool myCompare(int v1,int v2)
{
    //降序 就让第一个数>第二个数
    return v1>v2;
}
//排序
void test08()
{
    list<int>L1;

    L1.push_back(20);
    L1.push_back(10);
    L1.push_back(50);
    L1.push_back(40);
    L1.push_back(30);

    //排序
    cout<<"排序前: "<<endl;
    printlist(L1);


    
    //所有不支持随机访问迭代器的容器,不可以用标准算法
    //不支持随机访问迭代器的容器,内部会提供对应一些算法
    //sort(L1.begin(),L1.end());

    L1.sort();//默认排序规则,从小到大,升序
    cout<<"排序后: "<<endl;
    printlist(L1);

    L1.sort(myCompare);
    printlist(L1);
}





class Person
{
    public:
    Person(string name,int age,int height)
    {
        this -> m_name = name;
        this -> m_age = age;
        this ->m_height = height;
    }

    string m_name;
    int m_age;
    int m_height;

};
bool comparePerson(Person &p1,Person &p2)
{
    //按照年龄 升序
    if(p1.m_age == p2.m_age)
    {
        return p1.m_height >p2.m_height;
    }
    return p1.m_age < p2.m_age;
}
void test09()
{
    list<Person>L;//创建容器

    //准备数据
    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 170);
    Person p4("赵云", 25, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);

    //向容器中插入数据
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);


    for(list<Person>::iterator it =L.begin();it!=L.end();it++)
    {
        cout<<" 姓名: "<<(*it).m_name<<" 年龄: "<<it->m_age<<" 身高: "<<it->m_height<<endl;
    }

    //排序
    cout<<"______________________"<<endl;
    cout<<"排序后:"<<endl;

    L.sort(comparePerson);
    for(list<Person>::iterator it =L.begin();it!=L.end();it++)
    {
        cout<<" 姓名: "<<(*it).m_name<<" 年龄: "<<it->m_age<<" 身高: "<<it->m_height<<endl;
    }
    
}
main() 
{
    cout<<endl<<"test01 :  //list构造"<<endl<<endl;
    test01();
    cout<<endl<<"test02 :  //list赋值"<<endl<<endl;
    test02();
    cout<<endl<<"test03 :  //list交换"<<endl<<endl;
    test03();
    cout<<endl<<"test04 :  //list函数大小"<<endl<<endl;
    test04();
    cout<<endl<<"test05 :  //list插入和删除"<<endl<<endl;
    test05();
    cout<<endl<<"test06 :  //list插入和删除"<<endl<<endl;
    test06();
    cout<<endl<<"test07 :  //list插入和删除"<<endl<<endl;
    test07();
    cout<<endl<<"test08 :  //list插入和删除"<<endl<<endl;
    test08();
    cout<<endl<<"test09 :  //list插入和删除"<<endl<<endl;
    test09();
}
