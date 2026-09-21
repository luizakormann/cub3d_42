/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 18:25:12 by luiza             #+#    #+#             */
/*   Updated: 2026/09/21 20:20:37 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player_bonus.h"

static void	set_key(t_game *game, int keycode, int value)
{
	if (keycode == KEY_W)
		game->keys.w = value;
	else if (keycode == KEY_A)
		game->keys.a = value;
	else if (keycode == KEY_S)
		game->keys.s = value;
	else if (keycode == KEY_D)
		game->keys.d = value;
	else if (keycode == KEY_LEFT)
		game->keys.left = value;
	else if (keycode == KEY_RIGHT)
		game->keys.right = value;
}

int	key_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
	{
		mlx_loop_end(game->mlx_ptr);
		return (0);
	}
	set_key(game, keycode, 1);
	return (0);
}

int	key_release(int keycode, void *param)
{
	set_key((t_game *)param, keycode, 0);
	return (0);
}
