/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_lines_to_buf_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 19:58:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/17 18:43:51 by dpentlan         ###   ########.fr       */
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
	while (!map_fits(master))
	{
		master->map.map_scale += 0.2;
		la_scale(master, master->map.pnts_copy, master->map.map_scale);
	}
	return (0);
}

int	bresenhams_line(t_master *master, t_point from, t_point *to)
{
	if (master) {}
	t_point	delta;
	int		px_count;
	//int		seg_len;

	delta.x = from.x - to->x;
	delta.y = from.y - to->y;
	px_count = sqrt((delta.x * delta.x) + (delta.y * delta.y));
	//seg_len = px_count;
	delta.x /= px_count;
	delta.x /= px_count;
	while (px_count > 0)
	{
		set_px_color_img_buf(master, GREEN, from.x, from.y);
		from.x += delta.x;
		from.x += delta.y;
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
	while (i < master->map.map_size)
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