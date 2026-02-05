/* 
     * 7．编写一个函数，从标准输入中读取字符，直到遇到文件结尾。
     * 程序要报告每个字符是否是字母。如果是，还要报告该字母在字母表中的数值位置。
     * 例如，c和C在字母表中的位置都是3。合并一个函数，以一个字符作为参数，
     * 如果该字符是一个字母则返回一个数值位置，否则返回-1。
*/
#include <stdio.h>
#include <ctype.h>

//  判断字符是否为字母并返回其位置
int get_alpha_position(char ch) {
    if (isalpha(ch)) {
        if (islower(ch)) {
            return ch - 'a' + 1;
        } else {
            return ch - 'A' + 1;
        }
    } else {
        return -1;
    }
}

int main(void) {
    int ch;

    printf("请输入字符序列（输入结束后，按Ctrl+D(Linux/macOS)或Ctrl+Z然后回车(Windows)结束输入）：\n");
    printf("程序将报告每个字符是否为字母及其在字母表中的位置。\n\n");

    //核心循环：读取字符知道文件结尾
    while ((ch = getchar()) != EOF) {
        int position = get_alpha_position((char)ch);

        if (position != -1) {
            printf("字符 '%c' 是一个字母，在字母表中的位置是: %d\n", (char)ch, position);
        } else {
            printf("字符 '%c' 不是一个字母。\n", (char)ch);
        }
    }

    printf("\n输入结束。程序已处理完所有输入字符。\n");
}
