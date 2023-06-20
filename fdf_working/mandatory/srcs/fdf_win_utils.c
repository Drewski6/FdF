/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_win_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:50:04 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/20 16:00:18 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_usage(int button, int x, int y, void *param)
{
	t_master	*master;
	static int	i;

	i++;
	master = (t_master *)param;
	if (master)
	{
	}
	if (button == 1)
	{
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
	{
		if (i == 1)
			return (0);
		ft_printf("You pressed ENTER\n");
	}
	if (key == X_LC)
	{
		master->map.x_rot += 15;
		render_map(master);
	}
	if (key == Y_LC)
	{
		master->map.y_rot += 15;
		render_map(master);
	}
	if (key == Z_LC)
	{
		master->map.z_rot += 15;
		render_map(master);
	}
	if (key == U_ARROW)
	{
		master->map.offset.y -= 10;
		render_map(master);
	}
	if (key == D_ARROW)
	{
		master->map.offset.y += 10;
		render_map(master);
	}
	if (key == L_ARROW)
	{
		master->map.offset.x -= 10;
		render_map(master);
	}
	if (key == R_ARROW)
	{
		master->map.offset.x += 10;
		render_map(master);
	}
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
