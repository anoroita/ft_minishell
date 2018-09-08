/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 10:09:57 by anoroita          #+#    #+#             */
/*   Updated: 2018/09/03 10:10:32 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_error_msg(int i, char *str)
{
	if (i == SYSCALL)
	{
		ft_putstr_fd("ft_minishell : command not found: ", 2);
		ft_putendl_fd(str, 2);
	}
	else if (i == SYSPID)
		ft_putendl_fd("ft_minishell: fork failed: resource unavailable", 2);
	else if (i == ARG_ENV)
		ft_putendl_fd("setenv: Too many arguments.", 2);
	else if (i == UNSET_ARG)
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
	else if (i == ENV_ERROR)
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	else if (i == CD_ERROR)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
}

char	*ft_tab_to_space(char *cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\t')
			cmd[i] = ' ';
		i++;
	}
	return (cmd);
}
