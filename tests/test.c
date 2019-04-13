/*
** EPITECH PROJECT, 2019
** unity_test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "../include/105torus.h"

int main_test(int ac, char **av);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(main_test, bisection, .init = redirect_all_std)
{
    int ac = 8;
    char *av[] = {"105torus", "1", "-1", "0", "6", "-5", "1", "6"};
    int dest = main_test(ac, av);

    cr_assert_stdout_eq_str("x = 0.5\nx = 0.75\nx = 0.625\nx = 0.5625\n" \
                            "x = 0.53125\nx = 0.515625\nx = 0.523438\n" \
                            "x = 0.519531\nx = 0.521484\nx = 0.522461\n" \
                            "x = 0.522949\nx = 0.522705\nx = 0.522827\n" \
                            "x = 0.522766\nx = 0.522736\nx = 0.522751\n" \
                            "x = 0.522743\nx = 0.522739\nx = 0.522741\n" \
                            "x = 0.522740\n");
}

Test(main_test, newton, .init = redirect_all_std)
{
    int ac = 8;
    char *av[] = {"105torus", "2", "-1", "0", "6", "-5", "1", "12"};
    int dest = main_test(ac, av);

    cr_assert_stdout_eq_str("x = 0.5\nx = 0.522727272727\n" \
                            "x = 0.522740003514\nx = 0.522740003526\n");
}

Test(main_test, secant, .init = redirect_all_std)
{
    int ac = 8;
    char *av[] = {"105torus", "3", "-1", "0", "6", "-5", "1", "8"};
    int dest = main_test(ac, av);

    cr_assert_stdout_eq_str("x = 0.5\nx = 0.52941176\nx = 0.52274853\n" \
                            "x = 0.52274000\nx = 0.52274000\n");
}

Test(main_test, invalid_number_of_arg, .init = redirect_all_std)
{
    int ac = 2;
    char *av[] = {"105torus", "3"};
    int dest = main_test(ac, av);

    cr_assert_eq(dest, 84);
}

Test(main_test, test_h, .init = redirect_all_std)
{
    int ac = 2;
    char *av[] = {"105torus", "-h"};
    int dest = main_test(ac, av);

    cr_assert_eq(dest, 84);
}

Test(main_test, invalide_option, .init = redirect_all_std)
{
    int ac = 2;
    char *av[] = {"105torus", "4", "-1", "0", "6", "-5", "1", "8"};
    int dest = main_test(ac, av);

    cr_assert_eq(dest, 84);
}

Test(main_test, invalide_characters, .init = redirect_all_std)
{
    int ac = 2;
    char *av[] = {"105torus", "3", "-1av", "0", "6", "-5", "1", "8"};
    int dest = main_test(ac, av);

    cr_assert_eq(dest, 84);
}
