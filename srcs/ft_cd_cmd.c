/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:22:45 by anoroita          #+#    #+#             */
/*   Updated: 2018/09/21 10:04:17 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_sh_mod_pwd(t_all *all, char *str, char *pwd)
{
	t_env	*env;

	if (!all->env)
	{
		all->env = env_start();
		all->env->var = ft_strdup(str);
	}
	env = all->env;
	while (env->next && !ft_strequ(str, env->var))
		env = env->next;
	if (!ft_strequ(str, env->var))
	{
		env->next = (t_env *)malloc(sizeof(t_env));
		env = env->next;
		env->var = ft_strdup(str);
		env->value = NULL;
		env->next = NULL;
	}
	if (env->value)
		free(env->value);
	env->value = ft_strdup(pwd);
}

void	ft_cd(char **str, t_all *all)
{
	char	*pwd;
	char	*tmp;

	tmp = NULL;
	pwd = getcwd(tmp, 1024);
	if (str[1] && !str[2])
	{
		if (str[1][0] == '-' && str[1][1])
			ft_putendl_fd("Usage: cd [-][-|<dir>].", 2);
		else if (str[1][0] == '-')
			ft_cd_old_pwd(all, pwd);
		else
			ft_change_dir(pwd, all, str[1]);
	}
	else if (!str[1])
		ft_change_dir(pwd, all, all->home);
	else
		ft_putendl_fd("cd: Too many arguments.", 2);
	if (pwd)
		free(pwd);
}

void	ft_change_dir(char *pwd, t_all *all, char *str)
{
	char	*tmp;

	tmp = NULL;
	if (chdir(str) < 0)
		ft_error_msg(CD_ERROR, str);
	else
	{
		ft_sh_mod_pwd(all, "OLDPWD", pwd);
		tmp = NULL;
		pwd = getcwd(tmp, 1024);
		ft_sh_mod_pwd(all, "PWD", pwd);
		if (pwd)
			free(pwd);
	}
}

void	ft_cd_old_pwd(t_all *all, char *pwd)
{
	t_env	*env;

	env = all->env;
	while (env && !ft_strequ(env->var, "OLDPWD"))
		env = env->next;
	if (env && ft_strequ(env->var, "OLDPWD"))
		ft_change_dir(pwd, all, env->value);
	else
		ft_putendl_fd("No such file or directory.", 2);
}
