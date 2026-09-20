/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 17:08:32 by luiza             #+#    #+#             */
/*   Updated: 2026/09/20 00:32:23 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define ID_NO "NO"
# define ID_SO "SO"
# define ID_WE "WE"
# define ID_EA "EA"
# define ID_F "F"
# define ID_C "C"

# define FLAG_NO 1
# define FLAG_SO 2
# define FLAG_WE 4
# define FLAG_EA 8
# define FLAG_F 16
# define FLAG_C 32
# define FLAG_ALL 63
# define PI 3.14159265358979323846

typedef struct s_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_textures;

typedef struct s_player
{
	int		x;
	int		y;
	char	dir;
	double	angle;
}	t_player;

typedef struct s_data
{
	t_textures	tex;
	int			floor_color;
	int			ceiling_color;
	char		*map_line;
	int			flags;
	char		**grid;
	t_player	player;
}	t_data;

typedef struct s_fill
{
	char	**grid;
	char	**visited;
	int		height;
}	t_fill;

/* init_parser.c */
int		valid_extension(char *path);
int		parse_cub_file(char *path, t_data *data);

/* parse_elements.c */
int		parse_line(char *line, t_data *data);
int		parse_elements(int fd, t_data *data);

/* parse_texture.c */
int		open_texture(char *path);
int		set_texture(char **dst, char *value, int flag, t_data *data);
int		set_color(int *dst, char *value, int flag, t_data *data);

/* parse_utils.c */
int		is_blank_line(char *line);
char	*trim_identifier(char *line, char *id);
int		is_map_line(char *line);
int		check_all_elements(t_data *data);
void	strip_newline(char *str);

/* parse_color.c */
int		parse_color(char *raw, int *color);

/* flood_fill.c */
int		check_closed_map(t_data *data);

/* read_map.c */
char	**read_map(int fd, char *first_line);
int		validate_map(t_data *data);

/* validate_chars.c */
int		validate_map_chars(t_data *data);

/* map_utils.c */
int		map_height(char **grid);
int		map_width(char **grid, int height);

/* find_player.c */
int		find_player(t_data *data);

#endif