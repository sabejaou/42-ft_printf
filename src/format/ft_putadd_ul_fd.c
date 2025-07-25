/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd_ul_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:23:40 by sabejaou          #+#    #+#             */
/*   Updated: 2023/11/08 13:36:21 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putadd_ul_fd(unsigned long nb, unsigned long fd, const char *hex,
		unsigned int *ct)
{
	if (nb >= 16)
	{
		ft_putadd_ul_fd(nb / 16, fd, hex, ct);
		ft_putchar(hex[nb % 16], fd, ct);
	}
	else
		ft_putchar(hex[nb], fd, ct);
}
