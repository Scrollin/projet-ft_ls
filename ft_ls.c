/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrondin <mgrondin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 10:02:20 by mgrondin          #+#    #+#             */
/*   Updated: 2014/11/17 18:08:48 by mgrondin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		swap(char **tab)
{
	int		a;
	int		b;
	char	*tmp;

	a = 0;
	b = 0;
	while (tab[a])
	{
		b = 0;
		while (tab[b])
		{
			if (ft_strcmp(tab[a], tab[b]) > 0)
			{
				tmp = (char*)malloc(sizeof(char));
				tmp = tab[b];
				tab[b] = tab[a];
				tab[a] = tmp;
			}
			b++;
		}
		a++;
	}
	return (a);
}

void	print_tab(char **tab, int id, int a)
{
	while (tab[a] && a != -1)
	{
		if (id < 2)
		{
			if (tab[a][0] != '.')
			{
				ft_putstr(tab[a]);
				ft_putchar('\n');
			}
		}
		else
		{
			ft_putstr(tab[a]);
			ft_putchar('\n');
		}
		(id == 0 || id == 2) ? a--  : a++;
	}
}

void	opt_r_and_null(DIR *rep, char *opt, int id)
{
	int		a;
	struct	dirent	*list;
	char **tab;

	a = 0;
	tab = (char**)malloc(sizeof(char*));
	while ((list = readdir(rep)))
	{
		tab[a] = list->d_name;
		a++;
	}
	a -= 1;
	swap(tab);
	if (opt != NULL && (id == 1 || id == 3))
		a = 0;
	print_tab(tab, id, a);
	free(tab);
}

int		which_opt(char *opt)
{
	int		x;
	int		r;
	int		a;

	x = 1;
	r = 0;
	a = 0;
	if (opt[0] == '-')
	{
		while (opt[x])
		{
			if (opt[x] == 'r')
				r = 1;
			if (opt[x] == 'a')
				a = 2;
			x++;
		}
	}
	return (r + a);
}

void	ft_ls(DIR *rep, char *opt)
{
	int		id;
	if (opt != NULL)
		id = which_opt(opt);
	else
		opt = "";
	opt_r_and_null(rep, opt, id);
}
