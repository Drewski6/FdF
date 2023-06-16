/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:19:40 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/16 12:37:52 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_map(t_master *master)
{
	master->map.buf = 0;
	master->map.points = 0;
	master->map.pnts_copy = 0;
	master->map.map_size = 0;
	master->map.map_scale = 1;
	master->map.renders = 0;
	master->bitmap.bg_color = BG_COLOR;
	master->bitmap.menu_color = MENU_COLOR;
	master->map.center.x = ((WIN_X - WIN_MENU_WIDTH) / 2) + WIN_MENU_WIDTH;
	master->map.center.y = WIN_Y / 2;
	master->map.center.z = 0;
	return (0);
}

void	ft_free_tab(void *table)
{
	int		i;
	char	**tab;

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

int	map_buf_add(t_master *master, char **tab)
{
	t_list	*new_node;

	new_node = ft_lstnew((void *)tab);
	if (!new_node)
		error_fdf(master, "malloc");
	ft_lstadd_back(&(master->map.buf), new_node);
	return (0);
}

int	read_lines(t_master *master, int fd)
{
	int		n_lines;
	char	*st_line;
	char	**tab_line;
	char	*nl;

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

int	read_in_map(t_master *master, char *filename)
{
	int		fd;
	clock_t	start_time;

	if (DEBUG == 1)
		start_time = clock();
	fd = open(filename, O_RDONLY);
	if (fd < 2)
		error_fdf(master, "open");
	ft_printf("Reading in map file.\n");
	read_lines(master, fd);
	if (build_points_list(master))
		error_fdf(master, "malloc");
	ft_lstclear(&(master->map.buf), &ft_free_tab);
	close(fd);
	if (DEBUG == 1)
	{
		ft_printf("map read time:\t%d/%d s\n",
			clock() - start_time, CLOCKS_PER_SEC);
		ft_printf("map size:\t%d\n", master->map.map_size);
	}
	return (0);
}
