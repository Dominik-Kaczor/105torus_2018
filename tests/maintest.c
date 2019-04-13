/*
** EPITECH PROJECT, 2019
** main test
** File description:
** test
*/

#include "../include/my.h"
#include "../include/105torus.h"

int main_test(int ac, char **av)
{
    gest *nb = malloc(sizeof(*nb));
    double result;
    double tmp;

    if (error(ac, av))
        return (84);
    if (error_b(ac, av)) {
        write(2, "invalid insertion\n", 18);
        return (84);
    }
    initialisation(av, nb);
    if (nb->type == 1)
        bisection(nb);
    if (nb->type == 2)
        newton(nb);
    if (nb->type == 3)
        secant(nb);

    return (0);
}
