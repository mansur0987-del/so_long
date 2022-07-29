/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:35:15 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/22 14:22:40 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

static void	ft_putchar_move(t_prog *game, int x, int y)
{
	if (y == -1)
		mlx_string_put(game->ptr, game->win->ptr, 8, \
		game->win->y + 10, 0x0000FF00, "move up");
	if (y == 1)
		mlx_string_put(game->ptr, game->win->ptr, 8, \
		game->win->y + 10, 0x0000FF00, "move down");
	if (x == -1)
		mlx_string_put(game->ptr, game->win->ptr, 8, \
		game->win->y + 10, 0x0000FF00, "move left");
	if (x == 1)
		mlx_string_put(game->ptr, game->win->ptr, 8, \
		game->win->y + 10, 0x0000FF00, "move right");
}

static void	ft_change_skin(t_prog *game, t_image *player)
{
	static int	g;

	g += 1;
	if (g % 2)
		mlx_put_image_to_window(game->ptr, game->win->ptr, \
		game->pl1->ptr, player->ad_x, player->ad_y);
	else
		mlx_put_image_to_window(game->ptr, game->win->ptr, \
		game->pl->ptr, player->ad_x, player->ad_y);
}

static int	ft_move(t_prog *game, t_image *pl, int y, int x)
{
	static int	coin;

	if ((game->spl[pl->ad_y / 16][pl->ad_x / 16] == 'E' && \
	coin == game->co->how) || \
	game->spl[pl->ad_y / 16 + y][pl->ad_x / 16 + x] == '1' || \
	(pl->ad_y == game->pa->ad_y && pl->ad_x == game->pa->ad_x))
		return (0);
	ft_putchar_move(game, x, y);
	if (game->spl[pl->ad_y / 16][pl->ad_x / 16] == 'C')
	{
		game->spl[pl->ad_y / 16][pl->ad_x / 16] = '0';
		coin++;
	}
	mlx_put_image_to_window(game->ptr, game->win->ptr, \
	game->ro->ptr, pl->ad_x, pl->ad_y);
	if (game->spl[pl->ad_y / 16][pl->ad_x / 16] == 'E')
		mlx_put_image_to_window(game->ptr, game->win->ptr, \
		game->fi->ptr, pl->ad_x, pl->ad_y);
	pl->ad_y = pl->ad_y + 16 * y;
	pl->ad_x = pl->ad_x + 16 * x;
	if (pl->ad_y == game->pa->ad_y && pl->ad_x == game->pa->ad_x)
		return (0);
	ft_move_patrol(game, game->spl, game->pa);
	ft_change_skin(game, pl);
	return (1);
}

static int	ft_check_key(int key, t_prog *game)
{
	static int	move;

	if (key == 53)
		ft_close(53, game);
	mlx_put_image_to_window(game->ptr, game->win->ptr, \
	game->bl->ptr, 5, game->win->y);
	if (key == 13)
		move += ft_move(game, game->pl, -1, 0);
	if (key == 1)
		move += ft_move(game, game->pl, 1, 0);
	if (key == 0)
		move += ft_move(game, game->pl, 0, -1);
	if (key == 2)
		move += ft_move(game, game->pl, 0, 1);
	ft_putstr_len(1, "move = ");
	ft_putnbr_len(move);
	ft_putstr_len(1, "\n");
	return (0);
}

int	ft_move_pers(t_prog *game)
{
	mlx_key_hook(game->win->ptr, *ft_check_key, game);
	return (0);
}
