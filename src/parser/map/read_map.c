/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 23:22:05 by luiza             #+#    #+#             */
/*   Updated: 2026/09/11 17:29:55 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error_utils.h"

static char	**add_line_to_grid(char **grid, char *line, int count);
char		**read_map(int fd, char *first_line);
int			validate_map(t_data *data);

static char	**add_line_to_grid(char **grid, char *line, int count)
{
    char	**new_grid;
	int		i;

	new_grid = malloc(sizeof(char *) * (count + 2));
	if (!new_grid)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_grid[i] = grid[i];
		i++;
	}
	new_grid[count] = line;
	new_grid[count + 1] = NULL;
	free(grid);
	return (new_grid);
}

char	**read_map(int fd, char *first_line)
{
	char	**grid;
	char	*line;
	int		count;

	strip_newline(first_line);
	grid = add_line_to_grid(NULL, first_line, 0);
	if (!grid)
		return (NULL);
	count = 1;
	line = get_next_line(fd);
	while (line)
	{
		strip_newline(line);
		grid = add_line_to_grid(grid, line, count);
		if (!grid)
			return (NULL);
		count++;
		line = get_next_line(fd);
	}
	return (grid);
}

int	validate_map(t_data *data)
{
	if (validate_map_chars(data) < 0)
		return (-1);
	if (find_player(data) < 0)
		return (-1);
	if (check_closed_map(data) < 0)
		return (-1);
	return (0);
}