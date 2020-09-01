/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 15:39:28 by thallard          #+#    #+#             */
/*   Updated: 2020/09/01 15:23:09 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

void	ft_parcours(char *buf, t_map_info *data, int *ij, int **res)
{
	int		**tab;

	init_doubletab(&tab, data->nb_c);
	while (buf[ij[0] * (data->nb_c + 1) + ij[1]] && ij[0] < data->nb_l)
	{
		while (ij[1] < data->nb_c)
		{
			ft_fill_tab(buf, ij, data, &tab);
			ft_fill_res(res, &tab, ij, data);
			if ((*res)[0] == -1)
				return ;
			ij[1]++;
		}
		if (buf[ij[0]++ * (data->nb_c + 1) + ij[1]] != '\n')
		{
			ft_free_doubletab(&tab);
			(*res)[0] = -1;
			return ;
		}
		ij[1] = 0;
		switch_init_tab(&tab[0], &tab[1]);
	}
	if (buf[ij[0] * (data->nb_c + 1) + ij[1]] != '\0' || ij[0] != data->nb_l)
		(*res)[0] = -1;
	ft_free_doubletab(&tab);
}

int		main(int argc, char **argv)
{
	char	*buf;
	int		k;

	if (argc == 1)
	{
		buf = get_buf_standard();
		return (print_global(buf));
	}
	else
	{
		k = 1;
		while (k < argc)
		{
			buf = get_buf_file(argv[k]);
			print_global(buf);
			if (argc > 2)
				write(1, "\n", 1);
			k++;
		}
		return (0);
	}
}
