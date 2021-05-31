#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#ifndef TEST

int main()
{
    char buffer[128];
   
    Item *root = NULL; 
    FILE *fp = fopen("ex52.txt", "r");
    if (!fp) 
        exit(1); 
    while (fgets(buffer, 128, fp) != NULL)
        AddNode(atoi(buffer), &root); 
    
    lvl(root);
    fclose(fp);
    system("pause");
    return 0;
}

#endif

