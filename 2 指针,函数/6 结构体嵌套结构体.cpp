#include <bits/stdc++.h>
using namespace std;

struct student
{

    string name;
    int age;
    int score;
};
//定义老师结构体
struct teacher
{

    int id;//教师编号
    string name;//教师姓名
    int age;//年龄
    struct student stu;//辅导的学生
};
int main()
{
    //结构体嵌套结构体
    //创建老师
    teacher t;
    t.id=10000;
    t.name="老王";
    t.age=50;
    t.stu.name="张三";
    t.stu.age=20;
    t.stu.score=60;

    cout <<"老师名字:"<<t.name<<"  老师编号:"<<t.id<<"  老师年龄:"<<t.age<<"  老师辅导的学生姓名:"<<t.stu.name<<"  学生年龄:"<<t.stu.age<<"  学生考试分数为:"<<t.stu.score<<endl;


}