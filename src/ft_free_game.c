/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:41:32 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/22 01:48:24 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_free_game(t_prog	*game, char *err_mes)
{
	int	i;

	i = game->lines - 1;
	while (i >= 0)
	{
		free(game->spl[i]);
		i--;
	}
	free(game->spl);
	free(game->map);
	free(game);
	if (err_mes != NULL)
		return (ft_error(err_mes));
	return (0);
}
