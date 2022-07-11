//
// Created by zlhywlf on 2022/4/24.
//
#define DEBUG

#include <stdlib.h>
#include "hello.h"

// argc命令行参数的数量,包括程序名本身
// 命令行参数的指针数组
// ls -l main.c
// argc = 3
// argv[0] 指向含程序名的字符串
// argv[1] 指向 "-l"
// argv[2] 指向 "main.c"
int main(int argc, char *argv[]) {
    hello();
    int a[2][3] = {1, 2, 3, 5, 2, 3};
    printf("%d\n", *a[0]);
    int (*p)[3];
    for (p = a; p < a + 2; p++) {
        for (int i = 0; i < 3; ++i) {
            (*p)[i] = 0;
        }
    }
    printf("%d\n", *a[0]);
    char s[] = "\xfc" "ber\n";
    printf(s);
    printf("compiled on %s as %s\n", __DATE__, __TIME__);
    printf("%s called\n", __func__);
#ifdef DEBUG
    printf("DEBUG");
#endif //DEBUG
    return EXIT_SUCCESS;
}