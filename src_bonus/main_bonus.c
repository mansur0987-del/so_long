/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:45:26 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/22 14:23:57 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

static void	ft_open_close(t_prog *game, char *str)
{
	int	fd;

	game->map = NULL;
	fd = open(str, O_RDONLY);
	if (fd < 1)
		return ;
	game->map = ft_reading(fd);
	close (fd);
}

int	main(int argc, char **argv)
{
	t_prog	*game;

	if (argc < 2)
		return (ft_error("Not argument to read\n"));
	if (ft_strlen(argv[1]) <= 4 || !(ft_strnstr(argv[1], \
		".ber", ft_strlen(argv[1]))))
		return (ft_error("File must be in .ber format\n"));
	game = malloc(sizeof(t_prog));
	if (game == NULL)
		return (ft_error("Not memory for game\n"));
	ft_open_close(game, argv[1]);
	if (game->map == NULL)
		return (ft_error("Problem in open or read file\n"));
	ft_check_map(game);
	if (game->error == 1)
		return (ft_free_game(game, "Map is not valid\n"));
	ft_start(game);
	return (0);
}
