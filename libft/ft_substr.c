/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:17:59 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/14 10:18:23 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	index;

	if (start >= ft_strlen(s))
	{
		new = (char *)malloc(1);
		if (!new)
			return (NULL);
		*new = 0;
		return (new);
	}
	new = (char *)malloc(ft_strlen(s) - start + 1);
	if (!new)
		return (NULL);
	index = 0;
	while (index < len && s[start + index])
	{
		new[index] = s[start + index];
		index++;
	}
	new[index] = '\0';
	return (new);
}
