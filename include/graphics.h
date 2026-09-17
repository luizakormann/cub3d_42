/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 12:45:47 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/16 22:17:25 by luiza            ###   ########.fr       */
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

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define EVENT_KEYPRESS 2
# define EVENT_KEYRELEASE 3
# define MASK_KEYPRESS (1L << 0)
# define MASK_KEYRELEASE (1L << 1)

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
