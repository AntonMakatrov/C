#include <stdio.h>
#include <stdlib.h>
#include "task2.h"
#include <assert.h>
void testResult()
{
    int i;
    float valuev[2][2] = {{1,2},{3,4}};
    char oper[4] = {'+','*','-','/'};
    float** val = (float**)malloc(2*sizeof(float*));
    for(i=0;i<2;i++)
    {
        val[i] = (float*)valuev[i];
    }
    
    assert(Result(oper,val,0,0) == 3);
    assert(Result(oper,val,1,1) == 12);
    assert(Result(oper,val,0,2) == -1);
    assert(Result(oper,val,1,3) == 0.75);
}

int main()
{
    testResult();
    printf("Tests passed succesfully");
    return 0;
}
