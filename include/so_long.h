/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:43:25 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/22 15:28:45 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx_opengl_20191021/mlx.h"

typedef struct s_size
{
	int		x;
	int		y;
}			t_size;

typedef struct s_wind
{
	void	*ptr;
	int		x;
	int		y;
}			t_wind;

typedef struct s_image
{
	void	*ptr;
	t_size	size;
	int		ad_x;
	int		ad_y;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	int		how;
}			t_image;

typedef struct s_prog
{
	char	*map;
	int		lines;
	int		columns;
	int		error;
	char	**spl;
	void	*ptr;
	t_wind	*win;
	t_image	*wa;
	t_image	*ro;
	t_image	*fi;
	t_image	*co;
	t_image	*pl;
	t_image	*pl1;
	t_image	*pa;
	t_image	*bl;
}			t_prog;

size_t	ft_putchar_len(int fd, char c);
size_t	ft_putstr_len(int fd, char	*str);
size_t	ft_strlen(char	*str);
size_t	ft_putnbr_len(int n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_reading(int fd);
int		ft_split_map(t_prog	*game);
void	ft_check_map(t_prog	*game);
char	**ft_split(char const *s, char c);
int		ft_start(t_prog	*game);
int		ft_create_window(t_prog	*game);
int		ft_create_location(t_prog *game);
int		ft_free_mlx(t_prog *game, char *err_mes);
int		ft_close(int key, t_prog *game);
int		ft_move_pers(t_prog *game);
int		ft_error(char *str);
int		ft_free_game(t_prog	*game, char *err_mes);
void	ft_put_patrol(t_prog *game, char **spl, t_image *pa);
void	ft_move_patrol(t_prog *game, char **spl, t_image *pa);

#endif
