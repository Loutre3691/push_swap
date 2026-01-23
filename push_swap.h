/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaabid <slaabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:54:12 by fde-chec          #+#    #+#             */
/*   Updated: 2026/01/22 14:54:06 by slaabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <unistd.h>
# include <stddef.h> 
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	int			value;
    int         index;  
	struct s_list	*next;
}	t_list;

void	ft_parsing(t_list **stack_a, int argc, char **argv);
char	**ft_split(char const *s, char c);
void	error_exit(t_list **stack);
int		ft_atoi(const char *nptr, t_list **stack_a);
int     ft_isnumber(char *str);
int    	has_duplicate(t_list *stack, int value);
void	free_split(char **split);
t_list	*ft_newlst(int value, t_list **stack_a);
void	ft_lstadd_back(t_list **lst, t_list *newlst);
t_list	*ft_lstlast(t_list *lst);
void 	print_stack(t_list *stack);
void	free_stack(t_list **stack);
// Parsing
void ft_parsing(t_list **stack_a, int argc, char **argv);

// Indexation
void index_stack(t_list **stack);

// Utilitaires
void print_stack(t_list *stack);
void free_stack(t_list **stack);
void error_exit(t_list **stack);

#endif