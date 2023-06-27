/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_line_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:49:52 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/27 19:38:41 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	copy_points(t_master *master)
{
	master->map.pnts_copy = (t_point *)ft_calloc(sizeof(t_point),
			master->map.map_size);
	if (!master->map.points)
		error_fdf(master, "malloc");
	master->map.pnts_copy = ft_memcpy(master->map.pnts_copy, master->map.points,
			master->map.map_size * sizeof(t_point));
	return (0);
}

int	map_fits(t_master *master)
{
	int	i;

	i = 0;
	while (i < master->map.map_size)
	{
		if (master->map.pnts_copy[i].x
			< (WIN_MENU_WIDTH + MAP_MARGIN - (int)master->map.center.x))
			return (1);
		if (master->map.pnts_copy[i].x
			> (WIN_X - MAP_MARGIN - (int)master->map.center.x))
			return (2);
		if (master->map.pnts_copy[i].y
			< MAP_MARGIN - (int)master->map.center.y)
			return (3);
		if (master->map.pnts_copy[i].y
			> (WIN_Y - MAP_MARGIN - (int)master->map.center.y))
			return (4);
		i++;
	}
	return (0);
}

int	fit_map_to_screen(t_master *master)
{
	int	i;

	i = 0;
	while (!map_fits(master))
	{
		la_scale(master, 0);
		master->map.map_scale += 0.2;
		la_scale(master, 1);
		i++;
	}
	master->map.map_scale_default = master->map.map_scale;
	return (0);
}

/*	
**	3 steps for rendering lines:
**		1.	Make a copy of the points.
**		2.	If first render, find appropriate x/y scale and z_scale
**		2.	Manipulate this copy with rotations, translations, scaling, etc
**		3.	Draw lines.
**/

int	render_lines(t_master *master)
{
	copy_points(master);
	if (master->map.renders == 0)
	{
		la_translation(master, &master->map.origin, 0);
		fit_map_to_screen(master);
		if (master->map.size_x > 100)
			master->map.z_scale = 2;
		else
			master->map.z_scale = master->map.size_x - master->map.size_z + 1;
	}
	manipulate_points(master);
	draw_lines(master);
	free(master->map.pnts_copy);
	master->map.pnts_copy = 0;
	master->map.renders++;
	return (0);
}
