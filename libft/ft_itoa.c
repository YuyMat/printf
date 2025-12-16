/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:06:31 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/04 12:52:34 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nod(int n)
{
	int	nod;

	if (n == -2147483648)
		return (100);
	nod = (n < 0);
	if (nod)
		n = -n;
	while (n > 0)
	{
		nod++;
		n /= 10;
	}
	return (nod);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		nod;
	int		is_minus;

	if (n == 0)
		return (ft_strdup("0"));
	nod = get_nod(n);
	if (nod == 100)
		return (ft_strdup("-2147483648"));
	is_minus = (n < 0);
	if (is_minus)
		n = -n;
	result = (char *)malloc(nod + 1);
	if (!result)
		return (NULL);
	result[nod--] = '\0';
	while (n > 0)
	{
		result[nod--] = (n % 10) + '0';
		n /= 10;
	}
	if (is_minus)
		result[0] = '-';
	return (result);
}
