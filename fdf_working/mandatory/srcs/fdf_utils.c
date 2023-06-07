/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:17:43 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/07 10:48:29 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int error_fdf(t_master *master, char *message)
{
    if (master->win.win_ptr)
    {
        mlx_destroy_window(master->win.mlx_ptr, master->win.win_ptr);
        master->win.win_ptr = 0;
    }
    if (master->win.mlx_ptr)
    {
        mlx_destroy_display(master->win.mlx_ptr);
        free(master->win.mlx_ptr);
        master->win.mlx_ptr = 0;
    }
    if (message)
        perror(message);
    exit(EXIT_FAILURE);
}

/*  
**  Does not free anything. Only use this error for cases where you want to display a special message and quit immediately. (ie. args).
**  
**/

int error_fdf_putstr(char *message)
{
    ft_putstr_fd(message, 2);
    exit(EXIT_FAILURE);
}

void    close_program(t_master *master)
{
    mlx_destroy_window(master->win.mlx_ptr, master->win.win_ptr);
    mlx_destroy_display(master->win.mlx_ptr);
    free(master->win.mlx_ptr);
    //  free map
    exit(0);
}

