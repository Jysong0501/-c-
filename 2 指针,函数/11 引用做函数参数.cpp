#include<iostream>
using namespace std;


//1.值传递
void myswap01(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
}
//2.地址传递
void myswap02(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}



//3.引用传递
void myswap03(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}


int main()
{
    int a= 10;
    int b =20;
    myswap01(a,b);//值传递,形参不会修饰实参
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;

    myswap02(&a,&b);//地址传递,形参会修饰实参

    myswap03(a,b);//引用传递,形参会修饰实参 

}