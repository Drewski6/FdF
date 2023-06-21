/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_la_funcs_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:47:12 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/21 12:06:27 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	
**	linear algebra: apply scalar function to map
**	updn is a flag that indicates if the scale functions should scale up or down
**	0 indicates down, anything else indicates up
**/

int	la_scale(t_master *master, int updn)
{
	int		i;
	float	scalar;

	i = 0;
	if (updn == 0)
		scalar = 1 / master->map.map_scale;
	else
		scalar = master->map.map_scale;
	while (i < master->map.map_size)
	{
		master->map.pnts_copy[i].x *= scalar;
		master->map.pnts_copy[i].y *= scalar;
		master->map.pnts_copy[i].z *= scalar;
		i++;
	}
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

int	la_ortho_projection(t_master *master)
{
	float	rot_mtx[3][3];
	int		i;

	la_matrix_init(rot_mtx);
	rot_mtx[0][0] = 1;
	rot_mtx[1][1] = 1;
	rot_mtx[2][2] = 1;
	i = 0;
	while (i < master->map.map_size)
	{
		la_matrix_mult(rot_mtx, &master->map.pnts_copy[i]);
		i++;
	}
	return (0);
}

int	la_z_height(t_master *master, float divisor)
{
	int	i;

	i = 0;
	while (i < master->map.map_size)
	{
		master->map.pnts_copy[i].z = master->map.pnts_copy[i].z / divisor;
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
	la_translation(master, &master->map.origin, 0);
	if (master->map.renders == 0)
	{
		if (master->map.size_x > 100)
			master->map.z_scale = 2;
		else
			master->map.z_scale = master->map.size_x - master->map.size_z;
	}
	la_z_height(master, master->map.z_scale);
	la_scale(master, master->map.map_scale);
	la_x_rot(master, master->map.x_rot);
	la_y_rot(master, master->map.y_rot);
	la_z_rot(master, master->map.z_rot);
	la_ortho_projection(master);
	la_translation(master, &master->map.center, 1);
	la_translation(master, &master->map.offset, 1);
	return (0);
}
