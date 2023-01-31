#include "s21_math.h"
#include <math.h>
#include <stdlib.h>
#include <check.h>

START_TEST(testing_abs) {
    const int value = -29;
    ck_assert_int_eq(s21_abs(value), abs(value));
    ck_assert_int_eq(s21_abs(s21_abs(value)), abs(abs(value)));
}
END_TEST

START_TEST(testing_fabs) {
    const double value = -29.5;
    ck_assert_double_eq(s21_fabs(value), fabs(value));
    ck_assert_double_eq(s21_fabs(s21_fabs(value)), fabs(fabs(value)));
}
END_TEST

START_TEST(testing_pow) {
    const double x = 2, y = 5, z = 0;
    ck_assert_double_eq(s21_pow(x, y), pow(x, y));
    ck_assert_double_eq(s21_pow(-x, y), pow(-x, y));
    ck_assert_double_eq(s21_pow(-y, x), pow(-y, x));
    ck_assert_double_eq(s21_pow(y, -x), pow(y, -x));
    ck_assert_double_eq(s21_pow(z, y), pow(z, y));
    ck_assert_double_eq(s21_pow(z, y), pow(z, y));
    ck_assert_double_eq(s21_pow(z, -y), pow(z, -y));
}
END_TEST

START_TEST(testing_fmod) {
    const double x = 23.15, y = 5.124;
    ck_assert_double_eq(s21_fmod(x, y), fmod(x, y));
    ck_assert_double_eq(s21_fmod(-y, x), fmod(-y, x));
}
END_TEST

START_TEST(testing_sqrt) {
    const double x = 23;
    const double y = 1600;
    ck_assert_double_eq(s21_sqrt(x), sqrt(x));
    ck_assert_double_eq(s21_sqrt(y), sqrt(y));
    ck_assert_double_eq(s21_sqrt(-y), sqrt(-y));
}
END_TEST

START_TEST(testing_ceil) {
    const double x = 3.6;
    const double y = 3.2;
    const double z = 4.0;
    ck_assert_double_eq(s21_ceil(x), ceil(x));
    ck_assert_double_eq(s21_ceil(y), ceil(y));
    ck_assert_double_eq(s21_ceil(z), ceil(z));
    ck_assert_double_eq(s21_ceil(-x), ceil(-x));
    ck_assert_double_eq(s21_ceil(-y), ceil(-y));
    ck_assert_double_eq(s21_ceil(-z), ceil(-z));
}
END_TEST

START_TEST(testing_floor) {
    const double x = 3.6;
    const double y = 3.2;
    const double z = 4.0;
    ck_assert_double_eq(s21_floor(x), floor(x));
    ck_assert_double_eq(s21_floor(y), floor(y));
    ck_assert_double_eq(s21_floor(-y), floor(-y));
    ck_assert_double_eq(s21_floor(z), floor(z));
}
END_TEST

START_TEST(testing_sin) {
  const double x = 3, y = S21_PI;
  ck_assert_double_eq(s21_sin(x), sin(x));
  ck_assert_double_eq(s21_sin(y), sin(y));
}
END_TEST

START_TEST(testing_cos) {
  const double x = 3, y = S21_PI;
  ck_assert_double_eq(s21_cos(x), cos(x));
  ck_assert_double_eq(s21_cos(y), cos(y));
}
END_TEST

START_TEST(testing_tan) {
  const double x = 3, y = S21_PI;
  ck_assert_double_eq(s21_tan(x), tan(x));
  ck_assert_double_eq(s21_tan(y), tan(y));
}
END_TEST

// START_TEST(testing_asin) {}
// END_TEST
// START_TEST(testing_acos) {}
// END_TEST
// START_TEST(testing_atan) {}
// END_TEST

START_TEST(testing_exp) {
    const double x = 2, y = 5, z = 0;
    ck_assert_double_eq(s21_exp(x), exp(x));
    ck_assert_double_eq(s21_exp(-x), exp(-x));
    ck_assert_double_eq(s21_exp(-y), exp(-y));
    ck_assert_double_eq(s21_exp(z), exp(z));
}
END_TEST

START_TEST(testing_log) {
    const double x = 2, y = S21_E, z = 0;
    ck_assert_double_eq(s21_log(x), log(x));
    ck_assert_double_eq(s21_log(-x), log(-x));
    ck_assert_double_eq(s21_log(-y), log(-y));
    ck_assert_double_eq(s21_log(z), log(z));
}
END_TEST

Suite *test_suite(void) {
    Suite *s;

    TCase *tc_test_abs;
    TCase *tc_test_fabs;
    TCase *tc_test_pow;
    TCase *tc_test_fmod;
    TCase *tc_test_sqrt;
    TCase *tc_test_ceil;
    TCase *tc_test_floor;
    TCase *tc_test_sin;
    TCase *tc_test_cos;
    TCase *tc_test_tan;
    // TCase *tc_test_asin;
    // TCase *tc_test_acos;
    // TCase *tc_test_atan;
    TCase *tc_test_exp;
    TCase *tc_test_log;

    s = suite_create("Library tests");

    tc_test_abs = tcase_create("abs\n");
    tcase_add_test(tc_test_abs, testing_abs);
    suite_add_tcase(s, tc_test_abs);

    tc_test_fabs = tcase_create("fabs\n");
    tcase_add_test(tc_test_fabs, testing_fabs);
    suite_add_tcase(s, tc_test_fabs);

    tc_test_pow = tcase_create("pow\n");
    tcase_add_test(tc_test_pow, testing_pow);
    suite_add_tcase(s, tc_test_pow);

    tc_test_fmod = tcase_create("fmod\n");
    tcase_add_test(tc_test_fmod, testing_fmod);
    suite_add_tcase(s, tc_test_fmod);

    // tc_test_sqrt = tcase_create("sqrt\n");
    // tcase_add_test(tc_test_sqrt, testing_sqrt);
    // suite_add_tcase(s, tc_test_sqrt);

    tc_test_ceil = tcase_create("ceil\n");
    tcase_add_test(tc_test_ceil, testing_ceil);
    suite_add_tcase(s, tc_test_ceil);

    tc_test_floor = tcase_create("floor\n");
    tcase_add_test(tc_test_floor, testing_floor);
    suite_add_tcase(s, tc_test_floor);

    // tc_test_sin = tcase_create("sin\n");
    // tcase_add_test(tc_test_sin, testing_sin);
    // suite_add_tcase(s, tc_test_sin);

    // tc_test_cos = tcase_create("cos\n");
    // tcase_add_test(tc_test_cos, testing_cos);
    // suite_add_tcase(s, tc_test_cos);

    // tc_test_tan = tcase_create("tan\n");
    // tcase_add_test(tc_test_tan, testing_tan);
    // suite_add_tcase(s, tc_test_tan);

        // tc_test_asin = tcase_create("asin\n");
        // tcase_add_test(tc_test_asin, testing_asin);
        // suite_add_tcase(s, tc_test_asin);

        // tc_test_acos = tcase_create("acos\n");
        // tcase_add_test(tc_test_acos, testing_acos);
        // suite_add_tcase(s, tc_test_acos);

        // tc_test_atan = tcase_create("atan\n");
        // tcase_add_test(tc_test_atan, testing_atan);
        // suite_add_tcase(s, tc_test_atan);

    // tc_test_exp = tcase_create("exp\n");
    // tcase_add_test(tc_test_exp, testing_exp);
    // suite_add_tcase(s, tc_test_exp);

    // tc_test_log = tcase_create("log\n");
    // tcase_add_test(tc_test_log, testing_log);
    // suite_add_tcase(s, tc_test_log);

    return s;
}

int main() {
  int success = 0;
  Suite *s;
  SRunner *runner;
  s = test_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  success = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (success == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
