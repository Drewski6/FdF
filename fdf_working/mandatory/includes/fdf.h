/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:36:13 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/06 17:07:24 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../../libft/includes/libft.h"
#include "mlx.h"
#include "mlx_int.h"

typedef struct  s_win
{
    void        *mlx_ptr;
    void        *win_ptr;
}               t_win;

typedef struct  s_master
{
    t_win       win;
}               t_master;

//  fdf.c
//  int main(void);

//  fdf_win_utils.c
int error_fdf(t_master *master);
int close_win(void *param);
int init_win(t_master *master);
int deal_key(int key, void *param);

#endif
