#include <iostream>
using namespace std;
//void Test()
//{
//   // int a = 1;
//   // int &b = a;
//   // int &c = b;
//   // cout<<"a:address->"<<&a<<endl;
//   // cout<<"b:address->"<<&b<<endl;
//   // cout<<"c:address->"<<&c<<endl;
//   
//    int d1 = 4;
//    const int& d2 = d1;
////  //  d2 = 5;
//    d1 = 5;
//
//    const int a1 = 20;
//   // int & a2 = a1;
//   const int & a2 = a1;
//
//   double b1 = 1.2;
////   int & b2 = b1;
//   const int & b2 = b1;
//}

//值传递
void Swap(int left,int right)
{
    int temp = left;
    left = right;
    right = temp;
}
void Test()
{
    int a = 10;
    int b = 20;
    Swap(a,b);
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
}
int main()
{
    Test();
    return 0;
}
