#include <iostream>
#include<vector>
using namespace std;

//1.迭代器
//  正向
//  反向
//  const_xxx
//
//  1.for + operator[]
//   作用：1.遍历 2.修改
void print_vector(const vector<int> &v)
{
    //对vector而言最常用
    for(size_t i = 0;i < v.size();i++)
    {
        cout<<v[i]<<" ";
        cout<<endl;
    }

    //偶尔会用
    vector<int>::iterator it = v.begin();
    while(it != v.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
}

void Test()
{

}
int main()
{
    Test();
}
