/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaidda-s <kaidda-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 17:41:49 by luiza             #+#    #+#             */
/*   Updated: 2026/09/18 23:48:24 by kaidda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_UTILS_H
# define ERROR_UTILS_H

# include "libft.h"
# include "parser.h"

void	print_error(char *msg);
void	free_data(t_data *data);

#endif