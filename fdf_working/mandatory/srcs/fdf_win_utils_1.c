/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_win_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:50:04 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/21 14:12:36 by dpentlan         ###   ########.fr       */
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

int	manipulation_control_1(t_master *master, int key)
{
	if (key == X_KEY)
		master->map.x_rot += 15;
	if (key == Y_KEY)
		master->map.y_rot += 15;
	if (key == Z_KEY)
		master->map.z_rot += 15;
	if (key == U_ARROW)
		master->map.offset.y -= 50;
	if (key == D_ARROW)
		master->map.offset.y += 50;
	if (key == L_ARROW)
		master->map.offset.x -= 50;
	if (key == R_ARROW)
		master->map.offset.x += 50;
	return (1);
}

int	manipulation_control_2(t_master *master, int key)
{
	if (key == PLUS_KEY)
		master->map.map_scale += 0.2;
	if (key == MINUS_KEY)
		master->map.map_scale -= 0.2;
	return (0);
}

int	key_press(int key, void *param)
{
	t_master	*master;
	int			re_render_needed;
	static int	i;

	i++;
	re_render_needed = 0;
	master = (t_master *)param;
	if (key == ESC)
		close_program(master);
	if (key == ENTER)
	{
		if (i == 1)
			return (0);
	}
	if (key == X_KEY || key == Y_KEY || key == Z_KEY || key == U_ARROW
		|| key == D_ARROW || key == L_ARROW || key == R_ARROW)
		re_render_needed = manipulation_control_1(master, key);
	if (key == PLUS_KEY || key == MINUS_KEY)
		re_render_needed = manipulation_control_2(master, key);
	if (key == R_KEY)
		re_render_needed = reset_projection(master);
	if (re_render_needed == 1)
		render_map(master);
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
