/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_str_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:19:08 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/27 20:25:24 by dpentlan         ###   ########.fr       */
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

	x = TEXT_ORIGIN_X + 0;
	y = TEXT_ORIGIN_Y + 10;
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
		snip_start += (snip_size + 1);
		y += 15;
	}
	return (0);
}

int	render_strings(t_master *master)
{
	printer(master, "\
###### FDF ######\n\
\n\
By Drew Pentland\n\
\n\
###### CONTROLS ######\n\
\n\
ESC             EXIT\n\
X               POS X AXIS ROTATION\n\
Y               POS Y AXIS ROTATION\n\
Z               POS Z AXIS ROTATION\n\
S               NEG X AXIS ROTATION\n\
A               NEG Y AXIS ROTATION\n\
T               NEG Z AXIS ROTATION\n\
UP ARROW        PAN UP\n\
DOWN ARROW      PAN DOWN\n\
LEFT ARROW      PAN LEFT\n\
RIGHT ARROW     PAN RIGHT\n\
PLUS            ZOOM IN (SMALL)\n\
MINUS           ZOOM OUT (SMALL)\n\
RIGHT ANG BRKT  ZOOM IN (LARGE)\n\
LEFT ANG BRKT   ZOOM OUT (LARGE)\n\
CLOSE SQ BRKT   INCREASE Z SCALE\n\
OPEN SQ BRKT    DECREASE Z SCALE\n\
P               ALTERNATE PROJECTION\n\
E               SET Z ANGLE TO ZERO\n\
1               INCREASE ALPHA ANGLE\n\
2               DECREASE ALPHA ANGLE\n\
R               RESET PROJECTION\n\
\n\
");
	return (0);
}
