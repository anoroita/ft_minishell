/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:03:56 by anoroita          #+#    #+#             */
/*   Updated: 2018/09/21 10:06:18 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_shell_error(int i)
{
	if (i <= 0 || i == 2 || (i >= 16 && i <= 23) || i == 28 || i == 29)
		return ;
	else if (i >= 12)
		ft_shell_error_2(i);
	else if (i == 1)
		ft_putendl_fd("Hangup", 2);
	else if (i == 3)
		ft_putendl_fd("Quit", 2);
	else if (i == 4)
		ft_putendl_fd("Illegal instruction", 2);
	else if (i == 5)
		ft_putendl_fd("Trace/BPT trap", 2);
	else if (i == 6)
		ft_putendl_fd("Abort", 2);
	else if (i == 7)
		ft_putendl_fd("EMT trap", 2);
	else if (i == 8)
		ft_putendl_fd("Floating point execption", 2);
	else if (i == 9)
		ft_putendl_fd("Killed", 2);
	else if (i == 10)
		ft_putendl_fd("Bus error", 2);
	else if (i == 11)
		ft_putendl_fd("Segmentation fault", 2);
}

void	ft_shell_error_2(int i)
{
	if (i == 12)
		ft_putendl_fd("Bad system call", 2);
	else if (i == 13)
		ft_putendl_fd("Broken pipe", 2);
	else if (i == 14)
		ft_putendl_fd("Alarm clock", 2);
	else if (i == 15)
		ft_putendl_fd("Terminated", 2);
	else if (i == 24)
		ft_putendl_fd("CPU - time limit exceeded", 2);
	else if (i == 25)
		ft_putendl_fd("Filesize limit exceeded", 2);
	else if (i == 26)
		ft_putendl_fd("Virtual time alarm", 2);
	else if (i == 27)
		ft_putendl_fd("Profiling time alarm", 2);
	else if (i == 30)
		ft_putendl_fd("User signal 1", 2);
	else if (i == 31)
		ft_putendl_fd("User signal 2", 2);
}
