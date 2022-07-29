/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_location_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 21:20:04 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/22 14:23:04 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

static void	ft_came_image(t_prog *game, t_image *image, char *file_name)
{
	image->ptr = mlx_xpm_file_to_image(game->ptr, file_name, \
	&image->size.x, &image->size.y);
	image->pixels = mlx_get_data_addr(image->ptr, \
	&image->bits_per_pixel, &image->line_size, &image->endian);
}

static void	ft_put_image(t_prog *game, char **spl, t_image *image, char c)
{
	int	i;
	int	g;

	i = 0;
	image->how = 0;
	while (spl[i] != NULL)
	{
		g = -1;
		while (spl[i][++g])
		{
			if (spl[i][g] == c)
			{
				image->how++;
				image->ad_x = ((g + 1) * 16) - 16;
				image->ad_y = ((i + 1) * 16) - 16;
				mlx_put_image_to_window(game->ptr, game->win->ptr, \
				image->ptr, image->ad_x, image->ad_y);
			}
		}
		i++;
	}
}

static int	ft_null_image(t_prog *game)
{
	game->wa = NULL;
	game->ro = NULL;
	game->fi = NULL;
	game->co = NULL;
	game->pl = NULL;
	game->pl1 = NULL;
	game->pa = NULL;
	game->bl = NULL;
	game->wa = malloc(sizeof(t_image));
	game->ro = malloc(sizeof(t_image));
	game->fi = malloc(sizeof(t_image));
	game->co = malloc(sizeof(t_image));
	game->pl = malloc(sizeof(t_image));
	game->pl1 = malloc(sizeof(t_image));
	game->pa = malloc(sizeof(t_image));
	game->bl = malloc(sizeof(t_image));
	if (game->wa == NULL || game->ro == NULL || \
		game->fi == NULL || game->co == NULL || \
		game->pl == NULL || game->pl1 == NULL || \
		game->pa == NULL || game->bl == NULL)
		return (1);
	return (0);
}

static void	all_put_image(t_prog *game)
{
	ft_put_image(game, game->spl, game->wa, '1');
	ft_put_image(game, game->spl, game->ro, '0');
	ft_put_image(game, game->spl, game->fi, 'E');
	ft_put_image(game, game->spl, game->ro, 'C');
	ft_put_image(game, game->spl, game->ro, 'P');
	ft_put_image(game, game->spl, game->co, 'C');
	ft_put_image(game, game->spl, game->pl, 'P');
	ft_put_patrol(game, game->spl, game->pa);
}

int	ft_create_location(t_prog *game)
{
	if (ft_null_image(game))
		return (1);
	game->wa->ptr = NULL;
	game->ro->ptr = NULL;
	game->fi->ptr = NULL;
	game->co->ptr = NULL;
	game->pl->ptr = NULL;
	game->pl1->ptr = NULL;
	game->pa->ptr = NULL;
	game->bl->ptr = NULL;
	ft_came_image(game, game->wa, "xpm/wall.xpm");
	ft_came_image(game, game->ro, "xpm/road.xpm");
	ft_came_image(game, game->fi, "xpm/finish.xpm");
	ft_came_image(game, game->co, "xpm/coin.xpm");
	ft_came_image(game, game->pl, "xpm/player.xpm");
	ft_came_image(game, game->pl1, "xpm/player_1.xpm");
	ft_came_image(game, game->pa, "xpm/patrol.xpm");
	ft_came_image(game, game->bl, "xpm/black.xpm");
	if (game->wa->ptr == NULL || game->ro->ptr == NULL || \
		game->fi->ptr == NULL || game->co->ptr == NULL || \
		game->pl->ptr == NULL || game->pl1->ptr == NULL || \
		game->pa->ptr == NULL || game->bl->ptr == NULL)
		return (1);
	all_put_image(game);
	return (0);
}
