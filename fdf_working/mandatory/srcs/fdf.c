/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:34:37 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/06 23:32:36 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main (int argc, char **argv)
{
    t_master   master;

    if (argv) {} // get rid of this
    if (argc != 2)
        error_fdf(&master, "args");
    // 
    init_win(&master);
    if (read_in_map(argv[1]))
        error_fdf(&master, "read_in_map");
    mlx_key_hook(master.win.win_ptr, &key_press, (void *)&master);
    mlx_loop(master.win.mlx_ptr);
    return (0);
}

