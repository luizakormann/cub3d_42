/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:59:12 by luiza             #+#    #+#             */
/*   Updated: 2026/09/10 20:28:55 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error_utils.h"

int			parse_line(char *line, t_data *data);
static int	handle_line(char *line, t_data *data, char **map_line);
int			parse_elements(int fd, t_data *data);

int	parse_line(char *line, t_data *data)
{
	char	*value;
 
	if (is_blank_line(line))
		return (0);
	value = trim_identifier(line, ID_NO);
	if (value)
		return (set_texture(&data->tex.no, value, FLAG_NO, data));
	value = trim_identifier(line, ID_SO);
	if (value)
		return (set_texture(&data->tex.so, value, FLAG_SO, data));
	value = trim_identifier(line, ID_WE);
	if (value)
		return (set_texture(&data->tex.we, value, FLAG_WE, data));
	value = trim_identifier(line, ID_EA);
	if (value)
		return (set_texture(&data->tex.ea, value, FLAG_EA, data));
	value = trim_identifier(line, ID_F);
	if (value)
		return (set_color(&data->floor_color, value, FLAG_F, data));
	value = trim_identifier(line, ID_C);
	if (value)
		return (set_color(&data->ceiling_color, value, FLAG_C, data));
	print_error("Invalid element identifier");
	return (-1);
}

static int	handle_line(char *line, t_data *data, char **map_line)
{
	if (is_map_line(line))
	{
		*map_line = line;
		return (1);
	}
	if (parse_line(line, data) < 0)
	{
		free(line);
		return (-1);
	}
	free(line);
	return (0);
}
 
int	parse_elements(int fd, t_data *data)
{
	char	*line;
	char	*map_line;
	int		ret;
 
	map_line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		ret = handle_line(line, data, &map_line);
		if (ret == 1)
		{
			data->map_line = map_line;
			return (check_all_elements(data));
		}
		if (ret == -1)
			return (-1);
		line = get_next_line(fd);
	}
	print_error("Missing map after elements");
	return (-1);
}
