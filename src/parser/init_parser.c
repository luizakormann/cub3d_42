/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 16:59:12 by luiza             #+#    #+#             */
/*   Updated: 2026/09/10 19:18:23 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error_utils.h"

int	        valid_extension(char *path);
static void	init_data(t_data *data);
int	        parse_cub_file(char *path, t_data *data);

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
	data->floor_rgb = NULL;
	data->ceiling_rgb = NULL;
	data->map_line = NULL;
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
	close(fd);
	return (0);
}