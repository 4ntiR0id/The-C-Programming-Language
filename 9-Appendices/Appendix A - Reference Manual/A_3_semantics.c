/*
 * semantics.c
 * 
 * Semantics defines what valid statements mean.
 * It specifies how programs behave.
 */

#include <stdio.h>

main()
{
    int x = 5;
    int y;
    
    /* معنى =: تعيين قيمة x إلى y */
    y = x;
    
    /* معنى +: جمع القيم */
    y = x + 3;
    
    /* معنى if: تنفيذ شرطي */
    if (x > 0)              /* إذا كان x موجباً */
        y = 1;              /* نفذ هذا */
    
    /* ترتيب التنفيذ: من الأعلى للأسفل */
}
