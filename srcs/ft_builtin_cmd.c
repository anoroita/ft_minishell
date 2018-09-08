/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:54:03 by anoroita          #+#    #+#             */
/*   Updated: 2018/09/03 14:54:06 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_is_builtin(char *str)
{
	if (ft_strequ("env", str))
		return (1);
	else if (ft_strequ("cd", str))
		return (1);
	else if (ft_strequ("setenv", str))
		return (1);
	else if (ft_strequ("unsetenv", str))
		return (1);
	else if (ft_strequ("exit", str))
		return (1);
	else
		return (0);
}

void	ft_exec_builtin(char **str, t_all *all)
{
	if (ft_strequ("env", str[0]))
		ft_environ(str, all);
	else if (ft_strequ("setenv", str[0]))
		ft_set_environ(str, all);
	else if (ft_strequ("unsetenv", str[0]))
		ft_unset_env(str, all);
	else if (ft_strequ("exit", str[0]))
		ft_exit_cmd(str);
	else if (ft_strequ("cd", str[0]))
		ft_cd(str, all);
}

void	ft_exit_cmd(char **str)
{
	int		i;
	int		num;

	i = 0;
	if (!str[1])
	{
		ft_putendl_fd("exit", 1);
		exit(0);
	}
	else if (str[1])
	{
		while (!str[2] && str[1][i] && ft_isdigit(str[1][i]))
		{
			if (str[1][i + 1] == '\0')
			{
				num = ft_atoi(str[1]);
				ft_putendl_fd("exit", 1);
				exit(num);
			}
			i++;
		}
		ft_putendl_fd("exit: Expression Syntax.", 2);
	}
}
