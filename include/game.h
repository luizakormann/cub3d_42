#ifndef GAME_H
# define GAME_H

# include "graphics.h"

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
} t_map;

typedef struct s_camera
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
} t_camera;

typedef enum e_tex_id
{
	TEX_NO,
	TEX_SO,
	TEX_WE,
	TEX_EA
}	t_tex_id;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*window;
	t_image		image;
	t_image		textures[4];
	t_map		map;
	t_camera	player;
	int			floor_color;
	int			ceiling_color;
} t_game;

int		init_graphics(t_game *game);
void	destroy_graphics(t_game *game);
int		init_image(t_game *game);
int		render_frame(void *param);

#endif
