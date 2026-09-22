/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 17:45:34 by lukorman             #+#    #+#             */
/*   Updated: 2026/09/21 20:16:19 by lukorman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "error_utils_bonus.h"

int		is_blank_line(char *line);
char	*trim_identifier(char *line, char *id);
int		is_map_line(char *line);
int		check_all_elements(t_data *data);
void	strip_newline(char *str);

int	is_blank_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*trim_identifier(char *line, char *id)
{
	int	len;

	len = ft_strlen(id);
	if ((int)ft_strlen(line) <= len)
		return (NULL);
	if (ft_strncmp(line, id, len) != 0)
		return (NULL);
	if (line[len] != ' ' && line[len] != '\t')
		return (NULL);
	while (line[len] == ' ' || line[len] == '\t')
		len++;
	return (line + len);
}

int	is_map_line(char *line)
{
	if (is_blank_line(line))
		return (0);
	if (trim_identifier(line, ID_NO) || trim_identifier(line, ID_SO)
		|| trim_identifier(line, ID_WE) || trim_identifier(line, ID_EA))
		return (0);
	if (trim_identifier(line, ID_F) || trim_identifier(line, ID_C))
		return (0);
	return (1);
}

int	check_all_elements(t_data *data)
{
	if ((data->flags & FLAG_ALL) != FLAG_ALL)
	{
		print_error("Missing one or more required elements (NO/SO/WE/EA/F/C)");
		return (-1);
	}
	return (0);
}

void	strip_newline(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}
