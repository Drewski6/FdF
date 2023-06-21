/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_lines_to_buf_3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:40:11 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/21 10:40:18 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	iterate_over_points(t_master *master)
{
	int	i;

	i = 0;
	while (i < master->map.map_size - 1)
	{
		draw_lines_for_point(master, i);
		i++;
	}
	return (0);
}
