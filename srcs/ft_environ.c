/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:26:06 by anoroita          #+#    #+#             */
/*   Updated: 2018/09/21 10:04:55 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_env	*env_start(void)
{
	t_env *env;

	env = (t_env *)malloc(sizeof(t_env));
	env->var = NULL;
	env->value = NULL;
	env->next = NULL;
	return (env);
}

t_env	*env_save(char *var, char *value)
{
	t_env	*env;

	env = env_start();
	env->var = ft_strdup(var);
	env->value = ft_strdup(value);
	return (env);
}

void	ft_push(t_all *all, t_env *env)
{
	t_env	*tmp;

	if (all->env == NULL)
		all->env = env;
	else
	{
		tmp = all->env;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = env;
		tmp = NULL;
	}
}

void	ft_stock_env(char **envp, t_all *all)
{
	t_env	*env;
	int		i;
	int		h;
	char	*tmp;
	char	**env_tab;

	i = 0;
	h = 0;
	tmp = NULL;
	while (envp[i])
	{
		env = NULL;
		env_tab = ft_env_assign(envp[i]);
		env = env_save(env_tab[0], env_tab[1]);
		if (ft_strequ("HOME", env_tab[0]))
		{
			all->home = ft_strdup(env_tab[1]);
			h = 1;
		}
		ft_free_tb(&env_tab);
		ft_push(all, env);
		i++;
	}
	if (h == 0)
		all->home = getcwd(tmp, 1024);
}

void	ft_environ(char **str, t_all *all)
{
	int status;

	if (!str[1])
		return (ft_print_env(all));
	if (!(ft_strequ("-i", str[1]) && str[2]))
		return ;
	if (ft_is_binary(str[2], all))
	{
		all->pid = fork();
		if (all->pid < 0)
			ft_error_msg(SYSPID, "\0");
		if (all->pid == 0)
		{
			if (execve(all->path, (str + 2), NULL) < 0)
			{
				ft_sh_exec_error(all->path);
				exit(1);
			}
		}
		else
			waitpid(all->pid, &status, WUNTRACED);
		ft_shell_error(WTERMSIG(status));
	}
	else
		ft_error_msg(ENV_ERROR, str[2]);
}
