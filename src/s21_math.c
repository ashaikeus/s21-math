#include "s21_math.h"

int s21_abs(int x) {
    int retval = x;
    if (x != x) return S21_NAN;
    else if (x * 0 != 0) retval = S21_INF;
    else if (x < 0) retval = -retval;
    return retval;
}

long double s21_fabs(double x) {
    long double retval = x;
    if (x != x) retval = S21_NAN;
    else if (x * 0 != 0) retval = S21_INF;
    else if (x < 0) retval = -retval;
    return retval;
}

long double s21_pow(double base, double exp) {  // -/-!!!!
    if ((base == 1) || (exp == 0)) return 1.0;
    if ((base != base) || (exp != exp)) return S21_NAN;
    if (base == 0 && exp < 0) return S21_INF;
    if (base == 0 && exp != S21_INF_M) return 0;  // odd = -0?
    if ((base == -1) && (exp * 0 != 0)) return 1.0;
    if ((base * 0 != 0) || (exp * 0 != 0)) return S21_INF;
    if ((base == S21_INF_M) || (exp == S21_INF_M)) return S21_INF;
    if (exp == 1) return base;

    int base_sign = (base < 0) ? -1 : 1;
    int always_positive_by_even_exp = s21_fmod(exp, 2) ? 0 : 1;

    // long double result = 1 / s21_log(s21_log(base) * exp);
    // long double result = s21_mul_by(S21_E, exp * s21_log(base));
    long double result = 0.0;
    // long double fraction = s21_fmod(exp, 1);
    // for (int i = 0.0; i < s21_fabs(exp) - !!fraction; i++) result *= base;
    // if (!!fraction) {
        result += s21_exp(exp * s21_log(base));
    // }
    if (exp < 0) result = 1.0 / result;

    return result;

    // long double result = 1;
    // if (base == 0 && exp > 0) result = 0;
    // else if (exp == 0) result = 1;
    // result = s21_exp(exp * s21_log(base));
    // // else if (exp > 0) for (double i = 0; i < exp; i++) result *= base;
    // // else for (double i = 0; i < s21_abs(exp); i++) result /= base;
    
    // // else if (exp == 1) return base;
    // // if (s21_fmod(exp, 2) == 1) return base * s21_pow(base, exp - 1);
    // // result = s21_pow(base, exp / 2);
    // return result;
}

long double s21_fmod(double x, double y) {
    if ((x != x) || (y != y) || (y == 0) || (x * 0 != 0)) return S21_NAN;
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

long double s21_sqrt(double x) {
    if ((x != x) || (x < 0)) return S21_NAN;
    else if ((x * 0 != 0) || (x == 0)) return x;
    double original = x;
    long double res = (long double)x;
    while (1) {
        res = 0.5 * (x + (original / x));
        if (s21_fabs(res - x) < S21_EPS) break;
        x = res;
    }
    return res;
}

long double s21_ceil(double x) {
    if (x != x) return S21_NAN;
    if (x * 0 != 0) return S21_INF;
    int retval = (int)x;
    if (x > retval) retval += 1;
    return retval;
}

long double s21_floor(double x) {
    if (x != x) return S21_NAN;
    if (x * 0 != 0) return S21_INF;
    int retval = (int)x;
    if (x < retval && x < 0) retval -= 1;
    return retval;
}

long double s21_sin(double x) {
    // x = s21_fmod(x, 2 * S21_PI);
    if (x != x) return S21_NAN;
    if (x * 0 != 0) return S21_NAN;
    if (x == 0) return 0;
    long double result = 0;
    double sign = 1;
    for (double i = 1; i < S21_ACC; i += 2) {
        result += sign * s21_pow(x, i) / s21_fact(i);
        sign = -sign;
        // result += s21_pow(-1, i - 1) * (s21_pow(x, i) / (s21_fact(i)));
    }
    return result;
}

long double s21_cos(double x) {
    // x = s21_fmod(x, 2 * S21_PI);
    if (x != x) return S21_NAN;
    if (x * 0 != 0) return S21_NAN;
    if (x == 0) return 1;
    long double result = 0;
    double sign = 1;
    for (double i = 0; i < S21_ACC; i += 2) {
        result += sign * s21_pow(x, i) / s21_fact(i);
        sign = -sign;
        // result += s21_pow(-1, i - 1) * (s21_pow(x, i) / (s21_fact(i)));
    }
    return result;
}

long double s21_tan(double x) {
    if ((x != x) || (x * 0 != 0) || (s21_cos(x) == 0)) return S21_NAN;
    return s21_sin(x) / s21_cos(x);
}

long double s21_exp(double x) {  // exp(x) = 1 + x + x^2/2! + x^3/3! + x^4/4! + ... + x^n/n!
    if (x != x) return S21_NAN;
    if ((x * 0 != 0) && (x > 0)) return x;
    if ((x * 0 != 0) && (x < 0)) return 0;
    if (x == 0) return 1;

    long double result = 0;
    for (double i = 0; i < S21_ACC; i += 1) {
        result += s21_mul_by(x, i) / s21_fact(i);
    }
    return result;
}

long double s21_log(double x) {
    if (x != x || x < 0) return S21_NAN;
    else if (x * 0 != 0) return S21_INF;
    else if (x == 0) return S21_INF_M;
    else if (x == 1) return 0;

    long double n = x - 1.0;
    long double result = n;
    do {
        n = result;
        result = n + 2 * (x - s21_exp(n)) / (x + s21_exp(n));
    } while (s21_fabs(n - result) > S21_EPS);
    return result;
}

//// ~ HELPERS ~ \\\\

long double s21_fact(long double x) {
    long double result = 1;
    for (double i = 1; i < x + 1; i++) result *= i;
    return result;
}

long double s21_mul_by(long double x, long double y) {
    long double result = 1.0;
    for (int i = 0; i < y; i++) result *= x;
    return result;
}

long double s21_copysign(long double a, long double b) {
  if ((a < 0 && b > 0) || (a > 0 && b < 0))
    return -a;
  if ((a < 0 && b < 0) || (a > 0 && b > 0))
    return a;
  else
    return 0;
}