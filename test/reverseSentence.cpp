#include <iostream>
#include<string>
using namespace std;
class Solution {
public:
    //翻转单词顺序
    
    //将每一个单词反转
    void reverseWord(string& str,int l,int r)
    {
        if(str.size() == 0)
        {
            return;
        }
        while(l < r)
        {
            swap(str[l],str[r]);
            l++;
            r--;
        }
    }
    //反转整个句子
    //先将每个单词反转，然后再反转整个句子
    string ReverseSentence(string str) {
        if(str.size() == 0)
        {
            return str;
          //字符串为空
        }
        str += ' ';
        //这里加上一个空格，如果不加的话，最后一个单词不反转
        int cur = 0;
        int mark = 0;
        while(cur < str.size())
        {
            if(str[cur] == ' ')
            {
                //遇上一个空格，说明一个单词结束，将其反转
                reverseWord(str,mark,cur-1);
                mark = cur + 1;
            }
            cur++;
        }
        //获得字串的时候去掉多加上的一个空格
        //要不然反转整个句子后第一个字符为空格
        str = str.substr(0,str.size()-1);
        //反转整个句子
        reverseWord(str,0,str.size()-1);
        return str;

    }

};

