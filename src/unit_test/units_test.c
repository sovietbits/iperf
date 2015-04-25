#include <assert.h>
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif
#include <stdio.h>
#include <string.h>

#include "iperf.h"
#include "units.h"
#include "unity_fixture.h"
TEST_GROUP(units);
TEST_GROUP_RUNNER(units)
{
        RUN_TEST_CASE(units, test_creation);
        RUN_TEST_CASE(units, test_run);
}
char      s[11];
TEST_SETUP(units)
{
	s[0]='\0';
}
TEST_TEAR_DOWN(units)
{
}
TEST(units, test_atof_Kilo)
{
    TEST_ASSERT_EQUAL(1024.0 * 0.5, unit_atof("0.5K"));
    TEST_ASSERT_EQUAL(1024.0 * 0.5, unit_atof("0.5k"));
    TEST_ASSERT_EQUAL(1024.0, unit_atof("1K"));
    TEST_ASSERT_EQUAL(1024.0, unit_atof("1k"));
}
TEST(units, test_atof_Mega)
{
    TEST_ASSERT_EQUAL(1024.0 * 1024.0, unit_atof("1M"));
    TEST_ASSERT_EQUAL(1024.0 * 1024.0, unit_atof("1m"));
}
TEST(units, test_atof_Giga)
{
    TEST_ASSERT_EQUAL(4.0 * 1024.0 * 1024.0 * 1024.0, unit_atof("4G"));
    TEST_ASSERT_EQUAL(4.0 * 1024.0 * 1024.0 * 1024.0, unit_atof("4g"));
}
TEST(units, test_atoi_Kilo)
{
    TEST_ASSERT_EQUAL(1024 * 0.5, unit_atoi("0.5K"));
    TEST_ASSERT_EQUAL(1024 * 0.5, unit_atoi("0.5k"));
    TEST_ASSERT_EQUAL(1024, unit_atoi("1K"));
    TEST_ASSERT_EQUAL(1024, unit_atoi("1k"));
}
TEST(units, test_atoi_Mega)
{
    TEST_ASSERT_EQUAL(1024.0 * 1024.0, unit_atoi("1M"));
    TEST_ASSERT_EQUAL(1024.0 * 1024.0, unit_atoi("1m"));
}
TEST(units, test_atoi_Giga)
{
    TEST_ASSERT_EQUAL(4.0 * 1024.0 * 1024.0 * 1024.0, unit_atoi("4g"));
    TEST_ASSERT_EQUAL(4.0 * 1024.0 * 1024.0 * 1024.0, unit_atoi("4G"));
}
TEST(units, test_snprintf_Kilo)
{
    unit_snprintf(s, 11, 1024.0, 'A');
    (strncmp(s, "1.00 KByte", 11) == 0);
}


int
main(int argc, char **argv)
{
    iperf_size_t llu;
    double    d;


    unit_snprintf(s, 11, 1024.0 * 1024.0, 'A');
    assert(strncmp(s, "1.00 MByte", 11) == 0);

    unit_snprintf(s, 11, 1000.0, 'k');
    assert(strncmp(s, "8.00 Kbit", 11) == 0);

    unit_snprintf(s, 11, 1000.0 * 1000.0, 'a');
    assert(strncmp(s, "8.00 Mbit", 11) == 0);

    d = 4.0 * 1024 * 1024 * 1024;
    unit_snprintf(s, 11, d, 'A');
    assert(strncmp(s, "4.00 GByte", 11) == 0);

    unit_snprintf(s, 11, d, 'a');
    assert(strncmp(s, "34.4 Gbit", 11) == 0);

    return 0;
}
                                                                                                                                                                                         106,1         Bot

                                                                        
