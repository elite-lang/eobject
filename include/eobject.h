/*
 * @CreateTime: Jul 28, 2017 10:58 AM
 * @Author: sxf
 * @Contact: sunxfancy@gmail.com
 * @Last Modified By: sxf
 * @Last Modified Time: Jul 28, 2017 3:59 PM
 * @Description: Modify Here, Please 
 */

#pragma once

#include "etype.h"
#include "stdlib.h"

typedef struct _EObject { 
    EType   e_type;
    
} EObject;


typedef struct _EObjectClass {
    EType   e_class_type;
    void (*constructor) (EObject* self);
    void (*ref) (EObject* self);
    void (*unref) (EObject* self);
} EObjectClass;

extern EType eobject_get_type();

extern void* e_object_new(EType e_type);