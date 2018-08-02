#include <iostream>
using namespace std;
class Date
{
public:
    //无参构造函数
    /* Date() */
    /* { */

    /* } */
    //缺省有参构造函数
 //   Date(int year = 2018,int month = 8,int day = 8)
 //   {
 //       _year = year;
 //       _month = month;
 //       _day = day;

 //   }
 
    //初始化列表
    
    //拷贝构造函数
    //d2(d1) d2->this,d1->d
   Date(const Date& d)
   {
       _year = d._year;
       _month= d._month;
       _day = d._day;
   }
   void Display()
   {
       cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
   }
   //赋值运算符重载
   //对一个已经存在的对象进行拷贝赋值
  //  d1 = d3;
    Date& operator=(const Date& d)
    {
        if(this != &d)
        {
            this->_year = d._year;
            this->_month = d._month;
            this->_day = d._day;
        }
        return *this;
    }
   //析构函数
   ~Date()
   {
       //清理工作

   }
private:
    int _year;
    int _month;
    int _day;
};
int main()
{
    Date d1;
    d1.Display();
    Date d2(2020,7,4);
    Date(2002,12,12).Display();//匿名对象
    Date d4(1997,9,1);
    d1 = d2 = d4;
    d1.Display();

    
//    d2.Display();
//    d3.Display();
    return 0;
}
