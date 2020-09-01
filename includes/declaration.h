/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declaration.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 05:26:59 by bjacob            #+#    #+#             */
/*   Updated: 2020/09/01 15:22:13 by thallard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECLARATION_H
# define DECLARATION_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# define BUF_SIZE 20000000

typedef struct	s_map_info
{
	int		nb_l;
	int		nb_c;
	char	vide;
	char	obs;
	char	plein;
	int		nb_char;
}				t_map_info;

int				ft_check_first_line(char *buf);
int				ft_is_printable(char c);

void			init_res_nmax_emax(int **res);
void			init_doubletab(int ***tab, int nb_c);
void			init_tab(int **tab, int nb_c);
void			switch_init_tab(int	**tab0, int **tab1);
void			ft_free_doubletab(int ***tab);

char			*get_buf(char *path, int buf_size);
t_map_info		*get_map_info(char **buf);
int				ft_min_close(int **tab, int i, int j);
void			ft_fill_tab(char *buf, int *ij, t_map_info *data, int ***tab);
void			ft_fill_res(int **res, int ***tab, int *ij, t_map_info *data);

int				ft_atoi(char *str);
char			*ft_itoa(int nbr);
void			ft_fill_nbr(char **res, int nbr, int rang);
int				ft_str_is_numeric(char c);
int				ft_strlen(char *str);

void			print_map(char *buf, int *res, t_map_info *data);
int				print_global(char *buf);

char			*get_buf_standard(void);
char			*get_buf_file(char *path);

int				ft_map_error_int(void);
char			*ft_map_error_char(void);

void			ft_parcours(char *buf, t_map_info *data, int *ij, int **res);

#endif
