/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_sphere_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:40:09 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/26 13:03:37 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	sphere_coords(t_master *master)
{
	int		i;
	float	longi_step;
	float	lati_step;

	master->map.radius = master->map.size_x / (M_PI * 2);
	longi_step = (M_PI * 2) / (master->map.size_x - 1);
	lati_step = M_PI / (master->map.size_y);
	i = 0;
	while (i < master->map.map_size)
	{
		if (longi_step) {}
		if (lati_step) {}
		i++;
	}
	return (0);
}
