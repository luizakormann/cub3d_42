/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 00:25:17 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/19 23:42:44 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "mlx.h"
#include "parser.h"
#include "error_utils.h"
#include "game.h"
#include "game_data.h"
#include "player.h"
#include "libft.h"

static int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_loop_end(game->mlx_ptr);
	return (0);
}

static int	start_graphics(t_game *game, t_data *data)
{
	if (init_graphics(game))
	{
		free_data(data);
		return (1);
	}
	if (init_image(game))
	{
		destroy_graphics(game);
		free_data(data);
		return (1);
	}
	return (0);
}

static void	setup_hooks(t_game *game)
{
	mlx_hook(game->window, EVENT_KEYPRESS,
		MASK_KEYPRESS, key_press, game);
	mlx_hook(game->window, EVENT_KEYRELEASE,
		MASK_KEYRELEASE, key_release, game);
	mlx_hook(game->window, EVENT_DESTROY, 0, close_window, game);
	mlx_loop_hook(game->mlx_ptr, render_frame, game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_data	data;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2 || !valid_extension(argv[1]))
		return (1);
	if (parse_cub_file(argv[1], &data) < 0)
		return (1);
	load_game_data(&game, &data);
	if (start_graphics(&game, &data))
		return (1);
	if (init_textures(&game, &data))
	{
		destroy_graphics(&game);
		free_data(&data);
		return (1);
	}
	setup_hooks(&game);
	mlx_loop_hook(game.mlx_ptr, render_frame, &game);
	mlx_loop(game.mlx_ptr);
	destroy_graphics(&game);
	free_data(&data);
	ft_putstr_fd("See you later, alligator!\n", 2);
	return (0);
}
