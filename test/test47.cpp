#include <iostream>
class Solution {
public:
    int Sum_Solution(int n) {
        int result = n;
        bool ret = (n > 0)&&((result += Sum_Solution(n-1)) > 0);
        return result;
    }
};
