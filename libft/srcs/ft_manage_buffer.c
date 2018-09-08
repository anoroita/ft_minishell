/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:00:57 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 09:00:59 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbuf(t_pf *ft, char c)
{
	ft->buf[ft->index] = c;
	ft->index++;
	ft->print++;
	if (ft->index == 4096)
		ft_printbuf(ft);
}

void	ft_printbuf(t_pf *ft)
{
	if (ft->print != -1)
		write(1, ft->buf, ft->index);
	else
		write(1, ft->buf, ft->ready);
	ft->index = 0;
	ft->ready = 0;
}
