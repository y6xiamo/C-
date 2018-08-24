#include <iostream>
class Solution {
public:
    //求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、
    //switch、case等关键字及条件判断语句（A?B:C）
    //1.调用递归，
    int Sum_Solution(int n) {
        int result = n;
        bool ret = (n > 0)&&((result += Sum_Solution(n-1)) > 0);
        return result;
    }
};
