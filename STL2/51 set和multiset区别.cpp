#include <iostream>
using namespace std;
#include <set>


//set和multiset区别
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
    set<int>s;

    pair<set<int>::iterator,bool>  ret = s.insert(10);
    if(ret.second)
    {
        cout<<"第一次插入成功"<<endl;
    }
    else{
        cout<<"第一次插入失败"<<endl;
    }


    ret = s.insert(10);


   
    if(ret.second)
    {
        cout<<"第一次插入成功"<<endl;
    }
    else{
        cout<<"第一次插入失败"<<endl;
    }




    multiset<int>ms;
    ms.insert(10);
    ms.insert(10);

    for(multiset<int>::const_iterator it = ms.begin();it !=ms.end();it ++)
    {
        cout<<* it <<" ";
    }
    cout<<endl;
}

//交换

int main()
{

    test01();
    return 0;
}