/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_str_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:19:08 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/15 17:42:34 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	printer_find_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	printer(t_master *master, char *str)
{
	int		x;
	int		y;
	int		snip_size;
	int		snip_start;
	char	*buf;

	x = PRINT_ORIGIN_X + 0;
	y = PRINT_ORIGIN_Y + 10;
	snip_start = 0;
	snip_size = 0;
	buf = 0;
	while (str[snip_start])
	{
		snip_size = printer_find_nl(&str[snip_start]);
		buf = ft_calloc(snip_size + 1, sizeof(char));
		if (!buf)
			error_fdf(master, "malloc");
		ft_memcpy(buf, &str[snip_start], snip_size);
		mlx_string_put(master->win.mlx_ptr, master->win.win_ptr, x, y,
				TEXT_COLOR, buf);
		free(buf);
		snip_start += ( snip_size + 1 );
		y += 15;
	}
	return (0);
}

int	render_strings(t_master *master)
{
	printer(master, "##### FDF #####\n\
By Drew Pentland\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
Hello after a few lines.");
	return (0);
}

