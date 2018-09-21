/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:26:53 by anoroita          #+#    #+#             */
/*   Updated: 2018/09/21 10:05:51 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_sh_start(t_all *all)
{
	all->env = NULL;
	all->path = NULL;
	all->array = NULL;
	all->home = NULL;
	all->pid = 0;
}

int		ft_check_eviron(char **env, t_all *all)
{
	char	**str;
	char	*tmp;

	tmp = NULL;
	if (env[0])
		return (1);
	str = (char **)malloc(sizeof(char *) * 4);
	str[0] = ft_strdup("setenv");
	str[1] = ft_strdup("PWD");
	str[2] = getcwd(tmp, 1024);
	str[3] = NULL;
	all->home = ft_strdup(str[2]);
	ft_set_environ(str, all);
	ft_free_tb(&str);
	str = (char **)malloc(sizeof(char *) * 4);
	str[0] = ft_strdup("setenv");
	str[1] = ft_strdup("SHLVL");
	str[2] = ft_strdup("1");
	str[3] = NULL;
	ft_set_environ(str, all);
	ft_free_tb(&str);
	return (0);
}
