#include "s21_math.h"

long double s21_asin(double arg) {
  if (s21_fabs(arg) == 1)
    return s21_copysign(1.570796, arg);
  if (arg <= 1 || arg >= -1) {
    long double x1 = s21_fabs(arg), x = 0;
    if (arg > 0.9 || arg < -0.9)
      return S21_PI / 2 - 2 * s21_asin(s21_sqrt((1.0 - x1) / 2.0));
    long double del1 = 0, del2 = 0;
    for (double n = 0; n < S21_ACC; n++) {
      del1 = s21_fact(2 * n);
      del2 = s21_pow(4, n) * s21_pow(s21_fact(n), 2) * (2 * n + 1);
      x += del1 / del2 * s21_pow(x1, 2 * n + 1);
    }
    return s21_copysign(x, arg);
  } else
    return S21_NAN;
}

long double s21_acos(double x) {
  if (x <= 1 && x >= -1) {
    long double ansf = S21_PI / 2 - s21_asin(x);
    return ansf;
  } else
    return S21_NAN;
}

long double s21_atan(double x) {
  if (x == S21_INF)
    return S21_PI / 2;
  if (x == S21_INF_M)
    return -S21_PI / 2;
  if (x != x)
    return x;
  if (x == 1)
    return 0.785398163;
  if (x == -1)
    return -0.785398163;
  long double res = 0, arg = s21_fabs(x);
  if (arg > 1.0)
    res = 1.0 / arg;
  else
    res = arg;
  for (int i = 1; i < S21_ACC; i++) {
    res -= s21_pow(arg, (1 + 2 * i) * (arg < 1 ? 1 : -1)) / (1 + 2 * i);
    i++;
    res += s21_pow(arg, (1 + 2 * i) * (arg < 1 ? 1 : -1)) / (1 + 2 * i);
  }
  if (arg > 1.0)
    res = (S21_PI * arg / (2 * arg)) - res;
  return s21_copysign(res, x);
}
