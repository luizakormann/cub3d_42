/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:59:12 by luiza             #+#    #+#             */
/*   Updated: 2026/09/19 00:19:59 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error_utils.h"

int			valid_extension(char *path);
static void	init_data(t_data *data);
int			parse_cub_file(char *path, t_data *data);

int	valid_extension(char *path)
{
	int	len;

	if (!path)
		return (0);
	len = ft_strlen(path);
	if (len <= 4)
		return (0);
	return (ft_strncmp(path + len - 4, ".cub", 4) == 0);
}

static void	init_data(t_data *data)
{
	data->tex.no = NULL;
	data->tex.so = NULL;
	data->tex.we = NULL;
	data->tex.ea = NULL;
	data->floor_color = 0;
	data->ceiling_color = 0;
	data->map_line = NULL;
	data->grid = NULL;
	data->player.x = 0;
	data->player.y = 0;
	data->player.dir = 0;
	data->player.angle = 0;
	data->flags = 0;
}

int	parse_cub_file(char *path, t_data *data)
{
	int	fd;

	init_data(data);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		print_error("Cannot open .cub file");
		return (-1);
	}
	if (parse_elements(fd, data) < 0)
	{
		close(fd);
		free_data(data);
		return (-1);
	}
	data->grid = read_map(fd, data->map_line);
	close(fd);
	if (!data->grid)
	{
		free_data(data);
		return (-1);
	}
	data->map_line = NULL;
	if (validate_map(data) < 0)
	{
		free_data(data);
		return (-1);
	}
	return (0);
}
