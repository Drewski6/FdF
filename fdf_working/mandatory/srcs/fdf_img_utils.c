/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:25:46 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/10 08:11:08 by dpentlan         ###   ########.fr       */
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
