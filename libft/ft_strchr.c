/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:13:55 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/04 09:20:17 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_ptr;

	c = (char)c;
	s_ptr = (char *)s;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (*s_ptr != c && *s_ptr)
		s_ptr++;
	if (*s_ptr == '\0')
		return (NULL);
	return (s_ptr);
}
