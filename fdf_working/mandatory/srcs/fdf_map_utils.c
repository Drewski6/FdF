/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:19:40 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/06 23:30:41 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int read_in_map(t_master *master, char *filename)
{
    int fd;

    if (master) {}
    fd = open(filename, O_RDONLY);
    if (fd < 2)
        error_fdf(master, "open");
    close(fd);
    return (0);
}
