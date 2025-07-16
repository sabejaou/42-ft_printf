/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ul_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:23:40 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/08 13:36:21 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putnbr_ul_fd(unsigned int nb, int fd, unsigned int *ct)
{
	if (nb >= 10)
	{
		ft_putnbr_ul_fd(nb / 10, fd, ct);
		ft_putchar((nb % 10) + '0', fd, ct);
	}
	else
		ft_putchar(nb + '0', fd, ct);
}
