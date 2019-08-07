/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizulib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:35:01 by ivan              #+#    #+#             */
/*   Updated: 2019/08/07 22:05:15 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZULIB_H
# define VIZULIB_H

# define HEIGHT 1395
# define WIDTH 2560
# define LINE 20
# define COLOR 50
# define CON 1
# define VIZU "vizu"

# include <math.h>
# include "./libft/libft.h"
# include "./libmlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>

typedef struct			s_lem
{
	char				**s;
	struct s_room		**adj;
	int					ants;
	int					rooms_cnt;
	struct s_room		*begin;
	struct s_room		*end;
	int					path_count;
	struct s_path		**patharr;
	int					max_group_size;
	int					n;
	int					nb;
	int					oper;
}						t_lem;

typedef struct			s_room
{
	int					nb;
	char				*name;
	int					ant;
	int					x;
	int					y;
	int					link_count;
	int					visited;
	int					cor;
	int					color;
	struct s_room		*next;
	struct s_room		*prev;
	struct s_room		*self;
	unsigned int		dijkstra;
	struct s_room		*queue_next;
}						t_room;

typedef	struct			s_mlx
{
	void				*wind;
	void				*ptr;
	int					x_add;
	int					y_add;
	int					radius;
	int					blue;
	int					red;
	int					green;
	int					yellow;
	int					white;
	int					err;
	int					derr;
	float				l;
	int					right_mouse;
	int					left_mouse;
	int					mv;
	int					sl;
	int					fill;
	int					x;
	int					y;
	int					cor;
	int					cmnd;
	int					m;
	int					col;
	t_lem				*lem;
}						t_mlx;

typedef struct			s_split
{
	char				*name1;
	char				*name2;
	char				*name3;
	int					l;
	int					begin;
	int					end;
	struct s_split		*next;
	struct s_split		*prev;
	
}						t_split;

typedef	struct			s_queue
{
	t_room				*start;
	t_room				*end;
	int					size;
}						t_queue;

typedef struct			s_path
{
	int					len;
	t_room				*start;
	t_room				*end;
	struct s_path		*next;
	struct s_path		*prev;
	char				*intersection_arr;
}						t_path;

typedef struct			s_group
{
	int					size;
	int					sumlen;
	int					ants;
	t_path				**path_array;
	struct s_group		*next;//??maybe?
}						t_group;

void					resert_color(t_mlx *mlx);
void					give_color(t_mlx *mlx);
int						min(int a, int b);
void					print_path(t_path *path);
int						calc_max_group_size(t_lem *lem);
t_group					*create_group(t_path **patharr, int size);
int						check_link(t_room *src, t_room *dest);
t_path					*reverse_path(t_path *path);
void					fill_intersection_array(t_path *path, t_lem *lem);
t_group					*delete_intersecting_paths(t_group *group);
t_path					*create_path();
void					add_to_path(t_path *path, t_room *room);
int						is_intersect(t_path *path1, t_path *path2);
int						is_intersecting_n_paths(t_path **path_arr, int size);
void					add_to_priority_queue(t_room *room, t_queue *queue);
t_room					*pop_from_queue(t_queue *queue);
void					add_to_queue(t_room *room, t_queue *queue);
t_path					*dijkstra_search(t_lem *lem);
void					throw_error(char *msg);
int						rpf(t_room *room, t_lem *lem,
						t_path *path, t_path **pathlist);
int 					dublicates(t_split *tmp);
int						ret_null(t_split *tmp);
int						is_ants_at_finish(t_group *group);
void					make_prev_for_path(t_group *group, t_lem *lem);
t_split					*addlst(t_split *tmp, int l, int *t);
int						common_room(t_split *tmp, char **s, const int *t);
int						linker(t_split *tmp, char **s);
int						run_ants(t_group *group, t_lem *lem, int n);
void					switch_links(t_path *path, t_lem *lem);
void					add_group(t_group *group_list, t_lem *lem);
t_group					*find_best_group(t_group *group_list, t_lem *lem);
t_split					*ft_newsplit();
void					split_free(t_split *split);
void					putman(t_mlx *mlx);
int						key_release(int keycode, t_mlx *mlx);
void					graph_color(t_lem *lem, t_room *adj,
										t_mlx *mlx, int *col);
void					cloner(t_room *cl, t_room *adj, t_mlx *mlx);
void					visited(t_room *room, t_room *adj);
void					release_visited(t_room **adj);
void					fcircle(int x0, int y0, t_mlx *mlx, int colot);
int						mouse_release(int button, int x, int y, t_mlx *param);
int						mouse_move(int x, int y, t_mlx *param);
int						mouse_press(int button, int x, int y, t_mlx *param);
int						key_press(int keycode, t_mlx *param);
int						link_make(t_lem *lem, t_split *tmp);
void					free_lem(t_lem *lem);
void					free_adj(t_room **adj);
int						adj_list(t_lem *lem, t_split *split);
void					ft_triplefree(char ***s);
t_split					*ft_rec(char *s, t_lem *lem);
void					split_free(t_split *split);
int						link_make(t_lem *lem, t_split *tmp);
t_lem					*ft_newlem();
t_room					*ft_newroom();
void					mappaint(t_mlx *mlx);
void					circle(int x0, int y0, t_mlx *mlx, int color);
void					ft_bresenham(t_room *d0, t_room *d1, t_mlx *mlx);
void					run_window(t_mlx *mlx);
int						ft_close(void *param);
t_mlx					*ft_newmlx();

#endif
