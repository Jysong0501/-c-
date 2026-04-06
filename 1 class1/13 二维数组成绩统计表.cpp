#include <bits/stdc++.h>
using namespace std;
int main()
{
    //创建二维数组
    int scores[3][3]=
    {
        {100,100,100},
        {90,50,100},
        {60,70,80}
    };

    string names[3]={"张三","李四","王五"};
    //统计每个人的分数总和
    for(int i=0;i<3;i++)
    {
        int sum=0;
        for(int j =0;j<3;j++)
        {
            sum +=scores[i][j];
            
        }
        cout<<names[i]<<"的总分为:"<<sum<<endl;

    }

}