/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_split_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduque-a <fduque-a@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:24:44 by fduque-a          #+#    #+#             */
/*   Updated: 2023/06/17 00:24:48 by fduque-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Args at the command line are
 * spaced separated sings
*/
static int	ft_count_words(char const *s, char c)
{
	int		count;
	int		flag;

	count = 0;
	while (*s)
	{
		flag = 0;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (flag == 0)
			{
				count++;
				flag = 1;
			}
			++s;
		}
	}
	return (count);
}

/*
 * I exploit static variables
 * which are basically 
 * "Global private variables"
 * i can access it only via the get_next_word function
*/
static char	*ft_get_next_word(char *s, char c)
{
	static int	cursor;
	char		*next_s;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_s = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_s)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_s[i++] = s[cursor++];
	next_s[i] = '\0';
	return (next_s);
}

/*
 * I recreate an argv in the HEAP
 *
 * +2 because i want to allocate space
 * for the "\0" Placeholder and the final NULL
 *
 * words-->[p0]-> "\0" Placeholder to mimic argv
 * 				 |->[p1]->"Hello"
 * 				 |->[p2]->"how"
 * 				 |->[p3]->"Are"
 * 				 |->[..]->"..""
 * 				 |->[NULL]
*/
char	**ft_split(char *s, char c)
{
	int		words_number;
	char	**words;
	int		i;

	i = 0;
	words_number = ft_count_words(s, c);
	if (!words_number)
		return (NULL);
	words = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (words == NULL)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			words[i] = malloc(sizeof(char));
			if (words[i] == NULL)
				return (NULL);
			words[i++][0] = '\0';
			continue ;
		}
		words[i++] = ft_get_next_word(s, c);
	}
	words[i] = NULL;
	return (words);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (s[i] == c)
		return (1);
	return (0);
}
