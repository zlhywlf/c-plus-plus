//
// Created by zlhywlf on 2022/4/24.
//
#define DEBUG

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hello.h"

typedef union Value {
    struct JsonObj *child;
    char *string;
    double number;
} Value;

typedef struct JsonObj {
    char *key;
    int type;
    Value *value;
} JsonObj;

Value *createValue(void) {
    Value *o1 = (Value *) malloc(sizeof(Value));
    memset(o1, 0, sizeof(JsonObj));
    return o1;
}

JsonObj *createJsonObj(char *key, int t) {
    JsonObj *o1 = (JsonObj *) malloc(sizeof(JsonObj));
    memset(o1, 0, sizeof(JsonObj));
    o1->value = createValue();
    o1->type = t;
    o1->key = key;
    return o1;
}


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


    JsonObj *o1 = createJsonObj("key_o1", 0);

    JsonObj *o2 = createJsonObj("key_o2", 1);

    JsonObj *arr[] = {o1, o2};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        JsonObj *obj = arr[i];
        if (obj->type == 1) {
            obj->value->number = 22;
        } else {
            obj->value->string = "string123";
        }
        printf(arr[i]->key);
        printf("\n");
    }
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        JsonObj *obj = arr[i];
        if (obj->type == 1) {
            printf("%f", arr[i]->value->number);
        } else {
            printf("%s", arr[i]->value->string);
        }
        printf("\n");
    }

    printf("%d\n", strncmp("123", "124", 2));

    char p3[7] = "\"ssss\"", *p4;
    p4 = p3;
    p4++;
    // p4等价于p5
    char *p5 = &p3[1];
    printf("p4=%d p5=%d\n",p4,p5);
    while (*p5++ != '"' && *p3) {
        putchar(*p5);
    }
    bool aa = true;


    printf("\n");
#ifdef DEBUG
    printf("DEBUG");
#endif //DEBUG
    return EXIT_SUCCESS;
}