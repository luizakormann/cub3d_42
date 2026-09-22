/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 23:45:48 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/21 20:12:54 by lukorman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DATA_BONUS_H
# define GAME_DATA_BONUS_H

# include "game_bonus.h"
# include "parser_bonus.h"
# include "mlx.h"

void	load_game_data(t_game *game, t_data *data);
int		init_textures(t_game *game, t_data *data);

#endif
