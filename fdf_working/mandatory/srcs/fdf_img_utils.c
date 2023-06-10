/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:25:46 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/10 08:00:51 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 *	the address returned by mlx_get_data_addr contains pixel data for 
 *	an image of whatever size you gave it.
 *	To edit you need to access the address and iterate over it depending 
 *	on each pixel size.
 */

int	init_img_buffer(t_master *master)
{
	master->bitmap.img_ptr = mlx_new_image(master->win.mlx_ptr, 100, 100);
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

// below functions are useless so far. Just made them for testing drawing.

int	edit_img(t_master *master)
{
	char	*img_buf;

	img_buf = master->bitmap.img_ptr;
	ft_printf("bits_per_pixel = %d\n", master->bitmap.bits_per_pixel);
	ft_printf("img_buf addr = %x\n", (int *)img_buf);
	img_buf += 1;
	ft_printf("img_buf addr +1 = %d\n", (int *)img_buf);
	return (0);
}

int	draw_img(t_master *master)
{
	edit_img(master);
	mlx_put_image_to_window(master->win.mlx_ptr,
		master->win.win_ptr,
		master->bitmap.img_ptr,
		50, 50);
	return (0);
}

int	create_image(t_master *master)
{
	ft_printf("bits_per_pixel = %d\n", master->bitmap.bits_per_pixel);
	ft_printf("size_line = %d\n", master->bitmap.size_line);
	ft_printf("endian = %d\n", master->bitmap.endian);
	return (0);
}
