/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_points_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:29:43 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/08 13:39:04 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int read_points_data(t_master *master)
{
    t_point *current;
    int     i;

    i = 0;
    current = master->map.points;
    while (current)
    {
        ft_printf("%d. x:%d y:%d z:%d\n", i, current->x, current->y, current->z);
        i++;
        current = current->next;
    }
    return (0);
}

int get_y_len(t_master *master)
{
    int     i;
    t_list  *current;

    i = 0;
    current = master->map.buf;
    while (current)
    {
        i++;
        current = current->next;
    }
    return (i);
}

int get_x_len(t_master *master)
{
    int i;

    i = 0;
    while (((char **)master->map.buf->content)[i])
        i++;
    return (i);
}

int build_points_list_loop(t_master *master)
{
    int     y;
    int     x;
    t_point  *points_current;
    t_list  *buf_current;

    y = 0;
    points_current = master->map.points;
    buf_current = master->map.buf;
    while (y < master->map.size_y)
    {
        x = 0;
        while (x < master->map.size_x)
        {
            points_current->x = x;
            points_current->y = y;
            points_current->z = ft_atoi(((char **)buf_current->content)[x]);
            if (y == master->map.size_y - 1 && x == master->map.size_x - 1)
                points_current->next = 0;
            else
                points_current->next = points_current + 1;
            points_current = points_current->next;
            x++;
        }
        buf_current = buf_current->next;
        y++;
    }
    return (0);
}

int build_points_list(t_master *master)
{
    master->map.size_x = 0;
    master->map.size_x = get_x_len(master);
    master->map.size_y = 0;
    master->map.size_y = get_y_len(master);
    master->map.points = (t_point *)ft_calloc(master->map.size_x * master->map.size_y, sizeof(t_point));
    if (!master->map.points)
        error_fdf(master, "malloc");
    build_points_list_loop(master);
    return (0);
}

