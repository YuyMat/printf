/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:15:00 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/05 17:36:36 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*dst_p;
	size_t	index;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + ft_strlen(src));
	dst_p = dst;
	while (*dst_p)
		dst_p++;
	index = 0;
	while (dst_len + index < size - 1 && src[index])
		*dst_p++ = src[index++];
	*dst_p = '\0';
	return (dst_len + ft_strlen(src));
}
