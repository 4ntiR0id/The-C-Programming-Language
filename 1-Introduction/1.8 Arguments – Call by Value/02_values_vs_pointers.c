/*
 * ============================================================================
 * Chapter 1: Introduction
 * Section 1.8: Arguments – Call by Value
 * Topic: Difference between values and pointers
 * ============================================================================
 * 
 * ما الفرق بين القيم والمؤشرات؟
 * --------------------------------
 * - القيم (Values): نسخ من البيانات
 * - المؤشرات (Pointers): عناوين في الذاكرة تشير للبيانات الأصلية
 * 
 * لماذا المصفوفات مختلفة؟
 * -------------------------
 * المصفوفات في C تُمرر "بالمرجع" فعلياً (عبر المؤشر)
 * - اسم المصفوفة هو مؤشر لأول عنصر
 * - عند تمرير مصفوفة، نمرر عنوانها وليس نسخة منها
 * - لذلك يمكن تعديل المصفوفة الأصلية!
 * 
 * هذا القسم يوضح:
 * -----------------
 * 1. سلوك المتغيرات العادية (call by value)
 * 2. سلوك المصفوفات (تُمرر بالمرجع عملياً)
 * 3. لماذا هذا الاختلاف موجود
 * 4. كيف نستفيد من كل طريقة
 * 
 * ملاحظة: سنتعلم المؤشرات بالتفصيل في فصول لاحقة
 * هنا نركز على الفهم الأساسي والفرق العملي
 * 
 * ============================================================================
 */

/*
 * ============================================================================
 * القسم الأول: المتغيرات العادية (تُمرر بالقيمة)
 * ============================================================================
 */

/*
 * دالة تحاول تعديل متغير عادي:
 */
int try_modify_value(n)
int n;
{
    printf("  Inside function: n = %d\n", n);
    n = 999;
    printf("  After change:    n = %d\n", n);
    
    /*
     * هذا التعديل لا يؤثر على المتغير الأصلي
     * لأن n هو نسخة
     */
}


/*
 * ============================================================================
 * القسم الثاني: المصفوفات (تُمرر بالمرجع عملياً)
 * ============================================================================
 */

/*
 * دالة تعدل مصفوفة:
 * -----------------
 * لاحظ: arr هو مؤشر لأول عنصر في المصفوفة الأصلية
 */
int modify_array(arr, size)
int arr[];
int size;
{
    int i;
    
    printf("  Inside function - modifying array:\n");
    for (i = 0; i < size; i = i + 1) {
        printf("    Before: arr[%d] = %d\n", i, arr[i]);
        
        /*
         * هذا التعديل يؤثر على المصفوفة الأصلية!
         * لماذا؟ لأن arr هو عنوان المصفوفة، وليس نسخة منها
         */
        arr[i] = arr[i] * 10;
        
        printf("    After:  arr[%d] = %d\n", i, arr[i]);
    }
}


main()
{
    int number;
    int numbers[5];
    int i;
    
    /*
     * ========================================================================
     * مثال 1: المتغيرات العادية لا تتغير
     * ========================================================================
     */
    
    printf("Example 1: Regular variables (call by value)\n");
    printf("=============================================\n\n");
    
    number = 42;
    printf("Before function: number = %d\n\n", number);
    
    try_modify_value(number);
    
    printf("\nAfter function:  number = %d\n", number);
    printf("                 (unchanged!)\n\n\n");
    
    
    /*
     * ========================================================================
     * مثال 2: المصفوفات تتغير!
     * ========================================================================
     */
    
    printf("Example 2: Arrays (passed by reference)\n");
    printf("========================================\n\n");
    
    /*
     * تعبئة المصفوفة:
     */
    for (i = 0; i < 5; i = i + 1) {
        numbers[i] = i + 1;
    }
    
    printf("Before function: ");
    for (i = 0; i < 5; i = i + 1) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");
    
    /*
     * استدعاء الدالة:
     */
    modify_array(numbers, 5);
    
    printf("\nAfter function:  ");
    for (i = 0; i < 5; i = i + 1) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("                 (changed!)\n\n");
}


/*
 * ============================================================================
 * مثال توضيحي: لماذا المصفوفات مختلفة؟
 * ============================================================================
 */

/*
 * دالة توضح الفرق:
 */
explain_difference()
{
    int x;
    int arr[3];
    int i;
    
    printf("\nExample 3: Why arrays are different\n");
    printf("====================================\n\n");
    
    x = 5;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    
    printf("When we pass 'x':\n");
    printf("  - The VALUE 5 is copied\n");
    printf("  - Function gets a copy: n = 5\n");
    printf("  - Original x is protected\n\n");
    
    printf("When we pass 'arr':\n");
    printf("  - The ADDRESS of arr[0] is passed\n");
    printf("  - Function gets a pointer to original data\n");
    printf("  - Function can modify original array\n\n");
    
    printf("This is why:\n");
    printf("  - int var:   call by value (copy)\n");
    printf("  - int arr[]: call by reference (address)\n\n");
}


/*
 * ============================================================================
 * مثال عملي: تطبيقات مفيدة
 * ============================================================================
 */

/*
 * دالة تملأ مصفوفة بقيمة:
 * -------------------------
 * هذا مفيد لأننا نريد تعديل المصفوفة الأصلية
 */
int fill_array(arr, size, value)
int arr[];
int size;
int value;
{
    int i;
    
    for (i = 0; i < size; i = i + 1) {
        arr[i] = value;
    }
}


/*
 * دالة تضاعف كل عناصر مصفوفة:
 */
int double_array(arr, size)
int arr[];
int size;
{
    int i;
    
    for (i = 0; i < size; i = i + 1) {
        arr[i] = arr[i] * 2;
    }
}


/*
 * دالة تعكس مصفوفة:
 */
int reverse_array(arr, size)
int arr[];
int size;
{
    int i, temp;
    
    for (i = 0; i < size / 2; i = i + 1) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}


/*
 * دالة تطبع مصفوفة:
 * -----------------
 * لاحظ: هنا لا نعدل، فقط نقرأ
 * لكن لا يزال يُمرر العنوان (كفاءة)
 */
int print_array(arr, size)
int arr[];
int size;
{
    int i;
    
    printf("Array: ");
    for (i = 0; i < size; i = i + 1) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


practical_examples()
{
    int data[6];
    int i;
    
    printf("\nExample 4: Practical uses\n");
    printf("=========================\n\n");
    
    /*
     * استخدام fill_array:
     */
    printf("Filling array with 0:\n");
    fill_array(data, 6, 0);
    print_array(data, 6);
    printf("\n");
    
    /*
     * تعبئة بقيم:
     */
    printf("Filling with values 1-6:\n");
    for (i = 0; i < 6; i = i + 1) {
        data[i] = i + 1;
    }
    print_array(data, 6);
    printf("\n");
    
    /*
     * المضاعفة:
     */
    printf("After doubling:\n");
    double_array(data, 6);
    print_array(data, 6);
    printf("\n");
    
    /*
     * العكس:
     */
    printf("After reversing:\n");
    reverse_array(data, 6);
    print_array(data, 6);
}


/*
 * ============================================================================
 * مثال: ماذا لو أردنا حماية المصفوفة؟
 * ============================================================================
 */

/*
 * دالة تحسب مجموع بدون تعديل:
 * ------------------------------
 * هذه الدالة تقرأ فقط، لا تعدل
 */
int array_sum(arr, size)
int arr[];
int size;
{
    int sum;
    int i;
    
    sum = 0;
    for (i = 0; i < size; i = i + 1) {
        sum = sum + arr[i];
    }
    
    return sum;
}


/*
 * دالة تبحث بدون تعديل:
 */
int find_max(arr, size)
int arr[];
int size;
{
    int max;
    int i;
    
    max = arr[0];
    for (i = 1; i < size; i = i + 1) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    return max;
}


read_only_functions()
{
    int values[5];
    int i;
    
    printf("\n\nExample 5: Read-only array functions\n");
    printf("=====================================\n\n");
    
    /*
     * تعبئة:
     */
    for (i = 0; i < 5; i = i + 1) {
        values[i] = (i + 1) * 10;
    }
    
    printf("Array: ");
    print_array(values, 5);
    
    /*
     * هذه الدوال لا تعدل المصفوفة:
     */
    printf("\nSum: %d\n", array_sum(values, 5));
    printf("Max: %d\n", find_max(values, 5));
    
    printf("\nArray unchanged: ");
    print_array(values, 5);
    
    printf("\nNote: Even though arrays are passed by reference,\n");
    printf("these functions don't modify the original array.\n");
}


/*
 * ============================================================================
 * مثال: المقارنة المباشرة
 * ============================================================================
 */

/*
 * دالة تحاول تعديل كلاهما:
 */
int try_modify_both(n, arr, size)
int n;
int arr[];
int size;
{
    int i;
    
    printf("  Modifying parameter n:\n");
    printf("    Before: n = %d\n", n);
    n = 999;
    printf("    After:  n = %d\n\n", n);
    
    printf("  Modifying array:\n");
    for (i = 0; i < size; i = i + 1) {
        printf("    Before: arr[%d] = %d\n", i, arr[i]);
        arr[i] = arr[i] + 100;
        printf("    After:  arr[%d] = %d\n", i, arr[i]);
    }
}


direct_comparison()
{
    int num;
    int nums[3];
    int i;
    
    printf("\n\nExample 6: Direct comparison\n");
    printf("============================\n\n");
    
    num = 10;
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    
    printf("Before function:\n");
    printf("  num = %d\n", num);
    printf("  nums = ");
    for (i = 0; i < 3; i = i + 1) {
        printf("%d ", nums[i]);
    }
    printf("\n\n");
    
    try_modify_both(num, nums, 3);
    
    printf("\nAfter function:\n");
    printf("  num = %d (unchanged - call by value)\n", num);
    printf("  nums = ");
    for (i = 0; i < 3; i = i + 1) {
        printf("%d ", nums[i]);
    }
    printf("(changed - passed by reference)\n");
}


/*
 * ============================================================================
 * Expected Output:
 * ============================================================================
 * Example 1: Regular variables (call by value)
 * =============================================
 * 
 * Before function: number = 42
 * 
 *   Inside function: n = 42
 *   After change:    n = 999
 * 
 * After function:  number = 42
 *                  (unchanged!)
 * 
 * 
 * Example 2: Arrays (passed by reference)
 * ========================================
 * 
 * Before function: 1 2 3 4 5 
 * 
 *   Inside function - modifying array:
 *     Before: arr[0] = 1
 *     After:  arr[0] = 10
 *     Before: arr[1] = 2
 *     After:  arr[1] = 20
 *     Before: arr[2] = 3
 *     After:  arr[2] = 30
 *     Before: arr[3] = 4
 *     After:  arr[3] = 40
 *     Before: arr[4] = 5
 *     After:  arr[4] = 50
 * 
 * After function:  10 20 30 40 50 
 *                  (changed!)
 * 
 * 
 * Example 3: Why arrays are different
 * ====================================
 * 
 * When we pass 'x':
 *   - The VALUE 5 is copied
 *   - Function gets a copy: n = 5
 *   - Original x is protected
 * 
 * When we pass 'arr':
 *   - The ADDRESS of arr[0] is passed
 *   - Function gets a pointer to original data
 *   - Function can modify original array
 * 
 * This is why:
 *   - int var:   call by value (copy)
 *   - int arr[]: call by reference (address)
 * 
 * 
 * Example 4: Practical uses
 * =========================
 * 
 * Filling array with 0:
 * Array: 0 0 0 0 0 0 
 * 
 * Filling with values 1-6:
 * Array: 1 2 3 4 5 6 
 * 
 * After doubling:
 * Array: 2 4 6 8 10 12 
 * 
 * After reversing:
 * Array: 12 10 8 6 4 2 
 * 
 * 
 * Example 5: Read-only array functions
 * =====================================
 * 
 * Array: Array: 10 20 30 40 50 
 * 
 * Sum: 150
 * Max: 50
 * 
 * Array unchanged: Array: 10 20 30 40 50 
 * 
 * Note: Even though arrays are passed by reference,
 * these functions don't modify the original array.
 * 
 * 
 * Example 6: Direct comparison
 * ============================
 * 
 * Before function:
 *   num = 10
 *   nums = 1 2 3 
 * 
 *   Modifying parameter n:
 *     Before: n = 10
 *     After:  n = 999
 * 
 *   Modifying array:
 *     Before: arr[0] = 1
 *     After:  arr[0] = 101
 *     Before: arr[1] = 2
 *     After:  arr[1] = 102
 *     Before: arr[2] = 3
 *     After:  arr[2] = 103
 * 
 * After function:
 *   num = 10 (unchanged - call by value)
 *   nums = 101 102 103 (changed - passed by reference)
 * 
 * ============================================================================
 * ملاحظات مهمة:
 * ============================================================================
 * 
 * 1. القاعدة الأساسية:
 *    - المتغيرات العادية: call by value (تُنسخ)
 *    - المصفوفات: تُمرر بالمرجع عملياً (العنوان يُمرر)
 * 
 * 2. لماذا المصفوفات مختلفة؟
 *    - الكفاءة: نسخ مصفوفة كبيرة مكلف
 *    - العملية: غالباً نريد تعديل المصفوفة الأصلية
 *    - التصميم: اسم المصفوفة هو مؤشر
 * 
 * 3. الفوائد:
 *    - متغيرات: آمنة من التعديل غير المقصود
 *    - مصفوفات: كفاءة عالية، يمكن تعديلها
 * 
 * 4. الحذر المطلوب:
 *    - مع المتغيرات: تذكر استخدام القيمة المُرجعة
 *    - مع المصفوفات: كن حذراً، أي تعديل يؤثر على الأصل
 * 
 * 5. الأنماط الجيدة:
 *    - إذا لا تريد تعديل مصفوفة، لا تعدلها (واضح من اسم الدالة)
 *    - مثل: find_max, array_sum (قراءة فقط)
 *    - مقابل: sort_array, reverse_array (تعديل واضح)
 * 
 * 6. في المستقبل:
 *    - سنتعلم المؤشرات للتحكم الكامل
 *    - يمكننا حينها تمرير عناوين المتغيرات العادية أيضاً
 *    - لكن المصفوفات دائماً تُمرر بالعنوان
 * 
 * ============================================================================
 */
