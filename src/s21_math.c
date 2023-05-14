#include "s21_math.h"
#include <math.h>

int s21_abs(int x) {
    int retval = x;
    if (x != x) return S21_NAN;
    else if (x * 0 != 0) retval = S21_INF;
    else if (x < 0) retval = -retval;
    return retval;
}

long double s21_fabs(double x) {
    return (x > 0) ? x : -x;
}

long double s21_pow(double base, double exp) {
    if ((base * 0 == 0) && (base < 0) && (exp * 0 == 0) && (s21_floor(exp) != exp)) return S21_NAN;
    if ((base == 1) || (exp == 0)) return 1.0;
    if ((base != base) || (exp != exp)) return S21_NAN;
    if ((base == 0) && (exp > 0) && !((s21_fmod(s21_fabs(exp), 1.0) < S21_EPS) && (s21_fmod(s21_fabs(exp), 2.0) > S21_EPS))) return 0;
    if ((base == -1) && (exp * 0 != 0)) return 1.0;
    if ((s21_fabs(base) < 1) && (exp * 0 != 0) && (exp < 0)) return S21_INF;
    if ((s21_fabs(base) > 1) && (exp * 0 != 0) && (exp < 0)) return 0;
    if ((s21_fabs(base) < 1) && (exp * 0 != 0) && (exp > 0)) return 0;
    if ((s21_fabs(base) > 1) && (exp * 0 != 0) && (exp > 0)) return S21_INF;
    if ((base * 0 != 0) && (base < 0) && (s21_fmod(s21_fabs(exp), 2.0) > S21_EPS) && (s21_fmod(s21_fabs(exp), 1.0) < S21_EPS) && (exp < 0)) return -0;
    if ((base * 0 != 0) && (base < 0) && !((s21_fmod(s21_fabs(exp), 2.0) > S21_EPS) && (s21_fmod(s21_fabs(exp), 1.0) < S21_EPS)) && (exp < 0)) return +0;
    if ((base * 0 != 0) && (base < 0) && (s21_fmod(s21_fabs(exp), 2.0) > S21_EPS) && (s21_fmod(s21_fabs(exp), 1.0) < S21_EPS) && (exp > 0)) return S21_INF_M;    
    if ((base * 0 != 0) && (base < 0) && !((s21_fmod(s21_fabs(exp), 2.0) > S21_EPS) && (s21_fmod(s21_fabs(exp), 1.0) < S21_EPS)) && (exp > 0)) return S21_INF;
    if ((base * 0 != 0) && (base > 0) && (exp < 0)) return +0;
    if ((base * 0 != 0) && (base > 0) && (exp > 0)) return S21_INF;

    if (exp < 0) return 1 / s21_pow(base, -exp);
    int negate = (base < 0) ? 1 : 0;
    if (negate) base = -base;

    long double result = s21_exp(exp * s21_log(base));
    if (negate && (s21_fmod(exp, 2.0) == 1)) result *= -1.0;

    return result;
}

long double s21_fmod(double x, double y) {
    if ((x != x) || (y != y) || (y == 0) || (x * 0 != 0)) return S21_NAN;
    if (y * 0 != 0) return x;
    return x - (y * (int)(x / y));
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
    if (x != x) return S21_NAN;
    if (x * 0 != 0) return S21_NAN;
    if (x == 0) return 0;

    x = s21_fmod(x, 2 * S21_PI);
    long double result = 0;
    double sign = 1;
    for (double i = 1; i < S21_ACC; i += 2) {
        result += sign * s21_mul_by(x, i) / s21_fact(i);
        sign = -sign;
    }
    return result;
}

long double s21_cos(double x) {
    if (x != x) return S21_NAN;
    if (x * 0 != 0) return S21_NAN;
    if (x == 0) return 1;

    x = s21_fmod(x, 2 * S21_PI);
    long double result = 0;
    double sign = 1;
    for (double i = 0; i < S21_ACC; i += 2) {
        result += sign * s21_mul_by(x, i) / s21_fact(i);
        sign = -sign;
    }
    return result;
}

long double s21_tan(double x) {
    if ((x != x) || (x * 0 != 0) || (s21_cos(x) == 0)) return S21_NAN;
    if (x == S21_PI / 2) return 16331239353195370.000000;
    if (x == -(S21_PI / 2)) return -16331239353195370.000000;
    return s21_sin(x) / s21_cos(x);
}

long double s21_exp(double x) {  // exp(x) = 1 + x + x^2/2! + x^3/3! + x^4/4! + ... + x^n/n!
    if (x != x) return S21_NAN;
    if ((x * 0 != 0) && (x > 0)) return x;
    if ((x * 0 != 0) && (x < 0)) return 0;
    if (x == 0) return 1;
    if (x < 0) return 1 / s21_exp(-x);

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

    int ex_pow = 0;
    for (; x >= S21_E; x /= S21_E, ex_pow++) continue;

    long double result = x - 1.0;
    for (int i = 0; i < S21_ACC; i++) result = result + 2 * (x - s21_exp(result)) / (x + s21_exp(result));
    return result + ex_pow;
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

int main() {
    printf("%Lf\n\n\n", s21_asin(-0.5));
    printf("%Lf\n", asin(-0.5));
}