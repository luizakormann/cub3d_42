/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 17:49:37 by luiza             #+#    #+#             */
/*   Updated: 2026/09/19 00:14:39 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error_utils.h"

int	open_texture(char *path);
int	set_texture(char **dst, char *value, int flag, t_data *data);
int	set_color(int *dst, char *value, int flag, t_data *data);

int	open_texture(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

int	set_texture(char **dst, char *value, int flag, t_data *data)
{
	char	*copy;

	if (data->flags & flag)
	{
		print_error("Duplicate texture identifier");
		return (-1);
	}
	copy = ft_strdup(value);
	if (!copy)
	{
		print_error("Memory allocation failed");
		return (-1);
	}
	strip_newline(copy);
	if (open_texture(copy) < 0)
	{
		free(copy);
		print_error("Texture file not found or no permission");
		return (-1);
	}
	*dst = copy;
	data->flags |= flag;
	return (0);
}

int	set_color(int *dst, char *value, int flag, t_data *data)
{
	char	*copy;
	int		color;

	if (data->flags & flag)
	{
		print_error("Duplicate color identifier");
		return (-1);
	}
	copy = ft_strdup(value);
	if (!copy)
	{
		print_error("Memory allocation failed");
		return (-1);
	}
	strip_newline(copy);
	if (parse_color(copy, &color) < 0)
	{
		free(copy);
		return (-1);
	}
	free(copy);
	*dst = color;
	data->flags |= flag;
	return (0);
}
