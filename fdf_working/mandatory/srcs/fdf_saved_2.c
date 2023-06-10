/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_saved_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 08:10:55 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/10 08:11:03 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
