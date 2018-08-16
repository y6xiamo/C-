#include<iostream>
using namespace std;
class Date
{
    //四个默认成员函数
    //
    //构造函数
public:
    Date(int year = 2018,int month = 9,int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    //拷贝构造 
    //s2(s1)
    //s2->this,s1->d
    Date(const Date& d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    //赋值
    //d1 = d2; d1->this,d2->d
    Date& operator=(const Date& d)
    {
        if(this != &d)
        {
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }
        return *this;
    }

    
    //析构，完成清理工作
    ~Date()
    {

    }


    //赋值运算符的重载
   // d1 < d2 --> d1.operator(&d1,d2);
    bool operator < (const Date& d)
    {
        if(_year < d._year)
        {
            return true;
        }
        else if(_year == d._year)
        {
            if(_month < d._month)
            {
                return true;
            }
            else if(_month == d._month)
            {
                if(_day < d._day)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool operator > (const Date& d)
    {
        return !(*this < d);
    }
    //d1 == d2
    bool operator==(const Date& d)
    {
        if(_year == d._year)
        {
            if(_month == d._month)
            {
                if(_day == d._day)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool operator != (const Date& d)
    {
        if(*this == d)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool operator >= (const Date& d)
    {
        if(*this > d || *this == d)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool operator <= (const Date& d)
    {
        if(*this < d ||*this == d)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    

    //++d
    Date& operator ++ ()  //前置
    {
        ++(_day);
        if(_day > GetMonthDay(_year,_month))
        {
            _day = 1;
            ++(_month);
            if(_month > 12)
            {
                _month = 1;
                ++(_year);
            }

        }
       // cout << "*********" << endl;
       // cout << "_year:" << _year << endl;
       // cout << "_month:" << _month << endl;
       // cout << "_day:" << _day << endl;
       // cout << "*********" << endl;
        return *this;
    }

    Date operator ++ (int) //后置
    {
        Date tmp = (*this);
        ++(*this);


        return tmp;
    }

    Date& operator -- () //前置
    {
        --(_day);
        if(_day == 0)
        {
            --(_month);
            if(_month == 0)
            {
                _year -= 1;
                _month = 12;
            }
            _day += GetMonthDay(_year,_month);
        }
        return *this;

    }
    Date operator -- (int)//后置
    {
        Date tmp = (*this);
        --(*this);
        return tmp;;

    }


   Date& operator += (int day)
   {
       _day = _day + day;
       if(_day > GetMonthDay(_year,_month))
       {
           _day = _day - GetMonthDay(_year,_month);
           ++(_month);
           if(_month > 12)
           {
               ++(_year);
               _month = 1;
           }
       }
       return *this;
   }

   Date operator + (int day)
   {
       Date tmp = (*this);
       tmp += day;
       return tmp;
   }

   Date& operator -= (int day)
   { 
        _day = _day - day;
        if(_day  < 0)
        {
            _day = _day + GetMonthDay(_year,_month);
            --(_month);
            if(_month < 0)
            {
                --(_year);
                _month = 12;
            }

        }
        return (*this);

     } 

   Date operator - (int day)
   {
       Date tmp = (*this);
       tmp -= day;
       return tmp;
   }

   //一个日期减一个日期,看它们之间相差多少天
   //2018-8-6 - 2018-5-23
   //d1 - d2
   //d1.operator(d2);
   int operator - (Date& d)
   {
       int count = 0;//用来记录天数
       int flag = 1;//用来标志两个日期的大小

       if(*this < d)
       {
           swap(*this,d);
           flag = -1;//第一个日期小于第二个日期
       }

       while(*this > d)
       {
           --(*this);
           ++count;//算他们之间相差的天数
       }

       count = count * flag;
       if(flag == -1)
       {
           swap(*this,d);
       }
       return count;
   }

   //取地址运算符的重载
   const Date* operator & () const
   {
       return this;
   }

   Date* operator & ()
   {
       return this;
   }

   

    
    //输入输出流的重载
    //cout << d
    //cout.operator<<(d);
    friend ostream& operator << (ostream& out,const Date& d)
    {
        out << d._year<<"-" ;
        out << d._month<<"-";
        out << d._day << endl;
        return out;
    }

   friend  istream& operator >> (istream& in,Date& d)
   { 
       cout<<"请输入年月日"<<endl;
       in >> d._year;
       in >> d._month;
       in >> d._day;
       return in;
       
   }

    //打印年月日
    void Display()
    {
        cout<<_year<<"-"<<_month<<"-"<<_day;
    }
    
    //获取某一年某一个月的天数
    int GetMonthDay(int year,int month)
    {
        int day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};//平年

        if(year % 400 == 0 ||(year % 4 == 0 && year % 100 != 0))
        {
            day[month] = day[2] + 1;
        }
        return day[_month];
    }
private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date d1(2018,8,6);
    Date d2(2018,8,6);
    cout<<d1 -d2<<endl;
 //  Date d3(2018,8,6);
//    Date d3;
//    cin>>d3;

 //   cout<<(d1<d2)<<endl;
 //   cout<<(d1>d2)<<endl;
 //   cout<<(d1==d3)<<endl;
 //   cout<<(d1>=d3)<<endl;
 //   cout<<(d1<=d3)<<endl;
    
     /* cout<<(++d2); */
     /* cout<<(d2++); */
  //  cout << ++d2;
  //  cout << d2++;

  //  cout << --d2;
  //  cout << d2--;
//    cout<<(d1++);
//      cout << d2 + 30;
//      cout<< d2;
//      d2 += 30;
//      cout << d2;

//    cout << d2 - 30;
//    d2 = d2 - 30;
//    cout << d2 << endl;

//    Date d3(2018,8,1);
//    cout << (d3 - d1) << endl;

 //   Date d3(2018,9,2);
 //   cout << &d3 <<endl;

 //   d2 = d1++;
 //   d2.Display();
}
