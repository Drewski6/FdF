/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_la_funcs_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:56:06 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/27 19:56:23 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
