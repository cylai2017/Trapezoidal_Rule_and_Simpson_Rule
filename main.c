//Trapezoidal Rule
//                                           n-1
//    .  b                    -             .....                  -
//   . .               b-a   |   f(b)-f(a)   .              b-a     |
//    .     f(x)dx = ------- |   ---------    .    f(a + k-------)  |
//     .                n    |       2       .               n      |
//    .  a                    -             .....                  -
//                                           k=1
//Simpson's Rule：
//
//    .  b                    -                                -
//   . .               b-a   |                       a+b        |
//    .     f(x)dx = ------- |    f(a) + f(b) + 4*f(-----)      |
//     .                n    |                        2         |
//    .  a                    -                                -
//
#include <stdio.h>
#include <math.h>

double integrate_trapezoidal(double (*fx)(double), int number_of_retangles, double lower_limit, double upper_limit)
{
    double delta_x=0.0;
    double x = 0.0;
    double sum = 0.0;
    
    delta_x = (upper_limit - lower_limit) / number_of_retangles;
    
    for (int i = 1; i <= number_of_retangles-1; i++) {
        x = lower_limit + i*delta_x;
        sum += fx(x);
    }
    
    return delta_x * ((fx(lower_limit) + fx(upper_limit)) / 2 + sum);
}

double Simpson_rule(double (*fx)(double), int number_of_retangles, double lower_limit, double upper_limit)
{
    double delta_x = 0.0, sum = 0.0;
    delta_x = (upper_limit - lower_limit) / number_of_retangles;
    sum = (lower_limit+upper_limit)/2;
    return delta_x * (fx(lower_limit) + fx(upper_limit) + 4*fx(sum));
}

