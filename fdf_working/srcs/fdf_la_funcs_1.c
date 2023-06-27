/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_la_funcs_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:47:12 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/27 19:48:38 by dpentlan         ###   ########.fr       */
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

int	la_cabinet_projection(t_master *master)
{
	float	rot_mtx[3][3];
	float	ang_deg;
	float	ang_rad;
	int		i;

	ang_deg = 65;
	ang_rad = ang_deg * M_PI / 180;
	la_matrix_init(rot_mtx);
	rot_mtx[0][0] = 1;
	rot_mtx[0][2] = cos(ang_rad) / 2;
	rot_mtx[1][1] = 1;
	rot_mtx[1][2] = sin(ang_rad) / 2;
	rot_mtx[2][2] = 1;
	i = 0;
	while (i < master->map.map_size)
	{
		la_matrix_mult(rot_mtx, &master->map.pnts_copy[i]);
		i++;
	}
	return (0);
}

int	la_z_height(t_master *master, float z_scale)
{
	int	i;

	i = 0;
	while (i < master->map.map_size)
	{
		master->map.pnts_copy[i].z = master->map.pnts_copy[i].z / z_scale;
		i++;
	}
	return (0);
}

/*	
**	manipulate your pnts_copy (copy of points read from map file)
**	functions:
**		move map center from top left to center with la_translation
**		adjust z height (relative height of z axis)
**		apply x rotation with rotation matrix
**		apply y rotation with rotation matrix
**		apply z rotation with rotation matrix
**		adjust scale (zoom)
**		translate to center of screen
**		translate to offset (configured by user with keyboard)
**/

int	manipulate_points(t_master *master)
{
	if (master->map.renders != 0)
		la_translation(master, &master->map.origin, 0);
	la_z_height(master, master->map.z_scale);
	la_x_rot(master, master->map.x_rot);
	la_y_rot(master, master->map.y_rot);
	la_z_rot(master, master->map.z_rot);
	if (master->map.alt_proj == 1)
		la_cabinet_projection(master);
	else
		la_ortho_projection(master);
	if (master->map.renders != 0)
		la_scale(master, master->map.map_scale);
	la_translation(master, &master->map.center, 1);
	la_translation(master, &master->map.offset, 1);
	return (0);
}
