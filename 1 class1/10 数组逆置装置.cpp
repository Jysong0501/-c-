#include <bits/stdc++.h>
using namespace std;
int main()
{
    //1创建数组
    int arr[5]={1,3,2,5,4};
    cout<<"数组逆置前"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<endl;

    }
    //2实现逆置
    /*
    2.1记录初始下标位置
    2.2记录结束下标位置
    2.3初始下标与结束下标交换
    2.4初始下标++  结束下标--
    2.5重复执行2.1操作 直到初始下标>=结束下标
    */
   int start=0;//起始下标
   int end=sizeof(arr)/sizeof(arr[0])-1;//结束下标

   //实现元素互换
   while(start<end)
   {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        //下标更新
        start++;
        end--;
    }
    //3输出逆置后的数组
    cout<<"数组逆置后"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<endl;

    }
    return 0;
}