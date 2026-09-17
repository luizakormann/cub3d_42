/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 12:45:47 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/16 02:35:39 by kaidda-s         ###   ########.fr       */
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
# define WALL_COLOR 0x8B4513

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

void	*init_window(void *mlx_ptr, int width, int height, char *title);
void	put_pixel(t_image *image, int x, int y, int color);

#endif
