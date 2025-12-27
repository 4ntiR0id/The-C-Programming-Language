/*
 * ============================================================================
 * Chapter 1: Introduction
 * Section 1.10: External Variables and Scope
 * Topic: Scope rules
 * ============================================================================
 * 
 * ما هو النطاق (Scope)؟
 * -----------------------
 * النطاق هو الجزء من البرنامج الذي يمكن فيه استخدام متغير أو دالة
 * 
 * أنواع النطاق في C:
 * -------------------
 * 1. نطاق الدالة (Function Scope): داخل دالة واحدة
 * 2. نطاق الملف (File Scope): من نقطة التعريف حتى نهاية الملف
 * 3. نطاق الكتلة (Block Scope): داخل { }
 * 
 * لماذا مهم؟
 * ----------
 * - يمنع التضارب بين الأسماء
 * - يحمي البيانات من التعديل غير المقصود
 * - ينظم البرنامج بشكل منطقي
 * - يسمح بإعادة استخدام الأسماء في سياقات مختلفة
 * 
 * القواعد الأساسية:
 * ------------------
 * 1. المتغير المحلي يُخفي المتغير الخارجي بنفس الاسم
 * 2. لا يمكن الوصول لمتغير قبل تعريفه
 * 3. المتغيرات المحلية لها أولوية على الخارجية
 * 
 * ============================================================================
 */

/*
 * ============================================================================
 * مثال 1: النطاق الأساسي
 * ============================================================================
 */

/*
 * متغير خارجي:
 * يمكن الوصول إليه من كل الدوال بعد هذه النقطة
 */
int global_x = 100;


function1()
{
    /*
     * يمكننا الوصول لـ global_x هنا:
     */
    printf("function1: global_x = %d\n", global_x);
}


function2()
{
    /*
     * ويمكننا الوصول إليه هنا أيضاً:
     */
    printf("function2: global_x = %d\n", global_x);
    
    /*
     * ويمكننا تعديله:
     */
    global_x = 200;
    printf("function2: changed global_x to %d\n", global_x);
}


main()
{
    printf("Example 1: Basic scope\n");
    printf("======================\n\n");
    
    printf("main: global_x = %d\n", global_x);
    
    function1();
    function2();
    function1();  /* سيرى القيمة المعدلة */
    
    printf("\n");
}


/*
 * ============================================================================
 * مثال 2: إخفاء المتغيرات (Variable Shadowing)
 * ============================================================================
 */

int value = 10;  /* متغير خارجي */


test_shadowing()
{
    /*
     * متغير محلي بنفس الاسم:
     * ------------------------
     * هذا يُخفي المتغير الخارجي!
     */
    int value;
    
    printf("Example 2: Variable shadowing\n");
    printf("=============================\n\n");
    
    /*
     * value المحلي غير مُهيأ:
     */
    printf("Local value (uninitialized): %d\n", value);
    
    /*
     * تهيئة المحلي:
     */
    value = 99;
    printf("Local value (after init): %d\n", value);
    
    /*
     * ماذا عن المتغير الخارجي؟
     * لا يمكننا الوصول إليه مباشرة!
     * المتغير المحلي "يُخفيه"
     */
    
    printf("\nNote: External 'value' still exists but is hidden\n");
    printf("      We can only access the local 'value'\n\n");
}


verify_external_unchanged()
{
    /*
     * هنا لا يوجد متغير محلي value
     * لذلك نستطيع الوصول للخارجي:
     */
    printf("In another function, external value = %d\n", value);
    printf("(The external variable was never changed)\n\n");
}


/*
 * ============================================================================
 * مثال 3: نطاق الكتلة (Block Scope)
 * ============================================================================
 */

block_scope_demo()
{
    int outer = 1;
    
    printf("Example 3: Block scope\n");
    printf("======================\n\n");
    
    printf("Outer block: outer = %d\n", outer);
    
    /*
     * كتلة داخلية:
     * -----------
     */
    {
        int inner = 2;
        
        printf("Inner block: outer = %d, inner = %d\n", outer, inner);
        
        /*
         * يمكننا الوصول لـ outer و inner هنا
         */
        
        /*
         * تعريف متغير محلي يُخفي outer:
         */
        {
            int outer = 3;  /* متغير جديد! */
            
            printf("Innermost: outer = %d (shadows outer), inner = %d\n", 
                   outer, inner);
        }
        
        printf("Back to inner block: outer = %d\n", outer);
    }
    
    printf("Back to outer block: outer = %d\n", outer);
    
    /*
     * inner لم يعد موجوداً!
     * printf("inner = %d\n", inner);  ← خطأ!
     */
    
    printf("\n");
}


/*
 * ============================================================================
 * مثال 4: ترتيب التعريف مهم!
 * ============================================================================
 */

/*
 * هذه الدالة تُعرّف قبل external_var
 * لذلك لا يمكنها رؤيته بدون إعلان
 */
before_definition()
{
    /*
     * لو حاولنا استخدام external_var هنا:
     * printf("%d\n", external_var);  ← خطأ!
     * 
     * لأنه لم يُعرّف بعد
     */
    
    printf("before_definition: Cannot see external_var yet\n");
}


/*
 * الآن نُعرّف المتغير الخارجي:
 */
int external_var = 42;


/*
 * هذه الدالة بعد التعريف، يمكنها الوصول:
 */
after_definition()
{
    /*
     * الآن يمكننا استخدامه:
     */
    printf("after_definition: external_var = %d\n", external_var);
}


test_definition_order()
{
    printf("Example 4: Definition order matters\n");
    printf("====================================\n\n");
    
    before_definition();
    after_definition();
    
    printf("\nRule: Can only access external variables\n");
    printf("      defined BEFORE the function\n\n");
}


/*
 * ============================================================================
 * مثال 5: نطاق معاملات الدالة
 * ============================================================================
 */

function_with_params(param1, param2)
int param1, param2;
{
    /*
     * param1 و param2 محليان للدالة:
     * --------------------------------
     * - موجودان فقط داخل الدالة
     * - يمكن تعديلهما بدون تأثير خارجي
     * - يُدمران عند الخروج من الدالة
     */
    
    int local_var;
    
    printf("Example 5: Function parameter scope\n");
    printf("====================================\n\n");
    
    printf("Parameters: param1 = %d, param2 = %d\n", param1, param2);
    
    /*
     * تعديل المعاملات:
     */
    param1 = param1 * 2;
    param2 = param2 + 10;
    
    printf("Modified: param1 = %d, param2 = %d\n", param1, param2);
    
    /*
     * هذه التعديلات لا تؤثر على القيم الأصلية
     * خارج الدالة (call by value)
     */
}


test_parameter_scope()
{
    int a = 5;
    int b = 15;
    
    printf("Before call: a = %d, b = %d\n\n", a, b);
    
    function_with_params(a, b);
    
    printf("\nAfter call: a = %d, b = %d\n", a, b);
    printf("(unchanged because parameters are local)\n\n");
}


/*
 * ============================================================================
 * مثال 6: قواعد النطاق المعقدة
 * ============================================================================
 */

int x = 1;  /* خارجي */


complex_scope()
{
    int x = 2;  /* محلي للدالة */
    
    printf("Example 6: Complex scoping\n");
    printf("==========================\n\n");
    
    printf("Function level: x = %d\n", x);
    
    {
        int x = 3;  /* محلي للكتلة */
        
        printf("First block: x = %d\n", x);
        
        {
            int x = 4;  /* محلي لكتلة أعمق */
            
            printf("Second block: x = %d\n", x);
        }
        
        printf("Back to first block: x = %d\n", x);
    }
    
    printf("Back to function level: x = %d\n", x);
}


verify_external()
{
    printf("In another function: x = %d\n", x);
    printf("(This is the external x)\n\n");
}


/*
 * ============================================================================
 * مثال 7: قواعد البحث عن المتغيرات
 * ============================================================================
 */

int level0 = 0;


search_rules()
{
    int level1 = 1;
    
    printf("Example 7: Variable lookup rules\n");
    printf("=================================\n\n");
    
    printf("At function level:\n");
    printf("  level0 = %d (external)\n", level0);
    printf("  level1 = %d (local to function)\n", level1);
    
    {
        int level2 = 2;
        
        printf("\nAt first block:\n");
        printf("  level0 = %d (external)\n", level0);
        printf("  level1 = %d (from outer block)\n", level1);
        printf("  level2 = %d (local to this block)\n", level2);
        
        {
            int level3 = 3;
            
            printf("\nAt second block:\n");
            printf("  level0 = %d (external)\n", level0);
            printf("  level1 = %d (from function)\n", level1);
            printf("  level2 = %d (from first block)\n", level2);
            printf("  level3 = %d (local to this block)\n", level3);
        }
        
        /*
         * level3 لم يعد موجوداً
         */
    }
    
    /*
     * level2 و level3 لم يعودا موجودين
     */
    
    printf("\n");
    printf("Search order:\n");
    printf("1. Current block\n");
    printf("2. Outer blocks (inside to outside)\n");
    printf("3. Function level\n");
    printf("4. File level (external)\n");
}


/*
 * ============================================================================
 * مثال 8: نصائح عملية
 * ============================================================================
 */

practical_advice()
{
    printf("\nExample 8: Practical scoping advice\n");
    printf("====================================\n\n");
    
    printf("GOOD PRACTICES:\n");
    printf("---------------\n");
    printf("1. Use descriptive names\n");
    printf("   - Avoid generic names like 'x', 'temp'\n");
    printf("   - Use 'student_count', 'max_temperature'\n\n");
    
    printf("2. Minimize shadowing\n");
    printf("   - Don't reuse external variable names locally\n");
    printf("   - Can be confusing and error-prone\n\n");
    
    printf("3. Declare variables in smallest scope needed\n");
    printf("   - Prefer local over external\n");
    printf("   - Declare in innermost block possible\n\n");
    
    printf("4. Be careful with name conflicts\n");
    printf("   - Check for existing names before declaring\n");
    printf("   - Use prefixes for related variables\n\n");
    
    printf("5. Document external variables\n");
    printf("   - Comment their purpose\n");
    printf("   - Note which functions use them\n\n");
    
    printf("BAD PRACTICES:\n");
    printf("--------------\n");
    printf("1. Using same name at multiple levels\n");
    printf("2. Relying on shadowing behavior\n");
    printf("3. Excessive external variables\n");
    printf("4. Generic variable names everywhere\n");
}


/*
 * ============================================================================
 * Expected Output:
 * ============================================================================
 * Example 1: Basic scope
 * ======================
 * 
 * main: global_x = 100
 * function1: global_x = 100
 * function2: global_x = 100
 * function2: changed global_x to 200
 * function1: global_x = 200
 * 
 * Example 2: Variable shadowing
 * =============================
 * 
 * Local value (uninitialized): [random]
 * Local value (after init): 99
 * 
 * Note: External 'value' still exists but is hidden
 *       We can only access the local 'value'
 * 
 * In another function, external value = 10
 * (The external variable was never changed)
 * 
 * Example 3: Block scope
 * ======================
 * 
 * Outer block: outer = 1
 * Inner block: outer = 1, inner = 2
 * Innermost: outer = 3 (shadows outer), inner = 2
 * Back to inner block: outer = 1
 * Back to outer block: outer = 1
 * 
 * Example 4: Definition order matters
 * ====================================
 * 
 * before_definition: Cannot see external_var yet
 * after_definition: external_var = 42
 * 
 * Rule: Can only access external variables
 *       defined BEFORE the function
 * 
 * Example 5: Function parameter scope
 * ====================================
 * 
 * Before call: a = 5, b = 15
 * 
 * Parameters: param1 = 5, param2 = 15
 * Modified: param1 = 10, param2 = 25
 * 
 * After call: a = 5, b = 15
 * (unchanged because parameters are local)
 * 
 * Example 6: Complex scoping
 * ==========================
 * 
 * Function level: x = 2
 * First block: x = 3
 * Second block: x = 4
 * Back to first block: x = 3
 * Back to function level: x = 2
 * In another function: x = 1
 * (This is the external x)
 * 
 * Example 7: Variable lookup rules
 * =================================
 * 
 * At function level:
 *   level0 = 0 (external)
 *   level1 = 1 (local to function)
 * 
 * At first block:
 *   level0 = 0 (external)
 *   level1 = 1 (from outer block)
 *   level2 = 2 (local to this block)
 * 
 * At second block:
 *   level0 = 0 (external)
 *   level1 = 1 (from function)
 *   level2 = 2 (from first block)
 *   level3 = 3 (local to this block)
 * 
 * Search order:
 * 1. Current block
 * 2. Outer blocks (inside to outside)
 * 3. Function level
 * 4. File level (external)
 * 
 * Example 8: Practical scoping advice
 * ====================================
 * [See practical_advice output above]
 * 
 * ============================================================================
 * ملاحظات مهمة:
 * ============================================================================
 * 
 * 1. قاعدة البحث:
 *    - من الداخل للخارج
 *    - أول متغير يُوجد هو المستخدم
 * 
 * 2. الإخفاء (Shadowing):
 *    - المتغير المحلي يُخفي الخارجي
 *    - الخارجي لا يزال موجوداً، لكن لا يمكن الوصول إليه
 * 
 * 3. عمر المتغير:
 *    - الخارجي: طوال البرنامج
 *    - المحلي: فقط في نطاقه
 * 
 * 4. الأولوية:
 *    - محلي > خارجي
 *    - كتلة داخلية > كتلة خارجية
 * 
 * 5. النصيحة الذهبية:
 *    - استخدم أصغر نطاق ممكن
 *    - تجنب الإخفاء غير الضروري
 *    - أسماء واضحة ومميزة
 * 
 * ============================================================================
 */
