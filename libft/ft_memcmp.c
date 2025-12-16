/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:07:38 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/04 09:19:55 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;
	size_t			index;

	s1_ptr = (unsigned char *)s1;
	s2_ptr = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (s1_ptr[index] != s2_ptr[index])
			return (s1_ptr[index] - s2_ptr[index]);
		index++;
	}
	return (0);
}
