#pragma once

#include "eobject.h"

typedef struct {
    EObject parent;
    int x;
    struct TestPrivate * priv;
} Test;

typedef struct {
    EObjectClass super;
    int (*add) (Test* self, int x);
} TestClass;


extern EType test_get_type();
