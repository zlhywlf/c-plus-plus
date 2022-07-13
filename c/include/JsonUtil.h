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
typedef union Value {
    struct JsonObj *child;
    char *string;
    double number;
} Value;
/**
 * json对象
 */
typedef struct JsonObj {
    struct JsonObj *next;
    struct JsonObj *prev;
    JsonType type;
    char *key;
    Value *value;
} JsonObj;


JsonObj *jsonObjParse(const char *jsonStr);

JsonObj *jsonObjCreateObject(void);

JsonObj *jsonObjCreateArray(void);

JsonObj *jsonObjCreateNull(void);

JsonObj *jsonObjCreateString(const char *string);

JsonObj *jsonObjCreateNumber(double number);

JsonObj *jsonObjCreateBool(int bool);

void jsonObjAddItemToObject(JsonObj *object, char *key, JsonObj *item);

void jsonObjAddItemToArray(JsonObj *array, JsonObj *item);

char *jsonObjPrint(JsonObj *jsonObj);

#endif //C_PLUS_PLUS_JSON_UTIL_H
