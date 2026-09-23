/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:01:32 by lukorman          #+#    #+#             */
/*   Updated: 2025/03/09 20:10:37 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*d;

	slen = ft_strlen(s);
	d = (char *)malloc(slen + 1);
	if (d == NULL)
		return (NULL);
	ft_strlcpy(d, s, slen + 1);
	return (d);
}
