#include <iostream>
class Solution {
public:
    bool dev_zeroError = false;
    double Power(double base, int exponent) {
        dev_zeroError = false;
        double result = 1.0;

        if(equal(base,0.0) && exponent < 0)
        {
            //出错
            //            dev_zeroError = true;
            //                        result = 0.0;
            //                                
        }
        if(equal(base,0.0) && exponent >= 0)
        {
            return 0.0;

        }
        if(exponent == 0)
        {
            result = 1.0;

        }
        if(base > 0.0 && exponent > 0)
        {
            result = plusPower(base,exponent);

        }
        else if(base > 0.0 && exponent < 0)
        {
            exponent = -exponent;
            result = plusPower(base,exponent);
            result = 1.0/result;

        }
        if(base < 0)
        {
            base = -base;
            if(exponent < 0)
            {
                exponent = -exponent;

            }
            result = plusPower(base,exponent);
            result = -result;
            if(exponent < 0)
            {
                result = 1.0 / result;

            }

        }
        return result;

    }
    double plusPower(double base,int exponent)
    {
//        double result = 1.0;
//        if(base > 0 && exponent > 0)
//        {
//            for(int i = 0;i < exponent;i++)
//            {
//                result *= base;
//
//            }
//
//        }
        if(exponent == 0)
        {
            return 1;

        }
        if(exponent == 1)
        {
            return base;

        }
        //上述代码效率低，假如exponent为一个很大的数
        //exponent为32，需要循环31次
        //求出base的exponent/2次方，再一平方就可以求出最后的值
        //a^n = a^(n/2)*a^(n/2)  (偶数)
        //a^n = a^(n/2)*a^(n/2)*a  (奇数)
        //考虑数学公式
        double result = plusPower(base,exponent >> 1);//>>1相当于除以2,比除法效率高
        result*= result;
        if(exponent & 1)
            //如果为奇数，再乘以其本身
        {
            result *= base;

        }

        return result;

    }
    int equal(double num1,int num2)
    {

        if((num1 - num2) > -0.00000001 && (num1 - num2) < 0.000000001)
        {
            return 1;

        }
        else 
        {
            return 0;

        }

    }

};
