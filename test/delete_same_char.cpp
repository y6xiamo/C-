#include <iostream>
#include<string>
#include<vector>

using namespace std;
int main()
{
    string input;
    string to_delete;
    getline(cin,input);
    getline(cin,to_delete);

    int i = 0;
    int  index = 0;
    for( ;i < (int)to_delete.size();i++ )
    {
        int j = 0;
        for( ;j <(int)input.size();j++)
        {
            if((index = input.find(to_delete[i])) != -1)
            {
                 input.erase(index,1);

             }
        }

    }
    cout<<input;
    return 0;

}
