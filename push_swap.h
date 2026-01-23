/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-chec <fde-chec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:54:12 by fde-chec          #+#    #+#             */
/*   Updated: 2025/11/14 12:03:06 by fde-chec         ###   ########.fr       */
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
	struct s_list	*next;
}	t_list;

//parsing
void	ft_parsing(t_list **stack_a, int argc, char **argv);
void	error_exit(t_list **stack);
int		ft_atoi(const char *nptr, t_list **stack_a);
int     ft_isnumber(char *str);
int    	has_duplicate(t_list *stack, int value);
void	free_split(char **split);

//split
char	**ft_split(char const *s, char c);
static char	*ft_add_str(char const *str, size_t start, size_t end);
static void	*ft_free(char **array, size_t n);
static char	**ft_spliting(char **array, char const *s, char c);
static size_t	ft_count_word(const char *s, char c);

//lst
t_list	*ft_newlst(int value, t_list **stack_a);
void	ft_lstadd_back(t_list **lst, t_list *newlst);
t_list	*ft_lstlast(t_list *lst);
int     stack_size(t_list *stack_a);
void	free_stack(t_list **stack);

//algo
void    ft_algo(t_list **stack_a, t_list **stack_b);
void    ft_simple_algo(char **stack_a, char **stack_b);
void    ft_medium_algo(char **stack_a, char **stack_b);
void    ft_complex_algo(char **stack_a, char **stack_b);

#endif