#include <stdio.h>

//  方法一：递归实现
void decimalToBinaryRecursive(int n) {
    //  1.基准条件：当商为0时，停止递归
    if (n == 0) {
        return;
    }
    
    //  2. 递归调用：处理更小的子问题 （n/2)
    decimalToBinaryRecursive(n / 2);

    //  3. 在“归”的过程中打印余数，自然形成逆序
    printf("%d", n % 2);
}

// 方法二：循环实现
void decimalToBinaryIterative(int n) {
    int binary[32];  // 假设用32位存储
    int i = 0;

    // 特殊情况：十进制0的二进制也是0
    if (n == 0) {
        printf("0");
        return;
    }

    // 循环除2取余
    while (n > 0) {
        binary[i] = n % 2;  // 存储余数
        n = n / 2;
        i++;
    }

    //  逆序输出：因为最后计算的余数是最高位
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main(void) {
    int num = 5;

    printf("十进制 %d 的二进制（递归）是：", num);
    decimalToBinaryRecursive(num);
    printf("\n");

    printf("十进制 %d 的二进制（循环）是：", num);
    decimalToBinaryIterative(num);
    printf("\n");

    return 0;
}
