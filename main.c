/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrondin <mgrondin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 13:35:41 by mgrondin          #+#    #+#             */
/*   Updated: 2014/11/17 18:22:11 by mgrondin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ls(DIR *rep, char *opt);

int		main(int argc, char **argv)
{
	DIR *rep;

	(void)argc;
	rep = NULL;
	if(!(rep = opendir(".")))
	   return (0);
	ft_ls(rep, argv[1]);
	closedir(rep);
	return (0);
}
