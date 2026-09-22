/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 21:17:37 by luiza             #+#    #+#             */
/*   Updated: 2026/09/21 21:44:26 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "game_bonus.h"
# include "parser_bonus.h"
# include "graphics_bonus.h"

# define KEY_E 101
# define KEY_M 109
# define EVENT_MOTION 6
# define MASK_MOTION (1L << 6)
# define DOOR_COLOR 0x5C3A21
# define DOOR_OPEN_COLOR 0x8B5A2B
# define DOOR_OPEN_TIME 180
# define MOUSE_SENS 0.002

void	init_doors(t_game *game, t_data *data);
t_door	*get_door(t_game *game, int x, int y);
void	toggle_door(t_game *game);
void	update_doors(t_game *game);

void	draw_minimap(t_game *game);

int		mouse_move(int x, int y, void *param);
void	init_mouse(t_game *game);

#endif