#include <stdio.h>
#include<assert.h>

#define row 3
#define col 3
//杨氏矩阵
int young_tableaus(int arr[][col],int key)
{
    assert(arr);
    int i = 0;
    int j = col - 1;
    while(i < row && j >= 0)
    {
        if(key > arr[row-1][col-1] ||key < arr[0][0])
        {
            return 0;
        }
        else
        {

          if(key < arr[i][j])
          {
            j--;
          }
          else if(key > arr[i][j])
          {
            i++;
          }
          else
          {
            return 1;
          }
        }
    }
    return 0;
}
int main()
{
    int arr[row][col] = {
                   {1,2,3},
                   {4,5,6},
                   {7,9,11}
                   };
    int key = 8;
//int i = 0;
//   printf("请输入数组:\n");
//    for( ;i < row;i++)
//    {
//        int j = 0;
//        for( ;j < col;j++)
//        {
//            scanf("%d ",&arr[i][j]);
//        }
//    }
//    printf("请输入要查找的数:");
//    scanf("%d\n",&key);
    int ret = young_tableaus(arr,key);
    if(ret == 1)
    {
        printf("找到了\n");
    }
    else
    {
        printf("没有找到\n");
    }
    return 0;
}
