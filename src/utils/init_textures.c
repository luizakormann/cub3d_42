/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 17:31:45 by luiza             #+#    #+#             */
/*   Updated: 2026/09/19 00:38:46 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_data.h"

static int	load_textures(t_game *game, t_image *tex, char *path)
{
	tex->ptr = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&tex->width, &tex->height);
	if (!tex->ptr)
		return (1);
	tex->addr = mlx_get_data_addr(tex->ptr, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
	if (!tex->addr)
		return (1);
	return (0);
}

int	init_textures(t_game *game, t_data *data)
{
	if (load_textures(game, &game->textures[TEX_NO], data->tex.no))
		return (1);
	if (load_textures(game, &game->textures[TEX_SO], data->tex.so))
		return (1);
	if (load_textures(game, &game->textures[TEX_WE], data->tex.we))
		return (1);
	if (load_textures(game, &game->textures[TEX_EA], data->tex.ea))
		return (1);
	return (0);
}
