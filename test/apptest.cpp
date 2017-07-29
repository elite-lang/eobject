/*
 * @CreateTime: Jul 29, 2017 11:05 AM
 * @Author: sxf
 * @Contact: sunxfancy@gmail.com
 * @Last Modified By: sxf
 * @Last Modified Time: Jul 29, 2017 2:37 PM
 * @Description: Modify Here, Please 
 */

#ifdef __APPLE__
#define GTEST_HAS_POSIX_RE 0
#endif

#include <gtest/gtest.h>
#include <string>

extern "C" {
#include "test.h"
}

using namespace std;

#define __EOBJECT_TEST__(name) TEST(EObjectTest_##name, name)

__EOBJECT_TEST__(Construction)
{
	struct _Test* obj = (struct _Test*) e_object_new(test_get_type());
    EXPECT_EQ(obj != NULL, true);
}


__EOBJECT_TEST__(CallFunction)
{
	struct _Test* obj = (struct _Test*) e_object_new(test_get_type());
    printf("%d\n", TEST_T(obj)->add(obj, 10));
}

