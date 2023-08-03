/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvieilhe <bvieilhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:54:41 by bvieilhe          #+#    #+#             */
/*   Updated: 2023/08/03 19:33:27 by bvieilhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "print.h"
#include "structs.h"
#include <stdlib.h>

void	ft_error(char *msg)
{
	ft_dprintf(2, "Error\n%s\n", msg);
	exit(1);
}
