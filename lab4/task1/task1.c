#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "task1.h"
#ifndef TEST

int main()
{     
    char holiday[512];  
    char *surname[] = {"Ivanov","Petrov", "Sidorov","Aralin","Vashkevich",
                        "Krupenich", "Lazuk","Pronin","Ermakov","Dovgun"};
    char *wish[] = {"a lot of happiness","good luck in everything",
                    "success in your life in whatever you do", "every success",
                    "health", "best of everything", "to keep well and stay healthy"};
   
    scanf("%[^\n]s",holiday);
    srand(time(NULL));
   
    printf("Dear %s,\n", surname[GetRandom(0,sizeof(surname)/sizeof(surname[0])-1)]);
    printf("I want to wish you %s and hope you are doing well.\n", holiday);           
    printf("I want to wish you %s.\n", wish[GetRandom(0,sizeof(wish)/sizeof(wish[0])-1)]);     
    printf("May all your wishes come true.\n");          
            
    system("pause");
    return 0;
}

#endif

int GetRandom( int min,  int max) {
    return rand() % (max - min + 1) + min;
}