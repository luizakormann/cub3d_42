/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:40:08 by lukorman          #+#    #+#             */
/*   Updated: 2025/03/09 20:11:20 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;
	char	*str;

	slen = ft_strlen(s);
	str = (char *)s;
	if ((unsigned char)c == '\0')
		return (str + slen);
	while (slen > 0)
	{
		slen--;
		if (str[slen] == (unsigned char)c)
			return (str + slen);
	}
	if (str[0] == (unsigned char)c)
		return (str);
	return (NULL);
}
