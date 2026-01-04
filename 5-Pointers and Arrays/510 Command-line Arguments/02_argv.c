/*
 * argv.c
 * 
 * argv is an array of pointers to strings.
 * Each string is one command-line argument.
 */

#include <stdio.h>

main(int argc, char *argv[])
{
    int i;
    
    for (i = 0; i < argc; i++)  /* argv[0] هو اسم البرنامج */
        printf("arg %d: %s\n", i, argv[i]);
    
    /* تشغيل: ./program hello world
     * يطبع:
     * arg 0: ./program
     * arg 1: hello
     * arg 2: world
     */
}
