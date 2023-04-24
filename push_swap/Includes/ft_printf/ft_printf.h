/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:19:46 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/02/16 15:55:55 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_intlen(int n);
int		ft_nbrlen(unsigned long nb, char *base);
int		ft_putchar_fd(char c, int fd);
int		ft_puthex_fd(unsigned int uinb, int fd);
int		ft_puthex_up_fd(unsigned int uinb, int fd);
int		ft_putnbr_base_fd(unsigned long ulnb, char *base, int fd);
int		ft_putnbr_fd(int nb, int fd);
int		ft_putunbr_fd(unsigned int uinb, int fd);
int		ft_putptr_fd(void *ptr, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);

#endif