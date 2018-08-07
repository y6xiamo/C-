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
        double result = 1.0;
        if(base > 0 && exponent > 0)
        {
            for(int i = 0;i < exponent;i++)
            {
                result *= base;

            }

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
