/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_environ.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:46:31 by anoroita          #+#    #+#             */
/*   Updated: 2018/09/21 10:03:06 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_print_env(t_all *all)
{
	t_env	*tmp;

	tmp = all->env;
	while (tmp != NULL)
	{
		if (tmp->var)
		{
			ft_putstr(tmp->var);
			ft_putchar('=');
			if (tmp->value)
				ft_putendl(tmp->value);
			else
				ft_putchar('\n');
		}
		tmp = tmp->next;
	}
}

int		ft_setenv_exist(char **str, t_all *all)
{
	t_env	*tmp;

	tmp = all->env;
	while (tmp)
	{
		if (ft_strequ(tmp->var, str[1]))
		{
			free(tmp->value);
			if (str[2])
				tmp->value = ft_strdup(str[2]);
			else
				tmp->value = ft_strdup("\0");
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_set_environ(char **str, t_all *all)
{
	t_env	*tmp;
	size_t	len;

	len = ft_strlen_tab(str);
	if (len == 1)
		ft_print_env(all);
	else if (len > 3)
		ft_error_msg(ARG_ENV, "\0");
	else if (ft_setenv_exist(str, all))
		;
	else if (len <= 2)
	{
		tmp = env_save(str[1], "\0");
		ft_push(all, tmp);
	}
	else
	{
		tmp = env_save(str[1], str[2]);
		ft_push(all, tmp);
	}
}

void	ft_list_search(t_env *prev, char **str, int i)
{
	t_env	*tmp;

	tmp = prev->next;
	while (tmp != NULL)
	{
		if (ft_strequ(tmp->var, str[i]))
		{
			prev->next = tmp->next;
			free(tmp->var);
			free(tmp->value);
			free(tmp);
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

int		ft_unset_env(char **str, t_all *all)
{
	t_env	*prev;
	int		i;

	i = 1;
	if (!str[i])
		ft_error_msg(UNSET_ARG, "\0");
	if (!all->env)
		return (0);
	while (str[i])
	{
		prev = all->env;
		if (ft_strequ(prev->var, str[i]))
		{
			all->env = prev->next;
			free(prev->var);
			free(prev->value);
			free(prev);
		}
		ft_list_search(prev, str, i);
		prev = NULL;
		i++;
	}
	return (0);
}
