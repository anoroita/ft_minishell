/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 10:04:01 by anoroita          #+#    #+#             */
/*   Updated: 2018/09/03 10:04:06 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_env_to_array(t_all *all)
{
	t_env	*tmp;
	int		count;
	int		len;

	count = 0;
	tmp = all->env;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	all->array = (char **)malloc(sizeof(char *) * (count + 1));
	count = 0;
	tmp = all->env;
	while (tmp)
	{
		len = 0;
		len = ft_strlen(tmp->var);
		len += ft_strlen(tmp->value);
		all->array[count] = ft_strjoin(tmp->var, "=");
		all->array[count] = ft_strjoin_free(all->array[count], tmp->value);
		count++;
		tmp = tmp->next;
	}
	all->array[count] = NULL;
}

int		ft_check_binary(char **split, struct stat stat, t_all *all, char *str)
{
	int	i;

	i = 0;
	(void)stat;
	while (split[i])
	{
		all->path = ft_strjoin(split[i], "/");
		all->path = ft_strjoin_free(all->path, str);
		if (access(all->path, X_OK) == 0)
		{
			ft_free_tb(&split);
			return (1);
		}
		if (all->path)
			free(all->path);
		i++;
	}
	return (0);
}

int		ft_is_binary(char *str, t_all *all)
{
	char			**split;
	t_env			*tmp;
	struct stat		s;

	tmp = all->env;
	while (tmp && tmp->next && ft_strequ("PATH", tmp->var) != 1)
		tmp = tmp->next;
	if ((str[0] == '.' || str[0] == '/') && lstat(str, &s) >= 0)
	{
		all->path = ft_strdup(str);
		tmp = NULL;
		return (1);
	}
	else if (str[0] == '.' || str[0] == '/')
		return (0);
	if (!tmp)
		return (0);
	split = ft_strsplit(tmp->value, ':');
	if (ft_check_binary(split, s, all, str))
		return (1);
	ft_free_tb(&split);
	tmp = NULL;
	return (0);
}

void	ft_sh_exec_error(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": Permission denied.", 2);
}

void	ft_exec_binary(char **str, t_all *all)
{
	int		status;

	if (all->env)
		ft_env_to_array(all);
	all->pid = fork();
	save_pid(all->pid);
	if (all->pid < 0)
		ft_error_msg(SYSPID, "\0");
	if (all->pid == 0)
	{
		if (execve(all->path, str, all->array) < 0)
		{
			ft_sh_exec_error(all->path);
			exit(-1);
		}
	}
	else
		waitpid(all->pid, &status, WUNTRACED);
	ft_shell_error(WTERMSIG(status));
	save_pid(-1);
	ft_free_tb(&all->array);
	free(all->path);
}
