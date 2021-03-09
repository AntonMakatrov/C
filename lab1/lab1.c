#include <stdio.h>
#include <conio.h>

#define INT_MAX 32767
#include "lab1.h"

#ifndef TEST


int main()
{
    int ch1, sum, edge, counter;
    FibonacciCounter (&ch1, &counter, &sum, &edge);

    if (edge > INT_MAX && sum > INT_MAX)
    {
      printf("The desired number: %d\n", (edge - ch1));

      printf("Sum of numbers: %d\n",sum - ch1);
    }
    else
    {
      printf("The desired number: %d", edge);
      printf("Sum of numbers: %d\n",sum);
    }
    printf("The ordinal number ot the desired number: %d",counter);
    _getch();
    return 0;

}

#endif
void FibonacciCounter (int* PointCh1, int* PointCounter, int* PointSum, int* PointEdge)
{
  int ch1, ch2, sum, edge, counter;

  counter = 1;
  sum = 0;
  ch1 = 0;
  ch2 = 1;
  edge = 1;
  *PointCh1 = ch1;
  *PointCounter = counter;
  *PointSum = sum;
  *PointEdge = edge;
  do
  {
      *PointCh1 = ch2;
      ch2 = *PointEdge;
      *PointEdge = *PointCh1 + ch2;
      *PointSum += *PointCh1;
      *PointCounter = *PointCounter + 1;
  } while ( *PointEdge <= INT_MAX );
}
