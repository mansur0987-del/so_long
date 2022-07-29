/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:35:02 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/22 10:58:51 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_free_image(t_prog *game, t_image *image)
{
	if (image == NULL)
		return ;
	mlx_destroy_image(game->ptr, image->ptr);
	free(image);
}

int	ft_free_mlx(t_prog *game, char *err_mes)
{
	ft_free_image(game, game->fi);
	ft_free_image(game, game->pa);
	ft_free_image(game, game->pl1);
	ft_free_image(game, game->pl);
	ft_free_image(game, game->ro);
	ft_free_image(game, game->wa);
	ft_free_image(game, game->bl);
	ft_free_image(game, game->co);
	if (game->win->ptr != NULL)
		mlx_destroy_window(game->ptr, game->win->ptr);
	if (game->win != NULL)
		free(game->win);
	ft_free_game(game, err_mes);
	return (1);
}
