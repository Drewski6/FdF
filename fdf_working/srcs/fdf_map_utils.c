/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:19:40 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/21 12:59:56 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_map(t_master *master)
{
	init_max_min(master);
	master->map.buf = 0;
	master->map.points = 0;
	master->map.pnts_copy = 0;
	master->map.map_size = 0;
	master->map.map_scale = 1.0;
	master->map.renders = 0;
	master->bitmap.bg_color = BG_COLOR;
	master->bitmap.menu_color = MENU_COLOR;
	master->map.center.x = ((WIN_X - WIN_MENU_WIDTH) / 2) + WIN_MENU_WIDTH;
	master->map.center.y = WIN_Y / 2;
	master->map.center.z = 1;
	master->map.origin.x = 0;
	master->map.origin.y = 0;
	master->map.origin.z = 0;
	master->map.x_rot = 0;
	master->map.y_rot = 0;
	master->map.z_rot = 0;
	master->map.offset.x = 0;
	master->map.offset.y = 0;
	master->map.offset.z = 0;
	master->map.z_scale = 1;
	return (0);
}

int	init_max_min(t_master *master)
{
	master->max_min.x_max = 0;
	master->max_min.y_max = 0;
	master->max_min.z_max = 0;
	master->max_min.x_min = 0;
	master->max_min.y_min = 0;
	master->max_min.z_min = 0;
	return (0);
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

	fd = open(filename, O_RDONLY);
	if (fd < 2)
		error_fdf(master, "open");
	ft_printf("Reading in map file.\n");
	read_lines(master, fd);
	if (build_points_list(master))
		error_fdf(master, "malloc");
	ft_lstclear(&(master->map.buf), &ft_free_tab);
	close(fd);
	return (0);
}
