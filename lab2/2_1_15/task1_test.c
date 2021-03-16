#include "Functions.h"
#include <stdio.h>
#include <assert.h>

void testComplexity()
{
  assert(Complexity(12, 8) == 768);
  assert(Complexity(0, 12) == 0);
  assert(Complexity(10, 0) == 0);
  assert(Complexity(324, 12345) == 31998240);
  assert(Complexity(25, 40) == 8000);
}

void testFinances()
{
  assert(Finances(8) == 2016);
  assert(Finances(12) == 3024);
  assert(Finances(0) == 0);
  assert(Finances(12345) == 3110940);
  assert(Finances(40) == 10080);
}

int main()
{
  testFinances();
  testComplexity();
  printf("Tests passed succesfully\n");
  return 0;
}
