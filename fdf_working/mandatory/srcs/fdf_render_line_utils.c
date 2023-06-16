/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_line_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:49:52 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/16 12:51:04 by dpentlan         ###   ########.fr       */
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

/*	
**	linear algebra: apply scalar function to map
**	
**/

int	la_scale(t_master *master, t_point *cpy, float scalar)
{
	int	i;

	i = 0;
	while (i < master->map.map_size)
	{
		cpy[i].x = cpy[i].x * scalar;
		cpy[i].y = cpy[i].y * scalar;
		cpy[i].z = cpy[i].z * scalar;
		i++;
	}
	return (0);
}

/*	
**	manipulate your pnts_copy (copy of points read from map file)
**	functions:
**		adjust z height
**		adjust x rotation
**		adjust y rotation
**		adjust z rotation
**		adjust scale (zoom)
**		adjust translation
**/

int	manipulate_points(t_master *master)
{
	printf("First point before scalar: x:%f y:%f z:%f\n", master->map.pnts_copy->x,
		master->map.pnts_copy->y, master->map.pnts_copy->z);
	printf("map scale:\t%f\n", master->map.map_scale);
	if (master->map.map_scale != 1)
		la_scale(master, master->map.pnts_copy, master->map.map_scale);
	printf("First point after scalar: x:%f y:%f z:%f\n", master->map.pnts_copy->x,
		master->map.pnts_copy->y, master->map.pnts_copy->z);
	return (0);
}

int	fit_map_to_screen(t_master *master)
{
	if (master) {}
	ft_printf("First render!\n");
	return (0);
}

int	draw_lines(t_master *master)
{
	if (master->map.renders == 0)
		fit_map_to_screen(master);
	return (0);
}

/*	
**	3 steps for rendering lines:
**		1.	Make a copy of the points.
**		2.	Manipulate this copy with rotations, translations, scaling, etc
**		3.	Draw lines.
**/

int	render_lines(t_master *master)
{
	clock_t	start_time;

	if (DEBUG == 1)
	{
		ft_printf("center point: x:%d, y:%d z:%d\n",
			(int)master->map.center.x, (int)master->map.center.y,
			(int)master->map.center.z);
		start_time = clock();
	}
	copy_points(master);
	manipulate_points(master);
	draw_lines(master);
	free(master->map.pnts_copy);
	master->map.pnts_copy = 0;
	master->map.renders++;
	if (DEBUG == 1)
		ft_printf("render time:\t%d/%d s\n",
			clock() - start_time, CLOCKS_PER_SEC);
	return (0);
}
