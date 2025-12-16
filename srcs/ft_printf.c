/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:29:47 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/14 10:48:53 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

/*
    return value:
    1. %c
    2. %s
    3. %p
    4. %d
    5. %i
    6. %u
    7. %x
    8. %X
    9. %%
	0 is unexpected
*/
static int	kind_of_print(char c)
{
	if (c == 'c')
		return (1);
	if (c == 's')
		return (2);
	if (c == 'p')
		return (3);
	if (c == 'd')
		return (4);
	if (c == 'i')
		return (5);
	if (c == 'u')
		return (6);
	if (c == 'x')
		return (7);
	if (c == 'X')
		return (8);
	if (c == '%')
		return (9);
	return (0);
}

static int	parse_format(const char *format, size_t index)
{
	int	kind;

	if (format[index] == '%')
	{
		kind = kind_of_print(format[index + 1]);
		if (kind == 0)
			return (-1);
		else
			return (kind);
	}
	return (0);
}

static int	print_by_kind(int kind, va_list *args)
{
	if (kind == 1)
		return (print_c(args));
	if (kind == 2)
		return (print_str(args));
	if (kind == 3)
		return (print_ptr(args));
	if (kind == 4 || kind == 5)
		return (print_num(args));
	if (kind == 6)
		return (print_unsigned_num(args));
	if (kind == 7)
		return (print_lower_hex(args));
	if (kind == 8)
		return (print_upper_hex(args));
	return (0);
}

static size_t	special_prints(int kind, size_t *index,
	const char *format, va_list *args)
{
	size_t	count;

	if (kind == 9)
		count = write(1, "%", 1);
	else if (kind == -1)
	{
		count = write(1, "%", 1);
		count += write(1, &format[*index], 1);
	}
	else
		count = print_by_kind(kind, args);
	(*index)++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		kind;
	size_t	count;
	size_t	index;

	va_start(args, format);
	count = 0;
	index = 0;
	while (format[index])
	{
		kind = parse_format(format, index);
		if (kind == -1 || (kind > 0 && kind <= 9))
		{
			count += special_prints(kind, &index, format, &args);
		}
		if (kind == 0)
			count += write(1, &format[index], 1);
		index++;
	}
	va_end(args);
	return (count);
}
