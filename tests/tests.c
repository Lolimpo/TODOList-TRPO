#define CTEST_MAIN

#include <ctest.h>
#include "todolib.h"
#include <stdbool.h>

CTEST(Menu, Correct_Syntax_Check)
{
    bool result = menu();
    ASSERT_FALSE(result);
}

CTEST()
{
	
}


int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
