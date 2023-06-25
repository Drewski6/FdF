/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:04:55 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/21 13:57:12 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	
**	In the case when your color for your local system is not 32 bit color.
**	get local color value
**/

int	get_local_color(t_master *master, int color)
{
	if (master->bitmap.bits_per_pixel != 32)
		color = mlx_get_color_value(master->win.mlx_ptr, color);
	return (color);
}

int	render_background(t_master *master)
{
	int	color;
	int	x;
	int	y;

	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			color = 0;
			if (x < WIN_MENU_WIDTH)
				color = master->bitmap.menu_color;
			else
				color = master->bitmap.bg_color;
			set_px_color_img_buf(master, color, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

// int	print_render_info(t_master *master)
// {
// 	printf("rotation x:%f y:%f z:%f\n", master->map.x_rot,
// 		master->map.y_rot, master->map.z_rot);
// 	printf("offset x:%f y:%f z:%f\n", master->map.offset.x,
// 		master->map.offset.y, master->map.offset.z);
// 	printf("center x:%f y:%f z:%f\n", master->map.center.x,
// 		master->map.center.y, master->map.center.z);
// 	printf("origin x:%f y:%f z:%f\n", master->map.origin.x,
// 		master->map.origin.y, master->map.origin.z);
// 	printf("scale_default:%f scale:%f\n", master->map.map_scale_default,
// 		master->map.map_scale);
// 	return (0);
// }

// print_render_info(master);

int	render_map(t_master *master)
{
	render_background(master);
	render_lines(master);
	mlx_put_image_to_window(master->win.mlx_ptr, master->win.win_ptr,
		master->bitmap.img_ptr, 0, 0);
	render_strings(master);
	return (0);
}
