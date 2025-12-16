/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:09:34 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/05 17:35:18 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	index;
	char	*dest_p;
	char	*src_p;

	dest_p = (char *)dest;
	src_p = (char *)src;
	if (dest > src)
	{
		dest_p += n - 1;
		while (n > 0)
			*dest_p-- = src_p[--n];
		return (dest);
	}
	index = 0;
	while (index < n)
	{
		dest_p[index] = src_p[index];
		index++;
	}
	return (dest);
}
