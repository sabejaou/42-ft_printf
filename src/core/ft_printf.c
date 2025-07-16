/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:23:40 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/08 13:36:21 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_printf_secargs(char c, va_list *lst, unsigned int *ct)
{
	if (c == 'u')
		ft_putnbr_ul_fd(va_arg(*lst, unsigned int), 1, ct);
	if (c == 'x')
		ft_putadd_fd(va_arg(*lst, long), 1, "0123456789abcdef", ct);
	if (c == 'X')
		ft_putadd_fd(va_arg(*lst, long), 1, "0123456789ABCDEF", ct);
	if (c == '%')
		ft_putchar('%', 1, ct);
}

void	ft_print_arg(char c, va_list *lst, unsigned int *ct)
{
	size_t	add;

	if (c == 'c')
		ft_putchar(va_arg(*lst, int), 1, ct);
	if (c == 's')
		ft_putstr_fd(va_arg(*lst, char *), 1, ct);
	if (c == 'p')
	{
		add = va_arg(*lst, size_t);
		if (add)
		{
			ft_putstr_fd("0x", 1, ct);
			ft_putadd_ul_fd(add, 1, "0123456789abcdef", ct);
		}
		else
			ft_putstr_fd("(nil)", 1, ct);
	}
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(*lst, int), 1, ct);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		ft_printf_secargs(c, lst, ct);
}

int	ft_printf(const char *fmt, ...)
{
	va_list			lst;
	int				i;
	unsigned int	ct;

	i = 0;
	ct = 0;
	if (!fmt)
		return (ct);
	va_start(lst, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			ft_print_arg(fmt[i], &lst, &ct);
			i++;
		}
		else
		{
			ft_putchar(fmt[i], 1, &ct);
			i++;
		}
	}
	return (ct);
}
