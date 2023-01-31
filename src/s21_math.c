#include "s21_math.h"

int s21_abs(int x) {  // mostly fine, but check some stuff (whether value exists?)
    int retval = x;
    if (x < 0) retval = -retval;
    return retval;
}

long double s21_fabs(double x) {  // mostly fine, but check some stuff (whether value exists?)
    double retval = x;
    if (x < 0) retval = -retval;
    return retval;
}

long double s21_pow(double base, double exp) {  // mostly fine, but CHECK FOR VALUE ERRORS!
    double result = 1;
    if (exp > 0) for (int i = 0; i < (int)exp; i++) result *= base;
    else for (int i = 0; i < (int)s21_abs(exp); i++) result /= base;
    return result;
}

long double s21_fmod(double x, double y) {  // everything is wrong lol
    double mod = 0;
    double xchange = x;
    // if (y == 0) return S21_NULL;
    if (x < y) mod = x;
    else {
        while (xchange > y) {
            xchange -= y;
        }
        mod = x - xchange;
        // if ((x < 0 && y > 0) || (x > 0 && y < 0)) mod = -mod;
    }
    return mod;
}

long double s21_sqrt(double x) {}

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

long double s21_sin(double x) {}
long double s21_cos(double x) {}
long double s21_tan(double x) {}

long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);

long double s21_exp(double x) {}
long double s21_log(double x) {}




// int main() {
//     const double x = 3.6;
//     const double y = 3.2;
//     const double z = 4.0;
//     s21_ceil(x);
//     s21_ceil(y);
//     s21_ceil(z);
// }