/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 12:45:47 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/06 09:54:48 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GRAPHICS_H
# define GRAPHICS_H

# define WINDOW_WIDTH 900
# define WINDOW_HEIGHT 680
# define KEY_ESC 65307
# define EVENT_DESTROY 17
# define CEILING_COLOR 0x87CEEB
# define FLOOR_COLOR 0x228B22

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_image;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*window;
	t_image	image;
}t_game;

void	*init_window(void *mlx_ptr, int width, int height, char *title);
int		init_graphics(t_game *game);
void	destroy_graphics(t_game *game);
void	put_pixel(t_image *image, int x, int y, int color);
int		init_image(t_game *game);
int		render_frame(void *param);

#endif
