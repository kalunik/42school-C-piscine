/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_key_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjonatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 13:59:37 by wjonatho          #+#    #+#             */
/*   Updated: 2021/02/07 20:22:08 by wjonatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_map(char *str, int lenght)
{
	int		i;
	char	*array;

	array = malloc(sizeof(*str) * (lenght + 1));
	i = 0;
	while (i < lenght)
	{
		array[i] = str[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

int		ft_is_space(char d)
{
	if (d == '\t' || d == '\v' || d == '\f' || d == '\r' || d == ' ')
		return (1);
	else
		return (0);
}

int		ft_is_digit(char d)
{
	if ('0' <= d && d <= '9')
		return (1);
	else
		return (0);
}

char	*ft_clean_key(char *str, char *(*f)(char*, int length))
{
	int		i;
	int		count_digit;
	char	*res;

	i = 0;
	count_digit = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_is_digit(str[i]))
	{
		write(2, "Dict Error\n", 11);
		return (NULL);
	}
	while (ft_is_digit(str[i++]))
		count_digit++;
	i -= 1 + count_digit;
	res = ft_map(&str[i], count_digit);
	free(str);
	return (res);
}

char	*ft_clean_value(char *str, int length, char *(*f)(char *, int length))
{
	int		i;
	char	*res;

	i = 0;
	while (ft_is_space(str[i]))
		i++;
	if (i == length)
	{
		write(2, "Dict Error\n", 11);
		return (NULL);
	}
	while (ft_is_space(str[length - 1]))
		length--;
	printf("%d\n", length);
	res = ft_map(&str[i], length - i);
	free(str);
	return (res);
}
