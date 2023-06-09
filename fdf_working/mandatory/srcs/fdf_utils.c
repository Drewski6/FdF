/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:17:43 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/09 16:04:36 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error_fdf(t_master *master, char *message)
{
	if (master->win.win_ptr)
		mlx_destroy_window(master->win.mlx_ptr, master->win.win_ptr);
	if (master->bitmap.img_ptr)
		mlx_destroy_image(master->win.mlx_ptr, master->bitmap.img_ptr);
	if (master->win.mlx_ptr)
	{
		mlx_destroy_display(master->win.mlx_ptr);
		free(master->win.mlx_ptr);
		master->win.mlx_ptr = 0;
	}
	if (master->map.buf)
		ft_lstclear(&(master->map.buf), &ft_free_tab);
	if (master->map.points)
		free(master->map.points);
	if (message)
		perror(message);
	exit(EXIT_FAILURE);
}

int	error_fdf_putstr(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	close_program(t_master *master)
{
	mlx_destroy_window(master->win.mlx_ptr, master->win.win_ptr);
	mlx_destroy_image(master->win.mlx_ptr, master->bitmap.img_ptr);
	mlx_destroy_display(master->win.mlx_ptr);
	free(master->win.mlx_ptr);
	if (master->map.points)
	{
		free(master->map.points);
		master->map.points = 0;
	}
	exit(0);
}

void	init_master(t_master *master)
{
	master->map.buf = 0;
	master->map.points = 0;
}
