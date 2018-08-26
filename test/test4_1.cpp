#include <iostream>
#include<string>
using namespace std;
int main()
{
    string s1;
    string s2(s1);
    int i = 0;
    while(s1[i] != '\0')
    {
        if(s1[i] != ' ')
        {
            s2.push_back(s1[i]);
        }
        else
        {
            s2+="%20";
        }
    }
    s2[i] = '\0';
    for(i = 0;i < s2.size();i++)
    {
        cout<<s1[i]<<endl;
    }
    return 0;
}
