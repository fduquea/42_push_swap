/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aa-stack_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:55:40 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/12 22:13:59 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *) dest)[i] = ((char *) src)[i];
		i++;
	}
	return (dest);
}

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_words(char const *s, int len, int *j)
{
	char	*dest;

	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	j += len;
	return ((char *) ft_memcpy(dest, s, len));
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		j;
	char	**strings;
	int		len;

	strings = malloc((ft_count_words(str, c) + 2) * sizeof(char *));
	if (!str || !(strings))
		return (NULL);
	j = 0;
	strings[0] = ft_words("\0", 0, &j);
	i = 1;
	while (str[j])
	{
		if (str[j] == c)
			j++;
		else
		{
			len = 0;
			while (str[j + len] && str[j + len] != c)
				len++;
			strings[i++] = ft_words(str + j, len, &j);
			j += len;
		}
	}
	strings[i] = NULL;
	return (strings);
}
