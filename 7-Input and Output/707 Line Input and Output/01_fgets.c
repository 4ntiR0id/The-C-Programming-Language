/*
 * fgets.c
 * 
 * fgets reads a line from a file.
 * It stops at newline or EOF.
 */

#include <stdio.h>

main()
{
    FILE *fp;
    char line[100];
    
    fp = fopen("test.txt", "r");
    if (fp == NULL)
        return 1;
    
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);         /* line يحتوي على \n */
    }
    
    fclose(fp);
    
    /* fgets أكثر أماناً من gets */
}
