/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 21:16:34 by lukorman          #+#    #+#             */
/*   Updated: 2026/09/21 23:44:36 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

#define MM_CELL 6
#define MM_OX 10
#define MM_OY 10

static int	cell_color(char c, t_door *door);
static void	draw_cell(t_game *game, int gx, int gy);
static void	draw_player_dot(t_game *game);
void		draw_minimap(t_game *game);

static int	cell_color(char c, t_door *door)
{
	if (c == '1')
		return (0x555555);
	if (c == 'D')
	{
		if (door && door->is_open)
			return (DOOR_OPEN_COLOR);
		return (DOOR_COLOR);
	}
	if (c == ' ')
		return (-1);
	return (0x222222);
}

static void	draw_cell(t_game *game, int gx, int gy)
{
	char	c;
	int		color;
	int		px;
	int		py;

	c = game->map.grid[gy][gx];
	if (c == 'D')
		color = cell_color(c, get_door(game, gx, gy));
	else
		color = cell_color(c, NULL);
	if (color < 0)
		return ;
	py = MM_OY + gy * MM_CELL;
	while (py < MM_OY + gy * MM_CELL + MM_CELL - 1)
	{
		px = MM_OX + gx * MM_CELL;
		while (px < MM_OX + gx * MM_CELL + MM_CELL - 1)
		{
			put_pixel(&game->image, px, py, color);
			px++;
		}
		py++;
	}
}

static void	draw_player_dot(t_game *game)
{
	int	cx;
	int	cy;
	int	i;

	cx = MM_OX + (int)(game->player.pos_x * MM_CELL);
	cy = MM_OY + (int)(game->player.pos_y * MM_CELL);
	i = 0;
	while (i < 5)
	{
		put_pixel(&game->image, cx + (int)(game->player.dir_x * i),
			cy + (int)(game->player.dir_y * i), 0xFF0000);
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int	x;
	int	y;

	if (!game->show_minimap)
		return ;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			draw_cell(game, x, y);
			x++;
		}
		y++;
	}
	draw_player_dot(game);
}
