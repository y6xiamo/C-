#include <iostream>
#include<stdlib.h>
void Test()
{
    int *p1  = (int*)malloc(sizeof(int)*4);
    free(p1);
    int *p2 = (int*)calloc(4,sizeof(int));
    int *p3 = (int*)realloc(p2,sizeof(int)*4);


}
int main()
{
    Test();
    return 0;
}
