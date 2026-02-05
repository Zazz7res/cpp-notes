#include <stdio.h>
#include <stdbool.h>

// 递归版本的幂函数
double power_recursive(double n, int p) {
    // 处理特殊情况：0的0次幂
    static bool zero_zero_warned = false;
    
    if (p == 0 && n == 0) {
        if (!zero_zero_warned) {
            printf("Warning: 0 to the power of 0 is undefined, treating as 1.\n");
            zero_zero_warned = true;
        }
        return 1.0;
    }
    
    // 处理任何数的0次幂
    if (p == 0) {
        return 1.0;
    }
    
    // 处理0的任何次幂（p ≠ 0）
    if (n == 0) {
        return 0.0;
    }
    
    // 递归计算正指数
    if (p > 0) {
        return n * power_recursive(n, p - 1);
    }
    // 递归计算负指数
    else {
        return (1.0 / n) * power_recursive(n, p + 1);
    }
}

// 快速幂的递归版本（更高效）
double fast_power_recursive(double n, int p) {
    static bool zero_zero_warned = false;
    
    if (p == 0 && n == 0) {
        if (!zero_zero_warned) {
            printf("Warning: 0 to the power of 0 is undefined, treating as 1.\n");
            zero_zero_warned = true;
        }
        return 1.0;
    }
    
    if (p == 0) {
        return 1.0;
    }
    
    if (n == 0) {
        return 0.0;
    }
    
    // 处理负指数
    if (p < 0) {
        return 1.0 / fast_power_recursive(n, -p);
    }
    
    // 快速幂递归核心
    double half_power = fast_power_recursive(n, p / 2);
    
    if (p % 2 == 0) {
        // 偶数指数：n^p = (n^(p/2))^2
        return half_power * half_power;
    } else {
        // 奇数指数：n^p = n * (n^(p/2))^2
        return n * half_power * half_power;
    }
}

// 主函数测试
int main(void) {
    double x, xpow_recursive, xpow_fast;
    int exp;
    
    printf("测试递归幂函数计算\n");
    printf("Enter a number and the integer power to calculate.\n");
    printf("Enter q to quit.\n");
    
    while (scanf("%lf%d", &x, &exp) == 2) {
        // 普通递归版本
        xpow_recursive = power_recursive(x, exp);
        
        // 快速幂递归版本
        xpow_fast = fast_power_recursive(x, exp);
        
        printf("\n计算结果对比:\n");
        printf("%.3g to the power %d is:\n", x, exp);
        printf("  - 普通递归版本: %.5g\n", xpow_recursive);
        printf("  - 快速幂递归版本: %.5g\n", xpow_fast);
        printf("\nEnter next pair of numbers or q to quit.\n");
    }
    
    printf("测试结束！\n");
    return 0;
}
