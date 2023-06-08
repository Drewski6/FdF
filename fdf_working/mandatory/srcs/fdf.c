/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:34:37 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/08 14:27:12 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_master	master;

	if (argc != 2)
		error_fdf_putstr("Usage: ./fdf [map_file_path]\n");
	init_master(&master);
	init_win(&master);
	if (read_in_map(&master, argv[1]))
		error_fdf(&master, "read_in_map");
	ft_printf("largest x: %d largest y: %d largest z: %d\n",
		master.map.size_x, master.map.size_y, master.map.size_z);
	mlx_key_hook(master.win.win_ptr, &key_press, (void *)&master);
	mlx_loop(master.win.mlx_ptr);
	return (0);
}
