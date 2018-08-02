#include <iostream>
using namespace std;
//class Time
//{
//public:
//    Time(int hour)
//    {
//        cout<<"Time()"<<endl;
//        _hour = hour;
//        _minute = 0;
//        _second = 0;
//    }
//    Time(const Time& t)
//    {
//        _hour = t._hour;
//        _minute = t._minute;
//        _second = t._second;
//    }
//
//private:
//    int _hour;
//    int _minute;
//    int _second;
//};
class Date
{
public:
    //无参构造函数
    /* Date() */
    /* { */

    /* } */
//    int GetMonthDay(int year,int month)
//    {
//        //TODO
//    }
//    //缺省有参构造函数
//   Date(int year = 2018,int month = 8,int day = 8)
//   {
//       _year = year;
//       _month = month;
//       _day = day;
//       if(_year >= 1900
//          && _month >0 && _month < 13
//          && _day > 0 && _day <= GetMonthDay(_year,_month))
//          {
//                //
//          }
//
//   }
 
    //初始化列表
//    Date(int year,int month,int day,const Time& t)    
//    {
//        cout<<"Date()--非初始化列表"<<endl;
//        _year = year;
//        _month = month;
//        _day = day;
//        _t = t;
//    }
//    Date(int year,int month,int day,const Time& t)
//        :_year(year)
//        ,_month(month)
//        ,_day(day)
//        ,_t(t)
//
//    {
//        cout<<"Date() --初始化列表"<<endl;
//    }
    //拷贝构造函数
    //d2(d1) d2->this,d1->d
 //  Date(const Date& d)
 //  {
 //      _year = d._year;
 //      _month= d._month;
 //      _day = d._day;
 //  }
//   void Display()
//   {
//       cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
//   }
   //赋值运算符重载
   //对一个已经存在的对象进行拷贝赋值
  //  d1 = d3;
//    Date& operator=(const Date& d)
//    {
//        if(this != &d)
//        {
//            this->_year = d._year;
//            this->_month = d._month;
//            this->_day = d._day;
//        }
//        return *this;
//    }
//   //析构函数
//   ~Date()
//   {
//       //清理工作
//
//   }
//private:
//    int _year;
//    int _month;
//    int _day;
//    Time _t;
//};
//int main()
//{
//    Time t1;
//    Date d1(2008,9,20,t1);
////    Date d1;
////    d1.Display();
////    Date d2(2020,7,4);
////    Date(2002,12,12).Display();//匿名对象
////    Date d4(1997,9,1);
////    d1 = d2 = d4;
////    d1.Display();
//
//    
////    d2.Display();
////    d3.Display();
//    return 0;
//}
//class Time
//{
//public:
//    Time(const Time& t)
//    {
//        cout<<"Time(const Time&)"<<endl;
//        _hour = t._hour;
//        _minute = t._minute;
//        _second = t._second;
//    }
//private:
//    int _hour;
//    int _minute;
//    int _second;
//
//};
//class Date
//{
//public:
//    Date(int year,int month,int day,const Time& t)
//    {
//        cout<<"Date()"<<endl;
//        _year = year;
//        _month = month;
//        _day = day;
//        _t= t;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//    const int _testConst;//测试const成员变量的初始化，报错
//    int& _testReference;//测试引用成员变量的初始化，报错
//    Time _t;//测试无缺省构造函数的成员变量的初始化，报错
//    //上述三种情况，只能用初始化列表初始化
//};
//
//成员变量按声明顺序依次初始化，而非初始化列表出现的顺序
//class Date
//{
//public:
//    Date(int x)
//        :_year(x)
//        ,_month(_year)
//        ,_day(x)
//    {
//        cout<<"Date()"<<endl;
//    }
//
//    void Display()
//    {
//        cout<<"year"<<_year<<endl;
//        cout<<"year"<<_month<<endl;
//        cout<<"year"<<_day<<endl;
//
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//
//};
//void Test()
//{
//    Date d1(1);
//    d1.Display();
//    
//}
//int main()
//{
//    Test();
//    return 0;
//}
