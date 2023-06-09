/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_img_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:25:46 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/09 15:40:38 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_img_buffer(t_master *master)
{
	master->bitmap.img_ptr = mlx_new_image(master->win.mlx_ptr, WIN_X, WIN_Y);
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

int	create_image(t_master *master)
{
	if (master) {}
	ft_printf("something something darkside...\n");
	return (0);
}

