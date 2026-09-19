/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 11:26:09 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/19 00:21:27 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	put_pixel(t_image *image, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= image->width
		|| y < 0 || y >= image->height)
		return ;
	pixel = image->addr + (y * image->line_length)
		+ (x * (image->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}
