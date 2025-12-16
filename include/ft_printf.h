/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsumo <ymatsumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:48:20 by ymatsumo          #+#    #+#             */
/*   Updated: 2025/05/04 13:24:05 by ymatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

void	put_unsigned_nbr(unsigned int n, int fd);
int		print_c(va_list *args);
int		print_str(va_list *args);
int		print_ptr(va_list *args);
int		print_num(va_list *args);
int		print_unsigned_num(va_list *args);
int		print_lower_hex(va_list *args);
int		print_upper_hex(va_list *args);
int		ft_printf(const char *format, ...);

#endif
