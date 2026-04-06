#include <bits/stdc++.h>
using namespace std;
int main()
{
    //利用冒泡函数实现升序降序
    int arr[9] = {4,2,8,0,5,7,1,3,9};

    cout <<"排序前"<<endl;
    for(int i = 0;i<9;i++)
    {
        cout<<arr[i]<<" ";


    }
    cout << endl;
    //排序总轮数=元素个数-1
    //每轮对比次数= 元素个数-排序轮数-1


    //开始冒泡排序
    for(int i = 0;i<9-1;i++)//排序总轮数=元素个数-1
    {
        //内层循环对比   //每轮对比次数= 元素个数-排序轮数-1
        for(int j = 0; j<9-i-1;j++)
        {
            //如果第一个数字比第二个数字大,交换两个数字
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }

    //排序后结果
    cout<<"排序后结果"<<endl;
    for(int i = 0;i<9;i++)
    {
        cout<<arr[i]<<" ";


    }
    cout << endl;
    return 0;


}