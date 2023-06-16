/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_lines_to_buf_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:58:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/16 20:00:21 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_fits(t_master *master)
{
	int	i;

	i = 0;
	while (i < master->map.map_size)
	{
		if (master->map.pnts_copy[i].x < (WIN_MENU_WIDTH + MAP_MARGIN) 
			|| master->map.pnts_copy[i].x > (WIN_X - MAP_MARGIN))
			return (1);
		if (master->map.pnts_copy[i].y < MAP_MARGIN
			|| master->map.pnts_copy[i].y > (WIN_Y - MAP_MARGIN))
			return (1);
		i++;
	}
	return (0);
}

int	fit_map_to_screen(t_master *master)
{
	while (!map_fits(master))
	{
		master->map.map_scale += 0.2;
		la_scale(master, master->map.pnts_copy, master->map.map_scale);
	}
	return (0);
}

int	draw_lines(t_master *master)
{
	if (master->map.renders == 0)
		fit_map_to_screen(master);
	return (0);
}
