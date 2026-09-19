/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 20:46:32 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/19 00:21:08 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

static int	load_texture(t_game *game, t_texture *texture, char *path)
{
	texture->ptr = mlx_xpm_file_to_image(game->mlx_ptr, path,
		&texture->width, &texture->height);
	if (!texture->ptr)
		return (1);
	texture->addr = mlx_get_data_addr(texture->ptr,
		&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	if (!texture->addr)
	{
		mlx_destroy_image(game->mlx_ptr, texture->ptr);
		texture->ptr = NULL;
		return (1);
	}
	return (0);
}

int	init_textures(t_game *game, char **paths)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->textures[i].ptr = NULL;
		if (load_texture(game, &game->textures[i], paths[i]))
		{
			destroy_textures(game);
			return (1);
		}
		i++;
	}
	return (0);
}

void	destroy_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->textures[i].ptr)
			mlx_destroy_image(game->mlx_ptr, game->textures[i].ptr);
		i++;
	}
}
