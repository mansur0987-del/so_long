/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:00:55 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/22 14:23:26 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	ft_start(t_prog	*game)
{
	game->ptr = NULL;
	game->ptr = mlx_init();
	if (game->ptr == NULL)
		return (1);
	if (ft_create_window(game))
		return (ft_free_mlx(game, "Error in create window\n"));
	if (ft_create_location(game))
		return (ft_free_mlx(game, "Error in create location\n"));
	if (ft_move_pers(game))
		return (ft_free_mlx(game, "Error in moving\n"));
	mlx_loop (game->ptr);
	ft_free_mlx(game, NULL);
	return (0);
}
