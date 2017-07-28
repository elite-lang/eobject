/*
 * @CreateTime: Jul 28, 2017 10:58 AM
 * @Author: sxf
 * @Contact: sunxfancy@gmail.com
 * @Last Modified By: sxf
 * @Last Modified Time: Jul 28, 2017 4:51 PM
 * @Description: Modify Here, Please 
 */

#pragma once

#include <stddef.h>
#include <stdbool.h>


/* INVALID is a type used for error return */
#define E_TYPE_INVALID   E_TYPE_MAKE_FUNDAMENTAL(-1)

/* VOID is just like void in C language */
#define E_TYPE_VOID      E_TYPE_MAKE_FUNDAMENTAL(0)

/* The most basic type for all class object */
#define E_TYPE_OBJECT    E_TYPE_MAKE_FUNDAMENTAL(1)
#define E_TYPE_INTERFACE E_TYPE_MAKE_FUNDAMENTAL(2)


#define E_TYPE_CHAR      E_TYPE_MAKE_FUNDAMENTAL(3)
#define E_TYPE_BYTE      E_TYPE_MAKE_FUNDAMENTAL(4)
#define E_TYPE_BOOLEAN   E_TYPE_MAKE_FUNDAMENTAL(5)
#define E_TYPE_INT16     E_TYPE_MAKE_FUNDAMENTAL(6)
#define E_TYPE_UINT16    E_TYPE_MAKE_FUNDAMENTAL(7)
#define E_TYPE_INT32     E_TYPE_MAKE_FUNDAMENTAL(8)
#define E_TYPE_UINT32    E_TYPE_MAKE_FUNDAMENTAL(9)
#define E_TYPE_INT64     E_TYPE_MAKE_FUNDAMENTAL(10)
#define E_TYPE_UINT64    E_TYPE_MAKE_FUNDAMENTAL(11)
#define E_TYPE_ENUM      E_TYPE_MAKE_FUNDAMENTAL(12)
#define E_TYPE_FLOAT     E_TYPE_MAKE_FUNDAMENTAL(13)
#define E_TYPE_DOUBLE    E_TYPE_MAKE_FUNDAMENTAL(14)
#define E_TYPE_POINTER   E_TYPE_MAKE_FUNDAMENTAL(15)
#define E_TYPE_STRING    E_TYPE_MAKE_FUNDAMENTAL(16)
#define E_TYPE_VALUE     E_TYPE_MAKE_FUNDAMENTAL(17)



#define	E_TYPE_FUNDAMENTAL_MAX     E_TYPE_MAKE_FUNDAMENTAL(255)


#define E_TYPE_FUNDAMENTAL_SHIFT	(2)
#define E_TYPE_MAKE_FUNDAMENTAL(num) (num << E_TYPE_FUNDAMENTAL_SHIFT)


/* for testing that is or not is fundamental type */
#define E_TYPE_IS_FUNDAMENTAL(t)    ((t) <= E_TYPE_FUNDAMENTAL_MAX)
#define E_TYPE_IS_DERIVED(t)        ((t) >  E_TYPE_FUNDAMENTAL_MAX)


typedef unsigned char byte;
typedef size_t EType;


/* using for e_type initialization, must be run at first of the program. */
extern void e_type_init();

struct _EObject;
struct _EObjectClass;

typedef void (*e_object_constructor) (struct _EObject *); 
typedef void (*e_class_constructor) (struct _EObjectClass *); 

/* using for register class in *_get_type function */
extern EType e_type_reg (const char* name, size_t obj_size, size_t class_size, e_object_constructor obj_ctor, e_class_constructor cla_ctor);

