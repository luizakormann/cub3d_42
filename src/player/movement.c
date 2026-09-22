/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 18:13:34 by lukorman          #+#    #+#             */
/*   Updated: 2026/09/21 23:46:37 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	move_forward(t_game *game, double speed);
void	strafe_player(t_game *game, double speed);
void	rotate_player(t_game *game, double angle);
void	move_player(t_game *game);

void	move_forward(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * speed;
	new_y = game->player.pos_y + game->player.dir_y * speed;
	if (!is_wall(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!is_wall(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	strafe_player(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.plane_x * speed;
	new_y = game->player.pos_y + game->player.plane_y * speed;
	if (!is_wall(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (!is_wall(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(angle)
		- game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle)
		+ game->player.dir_y * cos(angle);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(angle)
		- game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle)
		+ game->player.plane_y * cos(angle);
}

void	move_player(t_game *game)
{
	if (game->keys.w)
		move_forward(game, MOVE_SPEED);
	if (game->keys.s)
		move_forward(game, -MOVE_SPEED);
	if (game->keys.a)
		strafe_player(game, -MOVE_SPEED);
	if (game->keys.d)
		strafe_player(game, MOVE_SPEED);
	if (game->keys.left)
		rotate_player(game, -ROT_SPEED);
	if (game->keys.right)
		rotate_player(game, ROT_SPEED);
}
