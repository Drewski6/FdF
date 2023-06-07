/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:19:40 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/07 14:57:02 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_tab(void *table)
{
	int	i;
    char    **tab;

	i = 0;
    tab = (char **)table;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

int map_buf_add(t_master *master, char **tab)
{
    t_list  *new_node;

    new_node = ft_lstnew((void *)tab);
    if (!new_node)
        error_fdf(master, "malloc");
    ft_lstadd_back(&(master->map.buf), new_node);
    return (0);
}

int read_lines(t_master *master, int fd)
{
    int     n_lines;
    char    *st_line;
    char    **tab_line;
    char    *nl;

    n_lines = 0;
    st_line = 0;
    tab_line = 0;
    while (n_lines < 1 || st_line)
    {
        st_line = get_next_line(fd, 0);
        if (!st_line)
            break ;
        nl = ft_strchr(st_line, '\n');
        if (nl)
            ft_memset(nl, 0, 1);
        tab_line = ft_split(st_line, ' ');
        if (!tab_line)
            error_fdf(master, "malloc");
        free(st_line);
        if (map_buf_add(master, tab_line))
            error_fdf(master, "malloc");
    }
    get_next_line(fd, 1);
    return (0);
}

int read_in_map(t_master *master, char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd < 2)
        error_fdf(master, "open");
    read_lines(master, fd);
    fdf_debug_print_read_in_file(master);
    //convert ll + tabs into ll of points.
    ft_lstclear(&(master->map.buf), &ft_free_tab);
    close(fd);
    return (0);
}
