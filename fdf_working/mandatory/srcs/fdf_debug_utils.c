/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_debug_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:39:38 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/17 22:41:31 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_debug_read_points_data(t_master *master)
{
	t_point	*current;
	int		i;

	i = 0;
	current = master->map.points;
	while (current)
	{
		ft_printf("%d. x:%d y:%d z:%d\n", i, current->x, current->y, current->z);
		i++;
		current = current->next;
	}
	return (0);
}

void	fdf_debug_print_read_in_file(t_master *master)
{
	t_list	*current;
	int		i;

	ft_printf("Size of master is %d\n", sizeof(t_master));
	current = master->map.buf;
	while (current)
	{
		i = 0;
		while (((char **)current->content)[i])
		{
			ft_printf("%s ", ((char **)current->content)[i]);
			i++;
		}
		ft_printf("\n");
		current = current->next;
	}
}

void	p(t_point *point)
{
	printf("x = %f\ny = %f\nz = %f\nx_coord = %d\ny_coord = %d\n", point->x, point->y, point->z, point->x_coord, point->y_coord);
}

void	pa(t_master *master)
{
	int	i;

	i = 0;
	while (i < master->map.map_size)
	{
		p(&master->map.pnts_copy[i]);
		i++;
	}
}

void	fresh(t_master *master)
{
	mlx_put_image_to_window(master->win.mlx_ptr, master->win.win_ptr,
		master->bitmap.img_ptr, 0, 0);
}
