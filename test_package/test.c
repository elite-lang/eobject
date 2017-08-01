
#include "test.h"
#include <stdio.h>

static int add (Test* self, int x) {
    EOBJECT_T(self)->unref(self);
    printf("self->x = %d\n", self->x);
    return self->x + x;
}

static int unref (Test* self) {
    printf("virtual call unref in test.\n");
}

static void test_init(Test* self) {
    printf("test_init begin.\n");
    TEST_T(self)->super->constructor(self);

    printf("test_init called.\n");
    self->x = 0;
}

static void test_class_init(TestClass* c) {
    c->super = (EObjectClass*) eobject_get_type();
    c->super->class_constructor(&(c->parent));
    // eobject_class_init(&(c->parent));

    printf("test_class_init called\n");
    c->add = add;
    c->parent.unref = unref;
}

extern EType test_get_type() {
    static EType test_type = 0;
    if (test_type == 0) {
        test_type = e_type_reg("Test", sizeof(Test), sizeof(TestClass), (e_object_constructor) test_init, (e_class_constructor) test_class_init);
    }
    return test_type;
}


int main() {
    struct _Test* obj = (struct _Test*) e_object_new(test_get_type());
    printf("%d\n", TEST_T(obj)->add(obj, 10));
    return 0;
}