#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#ifndef TEST
int main()
{
    int check = 0;
  while(check == 0)
  {
    int Price, Result, Workdays, NumberOfDevelopers, answer;

    printf("Enter the price for creating the project:  ");
    Price = CorrectInput();

    printf("Enter the number of developers: ");
    NumberOfDevelopers = CorrectInput();

    Workdays = GetDateInfo();
    printf("The complexity of the project: %d human-hours, or %d human-days\n",
    Complexity(NumberOfDevelopers, Workdays),
    Complexity(NumberOfDevelopers, Workdays)/8);

    Result = Finances(Workdays);
    printf("Salary : %d\n", (Result*2/7));
    printf("Overhead costs : %d\n", (Result-(Result*2/7)));

    if((Price - Result) < 1000)
    {
      printf("This project is not profitable for development in our company.\n");
    }
    else
    {
      printf("This project is suitable for development in our company.\n");
    }
    answer = 2;

    while(answer != 1 && answer != 0)
    {
      printf("Proceed to processing the next one (Yes - 1; No - 0)?\n");
      scanf("%d", &answer);
      switch (answer)
      {
        case 1:
          check = 0 ;
          break;
        case 0:
          check = 1 ;
          break;
        default:
          printf("Incorrect answer.Try again\n");
      }
    }
  }

  printf("| - Author: AntonMakatrov - | --- | -  Version: 1.4.3 -  |\n");
  system("pause");
  return 0;
}
#endif

int GetDateInfo()
{
  int y1, y2, m1, m2, d1, d2, NumOfDays1, NumOfDays2, NumOfCalendar,
  NumOfWorkdays;

  char ch, ch1, goodCheck;
  char type1[6] = "start";
  char type2[4] = "end";
  printf("Enter the project start date: ");

  while(!scanf("%d%c%d%c%d", &d1, &ch, &m1, &ch1, &y1) ||
        !scanf("%c", &goodCheck) || goodCheck != '\n' ||
        ch != '.' || ch1 != '.' || d1 == 0 || m1 == 0 ||
        (d1 > 29 && m1 == 2 && ( y1%4 == 0 && (y1%100 != 0 && y1%400 == 0))) ||
        (d1 > 28 && m1 == 2 && y1%4 != 0) ||
        (d1 > 30 && (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)) ||
        (d1 > 31 && (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 ||
        m1 == 10 || m1 == 12)) || m1 > 12)
  {
      printf("Input error: incorrect date. Try again: ");
      fflush(stdin);
  }

  printf("Enter the project end date: ");


  while(!scanf("%d%c%d%c%d", &d2, &ch, &m2, &ch1, &y2) ||
        !scanf("%c", &goodCheck) || goodCheck != '\n' ||
        y2 < y1 || (y1 == y2 && m2 < m1) || (y1 == y2 && m1 == m2 && d2 < d1) ||
        ch != '.' || ch1 != '.' || d2 == 0 || m2 == 0 ||
        (d2 > 29 && m2 == 2 && ( y2%4 == 0 && (y2%100 != 0 && y2%400 == 0))) ||
        (d2 > 28 && m2 == 2 && y2%4 != 0) ||
        (d2 > 30 && (m2 == 4 || m2 == 6 || m2 == 9 || m2 == 11)) ||
        (d2 > 31 && (m2 == 1 || m2 == 3 || m2 == 5 || m2 == 7 || m2 == 8 ||
        m2 == 10 || m2 == 12)) || m2 > 12)
  {

      printf("Input error: incorrect date. Try again: ");
      fflush(stdin);
  }
  NumOfDays1 = 365 * y1 + y1/4 - y1/100 + y1/400 + (153*m1-457)/5 + d1 - 306;
  NumOfDays2 = 365 * y2 + y2/4 - y2/100 + y2/400 + (153*m2-457)/5 + d2 - 306;
  NumOfCalendar = NumOfDays2 - NumOfDays1;
  NumOfWorkdays =(int)((NumOfCalendar / 1.4) + 0.5);

  DateOutput(type1, y1, m1, d1, ch, ch1);

  DateOutput(type2, y2, m2, d2, ch, ch1);

  printf("Number of calendar days: %d\n", NumOfCalendar);
  printf("Number of work days: %d\n", NumOfWorkdays);

  return NumOfWorkdays;
}


int Complexity(int NumberOfDevelopers, int NumOfWorkdays)
{
  int HumanHours;
  NumOfWorkdays *= 8;
  HumanHours = NumberOfDevelopers * NumOfWorkdays;

  return HumanHours;
}

int Finances(int Workdays)
{
  int Salary, OverheadCosts, CostPrice;
  Salary = Workdays*8*9;
  OverheadCosts = Salary * 2.5;
  CostPrice = Salary + OverheadCosts;

  return CostPrice;
}

int CorrectInput()
{
  int temp;
  char goodCheck;

  while(!scanf("%d", &temp) || !scanf("%c", &goodCheck) || goodCheck != '\n')
  {
      printf("Wrong input! Please, try again: ");
      fflush(stdin);
  }

  return temp;
}

void DateOutput(char type[], int year, int month, int day, int ch, int ch1)
{
  if(month < 10 && day < 10)
  {
    printf("Project %s date: 0%d%c0%d%c%d\n",type, day, ch, month, ch1, year);
  }
  else if (month > 9 && day < 10)
  {
    printf("Project %s date: 0%d%c%d%c%d\n", type, day, ch, month, ch1, year);
  }
  else if (month < 10 && day > 9)
  {
    printf("Project %s date: %d%c0%d%c%d\n", type, day, ch, month, ch1, year);
  }
  else
  {
    printf("Project %s date: %d%c%d%c%d\n", type, day, ch, month, ch1, year);
  }
}
