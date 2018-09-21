/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:16:39 by anoroita          #+#    #+#             */
/*   Updated: 2018/09/21 14:20:59 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_special_print(char c)
{
	if (c == 'n')
		ft_putchar('\n');
	if (c == 't')
		ft_putchar('\t');
	if (c == 'v')
		ft_putchar('\v');
	if (c == 'r')
		ft_putchar('\r');
	if (c == 'a')
		ft_putchar('\a');
	if (c == 'b')
		ft_putchar('\b');
	if (c == '\\')
		ft_putchar('\\');
}

void	ft_echo_print(char *str)
{
	int	i;
	int	l;

	l = ft_strlen(str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\\' && str[i] != '\0')
		{
			i++;
			ft_special_print(str[i]);
		}
		else if (str[i] != '\\')
			ft_putchar(str[i]);
		i++;
	}
}

int		ft_echo(char **str, t_all *all)
{
	int	i;

	i = 1;
	all = NULL;
	while (str[i] != NULL)
	{
		ft_echo_print(str[i]);
		if (str[i + 1] != NULL)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (1);
}
