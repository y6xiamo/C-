#include <iostream>
#include<string>
using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        if(str.size() == 0)
        {
            return 0;
        }
        int result = 0;
        int flag = 1;
        size_t i = 0;
        if(str[0] == '-')
        {
            flag = -1;
            i++;
        }
        else if(str[0] == '+')
        {
            flag = 1;
            i++;
        }
        while(str[i] != '\0')
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                result = result * 10 + str[i] - '0';
            }
            else
            {
                return 0;
            }
            i++;
        }
        return flag * result;
    }
};

int main()
{
    Solution str;
    cout<<str.StrToInt("-1233")<<endl;
    return 0;
}
