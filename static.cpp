#include <iostream>
using namespace std;
class Date
{
public:
    Date()
    {
        cout<<"Date()"<<endl;
        sCount++;
    }
    //静态成员函数
    static void PrintCount()
    {
        cout<<"Date count:"<<sCount<<endl;
    }
private:
    int _year;
    int _month;
    int _day;
private:
    static int sCount;
};

//定义并初始化静态成员变量
int Date::sCount = 2;

void test()
{
    Date d1,d2;
    //访问静态成员函数
    Date::PrintCount();
}
int main()
{
    void test();
    return 0;
}
