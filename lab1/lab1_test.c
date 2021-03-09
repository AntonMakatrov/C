#include "lab1.h"

#include <stdio.h>
#include <conio.h>
#include <assert.h>

#define INT_MAX 32767


void testFibonacciCounter (int* PointCh1, int* PointCounter, int* PointSum, int* PointEdge)
{
  int ch1, sum, edge, counter;

  counter = 1;
  sum = 0;
  ch1 = 0;
  edge = 1;
  FibonacciCounter(&ch1, &counter, &sum, &edge);
  assert(counter == 23);
  if (edge > INT_MAX && sum > INT_MAX)
  {
    assert((edge - ch1) == 28657);
    assert((sum - ch1) == 28656);

  }
  else
  {
    assert(edge == 28657);
    assert(sum == 28656);
  }
}

int main()
{
  int ch1, sum, edge, counter;
  testFibonacciCounter(&ch1, &counter, &sum, &edge);

  printf("Tests passed successfully\n");
  _getch();
  return 0;
}
