/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 23:16:04 by lukorman          #+#    #+#             */
/*   Updated: 2026/09/21 23:45:47 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error_utils.h"

static void	free_visited(char **visited, int height);
static char	**create_visited(int height, int width);
static char	get_char(char **grid, int height, int y, int x);
static int	flood_fill(t_fill *f, int y, int x);
int			check_closed_map(t_data *data);

static void	free_visited(char **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

static char	**create_visited(int height, int width)
{
	char	**visited;
	int		i;

	visited = malloc(sizeof(char *) * (height + 1));
	if (!visited)
		return (NULL);
	i = 0;
	while (i < height)
	{
		visited[i] = calloc(width + 1, sizeof(char));
		if (!visited[i])
		{
			free_visited(visited, i);
			return (NULL);
		}
		i++;
	}
	visited[height] = NULL;
	return (visited);
}

static char	get_char(char **grid, int height, int y, int x)
{
	if (y < 0 || y >= height || x < 0)
		return (' ');
	if ((int)ft_strlen(grid[y]) <= x)
		return (' ');
	return (grid[y][x]);
}

static int	flood_fill(t_fill *f, int y, int x)
{
	char	c;

	c = get_char(f->grid, f->height, y, x);
	if (c == ' ')
		return (-1);
	if (f->visited[y][x] || c == '1')
		return (0);
	f->visited[y][x] = 1;
	if (flood_fill(f, y - 1, x) < 0)
		return (-1);
	if (flood_fill(f, y + 1, x) < 0)
		return (-1);
	if (flood_fill(f, y, x - 1) < 0)
		return (-1);
	if (flood_fill(f, y, x + 1) < 0)
		return (-1);
	return (0);
}

int	check_closed_map(t_data *data)
{
	t_fill	f;
	int		width;
	int		result;

	f.grid = data->grid;
	f.height = map_height(data->grid);
	width = map_width(data->grid, f.height);
	f.visited = create_visited(f.height, width);
	if (!f.visited)
	{
		print_error("Memory allocation failed");
		return (-1);
	}
	result = flood_fill(&f, data->player.y, data->player.x);
	free_visited(f.visited, f.height);
	if (result < 0)
	{
		print_error("Map is not closed (leak detected)");
		return (-1);
	}
	return (0);
}
