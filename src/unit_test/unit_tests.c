#include <stdio.h>
#include "unity_fixture.h"
static void RunAllTests(void)
{
	RUN_TEST_GROUP(timer);
	RUN_TEST_GROUP(units);
}
int main(int argc, char * argv[])
{
	return UnityMain(argc, argv, RunAllTests);
}
