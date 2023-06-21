/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_win_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:05:01 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/21 14:06:01 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	reset_projection(t_master *master)
{
	master->map.x_rot = 0;
	master->map.y_rot = 0;
	master->map.z_rot = 0;
	master->map.offset.x = 0;
	master->map.offset.y = 0;
	master->map.offset.z = 0;
	master->map.map_scale = master->map.map_scale_default;
	return (1);
}
