/*
** EPITECH PROJECT, 2019
** tools_torus
** File description:
** tools
*/

#include "../include/my.h"
#include "../include/105torus.h"

int error(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        printf("USAGE\n    ./105torus opt a0 a1 a2 a3 a4 n\n\n");
        printf("DESCRIPTION\n");
        printf("    opt       method option:\n");
        printf("\t\t  1 for the bisection,\n");
        printf("\t\t  2 for Newton's method\n");
        printf("\t\t  3 for the secant method\n");
        printf("     a[0-4]   coefficients of the equation\n");
        printf("     n      precision (the application");
        printf("of the polynomial to the solution should\n");
        printf("\t    be smallen than 10^-n)\n");
        return (1);
    }
    else if (ac != 8) {
        write(2, "invalide nomber\n", 16);
        return (1);
    }
    return (0);
}

int error_b(int ac, char **av)
{
    if ((av[1][0] != '1' && av[1][0] != '2' && av[1][0] != '3')
        || av[1][1] != '\0')
        return (1);
    for (int i = 2; i != ac; i++) {
        for (int k = 0; av[i][k] != '\0'; k++) {
            if ((av[i][k] < '0' || av[i][k] > '9') && av[i][k] != '-')
                return (1);
        }
    }
    return (0);
}

double calc_deriv(gest *g, double x)
{
    double nb;

    nb = pow(x, 3) * g->a4 * 4 + pow(x, 2) *
        g->a3 * 3 + x * g->a2 * 2 + g->a1;

    return (nb);
}

double calc_function(gest *g, double x)
{
    double nb;

    nb = pow(x, 4) * g->a4 + pow(x, 3) *
        g->a3 + pow(x, 2) * g->a2 + g->a1 * x + g->a0;

    return (nb);
}

void initialisation(char **av, gest *nb)
{
    nb->type = atof(av[1]);
    nb->a0 = atof(av[2]);
    nb->a1 = atof(av[3]);
    nb->a2 = atof(av[4]);
    nb->a3 = atof(av[5]);
    nb->a4 = atof(av[6]);
    nb->n = atof(av[7]);
}
