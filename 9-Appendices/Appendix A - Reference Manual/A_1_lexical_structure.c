/*
 * lexical_structure.c
 * 
 * The lexical structure defines how the language reads source code.
 * Tokens are the basic building blocks.
 */

#include <stdio.h>

main()
{
    /* الرموز (Tokens): الكلمات الأساسية، المعرفات، الثوابت، العمليات */
    
    int count;              /* معرف */
    count = 42;             /* ثابت */
    
    if (count > 0)          /* كلمات أساسية: if، عملية: > */
        printf("%d\n", count);
    
    /* المسافات البيضاء تفصل الرموز */
    /* التعليقات تُتجاهل */
}
