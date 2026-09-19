/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 20:19:28 by luiza             #+#    #+#             */
/*   Updated: 2026/09/19 00:17:19 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error_utils.h"

static int	parse_component(char *str, int *idx, int *value);
int			parse_color(char *raw, int *color);

static int	parse_component(char *str, int *idx, int *value)
{
	int	n;
	int	digits;

	n = 0;
	digits = 0;
	while (str[*idx] >= '0' && str[*idx] <= '9')
	{
		n = n * 10 + (str[*idx] - '0');
		digits++;
		(*idx)++;
		if (digits > 3 || n > 255)
			return (-1);
	}
	if (digits == 0)
		return (-1);
	*value = n;
	return (0);
}

int	parse_color(char *raw, int *color)
{
	int	idx;
	int	r;
	int	g;
	int	b;

	idx = 0;
	r = 0;
	g = 0;
	b = 0;
	if (parse_component(raw, &idx, &r) < 0 || raw[idx] != ',')
	{
		print_error("Invalid RGB format");
		return (-1);
	}
	idx++;
	if (parse_component(raw, &idx, &g) < 0 || raw[idx] != ',')
	{
		print_error("Invalid RGB format");
		return (-1);
	}
	idx++;
	if (parse_component(raw, &idx, &b) < 0 || raw[idx] != '\0')
	{
		print_error("Invalid RGB format");
		return (-1);
	}
	*color = (r << 16) | (g << 8) | b;
	return (0);
}
