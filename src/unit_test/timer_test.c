#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#include "timer.h"
#include "unity_fixture.h"
static Timer *tp;
static int flag;
static void
timer_proc( TimerClientData client_data, struct timeval* nowP )
{
    flag = 1;
}
TEST_GROUP(timer);
TEST_GROUP_RUNNER(timer)
{
	RUN_TEST_CASE(timer, test_creation);
	RUN_TEST_CASE(timer, test_run);
}
TEST_SETUP(timer)
{
    tp = tmr_create((struct timeval*) 0, timer_proc, JunkClientData, 3000000, 0);
    flag=0;
}
TEST_TEAR_DOWN(timer)
{
    tmr_destroy();
}
TEST(timer, test_creation)
{
    TEST_ASSERT_NOT_EQUAL(NULL, tp);
}
TEST(timer, test_run)
{
	
    tmr_run((struct timeval*) 0);
    sleep(2);
    TEST_ASSERT_EQUAL(0,flag);
    sleep(1);
    tmr_run((struct timeval*) 0);
    TEST_ASSERT_EQUAL(1,flag);
}


