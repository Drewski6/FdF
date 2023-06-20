/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_line_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:49:52 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/20 11:29:50 by dpentlan         ###   ########.fr       */
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
**	3 steps for rendering lines:
**		1.	Make a copy of the points.
**		2.	Manipulate this copy with rotations, translations, scaling, etc
**		3.	Draw lines.
**/

int	render_lines(t_master *master)
{
	copy_points(master);
	manipulate_points(master);
	draw_lines(master);
	free(master->map.pnts_copy);
	master->map.pnts_copy = 0;
	master->map.renders++;
	return (0);
}
