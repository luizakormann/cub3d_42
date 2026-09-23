/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wraps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:08:30 by luiza             #+#    #+#             */
/*   Updated: 2025/03/12 20:09:07 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wrap_hex_low(va_list *args)
{
	return (ft_puthexa(va_arg(*args, unsigned int), 0));
}

int	wrap_hex_up(va_list *args)
{
	return (ft_puthexa(va_arg(*args, unsigned int), 1));
}
