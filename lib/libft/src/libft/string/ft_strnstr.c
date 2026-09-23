/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:21:57 by lukorman          #+#    #+#             */
/*   Updated: 2025/03/09 20:11:15 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lt_len;

	if (!*little)
		return ((char *)big);
	if (!*big)
		return (NULL);
	lt_len = ft_strlen(little);
	if (lt_len > len)
		return (NULL);
	while (*big && len >= lt_len)
	{
		if (!ft_memcmp(big, little, lt_len))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
