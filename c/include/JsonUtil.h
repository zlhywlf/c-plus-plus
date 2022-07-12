//
// Created by zlhywlf on 2022/7/12.
//

#ifndef C_PLUS_PLUS_JSON_UTIL_H
#define C_PLUS_PLUS_JSON_UTIL_H
#define JSON_UTIL_CDECL __cdecl

#include <stdlib.h>

/**
 * json类型
 */
typedef enum JsonType {
    IS_FALSE,
    IS_TRUE,
    IS_NULL,
    IS_NUMBER,
    IS_STRING,
    IS_ARRAY,
    IS_OBJECT
} JsonType;

/**
 * json对象
 */
typedef struct JsonUtil {
    /**
     * 链表
     */
    struct JsonUtil *next;
    struct JsonUtil *prev;
    /**
     * 类型
     */
    JsonType type;
    /**
    * 键
    */
    char *key;
    /**
    * 值
    */
    union {
        /**
         * 数组或者对象
         */
        struct JsonUtil *child;
        /**
         * 字符串
         */
        char *valueString;
        /**
         * 数字
         */
        double number;
    } *value;
} JsonUtil;

/**
 * 内部钩子
 */
static void *(*jsonUtilMalloc)(size_t sz) = malloc;

static void (*jsonUtilFree)(void *ptr) = free;

#endif //C_PLUS_PLUS_JSON_UTIL_H
