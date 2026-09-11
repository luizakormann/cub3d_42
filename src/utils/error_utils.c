/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 17:43:19 by luiza             #+#    #+#             */
/*   Updated: 2026/09/10 20:45:48 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_utils.h"

void	print_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}
 
void	free_data(t_data *data)
{
	if (data->tex.no)
		free(data->tex.no);
	if (data->tex.so)
		free(data->tex.so);
	if (data->tex.we)
		free(data->tex.we);
	if (data->tex.ea)
		free(data->tex.ea);
	if (data->map_line)
		free(data->map_line);
}