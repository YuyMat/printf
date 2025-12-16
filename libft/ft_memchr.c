/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:07:17 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/04 09:19:51 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s_ptr;

	c = (char)c;
	s_ptr = (char *)s;
	while (n-- > 0)
	{
		if (*s_ptr == c)
			return (s_ptr);
		s_ptr++;
	}
	return (NULL);
}
