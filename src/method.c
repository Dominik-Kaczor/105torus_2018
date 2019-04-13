/*
** EPITECH PROJECT, 2019
** method
** File description:
** method
*/

#include "../include/my.h"
#include "../include/105torus.h"

void bisection(gest *g)
{
    int i = 0;
    double a = 0;
    double b = 1;
    double c;

    while (round(a * pow(10, g->n)) <
            round(b * pow(10, g->n))) {
        if (i < g->n)
            i++;
        c = (a + b) / 2;
        printf("x = %.*f\n", c, i);
        if (calc_function(g, a) * calc_function(g, c) < 0)
            b = c;
        else
            a = c;
    }
}

void secant(gest *g)
{
    int i = 0;
    double x0 = 0;
    double x1 = 1;
    double y;

    if (calc_function(g, x1) - calc_function(g, x0) == 0)
        exit (84);    
    y = x1 - ((calc_function(g, x1) * (x1 - x0)) /
              (calc_function(g, x1) - calc_function(g, x0)));
    x0 = x1;
    x1 = y;
    printf("x = %.1f\n", x1);
    while (round(x0 * pow(10, g->n)) !=
           round(x1 * pow(10, g->n))) {
        if (calc_function(g, x1) - calc_function(g, x0) == 0)
            exit (84);
        y = x1 - ((calc_function(g, x1) * (x1 - x0)) /
                  (calc_function(g, x1) - calc_function(g, x0)));
        x0 = x1;
        x1 = y;
        printf("x = %.*f\n", x1, g->n);
    }
}

void newton(gest *g)
{
    double x0 = 0.5;
    double x1;
    double y;
    
    printf("x = 0.5\n");
    do {
        if (calc_deriv(g, x0) == 0)
            exit(84);
        x1 = x0 - calc_function(g, x0) / calc_deriv(g, x0);
        y = x0;
        x0 = x1;
        printf("x = %.*f\n", x1, g->n);
    } while (round(y * pow(10, g->n)) !=
             round(x1 * pow(10, g->n)));
}
