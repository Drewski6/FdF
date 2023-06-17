/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_lines_to_buf_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:58:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/18 00:42:10 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_fits(t_master *master)
{
	int	i;

	i = 0;
	while (i < master->map.map_size)
	{
		if (master->map.pnts_copy[i].x < (WIN_MENU_WIDTH + MAP_MARGIN) 
			|| master->map.pnts_copy[i].x > (WIN_X - MAP_MARGIN))
			return (1);
		if (master->map.pnts_copy[i].y < MAP_MARGIN
			|| master->map.pnts_copy[i].y > (WIN_Y - MAP_MARGIN))
			return (1);
		i++;
	}
	return (0);
}

int	fit_map_to_screen(t_master *master)
{
	if (master) {}
	while (!map_fits(master))
	{
		master->map.map_scale += 0.2;
		la_scale(master, master->map.pnts_copy, master->map.map_scale);
	}
	return (0);
}

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
	if (x >= WIN_X || y >= WIN_Y ||x < 0 || y < 0)
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
	delta.x /= px_count;
	x = from.x;
	y = from.y;
	while (px_count > 0)
	{
		pixel_put(master, GREEN, (int)x, (int)y);
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

int	cmp_max_min(t_point *current, float *max_min)
{
	if (max_min[0] < current->x)
		max_min[0] = current->x;
	if (max_min[1] < current->y)
		max_min[1] = current->y;
	if (max_min[2] < current->z)
		max_min[2] = current->z;
	if (max_min[3] > current->x)
		max_min[3] = current->x;
	if (max_min[4] > current->y)
		max_min[4] = current->y;
	if (max_min[5] > current->z)
		max_min[5] = current->z;
	return (0);
}

int	refresh_max_min(t_master *master)
{
	int		i;
	float	max_min[6];

	i = 0;
	while (i < 6)
	{
		max_min[i] = 0;
		i++;
	}
	i = 0;
	while (i < master->map.map_size)
	{
		cmp_max_min(&master->map.pnts_copy[i], max_min);
		i++;
	}
	master->max_min.x_max = max_min[0];
	master->max_min.y_max = max_min[1];
	master->max_min.z_max = max_min[2];
	master->max_min.x_min = max_min[3];
	master->max_min.y_min = max_min[4];
	master->max_min.z_min = max_min[5];
	return (0);
}

int	draw_lines(t_master *master)
{
	if (master->map.renders == 0)
		fit_map_to_screen(master);
	refresh_max_min(master);
	iterate_over_points(master);
	return (0);
}
