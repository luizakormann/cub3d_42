/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 17:08:32 by luiza             #+#    #+#             */
/*   Updated: 2026/09/10 19:26:05 by luiza            ###   ########.fr       */
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
# define FLAG_ALL (FLAG_NO | FLAG_SO | FLAG_WE | FLAG_EA | FLAG_F | FLAG_C)

typedef struct s_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}t_textures;

typedef struct s_data
{
	t_textures	tex;
	char		*floor_rgb;
	char		*ceiling_rgb;
	char		*map_line;
	int			flags;
}t_data;

//init_parser.c
int		valid_extension(char *path);
int		parse_cub_file(char *path, t_data *data);

//parse_elements.c
int		parse_line(char *line, t_data *data);
int		parse_elements(int fd, t_data *data);
 
//parse_texture.c
int		open_texture(char *path);
int		set_texture(char **dst, char *value, int flag, t_data *data);
int		set_color(char **dst, char *value, int flag, t_data *data);

//parse_utils.c
int		is_blank_line(char *line);
char	*trim_identifier(char *line, char *id);
int		is_map_line(char *line);
int		check_all_elements(t_data *data);

#endif