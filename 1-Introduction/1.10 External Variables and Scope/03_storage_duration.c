/*
 * ============================================================================
 * Chapter 1: Introduction
 * Section 1.10: External Variables and Scope
 * Topic: Storage duration
 * ============================================================================
 * 
 * ما هي مدة التخزين (Storage Duration)؟
 * ----------------------------------------
 * مدة التخزين تحدد متى يُحجز ومتى يُحرر المكان في الذاكرة للمتغير
 * 
 * أنواع مدة التخزين:
 * ---------------------
 * 1. تلقائية (Automatic): تُنشأ وتُدمر مع كل استدعاء
 * 2. ثابتة (Static): موجودة طوال عمر البرنامج
 * 
 * الفرق بين النطاق ومدة التخزين:
 * -----------------------------------
 * - النطاق (Scope): أين يمكن استخدام المتغير؟
 * - مدة التخزين (Duration): متى يكون المتغير موجوداً في الذاكرة؟
 * 
 * لماذا مهم؟
 * ----------
 * - فهم عمر المتغيرات ضروري لتجنب الأخطاء
 * - معرفة متى تُهيأ المتغيرات
 * - فهم استمرارية القيم بين الاستدعاءات
 * 
 * ============================================================================
 */

/*
 * ============================================================================
 * مثال 1: المتغيرات التلقائية (Automatic Variables)
 * ============================================================================
 */

automatic_example()
{
    /*
     * متغير تلقائي (automatic):
     * -------------------------
     * - يُنشأ عند دخول الدالة
     * - يُدمر عند الخروج من الدالة
     * - غير مُهيأ تلقائياً (يحتوي قيمة عشوائية)
     * - قيمته لا تستمر بين الاستدعاءات
     */
    int automatic_var;
    
    printf("Example 1: Automatic variables\n");
    printf("===============================\n\n");
    
    printf("Automatic variable (uninitialized): %d\n", automatic_var);
    
    automatic_var = 42;
    printf("After initialization: %d\n", automatic_var);
    
    automatic_var = automatic_var + 10;
    printf("After increment: %d\n", automatic_var);
    
    printf("\nNote: This value will be lost when function returns\n\n");
}


/*
 * ============================================================================
 * مثال 2: المتغيرات الخارجية (External Variables)
 * ============================================================================
 */

/*
 * متغير خارجي:
 * ------------
 * - مدة تخزين ثابتة (static duration)
 * - موجود طوال عمر البرنامج
 * - يُهيأ تلقائياً بـ 0 إذا لم نُهيئه
 * - قيمته تستمر طوال البرنامج
 */
int external_counter;  /* يُهيأ تلقائياً بـ 0 */


increment_external()
{
    ++external_counter;
    printf("External counter: %d\n", external_counter);
}


test_external_duration()
{
    printf("Example 2: External variables (static duration)\n");
    printf("================================================\n\n");
    
    printf("Initial value: %d (auto-initialized to 0)\n", external_counter);
    
    increment_external();
    increment_external();
    increment_external();
    
    printf("\nNote: Value persists throughout program\n\n");
}


/*
 * ============================================================================
 * مثال 3: مقارنة بين التلقائي والثابت
 * ============================================================================
 */

compare_storage()
{
    /*
     * متغير تلقائي:
     */
    int auto_count;
    
    printf("Example 3: Comparing storage durations\n");
    printf("=======================================\n\n");
    
    /*
     * في كل استدعاء، auto_count يُنشأ من جديد:
     */
    auto_count = 0;
    ++auto_count;
    
    printf("Automatic: %d (always 1)\n", auto_count);
    printf("External:  %d (accumulates)\n", external_counter);
    
    ++external_counter;
}


test_comparison()
{
    int i;
    
    printf("Calling compare_storage 5 times:\n\n");
    
    external_counter = 0;  /* إعادة تعيين */
    
    for (i = 0; i < 5; i = i + 1) {
        compare_storage();
    }
    
    printf("\n");
}


/*
 * ============================================================================
 * مثال 4: التهيئة الافتراضية
 * ============================================================================
 */

/*
 * متغيرات خارجية بدون تهيئة صريحة:
 */
int uninitialized_external;
int array_external[5];


test_default_initialization()
{
    int uninitialized_local;
    int i;
    
    printf("Example 4: Default initialization\n");
    printf("==================================\n\n");
    
    /*
     * المتغيرات الخارجية تُهيأ تلقائياً بـ 0:
     */
    printf("External variable (not explicitly initialized): %d\n", 
           uninitialized_external);
    
    printf("External array: ");
    for (i = 0; i < 5; i = i + 1) {
        printf("%d ", array_external[i]);
    }
    printf("\n");
    
    /*
     * المتغيرات المحلية غير مُهيأة:
     */
    printf("Local variable (not initialized): %d (random/garbage)\n", 
           uninitialized_local);
    
    printf("\nRule: External = 0 by default, Local = undefined\n\n");
}


/*
 * ============================================================================
 * مثال 5: المتغيرات في حلقات
 * ============================================================================
 */

loop_variables_demo()
{
    int i;
    int outer_sum;
    
    printf("Example 5: Variables in loops\n");
    printf("==============================\n\n");
    
    outer_sum = 0;
    
    for (i = 0; i < 3; i = i + 1) {
        /*
         * inner_sum تُنشأ وتُدمر في كل تكرار:
         */
        int inner_sum;
        
        inner_sum = 0;  /* يجب التهيئة في كل مرة */
        
        inner_sum = inner_sum + i;
        outer_sum = outer_sum + i;
        
        printf("Iteration %d: inner_sum = %d, outer_sum = %d\n", 
               i, inner_sum, outer_sum);
    }
    
    printf("\nNote: inner_sum resets each iteration\n");
    printf("      outer_sum accumulates\n\n");
}


/*
 * ============================================================================
 * مثال 6: عمر المتغيرات في الذاكرة
 * ============================================================================
 */

int permanent = 100;  /* موجود طوال البرنامج */


lifetime_demo()
{
    int temporary = 200;  /* موجود فقط خلال هذا الاستدعاء */
    
    printf("Example 6: Variable lifetime\n");
    printf("============================\n\n");
    
    printf("Inside function:\n");
    printf("  permanent = %d (exists throughout program)\n", permanent);
    printf("  temporary = %d (exists only during this call)\n", temporary);
    
    /*
     * تعديل كلاهما:
     */
    permanent = permanent + 1;
    temporary = temporary + 1;
    
    printf("After modification:\n");
    printf("  permanent = %d\n", permanent);
    printf("  temporary = %d\n", temporary);
    
    printf("\nWhen function returns:\n");
    printf("  permanent still exists with value %d\n", permanent);
    printf("  temporary is destroyed\n");
}


test_lifetime()
{
    printf("First call:\n");
    lifetime_demo();
    
    printf("\nSecond call:\n");
    lifetime_demo();
    
    printf("\nNote: permanent keeps its value, temporary doesn't\n\n");
}


/*
 * ============================================================================
 * مثال 7: المصفوفات والتخزين
 * ============================================================================
 */

/*
 * مصفوفة خارجية:
 */
int global_array[100];  /* تُهيأ بـ 0، موجودة طوال البرنامج */


array_storage_demo()
{
    /*
     * مصفوفة محلية:
     */
    int local_array[100];  /* غير مُهيأة، تُنشأ في كل استدعاء */
    
    int i;
    
    printf("Example 7: Arrays and storage\n");
    printf("=============================\n\n");
    
    /*
     * المصفوفة الخارجية مُهيأة بـ 0:
     */
    printf("Global array (first 5): ");
    for (i = 0; i < 5; i = i + 1) {
        printf("%d ", global_array[i]);
    }
    printf("\n");
    
    /*
     * المصفوفة المحلية غير مُهيأة:
     */
    printf("Local array (first 5, uninitialized): ");
    for (i = 0; i < 5; i = i + 1) {
        printf("%d ", local_array[i]);
    }
    printf("(random)\n");
    
    /*
     * تعبئة المصفوفة المحلية:
     */
    for (i = 0; i < 5; i = i + 1) {
        local_array[i] = i * 10;
    }
    
    printf("Local array (after init): ");
    for (i = 0; i < 5; i = i + 1) {
        printf("%d ", local_array[i]);
    }
    printf("\n\n");
    
    printf("Note: Local array loses values after function returns\n");
    printf("      Global array keeps values\n\n");
}


/*
 * ============================================================================
 * مثال 8: ملخص مدة التخزين
 * ============================================================================
 */

storage_summary()
{
    printf("Example 8: Storage duration summary\n");
    printf("====================================\n\n");
    
    printf("AUTOMATIC STORAGE (Local variables):\n");
    printf("-------------------------------------\n");
    printf("When created: Upon function entry\n");
    printf("When destroyed: Upon function exit\n");
    printf("Initialization: Not automatic (random values)\n");
    printf("Persistence: None (recreated each call)\n");
    printf("Scope: Function/block where declared\n");
    printf("Examples: function parameters, local variables\n\n");
    
    printf("STATIC STORAGE (External variables):\n");
    printf("-------------------------------------\n");
    printf("When created: Program start\n");
    printf("When destroyed: Program end\n");
    printf("Initialization: Automatic to 0 if not specified\n");
    printf("Persistence: Throughout program execution\n");
    printf("Scope: From definition point to end of file\n");
    printf("Examples: variables defined outside functions\n\n");
}


/*
 * ============================================================================
 * مثال 9: اختيار النوع المناسب
 * ============================================================================
 */

choosing_storage_type()
{
    printf("Example 9: Choosing the right storage\n");
    printf("======================================\n\n");
    
    printf("USE AUTOMATIC (LOCAL) when:\n");
    printf("---------------------------\n");
    printf("1. Variable only needed within one function\n");
    printf("2. Each function call should start fresh\n");
    printf("3. Temporary calculations\n");
    printf("4. You want to minimize global state\n");
    printf("5. Function should be self-contained\n\n");
    
    printf("Examples:\n");
    printf("  - Loop counters (i, j)\n");
    printf("  - Temporary results\n");
    printf("  - Function parameters\n");
    printf("  - Local working arrays\n\n");
    
    printf("USE STATIC (EXTERNAL) when:\n");
    printf("---------------------------\n");
    printf("1. Multiple functions need access\n");
    printf("2. Value must persist between calls\n");
    printf("3. Large data structures (efficiency)\n");
    printf("4. Program-wide configuration\n");
    printf("5. Counters/accumulators\n\n");
    
    printf("Examples:\n");
    printf("  - Program state\n");
    printf("  - Large lookup tables\n");
    printf("  - Shared buffers\n");
    printf("  - Global configuration\n\n");
}


/*
 * ============================================================================
 * مثال 10: مخاطر ومزايا
 * ============================================================================
 */

dangers_and_benefits()
{
    printf("Example 10: Dangers and benefits\n");
    printf("=================================\n\n");
    
    printf("AUTOMATIC VARIABLES:\n");
    printf("-------------------\n");
    printf("Benefits:\n");
    printf("  + No interference between calls\n");
    printf("  + Functions are reentrant\n");
    printf("  + Memory freed automatically\n");
    printf("  + Clear lifetime\n\n");
    
    printf("Dangers:\n");
    printf("  - Must initialize before use\n");
    printf("  - Cannot share data easily\n");
    printf("  - Overhead of creation/destruction\n\n");
    
    printf("STATIC/EXTERNAL VARIABLES:\n");
    printf("--------------------------\n");
    printf("Benefits:\n");
    printf("  + Auto-initialized to 0\n");
    printf("  + Persistent state\n");
    printf("  + Easy sharing between functions\n");
    printf("  + Efficient for large data\n\n");
    
    printf("Dangers:\n");
    printf("  - Hidden dependencies\n");
    printf("  - Functions not independent\n");
    printf("  - Name conflicts possible\n");
    printf("  - Memory always allocated\n");
    printf("  - Harder to test/debug\n\n");
}


/*
 * ============================================================================
 * مثال 11: نصائح عملية
 * ============================================================================
 */

practical_tips()
{
    printf("Example 11: Practical tips\n");
    printf("==========================\n\n");
    
    printf("INITIALIZATION:\n");
    printf("---------------\n");
    printf("1. Always initialize automatic variables\n");
    printf("   int count = 0;  // Good\n");
    printf("   int count;      // Dangerous!\n\n");
    
    printf("2. External variables auto-init to 0\n");
    printf("   But explicit is clearer:\n");
    printf("   int total = 0;  // Clear intent\n\n");
    
    printf("NAMING:\n");
    printf("-------\n");
    printf("1. Use prefixes for external:\n");
    printf("   global_count, g_count\n\n");
    
    printf("2. Descriptive local names:\n");
    printf("   student_count vs count\n\n");
    
    printf("DESIGN:\n");
    printf("-------\n");
    printf("1. Default to automatic/local\n");
    printf("2. Use external only when necessary\n");
    printf("3. Document external variables\n");
    printf("4. Group related externals\n");
    printf("5. Consider passing via parameters\n\n");
}


/*
 * ============================================================================
 * الدالة الرئيسية - تشغيل كل الأمثلة
 * ============================================================================
 */

main()
{
    automatic_example();
    test_external_duration();
    test_comparison();
    test_default_initialization();
    loop_variables_demo();
    test_lifetime();
    array_storage_demo();
    storage_summary();
    choosing_storage_type();
    dangers_and_benefits();
    practical_tips();
}


/*
 * ============================================================================
 * Expected Output (مختصر):
 * ============================================================================
 * Example 1: Automatic variables
 * ===============================
 * 
 * Automatic variable (uninitialized): [random number]
 * After initialization: 42
 * After increment: 52
 * 
 * Note: This value will be lost when function returns
 * 
 * 
 * Example 2: External variables (static duration)
 * ================================================
 * 
 * Initial value: 0 (auto-initialized to 0)
 * External counter: 1
 * External counter: 2
 * External counter: 3
 * 
 * Note: Value persists throughout program
 * 
 * 
 * Example 3: Comparing storage durations
 * =======================================
 * 
 * Calling compare_storage 5 times:
 * 
 * Automatic: 1 (always 1)
 * External:  0 (accumulates)
 * Automatic: 1 (always 1)
 * External:  1 (accumulates)
 * Automatic: 1 (always 1)
 * External:  2 (accumulates)
 * ...
 * 
 * 
 * Example 4: Default initialization
 * ==================================
 * 
 * External variable (not explicitly initialized): 0
 * External array: 0 0 0 0 0 
 * Local variable (not initialized): [random] (random/garbage)
 * 
 * Rule: External = 0 by default, Local = undefined
 * 
 * 
 * Example 6: Variable lifetime
 * ============================
 * 
 * First call:
 * Inside function:
 *   permanent = 100 (exists throughout program)
 *   temporary = 200 (exists only during this call)
 * After modification:
 *   permanent = 101
 *   temporary = 201
 * 
 * When function returns:
 *   permanent still exists with value 101
 *   temporary is destroyed
 * 
 * Second call:
 * Inside function:
 *   permanent = 101 (exists throughout program)
 *   temporary = 200 (exists only during this call)
 * After modification:
 *   permanent = 102
 *   temporary = 201
 * 
 * Note: permanent keeps its value, temporary doesn't
 * 
 * [باقي الأمثلة تتبع نفس النمط]
 * 
 * ============================================================================
 * ملاحظات حاسمة:
 * ============================================================================
 * 
 * 1. التهيئة:
 *    - خارجية: تلقائياً = 0
 *    - محلية: غير مُهيأة (قيمة عشوائية)
 *    - يجب دائماً تهيئة المحلية قبل الاستخدام!
 * 
 * 2. العمر:
 *    - خارجية: من بداية البرنامج حتى نهايته
 *    - محلية: من دخول الدالة/الكتلة حتى الخروج منها
 * 
 * 3. الذاكرة:
 *    - خارجية: محجوزة دائماً
 *    - محلية: تُحجز وتُحرر ديناميكياً
 * 
 * 4. الاستمرارية:
 *    - خارجية: تحتفظ بقيمتها
 *    - محلية: تفقد قيمتها عند الخروج
 * 
 * 5. الأمان:
 *    - عدم تهيئة المحلية = خطر!
 *    - قد تحتوي أي قيمة عشوائية
 *    - يمكن أن تسبب أخطاء صعبة التعقب
 * 
 * 6. الكفاءة:
 *    - خارجية: لا overhead للإنشاء/الإتلاف
 *    - محلية: overhead بسيط لكن أكثر أماناً
 * 
 * 7. الاختيار:
 *    - افترض المحلية/التلقائية
 *    - استخدم الخارجية/الثابتة عند الحاجة فقط
 * 
 * 8. في K&R الأولى:
 *    - لا يوجد الكلمة المفتاحية static للمتغيرات المحلية
 *    - فقط تلقائي (محلي) أو خارجي
 *    - static أُضيفت في إصدارات لاحقة
 * 
 * ============================================================================
 */
