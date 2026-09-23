/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 23:45:48 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/17 23:51:53 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DATA_H
# define GAME_DATA_H

# include "game.h"
# include "parser.h"
# include "mlx.h"

void	load_game_data(t_game *game, t_data *data);
int		init_textures(t_game *game, t_data *data);

#endif
