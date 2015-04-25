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
        RUN_TEST_CASE(units, test_atof_Kilo);
        RUN_TEST_CASE(units, test_atof_Mega);
        RUN_TEST_CASE(units, test_atof_Giga);
        RUN_TEST_CASE(units, test_atoi_Kilo);
        RUN_TEST_CASE(units, test_atoi_Mega);
        RUN_TEST_CASE(units, test_atoi_Giga);
        RUN_TEST_CASE(units, test_snprintf_Kilo);
        RUN_TEST_CASE(units, test_snprintf_Mega);
        RUN_TEST_CASE(units, test_snprintf_Giga);

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
    TEST_ASSERT_EQUAL_STRING("1.00 KByte",s);
    unit_snprintf(s, 11, 1000.0, 'k');
    TEST_ASSERT_EQUAL_STRING("8.00 Kbit",s);

}
TEST(units, test_snprintf_Mega)
{
    unit_snprintf(s, 11, 1024.0 * 1024.0, 'A');
    TEST_ASSERT_EQUAL_STRING(s, "1.00 MByte");
    unit_snprintf(s, 11, 1000.0 * 1000.0, 'a');
    TEST_ASSERT_EQUAL_STRING(s, "8.00 Mbit");

}
TEST(units, test_snprintf_Giga)
{
    unit_snprintf(s, 11, 4.0*1024*1024*1024,'A');
    TEST_ASSERT_EQUAL_STRING("4.00 GByte", s);
    unit_snprintf(s, 11, 4.0*1024*1024*1024, 'a');
    TEST_ASSERT_EQUAL_STRING("34.4 Gbit", s);
}
