#include <bits/stdc++.h>
using namespace std;
int main()
{
    //一维数组名称用途
    /*
    *可以统计整个数组在内存中的长度 sizeof(arr)
    *可以获取数组首元素地址  cout<<arr<<endl;

    */
   int arr[]={10,20,30,40,50};
    cout<<sizeof(arr)<<endl; //4*5=20
    cout<<"数组中元素个数为:"<<sizeof(arr)/sizeof(arr[0])<<endl; //20/4=5
    cout<<arr<<endl; //数组首元素地址
    cout<<"数组中第一个元素的地址:"<<&arr[0]<<endl;
    cout<<"数组中第二个元素的地址:"<<&arr[1]<<endl;//与第一个元素紧挨着,所以相差4个字节

    //数组名是一个常量,不能进行复制操作

}