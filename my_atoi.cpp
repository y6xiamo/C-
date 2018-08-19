#include <iostream>
using namespace std;

int my_atoi(char* str)
{
    int flag = 1;
    //标志位，表明概述是正数还是负数
    int num = 0;

    if(str == NULL)
    {
        //输入字符串为空，直接返回
        return 0;
    }

    while(*str == '\t' ||*str == '\f'||*str == '\r'||*str == '\n'||* str ==' ')
    {
        //遇到上述字符，直接跳过
        str++;
    }

    // + - 号出现在第一个字符上才是合法的
    if(*str == '-')
    {
        //负数
        flag = -1;
        ++str;
    }
    else if(*str == '+')
    {
        //正数
        flag = 1;
        ++str;
    }

    while(*str)
    {
        if(*str >= '0' && *str <= '9')
        {
            num = num * 10 + *str - '0';
        }
        else
        {
            break;
        }
        ++str;
    }
    return num * flag;
}

int main()
{
    char str[] = "\t\r123";
    cout<<my_atoi(str)<<endl;
    return 0;
}
