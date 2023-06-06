/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:17:43 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/06 23:33:01 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int error_fdf(t_master *master, char *message)
{
    if (master) {}  // get rid of this
    if (message)
        perror(message);
    exit(EXIT_FAILURE);
}

void    close_program(t_master *master)
{
    mlx_destroy_window(master->win.mlx_ptr, master->win.win_ptr);
    error_fdf(master, NULL);
}

