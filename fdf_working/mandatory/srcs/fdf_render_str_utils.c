/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_str_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:19:08 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/15 17:02:08 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	render_strings(t_master *master)
// {
//
// 	return (0);
// }
//
// int	render_strings(t_master *master)
// {
//
// 	return (0);
// }
//
// int	render_strings(t_master *master)
// {
//
// 	return (0);
// }
//
// int	render_strings(t_master *master)
// {
//
// 	return (0);
// }

int	render_strings(t_master *master)
{
	if (master) {}
	mlx_string_put(master->win.mlx_ptr, master->win.win_ptr, 0, 10,
				TEXT_COLOR, "Test String");
	return (0);
}
