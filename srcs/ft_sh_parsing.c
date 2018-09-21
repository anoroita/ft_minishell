/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:23:39 by anoroita          #+#    #+#             */
/*   Updated: 2018/09/21 10:05:28 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	**ft_env_assign(char *env)
{
	char	**env_tab;
	int		i;

	env_tab = (char **)malloc(sizeof(char *) * 3);
	i = 0;
	while (env[i] != '=')
		i++;
	env_tab[0] = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (env[i] != '=')
	{
		env_tab[0][i] = env[i];
		i++;
	}
	env_tab[0][i] = '\0';
	i++;
	env_tab[1] = ft_strdup(env + i);
	env_tab[2] = NULL;
	return (env_tab);
}

char	**ft_tild_split(char **split, char *home)
{
	int		i;
	char	*tmp;

	i = 0;
	while (split[i])
	{
		if (split[i][0] == '~')
		{
			tmp = split[i];
			split[i] = ft_strjoin(home, tmp + 1);
			free(tmp);
		}
		i++;
	}
	return (split);
}
