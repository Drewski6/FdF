/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_debug_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:39:38 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/07 14:58:17 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    fdf_debug_print_read_in_file(t_master *master)
{
    t_list  *current;
    int     i;

    ft_printf("Size of master is %d\n", sizeof(t_master));
    current = master->map.buf;
    while (current)
    {
        i = 0;
        while(((char **)current->content)[i])
        {
            ft_printf("%s ", ((char **)current->content)[i]);
            i++;
        }
        ft_printf("\n");
        current = current->next;
    }
}
