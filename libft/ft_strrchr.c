/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:17:03 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/14 09:33:09 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	char	*s_ptr;

	c = (char)c;
	s_len = ft_strlen(s);
	s_ptr = (char *)s + s_len;
	if (c == 0)
		return (s_ptr);
	while (*s_ptr != c && s_len-- > 0)
		s_ptr--;
	if (s_ptr == s && *s_ptr != c)
		return (NULL);
	return ((char *)s_ptr);
}
