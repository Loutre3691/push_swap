/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaabid <slaabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:54:12 by fde-chec          #+#    #+#             */
/*   Updated: 2026/02/25 11:20:17 by slaabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_bench
{
	int	active;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_bench;

typedef struct s_options
{
	int	strategy;
	int	bench;
}	t_options;

typedef struct s_sort
{
	t_list	**a;
	t_list	**b;
	t_bench	*bench;
}	t_sort;

// strategies
# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3

double		calculation_disorder(t_list *stack);
t_options	parse_options(int *argc, char **argv);

void		ft_parsing(t_list **stack_a, int argc, char **argv);
char		**ft_split(char const *s, char c);
void		error_exit(t_list **stack);
int			ft_atoi(const char *nptr, t_list **stack_a);
int			ft_isnumber(char *str);
int			has_duplicate(t_list *stack, int value);
void		free_split(char **split);
t_list		*ft_newlst(int value, t_list **stack_a);
void		ft_lstadd_back(t_list **lst, t_list *newlst);
t_list		*ft_lstlast(t_list *lst);
void		print_stack(t_list *stack);
void		free_stack(t_list **stack);
// Parsing
void		ft_parsing(t_list **stack_a, int argc, char **argv);

// Indexation
void		index_stack(t_list **stack);

// Utilitaires
void		print_stack(t_list *stack);
void		free_stack(t_list **stack);
void		error_exit(t_list **stack);

// Operations

void		ra(t_list **a, t_bench *bench);
void		rra(t_list **a, t_bench *bench);
void		pb(t_list **a, t_list **b, t_bench *bench);
void		pa(t_list **a, t_list **b, t_bench *bench);
void		sa(t_list **a, t_bench *bench);
void		sb(t_list **b, t_bench *bench);
void		rb(t_list **b, t_bench *bench);
void		rrb(t_list **b, t_bench *bench);

void		sort_two(t_list **stack_a, t_bench *bench);
void		sort_three(t_list **stack_a, t_bench *bench);
void		sort_four(t_list **stack_a, t_list **stack_b, t_bench *bench);
void		sort_five(t_list **stack_a, t_list **stack_b, t_bench *bench);
int			simple_small_cases(t_list **stack_a, t_list **stack_b,
				t_bench *bench);
void		simple_sort(t_list **stack_a, t_list **stack_b, t_bench *bench);
void		medium_sort(t_list **stack_a, t_list **stack_b, t_bench *bench);
void		complex_sort(t_list **stack_a, t_list **stack_b, t_bench *bench);
void		adaptive_sort(t_list **stack_a, t_list **stack_b, t_bench *bench);

void		print_bench(t_bench *bench, t_options opts, double disorder);
void		swap(t_list **stack, char c);

int			ft_lstsize(t_list *lst);
int			is_sorted(t_list *stack);

void		parsing(t_list **stack_a, int argc, char **argv);

t_list		*ft_newlst(int value, t_list **stack_a);

double		calculation_disorder(t_list *stack);

#endif