/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_la_funcs_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 22:33:38 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/20 23:16:35 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	la_matrix_mult(float rot_mtx[3][3], t_point *point)
{
	int		i;
	int		j;
	float	product[3];
	float	*factor[3];

	i = 0;
	product[0] = point->x;
	product[1] = point->y;
	product[2] = point->z;
	factor[0] = &point->x;
	factor[1] = &point->y;
	factor[2] = &point->z;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			product[i] += rot_mtx[i][j] * *factor[j];
			j++;
		}
		i++;
	}
	point->x = product[0];
	point->y = product[1];
	point->z = product[2];
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
	rot_mtx[0][0] = cos(ang_rad);
	rot_mtx[0][2] = sin(ang_rad);
	rot_mtx[1][1] = 1;
	rot_mtx[2][0] = -sin(ang_rad);
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
	rot_mtx[0][0] = cos(ang_rad);
	rot_mtx[0][1] = -sin(ang_rad);
	rot_mtx[1][0] = sin(ang_rad);
	rot_mtx[1][1] = cos(ang_rad);
	rot_mtx[2][2] = 1;
	i = 0;
	while (i < master->map.map_size)
	{
		la_matrix_mult(rot_mtx, &master->map.pnts_copy[i]);
		i++;
	}
	return (0);
}
