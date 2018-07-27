#include <iostream>
#include <assert.h>
#include<string>
#include<string.h>
using namespace std;
class CMyString
{
public:
    CMyString(const char* pData)
        :m_pData(new char[strlen(pData) + 1])
    {
        strcpy(m_pData,pData);

    }
    //拷贝构造
    //s2(s1)
    CMyString(const CMyString& str)
        :m_pData(new char[strlen(str.m_pData) + 1])
    {
        strcpy(m_pData,str.m_pData);
    }
    //s=s1
    //s.operator=(this, s1)
    CMyString& operator=(const CMyString& str)
    {
        if(&str != this)
        {
            char* temp = new char[strlen(str.m_pData)+1];
            strcpy(temp,str.m_pData);
            delete[] m_pData;

            m_pData = temp;
        }
        return *this;

    }
    ~CMyString()
    {
        delete[] m_pData;
        m_pData = NULL;
    }
    char* _pData()
    {
        return m_pData;
    }
    char operator[](int pos)
    {
        assert(pos >= 0 && pos < strlen(m_pData));
        return m_pData[pos];
    }
    size_t Size()
    {
        return strlen(m_pData);
    }
private:
    char* m_pData;
};
int main()
{
    CMyString str1("hello world");
    /* char* m_pData = str1; */

    cout<<str1._pData()<<endl;
    size_t i = 0;
    for(; i < str1.Size(); ++i)
    {
        cout << str1[i] << " ";
    }
    cout << endl;
    CMyString str2(str1);
    cout<<str2._pData()<<endl;

    CMyString str3("hello!!!!!!");

    cout<<str3._pData()<<endl;

    str1 = str1;
    cout<<str1._pData()<<endl;
    
    str1 = str3; 
    cout<<str1._pData()<<endl;
    return 0;
}
