/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 18:05:48 by lukorman             #+#    #+#             */
/*   Updated: 2026/09/17 23:57:08 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "game.h"
# include "libft.h"
# include <math.h>
# include "mlx.h"

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03

int		is_wall(t_game *game, double x, double y);
void	move_forward(t_game *game, double speed);
void	strafe_player(t_game *game, double speed);
void	rotate_player(t_game *game, double angle);
void	move_player(t_game *game);
int		key_press(int keycode, void *param);
int		key_release(int keycode, void *param);

#endif