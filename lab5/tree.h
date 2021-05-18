#ifndef TASK_H
#define TASK_H

typedef struct item 
{
    int digit;
    struct item *next;
    struct item *prev;
} Item;

typedef struct mnumber 
{
    Item *head;
    Item *tail;
    int n;
} MNumber;

MNumber CreateMNumber(char *initStr);

unsigned long long int ReverseNumber(unsigned long long int number);

unsigned long long int ToOctal(unsigned long long int number);

void AddDigit(MNumber *number, int digit);

void PrintMNumber(MNumber number);

unsigned long long int NumberToDec(MNumber n1);

#endif