#include <bits/stdc++.h>
#include <string.h>
using namespace std;

struct student
{   
    string name;
    int age;
    int score;

    

};

//打印学生信息函数
//1'值传递
void printStudent1(struct student s)
{
    s.age = 100;
    cout <<"子函数中  姓名:"<<s.name<<" 年龄:"<<s.age<<" 分数:"<<s.score<<endl;
}

//2'地址传递
void printStudent2(struct student
 *p)
 {
    p->age = 200;
    cout <<"子函数2中  姓名:"<<p->name<<" 年龄"<<p->age<<" 分数"<<p->score<<endl;

 }
int main()
{
    //结构体做函数参数
    //将学生传入到一个参数中,打印学生身上的所有信息

    //创建结构体变量
    struct student s;
    s.name = "张三";
    s.age = 20;
    s.score = 85;

    cout <<"main函数0中打印 姓名:"<<s.name<<" 年龄:"<<s.age<<" 分数:"<<s.score<<endl;
    printStudent1(s);
    cout <<"打印main1函数 姓名:"<<s.name<<" 年龄:"<<s.age<<" 分数:"<<s.score<<endl;//值传递只改变形参,不改变实参
    printStudent2(&s);
    cout <<"打印main2函数 姓名:"<<s.name<<" 年龄:"<<s.age<<" 分数:"<<s.score<<endl;//地址传递之后实参也改变了
    return 0;

}