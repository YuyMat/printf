/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:11:06 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/04 12:53:08 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nod(int n)
{
	int	nod;

	if (n < 0)
		n = -n;
	nod = 0;
	while (n > 0)
	{
		nod++;
		n /= 10;
	}
	return (nod);
}

static int	get_power_of(int n, int nod)
{
	int	result;

	result = 1;
	while (nod > 0)
	{
		result *= n;
		nod--;
	}
	return (result);
}

static void	not_mallocate_itoa(char *dest, int n)
{
	int	nod;
	int	index;

	if (n == 0)
	{
		dest[0] = '0';
		dest[1] = '\0';
		return ;
	}
	nod = get_nod(n);
	index = 0;
	if (n < 0)
	{
		dest[index++] = '-';
		n = -n;
	}
	while (nod > 0)
	{
		dest[index++] = (n / get_power_of(10, nod - 1)) + '0';
		n %= get_power_of(10, nod - 1);
		nod--;
	}
	dest[index] = '\0';
}

void	ft_putnbr_fd(int n, int fd)
{
	char	ascii_n[12];

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	not_mallocate_itoa(ascii_n, n);
	write(fd, ascii_n, ft_strlen(ascii_n));
}
