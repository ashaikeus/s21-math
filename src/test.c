#include "s21_math.h"
#include <check.h>
#include <math.h>
#include <stdlib.h>

#define POS 3
#define FPOS 3.465
#define LDPOS 7246.4275275457467467
#define FBIG 13987.9
#define NEG -2
#define FNEG -14.2463463
#define LDNEG -2246.235245246246
#define FSMALL 0.000000000000012

double values[10] = {0, 1, POS, FPOS, LDPOS, FBIG, FSMALL, NEG, FNEG, LDNEG};
double extremes[10] = {S21_INF, S21_INF_M, S21_NAN};
int valcount = 10;

START_TEST(testing_abs) {
  for (int i = 0; i < valcount; i++) {
    ck_assert_int_eq(s21_abs(values[i]), abs((int)values[i]));
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
  ck_assert_ldouble_eq_tol(s21_pow(3, 2), pow(3, 2), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(3.124, 2), pow(3.124, 2), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(3.124, 2.12), pow(3.124, 2.12), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(-3.12, -21), pow(-3.12, -21), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(3, -2), pow(3, -2), S21_EPS);
}
END_TEST

START_TEST(testing_pow_2) {
  ck_assert_ldouble_eq_tol(s21_pow(-3, -9), pow(-3, -9), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(-3, -20), pow(-3, -20), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(-3, -21), pow(-3, -21), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(3.24, 2.21), pow(3.24, 2.21), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(3.24, -2.21), pow(3.24, -2.21), S21_EPS);
}

START_TEST(testing_pow_weird) {
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), S21_EPS);
  ck_assert_ldouble_infinite(s21_pow(S21_INF, S21_INF));
  ck_assert_ldouble_infinite(s21_pow(S21_INF, 1));
  ck_assert_ldouble_eq_tol(s21_pow(-1, S21_INF), pow(-1, S21_INF), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(0, S21_INF), pow(0, S21_INF), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(1, S21_INF_M), pow(1, S21_INF_M), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(0.5, S21_INF), pow(0.5, S21_INF), S21_EPS);
  ck_assert_ldouble_infinite(s21_pow(0.5, S21_INF_M));
  ck_assert_ldouble_infinite(s21_pow(0, S21_INF_M));
  ck_assert_ldouble_infinite(s21_pow(0, -2.356827));
  ck_assert_ldouble_infinite(s21_pow(0, -2));
  ck_assert_ldouble_nan(s21_pow(0, NAN));
  ck_assert_ldouble_nan(s21_pow(-2, 2.5));
  ck_assert_ldouble_eq_tol(s21_pow(1, NAN), pow(1, NAN), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(NAN, 0), pow(NAN, 0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(2, S21_INF_M), pow(2, S21_INF_M), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF_M, -3), pow(S21_INF_M, -3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF_M, -2), pow(S21_INF_M, -2), S21_EPS);
  ck_assert_ldouble_infinite(s21_pow(S21_INF_M, 3));
  ck_assert_ldouble_infinite(s21_pow(S21_INF_M, 2));
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF, -2), pow(S21_INF, -2), S21_EPS);
  ck_assert_ldouble_nan(s21_pow(NAN, 1));
  ck_assert_ldouble_nan(s21_pow(NAN, 35));
  ck_assert_ldouble_nan(s21_pow(NAN, NAN));
}

START_TEST(testing_fmod) {
  ck_assert_ldouble_eq_tol(s21_fmod(23.15, 5.124), fmod(23.15, 5.124), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(5.124, 23.15), fmod(5.124, 23.15), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(23.15, -5.124), fmod(23.15, -5.124),
                           S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(-5.124, NEG), fmod(-5.124, NEG), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(5.124, NEG), fmod(5.124, NEG), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(0, 1), fmod(0, 1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_fmod(23.15, S21_INF), fmod(23.15, S21_INF),
                           S21_EPS);
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, 1));
  ck_assert_ldouble_nan(s21_fmod(1, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(1, 0));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, 1));
}
END_TEST

START_TEST(testing_sqrt) {
  ck_assert_ldouble_eq_tol(s21_sqrt(23), sqrt(23), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(1600), sqrt(1600), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sqrt(LDPOS), sqrt(LDPOS), S21_EPS);
  ck_assert_ldouble_infinite(s21_sqrt(S21_INF));
  ck_assert_ldouble_nan(s21_sqrt(-1600));
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(S21_INF_M));
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
  ck_assert_ldouble_eq_tol(s21_ceil(0), ceil(0), S21_EPS);
  ck_assert_ldouble_infinite(s21_ceil(S21_INF));
  ck_assert_ldouble_infinite(s21_ceil(S21_INF_M));
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
}
END_TEST

START_TEST(testing_floor) {
  const double x = 3.6;
  const double y = 3.2;
  const double z = 4.0;
  ck_assert_ldouble_eq_tol(s21_floor(x), floor(x), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(y), floor(y), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(z), floor(z), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(NEG), floor(NEG), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(-y), floor(-y), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(-z), floor(-z), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_floor(0), floor(0), S21_EPS);
  ck_assert_ldouble_infinite(s21_floor(S21_INF));
  ck_assert_ldouble_infinite(s21_floor(S21_INF_M));
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
}
END_TEST

START_TEST(testing_sin) {
  const double x = 3, y = S21_PI;

  ck_assert_ldouble_eq_tol(s21_sin(x), sin(x), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(y), sin(y), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(NEG), sin(NEG), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(x * 3), sin(x * 3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(-x * 3), sin(-x * 3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(1000), sin(1000), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), S21_EPS);
  ck_assert_ldouble_nan(s21_sin(S21_INF));
  ck_assert_ldouble_eq_tol(s21_sin(y / 2), sin(y / 2), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_sin(y / 3), sin(y / 3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(y / 4), sin(y / 4), S21_EPS);
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_nan(s21_sin(S21_INF));
}
END_TEST

START_TEST(testing_cos) {
  const double x = 3, y = S21_PI;

  ck_assert_ldouble_eq_tol(s21_cos(x), cos(x), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(y), cos(y), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(NEG), cos(NEG), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(x * 3), cos(x * 3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(-x * 3), cos(-x * 3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(1000), cos(1000), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), S21_EPS);
  ck_assert_ldouble_nan(s21_cos(S21_INF));
  ck_assert_ldouble_eq_tol(s21_cos(y / 2), cos(y / 2), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(y / 3), cos(y / 3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_cos(y / 4), cos(y / 4), S21_EPS);
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_nan(s21_cos(S21_INF));
}
END_TEST

START_TEST(testing_tan) {
  ck_assert_ldouble_eq_tol(s21_tan(3), tan(3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(NEG), tan(NEG), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(9), tan(9), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI), tan(S21_PI), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI / 2), tan(S21_PI / 2), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(-S21_PI / 2), tan(-S21_PI / 2), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI / 3), tan(S21_PI / 3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI / 4), tan(S21_PI / 4), S21_EPS);
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
  ck_assert_ldouble_nan(s21_tan(S21_INF));
}
END_TEST

START_TEST(testing_asin_1) {
  ck_assert_double_eq_tol(s21_asin(1), asin(1), S21_EPS);
}
END_TEST

START_TEST(testing_asin_2) {
  ck_assert_double_eq_tol(s21_asin(S21_PI / 4), asin(S21_PI / 4), S21_EPS);
}

START_TEST(testing_asin_3) {
  ck_assert_double_eq_tol(s21_asin(-0.5), asin(-0.5), S21_EPS);
}

START_TEST(testing_asin_4) {
  ck_assert_double_eq_tol(s21_asin(-1), asin(-1), S21_EPS);
}

START_TEST(testing_asin_weird) {
  ck_assert_double_nan(s21_asin(2.4363));
  ck_assert_double_nan(s21_asin(S21_INF));
  ck_assert_double_nan(s21_asin(S21_INF_M));
  ck_assert_double_nan(s21_asin(S21_NAN));
}

START_TEST(testing_acos_1) {
  ck_assert_double_eq_tol(s21_acos(1), acos(1), S21_EPS);
}
END_TEST

START_TEST(testing_acos_2) {
  ck_assert_double_eq_tol(s21_acos(S21_PI / 4), acos(S21_PI / 4), S21_EPS);
}
END_TEST

START_TEST(testing_acos_3) {
  ck_assert_double_eq_tol(s21_acos(-0.5), acos(-0.5), S21_EPS);
}
END_TEST

START_TEST(testing_acos_4) {
  ck_assert_double_eq_tol(s21_acos(-1), acos(-1), S21_EPS);
}

START_TEST(testing_acos_weird) {
  ck_assert_double_nan(s21_acos(3));
  ck_assert_double_nan(s21_acos(S21_INF));
  ck_assert_double_nan(s21_acos(S21_INF_M));
  ck_assert_double_nan(s21_acos(S21_NAN));
}

START_TEST(testing_atan_1) {
  ck_assert_double_eq_tol(s21_atan(1), atan(1), S21_EPS);
}
END_TEST

START_TEST(testing_atan_2) {
  ck_assert_double_eq_tol(s21_atan(-1), atan(-1), S21_EPS);
}
END_TEST

START_TEST(testing_atan_3) {
  ck_assert_double_eq_tol(s21_atan(0), atan(0), S21_EPS);
}
END_TEST

START_TEST(testing_atan_4) {
  ck_assert_double_eq_tol(s21_atan(NEG), atan(NEG), S21_EPS);
}
END_TEST

START_TEST(testing_atan_5) {
  ck_assert_double_eq_tol(s21_atan(3), atan(3), S21_EPS);
}
END_TEST

START_TEST(testing_atan_6) {
  ck_assert_double_eq_tol(s21_atan(S21_PI / 3), atan(S21_PI / 3), S21_EPS);
}
END_TEST

START_TEST(testing_atan_weird) {
  ck_assert_double_eq_tol(s21_atan(S21_INF), atan(S21_INF), S21_EPS);
  ck_assert_double_eq_tol(s21_atan(S21_INF_M), atan(S21_INF_M), S21_EPS);
  ck_assert_double_nan(s21_atan(S21_NAN));
}

START_TEST(testing_exp) {
  ck_assert_ldouble_eq_tol(s21_exp(2), exp(2), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(NEG), exp(NEG), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(6), exp(6), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(2), exp(2), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(3), exp(3), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(12), exp(12), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(35), exp(35), 0.03);
  ck_assert_ldouble_infinite(s21_exp(S21_INF));
  ck_assert_ldouble_eq_tol(s21_exp(S21_INF_M), exp(S21_INF_M), S21_EPS);
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
}
END_TEST

START_TEST(testing_log) {
  ck_assert_ldouble_nan(s21_log(NEG));
  ck_assert_double_eq(s21_log(S21_E), log(S21_E));
  ck_assert_double_eq(s21_log(2), log(2));
  ck_assert_double_eq(s21_log(0), log(0));
  ck_assert_double_eq(s21_log(1), log(1));
  ck_assert_double_eq(s21_log(S21_INF), log(S21_INF));
  ck_assert_ldouble_nan(s21_log(S21_NAN));
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
  TCase *tc_test_asin;
  TCase *tc_test_acos;
  TCase *tc_test_atan;
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
  tcase_add_test(tc_test_pow, testing_pow_2);
  tcase_add_test(tc_test_pow, testing_pow_weird);
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

  tc_test_asin = tcase_create("asin\n");
  tcase_add_test(tc_test_asin, testing_asin_1);
  tcase_add_test(tc_test_asin, testing_asin_2);
  tcase_add_test(tc_test_asin, testing_asin_3);
  tcase_add_test(tc_test_asin, testing_asin_4);
  tcase_add_test(tc_test_asin, testing_asin_weird);
  suite_add_tcase(s, tc_test_asin);

  tc_test_acos = tcase_create("acos\n");
  tcase_add_test(tc_test_acos, testing_acos_1);
  tcase_add_test(tc_test_acos, testing_acos_2);
  tcase_add_test(tc_test_acos, testing_acos_3);
  tcase_add_test(tc_test_acos, testing_acos_4);
  tcase_add_test(tc_test_acos, testing_acos_weird);
  suite_add_tcase(s, tc_test_acos);

  tc_test_atan = tcase_create("atan\n");
  tcase_add_test(tc_test_atan, testing_atan_1);
  tcase_add_test(tc_test_atan, testing_atan_2);
  tcase_add_test(tc_test_atan, testing_atan_3);
  tcase_add_test(tc_test_atan, testing_atan_4);
  tcase_add_test(tc_test_atan, testing_atan_5);
  tcase_add_test(tc_test_atan, testing_atan_6);
  tcase_add_test(tc_test_atan, testing_atan_weird);
  suite_add_tcase(s, tc_test_atan);

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
