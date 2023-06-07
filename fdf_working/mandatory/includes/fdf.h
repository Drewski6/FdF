/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:36:13 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/07 19:36:14 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../libft/includes/libft.h"
# include "mlx.h"
# include "mlx_int.h"

//  Window Param Macros
# define WIN_X 1000
# define WIN_Y 1000
# define WIN_NAME "My First Window"

//  Key Press Macros
# define ESC 65307
# define ENTER 65293

//  sub structs
typedef struct  s_map
{
    t_list      *buf;
    int         size_x;
    int         size_y;
    int         size_z;
}               t_map;

typedef struct  s_win
{
    void        *mlx_ptr;
    void        *win_ptr;
}               t_win;

//  master struct
typedef struct  s_master
{
    t_win       win;
    t_map       map;
}               t_master;

//  Function Declarations  //
//  fdf.c
//  int main(int argc, char **argv);

//  fdf_utils.c
int     error_fdf(t_master *master, char *message);
int     error_fdf_putstr(char *message);
void    close_program(t_master *master);

//  fdf_win_utils.c
int     key_press(int key, void *param);
int     init_win(t_master *master);
void    init_master(t_master* master);

//  fdf_map_utils.c
void	ft_free_tab(void *table);
int     map_buf_add(t_master *master, char **tab);
int     read_lines(t_master *master, int fd);
int     read_in_map(t_master *master, char *filename);

//  fdf_debug_utils.c
void    fdf_debug_print_read_in_file(t_master *master);

//  fdf_points_utils.c
int build_points_list(t_master *master);

#endif
