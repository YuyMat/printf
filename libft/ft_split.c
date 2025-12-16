/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:12:10 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/14 09:54:50 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	replace_to_null(char *s, char c)
{
	int	index;

	index = ft_strlen(s) - 1;
	while (index >= 0)
	{
		if (s[index] == c)
			s[index] = '\0';
		index--;
	}
}

static int	get_rtn_size(char *s, char c)
{
	size_t	c_count;
	size_t	index;

	c_count = 0;
	index = 0;
	while (s[index])
		if (s[index++] == c)
			c_count++;
	return (c_count + 2);
}

static int	fill_split_result(char **rtn_strs, char *s_cpy, const char *s)
{
	size_t	s_index;
	size_t	rtn_index;

	s_index = 0;
	rtn_index = 0;
	while (s_index < ft_strlen(s))
	{
		if (*s_cpy)
		{
			rtn_strs[rtn_index] = ft_strdup(s_cpy);
			if (!rtn_strs[rtn_index++])
				return (0);
			s_index += ft_strlen(s_cpy) - 1;
			s_cpy += ft_strlen(s_cpy) - 1;
		}
		s_index++;
		s_cpy++;
	}
	rtn_strs[rtn_index] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn_strs;
	char	*s_cpy;

	rtn_strs = (char **)malloc(sizeof(char *) * get_rtn_size((char *)s, c));
	if (!rtn_strs)
		return (NULL);
	s_cpy = ft_strdup(s);
	if (!s_cpy)
		return (NULL);
	replace_to_null(s_cpy, c);
	if (!fill_split_result(rtn_strs, s_cpy, s))
	{
		free(rtn_strs);
		return (NULL);
	}
	free(s_cpy);
	return (rtn_strs);
}
