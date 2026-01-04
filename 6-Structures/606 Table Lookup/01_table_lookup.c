/*
 * table_lookup.c
 * 
 * Structures organize lookup tables.
 * This example shows keyword recognition.
 */

#include <stdio.h>
#include <string.h>

struct keyword {
    char *word;
    int count;
};

struct keyword keytab[] = {     /* جدول الكلمات */
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"char", 0},
    {"const", 0}
};

int lookup(char *word);

main()
{
    int index;
    
    index = lookup("break");
    if (index >= 0)
        keytab[index].count++;
    
    printf("%s: %d\n", keytab[index].word, keytab[index].count);
}

int lookup(char *word)
{
    int i;
    
    for (i = 0; i < 5; i++)
        if (strcmp(keytab[i].word, word) == 0)
            return i;
    return -1;
}
