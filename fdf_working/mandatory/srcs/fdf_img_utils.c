/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:25:46 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/17 22:34:07 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 *	the address returned by mlx_get_data_addr contains pixel data for 
 *	an image of whatever size you gave it.
 *	To edit you need to access the address and iterate over it depending 
 *	on each pixel size.
 */

int	set_px_color_img_buf(t_master *master, int color, int x, int y)
{
	int	offset;

	offset = (y * master->bitmap.size_line) + (x * 4);
	if (master->bitmap.endian == 1)
	{
		master->bitmap.img_buf[offset + 0] = 1;
		master->bitmap.img_buf[offset + 1] = (color >> 16) & 0xFF;
		master->bitmap.img_buf[offset + 2] = (color >> 8) & 0xFF;
		master->bitmap.img_buf[offset + 3] = color & 0xFF;
	}
	else
	{
		master->bitmap.img_buf[offset + 1] = color & 0xFF;
		master->bitmap.img_buf[offset + 1] = (color >> 8) & 0xFF;
		master->bitmap.img_buf[offset + 2] = (color >> 16) & 0xFF;
		master->bitmap.img_buf[offset + 3] = 1;
	}
	return (0);
}

int	init_img_buffer(t_master *master, int img_size_x, int img_size_y)
{
	master->bitmap.img_ptr = mlx_new_image(master->win.mlx_ptr,
			img_size_x, img_size_y);
	master->bitmap.bits_per_pixel = 0;
	master->bitmap.size_line = 0;
	master->bitmap.endian = 0;
	master->bitmap.img_buf = mlx_get_data_addr(
			master->bitmap.img_ptr,
			&master->bitmap.bits_per_pixel,
			&master->bitmap.size_line,
			&master->bitmap.endian);
	return (0);
}
