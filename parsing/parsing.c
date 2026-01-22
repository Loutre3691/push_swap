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
            error_exit(stack_a); //stop le prog et free la stack
        
        j = 0;
        while (split[j])
        {
            if (!ft_isnumber(split[j]))
                error_exit(stack_a);  
            value = ft_atoi(split[j], stack_a); //envoi chaque valeur transformee en int dans la stack

            if (has_duplicate(*stack_a, value))
                error_exit(stack_a);
            ft_lstadd_back(stack_a, ft_newlst(value, stack_a));
            print_stack(*stack_a); //a enlever plus tard, pour verif
            j++;
        }
        free_split(split);
        i++;
    }
}