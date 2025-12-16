/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:14:10 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/14 09:30:41 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_s;
	size_t	index;

	new_s = (char *)malloc(ft_strlen(s) + 1);
	if (!new_s)
		return (NULL);
	index = 0;
	while (s[index])
	{
		new_s[index] = s[index];
		index++;
	}
	new_s[index] = '\0';
	return (new_s);
}
