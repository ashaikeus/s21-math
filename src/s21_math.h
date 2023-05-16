#ifndef S21_MATH_H
#define S21_MATH_H

#define S21_PI 3.14159265358979323846
#define S21_E 2.71828182845904523536
#define S21_EPS 1e-6
#define S21_INF 1.0 / 0.0
#define S21_INF_M -1.0 / 0.0
#define S21_NAN 0.0 / 0.0
// #define S21_MNAN -0.0 / 0.0

#define S21_ACC 100
// #define S21_NULL ((void*)0)

#include <stdio.h>

//                                      (code / posix / tests)
int s21_abs(int x);                           // +/+/+
long double s21_fabs(double x);               // +/+/+
long double s21_pow(double base, double exp); // +/+/+

long double s21_fmod(double x, double y); // +/+/+
long double s21_sqrt(double x);           // +/+/+

long double s21_ceil(double x);  // +/+/+
long double s21_floor(double x); // +/+/+

long double s21_sin(double x); // +/+/+
long double s21_cos(double x); // +/+/+
long double s21_tan(double x); // +/+/+

long double s21_asin(double x); // +/-/-
long double s21_acos(double x); // +/-/-
long double s21_atan(double x); // +/+/-

long double s21_exp(double x); // +/+/+
long double s21_log(double x); // +/+/+

// helpers

long double s21_fact(long double x);
long double s21_copysign(long double a, long double b);
long double s21_mul_by(long double x, long double y);

#endif
