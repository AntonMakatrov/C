#include <stdio.h>
#include <stdlib.h>
#include "task2.h"
#ifndef TEST
int main(){
    char  *line,*oper, *tempchar, n;
    float **valuev, **temp, result;
    char num[10];
    int i, j, p = 0,k, pos = 0, numVal = 0, counter = 1;
    FILE* val;
    FILE* exp;
    val = fopen("value.txt", "r");
    valuev = (float**) malloc(1 *sizeof(float*));
    if(valuev == NULL)
    {
        exit(1);
    }
    valuev[0] = (float*) malloc(2*sizeof(float));
    if(valuev[0]==NULL)
    {
        exit(1);
    }
    line = (char*) malloc(256* sizeof(char));
    if(line == NULL)
    {
        exit(1);
    }
    oper = (char*) malloc(1* sizeof(char));
    if(oper == NULL)
    {
        exit(1);
    }

    i = 0;
    while(1)
    {
        n = fgetc(val);
        if(feof(val))
            break;
        line[i] = n;
        i++;
        tempchar=(char*) realloc(line, (i+1 )* sizeof(char)); 
        if(tempchar==NULL)
        {
            exit(1);
        } 
        line = tempchar;
          
             
    }
    line[i] = '\0';
    
    j = 0;
    for (i = 0; line[i] != '\0'; i++)
    {
        if (numVal > 1)
        {
            counter++;
            temp = (float**)realloc(valuev,counter*sizeof(float*));
            if(temp == NULL)
            {
                exit(1);
            }
            valuev = temp;
            valuev[counter-1] = (float*)malloc(2*sizeof(float));
            if(valuev[counter-1]==NULL)
            {
                exit(1);
            }
            
            pos++;
            numVal = 0;
        }
        
        
        if (line [i - 1] == '=')
        {
            while (line[i] != ' ')
            {
                num[j] = line[i];
                j++;
                i++;
            }
            num[j] = '\0';
            valuev[pos][numVal] = atof(num);
            
            numVal++;

            j = 0;
        }
        
            
    }
    fclose(val);
    exp = fopen("expression.txt","r");
    
    
    i = 0;
    while(1)
    {
        n = fgetc(exp);
        if(feof(exp))
            break;
        if(n != 'A'&& n!='B'&& n!='\n')
        {
           oper[i] = n; 
        }
        i++;
        tempchar=(char*) realloc(oper, (i+1 )* sizeof(char)); 
        if(tempchar==NULL)
        {
            exit(1);
        } 
        oper = tempchar;
           
    }
    oper[i] = '\0';
    
    fclose(exp);
    printf("Enter the line of values: ");
    scanf("%d", &counter);
    printf("-------------------------------------------------------------\n");
    for (k=0; k < i - 1; k++)
    {  
        if(Result(oper,valuev,counter,k) != 0)
        {
            printf("%f %c %f = %f\n",valuev[counter][p],oper[k],valuev[counter][p+1],Result(oper,valuev,counter,k));
            k++;
        }
        else 
        {
            printf("-------------------------------------------------------------\n");
        }
        
        p = 0;
    }
    printf("-------------------------------------------------------------\n");
    printf("-------------------------------------------------------------\n");
    free(valuev);
    for(i=0;i<counter;i++)
    {
        free(valuev[i]);
    }
    free(line);
    free(oper);
    free(temp);
    free(tempchar);

    system("pause");
    return 0;
}
#endif

float Result(char *oper, float** valuev, int counter,int k)
{
    int numVal = 0;
    float result = 0;
        switch(oper[k])
        {
            case '+': 
                result = valuev[counter][numVal] + valuev[counter][numVal+1];
                break;
            case '*':
                result = valuev[counter][numVal] * valuev[counter][numVal+1];
                break;
            case '-':
                result = valuev[counter][numVal] - valuev[counter][numVal+1];
                break;
            case '/':
                result = valuev[counter][numVal] / valuev[counter][numVal+1];
                break;
            default:
                
                break;
        }
    return result;
}