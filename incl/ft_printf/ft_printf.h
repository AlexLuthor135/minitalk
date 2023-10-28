/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:31:33 by alappas           #+#    #+#             */
/*   Updated: 2023/08/01 03:13:09 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

int		ft_printf_s(char *s);
int		ft_printf_char(char c);
int		ft_count_d(int n);
int		ft_printf_d(int n);
int		ft_len_p(unsigned long int v);
int		ft_printf_p(unsigned long long ptr);
int		ft_printf_prc(void);
int		ft_count_u(unsigned int n);
int		ft_printf_undec(unsigned int n);
int		ft_len_x(unsigned int v);
int		ft_len_x2(unsigned int v2);
int		ft_printf_x(unsigned int v);
int		ft_printf_x2(unsigned int v);
int		ft_printf(const char *s, ...);
int		ft_printf_char(char c);

#endif