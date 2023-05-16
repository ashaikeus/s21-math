#include "s21_math.h"

long double s21_asin(double x) {
  if (x == 1 || x == -1) return 1.57079633 * x;
  return s21_atan(x / s21_sqrt(1 - x * x));
}

long double s21_acos(double x) {
  if (x <= 1 && x >= -1) {
    long double ansf = S21_PI / 2 - s21_asin(x);
    return ansf;
  } else return S21_NAN;
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
  for (int i = 1; i < 444; i++) {
    res -= s21_pow(arg, (1 + 2 * i) * (arg < 1 ? 1 : -1)) / (1 + 2 * i);
    i++;
    res += s21_pow(arg, (1 + 2 * i) * (arg < 1 ? 1 : -1)) / (1 + 2 * i);
  }
  if (arg > 1.0)
    res = (S21_PI * arg / (2 * arg)) - res;
  return s21_copysign(res, x);
}
