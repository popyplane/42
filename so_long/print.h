/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:27:16 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/08/03 19:55:16 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

int	ft_dprintf(int fd, const char *format, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int nb, int fd);
int	ft_putstr_fd(char *s, int fd);

#endif