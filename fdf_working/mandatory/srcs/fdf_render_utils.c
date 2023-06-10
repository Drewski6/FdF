/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:04:55 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/10 08:01:50 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// none of the functions here are usefull yet. Just made for testing drawing.

int	rgb(const char r, const char g, const char b)
{
	int	encoded_color;

	encoded_color = 0;
	encoded_color += r;
	encoded_color <<= 8;
	encoded_color += g;
	encoded_color <<= 8;
	encoded_color += b;
	return (encoded_color);
}

/*  
**  Takes a 4 member array for shape
**  [top left x coord, top left y coord,
**  	bottom right x coord, bottom left y coord]
**	Takes 3 member array for color
**	[Red, Green, Blue]
**	Colors are between 0 and 255.
**	
**	Variadic function
**	takes pointer to box, number of int arguments that follow
**	varaible number of int arguments, each corresponding to a varaible 
**	to overwrite
**/

int	create_box(t_box *box, int n, ...)
{
	va_list		parg;
	int			new_val;
	int			*pos;

	pos = (int *)box;
	va_start(parg, n);
	box->x_start = 100;
	box->y_start = 100;
	box->x_length = 100;
	box->y_length = 100;
	box->color[0] = 0;
	box->color[1] = 102;
	box->color[2] = 255;
	while (n-- > 0)
	{
		new_val = va_arg(parg, int);
		if (new_val >= 0)
		{
			*pos = new_val;
			pos++;
		}
	}
	va_end(parg);
	return (0);
}

int	draw_box(t_master *master, t_box *box)
{
	int	x;
	int	y;

	x = box->x_start + box->x_length;
	while (x-- > box->x_start)
	{
		y = box->y_start + box->y_length;
		while (y-- > box->y_start)
		{
			mlx_pixel_put(master->win.mlx_ptr, master->win.win_ptr,
				x, y, rgb(box->color[0], box->color[1], box->color[2]));
		}
	}
	return (0);
}

int	draw_text(t_master *master, char *str)
{
	if (!str)
		return (-1);
	mlx_string_put(master->win.mlx_ptr, master->win.win_ptr,
		500, 500, rgb(255, 255, 255), str);
	return (0);
}

int	draw_map(t_master *master)
{
	t_box	box;

	create_box(&box, 0);
	draw_box(master, &box);
	draw_text(master, "Oh hey there!!!");
	return (0);
}
