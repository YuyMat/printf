/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:32:17 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/14 10:29:19 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static int	u_get_nod(unsigned int n)
{
	int	nod;

	nod = 0;
	while (n > 0)
	{
		nod++;
		n /= 10;
	}
	return (nod);
}

static int	u_get_power_of(unsigned int n, int nod)
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

static void	u_not_mallocate_itoa(char *dest, unsigned int n)
{
	int				nod;
	unsigned int	index;

	if (n == 0)
	{
		dest[0] = '0';
		dest[1] = '\0';
		return ;
	}
	nod = u_get_nod(n);
	index = 0;
	if (n < 0)
	{
		dest[index++] = '-';
		n = -n;
	}
	while (nod > 0)
	{
		dest[index++] = (n / u_get_power_of(10, nod - 1)) + '0';
		n %= u_get_power_of(10, nod - 1);
		nod--;
	}
	dest[index] = '\0';
}

void	put_unsigned_nbr(unsigned int n, int fd)
{
	char	ascii_n[11];

	u_not_mallocate_itoa(ascii_n, n);
	write(fd, ascii_n, ft_strlen(ascii_n));
}
