#include "s21_math.h"
#include <math.h>
#include <stdlib.h>
#include <check.h>

#define POS 3  // 2
#define FPOS 3.465  // 3
#define LDPOS 7246.4275275457467467  // 4
#define FBIG 13987.9  // 5
#define NEG -2  // 6
#define FNEG -14.2463463  // 7
#define LDNEG -2246.235245246246  // 8
#define FSMALL 0.000000000000012  // 9

long double values[10] = {0, 1, POS, FPOS, LDPOS, FBIG, NEG, FNEG, LDNEG, FSMALL};
long double extremes[10] = {S21_INF, S21_MINF, S21_NAN};
int valcount = 10;

START_TEST(testing_abs) {
    for (int i = 0; i < valcount; i++) {
      ck_assert_int_eq(s21_abs(values[i]), abs(values[i]));
    }
}
END_TEST

START_TEST(testing_fabs) {
    for (int i = 0; i < valcount; i++) {
      ck_assert_ldouble_eq_tol(s21_fabs(values[i]), fabs(values[i]), S21_EPS);
    }
}
END_TEST

START_TEST(testing_pow) {
  int i = 6, j = 5;
  ck_assert_ldouble_eq_tol(s21_pow(values[i], values[j]), pow(values[i], values[j]), S21_EPS);
    // for (int i = 0; i < valcount; i++) {
    //   for (int j = 0; j < valcount; j++) {
    //     if ((i != 0 && i != 1 && j == 5) || ) ck_assert_ldouble_infinite(s21_pow(values[i], values[j]));
    //     else ck_assert_ldouble_eq_tol(s21_pow(values[i], values[j]), pow(values[i], values[j]), S21_EPS);
    //   }
    // }
}
END_TEST

START_TEST(testing_fmod) {
    const double x = 23.15, y = 5.124;
    ck_assert_ldouble_eq_tol(s21_fmod(x, y), fmod(x, y), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_fmod(y, x), fmod(y, x), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_fmod(x, -y), fmod(x, -y), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_fmod(-y, NEG), fmod(-y, NEG), S21_EPS);
}
END_TEST

START_TEST(testing_sqrt) {
    const double x = 23;
    const double y = 1600;
    ck_assert_ldouble_eq_tol(s21_sqrt(x), sqrt(x), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_sqrt(y), sqrt(y), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_sqrt(-y), sqrt(-y), S21_EPS);
}
END_TEST

START_TEST(testing_ceil) {
    const double x = 3.6;
    const double y = 3.2;
    const double z = 4.0;
    ck_assert_ldouble_eq_tol(s21_ceil(x), ceil(x), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_ceil(y), ceil(y), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_ceil(z), ceil(z), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_ceil(NEG), ceil(NEG), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_ceil(-y), ceil(-y), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_ceil(-z), ceil(-z), S21_EPS);
}
END_TEST

START_TEST(testing_floor) {
    const double x = 3.6;
    const double y = 3.2;
    const double z = 4.0;
    ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_floor(y), floor(y), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_floor(-y), floor(-y), S21_EPS);
    ck_assert_ldouble_eq_tol(s21_floor(z), floor(z), S21_EPS);
}
END_TEST

START_TEST(testing_sin) {
  const double x = 3, y = S21_PI;

  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(y), sin(y), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(NEG), sin(NEG), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(x * 3), sin(x * 3), S21_EPS);
}
END_TEST

START_TEST(testing_cos) {
  const double x = 3, y = S21_PI;

  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(y), cos(y), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(NEG), cos(NEG), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(x * 3), cos(x * 3), S21_EPS);
}
END_TEST

START_TEST(testing_tan) {
  const double x = 3, y = S21_PI;

  ck_assert_ldouble_eq_tol(s21_tan(x), tan(x), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(y), tan(y), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(NEG), tan(NEG), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(x * 3), tan(x * 3), S21_EPS);
}
END_TEST

// START_TEST(testing_asin) {}
// END_TEST
// START_TEST(testing_acos) {}
// END_TEST
// START_TEST(testing_atan) {}
// END_TEST

START_TEST(testing_exp) {
  int success = 0;
  const double x = 2, y = 6, z = 0;

  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(y), exp(y), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(NEG), exp(NEG), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(x * 3), exp(x * 3), S21_EPS);
}
END_TEST

START_TEST(testing_log) {
    const double x = 2, y = S21_E, z = 0;
    ck_assert_double_eq(s21_log(x), log(x));
    ck_assert_double_eq(s21_log(NEG), log(NEG));
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

    tc_test_sqrt = tcase_create("sqrt\n");
    tcase_add_test(tc_test_sqrt, testing_sqrt);
    suite_add_tcase(s, tc_test_sqrt);

    tc_test_ceil = tcase_create("ceil\n");
    tcase_add_test(tc_test_ceil, testing_ceil);
    suite_add_tcase(s, tc_test_ceil);

    tc_test_floor = tcase_create("floor\n");
    tcase_add_test(tc_test_floor, testing_floor);
    suite_add_tcase(s, tc_test_floor);

    tc_test_sin = tcase_create("sin\n");
    tcase_add_test(tc_test_sin, testing_sin);
    suite_add_tcase(s, tc_test_sin);

    tc_test_cos = tcase_create("cos\n");
    tcase_add_test(tc_test_cos, testing_cos);
    suite_add_tcase(s, tc_test_cos);

    tc_test_tan = tcase_create("tan\n");
    tcase_add_test(tc_test_tan, testing_tan);
    suite_add_tcase(s, tc_test_tan);

        // tc_test_asin = tcase_create("asin\n");
        // tcase_add_test(tc_test_asin, testing_asin);
        // suite_add_tcase(s, tc_test_asin);

        // tc_test_acos = tcase_create("acos\n");
        // tcase_add_test(tc_test_acos, testing_acos);
        // suite_add_tcase(s, tc_test_acos);

        // tc_test_atan = tcase_create("atan\n");
        // tcase_add_test(tc_test_atan, testing_atan);
        // suite_add_tcase(s, tc_test_atan);

    tc_test_exp = tcase_create("exp\n");
    tcase_add_test(tc_test_exp, testing_exp);
    suite_add_tcase(s, tc_test_exp);

    tc_test_log = tcase_create("log\n");
    tcase_add_test(tc_test_log, testing_log);
    suite_add_tcase(s, tc_test_log);

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
