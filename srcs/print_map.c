/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:33:00 by bjacob            #+#    #+#             */
/*   Updated: 2020/09/01 14:29:46 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

void	print_map(char *buf, int *res, t_map_info *data)
{
	int	value;
	int max;
	int	i;
	int	ligne;
	int	stop;

	max = res[1];
	i = -1;
	value = res[0];
	ligne = (value - 1) * -(data->nb_c + 1);
	stop = 0;
	while (buf[++i])
	{
		if (i >= max + ligne - value + 1 && i <= max + ligne && stop == 0)
		{
			if (i == max + ligne)
				ligne = ligne + data->nb_c + 1;
			if (ligne > 0)
				stop = 1;
			buf[i] = data->plein;
		}
	}
	write(1, &buf[0], i);
}

int		print_global(char *buf)
{
	t_map_info	*data;
	int			*res;
	int			ij[2];

	if (buf != NULL)
	{
		data = get_map_info(&buf);
		ij[0] = 0;
		ij[1] = 0;
		init_res_nmax_emax(&res);
		ft_parcours(buf, data, ij, &res);
		if (res[0] == -1)
			write(1, "map error\n", 10);
		else
			print_map(buf, res, data);
		free(res);
		buf = buf - data->nb_char;
		free(data);
		free(buf);
	}
	else
		write(1, "map error\n", 10);
	return (0);
}
