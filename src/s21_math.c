#include "s21_math.h"

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
    if (exp == 0) result = 1;
    else if (exp > 0) for (double i = 0; i < exp; i++) result *= base;
    else for (double i = 0; i < s21_abs(exp); i++) result /= base;
    return result;
}

long double s21_fmod(double x, double y) {  // continue with this
    long double mod = x;
    // if (y == 0) return S21_NULL;
    if (x > y) {
        while (mod > 0) {
            mod -= y;
        }
        // if ((x < 0 && y > 0) || (x > 0 && y < 0)) mod = -mod;
    }
    return mod;
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

long double s21_sin(double x) {
    // x = s21_fmod(x, 2 * S21_PI);
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

long double s21_asin(double x);  
long double s21_acos(double x);
long double s21_atan(double x);

long double s21_exp(double x) {  // fine
    return s21_pow(S21_E, x);
}

long double s21_log(double x) {}

// int main() {
//     printf("%Lf vs %lf\n", s21_exp(2), exp(2));
//     printf("%lf\n", s21_exp(2) - exp(2));
//     printf("%Lf vs %lf\n", s21_exp(-6), exp(-6));
// }