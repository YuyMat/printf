/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:16:29 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/05 17:37:47 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == *little)
		{
			j = 1;
			while (big[i + j] == little[j] && little[j] && big[i + j])
				j++;
			if (little[j] == '\0' && i + j <= len)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
