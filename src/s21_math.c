#include "s21_math.h"
#include <math.h>

long double s21_copysign (long double a, long double b) {
  if ((a < 0 && b > 0) || (a > 0 && b < 0))
    return -a;
  if ((a < 0 && b < 0) || (a > 0 && b > 0))
    return a;
  else
    return 0;
}

long double delproc(long double a, long double b) {
  a = s21_fabs(a);
  while (a > b) {
    if (a > 0)
      a -= b;
    else
      break;
  }
  return a;
}

int s21_abs(int x) {  // mostly fine, but check some stuff (whether value exists?)
    int retval = x;
    if (x < 0) retval = -retval;
    return retval;
}

long double s21_fabs(double x) {  // mostly fine, but check some stuff (whether value exists?)
    long double retval = x;
    if (x < 0) retval = -retval;
    return retval;
}

long double s21_pow(double base, double exp) {  // mostly fine, but CHECK FOR VALUE ERRORS!
    // doesn't work with exp in range (0, 1)!
    long double result = 1;
    if (base == 0 && exp > 0) result = 0;
    else if (exp == 0) result = 1;
    else if (exp > 0 && exp < 1) result = s21_exp(exp * s21_log(base));
    else if (exp > 0) for (double i = 0; i < exp; i++) result *= base;
    else for (double i = 0; i < s21_abs(exp); i++) result /= base;
    return result;
}

long double s21_fmod(double x, double y) {  // looks fine
    int minx = 0, miny = 0;
    // if (y == 0) return S21_NULL;
    if (x < 0) {
        minx = 1;
        x = s21_fabs(x);
    }
    if (y < 0) {
        miny = 1;
        y = s21_fabs(y);
    }

    if (x > y) while (x > y) x -= y;
    if (minx && miny) x = -x;
    return x;
}

long double s21_sqrt(double x) {  // no no wrong wrong
    // return s21_pow(x, 0.5);
}

long double s21_ceil(double x) {  // fine as h*ck
    int retval = (int)x;
    if (x > retval) retval += 1;
    return retval;
}

long double s21_floor(double x) {  // fine as h*ck
    int retval = (int)x;
    if (x < retval && x < 0) retval -= 1;
    return retval;
}

long double s21_fact(long double x) {
    long double result = 1;
    for (double i = 1; i < x + 1; i++) result *= i;
    return result;
}

double s21_sin(double x) {  // fine
    // x = s21_fmod(x, 2 * S21_PI);
    if (x > 30 || x < 30)
      x = delproc(x, S21_PI * 2);
    long double result = 0;
    double sign = 1;
    for (double i = 1; i < S21_ACC; i += 2) {
        result += sign * s21_pow(x, i) / s21_fact(i);
        sign = -sign;
        // result += s21_pow(-1, i - 1) * (s21_pow(x, i) / (s21_fact(i)));
    }
    return result;
}

// double s21_sin(double arg) {
//   long double x = 0, sx0 = 0, cx0 = 0, x0 = 0, result = 0;
//   x = delproc(arg, S21_PI / 2);
//   if (x >= S21_PI / 3.0 && x <= S21_PI / 2.0) {
//     x0 = S21_PI / 3.0;
//     sx0 = sP3;
//     cx0 = cP3;
//     result = sx0;
//   }
//   for (int n = 1; n <= 1000; n++) {
//     result -= cx0 * s21_pow((x - x0), n) / s21_fact(n);
//     n++;
//     result += sx0 * s21_pow((x - x0), n) / s21_fact(n);
//   }
//   result -= cx0 * s21_pow((x - x0), 1001.0) / s21_fact(1001.0);
//   return result;
// }

long double s21_cos(double x) {  // fine
  // x = s21_fmod(x, 2 * S21_PI);
  if (x > 30 || x < 30)
    x = delproc(x, 3.1415926535897932384626433832795028841971  * 2);
  long double result = 0;
  double sign = 1;
  for (double i = 0; i < S21_ACC; i += 2) {
      result += sign * s21_pow(x, i) / s21_fact(i);
      sign = -sign;
      // result += s21_pow(-1, i - 1) * (s21_pow(x, i) / (s21_fact(i)));
  }
  return result;
}

long double s21_tan(double x) {  // works fine
  long double sin = s21_sin(x);
  long double cos = s21_cos(x);
  long double tan = sin / cos;
  return tan;
}

long double s21_asin(double arg) {
  if (s21_fabs(arg) == 1)
    return s21_copysign(1.570796, arg);
  if (arg <= 1 || arg >= -1) {
    long double x1 = s21_fabs(arg), x = 0;
    if (arg > 0.9 || arg < -0.9)
      return S21_PI / 2 - 2 * s21_asin(sqrt((1.0 - x1) / 2.0));
    long double del1 = 0, del2 = 0;
    for (double n = 0; n < S21_ACC; n++) {
      del1 = s21_fact(2 * n);
      del2 = s21_pow(4, n) * s21_pow(s21_fact(n), 2) * (2 * n + 1);
      x += del1 / del2 * s21_pow(x1, 2 * n + 1);
    }
    // long double nn = 1;
    // long double y = 1;
    // for (long double n = 1; n <= 1000; n++) {
    //     nn *= 2 * n - 1;
    //     y *= 2 * n;
    //     x += nn / y * s21_pow(x, (2 * n + 1)) / (2 * n + 1);
    // }
    return s21_copysign(x, arg);
  }
}

long double s21_acos(double x) {
  if (x <= 1 || x >= -1) {
    long double ansf = S21_PI / 2 - s21_asin(x);
    return ansf;
  }
}

long double s21_exp(double x) {  // fine
    long double result = 0;
    for (double i = 0; i < S21_ACC; i += 1) {
        result += s21_pow(x, i) / s21_fact(i);
    }
    return result;
}

long double s21_log(double x) {
    long double result = 0;
    int sign = 1;
    x -= 1;
    for (double i = 0; i < S21_ACC; i += 1) {
        result += sign * s21_pow(x, i) / s21_fact(i);
        sign = -sign;
    }
    return result;
}

// int main() {
//     printf("%Lf vs %lf\n", s21_fmod(23.15, 5.124), fmod(23.15, 5.124));
// }
