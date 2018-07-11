#include<iostream>
#include <stdio.h>
#include<string.h>

using namespace std;
int main()
{
    string s1("hello");
    string s2(s1);
    printf("%p\n",(s1.c_str));
    printf("%p\n",s2.c_str);
    return 0;

}
