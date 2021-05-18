#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "tree.h"

void testToOctal()
{
    assert(ToOctal(123) == 173);
    assert(ToOctal(45677) == 131155);
    assert(ToOctal(34524132) == 203545744);
}

void testReverseNumber()
{
    assert(ReverseNumber(123) == 321);
    assert(ReverseNumber(12345678912345) == 54321987654321);
    assert(ReverseNumber(645989746513) == 315647989546);
}
void main()
{
    testToOctal();
    printf("Tests passed succesfully");
}