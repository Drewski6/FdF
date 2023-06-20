/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_la_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:47:12 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/20 13:46:09 by dpentlan         ###   ########.fr       */
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

int	la_matrix_init(float rot_mtx[3][3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			rot_mtx[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int	la_matrix_mult(float rot_mtx[3][3], t_point *point)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (j == 0)
				point->x += point->x * rot_mtx[i][j];
			if (j == 1)
				point->y += point->y * rot_mtx[i][j];
			if (j == 2)
				point->z += point->z * rot_mtx[i][j];
			j++;
		}
		i++;
	}
	return (0);
}

int	la_x_rot(t_master *master, float ang_deg)
{
	float	rot_mtx[3][3];
	float	ang_rad;
	int		i;

	la_matrix_init(rot_mtx);
	ang_rad = ang_deg * M_PI / 180;
	rot_mtx[0][0] = 1;
	rot_mtx[1][1] = cos(ang_rad);
	rot_mtx[1][2] = -sin(ang_rad);
	rot_mtx[2][1] = sin(ang_rad);
	rot_mtx[2][2] = cos(ang_rad);
	i = 0;
	while (i < master->map.map_size)
	{
		la_matrix_mult(rot_mtx, &master->map.pnts_copy[i]);
		i++;
	}
	return (0);
}

int	la_y_rot(t_master *master, float ang_deg)
{
	float	rot_mtx[3][3];
	float	ang_rad;
	int		i;

	la_matrix_init(rot_mtx);
	ang_rad = ang_deg * M_PI / 180;
	rot_mtx[0][0] = 1;
	rot_mtx[1][1] = cos(ang_rad);
	rot_mtx[1][2] = -sin(ang_rad);
	rot_mtx[2][1] = sin(ang_rad);
	rot_mtx[2][2] = cos(ang_rad);
	i = 0;
	while (i < master->map.map_size)
	{
		la_matrix_mult(rot_mtx, &master->map.pnts_copy[i]);
		i++;
	}
	return (0);
}

int	la_z_rot(t_master *master, float ang_deg)
{
	float	rot_mtx[3][3];
	float	ang_rad;
	int		i;

	la_matrix_init(rot_mtx);
	ang_rad = ang_deg * M_PI / 180;
	rot_mtx[0][0] = 1;
	rot_mtx[1][1] = cos(ang_rad);
	rot_mtx[1][2] = -sin(ang_rad);
	rot_mtx[2][1] = sin(ang_rad);
	rot_mtx[2][2] = cos(ang_rad);
	i = 0;
	while (i < master->map.map_size)
	{
		la_matrix_mult(rot_mtx, &master->map.pnts_copy[i]);
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
	la_x_rot(master, 0);
	la_y_rot(master, 0);
	la_z_rot(master, 0);
	if (master->map.map_scale != 1)
		la_scale(master, master->map.map_scale);
	la_translation(master, &master->map.center, 1);
	la_translation(master, &master->map.origin, 0);
	return (0);
}
