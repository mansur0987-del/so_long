/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patrol_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:43:34 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/22 14:23:41 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	ft_put_patrol(t_prog *game, char **spl, t_image *pa)
{
	int	i;
	int	g;

	i = 0;
	while (spl[++i] != NULL)
	{
		g = 1;
		while (spl[i][g] && spl[i][g] != 'E')
			g++;
		if (spl[i][g] == 'E')
			break ;
	}
	if (spl[i - 1][g] == '0')
		i--;
	else if (spl[i][g + 1] == '0')
		g++;
	else if (spl[i + 1][g] == '0')
		i++;
	else
		g--;
	pa->ad_x = ((g + 1) * 16) - 16;
	pa->ad_y = ((i + 1) * 16) - 16;
	mlx_put_image_to_window(game->ptr, game->win->ptr, \
	pa->ptr, pa->ad_x, pa->ad_y);
}

void	ft_move_patrol(t_prog *game, char **spl, t_image *pa)
{
	int			new[4];
	static int	last;

	new[0] = pa->ad_y / 16;
	new[1] = pa->ad_x / 16;
	new[2] = pa->ad_y / 16;
	new[3] = pa->ad_x / 16;
	mlx_put_image_to_window(game->ptr, game->win->ptr, \
	game->ro->ptr, pa->ad_x, pa->ad_y);
	if (spl[new[0] - 1][new[1]] == '0' && !last)
		new[0]--;
	else if (spl[new[0]][new[1] + 1] == '0')
		new[1]++;
	else if (spl[new[0]][new[1] - 1] == '0' && !last)
		new[1]--;
	else if (spl[new[0] + 1][new[1]] == '0')
		new[0]++;
	if (new[1] > new[3] || new[0] > new[2])
		last = 1;
	else
		last = 0;
	pa->ad_x = ((new[1] + 1) * 16) - 16;
	pa->ad_y = ((new[0] + 1) * 16) - 16;
	mlx_put_image_to_window(game->ptr, game->win->ptr, \
	pa->ptr, pa->ad_x, pa->ad_y);
}
