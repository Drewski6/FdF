/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_la_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:47:12 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/20 11:52:33 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	
**	linear algebra: apply scalar function to map
**	
**/

int	la_scale(t_master *master, float scalar)
{
	int	i;

	i = 0;
	la_translation(master, &master->map.center, 0);
	while (i < master->map.map_size)
	{
		master->map.pnts_copy[i].x *= scalar;
		master->map.pnts_copy[i].y *= scalar;
		master->map.pnts_copy[i].z *= scalar;
		i++;
	}
	la_translation(master, &master->map.center, 1);
	return (0);
}

/*	
**	add acts as an addition flag: if set to anything but 0, the function
**	will add t_point translate to master->map.pnts_copy
**/

int	la_translation(t_master *master, t_point *translate, int add)
{
	int	i;

	i = 0;
	if (add)
	{
		while (i < master->map.map_size)
		{
			master->map.pnts_copy[i].x += translate->x;
			master->map.pnts_copy[i].y += translate->y;
			master->map.pnts_copy[i].z += translate->z;
			i++;
		}
		return (0);
	}
	while (i < master->map.map_size)
	{
		master->map.pnts_copy[i].x -= translate->x;
		master->map.pnts_copy[i].y -= translate->y;
		master->map.pnts_copy[i].z -= translate->z;
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
		la_scale(master, master->map.map_scale);
	la_translation(master, &master->map.center, 1);
	la_translation(master, &master->map.origin, 0);
	return (0);
}
