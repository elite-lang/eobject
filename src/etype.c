/*
 * @CreateTime: Jul 28, 2017 11:16 AM
 * @Author: sxf
 * @Contact: sunxfancy@gmail.com
 * @Last Modified By: sxf
 * @Last Modified Time: Jul 28, 2017 4:52 PM
 * @Description: Modify Here, Please 
 */

#include "etype.h"
#include <stdlib.h>

extern void e_type_init() {

}

extern EType e_type_reg (const char* name, size_t obj_size, size_t class_size, e_object_constructor obj_ctor, e_class_constructor cla_ctor)
{
    void* obj = malloc(obj_size);
    void* cla = malloc(class_size);
    if (obj_ctor)
        obj_ctor((struct _EObject*) obj);
    if (cla_ctor)
        cla_ctor((struct _EObjectClass*) cla);
    return (EType) cla;
}