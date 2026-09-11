/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 23:46:31 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/08 00:04:17 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "graphics.h"

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*window;
	t_image		image;
	t_map		map;
	t_player	player;
}	t_game;

int		init_graphics(t_game *game);
void	destroy_graphics(t_game *game);
int		init_image(t_game *game);
int		render_frame(void *param);
void	init_map(t_game *game);
void	init_player(t_game *game);

#endif