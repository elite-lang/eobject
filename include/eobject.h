/*
 * @CreateTime: Jul 28, 2017 10:58 AM
 * @Author: sxf
 * @Contact: sunxfancy@gmail.com
 * @Last Modified By: sxf
 * @Last Modified Time: Jul 29, 2017 11:59 AM
 * @Description: Modify Here, Please 
 */

#pragma once

#include "etype.h"
#include "stdlib.h"

typedef struct _EObject { 
    struct _EObjectClass*   vtable;
    EType                   e_type;
    int                     e_count;
} EObject;


typedef struct _EObjectClass {
    EType           e_class_type;
    const char*     name;
    size_t          size;
    size_t          class_size;
    e_object_constructor constructor;
    e_class_constructor  class_constructor;
    void (*ref) (EObject* self);
    void (*unref) (EObject* self);
} EObjectClass;


extern EType eobject_get_type();

extern void* e_object_new(EType e_type);


#define EOBJECT_T(x) (((EObject*)x)->vtable)