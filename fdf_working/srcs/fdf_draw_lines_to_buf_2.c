/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_lines_to_buf_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:27:54 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/28 09:58:10 by dpentlan         ###   ########.fr       */
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
	if (x >= WIN_X || y >= WIN_Y || x < WIN_MENU_WIDTH || y < 0)
		return (-1);
	set_px_color_img_buf(master, color, x, y);
	return (0);
}

int	apply_gradient(t_point *from, t_point *to, int line_size, int pixel_no)
{
	int	color_diff;

	color_diff = from->color - to->color;
	color_diff /= line_size;
	return (from->color + (color_diff * pixel_no));
}

int	bresenhams_line(t_master *master, t_point from, t_point *to)
{
	t_point	delta;
	t_point	pixel;
	int		px_count;
	int		line_size;

	if (pixel_in_bounds(&from) == 0 && pixel_in_bounds(to) == 0)
		return (0);
	delta.x = to->x - from.x;
	delta.y = to->y - from.y;
	px_count = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	delta.x /= px_count;
	delta.y /= px_count;
	pixel.x = from.x;
	pixel.y = from.y;
	line_size = px_count;
	while (px_count > 0)
	{
		pixel_put(master, apply_gradient(&from, to, line_size, px_count),
			(int)pixel.x, (int)pixel.y);
		pixel.x += delta.x;
		pixel.y += delta.y;
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
