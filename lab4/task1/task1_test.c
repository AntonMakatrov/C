#include <time.h>
#include <stdio.h>
#include <assert.h>
#include "task1.h"

void testGetRandom()
{
    assert(GetRandom(1, 2) < 3 );
    assert(GetRandom(-5123,523) > -5125);
    assert(GetRandom(0,10)<11);
    assert(GetRandom(1, 2147483646)< 2147483647);
}
int main()
{
    testGetRandom();
    printf("Tests passed successfully");
    return 0;
}