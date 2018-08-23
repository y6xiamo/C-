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
 //   for(size_t i = 0;i < v.size();i++)
 //   {
 //       cout<<v[i]<<" ";
 //       cout<<endl;
 //   }

 //   //偶尔会用 迭代器
////   vector<int>::iterator it = v.begin();
////    while(it != v.end())
////    {
////        cout<<*it<<" ";
////        it++;
////    }

 //   //const迭代器
 //   vector<int>::const_iterator it = v.begin();
 //   while(it != v.end())
 //   {
 //      // *it = 10;
 //       cout<<*it<<" ";
 //       it++;
 //   }
 //   cout<<endl;

 //   for(int j = v.size() - 1;j >= 0;j--)
 //   {
 //       cout<<v[j]<<" ";
 //   }
 //   cout<<endl;


    //反向迭代器
    vector<int>::reverse_iterator rit = v.rbegin();
    while(rit != v.rend())
    {
        cout<<*rit<<" ";
        rit++;
    }
    cout<<endl;

 //   vector<int>::const_rever_iterator it = v.begin();

 //   while(rit != v.end())
 //   {
 //       cout<<*rit<<" ";
 //       ++rit;
 //   }
}

void Test()
{

}
int main()
{
    Test();
}
