#include "push_swap.h"

void    ft_parsing(t_list **stack_a, int argc, char **argv)
{
    int     i;
    int     j;
    int     value;
    char    **split;

    i = 1;
    while (i < argc)
    {
        split = ft_split(argv[i], ' ');
        if(!split)
            error_exit();
        
        j = 0;
        while (split[j])
        {
            if (!ft_isnumber(split[j]))
                error_exit(); //permet de stopper le programme si pas  un chiffre
            value = ft_atoi(split[j]); //envoi chaque valeur transformee en int dans la stack

            if (has_duplicate(*stack_a, value))
                error_exit();
            ft_lstadd_back(stack_a, ft_newlst(value));
            print_stack(*stack_a);
            j++;
        }
        free_split(split);
        i++;
    }
}