/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:02:23 by lukorman          #+#    #+#             */
/*   Updated: 2025/03/09 20:10:26 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nwords(const char *str, char delim);
static char	*writewords(char *start, char *end);

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	nw;
	char	*start;
	char	*end;
	size_t	i;

	nw = nwords((char *)s, c);
	res = (char **)malloc((nw + 1) * sizeof(char *));
	start = (char *)s;
	i = 0;
	if (!res)
		return (NULL);
	while (i < nw)
	{
		while (*start == c)
			start++;
		end = start;
		while (*end && *end != c)
			end++;
		res[i] = writewords(start, end);
		start = end;
		i++;
	}
	res[i] = NULL;
	return (res);
}

static int	nwords(const char *str, char delim)
{
	int	count;
	int	trig;

	count = 0;
	trig = 0;
	while (*str)
	{
		if (*str != delim && trig == 0)
		{
			trig = 1;
			count++;
		}
		else if (*str == delim)
			trig = 0;
		str++;
	}
	return (count);
}

static char	*writewords(char *start, char *end)
{
	char	*wword;

	wword = ft_substr((char const *)start, 0, (end - start));
	if (!wword)
		return (NULL);
	return (wword);
}
