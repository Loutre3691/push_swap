#include "push_swap.h"

static char	*ft_add_str(char const *str, size_t start, size_t end)
{
	size_t	i;
	char	*word;

	i = 0;
	word = calloc((end - start + 1), sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **array, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static char	**ft_spliting(char **array, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			array[j] = ft_add_str(s, start, i);
			if (!array[j])
				return (ft_free(array, j));
			j++;
		}
	}
	return (array);
}

static size_t	ft_count_word(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	array = calloc((ft_count_word(s, c) + 1), sizeof(char *));
	if (!array)
		return (NULL);
	array = ft_spliting(array, s, c);
	return (array);
}
