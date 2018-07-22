#include<iostream>
#include<string> 
using namespace std;
class string{
public:

private:
    char* c_str;
};
int main()
{
    string s1("hello");
    string s2(s1);
    printf("%p\n",s1);
    printf("%p\n",s2.c_str);
    return 0;

}
