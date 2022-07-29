/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:11:26 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/21 20:36:16 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_create_window(t_prog *game)
{
	t_wind	*wind;

	wind = NULL;
	wind = malloc(sizeof(game->win));
	wind->ptr = NULL;
	wind->ptr = mlx_new_window(game->ptr, game->columns * 16, \
	game->lines * 16 + 16, "so_long");
	if (wind->ptr == NULL)
		return (1);
	wind->x = game->columns * 16;
	wind->y = game->lines * 16;
	game->win = wind;
	mlx_hook(game->win->ptr, 17, 0, ft_close, game);
	return (0);
}
