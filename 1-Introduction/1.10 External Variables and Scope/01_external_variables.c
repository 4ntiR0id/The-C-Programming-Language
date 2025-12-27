/*
 * ============================================================================
 * Chapter 1: Introduction
 * Section 1.10: External Variables and Scope
 * Topic: External variables
 * ============================================================================
 * 
 * ما هي المتغيرات الخارجية (External Variables)؟
 * --------------------------------------------------
 * المتغيرات المُعرّفة خارج كل الدوال، يمكن الوصول إليها من أي دالة
 * في الملف (أو حتى من ملفات أخرى مع extern)
 * 
 * الفرق بين المتغيرات المحلية والخارجية:
 * ------------------------------------------
 * - محلية (Local): داخل دالة، تُنشأ وتُدمر عند كل استدعاء
 * - خارجية (External): خارج الدوال، موجودة طوال عمر البرنامج
 * 
 * لماذا نحتاج متغيرات خارجية؟
 * -------------------------------
 * 1. مشاركة البيانات بين الدوال بدون تمريرها كمعاملات
 * 2. الحفاظ على الحالة بين استدعاءات الدوال
 * 3. تخزين بيانات كبيرة (مثل مصفوفات كبيرة)
 * 4. إنشاء متغيرات عامة للبرنامج
 * 
 * متى نستخدمها؟
 * ---------------
 * - عندما تحتاج عدة دوال للوصول لنفس البيانات
 * - عندما تكون البيانات كبيرة جداً للتمرير
 * - للإعدادات العامة أو الثوابت
 * 
 * تحذير:
 * -------
 * الإفراط في استخدامها يجعل البرنامج صعب الفهم والصيانة
 * استخدمها بحكمة!
 * 
 * ============================================================================
 */

/*
 * ============================================================================
 * مثال 1: المتغيرات المحلية vs الخارجية
 * ============================================================================
 */

/*
 * متغير خارجي:
 * ------------
 * مُعرّف خارج كل الدوال
 * يمكن لأي دالة الوصول إليه
 */
int global_counter;  /* متغير خارجي */


/*
 * دالة تستخدم المتغير الخارجي:
 */
increment_global()
{
    /*
     * نستطيع الوصول لـ global_counter مباشرة:
     * لا حاجة لتمريره كمعامل!
     */
    ++global_counter;
    printf("Global counter: %d\n", global_counter);
}


/*
 * دالة أخرى تستخدم نفس المتغير:
 */
double_global()
{
    global_counter = global_counter * 2;
    printf("Global counter doubled: %d\n", global_counter);
}


/*
 * دالة تستخدم متغير محلي:
 */
use_local()
{
    /*
     * متغير محلي:
     * -----------
     * موجود فقط داخل هذه الدالة
     * يُنشأ عند دخول الدالة
     * يُدمر عند الخروج منها
     */
    int local_counter;
    
    local_counter = 0;
    ++local_counter;
    printf("Local counter: %d\n", local_counter);
    
    /*
     * في كل مرة نستدعي الدالة، local_counter يبدأ من جديد
     */
}


main()
{
    printf("Example 1: Local vs External variables\n");
    printf("=======================================\n\n");
    
    /*
     * تهيئة المتغير الخارجي:
     */
    global_counter = 0;
    
    printf("Testing external variable:\n");
    increment_global();  /* global_counter = 1 */
    increment_global();  /* global_counter = 2 */
    double_global();     /* global_counter = 4 */
    
    printf("\nTesting local variable:\n");
    use_local();         /* local_counter = 1 */
    use_local();         /* local_counter = 1 مرة أخرى! */
    use_local();         /* local_counter = 1 دائماً! */
    
    printf("\nNote: External variable persists between calls\n");
    printf("      Local variable resets each time\n\n");
}


/*
 * ============================================================================
 * مثال 2: مشاركة بيانات بين دوال
 * ============================================================================
 */

/*
 * متغيرات خارجية لتخزين بيانات:
 */
int numbers[100];  /* مصفوفة خارجية */
int count;         /* عدد العناصر الحالي */


/*
 * دالة لإضافة رقم:
 */
add_number(n)
int n;
{
    /*
     * نستطيع الوصول لـ numbers و count مباشرة:
     */
    if (count < 100) {
        numbers[count] = n;
        ++count;
    }
}


/*
 * دالة لطباعة كل الأرقام:
 */
print_numbers()
{
    int i;
    
    printf("Numbers: ");
    for (i = 0; i < count; i = i + 1) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}


/*
 * دالة لحساب المجموع:
 */
int sum_numbers()
{
    int i, sum;
    
    sum = 0;
    for (i = 0; i < count; i = i + 1) {
        sum = sum + numbers[i];
    }
    
    return sum;
}


test_shared_data()
{
    printf("Example 2: Sharing data between functions\n");
    printf("==========================================\n\n");
    
    /*
     * تهيئة:
     */
    count = 0;
    
    /*
     * إضافة أرقام:
     */
    add_number(10);
    add_number(20);
    add_number(30);
    add_number(40);
    add_number(50);
    
    /*
     * استخدام البيانات المشتركة:
     */
    print_numbers();
    printf("Sum: %d\n", sum_numbers());
    printf("Count: %d\n\n", count);
}


/*
 * ============================================================================
 * مثال 3: برنامج عملي - آلة حاسبة بسيطة
 * ============================================================================
 */

/*
 * متغيرات خارجية للآلة الحاسبة:
 */
int accumulator;    /* المُجمع - يحفظ النتيجة */
int last_operation; /* آخر عملية */


/*
 * رموز العمليات:
 */
#define OP_ADD 1
#define OP_SUB 2
#define OP_MUL 3
#define OP_DIV 4


/*
 * عمليات الآلة الحاسبة:
 */
calc_add(n)
int n;
{
    accumulator = accumulator + n;
    last_operation = OP_ADD;
}


calc_subtract(n)
int n;
{
    accumulator = accumulator - n;
    last_operation = OP_SUB;
}


calc_multiply(n)
int n;
{
    accumulator = accumulator * n;
    last_operation = OP_MUL;
}


calc_divide(n)
int n;
{
    if (n != 0) {
        accumulator = accumulator / n;
        last_operation = OP_DIV;
    }
}


calc_clear()
{
    accumulator = 0;
    last_operation = 0;
}


calc_display()
{
    printf("Result: %d\n", accumulator);
}


calculator_demo()
{
    printf("Example 3: Calculator with external state\n");
    printf("==========================================\n\n");
    
    /*
     * تهيئة الآلة:
     */
    calc_clear();
    
    /*
     * سلسلة عمليات:
     * 10 + 5 * 2 - 3 = 17
     */
    accumulator = 10;
    calc_display();
    
    calc_add(5);
    calc_display();
    
    calc_multiply(2);
    calc_display();
    
    calc_subtract(3);
    calc_display();
    
    printf("\nNote: accumulator persists across function calls\n\n");
}


/*
 * ============================================================================
 * مثال 4: متى تكون المتغيرات الخارجية مفيدة؟
 * ============================================================================
 */

/*
 * مثال: برنامج يقرأ أطول سطر
 * (المثال الكلاسيكي من K&R بمتغيرات خارجية)
 */

#define MAXLINE 1000

char line[MAXLINE];      /* السطر الحالي */
char longest[MAXLINE];   /* أطول سطر حتى الآن */
int max;                 /* طول أطول سطر */


/*
 * دالة تقرأ سطر:
 */
int get_line()
{
    int c, i;
    
    /*
     * القراءة في المصفوفة الخارجية line:
     */
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    
    line[i] = '\0';
    
    return i;
}


/*
 * دالة تنسخ line إلى longest:
 */
copy_line()
{
    int i;
    
    i = 0;
    while ((longest[i] = line[i]) != '\0') {
        ++i;
    }
}


find_longest_with_externals()
{
    int len;
    
    printf("Example 4: Finding longest line (with externals)\n");
    printf("================================================\n");
    printf("Enter lines (Ctrl+D to end):\n\n");
    
    max = 0;
    while ((len = get_line()) > 0) {
        if (len > max) {
            max = len;
            copy_line();
        }
    }
    
    if (max > 0) {
        printf("\nLongest line (%d chars):\n%s\n", max, longest);
    }
}


/*
 * ============================================================================
 * مثال 5: مزايا وعيوب المتغيرات الخارجية
 * ============================================================================
 */

advantages_disadvantages()
{
    printf("\nExample 5: External variables - Pros and Cons\n");
    printf("==============================================\n\n");
    
    printf("ADVANTAGES:\n");
    printf("-----------\n");
    printf("1. No need to pass as parameters\n");
    printf("   - Simplifies function calls\n");
    printf("   - Useful when many functions need same data\n\n");
    
    printf("2. Persist between function calls\n");
    printf("   - Maintain state\n");
    printf("   - No re-initialization needed\n\n");
    
    printf("3. Efficient for large data\n");
    printf("   - No copying overhead\n");
    printf("   - Direct access\n\n");
    
    printf("DISADVANTAGES:\n");
    printf("--------------\n");
    printf("1. Hidden dependencies\n");
    printf("   - Hard to track which functions use which variables\n");
    printf("   - Difficult to debug\n\n");
    
    printf("2. Name conflicts\n");
    printf("   - Global names must be unique\n");
    printf("   - Can clash across files\n\n");
    
    printf("3. Less modular\n");
    printf("   - Functions not self-contained\n");
    printf("   - Harder to reuse\n\n");
    
    printf("RECOMMENDATION:\n");
    printf("---------------\n");
    printf("Use external variables when:\n");
    printf("- Multiple functions truly need shared state\n");
    printf("- Data is large (arrays, structures)\n");
    printf("- It simplifies the program significantly\n\n");
    
    printf("Prefer local variables and parameters when possible!\n");
}


/*
 * ============================================================================
 * Expected Output (أمثلة):
 * ============================================================================
 * Example 1: Local vs External variables
 * =======================================
 * 
 * Testing external variable:
 * Global counter: 1
 * Global counter: 2
 * Global counter doubled: 4
 * 
 * Testing local variable:
 * Local counter: 1
 * Local counter: 1
 * Local counter: 1
 * 
 * Note: External variable persists between calls
 *       Local variable resets each time
 * 
 * Example 2: Sharing data between functions
 * ==========================================
 * 
 * Numbers: 10 20 30 40 50 
 * Sum: 150
 * Count: 5
 * 
 * Example 3: Calculator with external state
 * ==========================================
 * 
 * Result: 10
 * Result: 15
 * Result: 30
 * Result: 27
 * 
 * Note: accumulator persists across function calls
 * 
 * Example 4: Finding longest line (with externals)
 * ================================================
 * Enter lines (Ctrl+D to end):
 * 
 * short
 * this is a longer line
 * mid
 * 
 * Longest line (22 chars):
 * this is a longer line
 * 
 * Example 5: External variables - Pros and Cons
 * ==============================================
 * 
 * [See advantages_disadvantages output above]
 * 
 * ============================================================================
 * ملاحظات مهمة:
 * ============================================================================
 * 
 * 1. التعريف والإعلان:
 *    - التعريف: خارج الدوال، يحجز ذاكرة
 *    - الإعلان: داخل دالة، يُخبر عن وجوده
 * 
 * 2. التهيئة:
 *    - المتغيرات الخارجية تُهيأ تلقائياً بـ 0
 *    - المتغيرات المحلية غير مُهيأة
 * 
 * 3. العمر (Lifetime):
 *    - خارجية: طوال عمر البرنامج
 *    - محلية: فقط خلال تنفيذ الدالة
 * 
 * 4. النطاق (Scope):
 *    - خارجية: من نقطة التعريف حتى نهاية الملف
 *    - محلية: فقط داخل الدالة
 * 
 * 5. الاستخدام الجيد:
 *    - للبيانات المشتركة حقاً
 *    - للمصفوفات الكبيرة
 *    - لحالة البرنامج العامة
 * 
 * 6. تجنب الإفراط:
 *    - لا تجعل كل شيء خارجي
 *    - استخدم المعاملات عندما يكون ذلك مناسباً
 *    - اجعل الدوال مستقلة قدر الإمكان
 * 
 * ============================================================================
 */
