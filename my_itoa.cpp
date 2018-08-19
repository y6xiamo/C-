#include <iostream>
using namespace std;

//将一个整数转换为字符串
//value --- 要转换的整数 
//str --- 转为后的字符串的目标地址
//radix --- 以多少进制转换
char* my_itoa(int value,char* str,int radix)
{
    if(value < 0)
    {
        //输入数据不合理
        return str;
    }
    if(radix < 2|| radix > 36)
    {
        //输入的进制数错误
        return str;
    }
   
    char str_arr[256] = {0};//存转换后的字符
    int cur = 0;//用来遍历上面这个数组(存转化后的字符)
     while(value)
     {
         str_arr[cur++] = value % radix + '0';
         value /= radix;
     }

     char* pstr = str;
     for(int next = cur - 1;next >= 0;--next)
     {
         *pstr = str_arr[next];
         ++pstr;
     }

     *pstr = '\0';
     return pstr;
}
int main()
{
    int value = 8;
    char a[128] = {0};
    my_itoa(value,a,2);
    cout<<a<<endl;
    return 0;
}
