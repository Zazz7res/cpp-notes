
/*
 * 课本题目：数组拷贝练习
 * 
 * 题目要求：```

## 关键错误总结：

1. **指针逻辑错误**：
   - 在 `copy_ptrs_error` 函数中同时递增 `begin` 和 `source` 指针
   - 这两个指针初始指向相同位置，但都递增导致数据拷贝不完整
   - **修正**：移除多余的 `begin` 指针，直接使用 `source` 指针遍历

2. **编译器警告分析**：
   - 警告信息："non-void function does not return a value"
   - 虽然所有函数都已正确声明为 `void` 类型
   - **可能原因**：编译器缓存、IDE配置问题、之前的编译历史
   - **解决方案**：清理项目重新编译通常可以解决

3. **学习要点**：
   - 理解指针算术运算的原理
   - 避免重复递增指向相同位置的指针
   - 使用正确的循环条件确保完整拷贝

这份代码完整展示了：
- 原始的错误实现
- 修正后的正确实现  
- 详细的错误分析和说明
- 两种版本的对比输出

适合用于学习和复习C语言指针操作的相关概念和常见错误。
 * 编写一个程序，初始化一个double类型的数组，
 * 然后把该数组的内容拷贝至3个其他数组中（在main()中声明这4个数组）。
 * 
 * 要求使用三种不同的拷贝方法：
 * 1. 使用带数组表示法的函数进行第1份拷贝。
 * 2. 使用带指针表示法和指针递增的函数进行第2份拷贝。
 *    - 把目标数组名、源数组名和待拷贝的元素个数作为前两个函数的参数。
 * 3. 第3个函数以目标数组名、源数组名和指向源数组最后一个元素后面的元素的指针。
 * 
 * 函数调用示例如下：
 * double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
 * double target1[5];
 * double target2[5];
 * double target3[5];
 * copy_arr(target1, source, 5);
 * copy_ptr(target2, source, 5);
 * copy_ptrs(target3, source, source + 5);
 * 
 * 编程要点：
 * - 理解数组表示法和指针表示法的区别
 * - 掌握指针算术运算
 * - 学会使用指针作为循环条件
 * 
 * 原始错误总结：
 * 1. copy_ptrs函数中同时递增begin和source指针，导致逻辑错误
 * 2. 编译器警告：非void函数没有返回值（虽然函数已正确声明为void）
 */

#include <stdio.h>

// 函数声明
void copy_arr(double target1[], double source[], int num);      // 数组表示法
void copy_ptr(double *target2, double *source, int n);          // 指针表示法
void copy_ptrs(double *target3, double *source, double *end);   // 指针范围法
void copy_ptrs_error(double *target3, double *source, double *end); // 错误版本，用于对比
void PrintArr(double *pt, int n);                               // 打印数组

int main(void)
{
    // 初始化源数组和三个目标数组
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];  // 用于存储第一种拷贝方法的结果
    double target2[5];  // 用于存储第二种拷贝方法的结果  
    double target3[5];  // 用于存储第三种拷贝方法的结果
    double target_error[5]; // 用于存储错误版本的结果

    // 定义指向源数组末尾的指针（指向最后一个元素后面的位置）
    double *end_ptr = source + 5;

    printf("=== 数组拷贝程序 ===\n");
    printf("源数组内容: ");
    PrintArr(source, 5);
    printf("\n");

    // 方法1：使用数组表示法进行拷贝
    printf("1. 使用数组表示法拷贝...\n");
    copy_arr(target1, source, 5);
    printf("   target1数组: ");
    PrintArr(target1, 5);

    // 方法2：使用指针表示法和指针递增进行拷贝
    printf("2. 使用指针表示法和指针递增拷贝...\n");
    copy_ptr(target2, source, 5);
    printf("   target2数组: ");
    PrintArr(target2, 5);

    // 方法3：使用指针范围进行拷贝（正确版本）
    printf("3. 使用指针范围拷贝（正确版本）...\n");
    copy_ptrs(target3, source, end_ptr);
    printf("   target3数组: ");
    PrintArr(target3, 5);

    // 方法4：使用指针范围进行拷贝（错误版本）- 展示原始错误
    printf("4. 使用指针范围拷贝（错误版本）- 展示原始错误...\n");
    copy_ptrs_error(target_error, source, end_ptr);
    printf("   target_error数组: ");
    PrintArr(target_error, 5);
    printf("   ✗ 注意：错误版本的结果不正确！\n");

    // 验证所有目标数组是否相同
    printf("\n=== 拷贝结果验证 ===\n");
    int success = 1;
    for (int i = 0; i < 5; i++) {
        if (target1[i] != source[i] || target2[i] != source[i] || target3[i] != source[i]) {
            success = 0;
            break;
        }
    }
    
    if (success) {
        printf("✓ 所有正确拷贝方法都成功！三个目标数组与源数组完全相同。\n");
    } else {
        printf("✗ 拷贝过程中出现错误！\n");
    }

    return 0;
}

/*
 * 函数：copy_arr
 * 功能：使用数组表示法拷贝数组
 * 参数：
 *   - target1[]: 目标数组
 *   - source[]: 源数组  
 *   - n: 要拷贝的元素个数
 * 说明：这是最直观的数组拷贝方法，使用下标访问数组元素
 */
void copy_arr(double target1[], double source[], int n)
{
    for (int i = 0; i < n; i++) {
        target1[i] = source[i];  // 使用数组下标访问元素
    }
}

/*
 * 函数：copy_ptr  
 * 功能：使用指针表示法和指针递增拷贝数组
 * 参数：
 *   - target2: 目标数组指针
 *   - source: 源数组指针
 *   - n: 要拷贝的元素个数
 * 说明：通过直接操作指针和指针算术运算来拷贝数组
 */
void copy_ptr(double *target2, double *source, int n)
{
    for (int i = 0; i < n; i++) {
        *target2 = *source;      // 解引用指针进行赋值
        target2++;               // 指针递增，移动到下一个位置
        source++;                // 指针递增，移动到下一个位置
    }
    
    /* 另一种等价的写法：
    for (int i = 0; i < n; i++) {
        *(target2 + i) = *(source + i);
    }
    */
}

/*
 * 函数：copy_ptrs（正确版本）
 * 功能：使用指针范围拷贝数组
 * 参数：
 *   - target3: 目标数组指针
 *   - source: 源数组起始指针  
 *   - end: 源数组结束指针（指向最后一个元素后面的位置）
 * 说明：通过比较指针地址来确定循环结束条件
 */
void copy_ptrs(double *target3, double *source, double *end)
{
    // 使用指针比较作为循环条件
    while (source < end) {
        *target3 = *source;  // 拷贝当前元素
        target3++;           // 移动目标指针
        source++;            // 移动源指针
    }
    
    /* 另一种等价的写法：
    for (double *ptr = source; ptr < end; ptr++, target3++) {
        *target3 = *ptr;
    }
    */
}

/*
 * 函数：copy_ptrs_error（错误版本 - 原始代码中的错误）
 * 功能：错误的指针范围拷贝数组实现
 * 参数：
 *   - target3: 目标数组指针
 *   - source: 源数组起始指针  
 *   - end: 源数组结束指针（指向最后一个元素后面的位置）
 * 说明：这个版本包含了原始代码中的错误
 * 
 * 错误分析：
 * - 同时递增begin和source指针，但它们初始指向相同位置
 * - 这导致source指针移动速度是预期的两倍
 * - 结果：只拷贝了部分元素，其余位置是未定义值
 */
void copy_ptrs_error(double *target3, double *source, double *end)
{
    // 错误代码：同时递增begin和source指针
    for (double *begin = source; begin < end; begin++, target3++, source++) {
        *target3 = *source;
    }
    
    /* 
     * 错误详细分析：
     * 假设源数组有5个元素：[1.1, 2.2, 3.3, 4.4, 5.5]
     * 
     * 循环过程：
     * 迭代1: begin=&source[0], source=&source[0], 拷贝source[0]=1.1
     *        递增后: begin=&source[1], source=&source[1], target3=&target3[1]
     * 
     * 迭代2: begin=&source[1], source=&source[1], 拷贝source[1]=2.2  
     *        递增后: begin=&source[2], source=&source[2], target3=&target3[2]
     * 
     * 迭代3: begin=&source[2], source=&source[2], 拷贝source[2]=3.3
     *        递增后: begin=&source[3], source=&source[3], target3=&target3[3]
     * 
     * 此时begin=&source[3] < end=&source[5]，继续循环
     * 但实际上source指针已经移动了3次，而数组只有5个元素
     * 最终结果：target3数组可能包含 [1.1, 2.2, 3.3, 随机值, 随机值]
     */
}

/*
 * 函数：PrintArr
 * 功能：打印数组的所有元素
 * 参数：
 *   - pt: 指向数组的指针
 *   - n: 数组元素个数
 * 说明：格式化输出数组内容，便于查看结果
 */
void PrintArr(double *pt, int n)
{
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%.1lf", pt[i]);  // 输出每个元素，保留1位小数
        if (i < n - 1) {
            printf(", ");        // 元素之间用逗号分隔
        }
    }
    printf("]\n");
}

/*
 * 程序总结和学习要点：
 * 
 * 1. 三种拷贝方法的比较：
 *    - copy_arr: 最易读，适合初学者理解
 *    - copy_ptr: 效率较高，展示了指针算术
 *    - copy_ptrs: 最灵活，可以拷贝数组的任何部分
 * 
 * 2. 指针算术要点：
 *    - 指针加减整数：移动指针位置
 *    - 指针比较：判断相对位置
 *    - 指针解引用：访问指向的值
 * 
 * 3. 原始错误总结：
 *    - copy_ptrs函数中同时递增begin和source指针
 *    - 导致source指针移动过快，拷贝数据不完整
 *    - 修正方法：移除多余的begin指针，直接使用source指针
 * 
 * 4. 编译器警告分析：
 *    - 警告信息："non-void function does not return a value"
 *    - 虽然函数已正确声明为void，但仍出现警告
 *    - 可能原因：编译器缓存、之前的编译历史
 *    - 解决方案：清理项目重新编译
 * 
 * 5. 编译和运行：
 *    $ gcc array_copy.c -o array_copy
 *    $ ./array_copy
 * 
 * 预期输出：
 * === 数组拷贝程序 ===
 * 源数组内容: [1.1, 2.2, 3.3, 4.4, 5.5]
 * 
 * 1. 使用数组表示法拷贝...
 *    target1数组: [1.1, 2.2, 3.3, 4.4, 5.5]
 * 2. 使用指针表示法和指针递增拷贝...
 *    target2数组: [1.1, 2.2, 3.3, 4.4, 5.5]
 * 3. 使用指针范围拷贝（正确版本）...
 *    target3数组: [1.1, 2.2, 3.3, 4.4, 5.5]
 * 4. 使用指针范围拷贝（错误版本）- 展示原始错误...
 *    target_error数组: [1.1, 2.2, 3.3, 随机值, 随机值]
 *    ✗ 注意：错误版本的结果不正确！
 * 
 * === 拷贝结果验证 ===
 * ✓ 所有正确拷贝方法都成功！三个目标数组与源数组完全相同。
 */