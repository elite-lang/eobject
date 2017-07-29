/*
 * @CreateTime: Jul 28, 2017 11:16 AM
 * @Author: sxf
 * @Contact: sunxfancy@gmail.com
 * @Last Modified By: sxf
 * @Last Modified Time: Jul 29, 2017 2:07 PM
 * @Description: Modify Here, Please 
 */

#include "etype.h"
#include "eobject.h"
#include <stdlib.h>

extern void e_type_init() {

}

extern EType e_type_reg (const char* name, size_t obj_size, size_t class_size, e_object_constructor obj_ctor, e_class_constructor cla_ctor)
{
    EObjectClass* cla = (EObjectClass*) malloc(class_size);
    cla->name = name;
    cla->size = obj_size;
    cla->class_size = class_size;
    if (obj_ctor)
        cla->constructor = obj_ctor;
    if (cla_ctor) {
        cla->class_constructor = cla_ctor;
        cla_ctor(cla);
    }
    return (EType) cla;
}