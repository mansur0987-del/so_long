/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:45:48 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/22 14:22:58 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

static int	ft_check_line_1(t_prog	*game)
{
	int	i;

	if (game->lines < 3 || game->columns < 3 || \
	game->lines * game->columns < 16)
		game->error = 1;
	if (game->error == 1)
		return (0);
	i = 0;
	while (game->spl[0][i] == '1')
		i++;
	if (game->spl[0][i] != '\0')
		game->error = 1;
	i = 0;
	while (game->spl[(game->lines) - 1][i] == '1')
		i++;
	if (game->spl[0][i] != '\0')
		game->error = 1;
	if (game->error == 1)
		return (0);
	return (1);
}

static int	ft_check_simbol_1(char *map)
{
	unsigned int	i;
	char			flag[4];

	i = 0;
	while (map[i] && (map[i] == '1' || map[i] == '0' || map[i] == 'E' || \
		map[i] == 'C' || map[i] == 'P' || map[i] == '\n'))
	{
		if (map[i] == '0')
			flag[0] = '1';
		if (map[i] == 'E')
			flag[1] = '1';
		if (map[i] == 'C')
			flag[2] = '1';
		if (map[i++] == 'P')
			flag[3] = '1';
	}
	if (map[i] != '\0')
		return (1);
	i = 0;
	while (flag[i] && flag[i] == '1')
		i++;
	if (i != 4)
		return (1);
	return (0);
}

static int	ft_check_simbol_2(char *map)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (map[i])
	{
		if (map[i++] == 'P')
			p++;
	}
	if (p > 1)
		return (1);
	return (0);
}

static int	ft_check_line_2(t_prog	*game)
{
	int	i;

	i = 0;
	while (i < game->lines && game->spl[i][0] == '1' && \
	game->spl[i][(game->columns) - 1] == '1')
		i++;
	if (i != game->lines)
		i = 1;
	if (i != 1)
		i = ft_check_simbol_1(game->map);
	if (i != 1)
		i = ft_check_simbol_2(game->map);
	if (i == 1)
	{
		game->error = 1;
		return (0);
	}
	return (1);
}

void	ft_check_map(t_prog *game)
{
	game->error = 0;
	if (game->map == NULL)
	{
		game->error = 1;
		return ;
	}
	if (!ft_split_map(game))
		return ;
	if (!ft_check_line_1(game))
		return ;
	if (!ft_check_line_2(game))
		return ;
	return ;
}
