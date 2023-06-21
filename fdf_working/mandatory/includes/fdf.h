/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:36:13 by dpentlan          #+#    #+#             */
/*   Updated: 2023/06/21 11:53:48 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define DEBUG 1

# include "../../libft/includes/libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <time.h>
# include <math.h>

//	Define Colors
# define WHITE			0xFFFFFF
# define BLACK			0x000000
# define GREEN			0x66ff33
# define NAVY			0x000033
# define BROWN			0x663300

# define TEXT_COLOR		WHITE
# define BG_COLOR		NAVY
# define MENU_COLOR		BROWN
# define L_BASE_C		WHITE
# define L_TOP_C		GREEN

//	Window Param Macros
# define WIN_X			1920
# define WIN_Y			1080
# define WIN_MENU_WIDTH	400
# define WIN_NAME		"FdF *dpentlan*"
# define TEXT_ORIGIN_X	100
# define TEXT_ORIGIN_Y	100
# define MAP_MARGIN		100

//	Key Press Macros
# define ESC			65307
# define ENTER			65293
# define L_ARROW		65361
# define U_ARROW		65362
# define R_ARROW		65363
# define D_ARROW		65364
# define X_KEY			120
# define Y_KEY			121
# define Z_KEY			119
# define PLUS_KEY		61
# define MINUS_KEY		41
# define R_KEY			114

//	Sub Structs
typedef struct s_point
{
	float			x;
	float			y;
	float			z;
	int				x_coord;
	int				y_coord;
	int				color;
	struct s_point	*next;
}					t_point;

typedef struct s_max_min
{
	float			x_max;
	float			y_max;
	float			z_max;
	float			x_min;
	float			y_min;
	float			z_min;
}				t_max_min;

typedef struct s_map
{
	t_list		*buf;
	t_point		*points;
	t_point		*pnts_copy;
	t_point		center;
	t_point		origin;
	t_point		offset;
	int			size_x;
	int			size_y;
	int			size_z;
	int			map_size;
	float		map_scale;
	float		map_scale_default;
	int			renders;
	float		x_rot;
	float		y_rot;
	float		z_rot;
	float		z_scale;
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
	t_max_min	max_min;
}				t_master;

//  Function Declarations  //
//  fdf.c
//  int main(int argc, char **argv);

//  fdf_utils.c
int		error_fdf(t_master *master, char *message);
int		error_fdf_putstr(char *message);
void	close_program(t_master *master);
void	ft_free_tab(void *table);

//  fdf_win_utils.c
int		mouse_usage(int button, int x, int y, void *param);
int		manipulation_control(t_master *master, int key);
int		key_press(int key, void *param);
int		reset_projection(t_master *master);
int		init_win(t_master *master);

//  fdf_map_utils.c
int		init_map(t_master *master);
int		init_max_min(t_master *master);
int		map_buf_add(t_master *master, char **tab);
int		read_lines(t_master *master, int fd);
int		read_in_map(t_master *master, char *filename);

//  fdf_points_utils_1.c
int		build_points_largest_z(t_master *master);
int		build_points_set_x_y(t_point *points_current, int x, int y);
int		build_points_list_loop(t_master *master);
int		build_points_list(t_master *master);

//  fdf_points_utils_2.c
int		build_points_get_y_len(t_master *master);
int		build_points_get_x_len(t_master *master);
int		build_points_set_origin(t_master *master);

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

//	fdf_la_funcs_1.c
int		la_scale(t_master *master, int updn);
int		la_translation(t_master *master, t_point *translate, int add);
int		la_z_height(t_master *master, float divisor);
int		manipulate_points(t_master *master);

//	fdf_la_funcs_2.c
int		la_matrix_init(float rot_mtx[3][3]);
void	la_matrix_mult(float rot_mtx[3][3], t_point *point);
int		la_x_rot(t_master *master, float ang_deg);
int		la_y_rot(t_master *master, float ang_deg);
int		la_z_rot(t_master *master, float ang_deg);

//	fdf_draw_lines_to_buf_1.c
int		map_fits(t_master *master);
int		fit_map_to_screen(t_master *master);
// int		cmp_max_min(t_point *current, float *max_min);
// int		refresh_max_min(t_master *master);
int		draw_lines(t_master *master);

//	fdf_draw_lines_to_buf_2.c
int		pixel_in_bounds(t_point *point);
int		pixel_put(t_master *master, int color, int x, int y);
int		bresenhams_line(t_master *master, t_point from, t_point *to);
int		draw_lines_for_point(t_master *master, int i);

//	fdf_draw_lines_to_buf_3.c
int		iterate_over_points(t_master *master);

//  fdf_debug_utils.c
void	fdf_debug_print_read_in_file(t_master *master);
int		fdf_debug_read_points_data(t_master *master);
void	p(t_point *point);
void	pa(t_master *master);

#endif
