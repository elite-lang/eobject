#pragma once

#include "eobject.h"

typedef struct _Test {
    EObject parent;
    int x;
    struct TestPrivate * priv;
} Test;

typedef struct _TestClass {
    EObjectClass parent;
    EObjectClass* super;
    int (*add) (Test* self, int x);
} TestClass;


extern EType test_get_type();
#define TEST_T(x) ((TestClass*)(((EObject*)x)->vtable))