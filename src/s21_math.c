#include "s21_math.h"


// const long double POS = 3;  // 2
// const long double FPOS = 3.465;  // 3
// const long double LDPOS = 7246.42752754574;  // 4
// const long double FBIG = 13987.9;  // 5
// const long double NEG = -2;  // 6
// const long double FNEG = -14.2463463;  // 7
// const long double LDNEG = -2246.235245246246;  // 8
// const long double FSMALL = 0.00000000000012;  // 9

// long double values[10] = {0, 1, POS, FPOS, LDPOS, FBIG, NEG, FNEG, LDNEG, FSMALL};
// int valcount = 10;

int s21_abs(int x) {  // +/+;
    int retval = x;
    if (x != x) return S21_NAN;
    else if (x * 0 != 0) retval = S21_INF;
    else if (x < 0) retval = -retval;
    return retval;
}

long double s21_fabs(double x) {  // +/+
    long double retval = x;
    if (x != x) retval = S21_NAN;
    else if (x * 0 != 0) retval = S21_INF;
    else if (x < 0) retval = -retval;
    return retval;
}

long double s21_pow(double base, double exp) {  // -/-!!!!
    long double result = 1;
    if (base == 0 && exp > 0) result = 0;
    else if (exp == 0) result = 1;
    result = s21_exp(exp * s21_log(base));
    // else if (exp > 0) for (double i = 0; i < exp; i++) result *= base;
    // else for (double i = 0; i < s21_abs(exp); i++) result /= base;
    
    // else if (exp == 1) return base;
    // if (s21_fmod(exp, 2) == 1) return base * s21_pow(base, exp - 1);
    // result = s21_pow(base, exp / 2);
    return result;
}

long double s21_fmod(double x, double y) {  // +/+
    if (x != x || y != y || y == 0 || x * 0 != 0) return S21_NAN;
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

long double s21_sqrt(double x) {  // -/-!!!!
    long double res = (long double)x;
    while (1) {
        res = 0.5 * (x + (res / x));
        if (s21_fabs(res - x) < S21_EPS) break;
        x = res;
    }
    return res;
}

long double s21_ceil(double x) {  // +/+
    if (x != x) return S21_NAN;
    int retval = (int)x;
    if (x > retval) retval += 1;
    return retval;
}

long double s21_floor(double x) {  // +/+
    if (x != x) return S21_NAN;
    int retval = (int)x;
    if (x < retval && x < 0) retval -= 1;
    return retval;
}

long double s21_fact(long double x) { // +
    long double result = 1;
    for (double i = 1; i < x + 1; i++) result *= i;
    return result;
}

long double s21_sin(double x) {  // ~
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

long double s21_cos(double x) {  // ~
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

long double s21_tan(double x) {  // ~
    long double sin = s21_sin(x);
    long double cos = s21_cos(x);
    long double tan = sin / cos;
    return tan;
}

long double s21_asin(double x);  
long double s21_acos(double x);
long double s21_atan(double x);

long double s21_exp(double x) {  // +/+
    if (x != x) return S21_NAN;
    long double result = 0;
    for (double i = 0; i < S21_ACC; i += 1) {
        result += s21_pow(x, i) / s21_fact(i);
    }
    return result;
}

long double s21_log(double x) { // -/+
    if (x != x || x < 0) return S21_NAN;
    else if (x == 0) return S21_MINF;
    long double result = 0;
    if (x != 1) {
        for (double i = 1; i < S21_ACC; i += 2) {
            result += (1 / x) * s21_pow((x - 1) / (x + 1), i);
        }
    }
    return 2 * result;
}

// int main() {
//     for (int i = 0; i < valcount; i++) {
//       for (int j = 0; j < valcount; j++) {
//         long double s = s21_pow(values[i], values[j]);
//         double m = pow(values[i], values[j]);
//         if (s21_fabs(s - m) > S21_EPS) printf("[i]=[%d], [j]=[%d] - %Lf vs %lf\n", i, j, s, m);
//       }
//     }
// }