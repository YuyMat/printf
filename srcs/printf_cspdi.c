/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_cspdi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:30:54 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/14 10:35:17 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	print_c(va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	ft_putchar_fd((char)c, 1);
	return (1);
}

int	print_str(va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_ptr(va_list *args)
{
	char			*hex;
	unsigned long	address_num;
	char			ptr_str[17];
	size_t			i;
	size_t			ptr_len;

	hex = "0123456789abcdef";
	address_num = (unsigned long)va_arg(*args, void *);
	if (address_num == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	i = 0;
	while (address_num > 0)
	{
		ptr_str[i++] = hex[address_num % 16];
		address_num /= 16;
	}
	ptr_len = i;
	while (i--)
		ft_putchar_fd(ptr_str[i], 1);
	return (ptr_len + 2);
}

static int	get_nod(int n)
{
	int	nod;

	if (n == -2147483648)
		return (10);
	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	nod = 0;
	while (n > 0)
	{
		nod++;
		n /= 10;
	}
	return (nod);
}

int	print_num(va_list *args)
{
	int	num;

	num = va_arg(*args, int);
	ft_putnbr_fd(num, 1);
	if (num < 0)
		return (get_nod(num) + 1);
	return (get_nod(num));
}
