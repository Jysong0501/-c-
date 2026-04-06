#include <bits/stdc++.h>
using namespace std;

//字符串查找和替换

//1.查找
void test01()
{
    string str1 = "abcdefg";
    int pos = str1.find("de");
    cout<<"pos = "<<pos<<endl;//d在从0开始数第三个位置



    int pos2 = str1.find("df");
    if(pos == -1)//查不到返回-1
    {
        cout<<"未找到字符串"<<endl;
    }
    else{
        cout<<"找到字符串  pos2 = "<<pos2<<endl;
    }
    

    //rfind 和find 区别
    //rfind从右往左查找  find 从左往右查 *find为第一次出现的位置,rfind为最后一次出现的位置    但结果不变
    pos = str1.rfind("de");
    cout<<"pos = "<<pos<<endl;
    
}


//2.替换
void test02()
{
    string str1 = "abcdefg";

    //从1号位置起 3个字符 替换为"1111"
    str1.replace(1,3,"1111");
    cout <<"str1 ="<<str1 <<endl;
}
int main()
{
    test01();
    cout<<"--------------------------------------"<<endl;
    test02();

    return 0;
}