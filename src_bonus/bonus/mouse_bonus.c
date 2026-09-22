/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 21:19:19 by lukorman             #+#    #+#             */
/*   Updated: 2026/09/21 21:19:27 by lukorman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "bonus.h"
#include "player_bonus.h"
#include "mlx.h"

int		mouse_move(int x, int y, void *param);
void	init_mouse(t_game *game);

int	mouse_move(int x, int y, void *param)
{
	t_game	*game;
	int		center_x;
	double	delta;

	game = (t_game *)param;
	center_x = game->image.width / 2;
	delta = (x - center_x) * MOUSE_SENS;
	if (delta != 0.0)
		rotate_player(game, delta);
	mlx_mouse_move(game->mlx_ptr, game->window,
		center_x, game->image.height / 2);
	(void)y;
	return (0);
}

void	init_mouse(t_game *game)
{
	mlx_mouse_hide(game->mlx_ptr, game->window);
	mlx_mouse_move(game->mlx_ptr, game->window,
		game->image.width / 2, game->image.height / 2);
}
