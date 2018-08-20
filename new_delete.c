#include <iostream>
#include<stdlib.h>
using namespace std;
//C动态内存管理
//void Test()
//{
//    int *p1  = (int*)malloc(sizeof(int)*4);
//    free(p1);
//    int *p2 = (int*)calloc(4,sizeof(int));
//    int *p3 = (int*)realloc(p2,sizeof(int)*4);
//
//    free(p2);
//    free(p3);
//}

//C++动态内存管理
//void Test1()
//{
// //   int *p1 = new int;//动态开辟一块四字节空间，单个数据(1个int)
// //   int *p2 = new int(3);//动态开辟一块四字节空间并把它初始化为3
// //   int *p3 = new int[3];//动态开辟3个四字节空间(12字节)
//
//    int *p4 = new int;
//    int *p5 = new int(3);
//    int *p6 = new int[3];
//    int *p7 = (int*)malloc(sizeof(int));
//
// //   delete p1;
// //   delete p2;
// //   delete[] p3;
//
//    //malloc/free  new/delete  new[]/delete[]匹配使用
//    delete p4;
//    free(p5);
//    delete[] p6;
//    free(p7);   
//}

class Array
{
public:
    Array(size_t size = 10)
        :_size(size)
        ,_a(0)
    {
        cout<<"Array(size_t size)"<<endl;
        if(_size > 0)
        {
            _a = new int[size];
        }
    }

    ~Array()
    {
        cout<<"~Array()"<<endl;
        if(_a)
        {
            delete[] _a;
            _a = 0;
            _size = 0;
        }
    }
private:
    size_t _size;
    int *_a;
};

void Test()
{
    Array* p1 = (Array*)malloc(sizeof(Array));
    Array* p2 = new Array;
    Array* p3 = new Array(3);
    Array* p4 = new Array[3];

    free(p1);
    delete p2;
    delete p3;
    delete[] p4;
}
int main()
{
    Test();
    return 0;
}
