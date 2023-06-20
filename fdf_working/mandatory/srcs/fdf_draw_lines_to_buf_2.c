/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_lines_to_buf_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:27:54 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/20 13:15:22 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	pixel_in_bounds(t_point *point)
{
	if ((int)point->x < 0 || (int)point->x > WIN_X)
		return (0);
	if ((int)point->y < 0 || (int)point->y > WIN_Y)
		return (0);
	return (1);
}

int	pixel_put(t_master *master, int color, int x, int y)
{
	if (x >= WIN_X || y >= WIN_Y || x < 0 || y < 0)
		return (-1);
	set_px_color_img_buf(master, color, x, y);
	return (0);
}

int	bresenhams_line(t_master *master, t_point from, t_point *to)
{
	t_point	delta;
	int		px_count;
	float	x;
	float	y;

	if (pixel_in_bounds(&from) == 0 && pixel_in_bounds(to) == 0)
		return (0);
	delta.x = to->x - from.x;
	delta.y = to->y - from.y;
	px_count = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= px_count;
	delta.y /= px_count;
	x = from.x;
	y = from.y;
	while (px_count > 0)
	{
		pixel_put(master, LINE_COLOR, (int)x, (int)y);
		x += delta.x;
		y += delta.y;
		px_count--;
	}
	return (0);
}

int	draw_lines_for_point(t_master *master, int i)
{
	t_point	*point;

	point = &master->map.pnts_copy[i];
	if ((point + 1)->x_coord)
		bresenhams_line(master, *point, (point + 1));
	if (point->y_coord <= master->map.size_y - 2)
		bresenhams_line(master, *point, (point + master->map.size_x));
	return (0);
}

int	iterate_over_points(t_master *master)
{
	int	i;

	i = 0;
	while (i < master->map.map_size - 1)
	{
		draw_lines_for_point(master, i);
		i++;
	}
	return (0);
}
