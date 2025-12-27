/*
 * ============================================================================
 * Chapter 1: Introduction
 * Section 1.8: Arguments – Call by Value
 * Topic: Value passing mechanism
 * ============================================================================
 * 
 * ما هو Call by Value؟
 * ---------------------
 * في C، عندما نُمرر متغيراً لدالة، يتم نسخ قيمته فقط.
 * الدالة تعمل على نسخة من القيمة، وليس المتغير الأصلي.
 * 
 * لماذا مهم؟
 * ----------
 * - فهم كيفية تمرير البيانات للدوال أساسي في C
 * - يمنع الدوال من تعديل المتغيرات الأصلية بدون قصد
 * - يوضح لماذا بعض التعديلات "لا تعمل" كما نتوقع
 * - أساس فهم الفرق مع المؤشرات (pointers) لاحقاً
 * 
 * القاعدة الذهبية:
 * -----------------
 * "في C، كل شيء يُمرر بالقيمة (by value)"
 * - المتغيرات: تُنسخ قيمها
 * - المصفوفات: استثناء خاص (سنراه في الملف التالي)
 * 
 * ============================================================================
 */

/*
 * ============================================================================
 * مثال تمهيدي: محاولة تعديل متغير
 * ============================================================================
 */

/*
 * دالة تحاول مضاعفة قيمة:
 * --------------------------
 */
int double_value(n)
int n;
{
    printf("  Inside function before: n = %d\n", n);
    
    /*
     * نضاعف n:
     * --------
     * لكن تذكر: n هنا هو نسخة من المتغير الأصلي
     * تعديل n لا يؤثر على المتغير الأصلي
     */
    n = n * 2;
    
    printf("  Inside function after:  n = %d\n", n);
    
    /*
     * نُرجع القيمة الجديدة:
     */
    return n;
}


main()
{
    int x;
    int result;
    
    printf("Example 1: Understanding call by value\n");
    printf("=======================================\n\n");
    
    /*
     * المتغير الأصلي:
     */
    x = 5;
    printf("Before function call: x = %d\n", x);
    
    /*
     * استدعاء الدالة:
     * --------------
     * ماذا يحدث؟
     * 1. قيمة x (وهي 5) تُنسخ
     * 2. النسخة تُمرر للدالة كـ n
     * 3. الدالة تعمل على n (النسخة)
     * 4. x الأصلي لا يتأثر!
     */
    printf("\nCalling double_value(x):\n");
    result = double_value(x);
    
    /*
     * بعد الاستدعاء:
     * --------------
     * x لم يتغير! لماذا؟
     * لأن الدالة عملت على نسخة، وليس على x نفسه
     */
    printf("\nAfter function call:  x = %d\n", x);
    printf("Returned value:       result = %d\n\n", result);
    
    /*
     * الخلاصة:
     * --------
     * - x لا يزال 5
     * - result يساوي 10
     * - لو أردنا تغيير x، يجب إسناد القيمة المُرجعة:
     */
    x = double_value(x);
    printf("After x = double_value(x): x = %d\n\n", x);
}


/*
 * ============================================================================
 * مثال توضيحي: تبديل قيمتين (محاولة خاطئة)
 * ============================================================================
 */

/*
 * محاولة تبديل قيمتين:
 * ---------------------
 * هذه الدالة لن تعمل كما نتوقع!
 */
int swap_wrong(a, b)
int a, b;
{
    int temp;
    
    printf("  Inside swap - before: a=%d, b=%d\n", a, b);
    
    /*
     * التبديل:
     * --------
     * نبادل a و b داخل الدالة
     */
    temp = a;
    a = b;
    b = temp;
    
    printf("  Inside swap - after:  a=%d, b=%d\n", a, b);
    
    /*
     * لماذا هذا خطأ؟
     * --------------
     * a و b هما نسخ من المتغيرات الأصلية
     * التبديل يحدث على النسخ فقط
     * المتغيرات الأصلية لا تتأثر!
     */
}


test_swap_wrong()
{
    int x, y;
    
    printf("Example 2: Why swap doesn't work\n");
    printf("=================================\n\n");
    
    x = 10;
    y = 20;
    
    printf("Before swap: x=%d, y=%d\n", x, y);
    
    swap_wrong(x, y);
    
    /*
     * المفاجأة:
     * ---------
     * x و y لم يتغيرا!
     */
    printf("After swap:  x=%d, y=%d\n\n", x, y);
    
    printf("Explanation: x and y are unchanged because\n");
    printf("the function worked on copies, not originals.\n\n");
}


/*
 * ============================================================================
 * مثال: تتبع القيم خطوة بخطوة
 * ============================================================================
 */

/*
 * دالة تعدل معاملها:
 */
int modify(n)
int n;
{
    printf("  [Function entry]    n = %d (copy of original)\n", n);
    
    n = n + 10;
    printf("  [After n = n + 10]  n = %d (modified copy)\n", n);
    
    n = n * 2;
    printf("  [After n = n * 2]   n = %d (modified copy)\n", n);
    
    printf("  [Function exit]     returning %d\n", n);
    
    return n;
}


trace_call_by_value()
{
    int original;
    int returned;
    
    printf("Example 3: Step-by-step trace\n");
    printf("==============================\n\n");
    
    original = 5;
    printf("[Before call]         original = %d\n\n", original);
    
    returned = modify(original);
    
    printf("\n[After call]          original = %d (unchanged!)\n", original);
    printf("[Returned value]      returned = %d\n\n", returned);
}


/*
 * ============================================================================
 * مثال عملي: حساب بدون تعديل
 * ============================================================================
 */

/*
 * دالة تحسب مربع عدد:
 * --------------------
 * لاحظ: n لا يتغير خارج الدالة
 */
int square(n)
int n;
{
    /*
     * يمكننا تعديل n بحرية داخل الدالة:
     */
    n = n * n;
    return n;
}


/*
 * دالة تحسب المضروب:
 */
int factorial(n)
int n;
{
    int result;
    
    result = 1;
    
    /*
     * نقلل n في كل مرة:
     * -----------------
     * هذا آمن لأن n نسخة
     */
    while (n > 1) {
        result = result * n;
        n = n - 1;  /* تعديل آمن للنسخة */
    }
    
    return result;
}


test_safe_modification()
{
    int num;
    int result;
    
    printf("Example 4: Safe modification of parameters\n");
    printf("===========================================\n\n");
    
    num = 5;
    printf("num = %d\n", num);
    
    result = square(num);
    printf("square(num) = %d, but num is still %d\n\n", result, num);
    
    num = 6;
    printf("num = %d\n", num);
    
    result = factorial(num);
    printf("factorial(num) = %d, but num is still %d\n\n", result, num);
}


/*
 * ============================================================================
 * مثال: متى نحتاج القيمة المُرجعة؟
 * ============================================================================
 */

/*
 * دالة تزيد عدد:
 */
int increment(n)
int n;
{
    return n + 1;
}


/*
 * دالة تنقص عدد:
 */
int decrement(n)
int n;
{
    return n - 1;
}


using_return_values()
{
    int counter;
    
    printf("Example 5: Using return values\n");
    printf("===============================\n\n");
    
    counter = 0;
    printf("counter = %d\n", counter);
    
    /*
     * طريقة خاطئة:
     * -----------
     * هذا لا يغير counter!
     */
    increment(counter);
    printf("After increment(counter): counter = %d (unchanged!)\n", counter);
    
    /*
     * طريقة صحيحة:
     * ------------
     * نستخدم القيمة المُرجعة:
     */
    counter = increment(counter);
    printf("After counter = increment(counter): counter = %d\n\n", counter);
    
    /*
     * يمكن استخدامها عدة مرات:
     */
    printf("Incrementing 5 times:\n");
    counter = increment(counter);
    printf("  counter = %d\n", counter);
    counter = increment(counter);
    printf("  counter = %d\n", counter);
    counter = increment(counter);
    printf("  counter = %d\n", counter);
    counter = increment(counter);
    printf("  counter = %d\n", counter);
    counter = increment(counter);
    printf("  counter = %d\n", counter);
}


/*
 * ============================================================================
 * مثال: مقارنة الأساليب
 * ============================================================================
 */

/*
 * أسلوب 1: تعديل داخلي وإرجاع
 */
int add_one_style1(n)
int n;
{
    n = n + 1;
    return n;
}


/*
 * أسلوب 2: إرجاع مباشر
 */
int add_one_style2(n)
int n;
{
    return n + 1;
}


compare_styles()
{
    int x;
    
    printf("\nExample 6: Different styles, same result\n");
    printf("=========================================\n\n");
    
    x = 10;
    
    printf("Original x = %d\n", x);
    printf("add_one_style1(x) = %d\n", add_one_style1(x));
    printf("add_one_style2(x) = %d\n", add_one_style2(x));
    printf("x is still = %d\n\n", x);
    
    printf("Both styles are equivalent due to call by value.\n");
    printf("Choose the clearer style for your code.\n");
}


/*
 * ============================================================================
 * Expected Output:
 * ============================================================================
 * Example 1: Understanding call by value
 * =======================================
 * 
 * Before function call: x = 5
 * 
 * Calling double_value(x):
 *   Inside function before: n = 5
 *   Inside function after:  n = 10
 * 
 * After function call:  x = 5
 * Returned value:       result = 10
 * 
 * After x = double_value(x): x = 10
 * 
 * Example 2: Why swap doesn't work
 * =================================
 * 
 * Before swap: x=10, y=20
 *   Inside swap - before: a=10, b=20
 *   Inside swap - after:  a=20, b=10
 * After swap:  x=10, y=20
 * 
 * Explanation: x and y are unchanged because
 * the function worked on copies, not originals.
 * 
 * Example 3: Step-by-step trace
 * ==============================
 * 
 * [Before call]         original = 5
 * 
 *   [Function entry]    n = 5 (copy of original)
 *   [After n = n + 10]  n = 15 (modified copy)
 *   [After n = n * 2]   n = 30 (modified copy)
 *   [Function exit]     returning 30
 * 
 * [After call]          original = 5 (unchanged!)
 * [Returned value]      returned = 30
 * 
 * Example 4: Safe modification of parameters
 * ===========================================
 * 
 * num = 5
 * square(num) = 25, but num is still 5
 * 
 * num = 6
 * factorial(num) = 720, but num is still 6
 * 
 * Example 5: Using return values
 * ===============================
 * 
 * counter = 0
 * After increment(counter): counter = 0 (unchanged!)
 * After counter = increment(counter): counter = 1
 * 
 * Incrementing 5 times:
 *   counter = 2
 *   counter = 3
 *   counter = 4
 *   counter = 5
 *   counter = 6
 * 
 * 
 * Example 6: Different styles, same result
 * =========================================
 * 
 * Original x = 10
 * add_one_style1(x) = 11
 * add_one_style2(x) = 11
 * x is still = 10
 * 
 * Both styles are equivalent due to call by value.
 * Choose the clearer style for your code.
 * 
 * ============================================================================
 * ملاحظات مهمة:
 * ============================================================================
 * 
 * 1. القاعدة الأساسية:
 *    - في C، المتغيرات تُمرر بالقيمة (by value)
 *    - الدالة تحصل على نسخة، وليس الأصل
 *    - تعديل المعامل لا يؤثر على المتغير الأصلي
 * 
 * 2. لماذا call by value مفيد؟
 *    - الأمان: الدوال لا تعدل بياناتك بدون قصد
 *    - الوضوح: كل دالة معزولة عن الأخرى
 *    - سهولة التتبع: لا تأثيرات جانبية غير متوقعة
 * 
 * 3. كيف نعدل متغير إذن؟
 *    - نستخدم القيمة المُرجعة: x = modify(x);
 *    - أو نستخدم المؤشرات (سنتعلمها لاحقاً)
 * 
 * 4. الأخطاء الشائعة:
 *    - توقع أن modify(x) يغير x
 *    - نسيان إسناد القيمة المُرجعة
 *    - محاولة كتابة swap بدون مؤشرات
 * 
 * 5. النمط الصحيح:
 *    - إذا أردت تعديل: x = function(x);
 *    - إذا أردت حساب فقط: y = function(x);
 * 
 * 6. تعديل المعامل داخل الدالة:
 *    - آمن تماماً
 *    - لا يؤثر خارج الدالة
 *    - مفيد للحسابات المؤقتة
 * 
 * ============================================================================
 */
