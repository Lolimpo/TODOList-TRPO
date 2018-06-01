#define CTEST_MAIN

#include <ctest.h>
#include "todolib.h"
#include <stdbool.h>

CTEST(Add_task,Syntax_Check)
{
	bool result = add_task("\n");
	ASSERT_FALSE(result);
}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

