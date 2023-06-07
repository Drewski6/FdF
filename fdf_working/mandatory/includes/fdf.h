/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:36:13 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/07 10:42:05 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../libft/includes/libft.h"
# include "mlx.h"
# include "mlx_int.h"

// Window Param Macros
# define WIN_X 1000
# define WIN_Y 1000
# define WIN_NAME "My First Window"

// Key Press Macros
# define ESC 65307
# define ENTER 65293

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

//  fdf_utils.c
int     error_fdf(t_master *master, char *message);
int     error_fdf_putstr(char *message);
void    close_program(t_master *master);

//  fdf_win_utils.c
int     key_press(int key, void *param);
int     init_win(t_master *master);

//  fdf_map_utils.c
int     read_in_map(t_master *master, char *filename);

#endif
