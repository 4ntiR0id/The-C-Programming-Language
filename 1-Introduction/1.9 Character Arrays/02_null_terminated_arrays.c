/*
 * ============================================================================
 * Chapter 1: Introduction
 * Section 1.9: Character Arrays
 * Topic: Null-terminated character arrays
 * ============================================================================
 * 
 * ما هو Null Termination؟
 * -------------------------
 * النصوص في C تنتهي بحرف خاص يسمى "null character" ويُكتب '\0'
 * قيمته العددية هي 0
 * 
 * لماذا مهم؟
 * ----------
 * - يُعلم نهاية النص بدون الحاجة لتخزين الطول منفصلاً
 * - كل دوال النصوص في C تعتمد عليه
 * - فهمه ضروري لتجنب أخطاء شائعة وخطيرة
 * 
 * المشاكل الشائعة:
 * -----------------
 * - نسيان '\0' → نص غير صحيح
 * - الكتابة فوق '\0' → فساد البيانات
 * - قراءة ما بعد '\0' → سلوك غير محدد
 * 
 * ============================================================================
 */

/*
 * ============================================================================
 * مثال 1: أهمية '\0'
 * ============================================================================
 */

main()
{
    char good_string[6];
    char bad_string[5];
    
    printf("Example 1: Importance of null terminator\n");
    printf("=========================================\n\n");
    
    /*
     * نص صحيح مع '\0':
     * -----------------
     */
    good_string[0] = 'H';
    good_string[1] = 'e';
    good_string[2] = 'l';
    good_string[3] = 'l';
    good_string[4] = 'o';
    good_string[5] = '\0';  /* ضروري! */
    
    printf("Good string: %s\n", good_string);
    
    
    /*
     * نص بدون '\0':
     * -------------
     * خطر! السلوك غير محدد
     */
    bad_string[0] = 'B';
    bad_string[1] = 'a';
    bad_string[2] = 'd';
    bad_string[3] = '!';
    bad_string[4] = '!';
    /* لا يوجد '\0' */
    
    printf("Bad string: %s\n", bad_string);
    /*
     * ماذا سيحدث؟
     * - printf ستستمر في القراءة بعد bad_string[4]
     * - ستقرأ ذاكرة عشوائية
     * - قد تطبع أحرف غريبة
     * - قد يتعطل البرنامج!
     */
    
    printf("\n");
}


/*
 * ============================================================================
 * مثال 2: '\0' في الذاكرة
 * ============================================================================
 */

visualize_null_terminator()
{
    char text[10];
    int i;
    
    printf("Example 2: Visualizing null terminator\n");
    printf("=======================================\n\n");
    
    /*
     * نص قصير:
     */
    text[0] = 'H';
    text[1] = 'i';
    text[2] = '\0';
    
    printf("String: '%s'\n", text);
    printf("String length: 2 characters\n");
    printf("Array size: 10 bytes\n\n");
    
    printf("Memory contents:\n");
    printf("Index | Char | ASCII | Note\n");
    printf("------|------|-------|-----\n");
    
    for (i = 0; i < 10; i = i + 1) {
        printf("  %d   |  ", i);
        
        /*
         * طباعة الحرف إذا كان قابلاً للطباعة:
         */
        if (text[i] >= 32 && text[i] < 127) {
            printf("%c", text[i]);
        } else if (text[i] == '\0') {
            printf("\\0");
        } else {
            printf("?");
        }
        
        printf("  |  %3d  | ", text[i]);
        
        /*
         * ملاحظة:
         */
        if (i == 0 || i == 1) {
            printf("String data");
        } else if (i == 2) {
            printf("Null terminator!");
        } else {
            printf("Beyond string (garbage)");
        }
        
        printf("\n");
    }
    
    printf("\n");
}


/*
 * ============================================================================
 * مثال 3: القراءة حتى '\0'
 * ============================================================================
 */

/*
 * دالة تطبع نص حرفاً بحرف:
 * --------------------------
 */
print_char_by_char(s)
char s[];
{
    int i;
    
    printf("Printing character by character:\n");
    
    i = 0;
    /*
     * نستمر حتى نجد '\0':
     */
    while (s[i] != '\0') {
        printf("  s[%d] = '%c' (ASCII %d)\n", i, s[i], s[i]);
        ++i;
    }
    
    printf("  s[%d] = '\\0' (ASCII %d) <- End of string\n", i, s[i]);
}


test_reading_until_null()
{
    char message[20];
    
    printf("Example 3: Reading until null\n");
    printf("==============================\n\n");
    
    message[0] = 'T';
    message[1] = 'e';
    message[2] = 's';
    message[3] = 't';
    message[4] = '\0';
    
    printf("String: '%s'\n\n", message);
    print_char_by_char(message);
    
    printf("\n");
}


/*
 * ============================================================================
 * مثال 4: نصوص متعددة في مصفوفة واحدة
 * ============================================================================
 */

multiple_strings_demo()
{
    char buffer[30];
    int pos;
    
    printf("Example 4: Multiple strings in one array\n");
    printf("=========================================\n\n");
    
    /*
     * نص أول:
     */
    buffer[0] = 'F';
    buffer[1] = 'i';
    buffer[2] = 'r';
    buffer[3] = 's';
    buffer[4] = 't';
    buffer[5] = '\0';
    
    /*
     * نص ثاني (بعد النص الأول):
     */
    pos = 6;
    buffer[pos] = 'S';
    buffer[pos + 1] = 'e';
    buffer[pos + 2] = 'c';
    buffer[pos + 3] = 'o';
    buffer[pos + 4] = 'n';
    buffer[pos + 5] = 'd';
    buffer[pos + 6] = '\0';
    
    /*
     * printf ترى فقط النص الأول:
     */
    printf("First string: '%s'\n", buffer);
    
    /*
     * للوصول للنص الثاني، نبدأ من موقعه:
     */
    printf("Second string: '%s'\n", buffer + 6);
    /*
     * buffer + 6 يُشير إلى بداية النص الثاني
     */
    
    printf("\n");
}


/*
 * ============================================================================
 * مثال 5: الأخطاء الشائعة
 * ============================================================================
 */

common_mistakes()
{
    char str1[5];
    char str2[10];
    int i;
    
    printf("Example 5: Common mistakes\n");
    printf("==========================\n\n");
    
    /*
     * خطأ 1: نسيان '\0'
     * ------------------
     */
    printf("Mistake 1: Forgetting null terminator\n");
    
    str1[0] = 'O';
    str1[1] = 'o';
    str1[2] = 'p';
    str1[3] = 's';
    /* نسينا str1[4] = '\0'; */
    
    printf("This is dangerous! String may print garbage.\n\n");
    
    
    /*
     * خطأ 2: حجم غير كافي
     * --------------------
     */
    printf("Mistake 2: Insufficient size\n");
    
    /* نريد تخزين "Hello" (5 أحرف) */
    /* char str3[5];  ← خطأ! نحتاج 6 */
    
    printf("Need 6 bytes for \"Hello\" (5 chars + \\0)\n");
    printf("Declaring char str[5] is wrong!\n\n");
    
    
    /*
     * خطأ 3: الكتابة بعد النهاية
     * ---------------------------
     */
    printf("Mistake 3: Writing past the end\n");
    
    str2[0] = 'O';
    str2[1] = 'K';
    str2[2] = '\0';
    
    printf("String: '%s'\n", str2);
    
    /* الآن لو كتبنا بعد '\0': */
    str2[3] = 'X';
    str2[4] = 'Y';
    str2[5] = 'Z';
    
    printf("Still: '%s'\n", str2);
    printf("Functions still see only \"OK\" because \\0 is at index 2\n");
    printf("But we corrupted memory after the string!\n\n");
}


/*
 * ============================================================================
 * مثال 6: التحقق من صحة النص
 * ============================================================================
 */

/*
 * دالة تتحقق من وجود '\0':
 * --------------------------
 */
int is_valid_string(s, max_length)
char s[];
int max_length;
{
    int i;
    
    /*
     * نبحث عن '\0' ضمن الحد الأقصى:
     */
    for (i = 0; i < max_length; i = i + 1) {
        if (s[i] == '\0') {
            return 1;  /* وجدناه - النص صحيح */
        }
    }
    
    return 0;  /* لم نجده - النص غير صحيح */
}


test_string_validation()
{
    char valid[10];
    char invalid[10];
    
    printf("Example 6: String validation\n");
    printf("============================\n\n");
    
    /*
     * نص صحيح:
     */
    valid[0] = 'O';
    valid[1] = 'K';
    valid[2] = '\0';
    
    if (is_valid_string(valid, 10)) {
        printf("'%s' is a valid string\n", valid);
    }
    
    /*
     * نص غير صحيح:
     */
    invalid[0] = 'B';
    invalid[1] = 'a';
    invalid[2] = 'd';
    /* لا يوجد '\0' في أول 10 خانات */
    
    if (!is_valid_string(invalid, 10)) {
        printf("String without \\0 is invalid\n");
    }
    
    printf("\n");
}


/*
 * ============================================================================
 * مثال 7: حساب الطول بطريقتين
 * ============================================================================
 */

/*
 * الطريقة 1: عد الأحرف حتى '\0'
 */
int length_method1(s)
char s[];
{
    int len;
    
    len = 0;
    while (s[len] != '\0') {
        ++len;
    }
    
    return len;
}


/*
 * الطريقة 2: البحث عن '\0' مباشرة
 */
int length_method2(s)
char s[];
{
    int i;
    
    i = 0;
    while (s[i]) {  /* s[i] يساوي 0 عند '\0' */
        ++i;
    }
    
    return i;
}


compare_length_methods()
{
    char text[20];
    
    printf("Example 7: Different ways to use null terminator\n");
    printf("=================================================\n\n");
    
    text[0] = 'T';
    text[1] = 'e';
    text[2] = 's';
    text[3] = 't';
    text[4] = '\0';
    
    printf("String: '%s'\n", text);
    printf("Length (method 1): %d\n", length_method1(text));
    printf("Length (method 2): %d\n", length_method2(text));
    printf("\nBoth methods rely on null terminator!\n\n");
}


/*
 * ============================================================================
 * مثال 8: تطبيق عملي - تنظيف نص
 * ============================================================================
 */

/*
 * دالة تُزيل المسافات من نهاية نص:
 * -----------------------------------
 */
int trim_trailing_spaces(s)
char s[];
{
    int len;
    
    /*
     * إيجاد الطول:
     */
    len = 0;
    while (s[len] != '\0') {
        ++len;
    }
    
    /*
     * العودة للخلف وحذف المسافات:
     */
    while (len > 0 && s[len - 1] == ' ') {
        --len;
    }
    
    /*
     * وضع '\0' في الموقع الجديد:
     */
    s[len] = '\0';
}


test_trim()
{
    char padded[20];
    
    printf("Example 8: Practical use - trimming\n");
    printf("====================================\n\n");
    
    padded[0] = 'H';
    padded[1] = 'e';
    padded[2] = 'l';
    padded[3] = 'l';
    padded[4] = 'o';
    padded[5] = ' ';
    padded[6] = ' ';
    padded[7] = ' ';
    padded[8] = '\0';
    
    printf("Before trim: '%s' (length %d)\n", padded, length_method1(padded));
    
    trim_trailing_spaces(padded);
    
    printf("After trim:  '%s' (length %d)\n", padded, length_method1(padded));
    
    printf("\nNote: We moved the \\0 to remove trailing spaces\n");
}


/*
 * ============================================================================
 * Expected Output:
 * ============================================================================
 * Example 1: Importance of null terminator
 * =========================================
 * 
 * Good string: Hello
 * Bad string: Bad!!��@#$ (garbage characters)
 * 
 * Example 2: Visualizing null terminator
 * =======================================
 * 
 * String: 'Hi'
 * String length: 2 characters
 * Array size: 10 bytes
 * 
 * Memory contents:
 * Index | Char | ASCII | Note
 * ------|------|-------|-----
 *   0   |  H  |   72  | String data
 *   1   |  i  |  105  | String data
 *   2   | \0  |    0  | Null terminator!
 *   3   |  ?  |   34  | Beyond string (garbage)
 *   4   |  ?  |   12  | Beyond string (garbage)
 *   ...
 * 
 * Example 3: Reading until null
 * ==============================
 * 
 * String: 'Test'
 * 
 * Printing character by character:
 *   s[0] = 'T' (ASCII 84)
 *   s[1] = 'e' (ASCII 101)
 *   s[2] = 's' (ASCII 115)
 *   s[3] = 't' (ASCII 116)
 *   s[4] = '\0' (ASCII 0) <- End of string
 * 
 * Example 4: Multiple strings in one array
 * =========================================
 * 
 * First string: 'First'
 * Second string: 'Second'
 * 
 * Example 5: Common mistakes
 * ==========================
 * 
 * Mistake 1: Forgetting null terminator
 * This is dangerous! String may print garbage.
 * 
 * Mistake 2: Insufficient size
 * Need 6 bytes for "Hello" (5 chars + \0)
 * Declaring char str[5] is wrong!
 * 
 * Mistake 3: Writing past the end
 * String: 'OK'
 * Still: 'OK'
 * Functions still see only "OK" because \0 is at index 2
 * But we corrupted memory after the string!
 * 
 * Example 6: String validation
 * ============================
 * 
 * 'OK' is a valid string
 * String without \0 is invalid
 * 
 * Example 7: Different ways to use null terminator
 * =================================================
 * 
 * String: 'Test'
 * Length (method 1): 4
 * Length (method 2): 4
 * 
 * Both methods rely on null terminator!
 * 
 * Example 8: Practical use - trimming
 * ====================================
 * 
 * Before trim: 'Hello   ' (length 8)
 * After trim:  'Hello' (length 5)
 * 
 * Note: We moved the \0 to remove trailing spaces
 * 
 * ============================================================================
 * ملاحظات حاسمة:
 * ============================================================================
 * 
 * 1. '\0' إلزامي:
 *    - كل نص يجب أن ينتهي به
 *    - قيمته العددية 0
 *    - يُكتب '\0' أو ببساطة 0
 * 
 * 2. الحجم:
 *    - النص الذي طوله n يحتاج مصفوفة حجمها n+1
 *    - الخانة الإضافية لـ '\0'
 *    - نسيان هذا يسبب مشاكل خطيرة
 * 
 * 3. الأمان:
 *    - نسيان '\0' يسبب:
 *      * قراءة ذاكرة غير مخصصة
 *      * طباعة "قمامة"
 *      * أخطاء segmentation fault
 *      * ثغرات أمنية
 * 
 * 4. الدوال:
 *    - كل دوال C القياسية تتوقع '\0'
 *    - printf, strlen, strcpy, strcmp, إلخ
 *    - بدونه، لن تعمل بشكل صحيح
 * 
 * 5. التحقق:
 *    - تحقق دائماً من وجود '\0'
 *    - تحقق من عدم تجاوز حدود المصفوفة
 *    - استخدم أحجام آمنة
 * 
 * 6. التعديل:
 *    - يمكن تحريك '\0' لتقصير النص
 *    - لكن لا تنسَ وضعه في المكان الصحيح
 * 
 * 7. المقارنة مع لغات أخرى:
 *    - Python/Java: النصوص كائنات، تعرف طولها
 *    - C: النصوص مصفوفات، '\0' يحدد النهاية
 *    - هذا يجعل C أسرع لكن أقل أماناً
 * 
 * ============================================================================
 */
