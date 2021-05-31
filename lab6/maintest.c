#include "tree.h"
#include <assert.h>

int check(const char *fileName) {
    char buffer[128];
    Item *root = NULL;
    FILE *fp = fopen(fileName, "r");
    if (!fp) {
        exit(1); 
    }

    while (fgets(buffer, 128, fp) != NULL){
        AddNode(atoi(buffer), &root); 
    }
    lvl(root);
    fclose(fp);
    printf("\n");
    return 0;
}



#undef main

int main() {
    assert(check("ex52.txt")==0);
    assert(check("file1.txt")==0);
    assert(check("file2.txt")==0);
    
    printf("All tests passed successfully");
    return 0;
}