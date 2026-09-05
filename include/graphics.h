/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 12:45:47 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/04 21:51:29 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GRAPHICS_H
# define GRAPHICS_H

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 680
# define KEY_ESC 65307
# define EVENT_DESTROY 17

typedef struct s_game
{
	void	*mlx_ptr;
	void	*window;
}t_game;

void	*init_window(void *mlx_ptr, int width, int height, char *title);
int		init_graphics(t_game *game);
void	destroy_graphics(t_game *game);

#endif
