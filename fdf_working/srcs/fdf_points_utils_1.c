/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_points_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:29:43 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/28 07:57:04 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	build_points_largest_z(t_master *master)
{
	int		largest;
	t_point	*current;

	largest = -2147483648;
	current = master->map.points;
	while (current)
	{
		if (current->z > largest)
			largest = current->z;
		current = current->next;
	}
	return (largest);
}

int	build_points_set_x_y(t_point *points_current, int x, int y)
{
	points_current->x = x;
	points_current->x_coord = x;
	points_current->y = y;
	points_current->y_coord = y;
	return (0);
}

void	build_points_list_loop(t_master *master)
{
	int		y;
	int		x;
	t_point	*points_current;
	t_list	*buf_current;

	y = -1;
	points_current = master->map.points;
	buf_current = master->map.buf;
	while (++y < master->map.size_y)
	{
		x = -1;
		while (++x < master->map.size_x)
		{
			build_points_set_x_y(points_current, x, y);
			if (!((char **)buf_current->content)[x])
				error_fdf(master, "Map Dimensions Error");
			points_current->z = ft_atoi(((char **)buf_current->content)[x]);
			if (y == master->map.size_y - 1 && x == master->map.size_x - 1)
				points_current->next = 0;
			else
				points_current->next = points_current + 1;
			points_current = points_current->next;
		}
		buf_current = buf_current->next;
	}
}

int	build_points_apply_color_gradient(t_master *master)
{
	int	i;
	int	top_color;
	int	base_color;
	int	step;

	top_color = L_TOP_C;
	base_color = L_BASE_C;
	if (master->map.size_z == 0)
		step = 0;
	else
		step = (top_color - base_color) / master->map.size_z;
	i = 0;
	while (i < master->map.map_size)
	{
		if (master->map.points[i].z == 0)
			master->map.points[i].color = base_color;
		else
			master->map.points[i].color = master->map.points[i].z * step;
		i++;
	}
	return (0);
}

int	build_points_list(t_master *master)
{
	master->map.size_x = 0;
	master->map.size_x = build_points_get_x_len(master);
	master->map.size_y = 0;
	master->map.size_y = build_points_get_y_len(master);
	master->map.map_size = master->map.size_x * master->map.size_y;
	if (!master->map.map_size)
		error_fdf(master, "File size Zero");
	master->map.points = (t_point *)ft_calloc(sizeof(t_point),
			master->map.map_size);
	if (!master->map.points)
		error_fdf(master, "malloc");
	build_points_list_loop(master);
	set_points_ceil(master);
	master->map.size_z = build_points_largest_z(master);
	build_points_set_origin(master);
	build_points_apply_color_gradient(master);
	return (0);
}
