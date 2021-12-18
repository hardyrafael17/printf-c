/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjimenez <hjimenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:33:02 by hjimenez          #+#    #+#             */
/*   Updated: 2021/12/15 21:33:33 by hjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_write(char *str, int c, char task_type);
int				ft_printf(const char *fmt, ...);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_itoa(int num);
int				t_printstring(char *str, int size, char caller);
char			*ft_itoa_void(unsigned long int n, char *base);
size_t			rintstr(char *str);
int				ft_printchar(char c, int word_count);
void			ft_printvoid(void *ptr);
int				ft_lp(char *str, int size);
char			*ft_itoa_unsig(unsigned int n);
char			*ft_ib(unsigned int n, char *base);
void			ft_formatter(va_list args, char c);

#endif
