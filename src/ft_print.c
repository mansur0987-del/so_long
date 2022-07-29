/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:46:00 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/19 20:48:20 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_putchar_len(int fd, char c)
{
	write (fd, &c, 1);
	return (1);
}

size_t	ft_putstr_len(int fd, char	*str)
{
	size_t	i;
	char	*tmp;

	tmp = str;
	i = 0;
	if (!tmp || tmp == NULL)
	{
		i += ft_putstr_len(fd, "(null)");
		return (i);
	}
	while (tmp[i] != '\0')
	{
		ft_putchar_len(fd, tmp[i]);
		i++;
	}
	return (i);
}

size_t	ft_strlen(char	*str)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = str;
	while (tmp != NULL && tmp[i] != '\0')
		i++;
	return (i);
}

size_t	ft_putnbr_len(int n)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
	{
		len += ft_putstr_len(1, "-2147483648");
		return (len);
	}
	if (n < 0)
	{
		n = -n;
		len += ft_putchar_len(1, '-');
	}
	while (n >= 10)
	{
		len += ft_putnbr_len(n / 10);
		break ;
	}
	len += ft_putchar_len(1, n % 10 + '0');
	return (len);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	g;

	i = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (len > i && haystack[i] != '\0')
	{
		g = 0;
		while (needle[g] && needle[g] == haystack[i + g] && i + g < len)
			g++;
		if (needle[g] == '\0')
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
