/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhastag <skhastag@student.42heilbornn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:11:26 by skhastag          #+#    #+#             */
/*   Updated: 2024/03/24 12:24:08 by skhastag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
char	*ft_strchr(char const *str, int ch);
int		ft_get_formated_str(va_list args, const char format, int *flag_error);
int		ft_putchar_fd(char c, int fd, int *flag_error);
int		ft_putstr_fd(char *s, int fd, int *flag_error);
int		ft_putaddress(void *ptr, int *flag_error);
int		ft_putnbr_fd(long n, int fd, int *flag_error);
int		ft_putnbr_base(unsigned long nbr, char *base, int *flag_error);
int		ft_putunsigned(unsigned int val, int *flag_error);

#endif
