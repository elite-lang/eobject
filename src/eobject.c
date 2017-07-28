/*
 * @CreateTime: Jul 28, 2017 10:58 AM
 * @Author: sxf
 * @Contact: sunxfancy@gmail.com
 * @Last Modified By: sxf
 * @Last Modified Time: Jul 28, 2017 4:15 PM
 * @Description: Modify Here, Please 
 */

#include "eobject.h"

static void constructor(EObject* self) {
    
}

static void ref(EObject* self) {

}

static void unref(EObject* self) {
    printf("Hello");
}


static void eobject_class_init(EObjectClass* c) {
    c->e_class_type = E_TYPE_INTERFACE;
    c->constructor = constructor;
    c->ref = ref;
    c->unref = unref;
}

extern EType eobject_get_type() {
    return E_TYPE_OBJECT;
}

