/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_win_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:50:04 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/06 17:15:02 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int error_fdf(t_master *master)
{
    if (master) {}  // get rid of this
    // add a perror
    exit(EXIT_FAILURE);
}

int deal_key(int key, void *param)
{
    t_master    *master;

    master = (t_master *)param;
    if (key == 65307)
    {
        mlx_destroy_window(master->win.mlx_ptr, master->win.win_ptr);
        error_fdf(master);
    }
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

/*  
**  initialize window. Dont forget to modify error returns, These should cause program to stop. 
**  
**/

int init_win(t_master *master)
{
    master->win.mlx_ptr = 0;
    master->win.win_ptr = 0;

    master->win.mlx_ptr = mlx_init();
    if (!master->win.mlx_ptr)
        error_fdf(master);
    master->win.win_ptr = mlx_new_window(master->win.mlx_ptr, 1000, 1000, "My First Window");
    if (!master->win.win_ptr)
        error_fdf(master);
    return (0);
}
