/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:15:40 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/14 09:33:00 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	index;

	new_str = (char *)malloc(ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	index = 0;
	while (s[index])
	{
		new_str[index] = f(index, s[index]);
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}
