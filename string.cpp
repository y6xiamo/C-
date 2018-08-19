#include <iostream>
#include<string>
#include<string.h>
#include<assert.h>
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

    //Capacity
    void Reverse(size_t n)
    {
        Expand(n);
    }

    //Size+Capacity
    //初始化
    void Resize(size_t n,char ch = '\0')
    {
        if(n < _size)
        {
            _size = n;
            _str[_size] = '\0';
        }
        else
        {
            if(n > _capacity)
            {
                Expand(n);
            }
            for(size_t i = _size;i < n;i++)
            {
                _str[i] = ch;
            }
            _str[n] = '\0';
            _size = n;
        }
    }

    void Expand(size_t n)
    {
        if(n > _capacity)
        {
            char* tmp = new char[n+1];
            strcpy(tmp,_str);

            delete[] _str;
            _str = tmp;

            _capacity = n;
        }
    }

    //插入一个字符
    void PushBack(char ch)
    {
   //     if(_size == _capacity)
   //     {
   //         Expand(_capacity*2);
   //     }
   //     _str[_size] = ch;
   //     _str[_size+1] = '\0';
   //     _size++;
          Insert(_size,ch);
    }
    
    //添加一个字符串
    void Append(const char* str)
    {
   //     size_t len = strlen(str);
   //     if(_size + len > _capacity)
   //     {
   //         size_t newcapacity = _capacity * 2;
   //         while(newcapacity < _size + len)
   //         {
   //             newcapacity *= 2;
   //         }
   //         Expand(_size + len);

   //     }
   //     strcpy(_str+_size,str);
   //     _size += len;
          Insert(_size,str);
    }

    //在pos位置插入一个字符
    void Insert(size_t pos,char ch)
    {
        //检查pos是否越界
        assert(pos <= _size);

        //空间不够，扩容
        if(_size == _capacity)
        {
            Expand(_capacity*2);
        }
        //将pos之后的所有元素都向后移动
        size_t end = _size;
        while(end != pos)
        {
            _str[end+1] = _str[end];
            --end;
        }

        //在pos位置插入指定元素
        _str[end] = ch;
        ++_size;
    }
    
    //在pos位置插入一个字符串
    void Insert(size_t pos,const char* str)
    {
        assert(pos <= _size);
        //检查pos是否越界
        int len = strlen(str);
        if(len + _size > _capacity)
        {
            //空间不够，扩容
            Expand(_size+len);
        }
        int end = _size;
        while(end >= (int)pos)
        {
            //将元素向后移动len个位置
            _str[end+len] = _str[end];
            --end;
        }
        //将要插入的字符串拷贝过来
        strncpy(_str+pos,str,len);
        _size += len;
    }

    //s1 += "world"
    String& operator += (const char* str)
    {
       this->Append(str);
       return *this;
    }

    //s1 += s2
    String& operator += (const String s)
    {
       // this->Append(s._str);
        *this += s._str;
        //this->operator += (s._str);
        return *this;
    }

    //s1 + "world"
    String operator + (const char* str)
    {
        String ret(_str);
        ret.Append(str);
        return ret;
    }

    //s1 + s2
    String operator + (const String s)
    {
        String ret(_str);
        return *this + s._str;
    }

    void PopBack()
    {
        //检查是否为空
        assert(_size > 0);
        --_size;
        _str[_size] = '\0';
    }

    //删除指定位置的len个元素
    void Erase(size_t pos,size_t len)
    {
        assert(pos < _size);
        //检查pos是否合法
        //如果从pos位置往后的元素不够len个健康
        //就把pos位置置为0
        //否则，就用后面的元素覆盖掉前len个元素
        if(pos + len >= _size)
        {
            _str[pos] = '\0';
            _size = pos;
        }
        else
        {
            strcpy(_str+pos,_str+pos+len);
            _size -= len;
        }
    }

    size_t Size()
    {
        return _size;
    }

    size_t Capacity()
    {
        return _capacity;
    }

    bool Empty()
    {
        return _size == 0;
    }

    //[]重载
    char& operator[](size_t pos)
    {
        return _str[pos];
    }

    //查找一个指定的元素
    size_t Find(char ch) const
    {
        for(size_t i = 0;i < _size;i++)
        {
            if(_str[i] == ch)
            {
                return i;
            }
        }
        return npos;
    }

    //查找一个指定的字符串
    size_t Find(const char* sub) const
    {
        char* cur = _str;
        while(*cur)
        {
            const char* cur_tmp = cur;
            const char* sub_tmp = sub;
            while(*sub_tmp && *cur_tmp == *sub_tmp)
            {
                cur_tmp++;
                sub_tmp++;
            }
            if(*sub_tmp == '\0')
            {
                return cur-_str;
            }
            else
            {
                cur++;
            }
        }
        return npos;
    }

    //运算符重载
    //s1 < s2 ---> s1.operator<(s2)
    bool operator < (const String& s)const
    {
        const char* str1 = _str;
        const char* str2 = s._str;
        while(*str1 && *str2)
        {
            if(*str1 < *str2)
            {
                return true;
            }
            else if(*str1 > *str2)
            {
                return false;
            }
            else
            {
                str1++;
                str2++;
            }
        }
        if(*str1 == '\0' &&*str2 != '\0')
        {
            return true;;
        }
        else
        {
            return false;
        }

    }


    




    char* c_str()
    {
        return _str;
    }
private:
    char* _str;
    size_t _size;
    size_t _capacity;

public:
    static size_t npos;
};

size_t String::npos = -1;
}
int main()
{
 //   DP_COPY::String s1("hello");
 //   cout<<s1.c_str()<<1<<endl;
 //  DP_COPY::String s2(s1);
 //   cout<<s2.c_str()<<2<<endl;
 //   DP_COPY::String s3("world");
 //   s1 = s3;
 //   cout<<s3.c_str()<<3<<endl;
 //   cout<<s1.c_str()<<1<<endl;

//    DP_COPY::String s1("hello");
//    DP_COPY::String s3("world");
//
//    swap(s1,s3);
//    s1.Swap(s3);
//
//    cout<<s1.c_str()<<1<<endl;
//    cout<<s3.c_str()<<3<<endl;
//
//      DP_COPY::String s1("hello");
//      cout<<s1.c_str()<<endl;
//      s1.PushBack('c');
//      cout<<s1.c_str()<<endl;

//      DP_COPY::String s1("hello");
//      cout<<s1.c_str()<<endl;
//      s1.Append(" world");
//      cout<<s1.c_str()<<endl;

//        DP_COPY::String s1("hello");
//        cout<<s1.c_str()<<endl;
//
//        s1.Insert(2,'w');
//        cout<<s1.c_str()<<endl;
//
//        s1.Insert(2,"hahaha");
//        cout<<s1.c_str()<<endl;

        DP_COPY::String s1("hello");
        cout<<s1.c_str()<<endl;

       // s1 += "world";
  //      DP_COPY::String s2("wolrd");
  //       s1 += s2;
  
  //      DP_COPY::String s2 =  s1 + "world";
  //      cout<<s1.c_str()<<endl;
  //      cout<<s2.c_str()<<endl;

  //      s1.PopBack();
  //      cout<<s1.c_str()<<endl;

  //      s1.Erase(1,3);
  //      cout<<s1.c_str()<<endl;

  //      cout<<s1.Size()<<endl;
  //      cout<<s1.Capacity()<<endl;
  //      cout<<s1.Empty()<<endl;

  //      cout<<s1[2]<<endl;
  //      cout<<s1.Find('x')<<endl;
  //      cout<<s1.Find("llo")<<endl;
  
        DP_COPY::String s2("hell");
        cout<<s1.operator<(s2)<<endl;
}
