/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_points_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:25:50 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/20 22:58:41 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	build_points_get_y_len(t_master *master)
{
	int		i;
	t_list	*current;

	i = 0;
	current = master->map.buf;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	build_points_get_x_len(t_master *master)
{
	int	i;

	i = 0;
	while (((char **)master->map.buf->content)[i])
		i++;
	return (i);
}

int	build_points_set_origin(t_master *master)
{
	master->map.origin.x = (float)master->map.size_x / 2;
	master->map.origin.y = (float)master->map.size_y / 2;
	master->map.origin.z = (float)master->map.size_z / 2;
	return (0);
}
