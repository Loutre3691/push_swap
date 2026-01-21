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

void	ft_parsing(t_list **stack_a, int argc, char **argv);
char	**ft_split(char const *s, char c);
void	error_exit(void);
int		ft_atoi(const char *nptr);
int     ft_isnumber(char *str);
int    	has_duplicate(t_list *stack, int value);
void	free_split(char **split);
t_list	*ft_newlst(int value);
void	ft_lstadd_back(t_list **lst, t_list *newlst);
t_list	*ft_lstlast(t_list *lst);
void print_stack(t_list *stack);

#endif