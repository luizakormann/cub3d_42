/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 13:04:57 by kaidda-s          #+#    #+#             */
/*   Updated: 2026/09/05 23:36:56 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "mlx.h"

void	*init_window(void *mlx_ptr, int width, int height, char *title)
{
	return (mlx_new_window(mlx_ptr, width, height, title));
}
