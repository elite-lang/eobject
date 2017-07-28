
#include "test.h"
#include <stdio.h>

static int add (Test* self, int x) {
    return self->x + x;
}

static int unref (Test* self) {
    
    printf("Hello World");
}


static void test_class_init(TestClass* c) {
    eobject_class_init(&(c->super));
    c->add = add;
    c->super.unref = unref;
}

extern EType test_get_type() {
    static EType test_type = 0;
    if (test_type == 0) {
        test_type = e_type_reg("Test", sizeof(Test), sizeof(TestClass), NULL, (e_class_constructor)test_class_init);
    }
}