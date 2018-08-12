#include <iostream>
#include<string>
#include<string.h>
using namespace std;

class String 
{
public:
   // String s1("hello")
    //构造函数
    String(char* str)
     :_str(new char[strlen(str) + 1])
    {
        strcpy(_str,str);
    }

    //拷贝构造
    //s2(s1)
    String (const String& s)
        :_str(new char[strlen(s._str) + 1])
    {
        strcpy(_str,s._str);
    }

    //赋值运算符重载
    //s1 = s3
    String& operator = (const String& s)
    {
        if(this != &s)
        {
            char* tmp = new char[strlen(s._str) + 1];
            strcpy(tmp,s._str);
            delete[] _str;
            tmp = _str;

        }
        return *this;

    }

    //析构函数
    ~String()
    {

    }

    char* c_str()
    {
        return _str;
    }
private:
    char* _str;

};
int main()
{
    return 0;
}
