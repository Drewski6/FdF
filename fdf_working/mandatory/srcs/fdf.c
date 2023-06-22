/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:34:37 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/22 12:55:26 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	system_init(t_master *master)
{
	init_map(master);
	init_win(master);
	init_img_buffer(master, WIN_X, WIN_Y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_master	master;

	if (argc != 2)
		error_fdf_putstr("Usage: ./fdf [map_file_path]\n");
	system_init(&master);
	read_in_map(&master, argv[1]);
	render_map(&master);
	mlx_key_hook(master.win.win_ptr, &key_press, (void *)&master);
	mlx_hook(master.win.win_ptr, 17, 0, &close_program, (void *)&master);
	mlx_mouse_hook(master.win.win_ptr, &mouse_usage, (void *)&master);
	mlx_loop(master.win.mlx_ptr);
	return (0);
}
