/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_la_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:47:12 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/16 20:00:02 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		cpy[i].x = master->map.points[i].x * scalar;
		cpy[i].y = master->map.points[i].y * scalar;
		cpy[i].z = master->map.points[i].z * scalar;
		i++;
	}
	return (0);
}

int	la_translation(t_master *master, t_point *translate)
{
	int	i;

	i = 0;
	while (i < master->map.map_size)
	{
		master->map.pnts_copy[i].x += translate->x;
		master->map.pnts_copy[i].y += translate->y;
		master->map.pnts_copy[i].z += translate->z;
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
	if (master->map.map_scale != 1)
		la_scale(master, master->map.pnts_copy, master->map.map_scale);
	la_translation(master, &master->map.center);
	return (0);
}

