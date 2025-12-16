/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 08:54:16 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/14 09:42:28 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	can_ignore(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\r' || c == '\f')
		return (1);
	else
		return (0);
}

static void	ignore(const char *str, size_t *index)
{
	while (can_ignore(str[*index]))
		(*index)++;
}

static int	set_minus_f(const char *str, size_t *index, int *minus_f)
{
	if (str[*index] == '-' || str[*index] == '+')
	{
		if (str[*index] == '-')
			*minus_f = 1;
		(*index)++;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		result;
	size_t	index;
	int		minus_f;

	result = 0;
	index = 0;
	minus_f = 0;
	ignore(nptr, &index);
	set_minus_f(nptr, &index, &minus_f);
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = (result * 10) + (nptr[index] - '0');
		index++;
	}
	if (minus_f)
		return (-result);
	return (result);
}
