/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_win_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:50:04 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/09 16:44:54 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_usage(int button, int x, int y, void *param)
{
	t_master	*master;
	static int	i;
	t_box		box;
	int			box_size;

	box_size = 50;
	i++;
	master = (t_master *)param;
	if (button == 1)
	{
		create_box(&box, 7, x - (box_size / 2), y - (box_size / 2), box_size, box_size, 102, 255, 51);
		draw_box(master, &box);
	}
	ft_printf("button: %d x: %d y: %d i: %d\n", button, x, y, i);
	return (0);
}

int	key_press(int key, void *param)
{
	t_master	*master;
	static int	i;

	i++;
	master = (t_master *)param;
	if (key == ESC)
		close_program(master);
	if (key == ENTER)
		ft_printf("You pressed ENTER\n");
	ft_printf("Key: %d i: %d\n", key, i);
	return (0);
}

int	init_win(t_master *master)
{
	master->win.mlx_ptr = 0;
	master->win.win_ptr = 0;
	master->win.mlx_ptr = mlx_init();
	if (!master->win.mlx_ptr)
		error_fdf(master, "mlx_init");
	master->win.win_ptr = mlx_new_window(master->win.mlx_ptr,
			WIN_X, WIN_Y, WIN_NAME);
	if (!master->win.win_ptr)
		error_fdf(master, "mlx_new_window");
	return (0);
}
