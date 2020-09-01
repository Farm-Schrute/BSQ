/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 13:07:56 by thallard          #+#    #+#             */
/*   Updated: 2020/08/31 18:33:29 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

int		ft_is_printable(char c)
{
	if (c <= 31 || c == 127)
		return (0);
	return (1);
}

int		ft_check_double(char *buf, int s)
{
	if (buf[s - 1] == buf[s - 2] || buf[s - 1] == buf[s - 3] ||
			buf[s - 2] == buf[s - 3])
		return (0);
	if (buf[s] != '\n')
		return (0);
	return (1);
}

int		ft_get_end_of_line(char *buf, int start, int nb_lines)
{
	long	i;
	long	j;

	i = 0;
	j = start;
	while (buf[start] != '\n' && buf[start])
	{
		i++;
		start++;
	}
	if (i >= 1 && buf[j - 1] == '\n')
		return (((i + 1) * nb_lines) + (j + 1));
	return (-1);
}

int		ft_check_first_line(char *buf)
{
	int		size;
	int		i;
	int		nb_lines;
	char	case_;

	i = -1;
	while (buf[++i] != '\n')
		;
	case_ = buf[i - 3];
	buf[i - 3] = '\0';
	nb_lines = ft_atoi(buf);
	size = ft_strlen(ft_itoa(ft_atoi(buf)));
	buf[i - 3] = case_;
	i = size;
	while (i < size + 3)
		if (!(ft_is_printable(buf[i++])))
			return (-1);
	if (!ft_check_double(buf, i) ||
			ft_get_end_of_line(buf, i + 1, nb_lines) == -1)
		return (-1);
	return (ft_get_end_of_line(buf, i + 1, nb_lines));
}
