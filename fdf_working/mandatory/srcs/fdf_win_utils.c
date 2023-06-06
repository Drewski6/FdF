/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_win_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:50:04 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/06 23:31:37 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_press(int key, void *param)
{
    t_master    *master;

    master = (t_master *)param;
    if (key == ESC)
        close_program(master);
    if (key == ENTER)
        ft_printf("You did it!!\n");
    ft_printf("%d\n", key);
    return (0);
}

int close_win(void *param)
{
    t_master *master;

    master = (t_master *)param;
    mlx_destroy_window(master->win.mlx_ptr, master->win.win_ptr);
    return (0);
}

int init_win(t_master *master)
{
    master->win.mlx_ptr = 0;
    master->win.win_ptr = 0;

    master->win.mlx_ptr = mlx_init();
    if (!master->win.mlx_ptr)
        error_fdf(master, "mlx_init");
    master->win.win_ptr = mlx_new_window(master->win.mlx_ptr, 1000, 1000, "My First Window");
    if (!master->win.win_ptr)
        error_fdf(master, "mlx_new_window");
    return (0);
}
