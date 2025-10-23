#include <stdio.h>
#include <string.h>


int main(void)
{
    char name[100];

    printf("请输入你的名字:");
    if (fgets(name, sizeof(name), stdin) == NULL)
    {
        fprintf(stderr, "读取输入失败。\n");
        return 1;
    }
    size_t len = strlen(name);
    if (len > 0 && name[len -1] == '\n')
    {
        name[len -1] = '\0';
        len--;


    }

    printf("a. \"%s\"\n", name);
    printf("b. %20s\n", name);
    char quoted[104];
    snprintf(quoted, sizeof(quoted), "\"%s\"", name);
    printf("b. %20s\n", quoted);
    printf("c. %-20s\n", quoted);
    int field_width = (int)strlen(quoted) + 3;
    printf("d. %*s\n", field_width, quoted);






    return 0;

}
