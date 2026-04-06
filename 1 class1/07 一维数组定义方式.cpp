//数据类型 数组名[数组长度]
//数据类型 数组名[数组长度] = {初始值1,初始值2,...,初始值n}
//数据类型 数组名[] = {初始值1,初始值2,...,初始值n}  //自动计算数组长度

/*
数组特点:
放在一块连续的空间中
数组中每个元素都是相同的数据类型



a[0]
  ^下标,可通过下标访问数组元素
  ^下标从0开始,到数组长度-1结束
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr1[5]; //定义一个长度为5的int类型数组
    //给数组元素赋值
    arr1[0]=10;
    arr1[1]=20;
    arr1[2]=30;
    arr1[3]=40;
    arr1[4]=50;
    //访问数组元素
    cout<<arr1[0]<<endl;
    cout<<arr1[1]<<endl;
    cout<<arr1[2]<<endl;
    cout<<arr1[3]<<endl;
    cout<<arr1[4]<<endl;

    int arr2[5]={10,20,30,40,50};//定义一个长度为5的int类型数组并初始化
    //访问数组元素
    cout<<arr2[0]<<endl;
    cout<<arr2[1]<<endl;
    cout<<arr2[2]<<endl;
    cout<<arr2[3]<<endl;
    cout<<arr2[4]<<endl;

    int arr3[]={10,20,30,40,50};//定义一个int类型数组并初始化,自动计算数组长度
    //访问数组元素
    cout<<arr3[0]<<endl;
    cout<<arr3[1]<<endl;
    cout<<arr3[2]<<endl;
    cout<<arr3[3]<<endl;
    cout<<arr3[4]<<endl;

    return 0;

}