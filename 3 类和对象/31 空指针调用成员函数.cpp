#include <iostream>
using namespace std;

//空指针调用成员函数

class Person
{
    public:
    void showclassname()
    {
        cout<<"this is Person class"<<endl;
    }

    void showpersonage()
    {
        //报错原因是因为传入的指针是NULL
        if(this == NULL)
        {
            return ;
        }
        cout<<"age = "<<this->m_age<<endl;
    }

    int m_age;
};

void test01()
{
    Person *p = NULL;
    p->showclassname();
    p->showpersonage();

}

int main()
{
    test01();

    return 0;
}