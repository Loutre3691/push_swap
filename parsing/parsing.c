/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   parsing.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: slaabid <slaabid@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/02/22 22:29:20 by slaabid		   #+#	#+#			 */
/*   Updated: 2026/02/22 22:29:23 by slaabid		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

static void	error_exit_split(t_list **stack_a, char **split)
{
	if (split)
		free_split(split);
	error_exit(stack_a);
}

void	ft_parsing(t_list **stack_a, int argc, char **argv)
{
	int		i;
	int		j;
	int		value;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			error_exit(stack_a);
		j = 0;
		while (split[j])
		{
			if (!ft_isnumber(split[j]))
				error_exit_split(stack_a, split);
			value = ft_atoi(split[j], stack_a);
			if (has_duplicate(*stack_a, value))
				error_exit_split(stack_a, split);
			ft_lstadd_back(stack_a, ft_newlst(value, stack_a));
			j++;
		}
		free_split(split);
		i++;
	}
}

static void	shift_args(char **argv, int i, int argc)
{
	int	j;

	j = i;
	while (j < argc - 1)
	{
		argv[j] = argv[j + 1];
		j++;
	}
}

static int	get_strategy(char *arg)
{
	if (strcmp(arg, "--simple") == 0)
		return (SIMPLE);
	else if (strcmp(arg, "--medium") == 0)
		return (MEDIUM);
	else if (strcmp(arg, "--complex") == 0)
		return (COMPLEX);
	else if (strcmp(arg, "--adaptive") == 0)
		return (ADAPTIVE);
	return (-1);
}

t_options	parse_options(int *argc, char **argv)
{
	t_options	opts;
	int			i;
	int			strategy;

	opts.strategy = ADAPTIVE;
	opts.bench = 0;
	i = 1;
	while (i < *argc)
	{
		strategy = get_strategy(argv[i]);
		if (strategy != -1)
			opts.strategy = strategy;
		else if (strcmp(argv[i], "--bench") == 0)
			opts.bench = 1;
		else
		{
			i++;
			continue ;
		}
		shift_args(argv, i, *argc);
		(*argc)--;
	}
	return (opts);
}
