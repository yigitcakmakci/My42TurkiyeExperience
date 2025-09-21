/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:23:23 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/07/19 20:33:49 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	ft_print_char(char c);
int	ft_print_hex(int n, char fmt);
int	ft_print_nbr(int n);
int	ft_print_str(char *c);
int	ft_print_ptr(char *c);
int	ft_print_unsigned(unsigned int n);

#endif