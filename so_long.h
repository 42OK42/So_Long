/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okrahl <okrahl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:55:14 by okrahl            #+#    #+#             */
/*   Updated: 2023/10/12 15:52:24 by okrahl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_data {
	void	*img_wall;
	void	*img_background;
	void	*img_player;
	void	*img_end;
	void	*img_collectible;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*mlx_win;
	char	**map_array;
	int		last_collum;
	int		current_coin_count;
	int		final_coin_count;
	int		move_count;
	char	*filename;
	int		map_height;
	int		collum_length;
	int		successful;
	char	*relative_path_wall;
	char	*relative_path_player;
	char	*relative_path_end;
	char	*relative_path_collectible;
	char	*relative_path_background;
}			t_data;

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*allocate_memory2(size_t total_length);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_line(char	*read);
char	*ft_next(char	*read);
char	*ft_read(int fd, char *result);
char	*ft_free(char *read, char *buffer);
int		c_checks(t_data	*data);
void	ft_free_map(char **map_array);
int		direction_checker(t_data *data, int x, int y);
char	*ft_strdup(const char *s);
int		solveable(t_data *data, int x, int y, int	*finish_cor);
int		find_start_x(char **map_array, int map_height, char goal);
int		find_start_y(char **map_array, int map_height, char goal);
void	print_map(char	**map_array);
int		map_height1(char *filename);
char	**map_read(t_data *data);
int		find_last(char	**map_array);
int		wall_check(char	**map_array, int last_row, int collum_length);
int		find_map_length(char	**map_array);
int		count_in_map(char	**map_array, char c);
int		rectangular_check(char **map_array, int collum_length, int last_row);
int		**get_c_pos(char **map_array, int **c_pos, int count_c, int map_height);
int		valid_characters(char **map_array, int last_row);
int		error_check4(t_data	*data);
int		c_checks(t_data*data);
int		error_check3(t_data	*data);
int		error_check2(t_data	*data);
int		error_check(t_data	*data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	*open_window(void	*mlx, int last_collum, char	**map_array);
t_data	get_images(void	*mlx, t_data *data);
void	destroy_map(t_data	*data, char **map_array, int map_height);
int		close_window(void	*param);
void	put_images(t_data *data);
int		move_possible(t_data	*data, int x, int y);
void	move_player_left(t_data *data, int x, int y);
void	move_player_right(t_data *data, int x, int y);
void	move_player_up(t_data *data, int x, int y);
void	move_player_down(t_data *data, int x, int y);
void	update_player_position(t_data *data, char c);
int		on_press(int keycode, t_data *data);
int		solveable_utils(int x, int y, int *finish_cor);
void	put_images_on_window(t_data *data, int x, int y);
void	free_c_pos(t_data	*data, int **c_pos);

#endif
