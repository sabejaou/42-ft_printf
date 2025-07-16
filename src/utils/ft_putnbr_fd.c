/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:23:40 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/08 13:36:21 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <unistd.h>

void	ft_putchar(char c, int fd, unsigned int *ct)
{
	write(fd, &c, 1);
	(*ct)++;
}

void	ft_putnbr_fd(int nb, int fd, unsigned int *ct)
{
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd, ct);
	else if (nb < 0)
	{
		ft_putchar('-', fd, ct);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd, ct);
		ft_putchar((nb % 10) + '0', fd, ct);
	}
	else if (nb < 10 && nb >= 0)
		ft_putchar(nb + '0', fd, ct);
}
