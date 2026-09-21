/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validade_chars_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 23:24:49 by luiza             #+#    #+#             */
/*   Updated: 2026/09/21 20:14:56 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "error_utils_bonus.h"

static int	is_valid_char(char c);
int			validate_map_chars(t_data *data);

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ');
}

int	validate_map_chars(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->grid[y])
	{
		x = 0;
		while (data->grid[y][x])
		{
			if (!is_valid_char(data->grid[y][x]))
			{
				print_error("Invalid character in map");
				return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
