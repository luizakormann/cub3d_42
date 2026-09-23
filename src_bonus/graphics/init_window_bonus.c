/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 13:04:57 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/21 23:48:53 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics_bonus.h"
#include "mlx.h"

void	*init_window(void *mlx_ptr, int width, int height, char *title)
{
	return (mlx_new_window(mlx_ptr, width, height, title));
}
