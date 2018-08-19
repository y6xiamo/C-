#include <iostream>
using namespace std;

//将一个整数转换为字符串
//value --- 要转换的整数 
//str --- 转为后的字符串的目标地址
//radix --- 以多少进制转换
char* my_itoa(int value,char* str,int radix)
{
    if(radix < 2|| radix > 36)
    {
        cout<<"error"<<endl;
        //输入的进制数错误
        return str;
    }
    
    int flag = 1;
    //标志位，表明该位是正还是负
    if(value < 0)
    {
        value = -value;
        flag = -1;
        //输入的数是负数
    }
   
    char str_arr[256] = {0};//存转换后的字符
    int cur = 0;//用来遍历上面这个数组(存转化后的字符)
     while(value)
     {
         //将每个数字转化为字符并保存到str_arr中
         str_arr[cur++] = value % radix + '0';
         value /= radix;
     }

     //如果是负数，最后再把负号添上，这样取出来的第一个字符就是负号
     if(flag == -1)
     {
         str_arr[cur++] = '-';
     }

     char* pstr = str;
     for(int next = cur - 1;next >= 0;--next)
     {
         //从后往前取出数组中的每个字符
         *pstr = str_arr[next];
         ++pstr;
     }
     *pstr = '\0';
     return pstr;
}
int main()
{
    int value = 36;
    char a[128] = {0};
    my_itoa(value,a,10);
    cout<<a<<endl;
    return 0;
}
