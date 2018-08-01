#include <stdio.h>
#include<stdlib.h>
//将一个字符串的空格替换成%20
//第一种情况，数组后面空间不足，需要重新开辟一块空间
char* space_replace(char* src,char* dest)
{
    if(src == NULL)
    {
        return NULL;
    }
    
    int i = 0;
    //用来遍历原数组，算出它的长度，新数组长度 = 源数组总长度+2*空格个数
    int src_length = 0;//src的总长度
    int space_length = 0;//src中空格字符的个数
    int dest_length = 0;//新开辟数组的长度
    while(src[i] != '\0')
    {
        if(src[i] == ' ')
        {
            space_length++;
        }
        src_length++;
        i++;
    }
    dest_length = src_length + 2 * space_length;
 //   printf("dest_length = %d\n",dest_length);
    char* p_src = src;
    char* p_dest = dest;
    while(*p_src !='\0'&& p_dest != &dest[dest_length])
    {
        if(*p_src != ' ')
        {   
            *p_dest = *p_src;
            p_dest++;
        }
        else
        {
            *(p_dest++) = '%';
            *(p_dest++) = '2';
            *(p_dest++) = '0';
        }
        p_src++;

    }
    *p_dest = '\0';
    return dest;

}
//第二种情况，数组后面空间足够大
//在原数组上进行扩容
void space_replace2(char *arr,int length)
{
    if(arr == NULL||length <= 0)
    {
        return;
    }
    int orign_length = 0;//原数组的长度
    int new_length = 0;//扩容之后的长度
    int space_length = 0;//空格的个数
    int i = 0;
    while(arr[i] != '\0')
    {
        if(arr[i] == ' ')
        {
            space_length++;
        }
        orign_length++;
        i++;
    }
    new_length = orign_length + 2 * space_length;
    if(new_length > length)
    {
        return;
    }
    //新数组长度 = 原数组长度 + 2 * 空格个数
   int orign_index = orign_length - 1;//指向原数组的最后
   int new_index = new_length - 1;//指向扩容后的新数组的最后

   while(orign_index >= 0 && orign_index < new_index)
   {
       if(arr[orign_index] != ' ')
       {
           arr[new_index] = arr[orign_index];
           new_index--;
       }
       else
       {
           arr[new_index--] = '0';
           arr[new_index--] = '2';
           arr[new_index--] = '%';
       }
      orign_index--;
   }
}
int main()
{
   char arr[] = " 234 56 ";
  //   char arr[] = "We are happy!"; 
  //  char arr[] = "hello!"; 
    char dest[20] = {0};
    printf("%s\n",space_replace(arr,dest));
    space_replace2(arr,128);
    printf("%s\n",arr);
    return 0;
}
