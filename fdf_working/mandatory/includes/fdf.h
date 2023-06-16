/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:36:13 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/16 12:32:23 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define DEBUG 1

# include "../../libft/includes/libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <time.h>

//	Define Colors
# define GREEN			0x66ff33

# define TEXT_COLOR		0xFFFFFF
# define BG_COLOR		0x000033
# define MENU_COLOR		0x663300

//	Window Param Macros
# define WIN_X			1920
# define WIN_Y			1080
# define WIN_MENU_WIDTH	400
# define WIN_NAME		"FdF *dpentlan*"
# define PRINT_ORIGIN_X	100
# define PRINT_ORIGIN_Y	100
# define MAP_MARGIN		100

//	Key Press Macros
# define ESC			65307
# define ENTER			65293

//	Sub Structs
typedef struct s_point
{
	float			x;
	float			y;
	float			z;
	struct s_point	*next;
}					t_point;

typedef struct s_map
{
	t_list		*buf;
	t_point		*points;
	t_point		*pnts_copy;
	t_point		center;
	int			size_x;
	int			size_y;
	int			size_z;
	int			map_size;
	float		map_scale;
	int			renders;
}				t_map;

typedef struct s_bitmap
{
	void		*img_ptr;
	char		*img_buf;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			bg_color;
	int			menu_color;
}				t_bitmap;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_win;

//  master struct
typedef struct s_master
{
	t_win		win;
	t_map		map;
	t_bitmap	bitmap;
}				t_master;

//  Function Declarations  //
//  fdf.c
//  int main(int argc, char **argv);

//  fdf_utils.c
int		error_fdf(t_master *master, char *message);
int		error_fdf_putstr(char *message);
void	close_program(t_master *master);

//  fdf_win_utils.c
int		mouse_usage(int button, int x, int y, void *param);
int		key_press(int key, void *param);
int		init_win(t_master *master);

//  fdf_map_utils.c
int		init_map(t_master *master);
void	ft_free_tab(void *table);
int		map_buf_add(t_master *master, char **tab);
int		read_lines(t_master *master, int fd);
int		read_in_map(t_master *master, char *filename);

//  fdf_points_utils.c
int		points_largest_z(t_master *master);
int		get_y_len(t_master *master);
int		get_x_len(t_master *master);
int		build_points_list_loop(t_master *master);
int		build_points_list(t_master *master);

//	fdf_render_utils.c
int		get_local_color(t_master *master, int color);
int		render_background(t_master *master);
int		render_map(t_master *master);

//	fdf_render_str_utils.c
int		printer_find_nl(char *str);
int		printer(t_master *master, char *str);
int		render_strings(t_master *master);

//	fdf_render_line_utils.c
int		render_lines(t_master *master);

//	fdf_img_utils.c
int		set_px_color_img_buf(t_master *master, int color, int x, int y);
int		init_img_buffer(t_master *master, int img_size_x, int img_size_y);

//  fdf_debug_utils.c
void	fdf_debug_print_read_in_file(t_master *master);
int		fdf_debug_read_points_data(t_master *master);

#endif
