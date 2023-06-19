/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_points_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:25:50 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/19 13:26:58 by dpentlan         ###   ########.fr       */
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
