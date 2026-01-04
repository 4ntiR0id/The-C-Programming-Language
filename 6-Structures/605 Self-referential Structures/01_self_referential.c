/*
 * self_referential_structures.c
 * 
 * A structure can contain a pointer to its own type.
 * This is used to build linked lists.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;          /* مؤشر لنفس النوع */
};

main()
{
    struct node *head;
    struct node *second;
    
    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    
    head->data = 10;
    head->next = second;        /* ربط العقد */
    
    second->data = 20;
    second->next = NULL;        /* نهاية القائمة */
    
    printf("%d -> %d\n", head->data, head->next->data);
    
    free(head);
    free(second);
}
