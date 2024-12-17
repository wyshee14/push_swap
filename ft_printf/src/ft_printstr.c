/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:40:33 by wshee             #+#    #+#             */
/*   Updated: 2024/12/03 19:47:06 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (ft_printstr("(null)"));
	while (*s)
	{
		count += write(1, s, 1);
		s++;
	}
	return (count);
}
