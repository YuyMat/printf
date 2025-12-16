/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_uxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:01:47 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/05 19:19:49 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static int	u_get_nod(unsigned int n)
{
	int	nod;

	nod = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		nod++;
		n /= 10;
	}
	return (nod);
}

int	print_unsigned_num(va_list *args)
{
	unsigned int	num;

	num = va_arg(*args, unsigned int);
	put_unsigned_nbr(num, 1);
	return (u_get_nod(num));
}

static void	get_hex(char *hex_dest, unsigned int num, int *index)
{
	char	*hex;

	if (num == 0)
		hex_dest[(*index)++] = '0';
	hex = "0123456789abcdef";
	while (num > 0)
	{
		hex_dest[(*index)++] = hex[num % 16];
		num /= 16;
	}
}

int	print_lower_hex(va_list *args)
{
	unsigned int	num;
	char			num_str[11];
	int				index;
	int				hex_len;

	num = va_arg(*args, unsigned int);
	index = 0;
	get_hex(num_str, num, &index);
	hex_len = index;
	while (index--)
		ft_putchar_fd(num_str[index], 1);
	return (hex_len);
}

int	print_upper_hex(va_list *args)
{
	unsigned int	num;
	char			num_str[11];
	int				index;
	int				hex_len;

	num = va_arg(*args, unsigned int);
	index = 0;
	get_hex(num_str, num, &index);
	hex_len = index;
	while (index--)
		ft_putchar_fd((char)ft_toupper(num_str[index]), 1);
	return (hex_len);
}
