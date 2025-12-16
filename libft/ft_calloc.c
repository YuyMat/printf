/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 08:58:13 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/05 17:33:33 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*new_p;

	if (size == 0 || nmemb == 0)
	{
		new_p = (char *)malloc(1);
		if (!new_p)
			return (NULL);
		*new_p = 0;
		return (new_p);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	new_p = (char *)malloc(nmemb * size);
	if (!new_p)
		return (NULL);
	ft_memset(new_p, 0, nmemb * size);
	return ((void *)new_p);
}
