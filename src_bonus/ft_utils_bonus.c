/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:12:07 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/22 14:23:54 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	long	len_s1;
	long	len_s2;
	char	*output;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	output = (char *) malloc (sizeof(char) * (len_s1 + len_s2) + 1);
	if (output == NULL)
	{
		free (s1);
		return (NULL);
	}
	len_s2 = -1;
	while (s1 != NULL && s1[++len_s2] != '\0')
		output[len_s2] = s1[len_s2];
	len_s2 = 0;
	while (s2[len_s2] != '\0')
		output[len_s1++] = s2[len_s2++];
	output[len_s1] = '\0';
	free (s1);
	return (output);
}

char	*ft_reading(int fd)
{
	char	str[2];
	char	*last;
	int		ret;

	if (fd <= 0)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, str, BUFFER_SIZE);
		if (ret < 0)
		{
			free(last);
			free(str);
			return (NULL);
		}
		str[ret] = '\0';
		if (ret != 0 && str[0] != '\0')
			last = ft_strjoin(last, str);
	}
	return (last);
}

int	ft_split_map(t_prog *game)
{
	int	i;
	int	error;

	game->spl = ft_split(game->map, '\n');
	if (game->spl == NULL)
	{
		game->error = 1;
		return (0);
	}
	i = 0;
	error = 0;
	game->columns = ft_strlen(game->spl[i]);
	while (game->spl[i] != NULL)
	{
		if ((int)ft_strlen(game->spl[i]) != game->columns)
			game->error = 1;
		i++;
	}
	game->lines = i;
	if (game->error == 1)
		return (0);
	return (1);
}
