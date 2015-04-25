#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#include "timer.h"
#include "unity_fixture.h"
static Timer *tp;
static int flag;
static struct timeval start_time;
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
    gettimeofday(&start_time, NULL);	
    tp = tmr_create(&start_time, timer_proc, JunkClientData, 3000000, 0);
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
    tmr_run(&start_time);
    TEST_ASSERT_EQUAL(0,flag);

    start_time.tv_sec +=2;
    tmr_run(&start_time);
    TEST_ASSERT_EQUAL(0,flag);

    start_time.tv_sec +=1;
    tmr_run(&start_time);
    TEST_ASSERT_EQUAL(1,flag);
}


