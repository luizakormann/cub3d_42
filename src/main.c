#include "graphics.h"
#include "mlx.h"
#include <stddef.h>

static int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_loop_end(game->mlx_ptr);
	return (0);
}

static int	handle_key(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		close_window(param);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx_ptr = NULL;
	game.window = NULL;
	if (init_graphics(&game))
		return (1);
	mlx_key_hook(game.window, handle_key, &game);
	mlx_hook(game.window, EVENT_DESTROY, 0, close_window, &game);
	mlx_loop(game.mlx_ptr);
	destroy_graphics(&game);
	return (0);
}
