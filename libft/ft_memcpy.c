/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:09:10 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/04 09:09:30 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;
	char	*dest_p;
	char	*src_p;

	dest_p = (char *)dest;
	src_p = (char *)src;
	index = 0;
	while (index < n)
	{
		dest_p[index] = src_p[index];
		index++;
	}
	return (dest);
}
