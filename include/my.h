/*
** EPITECH PROJECT, 2018
** task02
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "105torus.h"

void bisection(gest *);
void newton(gest *);
void secant(gest *);
double calc_function(gest *, double);
double calc_deriv(gest *, double);
void initialisation(char **av, gest *nb);
double calc_function(gest *g, double x);
double calc_deriv(gest *g, double x);
int error_b(int ac, char **av);
int error(int ac, char **av);

#endif
