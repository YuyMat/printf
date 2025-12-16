/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:17:17 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/14 09:57:36 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	size_t	index;

	index = 0;
	while (set[index])
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

static int	get_new_bite(char const *s1, char const *set)
{
	size_t	counter;
	size_t	index;

	counter = 0;
	index = 0;
	while (is_set(s1[index], set))
	{
		counter++;
		index++;
	}
	if (!s1[index])
		return (1);
	index = ft_strlen(s1) - 1;
	while (is_set(s1[index], set))
	{
		counter++;
		index--;
	}
	return (ft_strlen(s1) - counter + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	char	*s1_ptr;
	size_t	index;
	size_t	new_index;

	new_str = (char *)malloc(get_new_bite(s1, set));
	if (!new_str)
		return (NULL);
	s1_ptr = ft_strdup(s1);
	index = ft_strlen(s1) - 1;
	new_index = 0;
	while (is_set(s1[index], set))
	{
		s1_ptr[index] = '\0';
		index--;
	}
	index = 0;
	while (is_set(s1[index], set))
		index++;
	while (s1_ptr[index])
		new_str[new_index++] = s1_ptr[index++];
	new_str[new_index] = '\0';
	free(s1_ptr);
	return (new_str);
}
