#include <iostream>
#include<string>
#include<string.h>
using namespace std;

//class String 
//{
//public:
//    //1.传统写法
//   // String s1("hello")
//    //构造函数
//    String(char* str)
//     :_str(new char[strlen(str) + 1])
//    {
//        strcpy(_str,str);
//    }
//
//    //拷贝构造
//    //s2(s1)
//    String (const String& s)
//        :_str(new char[strlen(s._str) + 1])
//    {
//        strcpy(_str,s._str);
//    }
//
//    //赋值运算符重载
//    //s1 = s3
//    String& operator = (const String& s)
//    {
//        if(this != &s)
//        {
//            char* tmp = new char[strlen(s._str) + 1];
//            strcpy(tmp,s._str);
//            delete[] _str;
//            tmp = _str;
//        }
//        return *this;
//    }
//
//    //析构函数
//    ~String()
//    {
//        delete[] _str;
//        _str = NULL;
//    }
//
//    char* c_str()
//    {
//        return _str;
//    }
//private:
//    char* _str;
//
//};
//int main()
//{
//    string s1("hello");
//    cout<<s1<<endl;
//    string s2(s1);
//    cout<<s2<<endl;
//    return 0;
//}

//1.现代写法，剥削
//class String
//{
//public:
//    //构造函数
//    String(const char* str)
//      :_str(new char[strlen(str) + 1])
//    {
//        strcpy(_str,str);
//    }
//
//    //拷贝构造
//    String(const String&  s)
//        :_str(NULL)
//    {
//        String tmp(s._str);
//        swap(_str,tmp._str);
//    }
//
//    //赋值运算符重载
//    //s1 = s3
//    String& operator=(const String s)
//    {
//        if(this != &s)
//        {
//            String tmp(s._str);
//            swap(_str,tmp._str);
//        }
//        return *this;
//    }
//
//    //析构
//    ~String()
//    {
//        if(_str != NULL)
//        {
//            delete[] _str;
//            _str = NULL;
//        }
//    }
//
//    char* c_str()
//    {
//        return _str;
//    }
//private:
//    char* _str;
//
//};
//int main()
//{
//    String s1("lalala");
//    cout<<s1.c_str()<<endl;
//    String s2(s1);
//    cout<<s2.c_str()<<endl;
//    String s3("sheep");
//    s1 = s3;
//    cout<<s1.c_str()<<endl;
//    return 0;
//}

namespace DP_COPY
{
class String
{
public:
    String(const char* str = "")
       :_size(strlen(str))
       ,_capacity(_size)
     {
         _str = new char[_size+1];
         strcpy(_str,str);
     }


    //swap(s1,s2) ---> s1.swap(s2)
    void Swap(String& s)
    {
        swap(_str,s._str);
        swap(_size,s._size);
        swap(_capacity,s._capacity);
    }

    //s2(s1)
    String(const String& s)
        :_str(NULL)
    {
        String tmp(s._str);
        this->Swap(tmp);
    }

    //s1 = s3
    String& operator = (String& s)
    {
        this->Swap(s);
        return *this;
    }

    ~String()
    {
        if(_str)
        {
            delete[] _str;
            _str = NULL;
        }
    }

private:
    char* _str;
    size_t _size;
    size_t _capacity;
};
}
int main()
{
    DP_COPY::String s1("hello");
    cout<<DP_COPY::s1.c_str()<<endl;
   DP_COPY::String s2(s1);
    cout<<s2.c_str()<<endl;

}
