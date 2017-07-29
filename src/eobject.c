/*
 * @CreateTime: Jul 28, 2017 10:58 AM
 * @Author: sxf
 * @Contact: sunxfancy@gmail.com
 * @Last Modified By: sxf
 * @Last Modified Time: Jul 29, 2017 3:50 PM
 * @Description: Modify Here, Please 
 */

#include "eobject.h"


static void ref(EObject* self) {
    printf("ref");
}

static void unref(EObject* self) {
    EOBJECT_T(self)->ref(self);
    printf("unref");
}

static void eobject_init(EObject* self) {
    printf("eobject_init called.\n");
    self->e_count = 0;
    self->e_type = E_TYPE_OBJECT;
}


static void eobject_class_init(EObjectClass* c) {
    printf("eobject_class_init called.\n");
    
    c->e_class_type = E_TYPE_INTERFACE;
    c->ref = ref;
    c->unref = unref;
}

extern EType eobject_get_type() {
    static EType e_type = 0;
    if (e_type == 0) {
        e_type = e_type_reg("EObject", sizeof(EObject), sizeof(EObjectClass), (e_object_constructor) eobject_init, (e_class_constructor) eobject_class_init);
    }
    return e_type;
}

extern void* e_object_new(EType e_type) {
    EObjectClass* p = (EObjectClass*) e_type;
    void* obj = malloc(p->size);
    EObject* eobj = (EObject*) obj;
    eobj->vtable = p;
    if (p->constructor)
        p->constructor(eobj);
    return obj;
}

